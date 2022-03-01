#ifndef BLE_UDEF_H
#define BLE_UDEF_H
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 ble_udef.h
//
//! @author 	 Roger
//
//! @date 		 2021/10
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
#define BLE_ID							       PFC_BLE_ID
#define BLE_BAUDRATE                                                   PFC_BLE_BAUDRATE
#define BLE_BITS                                                       PFC_BLE_BTIS
#define BLE_PARITY                                                     PFC_BLE_PARITY
#define BLE_MODE                                                       PFC_BLE_MODE
#define BLE_ASCII_MODE						       FK_MODBUS_ASCII_MODE
#define BLE_RTU_MODE						       FK_MODBUS_RTU_MODE
#define BLE_READONLY_REMAP_ADDRESS                                     BLE_READONLY_START_ADDRESS
#define BLE_READWRITE_REMAP_ADDRESS                                    BLE_READ_WRITE_START_ADDRESS
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
#include "c_src\ble_init.h"
#include "c_src\ble_glb_vars.h"
#include "c_src\ble_task.h"
//**********************************************************************************************************************
//
// A P I   F O R   O T H E R   M O D U L E S 
//
//**********************************************************************************************************************
//! @brief The API for initilizating ModBus module
#define	BLE_INIT_API()								ble_init()
//! @brief The API for receving task
#define BLE_RECEIVING_AND_CHECKING_API()				        ble_receiving_and_checking()
//! @brief The API for sending task
#define BLE_SENDING_API()						        ble_sending()
//! @brief The API for timeout task
#define BLE_TASK_API()                                                          ble_timeout_isr()
//! @brief The API for getting variable pointer
#define BLE_GET_VARIABLE_VALUE_API(address)                                     *(ble_get_variable_pointer(address))
//! @brief The API for writing variable value
#define BLE_WRITE_VARIABLE_VALUE_API(address,value)                             ble_write_variable_value(address,value)

#if MAIN_LOW_POWER_MODE == 1
//! @brief The API for enabling rx interrupt
#define BLE_RX_INTERRUPT_ENABLE_API()                                           FK_SET_FALLING_INTERRUPT_PIN_API(FK_PORTB,FK_PIN10,ble_disable_rx)
//! @brief The API for disabling rx interrupt
#define BLE_RX_INTERRUPT_DISABLE_API()                                          FK_SET_DISABLE_INTERRUPT_PIN_API(FK_PORTB,FK_PIN10)
//! @brief The API for disabling UART interrupt
#define BLE_UART_DISABLE_API()                                                  FK_UART3_TX_INTERRUPT_DISABLE_API()
#endif
//**********************************************************************************************************************
//
// A P I   C A L L   F R O M   O T H E R   M O D U L E S 
//
//**********************************************************************************************************************
//! @brief The API for initial UART function
#define BLE_UART_INIT_API(baudrate,bits,stop_bits,parity)                       FK_UART3_REMAP_INTERRUPT_API(baudrate,bits,stop_bits,parity,ble_sending,ble_receiving_and_checking)
//! @brief The API for sending out data
#define BLE_SEND_OUT_API(data)						        FK_UART3_REMAP_SEND_BYTE_API(data)
//! @brief The API for receiving data
#define BLE_RECEIVE_API()						        FK_UART3_GET_DATA_API()
//! @brief The API for keeping MCU don't fall into sleep
#define BLE_UART_HIGH_SPEED_API()                                               FK_UART3_HIGH_SPEED_API()
//! @brief The API for cancel MCU don't fall into sleep
#define BLE_UART_LOW_SPEED_API()                                                FK_UART3_LOW_SPEED_API()
//! @brief The API for computing CRC code
#define BLE_CRC_CODE_API(data,len)					        CRC_GENERATE_API(data,len)
//! @brief The API for setting waitting for reading in
#define BLE_SET_READ_IN_API()						        FK_SET_OUTPUT_PIN_LOW_API(FK_PORTB,FK_PIN9)
//! @brief The API for setting write out
#define BLE_SET_WRITE_OUT_API()					                FK_SET_OUTPUT_PIN_HIGH_API(FK_PORTB,FK_PIN9)
//! @brief The API for starting UART1 transfer interrupt
#define BLE_START_TX_API()                                                      FK_UART3_TX_INTERRUPT_ENABLE_API()
//! @brief The API for reset timeout timer
#define BLE_RESET_TIMEOUT_TIMER_API()					        HBTC_SET_TIMER_API(HBTC_BLE_TIMER,gb_ble_reset_value,ble_timeout_isr)
//! @brief The API for speeding up MCU
#define BLE_SPEED_UP_API()                                                      FK_SPEED_UP_API()
//**********************************************************************************************************************
//
// F U N C T I O N   P R O T O T Y P E S 
//
//**********************************************************************************************************************
#endif		// BLE_UDEF_H 
