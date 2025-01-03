#include "bk_private/bk_init.h"
#include <components/system.h>
#include <os/os.h>
#include <components/shell_task.h>

#include "cli.h"

#include "lcd_act.h"
#include "media_app.h"
#include "lv_vendor.h"
#include "driver/drv_tp.h"
#include <modules/pm.h>


#define TAG "lvgl qspi lcd"
#define LOGE(...) BK_LOGE(TAG, ##__VA_ARGS__)
#define LOGW(...) BK_LOGW(TAG, ##__VA_ARGS__)
#define LOGI(...) BK_LOGI(TAG, ##__VA_ARGS__)
#define LOGD(...) BK_LOGD(TAG, ##__VA_ARGS__)


extern void user_app_main(void);
extern void rtos_set_user_app_entry(beken_thread_function_t entry);

#define CMDS_COUNT  (sizeof(s_lv_qspi_lcd_commands) / sizeof(struct cli_command))

#define PSRAM_FRAME_BUFFER ((0x60000000UL) + 5 * 1024 * 1024)

const lcd_open_t lcd_open =
{
	.device_ppi = PPI_360X480,
	.device_name = "st77903_sat61478m",
};

extern void lv_example_meter(void);
extern bk_err_t bk_lcd_qspi_open(char *lcd_name, uint32_t *frame_buffer_addr, uint32_t frame_buffer_len);
extern bk_err_t bk_lcd_qspi_close(void);
	
void cli_lv_qspi_lcd_cmd(char *pcWriteBuffer, int xWriteBufferLen, int argc, char **argv)
{
	os_printf("%s\r\n", __func__);
	if (os_strcmp(argv[1], "openlcd") == 0) {
		if (BK_OK != bk_lcd_qspi_open(lcd_open.device_name, (uint32_t *)PSRAM_FRAME_BUFFER, ppi_to_pixel_x(lcd_open.device_ppi) * ppi_to_pixel_y(lcd_open.device_ppi) * (LV_COLOR_DEPTH / 8))) {
			os_printf("lcd qspi open fail!\r\n");
			return;
		}
	} else if (os_strcmp(argv[1], "closelcd") == 0) {
		bk_lcd_qspi_close();
	}
}

static const struct cli_command s_lv_qspi_lcd_commands[] =
{
	{"qspi_lcd", "qspi_lcd", cli_lv_qspi_lcd_cmd},
};

int cli_lv_qspi_lcd_init(void)
{
	return cli_register_commands(s_lv_qspi_lcd_commands, CMDS_COUNT);
}


#ifdef CONFIG_CACHE_CUSTOM_SRAM_MAPPING
const unsigned int g_sram_addr_map[4] =
{
	0x38000000,
	0x30020000,
	0x38020000,
	0x30000000
};
#endif

void lv_qspi_lcd_display_init(void)
{
#ifdef CONFIG_LV_QSPI_DEMO
	bk_err_t ret = BK_OK;
	lv_vnd_config_t lv_vnd_config = {0};

	os_printf("lvgl qspi display demo start\r\n");

	cli_lv_qspi_lcd_init();

	bk_pm_mcu_pm_ctrl(0);
	bk_pm_module_vote_power_ctrl(PM_POWER_MODULE_NAME_CPU1, PM_POWER_MODULE_STATE_ON);
	extern void start_slave_core(void);
	start_slave_core();
	rtos_delay_milliseconds(10);

#ifdef CONFIG_LVGL_USE_PSRAM
	lv_vnd_config.draw_pixel_size = ppi_to_pixel_x(lcd_open.device_ppi) * ppi_to_pixel_y(lcd_open.device_ppi);
	lv_vnd_config.draw_buf_2_1 = (lv_color_t *)PSRAM_DRAW_BUFFER;
	lv_vnd_config.draw_buf_2_2 = (lv_color_t *)(PSRAM_DRAW_BUFFER + lv_vnd_config.draw_pixel_size * sizeof(lv_color_t));
#else
	lv_vnd_config.draw_pixel_size = (30 * 1024) / sizeof(lv_color_t);
	lv_vnd_config.draw_buf_2_1 = LV_MEM_CUSTOM_ALLOC(lv_vnd_config.draw_pixel_size * sizeof(lv_color_t));
	lv_vnd_config.draw_buf_2_2 = NULL;
	lv_vnd_config.sram_frame_buf_1 = (lv_color_t *)PSRAM_FRAME_BUFFER;
//	lv_vnd_config.sram_frame_buf_2 = (lv_color_t *)PSRAM_FRAME_BUFFER + ppi_to_pixel_x(lcd_open.device_ppi)*ppi_to_pixel_y(lcd_open.device_ppi) * sizeof(lv_color_t);
#endif
	lv_vnd_config.rotation = ROTATE_270;
	lv_vnd_config.color_depth = LV_COLOR_DEPTH;

#if (CONFIG_TP)
	drv_tp_open(ppi_to_pixel_x(lcd_open.device_ppi), ppi_to_pixel_y(lcd_open.device_ppi));
#endif
	
	lv_vendor_init(&lv_vnd_config, ppi_to_pixel_y(lcd_open.device_ppi), ppi_to_pixel_x(lcd_open.device_ppi));
	
	bk_err_t bk_lcd_qspi_open(char *lcd_name, uint32_t *frame_buffer_addr, uint32_t frame_buffer_len);
	ret = bk_lcd_qspi_open(lcd_open.device_name, (uint32_t *)PSRAM_FRAME_BUFFER, ppi_to_pixel_x(lcd_open.device_ppi) * ppi_to_pixel_y(lcd_open.device_ppi) * (LV_COLOR_DEPTH / 8));
	if (ret != BK_OK)
	{
		os_printf("lcd qspi open failed\r\n");
	}

	lv_vendor_start();

	lv_example_meter();

#endif

}

void user_app_main(void){

}

int main(void)
{
#if (!CONFIG_SLAVE_CORE)
	rtos_set_user_app_entry((beken_thread_function_t)user_app_main);
	bk_set_printf_sync(true);
	// shell_set_log_level(BK_LOG_WARN);
#endif
	bk_init();

	lv_qspi_lcd_display_init();

	return 0;
}