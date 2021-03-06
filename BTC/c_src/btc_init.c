//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 	 btc_init.c
//
//! @author	 Willman Chen
//
//! @date 	 2009/06/22
//
//  @brief 	 Initial Subroutine
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S
//
//**********************************************************************************************************************
#include "..\drv_src\btc_drv.h"
#include "btc_glb_vars.h"
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 		 btc_init
//
//! @author 	 Willman Chen
//
//! @date 	     2009/06/22
//
//! @brief 	     initial function
//
//**********************************************************************************************************************
void btc_init()
{
    btc_sfr_init();
    btc_glb_vars_init();
    BTC_SET_TASK_WITH_RTC_API();
}
