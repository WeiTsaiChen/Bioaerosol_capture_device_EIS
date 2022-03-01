#ifndef BLE_TASK_H
#define BLE_TASK_H
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 ble_task.h
//
//! @author 	 Roger
//
//! @date 		 2021/10
//
//  @brief 		 Here declare task function
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S 
//
//**********************************************************************************************************************
#include "..\ble_udef.h"
//**********************************************************************************************************************
//
// M A C R O   D E F I N I T I O N 
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// F U N C T I O N   P R O T O T Y P E S 
//
//**********************************************************************************************************************
UINT8 ble_sending();
void ble_write_multi_register();
void ble_write_single_register();
void ble_read_input_registers();
void ble_receiving_and_checking();
void ble_null_func();
void ble_timeout_isr(void);
#if MAIN_LOW_POWER_MODE == 1
void ble_disable_rx();
#endif
UINT16* ble_get_variable_pointer(UINT16 register_addr);
UINT8 ble_write_variable_value(UINT16 register_addr,UINT16 value);

#endif		// BLE_TASK_H 
