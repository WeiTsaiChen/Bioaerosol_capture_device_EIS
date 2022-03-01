//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 	 btc_glb_vars.c
//
//! @author 	 Willman Chen
//
//! @date 	 2009/06/22
//
//  @brief 	 Init globe variable
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S
//
//**********************************************************************************************************************
#define BTC_ALLOC
#include "btc_glb_vars.h"
#undef BTC_ALLOC
#include "..\btc_udef.h"
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 		 btc_glb_vars_init
//
//! @author 	 Willman Chen
//
//! @date 	     2009/06/22
//
//! @brief 	     task function
//
//**********************************************************************************************************************
void btc_glb_vars_init()
{
#if BTC_USE_QUARTER_SEC_TIMER == 1 || BTC_USE_HALF_SEC_TIMER == 1 || BTC_USE_SEC_TIMER==1
    UINT8 i;
#endif
    gl_btc_unit=0;
#if BTC_USE_QUARTER_SEC_TIMER == 1                     // Reset all timer counter
    for (i=0; i<BTC_HALF_SEC_TIMER_TOTAL; i++)
        gb_btc_quarter_sec[i]=0x00;
#endif
#if BTC_USE_HALF_SEC_TIMER == 1
    for (i=0; i<BTC_HALF_SEC_TIMER_TOTAL; i++)
        gb_btc_half_sec[i]=0x00;
#endif
#if BTC_USE_SEC_TIMER == 1
    for (i=0; i<BTC_SEC_TIMER_TOTAL; i++)
        gb_btc_sec[i]=0x00;
#endif
}
