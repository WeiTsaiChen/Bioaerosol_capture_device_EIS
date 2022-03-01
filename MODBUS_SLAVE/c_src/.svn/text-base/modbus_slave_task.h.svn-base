#ifndef MODBUS_SLAVE_TASK_H
#define MODBUS_SLAVE_TASK_H
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 modbus_slave_task.h
//
//! @author 	 Willman Chen
//
//! @date 		 2009/11/10
//
//  @brief 		 Here declare task function
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S
//
//**********************************************************************************************************************
#include "..\modbus_slave_udef.h"
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
UINT8 modbus_slave_sending();
void modbus_slave_write_multi_register();
void modbus_slave_write_single_register();
void modbus_slave_read_input_registers();
void modbus_slave_receiving_and_checking();
void modbus_slave_null_func();
void modbus_slave_timeout_isr(void);
#if MAIN_LOW_POWER_MODE == 1
void modbus_slave_disable_rx();
#endif
UINT16* modbus_slave_get_variable_pointer(UINT16 register_addr);
UINT8 modbus_slave_write_variable_value(UINT16 register_addr,UINT16 value);
#endif		// MODBUS_SLAVE_TASK_H 
