//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 hbtc_init.c
//
//! @author 	 Willman Chen
//
//! @date 		 2010/12/27
//
//  @brief 		 Initial Subroutine
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S 
//
//**********************************************************************************************************************
#include "..\drv_src\hbtc_drv.h" 
#include "hbtc_glb_vars.h"
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
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 hbtc_init
//
//! @author 	 Willman Chen
//
//! @date 		 2010/12/27
//
//! @brief 		 initial function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void hbtc_init()
{
	hbtc_sfr_init();
	hbtc_glb_vars_init();
}
//**********************************************************************************************************************
//
// C   P L U S   P L U S   C O M P A T I A B L E   D E F I N I T I O N 
//
//**********************************************************************************************************************
#ifdef __cplusplus
}
#endif

