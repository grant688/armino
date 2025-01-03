// Copyright 2022-2023 Beken
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// This is a generated file, if you need to modify it, use the script to
// generate and modify all the struct.h, ll.h, reg.h, debug_dump.c files!

#pragma once


#ifdef __cplusplus
extern "C" {
#endif


#define AON_PMU_R0_ADDR (SOC_AON_PMU_REG_BASE + (0x0 << 2))

#define AON_PMU_R0_MEMCHK_BPS_POS (0)
#define AON_PMU_R0_MEMCHK_BPS_MASK (0x1)

#define AON_PMU_R0_FAST_BOOT_POS (1)
#define AON_PMU_R0_FAST_BOOT_MASK (0x1)

#define AON_PMU_R0_RESERVED_BIT_2_30_POS (2)
#define AON_PMU_R0_RESERVED_BIT_2_30_MASK (0x1fffffff)

#define AON_PMU_R0_GPIO_SLEEP_POS (31)
#define AON_PMU_R0_GPIO_SLEEP_MASK (0x1)

#define AON_PMU_R1_ADDR (SOC_AON_PMU_REG_BASE + (0x1 << 2))

#define AON_PMU_R1_TOUCH_SELECT_POS (0)
#define AON_PMU_R1_TOUCH_SELECT_MASK (0xf)

#define AON_PMU_R1_TOUCH_INT_EN_POS (4)
#define AON_PMU_R1_TOUCH_INT_EN_MASK (0xffff)

#define AON_PMU_R1_USBPLUG_INT_EN_POS (20)
#define AON_PMU_R1_USBPLUG_INT_EN_MASK (0x1)

#define AON_PMU_R1_CLK_MOD_POS (21)
#define AON_PMU_R1_CLK_MOD_MASK (0x1)

#define AON_PMU_R1_RESERVED_BIT_22_31_POS (22)
#define AON_PMU_R1_RESERVED_BIT_22_31_MASK (0x3ff)

#define AON_PMU_R2_ADDR (SOC_AON_PMU_REG_BASE + (0x2 << 2))

#define AON_PMU_R2_WDT_RST_ANA_POS (0)
#define AON_PMU_R2_WDT_RST_ANA_MASK (0x1)

#define AON_PMU_R2_WDT_RST_TOP_POS (1)
#define AON_PMU_R2_WDT_RST_TOP_MASK (0x1)

#define AON_PMU_R2_WDT_RST_AON_POS (2)
#define AON_PMU_R2_WDT_RST_AON_MASK (0x1)

#define AON_PMU_R2_WDT_RST_AWT_POS (3)
#define AON_PMU_R2_WDT_RST_AWT_MASK (0x1)

#define AON_PMU_R2_WDT_RST_GPIO_POS (4)
#define AON_PMU_R2_WDT_RST_GPIO_MASK (0x1)

#define AON_PMU_R2_WDT_RST_RTC_POS (5)
#define AON_PMU_R2_WDT_RST_RTC_MASK (0x1)

#define AON_PMU_R2_WDT_RST_WDT_POS (6)
#define AON_PMU_R2_WDT_RST_WDT_MASK (0x1)

#define AON_PMU_R2_WDT_RST_PMU_POS (7)
#define AON_PMU_R2_WDT_RST_PMU_MASK (0x1)

#define AON_PMU_R2_WDT_RST_PHY_POS (8)
#define AON_PMU_R2_WDT_RST_PHY_MASK (0x1)

#define AON_PMU_R2_RESERVED_BIT_9_31_POS (9)
#define AON_PMU_R2_RESERVED_BIT_9_31_MASK (0x7fffff)

#define AON_PMU_R3_ADDR (SOC_AON_PMU_REG_BASE + (0x3 << 2))

#define AON_PMU_R3_RSV_POS (0)
#define AON_PMU_R3_RSV_MASK (0xffffffff)

#define AON_PMU_R40_ADDR (SOC_AON_PMU_REG_BASE + (0x40 << 2))

#define AON_PMU_R40_WAKE1_DELAY_POS (0)
#define AON_PMU_R40_WAKE1_DELAY_MASK (0xf)

#define AON_PMU_R40_WAKE2_DELAY_POS (4)
#define AON_PMU_R40_WAKE2_DELAY_MASK (0xf)

#define AON_PMU_R40_WAKE3_DELAY_POS (8)
#define AON_PMU_R40_WAKE3_DELAY_MASK (0xf)

#define AON_PMU_R40_HALT1_DELAY_POS (12)
#define AON_PMU_R40_HALT1_DELAY_MASK (0xf)

#define AON_PMU_R40_HALT2_DELAY_POS (16)
#define AON_PMU_R40_HALT2_DELAY_MASK (0xf)

#define AON_PMU_R40_HALT3_DELAY_POS (20)
#define AON_PMU_R40_HALT3_DELAY_MASK (0xf)

#define AON_PMU_R40_HALT_VOLT_POS (24)
#define AON_PMU_R40_HALT_VOLT_MASK (0x1)

#define AON_PMU_R40_HALT_XTAL_POS (25)
#define AON_PMU_R40_HALT_XTAL_MASK (0x1)

#define AON_PMU_R40_HALT_CORE_POS (26)
#define AON_PMU_R40_HALT_CORE_MASK (0x1)

#define AON_PMU_R40_HALT_FLASH_POS (27)
#define AON_PMU_R40_HALT_FLASH_MASK (0x1)

#define AON_PMU_R40_HALT_ROSC_POS (28)
#define AON_PMU_R40_HALT_ROSC_MASK (0x1)

#define AON_PMU_R40_HALT_RESTEN_POS (29)
#define AON_PMU_R40_HALT_RESTEN_MASK (0x1)

#define AON_PMU_R40_HALT_ISOLAT_POS (30)
#define AON_PMU_R40_HALT_ISOLAT_MASK (0x1)

#define AON_PMU_R40_HALT_CLKENA_POS (31)
#define AON_PMU_R40_HALT_CLKENA_MASK (0x1)

#define AON_PMU_R41_ADDR (SOC_AON_PMU_REG_BASE + (0x41 << 2))

#define AON_PMU_R41_LPO_CONFIG_POS (0)
#define AON_PMU_R41_LPO_CONFIG_MASK (0x3)

#define AON_PMU_R41_FLSHSCK_IOCAP_POS (2)
#define AON_PMU_R41_FLSHSCK_IOCAP_MASK (0x3)

#define AON_PMU_R41_WAKEUP_ENA_POS (4)
#define AON_PMU_R41_WAKEUP_ENA_MASK (0x3f)

#define AON_PMU_R41_IO_DRV_POS (10)
#define AON_PMU_R41_IO_DRV_MASK (0x3)

#define AON_PMU_R41_RESERVED_BIT_12_13_POS (12)
#define AON_PMU_R41_RESERVED_BIT_12_13_MASK (0x3)

#define AON_PMU_R41_XTAL_SEL_POS (14)
#define AON_PMU_R41_XTAL_SEL_MASK (0x1)

#define AON_PMU_R41_RESERVED_BIT_15_23_POS (15)
#define AON_PMU_R41_RESERVED_BIT_15_23_MASK (0x1ff)

#define AON_PMU_R41_HALT_LPO_POS (24)
#define AON_PMU_R41_HALT_LPO_MASK (0x1)

#define AON_PMU_R41_HALT_BUSRST_POS (25)
#define AON_PMU_R41_HALT_BUSRST_MASK (0x1)

#define AON_PMU_R41_HALT_BUSISO_POS (26)
#define AON_PMU_R41_HALT_BUSISO_MASK (0x1)

#define AON_PMU_R41_HALT_BUSPWD_POS (27)
#define AON_PMU_R41_HALT_BUSPWD_MASK (0x1)

#define AON_PMU_R41_HALT_BLPISO_POS (28)
#define AON_PMU_R41_HALT_BLPISO_MASK (0x1)

#define AON_PMU_R41_HALT_BLPPWD_POS (29)
#define AON_PMU_R41_HALT_BLPPWD_MASK (0x1)

#define AON_PMU_R41_HALT_WLPISO_POS (30)
#define AON_PMU_R41_HALT_WLPISO_MASK (0x1)

#define AON_PMU_R41_HALT_WLPPWD_POS (31)
#define AON_PMU_R41_HALT_WLPPWD_MASK (0x1)
#define AON_PMU_R42_ADDR (SOC_AON_PMU_REG_BASE + (0x42 << 2))
#define AON_PMU_R43_ADDR (SOC_AON_PMU_REG_BASE + (0x43 << 2))

#define AON_PMU_R43_CLR_INT_TOUCHED_POS (0)
#define AON_PMU_R43_CLR_INT_TOUCHED_MASK (0xffff)

#define AON_PMU_R43_CLR_INT_USBPLUG_POS (16)
#define AON_PMU_R43_CLR_INT_USBPLUG_MASK (0x1)

#define AON_PMU_R43_CLR_WAKEUP_POS (17)
#define AON_PMU_R43_CLR_WAKEUP_MASK (0x1)

#define AON_PMU_R43_RESERVED_BIT_18_31_POS (18)
#define AON_PMU_R43_RESERVED_BIT_18_31_MASK (0x3fff)

#define AON_PMU_R70_ADDR (SOC_AON_PMU_REG_BASE + (0x70 << 2))

#define AON_PMU_R70_INT_TOUCHED_POS (0)
#define AON_PMU_R70_INT_TOUCHED_MASK (0xffff)

#define AON_PMU_R70_INT_USBPLUG_POS (16)
#define AON_PMU_R70_INT_USBPLUG_MASK (0x1)

#define AON_PMU_R70_RESERVED_BIT_17_31_POS (17)
#define AON_PMU_R70_RESERVED_BIT_17_31_MASK (0x7fff)

#define AON_PMU_R71_ADDR (SOC_AON_PMU_REG_BASE + (0x71 << 2))

#define AON_PMU_R71_TOUCH_STATE_POS (0)
#define AON_PMU_R71_TOUCH_STATE_MASK (0xffff)

#define AON_PMU_R71_USBPLUG_STATE_POS (16)
#define AON_PMU_R71_USBPLUG_STATE_MASK (0x1)

#define AON_PMU_R71_RESERVED_BIT_17_19_POS (17)
#define AON_PMU_R71_RESERVED_BIT_17_19_MASK (0x7)

#define AON_PMU_R71_WAKEUP_SOURCE_POS (20)
#define AON_PMU_R71_WAKEUP_SOURCE_MASK (0x1f)

#define AON_PMU_R71_RESERVED_BIT_25_31_POS (25)
#define AON_PMU_R71_RESERVED_BIT_25_31_MASK (0x7f)

#define AON_PMU_R7C_ADDR (SOC_AON_PMU_REG_BASE + (0x7c << 2))

#define AON_PMU_R7C_ID_POS (0)
#define AON_PMU_R7C_ID_MASK (0xffffffff)

#define AON_PMU_R7D_ADDR (SOC_AON_PMU_REG_BASE + (0x7d << 2))

#define AON_PMU_R7D_LCAL_POS (0)
#define AON_PMU_R7D_LCAL_MASK (0xff)

#define AON_PMU_R7D_L_POS (8)
#define AON_PMU_R7D_L_MASK (0x1)

#define AON_PMU_R7D_ADC_CAL_POS (9)
#define AON_PMU_R7D_ADC_CAL_MASK (0x3f)

#define AON_PMU_R7D_BGCAL_POS (15)
#define AON_PMU_R7D_BGCAL_MASK (0x3f)

#define AON_PMU_R7D_26MPLL_UNLOCK_POS (21)
#define AON_PMU_R7D_26MPLL_UNLOCK_MASK (0x1)

#define AON_PMU_R7D_DPLL_UNLOCK_POS (22)
#define AON_PMU_R7D_DPLL_UNLOCK_MASK (0x1)

#define AON_PMU_R7D_H1_POS (23)
#define AON_PMU_R7D_H1_MASK (0x1ff)

#define AON_PMU_R7E_ADDR (SOC_AON_PMU_REG_BASE + (0x7e << 2))

#define AON_PMU_R7E_CBCAL_POS (0)
#define AON_PMU_R7E_CBCAL_MASK (0x1f)

#define AON_PMU_R7E_AD_STATE_POS (5)
#define AON_PMU_R7E_AD_STATE_MASK (0xf)

#define AON_PMU_R7E_TD_STATES1_POS (9)
#define AON_PMU_R7E_TD_STATES1_MASK (0x1fff)

#define AON_PMU_R7E_H2_POS (22)
#define AON_PMU_R7E_H2_MASK (0x3ff)

#define AON_PMU_R7F_ADDR (SOC_AON_PMU_REG_BASE + (0x7f << 2))

#define AON_PMU_R7F_TD_STATES2_POS (0)
#define AON_PMU_R7F_TD_STATES2_MASK (0xffffffff)

#ifdef __cplusplus
}
#endif
