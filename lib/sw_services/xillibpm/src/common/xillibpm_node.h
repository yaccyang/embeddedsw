/******************************************************************************
*
* Copyright (C) 2018 Xilinx, Inc.  All rights reserved.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
* XILINX  BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
* OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*
* Except as contained in this notice, the name of the Xilinx shall not be used
* in advertising or otherwise to promote the sale, use or other dealings in
* this Software without prior written authorization from Xilinx.
*
******************************************************************************/

#ifndef XILLIBPM_NODE_H_
#define XILLIBPM_NODE_H_

#define NODE_CLASS_SHIFT	26U
#define NODE_SUBCLASS_SHIFT	20U
#define NODE_TYPE_SHIFT		14U
#define NODE_INDEX_SHIFT	0U
#define NODE_CLASS_MASK_BITS    0x3F
#define NODE_SUBCLASS_MASK_BITS 0x3F
#define NODE_TYPE_MASK_BITS     0x3F
#define NODE_INDEX_MASK_BITS    0x3FFF
#define NODE_CLASS_MASK         (NODE_CLASS_MASK_BITS << NODE_CLASS_SHIFT)
#define NODE_SUBCLASS_MASK      (NODE_SUBCLASS_MASK_BITS << NODE_SUBCLASS_SHIFT)
#define NODE_TYPE_MASK          (NODE_TYPE_MASK_BITS << NODE_TYPE_SHIFT)
#define NODE_INDEX_MASK         (NODE_INDEX_MASK_BITS << NODE_INDEX_SHIFT)

#define NODEID(CLASS, SUBCLASS, TYPE, INDEX)	\
	((((CLASS) & NODE_CLASS_MASK_BITS) << NODE_CLASS_SHIFT) | \
	(((SUBCLASS) & NODE_SUBCLASS_MASK_BITS) << NODE_SUBCLASS_SHIFT) | \
	(((TYPE) & NODE_TYPE_MASK_BITS) << NODE_TYPE_SHIFT) | \
	(((INDEX) & NODE_INDEX_MASK_BITS) << NODE_INDEX_SHIFT))

#define NODECLASS(ID)		(((ID) & NODE_CLASS_MASK) >> NODE_CLASS_SHIFT)
#define NODESUBCLASS(ID)	(((ID) & NODE_SUBCLASS_MASK) >> NODE_SUBCLASS_SHIFT)
#define NODETYPE(ID)		(((ID) & NODE_TYPE_MASK) >> NODE_TYPE_SHIFT)
#define NODEINDEX(ID)		(((ID) & NODE_INDEX_MASK) >> NODE_INDEX_SHIFT)

#define LMIONODEID(PINNUM)	NODEID(XPM_NODECLASS_STMIC,\
	XPM_NODESUBCL_PIN, XPM_NODETYPE_LPD_MIO, (PINNUM) + XPM_NODEIDX_STMIC_LMIO_0)

#define PMIONODEID(PINNUM)	NODEID(XPM_NODECLASS_STMIC,\
	XPM_NODESUBCL_PIN, XPM_NODETYPE_PMC_MIO, (PINNUM) + XPM_NODEIDX_STMIC_PMIO_0)

/* Node class types */
enum class {
	XPM_NODECLASS_MIN,

	XPM_NODECLASS_POWER,
	XPM_NODECLASS_CLOCK,
	XPM_NODECLASS_RESET,
	XPM_NODECLASS_MEMIC,
	XPM_NODECLASS_STMIC,
	XPM_NODECLASS_DEVICE,
	XPM_NODECLASS_SUBSYSTEM,

	XPM_NODECLASS_MAX
} XPm_NodeClass;

/* Node subclass types */
typedef enum {
        /* Power nodes */
        XPM_NODESUBCL_POWER_ISLAND=1,
        XPM_NODESUBCL_POWER_DOMAIN,
} XPm_PowerNodeSubclass;

typedef enum {
        /* Clock nodes */
        XPM_NODESUBCL_CLOCK_PLL=1,
        XPM_NODESUBCL_CLOCK_OUT,
        XPM_NODESUBCL_CLOCK_REF,
} XPm_ClockNodeSubclass;

typedef enum {
        /* Reset nodes */
        XPM_NODESUBCL_RESET_PERIPHERAL=1,
        XPM_NODESUBCL_RESET_DBG,
        XPM_NODESUBCL_RESET_POR,
        XPM_NODESUBCL_RESET_SRST,
} XPm_ResetNodeSubclass;

typedef enum {
        /* Pin nodes */
        XPM_NODESUBCL_PIN=1,
} XPm_PinNodeSubclass;

typedef enum {
        /* Device types */
        XPM_NODESUBCL_DEV_CORE=1,
        XPM_NODESUBCL_DEV_PERIPH,
        XPM_NODESUBCL_DEV_MEM,
} XPm_DeviceNodeSubclass;

typedef enum {
	/* Subsystem classes */
	XPM_NODESUBCL_SUBSYSTEM=0,
} XPm_SubsystemSubclass;

/* Node types */
typedef enum {
        /* Power nodes */
        XPM_NODETYPE_POWER_ISLAND=1,
        XPM_NODETYPE_POWER_DOMAIN_PMC,
        XPM_NODETYPE_POWER_DOMAIN_PS_FULL,
        XPM_NODETYPE_POWER_DOMAIN_PS_LOW,
        XPM_NODETYPE_POWER_DOMAIN_NOC,
        XPM_NODETYPE_POWER_DOMAIN_CPM,
	XPM_NODETYPE_POWER_DOMAIN_ME,
	XPM_NODETYPE_POWER_DOMAIN_PL,
} XPm_PowerNodeType;

typedef enum {
        /* Clock nodes */
        XPM_NODETYPE_CLOCK_PLL=1,
        XPM_NODETYPE_CLOCK_OUT,
        XPM_NODETYPE_CLOCK_REF,
        XPM_NODETYPE_CLOCK_SUBNODE,
} XPm_ClockNodeType;

typedef enum {
        /* Reset nodes */
        XPM_NODETYPE_RESET_PERIPHERAL=1,
        XPM_NODETYPE_RESET_DBG,
        XPM_NODETYPE_RESET_POR,
        XPM_NODETYPE_RESET_SRST,
} XPm_ResetNodeType;

typedef enum {
        /* Pin nodes */
        XPM_NODETYPE_LPD_MIO=1,
        XPM_NODETYPE_PMC_MIO,
} XPm_PinNodeType;

typedef enum {
        /* Device types */
        XPM_NODETYPE_DEV_CORE_PMC=1,
        XPM_NODETYPE_DEV_CORE_PSM,
        XPM_NODETYPE_DEV_CORE_APU,
        XPM_NODETYPE_DEV_CORE_RPU,
        XPM_NODETYPE_DEV_OCM,
        XPM_NODETYPE_DEV_TCM,
        XPM_NODETYPE_DEV_L2CACHE,
        XPM_NODETYPE_DEV_DDR,
        XPM_NODETYPE_DEV_PERIPH,
} XPm_DeviceNodeType;

typedef enum {
	/* Subsystem types */
        XPM_NODETYPE_SUBSYSTEM=0,
} XPm_SubsystemTypes;

/* All node IDs */
typedef enum {
	/* Power nodes */
	XPM_NODEIDX_POWER_MIN,

	/* Power domains */
	XPM_NODEIDX_POWER_PMC,
	XPM_NODEIDX_POWER_LPD,
	XPM_NODEIDX_POWER_FPD,
	XPM_NODEIDX_POWER_NOC,
	XPM_NODEIDX_POWER_ME,
	XPM_NODEIDX_POWER_PLD,
	XPM_NODEIDX_POWER_CPM,
	XPM_NODEIDX_POWER_PL_SYSMON,

	/* LPD power islands */
	XPM_NODEIDX_POWER_RPU0_0,
	XPM_NODEIDX_POWER_GEM0,
	XPM_NODEIDX_POWER_GEM1,
	XPM_NODEIDX_POWER_OCM_0,
	XPM_NODEIDX_POWER_OCM_1,
	XPM_NODEIDX_POWER_OCM_2,
	XPM_NODEIDX_POWER_OCM_3,
	XPM_NODEIDX_POWER_TCM_0_A,
	XPM_NODEIDX_POWER_TCM_0_B,
	XPM_NODEIDX_POWER_TCM_1_A,
	XPM_NODEIDX_POWER_TCM_1_B,

	/* FPD power islands */
	XPM_NODEIDX_POWER_ACPU_0,
	XPM_NODEIDX_POWER_ACPU_1,
	XPM_NODEIDX_POWER_L2_BANK_0,

	XPM_NODEIDX_POWER_MAX,
} XPm_PowerNodeIndex;

enum {
	XPM_NODEIDX_CLK_MIN,
	XPM_NODEIDX_CLK_PMC_PLL,
	XPM_NODEIDX_CLK_APU_PLL,
	XPM_NODEIDX_CLK_RPU_PLL,
	XPM_NODEIDX_CLK_CPM_PLL,
	XPM_NODEIDX_CLK_NOC_PLL,
	XPM_NODEIDX_CLK_PLL_MAX,
	XPM_NODEIDX_CLK_PMC_PRESRC,
	XPM_NODEIDX_CLK_PMC_POSTCLK,
	XPM_NODEIDX_CLK_PMC_PLL_OUT,
	XPM_NODEIDX_CLK_PPLL,
	XPM_NODEIDX_CLK_NOC_PRESRC,
	XPM_NODEIDX_CLK_NOC_POSTCLK,
	XPM_NODEIDX_CLK_NOC_PLL_OUT,
	XPM_NODEIDX_CLK_NPLL,
	XPM_NODEIDX_CLK_APU_PRESRC,
	XPM_NODEIDX_CLK_APU_POSTCLK,
	XPM_NODEIDX_CLK_APU_PLL_OUT,
	XPM_NODEIDX_CLK_APLL,
	XPM_NODEIDX_CLK_RPU_PRESRC,
	XPM_NODEIDX_CLK_RPU_POSTCLK,
	XPM_NODEIDX_CLK_RPU_PLL_OUT,
	XPM_NODEIDX_CLK_RPLL,
	XPM_NODEIDX_CLK_CPM_PRESRC,
	XPM_NODEIDX_CLK_CPM_POSTCLK,
	XPM_NODEIDX_CLK_CPM_PLL_OUT,
	XPM_NODEIDX_CLK_CPLL,
	XPM_NODEIDX_CLK_PPLL_TO_XPD,
	XPM_NODEIDX_CLK_NPLL_TO_XPD,
	XPM_NODEIDX_CLK_APLL_TO_XPD,
	XPM_NODEIDX_CLK_RPLL_TO_XPD,
	XPM_NODEIDX_CLK_EFUSE_REF,
	XPM_NODEIDX_CLK_SYSMON_REF,
	XPM_NODEIDX_CLK_IRO_SUSPEND_REF,
	XPM_NODEIDX_CLK_USB_SUSPEND,
	XPM_NODEIDX_CLK_SWITCH_TIMEOUT,
	XPM_NODEIDX_CLK_RCLK_PMC,
	XPM_NODEIDX_CLK_RCLK_LPD,
	XPM_NODEIDX_CLK_WDT,
	XPM_NODEIDX_CLK_TTC0,
	XPM_NODEIDX_CLK_TTC1,
	XPM_NODEIDX_CLK_TTC2,
	XPM_NODEIDX_CLK_TTC3,
	XPM_NODEIDX_CLK_GEM_TSU,
	XPM_NODEIDX_CLK_GEM_TSU_LB,
	XPM_NODEIDX_CLK_MUXED_IRO_DIV2,
	XPM_NODEIDX_CLK_MUXED_IRO_DIV4,
	XPM_NODEIDX_CLK_PSM_REF,
	XPM_NODEIDX_CLK_GEM0_RX,
	XPM_NODEIDX_CLK_GEM0_TX,
	XPM_NODEIDX_CLK_GEM1_RX,
	XPM_NODEIDX_CLK_GEM1_TX,
	XPM_NODEIDX_CLK_CPM_CORE_REF,
	XPM_NODEIDX_CLK_CPM_LSBUS_REF,
	XPM_NODEIDX_CLK_CPM_DBG_REF,
	XPM_NODEIDX_CLK_CPM_AUX0_REF,
	XPM_NODEIDX_CLK_CPM_AUX1_REF,
	XPM_NODEIDX_CLK_QSPI_REF,
	XPM_NODEIDX_CLK_OSPI_REF,
	XPM_NODEIDX_CLK_SDIO0_REF,
	XPM_NODEIDX_CLK_SDIO1_REF,
	XPM_NODEIDX_CLK_PMC_LSBUS_REF,
	XPM_NODEIDX_CLK_I2C_REF,
	XPM_NODEIDX_CLK_TEST_PATTERN_REF,
	XPM_NODEIDX_CLK_DFT_OSC_REF,
	XPM_NODEIDX_CLK_PMC_PL0_REF,
	XPM_NODEIDX_CLK_PMC_PL1_REF,
	XPM_NODEIDX_CLK_PMC_PL2_REF,
	XPM_NODEIDX_CLK_PMC_PL3_REF,
	XPM_NODEIDX_CLK_CFU_REF,
	XPM_NODEIDX_CLK_SPARE_REF,
	XPM_NODEIDX_CLK_NPI_REF,
	XPM_NODEIDX_CLK_HSM0_REF,
	XPM_NODEIDX_CLK_HSM1_REF,
	XPM_NODEIDX_CLK_SD_DLL_REF,
	XPM_NODEIDX_CLK_FPD_TOP_SWITCH,
	XPM_NODEIDX_CLK_FPD_LSBUS,
	XPM_NODEIDX_CLK_ACPU,
	XPM_NODEIDX_CLK_DBG_TRACE,
	XPM_NODEIDX_CLK_DBG_FPD,
	XPM_NODEIDX_CLK_LPD_TOP_SWITCH,
	XPM_NODEIDX_CLK_ADMA,
	XPM_NODEIDX_CLK_LPD_LSBUS,
	XPM_NODEIDX_CLK_CPU_R5,
	XPM_NODEIDX_CLK_CPU_R5_CORE,
	XPM_NODEIDX_CLK_CPU_R5_OCM,
	XPM_NODEIDX_CLK_CPU_R5_OCM2,
	XPM_NODEIDX_CLK_IOU_SWITCH,
	XPM_NODEIDX_CLK_GEM0_REF,
	XPM_NODEIDX_CLK_GEM1_REF,
	XPM_NODEIDX_CLK_GEM_TSU_REF,
	XPM_NODEIDX_CLK_USB0_BUS_REF,
	XPM_NODEIDX_CLK_UART0_REF,
	XPM_NODEIDX_CLK_UART1_REF,
	XPM_NODEIDX_CLK_SPI0_REF,
	XPM_NODEIDX_CLK_SPI1_REF,
	XPM_NODEIDX_CLK_CAN0_REF,
	XPM_NODEIDX_CLK_CAN1_REF,
	XPM_NODEIDX_CLK_I2C0_REF,
	XPM_NODEIDX_CLK_I2C1_REF,
	XPM_NODEIDX_CLK_DBG_LPD,
	XPM_NODEIDX_CLK_TIMESTAMP_REF,
	XPM_NODEIDX_CLK_DBG_TSTMP,
	XPM_NODEIDX_CLK_CPM_TOPSW_REF,
	XPM_NODEIDX_CLK_USB3_DUAL_REF,
	XPM_NODEIDX_CLK_OUTCLK_MAX,
	XPM_NODEIDX_CLK_REF_CLK,
	XPM_NODEIDX_CLK_PL_ALT_REF_CLK,
	XPM_NODEIDX_CLK_MUXED_IRO,
	XPM_NODEIDX_CLK_PL_EXT,
	XPM_NODEIDX_CLK_PL_LB,
	XPM_NODEIDX_CLK_MIO_50_OR_51,
	XPM_NODEIDX_CLK_MIO_24_OR_25,
	XPM_NODEIDX_CLK_MAX,
} XPm_ClockNodeIndex;

typedef enum {
	/* Reset nodes */
	XPM_NODEIDX_RST_MIN,
	XPM_NODEIDX_RST_PMC_POR,
	XPM_NODEIDX_RST_PMC,
	XPM_NODEIDX_RST_PS_POR,
	XPM_NODEIDX_RST_PL_POR,
	XPM_NODEIDX_RST_NOC_POR,
	XPM_NODEIDX_RST_FPD_POR,
	XPM_NODEIDX_RST_ACPU_0_POR,
	XPM_NODEIDX_RST_ACPU_1_POR,
	XPM_NODEIDX_RST_OCM2_POR,
	XPM_NODEIDX_RST_PS_SRST,
	XPM_NODEIDX_RST_PL_SRST,
	XPM_NODEIDX_RST_NOC,
	XPM_NODEIDX_RST_NPI,
	XPM_NODEIDX_RST_SYS_RST_1,
	XPM_NODEIDX_RST_SYS_RST_2,
	XPM_NODEIDX_RST_SYS_RST_3,
	XPM_NODEIDX_RST_FPD,
	XPM_NODEIDX_RST_PL0,
	XPM_NODEIDX_RST_PL1,
	XPM_NODEIDX_RST_PL2,
	XPM_NODEIDX_RST_PL3,
	XPM_NODEIDX_RST_APU,
	XPM_NODEIDX_RST_ACPU_0,
	XPM_NODEIDX_RST_ACPU_1,
	XPM_NODEIDX_RST_ACPU_L2,
	XPM_NODEIDX_RST_ACPU_GIC,
	XPM_NODEIDX_RST_RPU_ISLAND,
	XPM_NODEIDX_RST_RPU_AMBA,
	XPM_NODEIDX_RST_R5_0,
	XPM_NODEIDX_RST_R5_1,
	XPM_NODEIDX_RST_SYSMON_PMC_SEQ_RST,
	XPM_NODEIDX_RST_SYSMON_PMC_CFG_RST,
	XPM_NODEIDX_RST_SYSMON_FPD_CFG_RST,
	XPM_NODEIDX_RST_SYSMON_FPD_SEQ_RST,
	XPM_NODEIDX_RST_SYSMON_LPD,
	XPM_NODEIDX_RST_PDMA_RST1,
	XPM_NODEIDX_RST_PDMA_RST0,
	XPM_NODEIDX_RST_ADMA,
	XPM_NODEIDX_RST_TIMESTAMP,
	XPM_NODEIDX_RST_OCM,
	XPM_NODEIDX_RST_OCM2_RST,
	XPM_NODEIDX_RST_IPI,
	XPM_NODEIDX_RST_SBI,
	XPM_NODEIDX_RST_LPD,
	XPM_NODEIDX_RST_QSPI,
	XPM_NODEIDX_RST_OSPI,
	XPM_NODEIDX_RST_SDIO_0,
	XPM_NODEIDX_RST_SDIO_1,
	XPM_NODEIDX_RST_I2C_PMC,
	XPM_NODEIDX_RST_GPIO_PMC,
	XPM_NODEIDX_RST_GEM_0,
	XPM_NODEIDX_RST_GEM_1,
	XPM_NODEIDX_RST_SPARE,
	XPM_NODEIDX_RST_USB_0,
	XPM_NODEIDX_RST_UART_0,
	XPM_NODEIDX_RST_UART_1,
	XPM_NODEIDX_RST_SPI_0,
	XPM_NODEIDX_RST_SPI_1,
	XPM_NODEIDX_RST_CAN_FD_0,
	XPM_NODEIDX_RST_CAN_FD_1,
	XPM_NODEIDX_RST_I2C_0,
	XPM_NODEIDX_RST_I2C_1,
	XPM_NODEIDX_RST_GPIO_LPD,
	XPM_NODEIDX_RST_TTC_0,
	XPM_NODEIDX_RST_TTC_1,
	XPM_NODEIDX_RST_TTC_2,
	XPM_NODEIDX_RST_TTC_3,
	XPM_NODEIDX_RST_SWDT_FPD,
	XPM_NODEIDX_RST_SWDT_LPD,
	XPM_NODEIDX_RST_USB,
	XPM_NODEIDX_RST_DPC,
	XPM_NODEIDX_RST_PMCDBG,
	XPM_NODEIDX_RST_DBG_TRACE,
	XPM_NODEIDX_RST_DBG_FPD,
	XPM_NODEIDX_RST_DBG_TSTMP,
	XPM_NODEIDX_RST_RPU0_DBG,
	XPM_NODEIDX_RST_RPU1_DBG,
	XPM_NODEIDX_RST_HSDP,
	XPM_NODEIDX_RST_DBG_LPD,
	XPM_NODEIDX_RST_CPM_POR,
	XPM_NODEIDX_RST_CPM,
	XPM_NODEIDX_RST_CPMDBG,
	XPM_NODEIDX_RST_PCIE_CFG,
	XPM_NODEIDX_RST_PCIE_CORE0,
	XPM_NODEIDX_RST_PCIE_CORE1,
	XPM_NODEIDX_RST_PCIE_DMA,
	XPM_NODEIDX_RST_CMN,
	XPM_NODEIDX_RST_L2_0,
	XPM_NODEIDX_RST_L2_1,
	XPM_NODEIDX_RST_ADDR_REMAP,
	XPM_NODEIDX_RST_CPI0,
	XPM_NODEIDX_RST_CPI1,
	XPM_NODEIDX_RST_MAX,
} XPm_ResetNodeIndex;

typedef enum {
	/* MIO nodes */
	XPM_NODEIDX_STMIC_MIN,

	XPM_NODEIDX_STMIC_LMIO_0,
	XPM_NODEIDX_STMIC_LMIO_1,
	XPM_NODEIDX_STMIC_LMIO_2,
	XPM_NODEIDX_STMIC_LMIO_3,
	XPM_NODEIDX_STMIC_LMIO_4,
	XPM_NODEIDX_STMIC_LMIO_5,
	XPM_NODEIDX_STMIC_LMIO_6,
	XPM_NODEIDX_STMIC_LMIO_7,
	XPM_NODEIDX_STMIC_LMIO_8,
	XPM_NODEIDX_STMIC_LMIO_9,
	XPM_NODEIDX_STMIC_LMIO_10,
	XPM_NODEIDX_STMIC_LMIO_11,
	XPM_NODEIDX_STMIC_LMIO_12,
	XPM_NODEIDX_STMIC_LMIO_13,
	XPM_NODEIDX_STMIC_LMIO_14,
	XPM_NODEIDX_STMIC_LMIO_15,
	XPM_NODEIDX_STMIC_LMIO_16,
	XPM_NODEIDX_STMIC_LMIO_17,
	XPM_NODEIDX_STMIC_LMIO_18,
	XPM_NODEIDX_STMIC_LMIO_19,
	XPM_NODEIDX_STMIC_LMIO_20,
	XPM_NODEIDX_STMIC_LMIO_21,
	XPM_NODEIDX_STMIC_LMIO_22,
	XPM_NODEIDX_STMIC_LMIO_23,
	XPM_NODEIDX_STMIC_LMIO_24,
	XPM_NODEIDX_STMIC_LMIO_25,
	XPM_NODEIDX_STMIC_PMIO_0,
	XPM_NODEIDX_STMIC_PMIO_1,
	XPM_NODEIDX_STMIC_PMIO_2,
	XPM_NODEIDX_STMIC_PMIO_3,
	XPM_NODEIDX_STMIC_PMIO_4,
	XPM_NODEIDX_STMIC_PMIO_5,
	XPM_NODEIDX_STMIC_PMIO_6,
	XPM_NODEIDX_STMIC_PMIO_7,
	XPM_NODEIDX_STMIC_PMIO_8,
	XPM_NODEIDX_STMIC_PMIO_9,
	XPM_NODEIDX_STMIC_PMIO_10,
	XPM_NODEIDX_STMIC_PMIO_11,
	XPM_NODEIDX_STMIC_PMIO_12,
	XPM_NODEIDX_STMIC_PMIO_13,
	XPM_NODEIDX_STMIC_PMIO_14,
	XPM_NODEIDX_STMIC_PMIO_15,
	XPM_NODEIDX_STMIC_PMIO_16,
	XPM_NODEIDX_STMIC_PMIO_17,
	XPM_NODEIDX_STMIC_PMIO_18,
	XPM_NODEIDX_STMIC_PMIO_19,
	XPM_NODEIDX_STMIC_PMIO_20,
	XPM_NODEIDX_STMIC_PMIO_21,
	XPM_NODEIDX_STMIC_PMIO_22,
	XPM_NODEIDX_STMIC_PMIO_23,
	XPM_NODEIDX_STMIC_PMIO_24,
	XPM_NODEIDX_STMIC_PMIO_25,
	XPM_NODEIDX_STMIC_PMIO_26,
	XPM_NODEIDX_STMIC_PMIO_27,
	XPM_NODEIDX_STMIC_PMIO_28,
	XPM_NODEIDX_STMIC_PMIO_29,
	XPM_NODEIDX_STMIC_PMIO_30,
	XPM_NODEIDX_STMIC_PMIO_31,
	XPM_NODEIDX_STMIC_PMIO_32,
	XPM_NODEIDX_STMIC_PMIO_33,
	XPM_NODEIDX_STMIC_PMIO_34,
	XPM_NODEIDX_STMIC_PMIO_35,
	XPM_NODEIDX_STMIC_PMIO_36,
	XPM_NODEIDX_STMIC_PMIO_37,
	XPM_NODEIDX_STMIC_PMIO_38,
	XPM_NODEIDX_STMIC_PMIO_39,
	XPM_NODEIDX_STMIC_PMIO_40,
	XPM_NODEIDX_STMIC_PMIO_41,
	XPM_NODEIDX_STMIC_PMIO_42,
	XPM_NODEIDX_STMIC_PMIO_43,
	XPM_NODEIDX_STMIC_PMIO_44,
	XPM_NODEIDX_STMIC_PMIO_45,
	XPM_NODEIDX_STMIC_PMIO_46,
	XPM_NODEIDX_STMIC_PMIO_47,
	XPM_NODEIDX_STMIC_PMIO_48,
	XPM_NODEIDX_STMIC_PMIO_49,
	XPM_NODEIDX_STMIC_PMIO_50,
	XPM_NODEIDX_STMIC_PMIO_51,

	XPM_NODEIDX_STMIC_MAX,
} XPm_StmicNodeIndex;

typedef enum {
	/* Device nodes */
	XPM_NODEIDX_DEV_MIN,

	/* Processor devices */
	XPM_NODEIDX_DEV_PMC_PROC,
	XPM_NODEIDX_DEV_PSM_PROC,
	XPM_NODEIDX_DEV_ACPU_0,
	XPM_NODEIDX_DEV_ACPU_1,
	XPM_NODEIDX_DEV_RPU0_0,
	XPM_NODEIDX_DEV_RPU0_1,

	/* Memory devices */
	XPM_NODEIDX_DEV_OCM_0,
	XPM_NODEIDX_DEV_OCM_1,
	XPM_NODEIDX_DEV_OCM_2,
	XPM_NODEIDX_DEV_OCM_3,
	XPM_NODEIDX_DEV_TCM_0_A,
	XPM_NODEIDX_DEV_TCM_0_B,
	XPM_NODEIDX_DEV_TCM_1_A,
	XPM_NODEIDX_DEV_TCM_1_B,
	XPM_NODEIDX_DEV_L2_BANK_0,
	XPM_NODEIDX_DEV_DDR_0,
	XPM_NODEIDX_DEV_DDR_1,
	XPM_NODEIDX_DEV_DDR_2,
	XPM_NODEIDX_DEV_DDR_3,
	XPM_NODEIDX_DEV_DDR_4,
	XPM_NODEIDX_DEV_DDR_5,
	XPM_NODEIDX_DEV_DDR_6,
	XPM_NODEIDX_DEV_DDR_7,

	/* LPD Peripheral devices */
	XPM_NODEIDX_DEV_USB_0,
	XPM_NODEIDX_DEV_GEM_0,
	XPM_NODEIDX_DEV_GEM_1,
	XPM_NODEIDX_DEV_SPI_0,
	XPM_NODEIDX_DEV_SPI_1,
	XPM_NODEIDX_DEV_I2C_0,
	XPM_NODEIDX_DEV_I2C_1,
	XPM_NODEIDX_DEV_CAN_FD_0,
	XPM_NODEIDX_DEV_CAN_FD_1,
	XPM_NODEIDX_DEV_UART_0,
	XPM_NODEIDX_DEV_UART_1,
	XPM_NODEIDX_DEV_GPIO,
	XPM_NODEIDX_DEV_TTC_0,
	XPM_NODEIDX_DEV_TTC_1,
	XPM_NODEIDX_DEV_TTC_2,
	XPM_NODEIDX_DEV_TTC_3,
	XPM_NODEIDX_DEV_SWDT_LPD,

	/* FPD Peripheral devices */
	XPM_NODEIDX_DEV_SWDT_FPD,

	/* PMC Peripheral devices */
	XPM_NODEIDX_DEV_OSPI,
	XPM_NODEIDX_DEV_QSPI,
	XPM_NODEIDX_DEV_GPIO_PMC,
	XPM_NODEIDX_DEV_I2C_PMC,
	XPM_NODEIDX_DEV_SDIO_0,
	XPM_NODEIDX_DEV_SDIO_1,

	XPM_NODEIDX_DEV_MAX
} XPm_DeviceNodeIndex;


/**
 * Subsystem IDs
 */
typedef enum {
	XPM_NODEIDX_SUBSYS_DEFAULT,
	XPM_NODEIDX_SUBSYS_PMC,
	XPM_NODEIDX_SUBSYS_PSM,
	XPM_NODEIDX_SUBSYS_APU,
	XPM_NODEIDX_SUBSYS_RPU0_LOCK,
	XPM_NODEIDX_SUBSYS_RPU0_0,
	XPM_NODEIDX_SUBSYS_RPU0_1,
	XPM_NODEIDX_SUBSYS_DDR0,
	XPM_NODEIDX_SUBSYS_ME,
	XPM_NODEIDX_SUBSYS_PL,

	XPM_NODEIDX_SUBSYS_MAX,
} XPm_SubsystemId;

#endif /* XILLIBPM_NODE_H_ */
