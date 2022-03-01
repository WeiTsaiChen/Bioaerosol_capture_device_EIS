#ifndef BTC_UDEF_H
#define BTC_UDEF_H
//*********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 	 btc_udef.h
//
//! @author  Willman Chen
//
//! @date 	 2009/06/22
//
// @brief 	 Basic Timer provide Software Timers.
//
//*********************************************************************************************************************
//*********************************************************************************************************************
//
// E X T E R N A L   G L O B A L   C O N S T A N C E   /   V A R I A B L E S   I N   E E P R O M
//
//*********************************************************************************************************************
//! @brief The id for seconds level software timer
enum SEC_TIMER_ID
{
    BTC_SEC_TIMER_1,
    BTC_SEC_TIMER_2,
    BTC_SEC_TIMER_3,
    BTC_SEC_TIMER_TOTAL,
};
//! @brief The id for half seconds level software timer
enum HALF_SEC_TIEMER_ID
{
    BTC_HALF_SEC_TIMER_1,
    BTC_HALF_SEC_TIMER_2,
    BTC_HALF_SEC_TIMER_TOTAL,
};
//! @brief The id for quarter seconds level software timer
enum QUARTER_SEC_TIMER_ID
{
    BTC_QUARTER_SEC_TIMER_1,
    BTC_QUARTER_SEC_TIMER_2,
//  BTC_QUARTER_SEC_TIMER_3,
    BTC_QUARTER_SEC_TIMER_TOTAL,
};
//! @brief define the id of uif module seconds level software timer
#define BTC_UIF_USER_SEC                              BTC_SEC_TIMER_1
//! @brief define the id of uif module seconds level software timer for menu timeout
#define BTC_UIF_MENU_TIMEOUT                          BTC_SEC_TIMER_2
//! @brief define the id of uif module half seconds level software timer
#define BTC_UIF_USER_HALF_SEC                         BTC_HALF_SEC_TIMER_1
//! @brief define the id of uif module quarter seconds level software timer
#define BTC_UIF_USER_QUARTER_SEC                      BTC_QUARTER_SEC_TIMER_1
//! @brief define the id of modbus module quarter seconds level software timer
#define BTC_MODBUS_QUARTER_SEC			      BTC_QUARTER_SEC_TIMER_2
//**********************************************************************************************************************
//
// C O N D I C T I O N   C O M P I L E
//
//*********************************************************************************************************************
//! @brief set it to 1,if we wana using seconds level software timer
#define BTC_USE_SEC_TIMER                             1
//! @brief set it to 1,if we wana using half seconds level software timer
#define BTC_USE_HALF_SEC_TIMER                        1
//! @brief set it to 1,if we wana using quarter seconds level software timer
#define BTC_USE_QUARTER_SEC_TIMER                     1

//! @breif The Variable stand for the timing from start
#define BTC_SYSTEM_COUNTING_TIME                      gl_btc_unit
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S
//
//*********************************************************************************************************************
#include "..\fk\fk_udef.h"
#include "..\modbus_slave\modbus_slave_udef.h"
#include "c_src\btc_init.h"
#include "c_src\btc_glb_vars.h"
#include "c_src\btc_task.h"
//**********************************************************************************************************************
//
// A P I   F O R   O T H E R   M O D U L E S
//
//*********************************************************************************************************************
//! @brief BTC Module Initial API
#define	BTC_INIT_API()				      btc_init()
//! @brief Call this API for setting the seconds level timer counter by timer id.
#define BTC_SET_SEC_CNT_API(id,cnt)                   gb_btc_sec[id]=cnt
//! @brief Get the seconds level timer counter by timer id.
#define BTC_GET_SEC_CNT_API(id)                       gb_btc_sec[id]
//! @brief Call this API for setting the half seconds level timer counter by timer id.
#define BTC_GET_HALF_SEC_CNT_API(id)                  gb_btc_half_sec[id]
//! @brief Get the half seconds level timer counter by timer id.
#define BTC_SET_HALF_CNT_API(id,cnt)                  gb_btc_half_sec[id]=cnt
//! @brief Call this API for setting the quarter seconds level timer counter by timer id.
#define BTC_GET_QUARTER_SEC_CNT_API(id)               gb_btc_quarter_sec[id]
//! @brief Get the quarter seconds level timer counter by timer id.
#define BTC_SET_QUARTER_CNT_API(id,cnt)               gb_btc_quarter_sec[id]=cnt
//! @brief Clear the seconds level timer counter by time id.
#define BTC_CLR_SEC_CNT_API(id)			      gb_btc_sec[id]=0
//! @brief Clear the half-second level timer counter by time id.
#define BTC_CLR_HALF_SEC_CNT_API(id)	    	      gb_btc_half_sec[id]=0
//! @brief Clear the quarter-second level timer counter by time id.
#define BTC_CLR_QUARTER_SEC_CNT_API(id)		      gb_btc_quarter_sec[id]=0
//! @brief BTC task
#define BTC_TASK_API()                                btc_basic_timer_isr()
//**********************************************************************************************************************
//
// A P I   C A L L   F R O M   O T H E R   M O D U L E S
//
//*********************************************************************************************************************
//! @brief Check BTC flag is rasing
#define BTC_CHK_FLAG_API()                            FK_RTC_CHK_ALARM_API()
//! @brief Clear BTC flag
#define BTC_CLR_FLAG_API()                            FK_RTC_CLEAR_ALARM_FLAG_API()
//! @brief as uif action timing is expired,we will raise the flag.
#define BTC_SET_UIF_ACTION_API()                      PFC_SET_UIF_TASK_API()
//! @brief Reset RTC Alarm
#define BTC_RESET_RTC_ALARM_API()                     //RTC_SetAlarm(RTC_GetCounter()+1);RTC_WaitForLastTask()
//! @brief as key action timing is expired,we will raise the flag.
#define BTC_KEY_ACTION_API()                          PFC_SET_KEY_TASK_API()
//! @brief the api for adding system time && date
#define BTC_ADD_SEC_API()                             PFC_ADD_SECOND_API() 
//! @brief The api for setting rtc task with RTC clock
#define BTC_SET_TASK_WITH_RTC_API()                   FK_RTC_ENABLE_API(btc_basic_timer_isr)
//! @brief The api for speed up MCU
#define BTC_SPEED_UP_API()                            FK_SPEED_UP_API()
//**********************************************************************************************************************
//
// F U N C T I O N   P R O T O T Y P E S
//
//*********************************************************************************************************************
#endif		// BTC_UDEF_H 
