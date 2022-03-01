#ifndef PFC_UDEF_H
#define PFC_UDEF_H
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 	 pfc_udef.h
//
//! @author 	 Willman Chen
//
//! @date 	 2009/06/19
//
// @brief 	 Here define all API
//
//**********************************************************************************************************************
#define PFC_TAG_ASCII                    "FINE-TEK"
#define PFC_DESCRIPTOR_ASCII             "EB5-ADMITTANCE"
#define PFC_MESSAGE_ASCII                "RF ADMITTANCE LEVEL SENSOR      "
#define PFC_LONG_ASCII                   "Taipei County,Taiwan,R.O.C.      "
#define PFC_UNIVERAL_PASSWORD            2123
//**********************************************************************************************************************
//
// E X T E R N A L   G L O B A L   C O N S T A N C E   /   V A R I A B L E S   I N   E E P R O M
//
//**********************************************************************************************************************

//***************************************************************
//   STRUCT AUTO ID                                              
//   This is the auto id data                                    
//===============================================================
#define PFC_PRODUCT_TYPE                  gs_pfc_auto_id.product_type
#define PFC_PRODUCT_NUMBER                gs_pfc_auto_id.product_number
#define PFC_PRODUCT_VERSION               gs_pfc_auto_id.product_version
#define PFC_SAVE_CALIBRATION_SETTING      gs_pfc_vars.setting_flag.save_calibration_setting
#define PFC_LOAD_DEFAULT_SETTING          gs_pfc_vars.setting_flag.load_default_setting
#define	PFC_SAVE_SYSTEM_VAR_TO_EEPROM     gs_pfc_vars.setting_flag.save_system_var_to_eeprom
#define	PFC_LOAD_FIRMWARE_SETTING	  gs_pfc_vars.setting_flag.load_firmware_setting

//================== STRUCT COMMUNICATION SETTING ==================
#define PFC_USE_MODBUS                    gs_pfc_vars.communcation_setting.modbus
#define PFC_USE_HART                      gs_pfc_vars.communcation_setting.hart
#define PFC_USE_PROFIBUS                  gs_pfc_vars.communcation_setting.profibus
#define PFC_USE_ZIGBEE                    gs_pfc_vars.communcation_setting.zigbee
#define PFC_USE_HART_WIRELESS             gs_pfc_vars.communcation_setting.hart_wireless

//================== STRUCT CALANDAR SETTING    ==================
#define PFC_SEC                           gs_pfc_vars.calendar.second
#define PFC_MIN                           gs_pfc_vars.calendar.minute
#define PFC_HOUR                          gs_pfc_vars.calendar.hour
#define PFC_DAY                           gs_pfc_vars.calendar.day
#define PFC_MONTH                         gs_pfc_vars.calendar.month
#define PFC_YEAR                          gs_pfc_vars.calendar.year   // start from 1900
//================== STRUCT MODBUS SETTING    ==================
#define PFC_MODBUS_ID                     gs_pfc_vars.modbus_setting.modbus_id
#define PFC_MODBUS_BAUDRATE               gs_pfc_vars.modbus_setting.modbus_baudrate
#define PFC_MODBUS_BTIS                   gs_pfc_vars.modbus_setting.modbus_bits
#define PFC_MODBUS_STOP_BITS              gs_pfc_vars.modbus_setting.modbus_stop_bits
#define PFC_MODBUS_PARITY                 gs_pfc_vars.modbus_setting.modbus_parity
#define PFC_MODBUS_MODE                   gs_pfc_vars.modbus_setting.modbus_mode
//================== STRUCT BLE SETTING    ==================
#define PFC_BLE_ID                        gs_pfc_vars.ble_setting.modbus_id
#define PFC_BLE_BAUDRATE                  gs_pfc_vars.ble_setting.modbus_baudrate
#define PFC_BLE_BTIS                      gs_pfc_vars.ble_setting.modbus_bits
#define PFC_BLE_STOP_BITS                 gs_pfc_vars.ble_setting.modbus_stop_bits
#define PFC_BLE_PARITY                    gs_pfc_vars.ble_setting.modbus_parity
#define PFC_BLE_MODE                      gs_pfc_vars.ble_setting.modbus_mode

#define PFC_TEMPERATURE                   gs_pfc_status.temperature
#define PFC_DISPLAY_VALUE                 gs_pfc_status.display_value
#define PFC_DISPLAY_PERCENTAGE            gs_pfc_status.display_percentage

#define PFC_FAN_CTRL                      gs_pfc_status.fan_ctrl
#define PFC_AIR_PUMP_CTRL                 gs_pfc_status.air_ctrl
#define PFC_WATER_PUMP_CTRL               gs_pfc_status.water_ctrl
#define PFC_ADI_ID                        gs_pfc_status.adiid
#define PFC_CHIP_ID                       gs_pfc_status.chip_id

/* AD5941 Measurement event */
#define PFC_AD5941_MEASUREMENT_CTRL       gs_pfc_status.ad5941_measurement_ctrl

/* Impedance mode parameters */
#define PFC_AD5941_IMPEDANCE_FREQ_INT     gs_pfc_status.tx_buffer_int1
#define PFC_AD5941_IMPEDANCE_FREQ_DECI    gs_pfc_status.tx_buffer_decimal1
#define PFC_AD5941_IMPEDANCE_MAG_INT      gs_pfc_status.tx_buffer_int2
#define PFC_AD5941_IMPEDANCE_MAG_DECI     gs_pfc_status.tx_buffer_decimal2
#define PFC_AD5941_IMPEDANCE_PHASE_INT    gs_pfc_status.tx_buffer_int3
#define PFC_AD5941_IMPEDANCE_PHASE_DECI   gs_pfc_status.tx_buffer_decimal3

/* Ramp (include CV, SWV, DPV etc.) mode parameters */
#define PFC_AD5941_RAMP_VOL_INT           gs_pfc_status.tx_buffer_int1
#define PFC_AD5941_RAMP_VOL_DECI          gs_pfc_status.tx_buffer_decimal1
#define PFC_AD5941_RAMP_CURRENT_INT       gs_pfc_status.tx_buffer_int2
#define PFC_AD5941_RAMP_CURRENT_DECI      gs_pfc_status.tx_buffer_decimal2

#define PFC_DISPLAY_VALUE_HIGH_LIMIT      gs_pfc_vars.display_high_limit
#define PFC_DISPLAY_VALUE_LOW_LIMIT       gs_pfc_vars.display_low_limit
#define PFC_DISPLAY_VALUE_HIGH            gs_pfc_vars.display_high
#define PFC_DISPLAY_VALUE_LOW             gs_pfc_vars.display_low
#define PFC_DISPLAY_VALUE_SPAN            gs_pfc_vars.display_span
#define	PFC_SERIAL_NUMBER                 gs_pfc_vars.serial_number
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
#include "..\main.h"
#include "c_src\pfc_init.h"
#include "c_src\pfc_glb_vars.h"
#include "c_src\pfc_task.h"
//**********************************************************************************************************************
//
// A P I   F O R   O T H E R   M O D U L E S
//
//**********************************************************************************************************************
//! @brief The Product Function Control Initial API
#define	PFC_INIT_API()                          pfc_init()
//! @brief The Main Loop Task of PFC
#define PFC_MAIN_LOOP_API()                     pfc_loop()
//! @brief The API for counting the zero-checksum for a memory
#define PFC_MAKE_EEPROM_ZERO_CHECKSUM_API()     pfc_make_zero_checksum((UINT16*)&gs_pfc_vars,sizeof(gs_pfc_vars))
//! @brief The API for restoring the system variable back to eeprom
#define PFC_RESTORE_EEPROM_API(block)           pfc_restore_eeprom(block)
//! @brief The API for loading default setting
#define PFC_LOAD_DEFAULT_API()			pfc_glb_vars_load_default()

#define PFC_ADD_SECOND_API()                    pfc_add_sec()
//**********************************************************************************************************************
//
// A P I   C A L L   F R O M   O T H E R   M O D U L E S
//
//**********************************************************************************************************************
//! @brief The API for restore User data
#define PFC_RESTORE_USER_DATA_API()             FK_WRITE_USER_DATA_API((UINT32*)&gs_pfc_vars,sizeof(gs_pfc_vars))
//! @brief The API for restore Factory data
#define PFC_RESTORE_FACTORY_DATA_API()          FK_WRITE_FACTORY_DATA_API((UINT32*)&gs_pfc_vars,sizeof(gs_pfc_vars))
//! @brief The API for readint out User data
#define PFC_READ_USER_DATA_API()                FK_READ_USER_DATA_API((UINT32*)&gs_pfc_vars,sizeof(gs_pfc_vars))
//! @brief The API for readint out User data
#define PFC_READ_FACTORY_DATA_API()             FK_READ_FACTORY_DATA_API((UINT32*)&gs_pfc_vars,sizeof(gs_pfc_vars))
//! @brief The API for entering stop mode
#define PFC_ENTER_STOP_MODE_API()               FK_ENTER_STOP_MODE_API()
//! @brief The API for enabling watch dog
#define PFC_WATCHDOG_ENABLE_API()               FK_IWATCHDOG_ENABLE_API()
//! @brief The API for reloading watch dog
#define PFC_RELOAD_WATCHDOG_API()               FK_RELOAD_IWATCHDOG_API()


//=====================================================================================================================
//! @brief Set up a fan  event flag
#define PFC_SET_FAN_TASK_API()                          gs_pfc_status.fan_task=1
//! @brief Clear a fan event flag
#define PFC_CLR_FAN_TASK_API()                          gs_pfc_status.fan_task=0
//! @brief The fan task for pfc
#define PFC_CHK_FAN_TASK_API()                          gs_pfc_status.fan_task

//! @brief Set up a air pump event flag
#define PFC_SET_AIR_PUMP_TASK_API()                     gs_pfc_status.air_pump_task=1
//! @brief Clear a air pump event flag
#define PFC_CLR_AIR_PUMP_TASK_API()                     gs_pfc_status.air_pump_task=0
//! @brief The air pump task for pfc
#define PFC_CHK_AIR_PUMP_TASK_API()                     gs_pfc_status.air_pump_task

//! @brief Set up a water pump event flag
#define PFC_SET_WATER_PUMP_TASK_API()                   gs_pfc_status.water_pump_task=1
//! @brief Clear a water pump event flag
#define PFC_CLR_WATER_PUMP_TASK_API()                   gs_pfc_status.water_pump_task=0
//! @brief The water pump task for pfc
#define PFC_CHK_WATER_PUMP_TASK_API()                   gs_pfc_status.water_pump_task

//! @brief Set up a ad5941 event flag
#define PFC_SET_AD5941_TASK_API()                       gs_pfc_status.ad5941_task=1
//! @brief Clear a ad5941 event flag
#define PFC_CLR_AD5941_TASK_API()                       gs_pfc_status.ad5941_task=0
//! @brief The ad5941 task for pfc
#define PFC_CHK_AD5941_TASK_API()                       gs_pfc_status.ad5941_task


//! @brief The API for setting second level software timer
#define PFC_SET_SEC_CNT_API(cnt)                        BTC_SET_SEC_CNT_API(BTC_UIF_USER_SEC,cnt)
//! @brief The API for clearing second level software timer
#define PFC_CLR_SEC_CNT_API()                           BTC_CLR_SEC_CNT_API(BTC_UIF_USER_SEC)
//! @brief The API for getting the second level software timer counter
#define PFC_GET_SEC_CNT_API()                           BTC_GET_SEC_CNT_API(BTC_UIF_USER_SEC)
//**********************************************************************************************************************
//
// F U N C T I O N   P R O T O T Y P E S
//
//**********************************************************************************************************************
void pfc_loop(void);
#endif		// PFC_UDEF_H 
