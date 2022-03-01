#ifndef FK_GPIO_UDEF_H
#define FK_GPIO_UDEF_H
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
// GPIO Pin Definition
#define FK_PORTA                                      	GPIOA
#define FK_PORTB                                      	GPIOB
#define FK_PORTC                                      	GPIOC
#define FK_PORTD                                      	GPIOD
#define FK_PORTE                                      	GPIOE
#define FK_PORTF                                      	GPIOF
#define FK_PORTG                                      	GPIOG
#define FK_PORT_TOTAL                                7

#define FK_PIN0	                                      	GPIO_Pin_0
#define FK_PIN1	                                      	GPIO_Pin_1
#define FK_PIN2	                                      	GPIO_Pin_2
#define FK_PIN3	                                      	GPIO_Pin_3
#define FK_PIN4	                                      	GPIO_Pin_4
#define FK_PIN5	                                      	GPIO_Pin_5
#define FK_PIN6	                                      	GPIO_Pin_6
#define FK_PIN7	                                      	GPIO_Pin_7
#define FK_PIN8	                                      	GPIO_Pin_8
#define FK_PIN9	                                      	GPIO_Pin_9
#define FK_PIN10	                              		GPIO_Pin_10
#define FK_PIN11	                              		GPIO_Pin_11
#define FK_PIN12	                              		GPIO_Pin_12
#define FK_PIN13	                              		GPIO_Pin_13
#define FK_PIN14	                              		GPIO_Pin_14
#define FK_PIN15	                              		GPIO_Pin_15
#define FK_ALLPIN	                              	GPIO_Pin_All
#define FK_PIN_TOTAL									16
  
 enum
 {
          GPIO_Mode_Out_PP,
          GPIO_Mode_Out_OD,
          GPIO_Mode_IN_FLOATING,
          GPIO_Mode_AF_PP,
          GPIO_Mode_AIN_NOPULL,
          GPIO_Mode_IPD,
          GPIO_Mode_IPU,
 };
 
#define FK_GPIO_SPEED                                       GPIO_Speed_10MHz

#define FK_TRIGGER_RASING                             EXTI_Trigger_Rising
#define FK_TRIGGER_FALLING                           EXTI_Trigger_Falling
#define FK_TRIGGER_RASING_FALLING          EXTI_Trigger_Rising_Falling
 
 #define FK_FALLING_EDGE                TIM_ICPolarity_Falling
#define FK_RASING_EDGE                 TIM_ICPolarity_Rising
#define FK_BOTH_EDGE                   TIM_ICPolarity_BothEdge
//**********************************************************************************************************************
//
// A P I   F O R   O T H E R   M O D U L E S
//
//**********************************************************************************************************************
// GPIO Function
//===(GPIO的速度是指I/O驅動電路的速度而不是輸出訊號的速度,輸出訊號的速度取決於使用者的需求與程序)
//! @brief Setting I/O pin as output ( Push Pump Mode : 25mA max ,I/O Speed: as FK_GPIO_SPEED )
#define FK_SET_PIN_OUPUT_PUSH_PUMP_API(port,pin)                     fk_set_io((UINT32)port,pin,FK_GPIO_SPEED,GPIO_Mode_Out_PP)

//! @brief Setting I/O pin as output ( Push Pump Mode : 25mA max ,I/O Speed: 40MHz )
#define FK_SET_PIN_OUPUT_PUSH_PUMP_HIGH_SPEED_40MHz_API(port,pin)    fk_set_io((UINT32)port,pin,GPIO_Speed_40MHz,GPIO_Mode_Out_PP)

//! @brief Setting I/O pin as output ( Push Pump Mode : 25mA max ,I/O Speed: 10MHz )
#define FK_SET_PIN_OUPUT_PUSH_PUMP_MID_SPEED_10MHZ_API(port,pin)     fk_set_io((UINT32)port,pin,GPIO_Speed_10MHz,GPIO_Mode_Out_PP)

//! @brief Setting I/O pin as output ( Push Pump Mode : 25mA max ,I/O Speed: 2MHz )
#define FK_SET_PIN_OUPUT_PUSH_PUMP_LOW_SPEED_2MHZ_API(port,pin)      fk_set_io((UINT32)port,pin,GPIO_Speed_2MHz,GPIO_Mode_Out_PP)

//! @brief Setting I/O pin as output ( Open Drain Mode ,I/O Speed: as FK_GPIO_SPEED )
#define FK_SET_PIN_OUTPUT_OPEN_DRAIN_API(port,pin)                   fk_set_io((UINT32)port,pin,FK_GPIO_SPEED,GPIO_Mode_Out_OD)

//! @brief Setting I/O pin as output ( Open Drain Mode ,I/O Speed: 40MHz )
#define FK_SET_PIN_OUTPUT_OPEN_DRAIN_HIGH_SPEED_40MHz_API(port,pin)  fk_set_io((UINT32)port,pin,GPIO_Speed_40MHz,GPIO_Mode_Out_OD)

//! @brief Setting I/O pin as output ( Open Drain Mode ,I/O Speed: 10MHz )
#define FK_SET_PIN_OUTPUT_OPEN_DRAIN_MID_SPEED_10MHZ_API(port,pin)   fk_set_io((UINT32)port,pin,GPIO_Speed_10MHz,GPIO_Mode_Out_OD)

//! @brief Setting I/O pin as output ( Open Drain Mode ,I/O Speed: 2MHz )
#define FK_SET_PIN_OUTPUT_OPEN_DRAIN_LOW_SPEED_2MHZ_API(port,pin)    fk_set_io((UINT32)port,pin,GPIO_Speed_2MHz,GPIO_Mode_Out_OD)

//! @brief Setting I/O pin as input ( Floating Mode ,I/O Speed: as FK_GPIO_SPEED )
#define FK_SET_PIN_INPUT_FLOATING_API(port,pin)                      fk_set_io((UINT32)port,pin,FK_GPIO_SPEED,GPIO_Mode_IN_FLOATING)

//! @brief Setting I/O pin as input ( Floating Mode ,I/O Speed: 40MHz )
#define FK_SET_PIN_INPUT_FLOATING_HIGH_SPEED_40MHz_API(port,pin)     fk_set_io((UINT32)port,pin,GPIO_Speed_40MHz,GPIO_Mode_IN_FLOATING)

//! @brief Setting I/O pin as input ( Floating Mode ,I/O Speed: 10MHz )
#define FK_SET_PIN_INPUT_FLOATING_MID_SPEED_10MHZ_API(port,pin)      fk_set_io((UINT32)port,pin,GPIO_Speed_10MHz,GPIO_Mode_IN_FLOATING)

//! @brief Setting I/O pin as input ( Floating Mode ,I/O Speed: 20MHz )
#define FK_SET_PIN_INPUT_FLOATING_LOW_SPEED_2MHZ_API(port,pin)       fk_set_io((UINT32)port,pin,GPIO_Speed_2MHz,GPIO_Mode_IN_FLOATING)

//! @brief Setting I/O pin as input ( Pull Down Mode ,I/O Speed: as FK_GPIO_SPEED )
#define FK_SET_PIN_INPUT_PULL_DOWN_API(port,pin)                     fk_set_io((UINT32)port,pin,FK_GPIO_SPEED,GPIO_Mode_IPD)

//! @brief Setting I/O pin as input ( Pull Down Mode ,I/O Speed: 40MHz )
#define FK_SET_PIN_INPUT_PULL_DOWN_HIGH_SPEED_40MHz_API(port,pin)    fk_set_io((UINT32)port,pin,GPIO_Speed_40MHz,GPIO_Mode_IPD)

//! @brief Setting I/O pin as input ( Pull Down Mode ,I/O Speed: 10MHz )
#define FK_SET_PIN_INPUT_PULL_DOWN_MID_SPEED_10MHZ_API(port,pin)     fk_set_io((UINT32)port,pin,GPIO_Speed_10MHz,GPIO_Mode_IPD)

//! @brief Setting I/O pin as input ( Pull Down Mode ,I/O Speed: 2MHz )
#define FK_SET_PIN_INPUT_PULL_DOWN_LOW_SPEED_2MHZ_API(port,pin)      fk_set_io((UINT32)port,pin,GPIO_Speed_2MHz,GPIO_Mode_IPD)

//! @brief Setting I/O pin as input ( Push High Mode ,I/O Speed: as FK_GPIO_SPEED )
#define FK_SET_PIN_INPUT_PULL_HIGH_API(port,pin)                     fk_set_io((UINT32)port,pin,FK_GPIO_SPEED,GPIO_Mode_IPU)

//! @brief Setting I/O pin as input ( Push High Mode ,I/O Speed: as FK_GPIO_SPEED )
#define FK_SET_PIN_INPUT_PULL_HIGH_HIGH_SPEED_40MHz_API(port,pin)    fk_set_io((UINT32)port,pin,GPIO_Speed_40MHz,GPIO_Mode_IPU)

//! @brief Setting I/O pin as input ( Push High Mode ,I/O Speed: as FK_GPIO_SPEED )
#define FK_SET_PIN_INPUT_PULL_HIGH_MID_SPEED_10MHZ_API(port,pin)     fk_set_io((UINT32)port,pin,GPIO_Speed_10MHz,GPIO_Mode_IPU)

//! @brief Setting I/O pin as input ( Push High Mode ,I/O Speed: as FK_GPIO_SPEED )
#define FK_SET_PIN_INPUT_PULL_HIGH_LOW_SPEED_2MHZ_API(port,pin)      fk_set_io((UINT32)port,pin,GPIO_Speed_2MHz,GPIO_Mode_IPU)

//! @brief Getting I/O Pin state
#define FK_CHK_PIN_STATE_API(port,pin)                            GPIO_ReadInputDataBit(port,pin)
 
 //! @brief Getting I/O Port State
 #define FK_CHK_PORT_STATE_API(port,pin)                            GPIO_ReadInputData(port,pin)

//! @brief Setting I/O Pin output High
#define FK_SET_OUTPUT_PIN_HIGH_API(port,pin)                      port->BSRRL=pin

//! @brief Setting I/O pin output Low
#define FK_SET_OUTPUT_PIN_LOW_API(port,pin)                       port->BSRRH=pin

//! @brief Toggle I/O pin state
#define FK_SET_OUTPUT_PIN_TOGGLE_API(port,pin)                    port->ODR^=pin

//! @brief Setting Interrupt Pin Function ( Rasing Interrupt )
#define FK_SET_RASING_INTERRUPT_PIN_API(port,pin,func)            fk_set_io_interrupt((UINT32)port,pin,FK_TRIGGER_RASING,func,ENABLE)

//! @brief Setting Interrupt Pin Function ( Falling Interrupt )
#define FK_SET_FALLING_INTERRUPT_PIN_API(port,pin,func)           fk_set_io_interrupt((UINT32)port,pin,FK_TRIGGER_FALLING,func,ENABLE)

//! @brief Setting Interrupt Pin Function ( Rasing && Falling Interrupt )
#define FK_SET_RASING_FALLING_INTERRUPT_PIN_API(port,pin,func)    fk_set_io_interrupt((UINT32)port,pin,FK_TRIGGER_RASING_FALLING,func,ENABLE)

//! @brief Disable Interrupt Pin Function
#define FK_SET_DISABLE_INTERRUPT_PIN_API(port,pin)                fk_set_io_interrupt((UINT32)port,pin,FK_TRIGGER_RASING_FALLING,fk_null,DISABLE)
//**********************************************************************************************************************
//
// F U N C T I O N   P R O T O T Y P E S
//
//**********************************************************************************************************************

//**********************************************************************************************************************
//
// C   P L U S   P L U S   C O M P A T I A B L E   D E F I N I T I O N
//
//**********************************************************************************************************************
#ifdef __cplusplus
}
#endif
#endif		// FK_GPIO_UDEF_H 
