//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 ble_init.c
//
//! @author 	 Roger
//
//! @date 		 2021/10
//
//  @brief 		 Initial Subroutine
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S 
//
//**********************************************************************************************************************
#include "..\drv_src\ble_drv.h" 
#include "ble_glb_vars.h"
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 ble_init
//
//! @author 	 Roger
//
//! @date 		 2021/10
//
//! @brief 		 initial function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void ble_init()
{
      #if MAIN_USE_BLE == 1
            switch (BLE_BAUDRATE)
            {
                  case 1200:
                        gb_ble_reset_value=32;
                  break;
                  case 2400:
                        gb_ble_reset_value=16;
                  break;
                  case 4800:
                        gb_ble_reset_value=8;
                  break;
                  case 9600:
                        gb_ble_reset_value=4;
                  break;
                  case 38400:
                  case 57600:
                  case 19200:
                        gb_ble_reset_value=3;
                  break;
            }
      #endif   
	ble_sfr_init();
	ble_glb_vars_init();
}
