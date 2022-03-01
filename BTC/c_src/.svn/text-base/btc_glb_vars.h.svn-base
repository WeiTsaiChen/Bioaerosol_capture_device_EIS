#ifndef BTC_GLB_VARS_H
#define BTC_GLB_VARS_H
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 	 btc_glb_vars.h
//
//! @author 	 Willman Chen
//
//! @date 	 2009/06/22
//
//  @brief 	 Here declare globe variable
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S
//
//**********************************************************************************************************************
#include "..\btc_udef.h"
//**********************************************************************************************************************
//
// E X T E R N A L   V A R I A B L E   A L L O C
//
//**********************************************************************************************************************
#ifdef BTC_ALLOC
#define EXTERNAL
#else
#define EXTERNAL extern
#endif
//**********************************************************************************************************************
//
// D E C L A R E   G L O B E   V A R I A B L E
//
//**********************************************************************************************************************
EXTERNAL  UINT32   gl_btc_unit;                                         // Unit time counter for internal counting.
#if BTC_USE_SEC_TIMER == 1
EXTERNAL  UINT32   gb_btc_sec[BTC_SEC_TIMER_TOTAL];                    // Software Counter every second.
#endif
#if BTC_USE_HALF_SEC_TIMER == 1
EXTERNAL  UINT32   gb_btc_half_sec[BTC_HALF_SEC_TIMER_TOTAL];          // Software Counter every 0.5 second.
#endif
#if BTC_USE_QUARTER_SEC_TIMER == 1
EXTERNAL  UINT32   gb_btc_quarter_sec[BTC_QUARTER_SEC_TIMER_TOTAL];    // Software Counter every 0.25 second.
#endif
//**********************************************************************************************************************
//
// F U N C T I O N   P R O T O T Y P E S
//
//**********************************************************************************************************************
void btc_glb_vars_init();
#undef EXTERNAL
#endif		// BTC_GLB_VARS_H 
