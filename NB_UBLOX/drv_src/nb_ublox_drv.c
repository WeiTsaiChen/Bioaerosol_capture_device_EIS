//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 nb_ublox_drv.c
//
//! @author 	 Vic.Chen
//
//! @date 		 2018/09/05
//
//  @brief 		 Driver Subroutine
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S
//
//**********************************************************************************************************************
#include "nb_ublox_drv.h"
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
//! @fn 			 nb_ublox_sfr_init
//
//! @author 	 Vic.Chen
//
//! @date 		 2018/09/05
//
//! @brief 		 Register initial function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void nb_ublox_sfr_init()
{
    NB_UBLOX_UART_INIT();
    //AUTO_ON signal timing , reference Hardware Interface Description(datasheet) page 63
    
    NB_UBLOX_PWR_EN_INIT();
    for(UINT16 i=0; i<65535; i++) {}
    for(UINT16 i=0; i<65535; i++) {}
    for(UINT16 i=0; i<65535; i++) {}
    for(UINT16 i=0; i<65535; i++) {}
    for(UINT16 i=0; i<65535; i++) {}
    for(UINT16 i=0; i<65535; i++) {}
    for(UINT16 i=0; i<65535; i++) {}    
    NB_UBLOX_PWR_EN_OFF(); //Power ON(LD39300)  
    for(UINT16 i=0; i<65535; i++) {}
    NB_UBLOX_PWR_EN_ON(); //Power ON(LD39300)
    //EHS_RTS_INIT();
    //EHS_RTS_HIGH();

    NB_UBLOX_IGT_INIT();
    for(UINT16 i=0; i<65535; i++) {}
    NB_UBLOX_IGT_LOW();//EHS_IGT_HIGH();
    for(UINT16 i=0; i<65535; i++) {}
    for(UINT16 i=0; i<65535; i++) {}
    NB_UBLOX_IGT_HIGH();//EHS_IGT_LOW();
    //EHS_RTS_LOW();
    //for(UINT16 i=0; i<65535; i++) {}
    //EHS_IGT_HIGH();
    //EHS_RTS_LOW();
}
//**********************************************************************************************************************
//
// C   P L U S   P L U S   C O M P A T I A B L E   D E F I N I T I O N
//
//**********************************************************************************************************************
#ifdef __cplusplus
}
#endif

