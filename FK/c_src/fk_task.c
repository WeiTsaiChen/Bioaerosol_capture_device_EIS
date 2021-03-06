//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 	 fk_task.c
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//  @brief 	 Task Subroutine
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S
//
//**********************************************************************************************************************
#include "..\fk_udef.h"
#include "fk_glb_vars.h"
#include "fk_idef.h"
#include "..\drv_src\fk_drv.h"
#include "fk_task.h"
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
//! @fn 	 fk_port_index
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 task function
//
//! @param	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    UINT8 fk_port_index(UINT32 port)
    {
        UINT8 i;
        for (i=0; i<FK_PORT_TOTAL; i++)
            if (port==(UINT32)gt_fk_port_index[i])
                break;
        return i;
    }

//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 fk_pin_index
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 task function
//
//! @param	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    UINT8 fk_pin_index(UINT32 pin)
    {
        UINT8 i;
        for (i=0; i<FK_PIN_TOTAL; i++)
            if (pin==(UINT32)gt_fk_pin_index[i])
                break;
        return i;
    }
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 fk_set_io
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 task function
//
//! @param	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_set_io(UINT32 port,UINT32 pin,UINT32 speed,UINT32 mode)
    {
        GPIO_InitTypeDef  GPIO_InitStructure;
        UINT8 port_index=fk_port_index(port);
        RCC_AHBPeriphClockCmd(gt_fk_periph_register[port_index], ENABLE);
        GPIO_InitStructure.GPIO_Pin = pin;
        GPIO_InitStructure.GPIO_Speed = (GPIOSpeed_TypeDef)speed;
        switch (mode)
        {
              case GPIO_Mode_Out_PP:
              {
                  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
                  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;  
                  GPIO_InitStructure.GPIO_Mode =GPIO_Mode_OUT;
                  break;  
              }
              case GPIO_Mode_AF_PP:
              {
                  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
                  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; 
                  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
                  break;
              }
              case GPIO_Mode_AIN_NOPULL: 
              {
                  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
                  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL; 
                  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;             
                  break;
              }
              case GPIO_Mode_Out_OD:
              {
                  GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
                  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;  
                  GPIO_InitStructure.GPIO_Mode =GPIO_Mode_OUT;  
                  break;
              }
              case GPIO_Mode_IN_FLOATING:
              {
                  GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
                  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;  
                  GPIO_InitStructure.GPIO_Mode =GPIO_Mode_IN;  
                  break;
              }          
              case GPIO_Mode_IPD:
              {
                  GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
                  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;  
                  GPIO_InitStructure.GPIO_Mode =GPIO_Mode_IN;  
                  break;
              }                
              case GPIO_Mode_IPU:
              {
                  GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
                  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;  
                  GPIO_InitStructure.GPIO_Mode =GPIO_Mode_IN;  
                  break;
              }        
              
        }
        GPIO_Init((GPIO_TypeDef*)port, &GPIO_InitStructure);
    }

//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 fk_get_crc
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 task function
//
//! @param	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    UINT32 fk_get_crc(UINT32 *data,UINT32 size)
    {
        UINT32 result;
        FK_ENABLE_CRC_API();
        CRC_ResetDR();
        result=CRC_CalcBlockCRC(data,size);
        FK_DISABLE_CRC_API();
        return result;
    }

//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 fk_set_io_interrupt
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 task function
//
//! @param	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_set_io_interrupt(UINT32 port,UINT32 pin,UINT32 mode,void(*func)(void),UINT32 enable)
    {
        GPIO_InitTypeDef GPIO_InitStructure;
        EXTI_InitTypeDef EXTI_InitStructure;
        UINT8 port_index=fk_port_index(port);
        UINT8 pin_index=fk_pin_index(pin);
        UINT8 priority;
        priority=gt_fk_exti_priority[pin_index];
        
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE); // ?
        if (enable==(UINT32) ENABLE)
        {
            RCC_AHBPeriphClockCmd(gt_fk_periph_register[port_index], ENABLE);
            GPIO_InitStructure.GPIO_Pin = pin;
            GPIO_Init((GPIO_TypeDef*)port, &GPIO_InitStructure);      
            GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
            GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;  
            GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
            GPIO_Init((GPIO_TypeDef*)port, &GPIO_InitStructure);
            
            SYSCFG_EXTILineConfig(gt_fk_portsource_register[port_index],gt_fk_pinsource_register[pin_index]);
            gfunc_fk_exti_func[pin_index]=func; // ?
            EXTI_InitStructure.EXTI_Line = gt_fk_exti_line[pin_index];
            EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
            EXTI_InitStructure.EXTI_Trigger = (EXTITrigger_TypeDef)mode;
            EXTI_InitStructure.EXTI_LineCmd = ENABLE;
            EXTI_Init(&EXTI_InitStructure);
        }
        fk_nvic_enable(gt_fk_exti_irq_register[pin_index],priority,enable);
        EXTI_ClearITPendingBit(gt_fk_exti_line[pin_index]);
    }
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 fk_set_io_interrupt
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 task function
//
//! @param	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_rtc_enable(UINT32 time)
    {
        UINT32 rtc_timing;
        EXTI_InitTypeDef EXTI_InitStructure;
        RTC_AlarmTypeDef RTC_AlarmStructure;
  
        RTC_DeInit();
        RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR, ENABLE);
        PWR_RTCAccessCmd(ENABLE);
        RCC_RTCResetCmd(ENABLE);
        RCC_RTCResetCmd(DISABLE);
#if MAIN_USE_LSE == 1
        FK_TURN_ON_LSE_API();
        RCC_RTCCLKConfig(RCC_RTCCLKSource_LSE);
#endif
#if MAIN_USE_LSI == 1
        FK_TURN_ON_LSI_API();
        RCC_RTCCLKConfig(RCC_RTCCLKSource_LSI);
#endif  
#if MAIN_RTC_CALENDAR == 1
        RTC_TimeTypeDef  RTC_TimeStruct;
        RTC_InitTypeDef RTC_InitStructure;
        RTC_InitStructure.RTC_AsynchPrediv = 0; // 0x7F;
        RTC_InitStructure.RTC_SynchPrediv  = 0; // 0xFF;
        RTC_InitStructure.RTC_HourFormat   = RTC_HourFormat_24;
        RTC_Init(&RTC_InitStructure);
        
        /* Set the time to 00h 00mn 00s AM */
        RTC_TimeStruct.RTC_H12     = RTC_H12_AM;
        RTC_TimeStruct.RTC_Hours   = 0x00;
        RTC_TimeStruct.RTC_Minutes = 0x00;
        RTC_TimeStruct.RTC_Seconds = 0x00;  
        RTC_SetTime(RTC_Format_BIN, &RTC_TimeStruct);
#endif
        RCC_RTCCLKCmd(ENABLE);     
                
        RTC_WaitForSynchro();

        EXTI_ClearITPendingBit(EXTI_Line17);
        EXTI_InitStructure.EXTI_Line = EXTI_Line17;
        EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
        EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
        EXTI_InitStructure.EXTI_LineCmd = ENABLE;
        EXTI_Init(&EXTI_InitStructure);
        
        fk_nvic_enable(RTC_Alarm_IRQn,FK_RTC_ALARM_PRIORITY,ENABLE);
        RTC_AlarmStructure.RTC_AlarmMask = RTC_AlarmMask_All;
        RTC_SetAlarm(RTC_Format_BIN, RTC_Alarm_A, &RTC_AlarmStructure);
        switch (MAIN_RTC_TIMING)
        {
            case 1:   rtc_timing=RTC_AlarmSubSecondMask_SS14;   break;
            case 2:   rtc_timing=RTC_AlarmSubSecondMask_SS14_7;    break;
            case 4:   rtc_timing=RTC_AlarmSubSecondMask_SS14_6;    break;
            case 8:   rtc_timing=RTC_AlarmSubSecondMask_SS14_5;    break;
            case 16:  rtc_timing=RTC_AlarmSubSecondMask_SS14_4;    break;
            case 32:  rtc_timing=RTC_AlarmSubSecondMask_SS14_3;    break;
            case 64:  rtc_timing=RTC_AlarmSubSecondMask_SS14_2;    break;
            case 128:  rtc_timing=RTC_AlarmSubSecondMask_SS14_1;   break;
            default:  rtc_timing=RTC_AlarmSubSecondMask_SS14_5;    break;
        }
        RTC_AlarmSubSecondConfig(RTC_Alarm_A, 0xFF, rtc_timing);
        RTC_ITConfig(RTC_IT_ALRA, ENABLE);
        RTC_AlarmCmd(RTC_Alarm_A, ENABLE);

    }
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 fk_set_rtc_second_func
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 task function
//
//! @param	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_set_rtc_second_func(void(*func)(void))
    {
/*
        gfunc_fk_rtc_func=func;
        RTC_ITConfig(RTC_IT_SEC, ENABLE);
        RTC_ClearITPendingBit(RTC_IT_SEC);
        fk_nvic_enable(RTC_IRQn,FK_RTC_PRIORITY,ENABLE);
*/
    }

//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 fk_write_flash
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 task function
//
//! @param	 None
/**
  * @brief  Clears the FLASH's pending flags.
  * @param  FLASH_FLAG: specifies the FLASH flags to clear.
  *   This parameter can be any combination of the following values:
  *     @arg FLASH_FLAG_EOP: FLASH End of Operation flag
  *     @arg FLASH_FLAG_WRPERR: FLASH Write protected error flag 
  *     @arg FLASH_FLAG_PGAERR: FLASH Programming Alignment error flag 
  *     @arg FLASH_FLAG_SIZERR: FLASH size error flag    
  *     @arg FLASH_FLAG_OPTVERR: FLASH Option validity error flag
  *     @arg FLASH_FLAG_OPTVERRUSR: FLASH Option User validity error flag
  *     @arg FLASH_FLAG_RDERR: FLASH Read protected error flag (available only in STM32L1XX_MDP devices)
  * @retval None
  */
//
//**********************************************************************************************************************
    UINT32 fk_write_flash(UINT32 page,UINT32 *buf,UINT32 size)
    {
        UINT32 addr=FK_M3_FLASH_START+(page*FK_FLASH_PAGE_SIZE);
        UINT32 i,status;
        FLASH_Unlock();
        FLASH_ClearFlag(FLASH_FLAG_EOP | FLASH_FLAG_PGAERR | FLASH_FLAG_WRPERR);
        for (i=0; i<FK_NEED_PAGE; i++)
        {
            status=FLASH_ErasePage(addr+i*FK_FLASH_PAGE_SIZE);
            if (status!=FLASH_COMPLETE)
                return 0;
        }

        for (i=0; i<size; i+=sizeof(UINT32))
        {
            status=FLASH_FastProgramWord(addr+i,*(buf+(i/sizeof(UINT32))));
            if (status!=FLASH_COMPLETE)
                return 0;
        }
        FLASH_Lock();
        return 1;
    }

//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 fk_write_flash
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 task function
//
//! @param	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_read_flash(UINT32 page,UINT32 *buf,UINT32 size)
    {
        UINT32 i;
        UINT32 addr=FK_M3_FLASH_START+(page*FK_FLASH_PAGE_SIZE);
        UINT32 *read=(UINT32*)addr;
        for (i=0;i<size; i+=4,read++,buf++)
            *buf=*read;
    }

//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 fk_watchdog_enable
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 task function
//
//! @param	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_watchdog_enable()
    {
        IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
        IWDG_SetPrescaler(IWDG_Prescaler_64);
        IWDG_SetReload(FK_IWATCH_DOG_TIME);
        IWDG_ReloadCounter();
        IWDG_Enable();
    }

//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 fk_wwatchdog_enable
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 task function
//
//! @param	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_wwatchdog_enable()
    {
        RCC_APB1PeriphClockCmd(RCC_APB1Periph_WWDG, ENABLE);
        WWDG_SetPrescaler(WWDG_Prescaler_8);
        WWDG_SetWindowValue(FK_WWATCH_DOG_RESET_VALUE);
        WWDG_Enable(FK_WWATCH_DOG_RESET_VALUE);
        WWDG_ClearFlag();
        WWDG_EnableIT();
    }
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 fk_speed_up
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 task function
//
//! @param	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_speed_up()
    {
/*
        if(PWR_GetFlagStatus(PWR_FLAG_WU) != RESET)
        {
		//========================================================================// 
#if MAIN_USE_HSE == 1
            FK_TURN_ON_HSE_API();
#endif
		//========================================================================// 
#if MAIN_USE_HSI == 1
            FK_TURN_ON_HSI_API();
#endif
		//========================================================================// 
		#if (MAIN_USE_HSE == 1) && (MAIN_USE_PLL ==1) 
			FK_TURN_ON_HSE_API();
			FK_PLL_CONFIG_API();
	                FK_PREDIV1_CONFIG_API();    
			FK_ENABLE_PLL_API(); 
#endif
		//========================================================================// 
		#if (MAIN_USE_HSI == 1) && (MAIN_USE_PLL == 1) 
			FK_TURN_ON_HSI_API();
	                FK_PLL_CONFIG_API();
                        FK_ENABLE_PLL_API();
		#endif
		//========================================================================//  

            FK_SET_SYSCLOCK_SOURCE_API();
        }
*/
    }
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 fk_enter_stop_mode
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 task function
//
//! @param	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
  void fk_enter_stop_mode()
  {
        UINT32 *ptr=(UINT32*)&gs_fk_interrupt_list;
        FK_RELOAD_IWATCHDOG_API();
        if (*ptr==0)
        {
#if MAIN_LOW_POWER_MODE == 1
            PWR_EnterSTOPMode(PWR_Regulator_LowPower, PWR_STOPEntry_WFI);
#endif
#if MAIN_ENTER_SLEEP_MODE == 1
            FK_ENTER_SLEEP_MODE_API();
#endif
        }
        FK_RELOAD_IWATCHDOG_API();
  }

//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 fk_dma_enable
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 task function
//
//! @param	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_dma_enable(UINT8 channel,UINT32 *source,UINT32 *dest,UINT32 size,void(*func)(void))
    {
        DMA_InitTypeDef  DMA_InitStructure;

        if (channel<=7)
            RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
        else
            RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA2, ENABLE);

        fk_nvic_enable(gt_fk_dma_irq_register[channel],gt_fk_dma_priority[channel],ENABLE);
        DMA_DeInit((DMA_Channel_TypeDef *)gt_fk_dma_channel_register[channel]);
        DMA_InitStructure.DMA_PeripheralBaseAddr = (UINT32)source;
        DMA_InitStructure.DMA_MemoryBaseAddr = (UINT32)dest;
        DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
        DMA_InitStructure.DMA_BufferSize = size;
        DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Enable;
        DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
        DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Word;
        DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Word;
        DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;
        DMA_InitStructure.DMA_Priority = DMA_Priority_High;
        DMA_InitStructure.DMA_M2M = DMA_M2M_Enable;
        DMA_Init((DMA_Channel_TypeDef *)gt_fk_dma_channel_register[channel], &DMA_InitStructure);
        *((UINT16*)&gs_fk_interrupt_list)|=((0x01)<<(channel));
        gfunc_fk_dma_func[channel]=func;
        DMA_ITConfig((DMA_Channel_TypeDef *)gt_fk_dma_channel_register[channel], DMA_IT_TC, ENABLE);
        DMA_Cmd((DMA_Channel_TypeDef *)gt_fk_dma_channel_register[channel], ENABLE);

    }

//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 fk_nvic_enable
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 task function
//
//! @param	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_nvic_enable(UINT32 irq_channel,UINT32 priority,UINT32 enable)
    {
        NVIC_InitTypeDef NVIC_InitStructure;
        NVIC_InitStructure.NVIC_IRQChannel = irq_channel;
        NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = priority%16;   
        NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;          
        NVIC_InitStructure.NVIC_IRQChannelCmd = (FunctionalState)enable;
        
        // NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
        
        NVIC_Init(&NVIC_InitStructure);
    }
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 fk_nvic_disable
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 task function
//
//! @param	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_nvic_disable(UINT32 irq_channel)
    {
        NVIC_InitTypeDef NVIC_InitStructure;
        NVIC_InitStructure.NVIC_IRQChannel = irq_channel;
        NVIC_InitStructure.NVIC_IRQChannelCmd = DISABLE;
        NVIC_Init(&NVIC_InitStructure);
    }

//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 fk_timer_enable
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 task function
//
//! @param	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_timer_interrupt_enable(UINT8 timer,UINT32 prescale,UINT32 count,void(*func)(void))
    {
        if(count ==0)
        	return;
        else if(count == 1)	
        {
        	count = 2;
        	prescale = prescale/2;
        }
        
        TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
        gfunc_fk_timer_interrupt[timer]=func;
        if (timer != FK_INTERRUPT4_FUNC_CONTINUE )
            RCC_APB1PeriphClockCmd(gt_fk_timer_periph_register[timer], ENABLE);
        else
            RCC_APB2PeriphClockCmd(gt_fk_timer_periph_register[timer], ENABLE);
        TIM_TimeBaseStructure.TIM_Period = count-1;
        TIM_TimeBaseStructure.TIM_Prescaler = prescale-1;
        TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
        TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Down;
        TIM_TimeBaseInit((TIM_TypeDef *)gt_fk_timer_register[timer], &TIM_TimeBaseStructure);
        TIM_PrescalerConfig((TIM_TypeDef *)gt_fk_timer_register[timer], prescale, TIM_PSCReloadMode_Immediate);
        fk_nvic_enable(gt_fk_timer_irq[timer],gt_fk_timer_priority[timer],ENABLE);
        TIM_ClearFlag((TIM_TypeDef *)gt_fk_timer_register[timer], TIM_FLAG_Update);
        TIM_ITConfig((TIM_TypeDef *)gt_fk_timer_register[timer], TIM_IT_Update,ENABLE);
        TIM_Cmd((TIM_TypeDef *)gt_fk_timer_register[timer], ENABLE);
    }

//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 fk_timer_capture_enable
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 task function
//
//! @param	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_timer_capture_enable(UINT8 timer,UINT16 channel,UINT32 port,UINT32 pin,UINT16 edge,void(*func)(void))
    {
        TIM_ICInitTypeDef  TIM_ICInitStructure;
        UINT8 pin_index=fk_pin_index(pin);
        RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5, ENABLE);
        fk_set_io(port,pin,GPIO_Speed_40MHz,GPIO_Mode_AF_PP);

        GPIO_PinAFConfig((GPIO_TypeDef*)port,gt_fk_pinsource_register[pin_index],GPIO_AF_TIM5);
        
        gfunc_fk_timer_interrupt[timer]=func;
        gb_fk_capture_compare_channel=channel;

        switch (channel)
        {
            case FK_TIMER_CHANNEL1:
                TIM_ICInitStructure.TIM_Channel = TIM_Channel_1;
                break;
            case FK_TIMER_CHANNEL2:
                TIM_ICInitStructure.TIM_Channel = TIM_Channel_2;
                break;
            case FK_TIMER_CHANNEL3:
                TIM_ICInitStructure.TIM_Channel = TIM_Channel_3;
                break;
            case FK_TIMER_CHANNEL4:
                TIM_ICInitStructure.TIM_Channel = TIM_Channel_4;
                break;
        }

        TIM_ICInitStructure.TIM_ICPolarity = edge;
        TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;
        TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;
        TIM_ICInitStructure.TIM_ICFilter = 0x0;
        TIM_ICInit((TIM_TypeDef*)gt_fk_timer_register[timer], &TIM_ICInitStructure);
        TIM_Cmd((TIM_TypeDef*)gt_fk_timer_register[timer], ENABLE);

        switch (channel)
        {
            case FK_TIMER_CHANNEL1:
                TIM_ITConfig((TIM_TypeDef*)gt_fk_timer_register[timer], TIM_IT_CC1, ENABLE);
                break;
            case FK_TIMER_CHANNEL2:
                TIM_ITConfig((TIM_TypeDef*)gt_fk_timer_register[timer], TIM_IT_CC2, ENABLE);
                break;
            case FK_TIMER_CHANNEL3:
                TIM_ITConfig((TIM_TypeDef*)gt_fk_timer_register[timer], TIM_IT_CC3, ENABLE);
                break;
            case FK_TIMER_CHANNEL4:
                TIM_ITConfig((TIM_TypeDef*)gt_fk_timer_register[timer], TIM_IT_CC4, ENABLE);
                break;
        } 
        fk_nvic_enable(gt_fk_timer_irq[timer],FK_TIM5_CC_PRIORITY,ENABLE);
    }
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 fk_timer_enable
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 task function
//
//! @param	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_uart_init(UINT8 comport,UINT32 baudrate,UINT16 bits,UINT16 stop_bits,UINT16 parity,UINT8 mode,UINT8(*tx_func)(void),void(*rx_func)(void))
    {
        GPIO_InitTypeDef  GPIO_InitStructure;
        USART_InitTypeDef USART_InitStructure;
        UINT32 port=gt_fk_uart_port_register[comport];
        UINT32 tx_pin=gt_fk_uart_tx_pin_register[comport];
        UINT32 rx_pin=gt_fk_uart_rx_pin_register[comport];
        UINT8 port_index=fk_port_index(port);
        UINT8 tx_pin_index=fk_pin_index(tx_pin);
        UINT8 rx_pin_index=fk_pin_index(rx_pin);


        RCC_AHBPeriphClockCmd(gt_fk_periph_register[port_index], ENABLE);

        if (comport<=FK_UART1_REMAP)
            RCC_APB2PeriphClockCmd(gt_fk_uart_periph_register[comport], ENABLE);
        else
            RCC_APB1PeriphClockCmd(gt_fk_uart_periph_register[comport], ENABLE);


        GPIO_InitStructure.GPIO_Pin = tx_pin | rx_pin;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_40MHz;
        GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
        GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
        GPIO_Init((GPIO_TypeDef*)port, &GPIO_InitStructure);

        GPIO_PinAFConfig((GPIO_TypeDef*)port,gt_fk_pinsource_register[tx_pin_index],gt_fk_uart_remap_register[comport/2]);
        GPIO_PinAFConfig((GPIO_TypeDef*)port,gt_fk_pinsource_register[rx_pin_index],gt_fk_uart_remap_register[comport/2]);

        USART_InitStructure.USART_BaudRate = baudrate;
        USART_InitStructure.USART_WordLength = bits;
        USART_InitStructure.USART_StopBits = stop_bits;
        USART_InitStructure.USART_Parity = parity;
        USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
        USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
        USART_Init((USART_TypeDef*)gt_fk_uart_name[comport], &USART_InitStructure);

        if (mode==FK_UART_INTERRUPT_MODE)
        {
            gfunc_fk_uart_tx_func[comport/2]=tx_func;
            gfunc_fk_uart_rx_func[comport/2]=rx_func;
            fk_nvic_enable(gt_fk_uart_irq_register[comport/2],gt_fk_uart_priority[comport/2],ENABLE);
            USART_ITConfig((USART_TypeDef*)gt_fk_uart_name[comport], USART_IT_RXNE, ENABLE);
        }

        USART_Cmd((USART_TypeDef*)gt_fk_uart_name[comport], ENABLE);
    }

//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 fk_adc_functions
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 task function
//
//! @param	 None
/*
#define ADC_SampleTime_4Cycles                     ((uint8_t)0x00)
#define ADC_SampleTime_9Cycles                     ((uint8_t)0x01)
#define ADC_SampleTime_16Cycles                    ((uint8_t)0x02)
#define ADC_SampleTime_24Cycles                    ((uint8_t)0x03)
#define ADC_SampleTime_48Cycles                    ((uint8_t)0x04)
#define ADC_SampleTime_96Cycles                    ((uint8_t)0x05)
#define ADC_SampleTime_192Cycles                   ((uint8_t)0x06)
#define ADC_SampleTime_384Cycles                   ((uint8_t)0x07)
    
// ADC Bank A Channels ------------------------------------------------------- 
#define ADC_Channel_0                              ((uint8_t)0x00)
#define ADC_Channel_1                              ((uint8_t)0x01)
#define ADC_Channel_2                              ((uint8_t)0x02)
#define ADC_Channel_3                              ((uint8_t)0x03)

#define ADC_Channel_6                              ((uint8_t)0x06)
#define ADC_Channel_7                              ((uint8_t)0x07)
#define ADC_Channel_8                              ((uint8_t)0x08)
#define ADC_Channel_9                              ((uint8_t)0x09)
#define ADC_Channel_10                             ((uint8_t)0x0A)
#define ADC_Channel_11                             ((uint8_t)0x0B)
#define ADC_Channel_12                             ((uint8_t)0x0C)


// ADC Bank B Channels -------------------------------------------------------
#define ADC_Channel_0b                             ADC_Channel_0
#define ADC_Channel_1b                             ADC_Channel_1
#define ADC_Channel_2b                             ADC_Channel_2
#define ADC_Channel_3b                             ADC_Channel_3

#define ADC_Channel_6b                             ADC_Channel_6
#define ADC_Channel_7b                             ADC_Channel_7
#define ADC_Channel_8b                             ADC_Channel_8
#define ADC_Channel_9b                             ADC_Channel_9
#define ADC_Channel_10b                            ADC_Channel_10
#define ADC_Channel_11b                            ADC_Channel_11
#define ADC_Channel_12b                            ADC_Channel_12

// ADC Common Channels (ADC Bank A and B) ------------------------------------
#define ADC_Channel_4                              ((uint8_t)0x04)
#define ADC_Channel_5                              ((uint8_t)0x05)

#define ADC_Channel_13                             ((uint8_t)0x0D)
#define ADC_Channel_14                             ((uint8_t)0x0E)
#define ADC_Channel_15                             ((uint8_t)0x0F)
#define ADC_Channel_16                             ((uint8_t)0x10)
#define ADC_Channel_17                             ((uint8_t)0x11)
#define ADC_Channel_18                             ((uint8_t)0x12)
#define ADC_Channel_19                             ((uint8_t)0x13)
#define ADC_Channel_20                             ((uint8_t)0x14)
#define ADC_Channel_21                             ((uint8_t)0x15)
#define ADC_Channel_22                             ((uint8_t)0x16)
#define ADC_Channel_23                             ((uint8_t)0x17)
#define ADC_Channel_24                             ((uint8_t)0x18)
#define ADC_Channel_25                             ((uint8_t)0x19)

#define ADC_Channel_27                             ((uint8_t)0x1B)
#define ADC_Channel_28                             ((uint8_t)0x1C)
#define ADC_Channel_29                             ((uint8_t)0x1D)
#define ADC_Channel_30                             ((uint8_t)0x1E)
#define ADC_Channel_31                             ((uint8_t)0x1F)    
*/
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_adc_functions(UINT32 port,UINT32 pin,UINT8 channel,UINT8 dma_channel,UINT8 func_index,UINT8 func_mode,void (*func)(void),UINT16 *buf,UINT32 size)
    {
        GPIO_InitTypeDef GPIO_InitStructure;
        ADC_InitTypeDef ADC_InitStructure;
        DMA_InitTypeDef DMA_InitStructure;
        NVIC_InitTypeDef   NVIC_InitStructure;
        UINT8 port_index=fk_port_index(port);
        UINT8 pin_index=fk_pin_index(pin);
        RCC_HSICmd(ENABLE);
        while(RCC_GetFlagStatus(RCC_FLAG_HSIRDY) == RESET);
        if (func_index==FK_ADC_DMA_FUNC)
        {
            if (dma_channel<=7)
                RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
            else
                RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA2, ENABLE);
            fk_nvic_enable(gt_fk_dma_irq_register[dma_channel],gt_fk_dma_priority[dma_channel],ENABLE);
            DMA_DeInit((DMA_Channel_TypeDef *)gt_fk_dma_channel_register[dma_channel]);
            DMA_InitStructure.DMA_PeripheralBaseAddr = (UINT32)0x40012458; //(UINT32)0x40012458;  ADC1->DR;
            DMA_InitStructure.DMA_MemoryBaseAddr = (UINT32)buf;
            DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
            DMA_InitStructure.DMA_BufferSize = size;
            DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
            DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
            DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
            DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
            DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;  // DMA_Mode_Circular   DMA_Mode_Normal
            DMA_InitStructure.DMA_Priority = DMA_Priority_High;
            DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
            DMA_Init((DMA_Channel_TypeDef *)gt_fk_dma_channel_register[dma_channel], &DMA_InitStructure);
            gfunc_fk_dma_func[dma_channel]=func;
            DMA_ITConfig((DMA_Channel_TypeDef *)gt_fk_dma_channel_register[dma_channel], DMA_IT_TC, ENABLE);
            DMA_Cmd((DMA_Channel_TypeDef *)gt_fk_dma_channel_register[dma_channel], ENABLE);
        }
        
        RCC_AHBPeriphClockCmd(gt_fk_periph_register[port_index], ENABLE);
        GPIO_InitStructure.GPIO_Pin =  pin;
        GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AN;
        GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;
        GPIO_Init(GPIOA, &GPIO_InitStructure);
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE); 
        ADC_DeInit(ADC1);
        ADC_StructInit(&ADC_InitStructure);
        ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;
        ADC_InitStructure.ADC_ScanConvMode = ENABLE;
        if (func_mode==FK_ADC_SINGLE_MODE)
            ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;
        else
            ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
        ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;
        ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
        ADC_InitStructure.ADC_NbrOfConversion = 1;
        ADC_Init(ADC1, &ADC_InitStructure);
        ADC_RegularChannelConfig(ADC1, channel, 1, ADC_SampleTime_4Cycles);
        if (func_index==FK_ADC_DMA_FUNC)
        {
            ADC_DMARequestAfterLastTransferCmd(ADC1, ENABLE);
            ADC_DMACmd(ADC1, ENABLE);
        }
        if (func_index==FK_ADC_POLLING_FUNC)
        {
            ADC_DelaySelectionConfig(ADC1, ADC_DelayLength_None);   // ADC_DelayLength_None  ADC_DelayLength_Freeze
            ADC_PowerDownCmd(ADC1, ADC_PowerDown_Idle_Delay, ENABLE);
        }
        if (func_index==FK_ADC_INTERRUPT_FUNC)
          ADC_ITConfig(ADC1, ADC_IT_EOC, ENABLE);
        ADC_Cmd(ADC1, ENABLE);
        if (func_index==FK_ADC_DMA_FUNC)
        {
            while(ADC_GetFlagStatus(ADC1, ADC_FLAG_ADONS) == RESET);
            ADC_SoftwareStartConv(ADC1);
        }
        if (func_index==FK_ADC_INTERRUPT_FUNC)
        {
            gfunc_fk_adc_func=func;
            NVIC_InitStructure.NVIC_IRQChannel = ADC1_IRQn;
            NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = FK_ADC1_2_PRIORITY;
            NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
            NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
            NVIC_Init(&NVIC_InitStructure);  
            ADC_SoftwareStartConv(ADC1);
        }
  }
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 fk_adc_polling
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 task function
//
//! @param	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    UINT16 fk_adc_polling(UINT8 set)
    {
        while (ADC_GetFlagStatus(ADC1, ADC_FLAG_ADONS) == RESET);
        ADC_SoftwareStartConv(ADC1);
        while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET);
        return ADC_GetConversionValue(ADC1);
    }

//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 fk_set_dac
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 task function
//
//! @param	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_set_dac(UINT8 channel,UINT32 port,UINT32 pin,UINT8 dma_channel,UINT16 *buf,UINT32 size,UINT32 wave)
    {
      
        DAC_InitTypeDef            DAC_InitStructure;
        DMA_InitTypeDef            DMA_InitStructure;

        fk_set_io(port,pin,FK_GPIO_SPEED,GPIO_Mode_AIN_NOPULL);

        if (wave!=FK_DAC_NONE_WAVE || dma_channel!=FK_DMA_CHANNEL_TOTAL)
        {
            TIM_TimeBaseInitTypeDef    TIM_TimeBaseStructure;
            RCC_APB1PeriphClockCmd(gt_fk_dac_timer_rcc[channel], ENABLE);
            TIM_TimeBaseStructInit(&TIM_TimeBaseStructure); 
            TIM_TimeBaseStructure.TIM_Period = 0x80;          
            TIM_TimeBaseStructure.TIM_Prescaler = 0x0;       
            TIM_TimeBaseStructure.TIM_ClockDivision = 0x0;    
            TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  
            TIM_TimeBaseInit((TIM_TypeDef*)gt_fk_dac_timer[channel], &TIM_TimeBaseStructure);
            TIM_SelectOutputTrigger((TIM_TypeDef*)gt_fk_dac_timer[channel], TIM_TRGOSource_Update);
            TIM_Cmd((TIM_TypeDef*)gt_fk_dac_timer[channel], ENABLE);
        }
        DAC_DeInit(); 
        RCC_APB1PeriphClockCmd(RCC_APB1Periph_DAC, ENABLE);
        if (dma_channel==FK_DMA_CHANNEL_TOTAL)
            DAC_InitStructure.DAC_Trigger = DAC_Trigger_None; 
        else
            DAC_InitStructure.DAC_Trigger = gt_fk_dac_trigger[channel]; 
        DAC_InitStructure.DAC_WaveGeneration =  gt_fk_dac_wave[wave];  
        DAC_InitStructure.DAC_LFSRUnmask_TriangleAmplitude = DAC_LFSRUnmask_Bits11_0;  
        DAC_InitStructure.DAC_OutputBuffer = DAC_OutputBuffer_Enable;

        if (dma_channel!=FK_DMA_CHANNEL_TOTAL)
        {    
            if (dma_channel<=7)
                RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
            else
                RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA2, ENABLE);

//fk_nvic_enable(gt_fk_dma_irq_register[dma_channel],gt_fk_dma_priority[dma_channel],ENABLE);

            DMA_DeInit((DMA_Channel_TypeDef *)gt_fk_dma_channel_register[dma_channel]);
            if (channel==FK_DAC_CHANNEL1)
                DMA_InitStructure.DMA_PeripheralBaseAddr = (UINT32)0x40007408;
            else
                DMA_InitStructure.DMA_PeripheralBaseAddr = (UINT32)0x40007414;
            DMA_InitStructure.DMA_MemoryBaseAddr = (UINT32)buf;
            DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;
            DMA_InitStructure.DMA_BufferSize = size;
            DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
            DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
            DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
            DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
            DMA_InitStructure.DMA_Mode = DMA_Mode_Circular; // DMA_Mode_Normal; DMA_Mode_Circular
            DMA_InitStructure.DMA_Priority = DMA_Priority_High;
            DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
            DMA_Init((DMA_Channel_TypeDef *)gt_fk_dma_channel_register[dma_channel], &DMA_InitStructure);
            
            *((UINT16*)&gs_fk_interrupt_list)|=((0x01)<<(dma_channel));
            gfunc_fk_dma_func[dma_channel]=fk_null;
            
//DMA_ITConfig((DMA_Channel_TypeDef *)gt_fk_dma_channel_register[dma_channel], DMA_IT_TC, ENABLE);      
            DMA_Cmd((DMA_Channel_TypeDef *)gt_fk_dma_channel_register[dma_channel], ENABLE);        

        }

        DAC_Init(gt_fk_dac_register[channel], &DAC_InitStructure);
        DAC_Cmd(gt_fk_dac_register[channel], ENABLE);

        if (wave != FK_DAC_NONE_WAVE)
            DAC_WaveGenerationCmd(gt_fk_dac_register[channel],gt_fk_dac_wave[wave],ENABLE);
        if (dma_channel!=FK_DMA_CHANNEL_TOTAL)
            DAC_DMACmd(gt_fk_dac_register[channel], ENABLE);
    }
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 fk_i2c_init
//
//! @author 	 Vic Chen
//
//! @date 	 2010/11/16
//
//! @brief 	I2C INIT function
//
//! @param	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_i2c_init(UINT8 channel,UINT32 speed)
    {
/*
        GPIO_InitTypeDef GPIO_Initstructure;
        I2C_InitTypeDef I2C_Initstructure;

        //RCC config
        if(channel == FK_I2C_TOTAL)
        {
            RCC_APB1PeriphClockCmd(gt_fk_i2c_periph[FK_I2C1],ENABLE);
            RCC_APB1PeriphClockCmd(gt_fk_i2c_periph[FK_I2C2],ENABLE);
            //define GPIO SCL and SDA
            GPIO_Initstructure.GPIO_Pin = gt_fk_i2c_pin[FK_I2C1]|gt_fk_i2c_pin[FK_I2C1+2];
            GPIO_Initstructure.GPIO_Speed = GPIO_Speed_40MHz;
            GPIO_Initstructure.GPIO_Mode = GPIO_Mode_AF_OD;
            GPIO_Init((GPIO_TypeDef*)gt_fk_i2c_port[FK_I2C1],&GPIO_Initstructure);
            GPIO_Initstructure.GPIO_Pin = gt_fk_i2c_pin[FK_I2C2]|gt_fk_i2c_pin[FK_I2C2+2];
            GPIO_Init((GPIO_TypeDef*)gt_fk_i2c_port[FK_I2C2],&GPIO_Initstructure);

            //I2C Init
            I2C_Initstructure.I2C_Mode = I2C_Mode_I2C;
            I2C_Initstructure.I2C_DutyCycle = I2C_DutyCycle_2;
            I2C_Initstructure.I2C_Ack = I2C_Ack_Enable;
            I2C_Initstructure.I2C_OwnAddress1 = 0;
            I2C_Initstructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
            I2C_Initstructure.I2C_ClockSpeed = speed;
            I2C_Init((I2C_TypeDef*)gt_fk_i2c_register[FK_I2C1], &I2C_Initstructure);
            I2C_Cmd((I2C_TypeDef*)gt_fk_i2c_register[FK_I2C1],ENABLE);
            I2C_Init((I2C_TypeDef*)gt_fk_i2c_register[FK_I2C2], &I2C_Initstructure);
            I2C_Cmd((I2C_TypeDef*)gt_fk_i2c_register[FK_I2C2],ENABLE);
        }
        else
        {
            RCC_APB1PeriphClockCmd(gt_fk_i2c_periph[channel],ENABLE);

            RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);

            //define GPIO SCL and SDA
            GPIO_Initstructure.GPIO_Pin = gt_fk_i2c_pin[channel]|gt_fk_i2c_pin[channel+2];
            GPIO_Initstructure.GPIO_Speed = GPIO_Speed_40MHz;
            GPIO_Initstructure.GPIO_Mode = GPIO_Mode_AF_OD;
            GPIO_Init((GPIO_TypeDef*)gt_fk_i2c_port[channel],&GPIO_Initstructure);

            //I2C Init
            I2C_Initstructure.I2C_Mode = I2C_Mode_I2C;
            I2C_Initstructure.I2C_DutyCycle = I2C_DutyCycle_16_9;
            I2C_Initstructure.I2C_Ack = I2C_Ack_Enable;
            I2C_Initstructure.I2C_OwnAddress1 = 0;
            I2C_Initstructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
            I2C_Initstructure.I2C_ClockSpeed = speed;
            I2C_Init((I2C_TypeDef*)gt_fk_i2c_register[channel], &I2C_Initstructure);
            I2C_Cmd((I2C_TypeDef*)gt_fk_i2c_register[channel],ENABLE);
        }
*/
    }

//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 fk_spi_init
//
//! @author 	 Willman Chen
//
//! @date 	 2010/12/20
//
//! @brief 	 task function
//
//! @param	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_spi_init(UINT8 set,UINT8 dma,UINT8 *buf,UINT32 len)
    {
      
      GPIO_InitTypeDef GPIO_InitStructure;
      UINT8 port_index=fk_port_index((UINT32)gt_fk_spi_port[set]);
      
      RCC_AHBPeriphClockCmd(gt_fk_periph_register[port_index], ENABLE);
      GPIO_PinAFConfig((GPIO_TypeDef*)gt_fk_spi_port[set],gt_fk_pinsource_register[fk_pin_index((UINT32)gt_fk_spi_pins[3*set])],gt_fk_spi_af_register[set]);
      GPIO_PinAFConfig((GPIO_TypeDef*)gt_fk_spi_port[set],gt_fk_pinsource_register[fk_pin_index((UINT32)gt_fk_spi_pins[3*set+1])],gt_fk_spi_af_register[set]);
      GPIO_PinAFConfig((GPIO_TypeDef*)gt_fk_spi_port[set],gt_fk_pinsource_register[fk_pin_index((UINT32)gt_fk_spi_pins[3*set+2])],gt_fk_spi_af_register[set]);
      
      GPIO_InitStructure.GPIO_Pin = gt_fk_spi_pins[set*3] | gt_fk_spi_pins[set*3+1] |gt_fk_spi_pins[set*3+2] ;
      GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
      GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
      GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; 
      GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
      GPIO_Init((GPIO_TypeDef*)gt_fk_spi_port[set], &GPIO_InitStructure);
      
      RCC_AHBPeriphClockCmd(gt_fk_periph_register[port_index], ENABLE);
      
      if (set==FK_SPI1)
        RCC_APB2PeriphClockCmd(gt_fk_spi_periph[set], ENABLE);
      else
        RCC_APB1PeriphClockCmd(gt_fk_spi_periph[set], ENABLE);
      
      SPI_InitTypeDef  SPI_InitStructure;
      SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex; // NOTE
      SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
      SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b; // NOTE
      SPI_InitStructure.SPI_CPOL = SPI_CPOL_High;
      SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge; // NOTE
      SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
      SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_2; // NOTE
      SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
      SPI_InitStructure.SPI_CRCPolynomial = 7;
      SPI_Init((SPI_TypeDef *)gt_fk_spi_register[set], &SPI_InitStructure);
      SPI_Cmd((SPI_TypeDef *)gt_fk_spi_register[set], ENABLE);
      
      if (dma!=FK_DMA_CHANNEL_TOTAL)
      {
        if (dma<=7)
            RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
        else
            RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA2, ENABLE);

        DMA_InitTypeDef  DMA_InitStructure;
        DMA_DeInit((DMA_Channel_TypeDef *)gt_fk_dma_channel_register[dma]);
        DMA_InitStructure.DMA_PeripheralBaseAddr = (UINT32)0x4001300C; // (uint32_t)&((SPI_TypeDef *)gt_fk_spi_register[set])->DR;
        DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)buf;
        DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;
        DMA_InitStructure.DMA_BufferSize = len;
        DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
        DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
        DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
        DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
        DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;
        DMA_InitStructure.DMA_Priority = DMA_Priority_VeryHigh;
        DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
        DMA_Init((DMA_Channel_TypeDef *)gt_fk_dma_channel_register[dma], &DMA_InitStructure);
        SPI_I2S_DMACmd((SPI_TypeDef *)gt_fk_spi_register[set], SPI_I2S_DMAReq_Tx, ENABLE);
        DMA_Cmd((DMA_Channel_TypeDef *)gt_fk_dma_channel_register[dma], ENABLE);
        //if(set==FK_SPI1)
        //  while (DMA_GetFlagStatus(DMA1_FLAG_TC3) == RESET);
        //else
        //  while (DMA_GetFlagStatus(DMA1_FLAG_TC5) == RESET);
      }
      else
      {
        for (UINT32 i=0;i<len;i++)
        {
          while (SPI_I2S_GetFlagStatus((SPI_TypeDef *)gt_fk_spi_register[set], SPI_I2S_FLAG_TXE) == RESET);
          SPI_I2S_SendData((SPI_TypeDef *)gt_fk_spi_register[set], *(buf+i));
          //while(SPI_I2S_GetFlagStatus((SPI_TypeDef *)gt_fk_spi_register[set], SPI_I2S_FLAG_RXNE)==RESET);
        }
      }
    }
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 fk_pvd_enable
//
//! @author 	 Willman Chen
//
//! @date 	 2010/12/20
//
//! @brief 	 task function
//
//! @param	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_pvd_enable(UINT32 voltage,void(*func)(void))
    {
      gfunc_fk_pvd_func=func;
      EXTI_InitTypeDef EXTI_InitStructure;
      EXTI_ClearITPendingBit(EXTI_Line17);
      EXTI_InitStructure.EXTI_Line = EXTI_Line17;
      EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
      EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising_Falling;
      EXTI_InitStructure.EXTI_LineCmd = ENABLE;
      EXTI_Init(&EXTI_InitStructure); 
      fk_nvic_enable(PVD_IRQn,FK_PVD_PRIORITY,ENABLE);
      PWR_PVDLevelConfig(voltage);    
      PWR_PVDCmd(ENABLE);
    }
    
    
    

//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 i2c_io_task.c
//
//! @author 	         Roger Chang
//
//! @date 		 2010/12/20
//
//  @brief 		 fk_i2c_master_receive 
//
//**********************************************************************************************************************
UINT8 fk_i2c_master_receive(UINT8 cmd, UINT8* data,  UINT8 length)
{
    // This corresponds to i2c_master_recv
    // S Addr Rd [A] [Data] A [Data] A ... A [Data] NA P
    gb_fk_i2c_status_flag = FK_I2C_OK;
    fk_i2c_tx_start();					                        //======	Send START
    fk_i2c_tx_byte((UINT8)(cmd|FK_I2C_IO_READ_CMD_MASK));                             //======	Send Slave Address & Read bit
    fk_i2c_io_rx_ack();					                      //======	Get  ACK  from slave dev
    do                                                        // Decrement RX byte counter
    {        
        length=length-1;
        *(data+length) = fk_i2c_rx_byte();	                      //======	Get  DATA from slave dev
        if (length)
            fk_i2c_io_tx_ack();	                              //======	Send ACK from master dev
        else
            fk_i2c_io_tx_nanack();		    	                  //======	Send NACK from master dev if last Data
    }  while (length);
    fk_i2c_tx_stop();		                                      //======	Send STOP   
    return gb_fk_i2c_status_flag;
}

//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 i2c_io_task.c
//
//! @author 	         Roger Chang
//
//! @date 		 2010/12/20
//
//  @brief 		 fk_i2c_master_send 
//
//**********************************************************************************************************************
UINT8 fk_i2c_master_send( UINT8 cmd, UINT8* data, UINT8 len)
{
    // This corresponds to i2c_master_send.
    // S Addr Wr [A] Data [A] Data [A] ... [A] Data [A] P 
    gb_fk_i2c_status_flag = FK_I2C_OK;
    fk_i2c_tx_start();		    		        //======	Send START
    fk_i2c_tx_byte(cmd&FK_I2C_IO_WRITE_CMD_MASK); //======	Send Slave Address & Write
    fk_i2c_io_rx_ack();		    			//======	Get  ACK  from slave dev
    do
    {                                       // Decrement TX byte counter
        fk_i2c_tx_byte(data[--len]); 	        //======	Send data
        fk_i2c_io_rx_ack();	                //======	Get  ACK  from slave dev
    } while (len);
    fk_i2c_tx_stop();		                    //======	Send STOP       
    return gb_fk_i2c_status_flag;
}

//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 i2c_io_task.c
//
//! @author 	         Roger Chang
//
//! @date 		 2010/12/20
//
//  @brief 		 fk_i2c_io_rx_ack 
//
//**********************************************************************************************************************
UINT8 fk_i2c_io_rx_ack()
{
    //  assert: scl is low
    gb_fk_i2c_status_flag = FK_I2C_FAIL;
    FK_I2C_IO_SET_SDA_IN();        
#if MCP3421_HAS_DELAY_WITH_EACH_COMMAND == 1
    fk_i2c_io_delay(FK_I2C_IO_DELAY_TIME);                              //  Set to input 
#endif
    for (UINT16 k = 0; k < FK_I2C_IO_DELAY_FOR_ACK; k++)             //  Check ACK (low)
    {
        if (!(FK_I2C_IO_CHK_SDA_STATE()))
        {
            gb_fk_i2c_status_flag = FK_I2C_OK;
            break;
        }
    }                                                             //SDA???????LO, SCL?????????HI, LO
    FK_I2C_IO_SET_SCL_OUT();
    FK_I2C_IO_SCL_H();  
#if MCP3421_HAS_DELAY_WITH_EACH_COMMAND == 1
    fk_i2c_io_delay(FK_I2C_IO_DELAY_TIME);        
#endif
    FK_I2C_IO_SCL_L();         
#if MCP3421_HAS_DELAY_WITH_EACH_COMMAND == 1
    fk_i2c_io_delay(FK_I2C_IO_DELAY_TIME);        
#endif
    
    return gb_fk_i2c_status_flag;
}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 i2c_io_task.c
//
//! @author 	         Roger Chang
//
//! @date 		 2010/12/20
//
//  @brief 		 fk_i2c_io_tx_ack 
//
//**********************************************************************************************************************
void fk_i2c_io_tx_ack()
{
    //  assert: scl is low

    FK_I2C_IO_SET_SDA_OUT();
    FK_I2C_IO_SET_SCL_OUT();
    FK_I2C_IO_SDA_L();       
#if FK_I2C_IO_HAS_DELAY_WITH_EACH_COMMAND == 1
    fk_i2c_io_delay(FK_I2C_IO_DELAY_TIME);      //  Set to output, data low so SDA = 0
#endif
    FK_I2C_IO_SCL_H();
#if FK_I2C_IO_HAS_DELAY_WITH_EACH_COMMAND == 1
    fk_i2c_io_delay(FK_I2C_IO_DELAY_TIME);      //  Set to input, SCL = 1 due to pull-up
#endif
    FK_I2C_IO_SCL_L();                       //  Set to output, data low so SCL = 0

}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 i2c_io_task.c
//
//! @author 	         Roger Chang
//
//! @date 		 2010/12/20
//
//  @brief 		 fk_i2c_io_tx_nanack 
//
//**********************************************************************************************************************
void fk_i2c_io_tx_nanack()
{

    FK_I2C_IO_SET_SDA_OUT();
    FK_I2C_IO_SET_SCL_OUT();
    FK_I2C_IO_SDA_H();              
#if FK_I2C_IO_HAS_DELAY_WITH_EACH_COMMAND == 1
    fk_i2c_io_delay(FK_I2C_IO_DELAY_TIME);        
#endif
    FK_I2C_IO_SCL_H();
#if FK_I2C_IO_HAS_DELAY_WITH_EACH_COMMAND == 1
    fk_i2c_io_delay(FK_I2C_IO_DELAY_TIME);        
#endif
    FK_I2C_IO_SCL_L();

}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 i2c_io_task.c
//
//! @author 	         Roger Chang
//
//! @date 		 2010/12/20
//
//  @brief 		 fk_i2c_io_rx_nanack 
//
//**********************************************************************************************************************
void fk_i2c_io_rx_nanack()
{

    gb_fk_i2c_status_flag = FK_I2C_FAIL;
    FK_I2C_IO_SET_SDA_IN();
#if FK_I2C_IO_HAS_DELAY_WITH_EACH_COMMAND == 1
    fk_i2c_io_delay(FK_I2C_IO_DELAY_TIME);                       //  Set to input
#endif
    for (UINT16 k = 0; k < FK_I2C_IO_DELAY_FOR_NACK; k++)     //  Check ACK (low)
    {
        if (!(FK_I2C_IO_CHK_SDA_STATE()))
        {
            gb_fk_i2c_status_flag = FK_I2C_OK;
            break;
        }
    }                                                      //  After receving low signal from SDA,we need to pass hi signal to SCL
    FK_I2C_IO_SET_SCL_OUT();
    FK_I2C_IO_SCL_H();
#if FK_I2C_IO_HAS_DELAY_WITH_EACH_COMMAND == 1
    fk_i2c_io_delay(FK_I2C_IO_DELAY_TIME);        
#endif
    FK_I2C_IO_SCL_L();
#if FK_I2C_IO_HAS_DELAY_WITH_EACH_COMMAND == 1
    fk_i2c_io_delay(FK_I2C_IO_DELAY_TIME);        
#endif

}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 i2c_io_task.c
//
//! @author 	         Roger Chang
//
//! @date 		 2010/12/20
//
//  @brief 		 fk_i2c_io_delay 
//
//**********************************************************************************************************************
#if FK_I2C_IO_HAS_DELAY_WITH_EACH_COMMAND == 1
void fk_i2c_io_delay(UINT8 data)
{               
    for (;data>0;data--);  	//  delay to meet I2C spec
}                                           
#endif
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 i2c_io_task.c
//
//! @author 	         Roger Chang
//
//! @date 		 2010/12/20
//
//  @brief 		 fk_i2c_tx_start 
//
//**********************************************************************************************************************
void fk_i2c_tx_start()
{
/*
    FK_I2C_IO_SET_SDA_OUT();
    FK_I2C_IO_SET_SCL_OUT();
    FK_I2C_IO_SDA_H();               
#if FK_I2C_IO_HAS_DELAY_WITH_EACH_COMMAND == 1
    fk_i2c_io_delay(FK_I2C_IO_DELAY_TIME);        
#endif
    FK_I2C_IO_SCL_H();
#if FK_I2C_IO_HAS_DELAY_WITH_EACH_COMMAND == 1
    fk_i2c_io_delay(FK_I2C_IO_DELAY_TIME);        
#endif
    FK_I2C_IO_SDA_L() ;
#if FK_I2C_IO_HAS_DELAY_WITH_EACH_COMMAND == 1
    fk_i2c_io_delay(FK_I2C_IO_DELAY_TIME);        
#endif
    FK_I2C_IO_SCL_L();
#if FK_I2C_IO_HAS_DELAY_WITH_EACH_COMMAND == 1
    fk_i2c_io_delay(FK_I2C_IO_DELAY_TIME);        
#endif
*/
}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 i2c_io_task.c
//
//! @author 	         Roger Chang
//
//! @date 		 2010/12/20
//
//  @brief 		 fk_i2c_tx_stops 
//
//**********************************************************************************************************************
void fk_i2c_tx_stop()
{   
    //  assert: scl is low
/*
    FK_I2C_IO_SET_SDA_OUT();
    FK_I2C_IO_SET_SCL_OUT();
    FK_I2C_IO_SCL_H();                
#if FK_I2C_IO_HAS_DELAY_WITH_EACH_COMMAND == 1
    fk_i2c_io_delay(FK_I2C_IO_DELAY_TIME);        
#endif
    FK_I2C_IO_SDA_H();
#if FK_I2C_IO_HAS_DELAY_WITH_EACH_COMMAND == 1
    fk_i2c_io_delay(FK_I2C_IO_DELAY_TIME);        
#endif
*/
}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 i2c_io_task.c
//
//! @author 	         Roger Chang
//
//! @date 		 2010/12/20
//
//  @brief 		 fk_i2c_tx_byte 
//
//**********************************************************************************************************************
void fk_i2c_tx_byte(UINT8 data)
{
    //  assert: scl is low
/*
    UINT8 i;
    FK_I2C_IO_SET_SDA_OUT();
    FK_I2C_IO_SET_SCL_OUT();
    for (i = 0; i < FK_I2C_IO_BYTE_BITS; i++)
    {
        if ( (data&FK_I2C_IO_BYTE_BIT7) )
            FK_I2C_IO_SDA_H();
        else
            FK_I2C_IO_SDA_L();    
#if FK_I2C_IO_HAS_DELAY_WITH_EACH_COMMAND == 1
        fk_i2c_io_delay(FK_I2C_IO_DELAY_TIME);    
#endif
        FK_I2C_IO_SCL_H();
        data <<= 1;
#if FK_I2C_IO_HAS_DELAY_WITH_EACH_COMMAND == 1
        fk_i2c_io_delay(FK_I2C_IO_DELAY_TIME);    
#endif
        FK_I2C_IO_SCL_L();
#if FK_I2C_IO_HAS_DELAY_WITH_EACH_COMMAND == 1
        fk_i2c_io_delay(FK_I2C_IO_DELAY_TIME);    
#endif
    }
*/
}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 i2c_io_task.c
//
//! @author 	         Roger Chang
//
//! @date 		 2010/12/20
//
//  @brief 		 fk_i2c_rx_byte 
//
//**********************************************************************************************************************
UINT8 fk_i2c_rx_byte(void)
{	
    //  assert: scl is low
/*
    UINT8 i;
    UINT8 buf = 0;
    FK_I2C_IO_SET_SDA_IN();        
#if FK_I2C_IO_HAS_DELAY_WITH_EACH_COMMAND == 1
    fk_i2c_io_delay(FK_I2C_IO_DELAY_TIME);        
#endif
    for (i = 0; i < FK_I2C_IO_BYTE_BITS; i++)
    {    
        buf=((buf<<1)&0xff);           
        FK_I2C_IO_SCL_H();
#if FK_I2C_IO_HAS_DELAY_WITH_EACH_COMMAND == 1
        fk_i2c_io_delay(FK_I2C_IO_DELAY_TIME);    
#endif
        if (FK_I2C_IO_CHK_SDA_STATE())
            buf |= 0x01;
        FK_I2C_IO_SCL_L();
#if FK_I2C_IO_HAS_DELAY_WITH_EACH_COMMAND == 1
        fk_i2c_io_delay(FK_I2C_IO_DELAY_TIME);    
#endif
    }
    return buf;
*/
    return 0;
}    
    
//**********************************************************************************************************************
//
// Copyright (C) 2011, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 	fk_i2c1_hw_check_timeout_func
//
//! @author 	 		Simon Lu
//
//! @date 		 		2011/12/01
//
//! @brief 		 	i2c byte write function
//
//! @param 		 	(?????HTBC ??????Timeout)
//
//! @return 			None
//
//**********************************************************************************************************************
void fk_i2c1_hw_check_timeout_func(void)
{
	//===(Simon MCP3422 Timeout check)
	if(gb_fk_i2c1_hw_time_out_sw == 1)
	{
		gb_fk_i2c1_hw_time_out_counter++;
		gb_fk_i2c1_hw_time_out_counter &= 0xFFFF;
	}  
}
   
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 	iic_hw_task
//
//! @author 	 		Simon Lu
//
//! @date 		 		2011.12.12
//
//! @brief 		 	task function
//
//! @param 		 	None
//
//! @return 	 		None
//
//**********************************************************************************************************************
UINT8 fk_i2c1_hw_timeout_check(void)
{
	//===(Only do once)
	if(0 == gb_fk_i2c1_hw_repeat_flag)
	{
		//===(Strat timeout switch in HTBC)
		gb_fk_i2c1_hw_time_out_sw 		= 1;
		gb_fk_i2c1_hw_repeat_flag 		= 1;
	}
	
	//===(20ms timeout check)
	if(gb_fk_i2c1_hw_time_out_counter >= 10)
	{
		gb_fk_i2c1_hw_time_out_sw 		= 0;
		gb_fk_i2c1_hw_time_out_counter	= 0;
		gb_fk_i2c1_hw_repeat_flag 		= 0;
		return 0;
	}
	return 1;
}  
  
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 	iic_hw_task
//
//! @author 	 		Simon Lu
//
//! @date 		 		2011.12.12
//
//! @brief 		 	task function
//
//! @param 		 	None
//
//! @return 	 		None
//
//**********************************************************************************************************************
void fk_i2c1_hw_task()
{

}

//**********************************************************************************************************************
//
// Copyright (C) 2011, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 	fk_i2c1_hw_byte_read
//
//! @author 	 		Simon Lu
//
//! @date 		 		2011/12/01
//
//! @brief 		 	i2c byte read function
//
//! @param 		 	UINT16 Addr,UINT8 Counter,UINT16 iic_hw_read_buf[]
//
//! @return 			None
//
//**********************************************************************************************************************
void  fk_i2c1_hw_byte_read(UINT8 Addr_Counter,UINT16 Addr_buf[],UINT8 Read_Counter,UINT16 iic_hw_read_buf[])
{
	UINT8   txd_counter = 1;
	UINT16  i;
	
	if(Read_Counter == 0)
	{
		return;
	}	
		                                              
    //===(Clean All Flag Status)
    FK_I2C1_HW_CLEAR_FLAG_API();                                               
                           
   	//===(Check Busy status)
	while(I2C_GetFlagStatus(I2C1, I2C_FLAG_BUSY) && fk_i2c1_hw_timeout_check());
	FK_I2C1_HW_CLAEN_TIMEOUT_STATUS();
  
  	//===============================================================================================//
	//===(Send Device Addr)
	//===============================================================================================//
	if(Addr_Counter >= 2)
	{
		//===(Send START condition)
	    FK_I2C1_HW_START_API();                                                        
	    while((!FK_I2C1_HW_CHK_START_API()) && fk_i2c1_hw_timeout_check());
	    FK_I2C1_HW_CLAEN_TIMEOUT_STATUS();
	    
	    //===(send device addr) 
	    FK_I2C1_HW_SEND7BIT_ADDR(Addr_buf[0]);  
	    while((!FK_I2C1_HW_CHK_7BITADDR_API()) && fk_i2c1_hw_timeout_check());
	    FK_I2C1_HW_CLAEN_TIMEOUT_STATUS();
	    
	    while(Addr_Counter-1)
	    {	
		    //===(send pointer register data)     
			FK_I2C1_HW_WRITE_API(Addr_buf[txd_counter++]);    
			while((!FK_I2C1_HW_CHK_TX_API()) && fk_i2c1_hw_timeout_check());
		    FK_I2C1_HW_CLAEN_TIMEOUT_STATUS();
	     	
	    	Addr_Counter--;
	    }
	}
	else
	{
		//===(Send START condition)
	    FK_I2C1_HW_START_API();                                                        
	    while((!FK_I2C1_HW_CHK_START_API()) && fk_i2c1_hw_timeout_check());
	    FK_I2C1_HW_CLAEN_TIMEOUT_STATUS();
	    
	    //===(send device addr) 
	    FK_I2C1_HW_SEND7BIT_ADDR(Addr_buf[0]);  
	    while((!FK_I2C1_HW_CHK_7BITADDR_API()) && fk_i2c1_hw_timeout_check());
	    FK_I2C1_HW_CLAEN_TIMEOUT_STATUS();
	}		                                    	
	//===============================================================================================//
	//===(Read data)
	//===============================================================================================//
	if(Read_Counter == 1)
	{		
		//===(Send START condition)
	    FK_I2C1_HW_START_API();                                                        
    	while((!FK_I2C1_HW_CHK_START_API()) && fk_i2c1_hw_timeout_check());
		FK_I2C1_HW_CLAEN_TIMEOUT_STATUS();
		
		
	    //===(Simon Modify)
	    I2C_Send7bitAddress(I2C1,Addr_buf[0],I2C_Direction_Receiver);
		while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED)&& fk_i2c1_hw_timeout_check()); 
		FK_I2C1_HW_CLAEN_TIMEOUT_STATUS();

		/* Clear ACK bit */
        //I2C1->CR1 &= CR1_ACK_Reset;
        FK_I2C1_HW_ACK_RESET_API(); 
         
        /* Disable all active IRQs around ADDR clearing and STOP programming because the EV6_3
            software sequence must complete before the current byte end of transfer */
        //__disable_irq();
        FK_I2C1_HW_STM32_SYSTEM_ISR_DISABLE();
         
        /* Clear ADDR flag */
        i = I2C1->SR2;
         
        /* Program the STOP */
        //I2C1->CR1 |= CR1_STOP_Set;
        FK_I2C1_HW_STOP_API();
            
        /* Re-enable IRQs */
        //__enable_irq();
        FK_I2C1_HW_STM32_SYSTEM_ISR_ENABLE();
              
        /* Wait until a data is received in DR register (RXNE = 1) EV7 */
		while((!FK_I2C1_HW_CHK_RX_API())&& fk_i2c1_hw_timeout_check());
		FK_I2C1_HW_CLAEN_TIMEOUT_STATUS();
         
        /* Read the data */
		iic_hw_read_buf[0] = FK_I2C1_HW_READ_API(); 
	 		 	
	 	//===(CHECK STOP)
	 	while (((I2C1->CR1&0x200) == 0x200) && fk_i2c1_hw_timeout_check());
        FK_I2C1_HW_CLAEN_TIMEOUT_STATUS();
               
        /* Enable Acknowledgement to be ready for another reception */
        //I2C1->CR1 |= CR1_ACK_Set;	
		FK_I2C1_HW_ACK_ENABLE_API();
	}	
	else if(Read_Counter == 2)
	{
		/* Set POS bit */
        //I2C1->CR1 |= CR1_POS_Set;
		FK_I2C1_HW_SET_POS_BIT_API();
		
		//===(Send START condition)
	    FK_I2C1_HW_START_API();                                                        
	    while((!FK_I2C1_HW_CHK_START_API()) && fk_i2c1_hw_timeout_check());
    	FK_I2C1_HW_CLAEN_TIMEOUT_STATUS();
    	
	    //===(Simon Modify)
	    I2C_Send7bitAddress(I2C1,Addr_buf[0],I2C_Direction_Receiver);
	    while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED) && fk_i2c1_hw_timeout_check()); 
		FK_I2C1_HW_CLAEN_TIMEOUT_STATUS();
		
		 /* EV6_1: The acknowledge disable should be done just after EV6,
            that is after ADDR is cleared, so disable all active IRQs around ADDR clearing and ACK clearing */
         //__disable_irq();
         FK_I2C1_HW_STM32_SYSTEM_ISR_DISABLE();
         
         /* Clear ADDR by reading SR2 register  */
         i = I2C1->SR2;
         
         /* Clear ACK */
         //I2C1->CR1 &= CR1_ACK_Reset;
         FK_I2C1_HW_ACK_RESET_API();
         
         /*Re-enable IRQs */
         //__enable_irq();
         FK_I2C1_HW_STM32_SYSTEM_ISR_ENABLE();
         
         /* Wait until BTF is set */
         while (((I2C1->SR1 & 0x00004) != 0x000004) && fk_i2c1_hw_timeout_check());
         FK_I2C1_HW_CLAEN_TIMEOUT_STATUS();
         
         /* Disable IRQs around STOP programming and data reading because of the limitation ?*/
         //__disable_irq();
         FK_I2C1_HW_STM32_SYSTEM_ISR_DISABLE();
         
         /* Program the STOP */                      
         //I2C_GenerateSTOP(I2C1, ENABLE);
         FK_I2C1_HW_STOP_API();
         
         /* Read first data */
         //*pBuffer = I2Cx->DR;
         iic_hw_read_buf[0] = FK_I2C1_HW_READ_API();   
         
         /* Re-enable IRQs */
         //__enable_irq();
         FK_I2C1_HW_STM32_SYSTEM_ISR_ENABLE();
  
         /* Read second data */
         //*pBuffer = I2Cx->DR;
         iic_hw_read_buf[1] = FK_I2C1_HW_READ_API();   
         
         /* Make sure that the STOP bit is cleared by Hardware before CR1 write access */
         while (((I2C1->CR1&0x200) == 0x200) && fk_i2c1_hw_timeout_check());
         FK_I2C1_HW_CLAEN_TIMEOUT_STATUS();
         
         /* Enable Acknowledgement to be ready for another reception */
         //I2C1->CR1  |= CR1_ACK_Set;
        FK_I2C1_HW_ACK_ENABLE_API();
         
         /* Clear POS bit */
         //I2C1->CR1  &= CR1_POS_Reset;
         FK_I2C1_HW_RESET_POS_BIT_API();   
	}	
	else if(Read_Counter >= 3)
	{	
		//===(Send START condition)
	    FK_I2C1_HW_START_API();                                                        
	    while((!FK_I2C1_HW_CHK_START_API()) && fk_i2c1_hw_timeout_check());
	    FK_I2C1_HW_CLAEN_TIMEOUT_STATUS();
	      
	    //===(Simon Modify)
	    I2C_Send7bitAddress(I2C1,Addr_buf[0],I2C_Direction_Receiver);
	    while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED) && fk_i2c1_hw_timeout_check()); 
		FK_I2C1_HW_CLAEN_TIMEOUT_STATUS();
		
		/* Clear ADDR by reading SR2 status register */
        i = I2C1->SR2;
        i = 0;
        
        /* While there is data to be read */
        while (Read_Counter)
        //for(i=0;i<Counter;i++)
        {
			/* Receive bytes from first byte until byte N-3 */
			if (Read_Counter != 3)
			{	
				/* Poll on BTF to receive data because in polling mode we can not guarantee the
				EV7 software sequence is managed before the current byte transfer completes */
				//while ((I2C1->SR1 & 0x00004) != 0x000004) ;
                 while (((I2C1->SR1 & 0x00004) != 0x000004) && fk_i2c1_hw_timeout_check());
        		 FK_I2C1_HW_CLAEN_TIMEOUT_STATUS();
                         
                /* Read data */
                //*pBuffer = I2Cx->DR;
                iic_hw_read_buf[i] = FK_I2C1_HW_READ_API();     
                   
                //pBuffer++;
                i++;
                
                /* Decrement the read bytes counter */
                //NumByteToRead--;
                Read_Counter--;
            }

            /* it remains to read three data: data N-2, data N-1, Data N */
            if (Read_Counter == 3)
            {
				/* Wait until BTF is set: Data N-2 in DR and data N -1 in shift register */
				//while ((I2C1->SR1 & 0x00004) != 0x000004);
				while (((I2C1->SR1 & 0x00004) != 0x000004) && fk_i2c1_hw_timeout_check());
				FK_I2C1_HW_CLAEN_TIMEOUT_STATUS();
                 
				/* Clear ACK */
				//I2C1->CR1 &= CR1_ACK_Reset;
				FK_I2C1_HW_ACK_RESET_API();

                /* Disable IRQs around data reading and STOP programming because of the limitation ? */
                //__disable_irq();
                FK_I2C1_HW_STM32_SYSTEM_ISR_DISABLE();
                
                /* Read Data N-2 */
                //*pBuffer = I2C1->DR;
                iic_hw_read_buf[i] = FK_I2C1_HW_READ_API(); 
                
                /* Increment */
                //pBuffer++;
                i++;
                
                /* Program the STOP */
                //I2C1->CR1 |= CR1_STOP_Set;
                FK_I2C1_HW_STOP_API();
                
                /* Read DataN-1 */
                //*pBuffer = I2Cx->DR;
                iic_hw_read_buf[i] = FK_I2C1_HW_READ_API();
                    
                /* Re-enable IRQs */
                //__enable_irq();
                FK_I2C1_HW_STM32_SYSTEM_ISR_ENABLE();
                
                /* Increment */
                //pBuffer++;
                i++;
                    
                /* Wait until RXNE is set (DR contains the last data) */
                while (((I2C1->SR1 & 0x00040) != 0x000040) && fk_i2c1_hw_timeout_check());
				FK_I2C1_HW_CLAEN_TIMEOUT_STATUS();
                
                /* Read DataN */
                //*pBuffer = I2Cx->DR;
                iic_hw_read_buf[i] = FK_I2C1_HW_READ_API();
                    
                /* Reset the number of bytes to be read by master */
                //NumByteToRead = 0;
				Read_Counter = 0;
                }
            }  
            
            /* Make sure that the STOP bit is cleared by Hardware before CR1 write access */
            while (((I2C1->CR1&0x200) == 0x200) && fk_i2c1_hw_timeout_check());
           	FK_I2C1_HW_CLAEN_TIMEOUT_STATUS();
           
            /* Enable Acknowledgement to be ready for another reception */
            //I2C1->CR1 |= CR1_ACK_Set;
            FK_I2C1_HW_ACK_ENABLE_API();
	}	
	//===============================================================================================//          
}

//**********************************************************************************************************************
//
// Copyright (C) 2011, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 	fk_i2c1_hw_byte_write
//
//! @author 	 		Simon Lu
//
//! @date 		 		2011/12/01
//
//! @brief 		 	i2c byte write function
//
//! @param 		 	UINT16 addr,UINT8 counter,UINT16 *data
//
//! @return 			None
//
//**********************************************************************************************************************
void  fk_i2c1_hw_byte_write(UINT16 addr,UINT8 counter,UINT16 *data)
{
	UINT16 i;
   	
   	
    FK_I2C1_HW_CLEAR_FLAG_API();       
                                                              
    
    //START BIT
    FK_I2C1_HW_START_API();                                                    	 
    while((!FK_I2C1_HW_CHK_START_API()) && fk_i2c1_hw_timeout_check());
     
    //===(send device addr) 
    FK_I2C1_HW_SEND7BIT_ADDR(addr);  
    while((!FK_I2C1_HW_CHK_7BITADDR_API()) && fk_i2c1_hw_timeout_check());

	/* Clear ADDR flag by reading SR2 register */
	i = I2C1->SR2;

 	//===(write data)
	for(i=0;i<counter;i++)        
	{
		//===(send data)     
	    FK_I2C1_HW_WRITE_API(*data++);    
	    while((!FK_I2C1_HW_CHK_TX_API()) && fk_i2c1_hw_timeout_check());
	    FK_I2C1_HW_CLAEN_TIMEOUT_STATUS();
	}
	  
	/* EV8_2: Wait until BTF is set before programming the STOP */
	while (((I2C1->SR1 & 0x00004) != 0x000004) && fk_i2c1_hw_timeout_check());	
	FK_I2C1_HW_CLAEN_TIMEOUT_STATUS();
	   
    //===(stop) 
    FK_I2C1_HW_STOP_API();

	/* Make sure that the STOP bit is cleared by Hardware */
	while (((I2C1->CR1&0x200) == 0x200) && fk_i2c1_hw_timeout_check());    
	FK_I2C1_HW_CLAEN_TIMEOUT_STATUS();    
}

//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 fk_timer_pwm_enable
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 task function
//
//! @param	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void fk_timer_pwm_enable(UINT8 timer,UINT16 channel,UINT32 port,UINT32 pin,UINT32 period,UINT32 pulse)   
{
        TIM_OCInitTypeDef   			TIM_OCInitStructure; 
        TIM_TimeBaseInitTypeDef  		TIM_TimeBaseStructure;
        UINT16 PrescalerValue;
        UINT8 port_index				=	fk_port_index(port);
        UINT8 pin_index					=	fk_pin_index(pin);
        fk_set_io(port,pin,GPIO_Speed_40MHz,GPIO_Speed_40MHz);
        GPIO_PinAFConfig((GPIO_TypeDef*)port,gt_fk_pinsource_register[pin_index], GPIO_AF_TIM5);      	
        RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5, ENABLE);

        PrescalerValue = (UINT16) (SystemCoreClock / FK_EXTERNAL_OSC_CLOCK) - 1;
        TIM_TimeBaseStructure.TIM_Period = period;
        TIM_TimeBaseStructure.TIM_Prescaler = PrescalerValue;
        TIM_TimeBaseStructure.TIM_ClockDivision = 0;
        TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
        TIM_TimeBaseInit(TIM5, &TIM_TimeBaseStructure);    
        
        TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
        TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
        TIM_OCInitStructure.TIM_Pulse = pulse;
        TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
        
        switch (pin)
        {
            case FK_PIN0:   TIM_OC1Init(TIM5, &TIM_OCInitStructure); TIM_OC1PreloadConfig(TIM5, TIM_OCPreload_Enable); break;
            case FK_PIN1:   TIM_OC2Init(TIM5, &TIM_OCInitStructure); TIM_OC2PreloadConfig(TIM5, TIM_OCPreload_Enable); break;
            case FK_PIN2:   TIM_OC3Init(TIM5, &TIM_OCInitStructure); TIM_OC3PreloadConfig(TIM5, TIM_OCPreload_Enable); break;
            case FK_PIN3:   TIM_OC4Init(TIM5, &TIM_OCInitStructure); TIM_OC4PreloadConfig(TIM5, TIM_OCPreload_Enable); break;
        }
        
        TIM_ARRPreloadConfig(TIM5, ENABLE);
        TIM_Cmd(TIM5, ENABLE);
}
    
#ifdef __cplusplus
}
#endif

