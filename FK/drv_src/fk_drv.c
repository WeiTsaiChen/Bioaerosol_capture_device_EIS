//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 	 fk_drv.c
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//  @brief 	 Driver Subroutine
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S
//
//**********************************************************************************************************************
#include "..\fk_udef.h"
#include "..\c_src\fk_glb_vars.h"
#include "fk_drv.h"
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
//! @fn          fk_sfr_init
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 Register initial function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void fk_sfr_init()
{

      FK_RESET_CLOCK_SETTING_API();	
//==================================================================================================================//      
#if (MAIN_USE_HSE == 1) && (MAIN_USE_MSI == 0)
      FK_TURN_ON_HSE_API();				
#else
      FK_TURN_ON_HSI_API();
#endif

#if (MAIN_USE_PLL == 1) && (MAIN_USE_MSI == 0)
      FK_PLL_CONFIG_API();     
      FK_ENABLE_PLL_API();    
#endif
#if MAIN_USE_MSI ==1 
      FK_SET_INIT_MSI_RANGE_API();
#endif
//==================================================================================================================// 
      FK_SET_FLASH_PREFETCH_API();
      FK_SET_FLASH_LATENCY_API();
      FK_AHB_SET_CLOCK_API();
      FK_APB1_SET_CLOCK_API();
      FK_APB2_SET_CLOCK_API();	
      FK_SET_SYSCLOCK_SOURCE_API();
      FK_SET_PRIORITY_GROUP_4_API();
      
      // Hardware interrupt handler
      fk_EXTI9_5_Handler();
      
    }
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn          FK_NMI_Handler
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 Register initial function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_NMI_Handler(void)
    {

    }
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn          fk_PVD_Handler
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 Register initial function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_PVD_Handler(void)
    {
        gfunc_fk_pvd_func();
    }
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn          fk_HardFault_Handler
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 Register initial function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_HardFault_Handler(void)
    {

    }

//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn          fk_MemManage_Handler
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 Register initial function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_MemManage_Handler(void)
    {

    }

//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn          fk_BusFault_Handler
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 Register initial function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_BusFault_Handler(void)
    {

    }

//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn          fk_UsageFault_Handler
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 Register initial function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_UsageFault_Handler(void)
    {

    }

//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn          fk_SVC_Handler
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 Register initial function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_SVC_Handler(void)
    {

    }
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn          fk_DebugMon_Handler
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 Register initial function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_DebugMon_Handler(void)
    {

    }

//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn          fk_PendSV_Handler
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 Register initial function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_PendSV_Handler(void)
    {

    }

//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn          fk_SysTick_Handler
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 Register initial function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_SysTick_Handler(void)
    {
        gfunc_fk_systick_func();
    }

//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn          fk_EXTI0_Handler
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 Register initial function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_EXTI0_Handler(void)
    {
        if(EXTI_GetFlagStatus(gt_fk_exti_line[0]) != RESET)
        {
          gfunc_fk_exti_func[0]();
          EXTI_ClearITPendingBit(gt_fk_exti_line[0]);
        }
    }
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn          fk_EXTI1_Handler
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 Register initial function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_EXTI1_Handler(void)
    {
        if(EXTI_GetFlagStatus(gt_fk_exti_line[1]) != RESET)
        {
          gfunc_fk_exti_func[1]();
          EXTI_ClearITPendingBit(gt_fk_exti_line[1]);
        }
    }
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn          fk_EXTI2_Handler
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 Register initial function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_EXTI2_Handler(void)
    {
        if(EXTI_GetFlagStatus(gt_fk_exti_line[2]) != RESET)
        {
          gfunc_fk_exti_func[2]();
          EXTI_ClearITPendingBit(gt_fk_exti_line[2]);
        }
    }
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn          fk_EXTI3_Handler
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 Register initial function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_EXTI3_Handler(void)
    {
        if(EXTI_GetFlagStatus(gt_fk_exti_line[3]) != RESET)
        {
          gfunc_fk_exti_func[3]();
          EXTI_ClearITPendingBit(gt_fk_exti_line[3]);
        }
    }
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn          fk_EXTI4_Handler
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 Register initial function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_EXTI4_Handler(void)
    {
        if(EXTI_GetFlagStatus(gt_fk_exti_line[4]) != RESET)
        {
          gfunc_fk_exti_func[4]();
          EXTI_ClearITPendingBit(gt_fk_exti_line[4]);
        }
    }

//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn          fk_EXTI9_5_Handler
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 Register initial function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_EXTI9_5_Handler(void)
    {
        UINT32 i;
        for (i=5; i<10; i++)
            if (EXTI_GetFlagStatus(gt_fk_exti_line[i]) != RESET)
                break;
        if (i==10)
            return ;
        gfunc_fk_exti_func[i]();
        EXTI_ClearITPendingBit(gt_fk_exti_line[i]);
    }
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn          fk_EXTI15_10_Handler
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 Register initial function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_EXTI15_10_Handler(void)
    {
        UINT32 i;
        for (i=10; i<16; i++)
            if (EXTI_GetFlagStatus(gt_fk_exti_line[i]) != RESET)
                break;
        if (i==16)
            return ;
        gfunc_fk_exti_func[i]();
        EXTI_ClearITPendingBit(gt_fk_exti_line[i]);
    }

//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn          fk_rtc_Handler
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 Register initial function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_rtc_Handler(void)
    {
        if (RTC_GetITStatus(RTC_IT_TS) != RESET)
        {
            gfunc_fk_rtc_func();
            RTC_ClearITPendingBit(RTC_IT_TS);
        }
    }

//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn          fk_rtc_alarm_Handler
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 Register initial function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_rtc_alarm_Handler(void)
    {
        if (RTC_GetITStatus(RTC_IT_ALRA) != RESET)
        {
            EXTI_ClearITPendingBit(EXTI_Line17);
            RTC_ClearITPendingBit(RTC_IT_ALRA);
            gfunc_fk_rtc_alarm_func();
        }
    }
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn          fk_wwatchdog_Handler
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 Register initial function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_wwatchdog_Handler(void)
    {
        void (*func)(void);
        func=(void(*)(void))0x0000;
        func();
    }

//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn          fk_dma_Handler
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 Register initial function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_dma_Handler(void)
    {
        UINT32 i;
        for (i=0; i<FK_DMA_TOTAL; i++)
            if (DMA_GetITStatus(gt_fk_dma_TC_register[0]))
                break;
        if(i!=FK_DMA_TOTAL)
        {
            *((UINT32*)&gs_fk_interrupt_list)|=(0x01<<i);
            gfunc_fk_dma_func[i]();
            DMA_ClearITPendingBit(gt_fk_dma_GL_register[i]);
        }
    }

//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn          fk_tim1_cc_Handler
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 Register initial function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void fk_tim5_cc_Handler(void)
{
        if(TIM_GetITStatus((TIM_TypeDef*)gt_fk_timer_register[FK_INTERRUPT5_INPUT_CAPTURE], TIM_IT_CC1<<gb_fk_capture_compare_channel) == SET)
        {
            gfunc_fk_timer_interrupt[FK_INTERRUPT5_INPUT_CAPTURE]();
            TIM_ClearITPendingBit((TIM_TypeDef*)gt_fk_timer_register[FK_INTERRUPT5_INPUT_CAPTURE], TIM_IT_CC1<<gb_fk_capture_compare_channel);
        }      
}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn          fk_tim2_Handler
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 Register initial function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_tim2_Handler(void)
    {
        if(TIM_GetITStatus((TIM_TypeDef *)gt_fk_timer_register[FK_INTERRUPT1_FUNC_ONCE],TIM_IT_Update) != RESET)
        {
              TIM_ClearITPendingBit((TIM_TypeDef *)gt_fk_timer_register[FK_INTERRUPT1_FUNC_ONCE],TIM_IT_Update);
              gfunc_fk_timer_interrupt[FK_INTERRUPT1_FUNC_ONCE]();
              TIM_ITConfig((TIM_TypeDef *)gt_fk_timer_register[FK_INTERRUPT1_FUNC_ONCE], TIM_IT_Update,DISABLE); 
        }
    }

//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn          fk_tim3_Handler
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 Register initial function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_tim3_Handler(void)
    {
        if(TIM_GetITStatus((TIM_TypeDef *)gt_fk_timer_register[FK_INTERRUPT2_FUNC_ONCE],TIM_IT_Update) != RESET)
        {      
            TIM_ClearITPendingBit((TIM_TypeDef *)gt_fk_timer_register[FK_INTERRUPT2_FUNC_ONCE],TIM_IT_Update);
            gfunc_fk_timer_interrupt[FK_INTERRUPT2_FUNC_ONCE]();
            TIM_ITConfig((TIM_TypeDef *)gt_fk_timer_register[FK_INTERRUPT2_FUNC_ONCE], TIM_IT_Update,DISABLE);
        }
    }

//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn          fk_tim4_Handler
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 Register initial function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_tim4_Handler(void)
    {
        if(TIM_GetITStatus((TIM_TypeDef *)gt_fk_timer_register[FK_INTERRUPT3_FUNC_CONTINUE],TIM_IT_Update) != RESET)
        {        
            TIM_ClearITPendingBit((TIM_TypeDef *)gt_fk_timer_register[FK_INTERRUPT3_FUNC_CONTINUE],TIM_IT_Update);
            gfunc_fk_timer_interrupt[FK_INTERRUPT3_FUNC_CONTINUE]();
            TIM_ClearFlag((TIM_TypeDef *)gt_fk_timer_register[FK_INTERRUPT3_FUNC_CONTINUE], TIM_FLAG_Update);
        }
    }

//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn          fk_tim3_Handler
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 Register initial function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_tim9_Handler(void)
    {
        if(TIM_GetITStatus((TIM_TypeDef *)gt_fk_timer_register[FK_INTERRUPT4_FUNC_CONTINUE],TIM_IT_Update) != RESET)
        {      
            TIM_ClearITPendingBit((TIM_TypeDef *)gt_fk_timer_register[FK_INTERRUPT4_FUNC_CONTINUE],TIM_IT_Update);
            gfunc_fk_timer_interrupt[FK_INTERRUPT4_FUNC_CONTINUE]();
            TIM_ClearFlag((TIM_TypeDef *)gt_fk_timer_register[FK_INTERRUPT4_FUNC_CONTINUE], TIM_FLAG_Update);
        }
    }

//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn          fk_uart1_Handler
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 Register initial function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_uart1_Handler(void)
    {        
        if(USART_GetITStatus((USART_TypeDef*)USART1_BASE, USART_IT_RXNE) == SET)
        {
            USART_ClearITPendingBit(USART1,USART_IT_RXNE);
            gfunc_fk_uart_rx_func[0]();
        }
        if(USART_GetITStatus((USART_TypeDef*)USART1_BASE, USART_IT_TXE) == SET)
        {
            USART_ClearITPendingBit(USART1,USART_IT_TXE);
            if (gfunc_fk_uart_tx_func[0]()==0)
            {
                FK_UART1_TX_WAIT_API();
                FK_UART1_TX_INTERRUPT_DISABLE_API();
                FK_UART1_LOW_SPEED_API();
            }
        }
        if(USART_GetFlagStatus(USART1,USART_FLAG_ORE)==SET)
        {
            USART_ClearFlag(USART1,USART_FLAG_ORE);    
            USART_ReceiveData(USART1);                
        }        
        
    }
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn          fk_uart2_Handler
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 Register initial function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_uart2_Handler(void)
    {
        if(USART_GetITStatus((USART_TypeDef*)USART2_BASE, USART_IT_RXNE) == SET)
        {
            USART_ClearITPendingBit(USART2,USART_IT_RXNE);
            gfunc_fk_uart_rx_func[1]();
        }
        if(USART_GetITStatus((USART_TypeDef*)USART2_BASE, USART_IT_TXE) == SET)
        {
            USART_ClearITPendingBit(USART2,USART_IT_TXE);
            if (gfunc_fk_uart_tx_func[1]()==0)
            {
                FK_UART2_TX_WAIT_API();
                FK_UART2_TX_INTERRUPT_DISABLE_API(); 
                FK_UART2_LOW_SPEED_API();
            }
        }
        if(USART_GetFlagStatus(USART2,USART_FLAG_ORE)==SET)
        {
            USART_ClearFlag(USART2,USART_FLAG_ORE);    
            USART_ReceiveData(USART2);                
        }    
    }
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn          fk_uart3_Handler
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 Register initial function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_uart3_Handler(void)
    {
        if(USART_GetITStatus((USART_TypeDef*)USART3_BASE, USART_IT_RXNE) == SET)
        {
            USART_ClearITPendingBit(USART3,USART_IT_RXNE);
            gfunc_fk_uart_rx_func[2]();
            USART_ClearFlag((USART_TypeDef*)USART3_BASE, USART_IT_RXNE);
        }
        if(USART_GetITStatus((USART_TypeDef*)USART3_BASE, USART_IT_TXE) == SET)
        {
            USART_ClearITPendingBit(USART3,USART_IT_TXE);
            if (gfunc_fk_uart_tx_func[2]()==0)
            {
                FK_UART3_TX_WAIT_API();
                FK_UART3_TX_INTERRUPT_DISABLE_API();
                FK_UART3_LOW_SPEED_API();
            }
        }
        if(USART_GetFlagStatus(USART3,USART_FLAG_ORE)==SET)
        {
            USART_ClearFlag(USART3,USART_FLAG_ORE);    
            USART_ReceiveData(USART3);                
        }
    }

//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn          fk_adc1_2_Handler
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 Register initial function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_adc1_2_Handler(void)
    {
        gfunc_fk_adc_func();
        FK_ADC1_CLR_INTERRUPT_FLAG_API();
    }
//**********************************************************************************************************************
//
// C   P L U S   P L U S   C O M P A T I A B L E   D E F I N I T I O N
//
//**********************************************************************************************************************
#ifdef __cplusplus
}
#endif

