//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 	 pfc_glb_vars.c
//
//! @author  Willman Chen
//
//! @date 	 2009/06/19
//
// @brief 	 Init globe variable
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S
//
//**********************************************************************************************************************
#define PFC_ALLOC
#include "pfc_glb_vars.h"
#undef PFC_ALLOC
#include "pfc_task.h"
#include "pfc_idef.h"
#include "..\pfc_udef.h"

STC_PFC_AUTO_ID  gs_pfc_auto_id=
{
    0xCDEF,   // Product Type : FM 0x464D
    0x00AB,   // Product number: 0x0001
    0x0001    // Product version: 0x0001
};

const UINT8 gt_pfc_days_of_month[12]=
{
// 1  2 3  4  5  6  7  8  9  10 11 12  month
  31,28,31,30,31,30,31,31,30,31,30,31,
};
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 pfc_glb_vars_init
//
//! @author  Willman Chen
//
//! @date 	 2009/06/19
//
//! @brief 	 task function
//
//**********************************************************************************************************************
void pfc_glb_vars_load_default()
{
    UINT32 i;
    UINT8 *data=(UINT8*)&gs_pfc_vars;
    for (i=0; i<sizeof(gs_pfc_vars); i++)
        *(data+i)=0x00;
    
    PFC_USE_HART=0;
    PFC_USE_MODBUS=1;
    PFC_USE_ZIGBEE=0;
    PFC_USE_PROFIBUS=0;
    PFC_USE_HART_WIRELESS=0;

    PFC_SAVE_CALIBRATION_SETTING=0;
    PFC_LOAD_DEFAULT_SETTING=0;
    PFC_SAVE_SYSTEM_VAR_TO_EEPROM=0;
    PFC_LOAD_FIRMWARE_SETTING=0;
    
    PFC_DISPLAY_VALUE=0;
    PFC_DISPLAY_VALUE_HIGH_LIMIT=0;
    PFC_DISPLAY_VALUE_LOW_LIMIT=0;
    PFC_DISPLAY_VALUE_HIGH=0;
    PFC_DISPLAY_VALUE_LOW=0;
    PFC_SERIAL_NUMBER=1;

    PFC_MODBUS_BAUDRATE=57600;
    PFC_MODBUS_ID=1;
    PFC_MODBUS_BTIS=FK_UART_8BITS_MODE;
    PFC_MODBUS_STOP_BITS=FK_UART_ONE_STOP_BIT;
    PFC_MODBUS_PARITY=FK_UART_PARITY_NONE;
    PFC_MODBUS_MODE=MODBUS_SLAVE_RTU_MODE;
    
    PFC_BLE_BAUDRATE=9600;
    PFC_BLE_ID=1;
    PFC_BLE_BTIS=FK_UART_8BITS_MODE;
    PFC_BLE_STOP_BITS=FK_UART_ONE_STOP_BIT;
    PFC_BLE_PARITY=FK_UART_PARITY_NONE;
    PFC_BLE_MODE=MODBUS_SLAVE_RTU_MODE;
}

//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 pfc_glb_vars_init
//
//! @author  Willman Chen
//
//! @date 	 2009/06/19
//
//! @brief 	 task function
//
//**********************************************************************************************************************
void pfc_glb_vars_init()
{
    UINT16 i,chksum;
    UINT16 *data=(UINT16*)&gs_pfc_vars;
    *((UINT32*)&gs_pfc_status)=0x00;
    PFC_READ_USER_DATA_API();
    for (i=0,chksum=0; i<(sizeof(gs_pfc_vars)>>1); i++)
        chksum+=*(data+i);
    // loading default setting from firmware if fail.
    if (chksum)
    {
        PFC_READ_FACTORY_DATA_API();
        //check the checksum
        for (i=0,chksum=0; i<(sizeof(gs_pfc_vars)>>1); i++)
            chksum+=*(data+i);
        if (chksum)
        {
            for (i=0; i<(sizeof(gs_pfc_vars)>>1); i++)
                *(data+i)=0x0000;
            pfc_glb_vars_load_default();
            PFC_MAKE_EEPROM_ZERO_CHECKSUM_API();
            PFC_RESTORE_FACTORY_DATA_API();
        }
        PFC_MAKE_EEPROM_ZERO_CHECKSUM_API();
        PFC_RESTORE_USER_DATA_API();
    }
}
