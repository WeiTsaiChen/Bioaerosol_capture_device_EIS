//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 modbus_slave_glb_vars.c
//
//! @author 	 Willman Chen
//
//! @date 		 2009/11/10
//
//  @brief 		 Init globe variable
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S
//
//**********************************************************************************************************************
#define MODBUS_SLAVE_ALLOC
#include "modbus_slave_glb_vars.h"
#undef MODBUS_SLAVE_ALLOC
#include "modbus_slave_idef.h"
#include "modbus_slave_task.h"

const STC_MODBUS_SLAVE_COMMAND_INFO gt_modbus_slave_valid_function[MODBUS_SLAVE_MAX_COMMAND]=
{
//  id code	max_register	max_value	return_byte_cnt	command length	action		supported
    {0x00	,0	,0	,0	,0	,modbus_slave_null_func			,MODBUS_SLAVE_SUPPORTED_CMD_NO},	//  Non
    {0x01	,0	,0	,0	,0	,modbus_slave_null_func			,MODBUS_SLAVE_SUPPORTED_CMD_NO},	//  Read Coils
    {0x02	,0	,0	,0	,0	,modbus_slave_null_func			,MODBUS_SLAVE_SUPPORTED_CMD_NO},	//  Read Discrete Inputs
    {0x03	,0xffff	,125	,2	,5	,modbus_slave_read_input_registers	,MODBUS_SLAVE_SUPPORTED_CMD_YES},	//  Read Holding Registers
    {0x04	,0	,0	,0	,0	,modbus_slave_null_func			,MODBUS_SLAVE_SUPPORTED_CMD_NO},	//  Read Input Registers
    {0x05	,0	,0	,0	,0	,modbus_slave_null_func			,MODBUS_SLAVE_SUPPORTED_CMD_NO},	//  Write Single Coil
    {0x06	,0xffff	,0xffff	,0	,5	,modbus_slave_write_single_register	,MODBUS_SLAVE_SUPPORTED_CMD_YES},	//  Write Single Register
    {0x07	,0	,0	,0	,0	,modbus_slave_null_func			,MODBUS_SLAVE_SUPPORTED_CMD_NO},	//	Read Exception Status
    {0x08	,0	,0	,0	,0	,modbus_slave_null_func			,MODBUS_SLAVE_SUPPORTED_CMD_NO},	//  Diagnostics
    {0x09	,0	,0	,0	,0	,modbus_slave_null_func			,MODBUS_SLAVE_SUPPORTED_CMD_NO},	//  not defined
    {0x0A	,0	,0	,0	,0	,modbus_slave_null_func			,MODBUS_SLAVE_SUPPORTED_CMD_NO},	//  not defined
    {0x0B	,0	,0	,0	,0	,modbus_slave_null_func			,MODBUS_SLAVE_SUPPORTED_CMD_NO},	//	Get Common Event Counter
    {0x0C	,0	,0	,0	,0	,modbus_slave_null_func			,MODBUS_SLAVE_SUPPORTED_CMD_NO},	//	Get common Event log
    {0x0D	,0	,0	,0	,0	,modbus_slave_null_func			,MODBUS_SLAVE_SUPPORTED_CMD_NO},	//  not defined
    {0x0E	,0	,0	,0	,0	,modbus_slave_null_func			,MODBUS_SLAVE_SUPPORTED_CMD_NO},	//  not defined
    {0x0F	,0	,0	,0	,0	,modbus_slave_null_func			,MODBUS_SLAVE_SUPPORTED_CMD_NO},	//  Write Multiple Coils
    {0x10	,0xffff	,0x7b	,1	,6	,modbus_slave_write_multi_register	,MODBUS_SLAVE_SUPPORTED_CMD_YES},	//	Write Multiple register
    {0x11	,0	,0	,0	,0	,modbus_slave_null_func			,MODBUS_SLAVE_SUPPORTED_CMD_NO},	//	Report Slave ID
    {0x12	,0	,0	,0	,0	,modbus_slave_null_func			,MODBUS_SLAVE_SUPPORTED_CMD_NO},	//  not defined
    {0x13	,0	,0	,0	,0	,modbus_slave_null_func			,MODBUS_SLAVE_SUPPORTED_CMD_NO},	//  not defined
    {0x14	,0	,0	,0	,0	,modbus_slave_null_func			,MODBUS_SLAVE_SUPPORTED_CMD_NO},	//	Read File Record
    {0x15	,0	,0	,0	,0	,modbus_slave_null_func			,MODBUS_SLAVE_SUPPORTED_CMD_NO},	//	Write File Record
    {0x16	,0	,0	,0	,0	,modbus_slave_null_func			,MODBUS_SLAVE_SUPPORTED_CMD_NO},	//	Mask Write Register
    {0x17	,0	,0	,0	,0	,modbus_slave_null_func			,MODBUS_SLAVE_SUPPORTED_CMD_NO},	//  Read/Write Multiple registers
    {0x18	,0	,0	,0	,0	,modbus_slave_null_func			,MODBUS_SLAVE_SUPPORTED_CMD_NO},	//	Read FIFO Queue
};

const UINT16 gt_modbus_slave_ddf_file[MODBUS_SLAVE_DDF_LEN]=
{
	0x4444,0x0046,0x014D,0x944F,0x0002,0x5100,0x0005,0x0000,0x0000,0x4680,0x6E69,0x5465,0x6B65,0x495F,0x2C44,0x7830,
        0x3031,0x3030,0x532C,0x5254,0x4E49,0x2C47,0x2C38,0x0D31,0x500A,0x0800,0x8100,0x6F72,0x7564,0x7463,0x545F,0x7079,
        0x0E65,0x3408,0x552C,0x4E49,0x3154,0x2C36,0x2C31,0x1E32,0x4E08,0x6D75,0x6562,0x1572,0x0050,0x8E80,0x3508,0x089E,
        0x9E33,0x5608,0x7265,0x6973,0x6E6F,0x08CE,0xDE36,0x3408,0x0A0D,0x6944,0x7073,0x616C,0x5F79,0x6156,0x756C,0x0265,
        0xAB02,0x31DA,0x088E,0x2C37,0x4C46,0x414F,0x8454,0x0D35,0x550A,0x696E,0x20CE,0x0752,0xDE39,0x360F,0x0FF2,0x8E32,
        0x6108,0x0FDA,0xE237,0x520F,0x6307,0x0FDE,0xA5AA,0x8374,0xF238,0x330F,0x088E,0xDA64,0x390F,0x0FE2,0x0752,0xDE66,
        0x310F,0x3230,0x3410,0x08CA,0x3031,0x101A,0x1531,0x5A05,0x9210,0x3207,0x1062,0x0511,0x4444,0x5F46,0x0053,0x8068,
        0x74B6,0x7261,0x4174,0x6464,0x6572,0x7373,0x094E,0x6233,0x1D09,0x5205,0x6165,0x4F64,0x6C6E,0x8E79,0x5F0A,0x0AEA,
        0x64E2,0x3D31,0xDA05,0x4C0A,0x8360,0x80DD,0x6E65,0x7467,0x0E68,0x6209,0x3165,0x0549,0x0906,0x7257,0x7469,0x4B65,
        0x0028,0x67A2,0x8131,0x1E05,0x660B,0x3714,0x0962,0x0591,0x4650,0x5F43,0x4944,0x0053,0x2074,0x5087,0x414C,0x5F59,
        0x4156,0x554C,0x8E45,0x3809,0x425E,0x05AD,0x0946,0x4F4D,0x4244,0x5355,0x9BD6,0x6131,0x11E2,0x05B1,0x08A2,0x4142,
        0x4455,0x00E8,0x9D6C,0x4152,0x5254,0x6212,0x9DE2,0x05D5,0x0A06,0x5F33,0x4F44,0x5F54,0x5F35,0x414D,0x08CE,0x75E2,
        0xC632,0x8CAE,0x5A34,0x6407,0x0762,0xAE06,0x3174,0x9D32,0x039D,0x9AE8,0x6507,0x07A2,0xAD06,0x3278,0x9A30,0x6207,
        0x327C,0x0581,0x078A,0x0F1A,0x3032,0x07A2,0x0569,0x1DCA,0x414D,0x4F5F,0x4646,0x4553,0xCE54,0x3108,0x08E2,0x0545,
        0x0017,0x802A,0x17CE,0x0932,0x8562,0x1232,0x4354,0x5255,0x4E52,0x5445,0x4C5F,0x434F,0x624B,0x3255,0x86E2,0x9232,
        0x5355,0x5641,0x5F45,0x5953,0x5453,0xC004,0xD003,0x4D45,0x52A8,0x545F,0x5F4F,0x4545,0x5250,0x4D4F,0x0C8E,0xED66,
        0x5992,0x065D,0x5F44,0x4544,0x4146,0x4C55,0x5F54,0x0219,0x0654,0x0FFD,0x41B8,0x4AAC,0x260B,0xD2F0,0x4A5A,0x460B,
        0x5249,0x574D,0x5241,0x01A1,0x0BA6,0x8B62,0x9233,0x4A5D,0x4323,0x4C41,0x4249,0x0701,0x4F49,0x6E4E,0x620C,0x338E,
        0x6292,0x3453,0x1616,0x458B,0x0E43,0x3807,0x0722,0x6212,0x494D,0x0E4E,0x6207,0x33FD,0x6192,0x4F48,0x5255,0x074E,
        0x91E2,0x5233,0x4461,0x5941,0x070E,0x8EE2,0x9233,0x4D5F,0x4E4F,0x162C,0x8032,0x4854,0x078E,0x8DA2,0x1233,0x595E,
        0x4145,0x15D2,0x8DA2,0x9633,0x455A,0x534E,0x854F,0x5905,0x9250,0x2263,0x338F,0x0D39,0x410A,
};

const UINT16* gt_modbus_slave_readonly[MODBUS_SLAVE_READONLY_NUM]=
{
    (UINT16*)&PFC_DISPLAY_VALUE		                    ,  //4128
    (UINT16*)&PFC_DISPLAY_VALUE+1		            ,  //4129
    (UINT16*)&PFC_MODBUS_ID                                 ,  //4130
    (UINT16*)&PFC_MODBUS_BAUDRATE                           ,  //4131~4139
};

const UINT16* gt_modbus_slave_read_write[MODBUS_SLAVE_READ_WRITE_NUM]=
{
    (UINT16*)&PFC_SAVE_SYSTEM_VAR_TO_EEPROM                 , //4140
    (UINT16*)&PFC_LOAD_DEFAULT_SETTING                      , //4141
    (UINT16*)&PFC_LOAD_FIRMWARE_SETTING			    , 
    (UINT16*)&PFC_SAVE_CALIBRATION_SETTING                  ,
    (UINT16*)&PFC_SEC			                    ,
    (UINT16*)&PFC_MIN	                                    ,
    (UINT16*)&PFC_HOUR                                      ,
    (UINT16*)&PFC_DAY                                       ,
    (UINT16*)&PFC_MONTH			                    ,
    (UINT16*)&PFC_YEAR                                      ,
    (UINT16*)&PFC_SERIAL_NUMBER                             ,             // For parellel communication with HART,please don't remove "PFC_SERIAL_NUMBER" variable
    (UINT16*)&PFC_SERIAL_NUMBER+1                           ,
    (UINT16*)&PFC_FAN_CTRL                                  , //4152
    (UINT16*)&PFC_AIR_PUMP_CTRL                             , //4153
    (UINT16*)&PFC_WATER_PUMP_CTRL                           , //4154   
    (UINT16*)&PFC_ADI_ID                                    , 
    (UINT16*)&PFC_CHIP_ID                                   , 
};
const UINT8 gt_modbus_slave_fine_tek_id[]= {'F','I','N','E','-','T','E','K'};
const UINT16 gw_modbus_slave_readonly_number=MODBUS_SLAVE_READONLY_NUM;
const UINT16 gw_modbus_slave_readwrite_number=MODBUS_SLAVE_READ_WRITE_NUM;
const UINT16 gw_modbus_slave_unit_type=0x501C;
const UINT16 gw_modbus_slave_ddf_start_address=MODBUS_SLAVE_DDF_START_ADDRESS;
const UINT16 gw_modbus_slave_readonly_remap_addr=MODBUS_SLAVE_READONLY_START_ADDRESS;
const UINT16 gw_modbus_slave_readwrite_remap_addr=MODBUS_SLAVE_READ_WRITE_START_ADDRESS;

const UINT16* gt_modbus_slave_header[MODBUS_SLAVE_HEADER_NUM]=
{
    (UINT16*)&gt_modbus_slave_fine_tek_id[0],				// 0x1000 ~ 0x1003 "FINE-TEK" company identified string
    (UINT16*)&gt_modbus_slave_fine_tek_id[2],
    (UINT16*)&gt_modbus_slave_fine_tek_id[4],
    (UINT16*)&gt_modbus_slave_fine_tek_id[6],
    (UINT16*)&PFC_PRODUCT_TYPE,			                        // 0x1004 : Product Type
    (UINT16*)&PFC_PRODUCT_NUMBER,			                // 0x1005 : Product number "FMCW 10G (0 ~ 30M)
    (UINT16*)&PFC_PRODUCT_VERSION,			                // 0x1006 : Product version 2010/10/01
    (UINT16*)&PFC_DISPLAY_VALUE,					// 0x1007 : the first variable value (high)
    (UINT16*)&PFC_DISPLAY_VALUE+1,					// 0x1008 : the first variable value (low)
    (UINT16*)&gw_modbus_slave_unit_type,                                // 0x1009 : the first variable unit
    (UINT16*)&PFC_DISPLAY_VALUE,					// 0x100A : the second variable value (high)
    (UINT16*)&PFC_DISPLAY_VALUE+1,					// 0x100B : the second variable value (low)
    (UINT16*)&gw_modbus_slave_unit_type,                                // 0x100C : the second variable unit (
    (UINT16*)&PFC_DISPLAY_VALUE,					// 0x100D : the third variable value (high)
    (UINT16*)&PFC_DISPLAY_VALUE+1,					// 0x100E : the third variable value (low)
    (UINT16*)&gw_modbus_slave_unit_type,                                // 0x100F : the third variable unit
    (UINT16*)&PFC_DISPLAY_VALUE,					// 0x1010 : the fourth variable value (high)
    (UINT16*)&PFC_DISPLAY_VALUE+1,					// 0x1011 : the fourth variable value (low)
    (UINT16*)&gw_modbus_slave_unit_type,                                // 0x1012 : the fourth variable unit
    (UINT16*)&gw_modbus_slave_ddf_start_address,			// 0x1013 : DDF Start Address
    (UINT16*)&gw_modbus_slave_readonly_remap_addr,                      // 0x1014 : Read-Only start address
    (UINT16*)&gw_modbus_slave_readonly_number,				// 0x1015 : the numbers of Read-Only Registers
    (UINT16*)&gw_modbus_slave_readwrite_remap_addr,                     // 0x1016 : Read-Write start address
    (UINT16*)&gw_modbus_slave_readwrite_number,				// 0x1017 : the numbers of Read-Write Registers
};


//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 		 modbus_slave_glb_vars_init
//
//! @author 	         Willman Chen
//
//! @date 		 2009/11/10
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	         None
//
//**********************************************************************************************************************
void modbus_slave_glb_vars_init()
{
    gb_modbus_slave_ptr=0;
    gs_modbus_slave_package_ptr=(STC_MODBUS_SLAVE_COMMAND_INFO*)&gt_modbus_slave_valid_function[0];
    gs_modbus_slave_error_package.error_code=0;
    gb_modbus_slave_response_length=0;
    gb_modbus_slave_state=MODBUS_SLAVE_STATE_STOP;
    gb_modbus_slave_char_ptr=0;
}
