//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 ble_drv.c
//
//! @author 	 Roger
//
//! @date 		 2021/10
//
//  @brief 		 Driver Subroutine
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S 
//
//**********************************************************************************************************************
#include "ble_drv.h" 
#include "..\ble_udef.h"
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 ble_sfr_init
//
//! @author 	 Roger
//
//! @date 		 2021/10
//
//! @brief 		 Register initial function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void ble_sfr_init()
{
      #if MAIN_USE_BLE == 1  
            FK_SET_PIN_OUPUT_PUSH_PUMP_API(FK_PORTB,FK_PIN9);
            BLE_DIRECTION_INIT();
            BLE_SET_READ_IN_API();
            //BLE_RX_INTERRUPT_ENABLE_API();
            BLE_RESET_TIMEOUT_TIMER_API();
            BLE_UART_LOW_SPEED_API();
      #if MAIN_LOW_POWER_MODE == 1
            BLE_RX_INTERRUPT_ENABLE_API();
      #else
            BLE_UART_INIT_API(BLE_BAUDRATE,BLE_BITS,PFC_MODBUS_STOP_BITS,BLE_PARITY);
      #endif  
      #endif       
}
