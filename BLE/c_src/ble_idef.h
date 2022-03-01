#ifndef BLE_IDEF_H
#define BLE_IDEF_H
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 ble_idef.h
//
//! @author 	        Roger
//
//! @date 		 2021/10
//
//  @brief 		 Here define internal constant
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// E X T E R N A L   G L O B A L   C O N S T A N C E   /   V A R I A B L E S   I N   E E P R O M 
//
//**********************************************************************************************************************
#define BLE_HEADER_START_ADDRESS    				0x1000
#define BLE_NULL_ADDRESS                                       0xffff
#define BLE_HEADER_NUM						32
#define BLE_READONLY_START_ADDRESS				(BLE_HEADER_START_ADDRESS+BLE_HEADER_NUM)
#define BLE_READONLY_NUM					12
#define BLE_READ_WRITE_START_ADDRESS				(BLE_HEADER_START_ADDRESS+BLE_HEADER_NUM+BLE_READONLY_NUM)
#define BLE_READ_WRITE_NUM					30      //william
#define BLE_DDF_START_ADDRESS					(BLE_READ_WRITE_START_ADDRESS+BLE_READ_WRITE_NUM)
#define BLE_DDF_LEN						333
#define BLE_LAST_ADDRESS					(BLE_DDF_START_ADDRESS+BLE_DDF_LEN)
#define BLE_MAX_BUFFER_SIZE					256
#define BLE_MAX_COMMAND					        25
#define BLE_ERROR_CODE_MASK					0x80
#define BLE_BYTE_BITS						8
#define BLE_HIGH_BYTE_MASK					0xff00
#define BLE_LOW_BYTE_MASK					0xff
#define BLE_MAX_REGISTER_ADDRESS				0xffff
#define BLE_ADDRESS_LEN					        1
#define BLE_CRC_LEN						2
#define BLE_CRC_HI_BYTE_POS					1
#define BLE_CRC_LOW_BYTE_POS					2
#define BLE_ASCII_START_CHAR					':'
#define BLE_ASCII_ZERO_CHAR					'0'
#define BLE_ASCII_NINE_CHAR					'9'
#define BLE_ASCII_A_CHAR					'A'
#define BLE_ASCII_F_CHAR					'F'
#define BLE_HEX_0						0x00
#define BLE_HEX_9						0x09
#define BLE_HEX_A						0x0A
#define BLE_HEX_F						0x0F
#define BLE_HEX_TEN						BLE_HEX_A
#define BLE_ASCII_NULL_VALUE					0xff
#define BLE_LOW_FOUR_BITS					0x0f
#define BLE_HIGH_FOUR_BITS					0xf0
#define BLE_HALF_BYTE_BITS					4
#define BLE_CR_CODE						0x0D
#define BLE_LF_CODE						0x0A

enum BLE_SUPPORTED_CMD
{
    BLE_SUPPORTED_CMD_NO,
    BLE_SUPPORTED_CMD_YES,
};

enum BLE_BYTE_NAME
{
    BLE_BYTE_NAME_ADDRESS,
    BLE_BYTE_NAME_FUNCTION_BYTE,
};

enum BLE_STATE
{
    BLE_STATE_STOP,
    BLE_STATE_RECEIVING_AND_CHECKING,
    BLE_STATE_ACTION,
    BLE_STATE_RESPONSE,
    BLE_STATE_SENDING,
    BLE_STATE_BACK_TO_STOP,
};

enum BLE_EXCEPTION_CODE
{
    BLE_EXECETION_CODE_NONE,
    BLE_EXCEPTION_CODE_ILLEGAL_FUNCTION,
    BLE_EXCEPTION_CODE_ILLEGAL_DATA_ADDRESS,
    BLE_EXCEPTION_CODE_ILLEGAL_DATA_VALUE,
    BLE_EXCEPTION_CODE_SLAVE_DEVICE_FAILURE,
    BLE_EXCEPTION_CODE_ACKNOWLEDGE,
    BLE_EXCEPTION_CODE_SLAVE_DEVICE_BUSY,
    BLE_EXCEPTION_CODE_MEMORY_PARITY_ERROR,
    BLE_EXCEPTION_CODE_GATEWAY_PATH_UNAVAILABLE,
    BLE_EXCEPTION_CODE_GETEWAY_TARGET_DEVICE_FAILED_TO_RESPOND,
};


#endif		// BLE_IDEF_H 
