#ifndef NB_UBLOX_DRV_H
#define NB_UBLOX_DRV_H
//**********************************************************************************************************************
//
// C   P L U S   P L U S   C O M P A T I A B L E   D E F I N I T I O N 
//
//**********************************************************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 nb_ublox_drv.h
//
//! @author 	 Vic.Chen
//
//! @date 		 2018/09/05
//
//  @brief 		 Here declare driver function
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S 
//
//**********************************************************************************************************************
#include "..\nb_ublox_udef.h"
//**********************************************************************************************************************
//
// I / O   P O R T   D E F I N I T I O N 
//
//**********************************************************************************************************************
#define NB_UBLOX_IGT_PORT		FK_PORTA//FK_PORTB
#define NB_UBLOX_IGT_PIN		FK_PIN4	//FK_PIN0
#define NB_UBLOX_IGT_INIT()		FK_SET_PIN_OUPUT_PUSH_PUMP_API(NB_UBLOX_IGT_PORT,NB_UBLOX_IGT_PIN)
#define NB_UBLOX_IGT_HIGH()		FK_SET_OUTPUT_PIN_HIGH_API(NB_UBLOX_IGT_PORT,NB_UBLOX_IGT_PIN)
#define NB_UBLOX_IGT_LOW()		FK_SET_OUTPUT_PIN_LOW_API(NB_UBLOX_IGT_PORT,NB_UBLOX_IGT_PIN)

#define NB_UBLOX_PWR_EN_PORT	        FK_PORTB//FK_PORTA
#define NB_UBLOX_PWR_EN_PIN		FK_PIN6//FK_PIN4
#define NB_UBLOX_PWR_EN_INIT()	FK_SET_PIN_OUPUT_PUSH_PUMP_API(NB_UBLOX_PWR_EN_PORT,NB_UBLOX_PWR_EN_PIN)
#define NB_UBLOX_PWR_EN_ON()		FK_SET_OUTPUT_PIN_HIGH_API(NB_UBLOX_PWR_EN_PORT,NB_UBLOX_PWR_EN_PIN)
#define NB_UBLOX_PWR_EN_OFF()	FK_SET_OUTPUT_PIN_LOW_API(NB_UBLOX_PWR_EN_PORT,NB_UBLOX_PWR_EN_PIN)


#define NB_UBLOX_RTS_PORT		FK_PORTB//FK_PORTA
#define NB_UBLOX_RTS_PIN			FK_PIN5	//FK_PIN8
#define NB_UBLOX_RTS_INIT()		FK_SET_PIN_OUPUT_PUSH_PUMP_API(NB_UBLOX_RTS_PORT,NB_UBLOX_RTS_PIN)
#define NB_UBLOX_RTS_HIGH()		FK_SET_OUTPUT_PIN_HIGH_API(NB_UBLOX_RTS_PORT,NB_UBLOX_RTS_PIN)
#define NB_UBLOX_RTS_LOW()		FK_SET_OUTPUT_PIN_LOW_API(NB_UBLOX_RTS_PORT,NB_UBLOX_RTS_PIN)

//**********************************************************************************************************************
//
// M A C R O   D E F I N I T I O N 
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// F U N C T I O N   P R O T O T Y P E S 
//
//**********************************************************************************************************************
void nb_ublox_sfr_init();
//**********************************************************************************************************************
//
// C   P L U S   P L U S   C O M P A T I A B L E   D E F I N I T I O N 
//
//**********************************************************************************************************************
#ifdef __cplusplus
}
#endif
#endif		// NB_UBLOX_DRV_H 
