#ifndef PFC_GLB_VARS_H
#define PFC_GLB_VARS_H
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 	 pfc_glb_vars.h
//
//! @author	 Willman Chen
//
//! @date 	 2009/06/19
//
// @brief 	 Here declare globe variable
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S
//
//**********************************************************************************************************************
#include "pfc_idef.h"
#include "..\pfc_udef.h"
//**********************************************************************************************************************
//
// E X T E R N A L   V A R I A B L E   A L L O C
//
//**********************************************************************************************************************
#ifdef PFC_ALLOC
#define EXTERNAL
#else
#define EXTERNAL extern
#endif

typedef struct
{
    UINT16    modbus_id;
    UINT16    modbus_baudrate;
    UINT16    modbus_bits:4;
    UINT16    modbus_stop_bits:2;
    UINT16    modbus_parity:2;
    UINT16    modbus_mode:1;
    UINT16    modbus_change:1;
    UINT16    null:6;
} STC_PFC_MODBUS_SETTING;

typedef struct
{
    UINT16   save_system_var_to_eeprom;
    UINT16   save_calibration_setting;
    UINT16   load_default_setting;
    UINT16   load_firmware_setting;
} STC_PFC_SETTING_FLAG;

typedef struct
{
    UINT8    second;
    UINT8    minute;
    UINT8    hour;
    UINT8    day;
    UINT8    month;
    UINT8    year;   // start from 1900
} STC_PFC_CALANDAR_STATUS;

typedef struct
{
    UINT16                   fan_task:1;
    UINT16                   air_pump_task:1;
    UINT16                   water_pump_task:1; 
    UINT16                   ad5941_task:1;     
    UINT16                   null:12;
    FLOAT32                  display_value;             //  display_value
    FLOAT32                  display_percentage;
    FLOAT32                  temperature;
    UINT16                   fan_ctrl;
    UINT16                   air_ctrl;
    UINT16                   water_ctrl;
    UINT32                   adiid;
    UINT32                   chip_id;
    UINT16                   ad5941_measurement_ctrl;   // AD5941 Measurement event
    UINT16                   tx_buffer_int1;
    UINT16                   tx_buffer_decimal1;
    UINT16                   tx_buffer_int2;
    UINT16                   tx_buffer_decimal2;
    UINT16                   tx_buffer_int3;
    UINT16                   tx_buffer_decimal3;
} STC_PFC_STATUS;

typedef struct
{
    UINT16   product_type;
    UINT16   product_number;
    UINT16   product_version;
} STC_PFC_AUTO_ID;

typedef struct
{
    UINT16   modbus:1;
    UINT16   hart:1;
    UINT16   profibus:1;
    UINT16   zigbee:1;
    UINT16   hart_wireless:1;
    UINT16   reserved:11;
} STC_PFC_COMMUCATION_INTERFACE;

//! @brief The System variables struct
typedef struct
{
    STC_PFC_COMMUCATION_INTERFACE  communcation_setting;
    STC_PFC_SETTING_FLAG           setting_flag;
    STC_PFC_MODBUS_SETTING         modbus_setting;
    STC_PFC_MODBUS_SETTING         ble_setting;
    STC_PFC_CALANDAR_STATUS        calendar;
    FLOAT32                        display_high;
    FLOAT32                        display_low;
    FLOAT32                        display_high_limit;
    FLOAT32                        display_low_limit;
    FLOAT32                        display_span;
    UINT32                         serial_number;
    UINT16                         zero_chksum;      //  the zero checksum,please always place this variable at the last one in this structure.
} STC_SYSTEM_INFO;
//**********************************************************************************************************************
//
// D E C L A R E   G L O B E   V A R I A B L E
//
//**********************************************************************************************************************
//! @brief The System status flag
EXTERNAL STC_PFC_STATUS             	gs_pfc_status;
//! @brief The System Variables
EXTERNAL STC_SYSTEM_INFO            	gs_pfc_vars;
//! @brief The System Product Information
extern STC_PFC_AUTO_ID                  gs_pfc_auto_id;
extern const UINT8                      gt_pfc_days_of_month[12];
//**********************************************************************************************************************
//
// F U N C T I O N   P R O T O T Y P E S
//
//**********************************************************************************************************************
void pfc_glb_vars_init();
void pfc_glb_vars_load_default();
#undef EXTERNAL
#endif		// PFC_GLB_VARS_H 
