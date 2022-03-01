#ifndef MAIN_H
#define MAIN_H
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 main.h
//
//! @author 	 Willman Chen
//
//! @date 		 	2012-03-29
//
//  @brief 		 Here define all API
//
//**********************************************************************************************************************

//**********************************************************************************************************************
//
// E X T E R N A L   G L O B A L   C O N S T A N C E   /   V A R I A B L E S   I N   E E P R O M
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// C O N D I C T I O N   C O M P I L E
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//  MCU TYPE AND CLOCK SELECT
//**********************************************************************************************************************
#define MAIN_LOW_POWER_MODE			        0
#define MAIN_ENTER_SLEEP_MODE   			0
#define MAIN_USE_WATCHDOG       		        0
#define MAIN_RTC_TIMING         			16   // Range: 1 ~ 128    1 sec ~ 1/128 sec 
#define MAIN_RTC_CALENDAR				0
#define MAIN_USE_LSE            			0
#define MAIN_USE_LSI            			1
#define MAIN_USE_HSE            			1
#define	MAIN_USE_HSI            			0
#define MAIN_USE_PLL					1
#define MAIN_USE_MSI					0
//**********************************************************************************************************************
//  Software Timer
//**********************************************************************************************************************
#define	MAIN_USE_HBTC        				1
#define	MAIN_USE_BTC         				1
//**********************************************************************************************************************
//  LOOP POWER IC SELECT
//**********************************************************************************************************************
#define MAIN_USE_AD5421     				0
#define MAIN_USE_AD5422					0
#define MAIN_USE_AD421       				0
//**********************************************************************************************************************
//  COMMUCATION INTERFACE
//**********************************************************************************************************************
#define	MAIN_USE_MODBUS					1
#define	MAIN_USE_BLE					1
#define	MAIN_USE_HART					0
//**********************************************************************************************************************
//  KEY INTERFACE
//**********************************************************************************************************************
#define MAIN_USE_KEY         				0
//**********************************************************************************************************************
//  DISPLAY INTERFACE
//**********************************************************************************************************************
#define MAIN_USE_UIF         				0
#define MAIN_USE_ST7565					0
#define MAIN_USE_LCD         				0
#define MAIN_USE_BU9795AFV   				0    // LCD Driver
//**********************************************************************************************************************
//  PLUS GENERATOR
//**********************************************************************************************************************
#define MAIN_USE_AD9833      				0
#define MAIN_USE_CDCE925     				0
//**********************************************************************************************************************
//  DAC
//**********************************************************************************************************************
#define MAIN_USE_DAC7578     				0
#define MAIN_USE_DAC8562     				0
//**********************************************************************************************************************
//  ADC
//**********************************************************************************************************************
#define MAIN_USE_ADS1114     				0
#define MAIN_USE_ADS1115     				0
#define MAIN_USE_MCP3422				0
//**********************************************************************************************************************
//  I/O Expander
//**********************************************************************************************************************
#define MAIN_USE_TCA9539     				0
//**********************************************************************************************************************
//  DIGITAL RESISTANCE
//**********************************************************************************************************************
#define   MAIN_USE_AD5245			        0
//**********************************************************************************************************************
//  TEMPERATURE SENSOR
//**********************************************************************************************************************
#define   MAIN_USE_TMP100				0
//#define   MAIN_USE_TMP121				0
#define   MAIN_USE_ADT7410				0
//**********************************************************************************************************************
//  OTHER
//**********************************************************************************************************************
#define   MAIN_USE_AD5941				1
//**********************************************************************************************************************
//
// Define Check && Include file
//
//**********************************************************************************************************************
#if MAIN_LOW_POWER_MODE == 1 && MAIN_ENTER_SLEEP_MODE== 1
#error "Please choose one girl once time !"
#endif

#if MAIN_USE_LSI == 1 && MAIN_USE_LSE ==1
#error "You can't get both! bad boy!"
#endif

#if MAIN_USE_LSI == 0 && MAIN_USE_LSE == 0
#error "You must get one girl,handsome boy!"
#endif

#if MAIN_USE_HSE == 1 && MAIN_USE_HSI ==1 
#error "You can't get both! bad boy!"
#endif

#if MAIN_USE_HSE == 0 && MAIN_USE_HSI == 0
#error "You must get one girl,handsome boy!"
#endif

#if MAIN_USE_AD5421 == 1 && MAIN_USE_AD421 == 1
#error "Are you Crazy?"
#endif

#if MAIN_USE_AD5421 == 1
#include "ad5421\ad5421_udef.h"
#endif

#if MAIN_USE_AD421 == 1
#include "ad421\ad421_udef.h"
#endif

#if MAIN_USE_ST7565 == 1
#define MAIN_USE_GDM       1
#define MAIN_USE_UDM       1
#include "st7565\st7565_udef.h"
#include "gdm\gdm_udef.h"
#include "udm\udm_udef.h"
#endif

#if MAIN_USE_AD9833 == 1
#include "ad9833\ad9833_udef.h"
#endif

#if MAIN_USE_CDCE925 == 1
#include "cdce925\cdce925_udef.h"
#endif

#if MAIN_USE_DAC7578 == 1
#include "dac7578\dac7578_udef.h"
#endif

#if MAIN_USE_DAC8562 == 1
#include "DAC8562\dac8562_udef.h"
#endif

#if MAIN_USE_ADS1114 == 1
#include "ads1114\ads1114_udef.h"
#endif

#if MAIN_USE_MCP3422 == 1
#include "mcp3422\mcp3422_udef.h"
#endif

#if MAIN_USE_TCA9539 == 1
#include "tca9539\tca9539_udef.h"
#endif

#if MAIN_USE_AD5245 == 1
#include "ad5245\ad5245_udef.h"
#endif

#if MAIN_USE_TMP100 == 1
#include "tmp100\tmp100_udef.h"
#endif

#if MAIN_USE_TMP121 == 1
#include "tmp121\tmp121_udef.h"
#endif

#include "fk\fk_udef.h"
#include "btc\btc_udef.h"
#if MAIN_USE_KEY == 1
#include "key\key_udef.h"
#endif

#if MAIN_USE_UIF == 1
#include "uif\uif_udef.h"
#endif

#if MAIN_USE_MODBUS==1 || MAIN_USE_HART == 1
#define MAIN_USE_CRC   1
#include "crc\crc_udef.h"
#endif

#if MAIN_USE_MODBUS == 1
#include "modbus_slave\modbus_slave_udef.h"
#endif

#if MAIN_USE_BLE == 1
#include "ble\ble_udef.h"
#endif

#if MAIN_USE_HART == 1
#include "hart\hart_udef.h"
#endif

#if MAIN_USE_LCD == 1
#include "lcd\lcd_udef.h"
#endif

#if MAIN_USE_BU9795AFV == 1
#include "BU9795AFV\BU9795AFV_udef.h"
#endif

#if MAIN_USE_AD5422 == 1
#include "AD5422\AD5422_udef.h"
#endif

#if MAIN_USE_ADS1115 == 1
#include "ADS1115\ADS1115_udef.h"
#endif

#if MAIN_USE_ADT7410 == 1
#include "ADT7410\ADT7410_udef.h"
#endif

#if MAIN_USE_AD5941 == 1
#include "AD5941\AD5941_udef.h"
#endif

#include "pfc\pfc_udef.h"
#endif		// MAIN_H 
