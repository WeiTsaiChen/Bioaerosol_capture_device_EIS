//**********************************************************************************************************************
//
// C   P L U S   P L U S   C O M P A T I A B L E   D E F I N I T I O N 
//
//**********************************************************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif
#ifndef NB_UBLOX_GLB_VARS_H
#define NB_UBLOX_GLB_VARS_H
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 nb_ublox_glb_vars.h
//
//! @author 	 Vic.Chen
//
//! @date 		 2018/09/05
//
//  @brief 		 Here declare globe variable
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S 
//
//**********************************************************************************************************************
#include "nb_ublox_idef.h"
#include "../nb_ublox_udef.h"
//**********************************************************************************************************************
//
// E X T E R N A L   V A R I A B L E   A L L O C 
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// T Y P E D E F   S T R U C T   D E F I N I T I O N 
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// F U N C T I O N   P R O T O T Y P E S 
//
//**********************************************************************************************************************
void nb_ublox_glb_vars_init();
#endif		// NB_UBLOX_GLB_VARS_H 
#ifdef NB_UBLOX_ALLOC
	#define EXTERNAL
#else
	#define EXTERNAL extern
#endif
//**********************************************************************************************************************
//
// D E C L A R E   G L O B E   V A R I A B L E 
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// C   P L U S   P L U S   C O M P A T I A B L E   D E F I N I T I O N 
//
//**********************************************************************************************************************
EXTERNAL UINT8	 gb_nb_ublox_cmd_oder;
EXTERNAL UINT8	 gb_nb_ublox_ststus;
EXTERNAL UINT16	 gb_nb_ublox_error_code;
EXTERNAL UINT8   gb_nb_ublox_send_buf[NB_UBLOX_MAX_BUFFER];
EXTERNAL UINT8   gb_nb_ublox_receive_buf[NB_UBLOX_MAX_BUFFER];
EXTERNAL UINT8	 gb_nb_ublox_error_buffer[NB_UBLOX_MAX_BUFFER];
EXTERNAL UINT16	 gb_nb_ublox_uart_send_index;
EXTERNAL UINT16	 gb_nb_ublox_uart_send_count;
EXTERNAL UINT16	 gb_nb_ublox_uart_receive_cound;
EXTERNAL UINT8	 gb_nb_ublox_uart_direction;
EXTERNAL UINT8   gb_nb_ublox_timer_value;
EXTERNAL UINT8	 gb_nb_ublox_uart_status;
EXTERNAL UINT8	 gb_nb_ublox_net_profile_id; //max id 6
EXTERNAL UINT8	 gb_nb_ublox_cgdcont_delay_ocunt;
EXTERNAL UINT8   gb_nb_ublox_cgdcont_noreg_count;  //註冊不到的次數
#undef EXTERNAL
#ifdef __cplusplus
}
#endif
