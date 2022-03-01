#ifndef PFC_DRV_H
#define PFC_DRV_H
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 	 pfc_drv.h
//
//! @author	 Willman Chen
//
//! @date 	 2009/06/19
//
// @brief 	 Here declare driver function
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S
//
//**********************************************************************************************************************
#define PFC_FAN_CTRL_PORT                   FK_PORTC
#define PFC_FAN_CTRL_PIN                    FK_PIN6
#define PFC_FAN_CTRL_LOW()                  FK_SET_OUTPUT_PIN_LOW_API(PFC_FAN_CTRL_PORT,PFC_FAN_CTRL_PIN)
#define PFC_FAN_CTRL_HIGH()                 FK_SET_OUTPUT_PIN_HIGH_API(PFC_FAN_CTRL_PORT,PFC_FAN_CTRL_PIN)
#define PFC_FAN_CTRL_INIT()                 FK_SET_PIN_OUPUT_PUSH_PUMP_API(PFC_FAN_CTRL_PORT,PFC_FAN_CTRL_PIN);PFC_FAN_CTRL_LOW()   

#define PFC_AIR_PUMP_CTRL_PORT              FK_PORTC
#define PFC_AIR_PUMP_CTRL_PIN               FK_PIN7
#define PFC_AIR_PUMP_CTRL_LOW()             FK_SET_OUTPUT_PIN_LOW_API(PFC_AIR_PUMP_CTRL_PORT,PFC_AIR_PUMP_CTRL_PIN)
#define PFC_AIR_PUMP_CTRL_HIGH()            FK_SET_OUTPUT_PIN_HIGH_API(PFC_AIR_PUMP_CTRL_PORT,PFC_AIR_PUMP_CTRL_PIN)
#define PFC_AIR_PUMP_CTRL_INIT()            FK_SET_PIN_OUPUT_PUSH_PUMP_API(PFC_AIR_PUMP_CTRL_PORT,PFC_AIR_PUMP_CTRL_PIN);PFC_AIR_PUMP_CTRL_LOW() 

#define PFC_WATER_PUMP_CTRL_PORT            FK_PORTC
#define PFC_WATER_PUMP_CTRL_PIN             FK_PIN8
#define PFC_WATER_PUMP_CTRL_LOW()           FK_SET_OUTPUT_PIN_LOW_API(PFC_WATER_PUMP_CTRL_PORT,PFC_WATER_PUMP_CTRL_PIN)
#define PFC_WATER_PUMP_CTRL_HIGH()          FK_SET_OUTPUT_PIN_HIGH_API(PFC_WATER_PUMP_CTRL_PORT,PFC_WATER_PUMP_CTRL_PIN)
#define PFC_WATER_PUMP_CTRL_INIT()          FK_SET_PIN_OUPUT_PUSH_PUMP_API(PFC_WATER_PUMP_CTRL_PORT,PFC_WATER_PUMP_CTRL_PIN);PFC_WATER_PUMP_CTRL_LOW() 
//**********************************************************************************************************************
//
// F U N C T I O N   P R O T O T Y P E S
//
//**********************************************************************************************************************
void pfc_sfr_init();
#endif		// PFC_DRV_H 
