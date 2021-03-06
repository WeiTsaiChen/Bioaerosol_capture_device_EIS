#ifndef AD5941_GLB_VARS_H
#define AD5941_GLB_VARS_H
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 ad5941_glb_vars.h
//
//! @author 	 Roger
//
//! @date 		 2021/10
//
//  @brief 		 Here declare globe variable
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S 
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// E X T E R N A L   V A R I A B L E   A L L O C 
//
//**********************************************************************************************************************
#ifdef AD5941_ALLOC
	#define EXTERNAL
#else
	#define EXTERNAL extern
#endif
//**********************************************************************************************************************
//
// D E C L A R E   G L O B E   V A R I A B L E 
//
//**********************************************************************************************************************

//**********************************************************************************************************************
//
// F U N C T I O N   P R O T O T Y P E S 
//
//**********************************************************************************************************************
void ad5941_glb_vars_init();
#undef EXTERNAL
#endif		// AD5941_GLB_VARS_H 
