/*
 * Copyright (c) 2018-2021, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "cmsis.h"
#include "target_cfg.h"
#include "Driver_MPC.h"
#include "utilities.h"

/* Import MPC driver */
extern ARM_DRIVER_MPC Driver_SRAM1_MPC;

/* Get address of memory regions to configure MPU */
extern const struct memory_region_limits memory_regions;

void MPC_Handler(void)
{
    //TODO
    /* Inform TF-M core that isolation boundary has been violated */
}

void PPC_Handler(void)
{
    //TODO
    /* Inform TF-M core that isolation boundary has been violated */
}

uint32_t tfm_spm_hal_get_ns_VTOR(void)
{
    return memory_regions.non_secure_code_start;
}

uint32_t tfm_spm_hal_get_ns_MSP(void)
{
    return *((uint32_t *)memory_regions.non_secure_code_start);
}

uint32_t tfm_spm_hal_get_ns_entry_point(void)
{
    return *((uint32_t *)(memory_regions.non_secure_code_start+ 4));
}

enum tfm_plat_err_t tfm_spm_hal_set_secure_irq_priority(IRQn_Type irq_line)
{
    NVIC_SetPriority(irq_line, DEFAULT_IRQ_PRIORITY);
    return TFM_PLAT_ERR_SUCCESS;
}

void tfm_spm_hal_clear_pending_irq(IRQn_Type irq_line)
{
    NVIC_ClearPendingIRQ(irq_line);
}

void tfm_spm_hal_enable_irq(IRQn_Type irq_line)
{
    NVIC_EnableIRQ(irq_line);
}

void tfm_spm_hal_disable_irq(IRQn_Type irq_line)
{
    NVIC_DisableIRQ(irq_line);
}

#ifndef TFM_PSA_API
#include "mpu_armv8m_drv.h"
#include "region_defs.h"

struct mpu_armv8m_dev_t dev_mpu_s = { MPU_BASE };

#ifdef CONFIG_TFM_ENABLE_MEMORY_PROTECT
#define PARTITION_REGION_PERIPH_START   5
#define PARTITION_REGION_PERIPH_MAX_NUM 2

uint32_t periph_num_count = 0;
#endif /* CONFIG_TFM_ENABLE_MEMORY_PROTECT */

enum tfm_plat_err_t tfm_spm_hal_configure_default_isolation(
                  bool privileged,
                  const struct platform_data_t *platform_data)
{
    if (!platform_data) {
        return TFM_PLAT_ERR_INVALID_INPUT;
    }

    return TFM_PLAT_ERR_SUCCESS;
}
#endif
// eof

