//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 	 btc_task.c
//
//! @author      Willman Chen
//
//! @date 	 2009/06/22
//
// @brief 	 Task Subroutine
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S
//
//**********************************************************************************************************************
#include "..\drv_src\btc_drv.h"
#include "btc_glb_vars.h"
#include "btc_idef.h"
#include "..\btc_udef.h"
#include "btc_task.h"
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 btc_basic_timer_isr
//
//! @author  Willman Chen
//
//! @date 	 2009/06/22
//
//! @brief 	 The Basic Timer Module Interrupt Service Rountine.
//
//**********************************************************************************************************************
void btc_basic_timer_isr(void)
{
#if BTC_USE_QUARTER_SEC_TIMER == 1 || BTC_USE_HALF_SEC_TIMER == 1 || BTC_USE_SEC_TIMER==1
    UINT8 i;
#endif
    BTC_SPEED_UP_API();
    BTC_RESET_RTC_ALARM_API();
    gl_btc_unit++;


#if BTC_USE_QUARTER_SEC_TIMER == 1                      // checking for quarter software timer
#if BTC_QUARTER_UINT > 1
    if (!(gl_btc_unit%BTC_QUARTER_UINT))
#endif
    {
        for (i=0; i<BTC_QUARTER_SEC_TIMER_TOTAL; i++)
        {
            if (gb_btc_quarter_sec[i])
            {
                gb_btc_quarter_sec[i]--;
            }
        }
    }
#endif


#if BTC_USE_HALF_SEC_TIMER == 1                         // checking for half second software timer
    if (!(gl_btc_unit%BTC_HALF_UNIT))
    {
        for (i=0; i<BTC_HALF_SEC_TIMER_TOTAL; i++)
        {
            if (gb_btc_half_sec[i])
            {
                gb_btc_half_sec[i]--;
            }
        }
    }
#endif
#if BTC_USE_SEC_TIMER == 1                              // checking for second software timer
    if (!(gl_btc_unit%BTC_SEC_UNIT))
    {
        BTC_ADD_SEC_API();
        for (i=0; i<BTC_SEC_TIMER_TOTAL; i++)
        {
            if (gb_btc_sec[i])
            {
                gb_btc_sec[i]--;
            }
        }
    }
#endif
}
