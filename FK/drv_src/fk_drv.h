#ifndef FK_DRV_H
#define FK_DRV_H
//**********************************************************************************************************************
//
// C   P L U S   P L U S   C O M P A T I A B L E   D E F I N I T I O N
//
//**********************************************************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 fk_drv.h
//
//! @author 	 Willman Chen
//
//! @date 		 2010/10/25
//
//  @brief 		 Here declare driver function
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I / O   P O R T   D E F I N I T I O N
//
//**********************************************************************************************************************

//**********************************************************************************************************************
//
// M A C R O   D E F I N I T I O N
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// F U N C T I O N   P R O T O T Y P E S
//
//**********************************************************************************************************************
    void fk_sfr_init();
    void fk_NMI_Handler(void);
    void fk_HardFault_Handler(void);
    void fk_MemManage_Handler(void);
    void fk_BusFault_Handler(void);
    void fk_UsageFault_Handler(void);
    void fk_SVC_Handler(void);
    void fk_DebugMon_Handler(void);
    void fk_PendSV_Handler(void);
    void fk_SysTick_Handler(void);
    void fk_EXTI9_5_Handler(void);
    void fk_EXTI15_10_Handler(void);
    void fk_rtc_Handler(void);
    void fk_rtc_alarm_Handler(void);
    void fk_wwatchdog_Handler(void);
    void fk_dma_Handler(void);
    void fk_tim2_Handler(void);
    void fk_tim3_Handler(void);
    void fk_tim4_Handler(void);
    void fk_tim9_Handler(void);
    void fk_tim5_cc_Handler(void);
    void fk_adc1_2_Handler(void);
    void fk_PVD_Handler(void);
//**********************************************************************************************************************
//
// C   P L U S   P L U S   C O M P A T I A B L E   D E F I N I T I O N
//
//**********************************************************************************************************************
#ifdef __cplusplus
}
#endif
#endif		// FK_DRV_H 
