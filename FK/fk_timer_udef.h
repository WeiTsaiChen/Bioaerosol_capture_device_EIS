#ifndef FK_TIMER_UDEF_H
#define FK_TIMER_UDEF_H
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
// E X T E R N A L   G L O B A L   C O N S T A N C E   /   V A R I A B L E S   I N   E E P R O M
//
//**********************************************************************************************************************
/*
Name	    Main Purpose	    Counter Type	Resolution	Capture/Compare Channels
Timer2	    Gerneral-Purpose	Up/Down	            16Bits	        4
Timer3	    Gerneral-Purpose	Up/Down	            16Bits	        4
Timer4	    Gerneral-Purpose	Up/Down	            16Bits	        4		
Timer5	    Capture/Output,PWM	Up/Down	            32Bits	        4		
Timer9	    Capture/Output,PWM	Up/Down	            16Bits	        2		
Timer10		                    Up	                16Bits	        1
Timer11		                    Up	                16Bits	        1		
Timer6	    Basic Timer (DAC)	Up	                16Bits	        0
Timer7	    Basic Timer (DAC)	Up	                16Bits	        0
*/
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
// C O N D I C T I O N   C O M P I L E
//
//**********************************************************************************************************************
#define FK_1MS_SET		1
#define FK_2MS_SET		2
#define FK_4MS_SET		4
#define FK_8MS_SET		8
#define FK_10MS_SET	    10
//**********************************************************************************************************************
//
// A P I   F O R   O T H E R   M O D U L E S
//
//**********************************************************************************************************************
// Timer Function
//!@ TIM Compute ==> ((1+TIM_Prescaler )/TIM_CLOCK)*(1+TIM_Period )
//! @brief Setting TIM2 interrupt function in once mode.
#define FK_SET_TIMER_INTERRUPT1_FUNC_ONCE_API(prescale,count,func)       fk_timer_interrupt_enable(FK_INTERRUPT1_FUNC_ONCE,prescale,count,func)
#define FK_SET_MS_TIMER_INTERRUPT1_FUNC_ONCE_API(ms,func)                FK_SET_TIMER_INTERRUPT1_FUNC_ONCE_API(FK_APB1_MS_PRESCALER,ms,func)

//! @brief Setting TIM2 interrupt function in continue mode.
#define FK_SET_TIMER_INTERRUPT1_FUNC_CONTINUE_API(prescale,count,func)   fk_timer_interrupt_enable(FK_INTERRUPT3_FUNC_CONTINUE,prescale,count,func)
#define FK_SET_MS_TIMER_INTERRUPT1_FUNC_CONTINUE_API(ms,func)            FK_SET_TIMER_INTERRUPT1_FUNC_CONTINUE_API(FK_APB1_MS_PRESCALER,ms,func)   

//! @brief Setting TIM3 interrupt function in once mode.
#define FK_SET_TIMER_INTERRUPT2_FUNC_ONCE_API(prescale,count,func)       fk_timer_interrupt_enable(FK_INTERRUPT2_FUNC_ONCE,prescale,count,func)
#define FK_SET_MS_TIMER_INTERRUPT2_FUNC_ONCE_API(ms,func)                FK_SET_TIMER_INTERRUPT2_FUNC_ONCE_API(FK_APB1_MS_PRESCALER,ms,func)       

//! @brief Setting TIM3 interrupt function in continue mode.
#define FK_SET_TIMER_INTERRUPT2_FUNC_CONTINUE_API(prescale,count,func)   fk_timer_interrupt_enable(FK_INTERRUPT4_FUNC_CONTINUE,prescale,count,func)
#define FK_SET_MS_TIMER_INTERRUPT2_FUNC_CONTINUE_API(ms,func)            FK_SET_TIMER_INTERRUPT2_FUNC_CONTINUE_API(FK_APB1_MS_PRESCALER,ms,func)   

//============================================================================================================================//
// You Could configure FK_INTERRUPT_FUNC_TOTAL variable in fk_idef.h for changing the timer set
//============================================================================================================================//
// PA.0
#define FK_SET_TIMER_INPUT_CHANNEL_1_FALLING_EDGE_CAPTURE_FUNC_API(port,pin,func)     fk_timer_capture_enable(FK_INTERRUPT5_INPUT_CAPTURE,FK_TIMER_CHANNEL1,(UINT32)port,pin,FK_FALLING_EDGE,func)
#define FK_SET_TIMER_INPUT_CHANNEL_1_RASING_EDGE_CAPTURE_FUNC_API(port,pin,func)      fk_timer_capture_enable(FK_INTERRUPT5_INPUT_CAPTURE,FK_TIMER_CHANNEL1,(UINT32)port,pin,FK_RASING_EDGE,func)
#define FK_SET_TIMER_INPUT_CHANNEL_1_BOTH_EDGE_CAPTURE_FUNC_API(port,pin,func)        fk_timer_capture_enable(FK_INTERRUPT5_INPUT_CAPTURE,FK_TIMER_CHANNEL1,(UINT32)port,pin,FK_BOTH_EDGE,func)
#define FK_TIMER_INPUT_CHANNEL_1_CAPTURE_FUNC_DISABLE_API()                           TIM_ITConfig((TIM_TypeDef *)gt_fk_timer_register[FK_INTERRUPT5_INPUT_CAPTURE], TIM_IT_CC1,DISABLE);
#define FK_GET_TIMER_CHANNEL_1_CAPTURE_VALUE_API()                                    TIM_GetCapture1((TIM_TypeDef *)gt_fk_timer_register[FK_INTERRUPT5_INPUT_CAPTURE])
#define FK_SET_TIMER_CHANNEL_1_CAPTURE_VALUE_API(value)                               TIM_SetCompare1((TIM_TypeDef *)gt_fk_timer_register[FK_INTERRUPT5_INPUT_CAPTURE],value)
// PA.1
#define FK_SET_TIMER_INPUT_CHANNEL_2_FALLING_EDGE_CAPTURE_FUNC_API(port,pin,func)     fk_timer_capture_enable(FK_INTERRUPT5_INPUT_CAPTURE,FK_TIMER_CHANNEL2,(UINT32)port,pin,FK_FALLING_EDGE,func)
#define FK_SET_TIMER_INPUT_CHANNEL_2_RASING_EDGE_CAPTURE_FUNC_API(port,pin,func)      fk_timer_capture_enable(FK_INTERRUPT5_INPUT_CAPTURE,FK_TIMER_CHANNEL2,(UINT32)port,pin,FK_RASING_EDGE,func)
#define FK_SET_TIMER_INPUT_CHANNEL_2_BOTH_EDGE_CAPTURE_FUNC_API(port,pin,func)        fk_timer_capture_enable(FK_INTERRUPT5_INPUT_CAPTURE,FK_TIMER_CHANNEL2,(UINT32)port,pin,FK_BOTH_EDGE,func)
#define FK_TIMER_INPUT_CHANNEL_2_CAPTURE_FUNC_DISABLE_API()                           TIM_ITConfig((TIM_TypeDef *)gt_fk_timer_register[FK_INTERRUPT5_INPUT_CAPTURE], TIM_IT_CC2,DISABLE);
#define FK_GET_TIMER_CHANNEL_2_CAPTURE_VALUE_API()                                    TIM_GetCapture2((TIM_TypeDef *)gt_fk_timer_register[FK_INTERRUPT5_INPUT_CAPTURE])
#define FK_SET_TIMER_CHANNEL_2_CAPTURE_VALUE_API(value)                               TIM_SetCompare2((TIM_TypeDef *)gt_fk_timer_register[FK_INTERRUPT5_INPUT_CAPTURE],value)
// PA.2
#define FK_SET_TIMER_INPUT_CHANNEL_3_FALLING_EDGE_CAPTURE_FUNC_API(port,pin,func)     fk_timer_capture_enable(FK_INTERRUPT5_INPUT_CAPTURE,FK_TIMER_CHANNEL3,(UINT32)port,pin,FK_FALLING_EDGE,func)
#define FK_SET_TIMER_INPUT_CHANNEL_3_RASING_EDGE_CAPTURE_FUNC_API(port,pin,func)      fk_timer_capture_enable(FK_INTERRUPT5_INPUT_CAPTURE,FK_TIMER_CHANNEL3,(UINT32)port,pin,FK_RASING_EDGE,func)
#define FK_SET_TIMER_INPUT_CHANNEL_3_BOTH_EDGE_CAPTURE_FUNC_API(port,pin,func)        fk_timer_capture_enable(FK_INTERRUPT5_INPUT_CAPTURE,FK_TIMER_CHANNEL3,(UINT32)port,pin,FK_BOTH_EDGE,func)
#define FK_TIMER_INPUT_CHANNEL_3_CAPTURE_FUNC_DISABLE_API()                           TIM_ITConfig((TIM_TypeDef *)gt_fk_timer_register[FK_INTERRUPT5_INPUT_CAPTURE], TIM_IT_CC3,DISABLE);
#define FK_GET_TIMER_CHANNEL_3_CAPTURE_VALUE_API()                                    TIM_GetCapture3((TIM_TypeDef *)gt_fk_timer_register[FK_INTERRUPT5_INPUT_CAPTURE])
#define FK_SET_TIMER_CHANNEL_3_CAPTURE_VALUE_API(value)                               TIM_SetCompare3((TIM_TypeDef *)gt_fk_timer_register[FK_INTERRUPT5_INPUT_CAPTURE],value)
// PA.3
#define FK_SET_TIMER_INPUT_CHANNEL_4_FALLING_EDGE_CAPTURE_FUNC_API(port,pin,func)     fk_timer_capture_enable(FK_INTERRUPT5_INPUT_CAPTURE,FK_TIMER_CHANNEL4,(UINT32)port,pin,FK_FALLING_EDGE,func)
#define FK_SET_TIMER_INPUT_CHANNEL_4_RASING_EDGE_CAPTURE_FUNC_API(port,pin,func)      fk_timer_capture_enable(FK_INTERRUPT5_INPUT_CAPTURE,FK_TIMER_CHANNEL4,(UINT32)port,pin,FK_RASING_EDGE,func)
#define FK_SET_TIMER_INPUT_CHANNEL_4_BOTH_EDGE_CAPTURE_FUNC_API(port,pin,func)        fk_timer_capture_enable(FK_INTERRUPT5_INPUT_CAPTURE,FK_TIMER_CHANNEL4,(UINT32)port,pin,FK_BOTH_EDGE,func)
#define FK_TIMER_INPUT_CHANNEL_4_CAPTURE_FUNC_DISABLE_API()                           TIM_ITConfig((TIM_TypeDef *)gt_fk_timer_register[FK_INTERRUPT5_INPUT_CAPTURE], TIM_IT_CC4,DISABLE);
#define FK_GET_TIMER_CHANNEL_4_CAPTURE_VALUE_API()                                    TIM_GetCapture4((TIM_TypeDef *)gt_fk_timer_register[FK_INTERRUPT5_INPUT_CAPTURE])
#define FK_SET_TIMER_CHANNEL_4_CAPTURE_VALUE_API(value)                               TIM_SetCompare4((TIM_TypeDef *)gt_fk_timer_register[FK_INTERRUPT5_INPUT_CAPTURE],value)

//**********************************************************************************************************************
//
// F U N C T I O N   P R O T O T Y P E S
//
//**********************************************************************************************************************
#define FK_SET_PWM_OUTPUT_CHANNEL_1_FUNC_API(period,pulse)                      fk_timer_pwm_enable(FK_INTERRUPT5_INPUT_CAPTURE,FK_TIMER_CHANNEL1,(UINT32)FK_PORTA,FK_PIN0,period,pulse)
#define FK_SET_PWM_OUTPUT_CHANNEL_2_FUNC_API(period,pulse)                      fk_timer_pwm_enable(FK_INTERRUPT5_INPUT_CAPTURE,FK_TIMER_CHANNEL2,(UINT32)FK_PORTA,FK_PIN1,period,pulse)
#define FK_SET_PWM_OUTPUT_CHANNEL_3_FUNC_API(period,pulse)                      fk_timer_pwm_enable(FK_INTERRUPT5_INPUT_CAPTURE,FK_TIMER_CHANNEL3,(UINT32)FK_PORTA,FK_PIN2,period,pulse)
#define FK_SET_PWM_OUTPUT_CHANNEL_4_FUNC_API(period,pulse)                      fk_timer_pwm_enable(FK_INTERRUPT5_INPUT_CAPTURE,FK_TIMER_CHANNEL4,(UINT32)FK_PORTA,FK_PIN3,period,pulse)
#define FK_SET_PWM_OUTPUT_DISABLE_FUNC_DISABLE_API()                            RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5,DISABLE)
//**********************************************************************************************************************
//
// C   P L U S   P L U S   C O M P A T I A B L E   D E F I N I T I O N
//
//**********************************************************************************************************************
#ifdef __cplusplus
}
#endif
#endif		// FK_TIMER_UDEF_H 
