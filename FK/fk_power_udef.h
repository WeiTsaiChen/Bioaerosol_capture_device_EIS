#ifndef FK_POWER_UDEF_H
#define FK_POWER_UDEF_H
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

//**********************************************************************************************************************
//
// A P I   F O R   O T H E R   M O D U L E S
//
//**********************************************************************************************************************
// Power Function
//! @brief The API for entering stop mode
#define FK_ENTER_STOP_MODE_API()                          fk_enter_stop_mode()
#define FK_ENTER_STANDBY_MODE_API()                       PWR_EnterSTANDBYMode()
#define FK_ENTER_SLEEP_MODE_API()                         __WFI()

#if MAIN_LOW_POWER_MODE == 1
#define FK_SPEED_UP_API()                                 fk_speed_up()
#else
#define FK_SPEED_UP_API()
#endif

#define FK_UART1_HIGH_SPEED_API()                         gs_fk_interrupt_list.usart1=1
#define FK_UART2_HIGH_SPEED_API()                         gs_fk_interrupt_list.usart2=1
#define FK_UART3_HIGH_SPEED_API()                         gs_fk_interrupt_list.usart3=1
#define FK_CAPTURE_HIGH_SPEED_API()                       gs_fk_interrupt_list.capture=1
#define FK_UART1_LOW_SPEED_API()                          gs_fk_interrupt_list.usart1=0
#define FK_UART2_LOW_SPEED_API()                          gs_fk_interrupt_list.usart2=0
#define FK_UART3_LOW_SPEED_API()                          gs_fk_interrupt_list.usart3=0
#define FK_CAPTURE_LOW_SPEED_API()                        gs_fk_interrupt_list.capture=0  

// PVD Power Votlage Detect Interrupt
/**
  * @brief  Configures the voltage threshold detected by the Power Voltage Detector(PVD).
  * @param  PWR_PVDLevel: specifies the PVD detection level.
  *   This parameter can be one of the following values:
  *     @arg PWR_PVDLevel_0: PVD detection level set to 1.9V.
  *     @arg PWR_PVDLevel_1: PVD detection level set to 2.1V.
  *     @arg PWR_PVDLevel_2: PVD detection level set to 2.3V.
  *     @arg PWR_PVDLevel_3: PVD detection level set to 2.5V.
  *     @arg PWR_PVDLevel_4: PVD detection level set to 2.7V.
  *     @arg PWR_PVDLevel_5: PVD detection level set to 2.9V.
  *     @arg PWR_PVDLevel_6: PVD detection level set to 3.1V.
  *     @arg PWR_PVDLevel_7: External input analog voltage (Compare internally to VREFINT).
  * @retval None
  */
#define FK_PVD_ENABLE_API(func)                           fk_pvd_enable(PWR_PVDLevel_6,func)

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
#endif		// FK_POWER_UDEF_H 
