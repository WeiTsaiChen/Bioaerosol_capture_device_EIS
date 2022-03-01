#ifndef MODBUS_SLAVE_UDEF_H
#define MODBUS_SLAVE_UDEF_H
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 modbus_slave_udef.h
//
//! @author 	 Willman Chen
//
//! @date 		 2009/11/10
//
//  @brief 		 Here define all API
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// E X T E R N A L   G L O B A L   C O N S T A N C E   /   V A R I A B L E S   I N   E E P R O M
//
//**********************************************************************************************************************
// TIME OUT range : 3.5 chars <= timeout <= 4.0 chars
#define MODBUS_SLAVE_ID							        PFC_MODBUS_ID
#define MODBUS_SLAVE_BAUDRATE                                                   PFC_MODBUS_BAUDRATE
#define MODBUS_SLAVE_BITS                                                       PFC_MODBUS_BTIS
#define MODBUS_SLAVE_PARITY                                                     PFC_MODBUS_PARITY
#define MODBUS_SLAVE_MODE                                                       PFC_MODBUS_MODE
#define MODBUS_SLAVE_ASCII_MODE							FK_MODBUS_ASCII_MODE
#define MODBUS_SLAVE_RTU_MODE							FK_MODBUS_RTU_MODE
#define MODBUS_SLAVE_READONLY_REMAP_ADDRESS                                     MODBUS_SLAVE_READONLY_START_ADDRESS
#define MODBUS_SLAVE_READWRITE_REMAP_ADDRESS                                    MODBUS_SLAVE_READ_WRITE_START_ADDRESS
//**********************************************************************************************************************
//
// C O N D I C T I O N   C O M P I L E
//
//**********************************************************************************************************************

//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S
//
//**********************************************************************************************************************
#include "..\fk\fk_udef.h"
#include "..\crc\crc_udef.h"
#include "..\hbtc\hbtc_udef.h"
#include "..\pfc\pfc_udef.h"
#include "..\main.h"
#include "c_src\modbus_slave_init.h"
#include "c_src\modbus_slave_glb_vars.h"
#include "c_src\modbus_slave_task.h"
//**********************************************************************************************************************
//
// A P I   F O R   O T H E R   M O D U L E S
//
//**********************************************************************************************************************
//! @brief The API for initilizating ModBus module
#define	MODBUS_SLAVE_INIT_API()                                                 modbus_slave_init()
//! @brief The API for receving task
#define MODBUS_SLAVE_RECEIVING_AND_CHECKING_API()				modbus_slave_receiving_and_checking()
//! @brief The API for sending task
#define MODBUS_SLAVE_SENDING_API()						modbus_slave_sending()
//! @brief The API for timeout task
#define MODBUS_SLAVE_TASK_API()                                                 modbus_slave_timeout_isr()
//! @brief The API for getting variable pointer
#define MODBUS_SLAVE_GET_VARIABLE_VALUE_API(address)                            *(modbus_slave_get_variable_pointer(address))
//! @brief The API for writing variable value
#define MODBUS_SLAVE_WRITE_VARIABLE_VALUE_API(address,value)                    modbus_slave_write_variable_value(address,value)

#if MAIN_LOW_POWER_MODE == 1
//! @brief The API for enabling rx interrupt
#define MODBUS_SLAVE_RX_INTERRUPT_ENABLE_API()                                  FK_SET_FALLING_INTERRUPT_PIN_API(FK_PORTA,FK_PIN3,modbus_slave_disable_rx)
//! @brief The API for disabling rx interrupt
#define MODBUS_SLAVE_RX_INTERRUPT_DISABLE_API()                                 FK_SET_DISABLE_INTERRUPT_PIN_API(FK_PORTA,FK_PIN3)
//! @brief The API for disabling UART interrupt
#define MODBUS_SLAVE_UART_DISABLE_API()                                         FK_UART2_TX_INTERRUPT_DISABLE_API()
#endif
//**********************************************************************************************************************
//
// A P I   C A L L   F R O M   O T H E R   M O D U L E S
//
//**********************************************************************************************************************
//! @brief The API for initial UART function
#define MODBUS_UART_INIT_API(baudrate,bits,stop_bits,parity)                    FK_UART2_REMAP_INTERRUPT_API(baudrate,bits,stop_bits,parity,modbus_slave_sending,modbus_slave_receiving_and_checking)
//! @brief The API for sending out data
#define MODBUS_SLAVE_SEND_OUT_API(data)						FK_UART2_REMAP_SEND_BYTE_API(data)
//! @brief The API for receiving data
#define MODBUS_SLAVE_RECEIVE_API()						FK_UART2_GET_DATA_API()
//! @brief The API for keeping MCU don't fall into sleep
#define MODBUS_SLAVE_UART_HIGH_SPEED_API()                                      FK_UART2_HIGH_SPEED_API()
//! @brief The API for cancel MCU don't fall into sleep
#define MODBUS_SLAVE_UART_LOW_SPEED_API()                                       FK_UART2_LOW_SPEED_API()
//! @brief The API for computing CRC code
#define MODBUS_SLAVE_CRC_CODE_API(data,len)					CRC_GENERATE_API(data,len)
//! @brief The API for setting waitting for reading in
#define MODBUS_SLAVE_SET_READ_IN_API()						FK_SET_OUTPUT_PIN_LOW_API(FK_PORTA,FK_PIN1)
//! @brief The API for setting write out
#define MODBUS_SLAVE_SET_WRITE_OUT_API()					FK_SET_OUTPUT_PIN_HIGH_API(FK_PORTA,FK_PIN1)
//! @brief The API for starting UART1 transfer interrupt
#define MODBUS_SLAVE_START_TX_API()                                             FK_UART2_TX_INTERRUPT_ENABLE_API()
//! @brief The API for reset timeout timer
#define MODBUS_SLAVE_RESET_TIMEOUT_TIMER_API()					HBTC_SET_TIMER_API(HBTC_MODBUS_TIMER,gb_modbus_slave_reset_value,modbus_slave_timeout_isr)
//! @brief The API for speeding up MCU
#define MODBUS_SLAVE_SPEED_UP_API()                                             FK_SPEED_UP_API()
//**********************************************************************************************************************
//
// F U N C T I O N   P R O T O T Y P E S
//
//**********************************************************************************************************************
#endif		// MODBUS_SLAVE_UDEF_H 
