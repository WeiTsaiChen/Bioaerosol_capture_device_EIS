#ifndef FK_SYSTEM_UDEF_H
#define FK_SYSTEM_UDEF_H
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
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S
//
//**********************************************************************************************************************
#include "..\main.h"
#include "stm32l1xx.h"
#include "c_src\fk_idef.h"
#include "c_src\fk_init.h"
#include "c_src\fk_task.h"
#include "c_src\fk_glb_vars.h" 
//**********************************************************************************************************************
//
// E X T E R N A L   G L O B A L   C O N S T A N C E   /   V A R I A B L E S   I N   E E P R O M
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// C O N D I C T I O N   C O M P I L E
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// A P I   F O R   O T H E R   M O D U L E S
//
//**********************************************************************************************************************
//! @brief FK Library Initial Function
#define	FK_INIT_API()					          fk_init()

//=================================================================================================================//
//! @brief Null Function ( Just Return )
#define FK_NULL_FUNC                                              fk_null

// System Clock
//! @brief We need to reset all clock setting for ensuring everything is ok
#define FK_RESET_CLOCK_SETTING_API()                              RCC_DeInit()

//=================================================================================================================//
//! @brief Turn on High Speed External Oscillator
#define FK_TURN_ON_HSE_API()                                      RCC_HSEConfig(RCC_HSE_ON);while(RCC_WaitForHSEStartUp()==ERROR)

//=================================================================================================================//
//! @brief Turn on other kinds of oscillator as our High Speed External Oscillator
#define FK_TURN_ON_HSE_AND_PASSBY_API()                           RCC_HSEConfig(RCC_HSE_Bypass);while(RCC_WaitForHSEStartUp()==ERROR)

//=================================================================================================================//
//! @brief Turn off High Speed External Oscillator
#define FK_TURN_OFF_HSE_API()                                     RCC_HSEConfig(RCC_HSE_ON+RCC_HSE_Bypass)

//=================================================================================================================//
//! @brief  Adjusts the Internal High Speed oscillator (HSI) calibration value.
//! @param  HSICalibrationValue: specifies the calibration trimming value.
//          This parameter must be a number between 0 and 0x1F.
#define FK_ADJUST_HSI_API(value)                                  RCC_AdjustHSICalibrationValue(value&0x1f)

//=================================================================================================================//
//! @brief  Enables or disables the Internal High Speed oscillator (HSI).
//! @note   HSI can not be stopped if it is used directly or through the PLL as system clock.
#define FK_TURN_ON_HSI_API()                                      RCC_HSICmd(ENABLE)
#define FK_TURN_OFF_HSI_API()                                     RCC_HSICmd(DISABLE)

//=================================================================================================================//
//! @brief Turn on Low Speed External Oscillator
#define FK_TURN_ON_LSE_API()                                      RCC_LSEConfig(RCC_LSE_ON);while(RCC_GetFlagStatus(RCC_FLAG_LSERDY)==RESET)

//=================================================================================================================//
//! @brief Turn on other kinds of oscillator as our Low Speed External Oscillator
#define FK_TURN_ON_LSE_AND_PASSBY_API()                           RCC_LSEConfig(RCC_LSE_Bypass)

//=================================================================================================================//
//! @brief Turn off Low Speed External Oscillator
#define FK_TURN_OFF_LSE_API()                                     RCC_LSEConfig(RCC_LSE_ON+RCC_LSE_Bypass)
#define FK_TURN_ON_LSI_API()                                      RCC_LSICmd(ENABLE);while(RCC_GetFlagStatus(RCC_FLAG_LSIRDY)==RESET)
#define FK_TURN_OFF_LSI_API()                                     RCC_LSICmd(DISABLE)

//=================================================================================================================//
#define FK_ENABLE_PLL_API()                                       RCC_PLLCmd(ENABLE);while((RCC->CR&RCC_CR_PLLRDY)==0)
#define FK_DISABLE_PLL_API()                                      RCC_PLLCmd(DISABLE)
/**
  * @brief  Configures the PLL clock source and multiplication factor.
  * @note   This function must be used only when the PLL is disabled.
  *   
  * @param  RCC_PLLSource: specifies the PLL entry clock source.
  *   This parameter can be one of the following values:
  *     @arg RCC_PLLSource_HSI: HSI oscillator clock selected as PLL clock source
  *     @arg RCC_PLLSource_HSE: HSE oscillator clock selected as PLL clock source
  * @note   The minimum input clock frequency for PLL is 2 MHz (when using HSE as
  *         PLL source).
  *               
  * @param  RCC_PLLMul: specifies the PLL multiplication factor, which drive the PLLVCO clock
  *   This parameter can be:
  *     @arg RCC_PLLMul_3: PLL clock source multiplied by 3
  *     @arg RCC_PLLMul_4: PLL clock source multiplied by 4
  *     @arg RCC_PLLMul_6: PLL clock source multiplied by 6
  *     @arg RCC_PLLMul_8: PLL clock source multiplied by 8
  *     @arg RCC_PLLMul_12: PLL clock source multiplied by 12
  *     @arg RCC_PLLMul_16: PLL clock source multiplied by 16  
  *     @arg RCC_PLLMul_24: PLL clock source multiplied by 24
  *     @arg RCC_PLLMul_32: PLL clock source multiplied by 32
  *     @arg RCC_PLLMul_48: PLL clock source multiplied by 48
  * @note   The application software must set correctly the PLL multiplication
  *         factor to avoid exceeding:
  *             - 96 MHz as PLLVCO when the product is in range 1
  *             - 48 MHz as PLLVCO when the product is in range 2
  *             - 24 MHz when the product is in range 3
  * @note   When using the USB the PLLVCO should be 96MHz
  *                                   
  * @param  RCC_PLLDiv: specifies the PLL division factor.
  *   This parameter can be:
  *     @arg RCC_PLLDiv_2: PLL Clock output divided by 2  
  *     @arg RCC_PLLDiv_3: PLL Clock output divided by 3         
  *     @arg RCC_PLLDiv_4: PLL Clock output divided by 4  
  * @note   The application software must set correctly the output division to avoid
  *         exceeding 32 MHz as SYSCLK.
  *            
  * @retval None
  */

      #define FK_PLL_MUL                                                RCC_PLLMul_8
      #define FK_PLL_DIV                                                RCC_PLLDiv_2
#if (MAIN_USE_PLL == 1) 
      #define FK_PLL_CLOCK						((FK_EXTERNAL_OSC_CLOCK/2)*8)
#else
      #if MAIN_USE_HSE == 1
              #define FK_PLL_CLOCK					(FK_EXTERNAL_OSC_CLOCK)
      #else
              #define FK_PLL_CLOCK                                      16000000                           
      #endif
#endif  
      #define FK_SYSTEM_CLOCK                                           FK_PLL_CLOCK
      #define FK_SYSTEM_MS_PRESCALER                                    ((FK_PLL_CLOCK/9000))
/**
  * @brief  Configures the system clock (SYSCLK).
  * @note     The MSI is used (enabled by hardware) as system clock source after
  *           startup from Reset, wake-up from STOP and STANDBY mode, or in case
  *           of failure of the HSE used directly or indirectly as system clock
  *           (if the Clock Security System CSS is enabled).
  * @note     A switch from one clock source to another occurs only if the target
  *           clock source is ready (clock stable after startup delay or PLL locked). 
  *           If a clock source which is not yet ready is selected, the switch will
  *           occur when the clock source will be ready. 
  *           You can use RCC_GetSYSCLKSource() function to know which clock is
  *           currently used as system clock source.  
  * @param  RCC_SYSCLKSource: specifies the clock source used as system clock source 
  *   This parameter can be one of the following values:
  *     @arg RCC_SYSCLKSource_MSI:    MSI selected as system clock source
  *     @arg RCC_SYSCLKSource_HSI:    HSI selected as system clock source
  *     @arg RCC_SYSCLKSource_HSE:    HSE selected as system clock source
  *     @arg RCC_SYSCLKSource_PLLCLK: PLL selected as system clock source
  * @retval None
  */
//=================================================================================================================//
#if MAIN_USE_MSI == 1 
/**
  * @brief  Configures the Internal Multi Speed oscillator (MSI) clock range.
  * @note     After restart from Reset or wakeup from STANDBY, the MSI clock is 
  *           around 2.097 MHz. The MSI clock does not change after wake-up from
  *           STOP mode.
  *  @note    The MSI clock range can be modified on the fly.     
  * @param  RCC_MSIRange: specifies the MSI Clock range.
  *   This parameter must be one of the following values:
  *     @arg RCC_MSIRange_0: MSI clock is around 65.536 KHz
  *     @arg RCC_MSIRange_1: MSI clock is around 131.072 KHz
  *     @arg RCC_MSIRange_2: MSI clock is around 262.144 KHz
  *     @arg RCC_MSIRange_3: MSI clock is around 524.288 KHz
  *     @arg RCC_MSIRange_4: MSI clock is around 1.048 MHz
  *     @arg RCC_MSIRange_5: MSI clock is around 2.097 MHz (default after Reset or wake-up from STANDBY)
  *     @arg RCC_MSIRange_6: MSI clock is around 4.194 MHz
  *                   
  * @retval None
  */  
                #define FK_SET_MSI_RANGE_API(range)                     RCC_MSIRangeConfig(range)
                #define FK_SET_INIT_MSI_RANGE_API()                     FK_SET_MSI_RANGE_API(RCC_MSIRange_4)        
                #define FK_SET_SYSCLOCK_SOURCE_API()			RCC_SYSCLKConfig(RCC_SYSCLKSource_MSI)
#endif
#if (MAIN_USE_HSE ==1) && (MAIN_USE_PLL ==0) && (MAIN_USE_MSI == 0)	
  		#define FK_SET_SYSCLOCK_SOURCE_API()			RCC_SYSCLKConfig(RCC_SYSCLKSource_HSE)
#endif
//==================================================================================================================//
#if (MAIN_USE_HSI ==1) && (MAIN_USE_PLL ==0) && (MAIN_USE_MSI == 0)	
		#define FK_SET_SYSCLOCK_SOURCE_API()			RCC_SYSCLKConfig(RCC_SYSCLKSource_HSI)
#endif
//==================================================================================================================// 
#if (MAIN_USE_HSE ==1) && (MAIN_USE_PLL ==1) && (MAIN_USE_MSI == 0)	      	
		#define FK_PLL_CONFIG_API()				RCC_PLLConfig(RCC_PLLSource_HSE,FK_PLL_DIV,FK_PLL_MUL)
  		#define FK_SET_SYSCLOCK_SOURCE_API()			RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK)
#endif
//==================================================================================================================//
#if (MAIN_USE_HSI ==1) && (MAIN_USE_PLL ==1) && (MAIN_USE_MSI == 0)	   
		#define FK_PLL_CONFIG_API()				RCC_PLLConfig(RCC_PLLSource_HSI,FK_PLL_DIV,FK_PLL_MUL)
 		#define FK_SET_SYSCLOCK_SOURCE_API()			RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK)
#endif
//=================================================================================================//
//Returns the clock source used as system clock
//=================================================================================================================//
//! @brief  Returns the clock source used as system clock.
//! @param  None
//! @retval The clock source used as system clock. The returned value can
//!   be one of 
//================the following:
//!               - 0x00: MSI used as system clock
//!               - 0x04: HSI used as system clock  
//!               - 0x08: HSE used as system clock
//!               - 0x0C: PLL used as system clock
#define FK_GET_SYSCLOCK_SOURCE_API()                                            RCC_GetSYSCLKSource()
//=================================================================================================================//
//Configures the AHB clock (HCLK).
//=================================================================================================================//
/**
  * @brief  Configures the AHB clock (HCLK).
  * @note   Depending on the device voltage range, the software has to set correctly
  *         these bits to ensure that the system frequency does not exceed the
  *         maximum allowed frequency (for more details refer to section above
  *         "CPU, AHB and APB busses clocks configuration functions")
  * @param  RCC_SYSCLK: defines the AHB clock divider. This clock is derived from 
  *                     the system clock (SYSCLK).
  *   This parameter can be one of the following values:
  *     @arg RCC_SYSCLK_Div1:   AHB clock = SYSCLK
  *     @arg RCC_SYSCLK_Div2:   AHB clock = SYSCLK/2
  *     @arg RCC_SYSCLK_Div4:   AHB clock = SYSCLK/4
  *     @arg RCC_SYSCLK_Div8:   AHB clock = SYSCLK/8
  *     @arg RCC_SYSCLK_Div16:  AHB clock = SYSCLK/16
  *     @arg RCC_SYSCLK_Div64:  AHB clock = SYSCLK/64
  *     @arg RCC_SYSCLK_Div128: AHB clock = SYSCLK/128
  *     @arg RCC_SYSCLK_Div256: AHB clock = SYSCLK/256
  *     @arg RCC_SYSCLK_Div512: AHB clock = SYSCLK/512
  * @retval None
  */
#define FK_AHB_CLOCK                                                            (FK_PLL_CLOCK)
#define FK_AHB_SET_CLOCK_API()                                                  RCC_HCLKConfig(RCC_SYSCLK_Div1)
//=================================================================================================================//
//Configures the Low Speed APB clock (PCLK1)
//=================================================================================================================//
/**
  * @brief  Configures the Low Speed APB clock (PCLK1).
  * @param  RCC_HCLK: defines the APB1 clock divider. This clock is derived from 
  *                   the AHB clock (HCLK).
  *   This parameter can be one of the following values:
  *     @arg RCC_HCLK_Div1:  APB1 clock = HCLK
  *     @arg RCC_HCLK_Div2:  APB1 clock = HCLK/2
  *     @arg RCC_HCLK_Div4:  APB1 clock = HCLK/4
  *     @arg RCC_HCLK_Div8:  APB1 clock = HCLK/8
  *     @arg RCC_HCLK_Div16: APB1 clock = HCLK/16
  * @retval None
  */
#define FK_APB1_CLOCK                                             (FK_AHB_CLOCK)
#define FK_APB1_MS_PRESCALER                                      (FK_APB1_CLOCK/1000)
#define FK_APB1_SET_CLOCK_API()                                   RCC_PCLK1Config(RCC_HCLK_Div1)
//=================================================================================================================//
//Configures the High Speed APB clock (PCLK2)
//=================================================================================================================//
/**
  * @brief  Configures the High Speed APB clock (PCLK2).
  * @param  RCC_HCLK: defines the APB2 clock divider. This clock is derived from 
  *                   the AHB clock (HCLK).
  *   This parameter can be one of the following values:
  *     @arg RCC_HCLK_Div1:  APB2 clock = HCLK
  *     @arg RCC_HCLK_Div2:  APB2 clock = HCLK/2
  *     @arg RCC_HCLK_Div4:  APB2 clock = HCLK/4
  *     @arg RCC_HCLK_Div8:  APB2 clock = HCLK/8
  *     @arg RCC_HCLK_Div16: APB2 clock = HCLK/16
  * @retval None
  */
#define FK_APB2_CLOCK                                             (FK_AHB_CLOCK)
#define FK_APB2_MS_PRESCALER                                      (FK_APB2_CLOCK/1000)
#define FK_APB2_SET_CLOCK_API()                                   RCC_PCLK2Config(RCC_HCLK_Div1)
/**
  * @brief  Selects the clock source to output on MCO pin (PA8).
  * @note   PA8 should be configured in alternate function mode.   
  * @param  RCC_MCOSource: specifies the clock source to output.
  *   This parameter can be one of the following values:
  *     @arg RCC_MCOSource_NoClock: No clock selected
  *     @arg RCC_MCOSource_SYSCLK: System clock selected
  *     @arg RCC_MCOSource_HSI: HSI oscillator clock selected
  *     @arg RCC_MCOSource_MSI: MSI oscillator clock selected  
  *     @arg RCC_MCOSource_HSE: HSE oscillator clock selected
  *     @arg RCC_MCOSource_PLLCLK: PLL clock selected
  *     @arg RCC_MCOSource_LSI: LSI clock selected
  *     @arg RCC_MCOSource_LSE: LSE clock selected    
  * @param  RCC_MCODiv: specifies the MCO prescaler.
  *   This parameter can be one of the following values: 
  *     @arg RCC_MCODiv_1: no division applied to MCO clock 
  *     @arg RCC_MCODiv_2: division by 2 applied to MCO clock
  *     @arg RCC_MCODiv_4: division by 4 applied to MCO clock
  *     @arg RCC_MCODiv_8: division by 8 applied to MCO clock
  *     @arg RCC_MCODiv_16: division by 16 applied to MCO clock             
  * @retval None
  */
#define FK_MCO_CONFIG_API()                                       RCC_MCOConfig(RCC_MCOSource_SYSCLK,RCC_MCODiv_1);
#define FK_MCO_OUTPUT_API()                                       fk_set_io((UINT32)FK_PORTA,FK_PIN8,GPIO_Speed_40MHz,GPIO_Mode_AF_PP);FK_MCO_CONFIG_API()
/**
  * @brief  Enables or disables the Prefetch Buffer.
  * @param  NewState: new state of the FLASH prefetch buffer.
  *              This parameter can be: ENABLE or DISABLE. 
  * @retval None
  */
#define FK_SET_FLASH_PREFETCH_API()                               FLASH_PrefetchBufferCmd(ENABLE)
/**
  * @brief  Sets the code latency value.
  * @param  FLASH_Latency: specifies the FLASH Latency value.
  *   This parameter can be one of the following values:
  *     @arg FLASH_Latency_0: FLASH Zero Latency cycle.
  *     @arg FLASH_Latency_1: FLASH One Latency cycle.
  * @retval None
  */
#define FK_SET_FLASH_LATENCY_API()                                FLASH_SetLatency(FLASH_Latency_1)


//=================================================================================================================//
//System Tick
//=================================================================================================================//
// System Tick
//! @brief Setting 1ms timer for doing something you want
#define FK_1MS_SYSTEM_TICK_ENABLE_API(func)                       SysTick_Config(FK_SYSTEM_MS_PRESCALER);gfunc_fk_systick_func=func
//! @brief Setting 250ms timer for doing something you want
#define FK_250MS_SYSTEM_TICK_ENABLE_API(func)                     SysTick_Config(FK_SYSTEM_MS_PRESCALER*250);gfunc_fk_systick_func=func
//! @brief Setting 500ms timer for doing something you want
#define FK_500MS_SYSTEM_TICK_ENABLE_API(func)                     SysTick_Config(FK_SYSTEM_MS_PRESCALER*500);gfunc_fk_systick_func=func
//! @brief Setting 1 sec timer for doing something you want
#define FK_1S_SYSTEM_TICK_ENABLE_API(func)                        SysTick_Config(FK_SYSTEM_MS_PRESCALER*1000);gfunc_fk_systick_func=func
//! @brief Setting ms unit system tick
#define FK_MS_SYSTEM_TICK_ENABLE_API(func,ms)                     SysTick_Config(FK_SYSTEM_MS_PRESCALER*ms);gfunc_fk_systick_func=func

//**********************************************************************************************************************
//
// C   P L U S   P L U S   C O M P A T I A B L E   D E F I N I T I O N
//
//**********************************************************************************************************************
#ifdef __cplusplus
}
#endif
#endif		// FK_SYSTEM_UDEF_H 
