#ifndef BLE_GLB_VARS_H
#define BLE_GLB_VARS_H
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 ble_glb_vars.h
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
#include "ble_idef.h"
#include "..\ble_udef.h"
//**********************************************************************************************************************
//
// E X T E R N A L   V A R I A B L E   A L L O C 
//
//**********************************************************************************************************************
#ifdef BLE_ALLOC
	#define EXTERNAL
#else
	#define EXTERNAL extern
#endif

typedef struct
{
    UINT8	id_code;
    UINT16	max_register;
    UINT16      max_value;
    UINT8	return_byte_cnt;
    UINT8       command_length;
    void        (*action)();
    UINT8       supported;
} STC_BLE_COMMAND_INFO;

typedef struct
{
    UINT8       device_id;
    UINT8	function_code;
    UINT8	register_address_h;
    UINT8	register_address_l;
    UINT8	register_value_h;
    UINT8	register_value_l;
    UINT16	crc_check;
} STC_BLE_READ_WRITE_REGISTER_PACKAGE;

typedef struct
{
    UINT8       device_id;
    UINT8	function_code;
    UINT8	register_address_h;
    UINT8	register_address_l;
    UINT8	register_value_h;
    UINT8	register_value_l;
    UINT8       byte_count;
    UINT8	data;
} STC_BLE_WRITE_MULTI_REGISTER_CMD_PACKAGE;

typedef struct
{
    UINT8       device_id;
    UINT8	function_code;
    UINT8	register_address_h;
    UINT8	register_address_l;
    UINT8	byte_count_h;
    UINT8	byte_count_l;
    UINT16      crc_check;
} STC_BLE_WRITE_MULTI_REGISTER_RESPONSE_PACKAGE;

typedef struct
{
    UINT8	device_address;
    UINT8	function_code;
    UINT8	byte_count;
    UINT8       data;
} STC_BLE_RESPONSE_READ_HOLDING_REGISTER_PACKAGE;
typedef struct
{
    UINT8       device_address;
    UINT8	error_code;
    UINT8	exception_code;
    UINT16      crc_check;
} STC_BLE_ERROR_PACKAGE;
#define BLE_ERROR_PACKAGE_LEN			5
//**********************************************************************************************************************
//
// D E C L A R E   G L O B E   V A R I A B L E 
//
//**********************************************************************************************************************
EXTERNAL UINT8 					gb_ble_buffer[BLE_MAX_BUFFER_SIZE];
EXTERNAL UINT16					gb_ble_ptr;
EXTERNAL UINT16					gb_ble_response_length;
EXTERNAL STC_BLE_COMMAND_INFO*		        gs_ble_package_ptr;
EXTERNAL STC_BLE_ERROR_PACKAGE		        gs_ble_error_package;
extern const STC_BLE_COMMAND_INFO 	        gt_ble_valid_function[BLE_MAX_COMMAND];
extern const UINT16*                            gt_ble_read_write[BLE_READ_WRITE_NUM];
extern const UINT16*                            gt_ble_readonly[BLE_READONLY_NUM];
extern const UINT16*                            gt_ble_header[BLE_HEADER_NUM];
extern const UINT16                             gt_ble_ddf_file[BLE_DDF_LEN];
EXTERNAL UINT8                                  gb_ble_reset_value;
EXTERNAL UINT8		                        gb_ble_state;
EXTERNAL UINT16					gb_ble_char_ptr;
//**********************************************************************************************************************
//
// F U N C T I O N   P R O T O T Y P E S 
//
//**********************************************************************************************************************
void ble_glb_vars_init();
#undef EXTERNAL
#endif		// BLE_GLB_VARS_H 
