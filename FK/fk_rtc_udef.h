#ifndef FK_RTC_UDEF_H
#define FK_RTC_UDEF_H
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
// RTC Function
//! @brief Enable RTC function
#define FK_RTC_ENABLE_API(func)                                   gfunc_fk_rtc_alarm_func=func;fk_rtc_enable(0)

//! @brief Setting (H,M,S) into RTC
#define FK_RTC_SET_TIME_API(h,m,s)                                fk_rtc_enable(h*3600+m*60+s)

//! @brief Reading the time data
#define FK_RTC_GET_TIME_API()                                     RTC_GetCounter()

//! @brief There're a one-second period timer for us in RTC function
#define FK_RTC_SET_SECOND_FUNC_API(func)                          fk_set_rtc_second_func(func)

//! @brief Disable RTC's one-second period timer function
#define FK_RTC_DISABLE_SECOND_FUNC_API()                          FK_INTERRUPT_DISABLE_API(RTC_IRQn)

//! @brief Check RTC Alarm flag
#define FK_RTC_CHK_ALARM_API()                                    gs_fk_interrupt_list.rtc_alarm

//! @brief Clear RTC Alarm flag
#define FK_RTC_CLEAR_ALARM_FLAG_API()                             gs_fk_interrupt_list.rtc_alarm=0

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
#endif		// FK_RTC_UDEF_H 
