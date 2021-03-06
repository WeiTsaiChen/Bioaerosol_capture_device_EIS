//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 nb_ublox_glb_vars.c
//
//! @author 	 Vic.Chen
//
//! @date 		 2018/09/05
//
//  @brief 		 Init globe variable
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S
//
//**********************************************************************************************************************
#define NB_UBLOX_ALLOC
#include "nb_ublox_glb_vars.h"
#undef NB_UBLOX_ALLOC
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
//! @fn 			 nb_ublox_glb_vars_init
//
//! @author 	 Vic.Chen
//
//! @date 		 2018/09/05
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void nb_ublox_glb_vars_init()
{
    gb_nb_ublox_cmd_oder = 0;
    gb_nb_ublox_ststus = 0;
    gb_nb_ublox_error_code = 0;
    gb_nb_ublox_uart_send_index = 0;
    gb_nb_ublox_uart_send_count = 0;
    gb_nb_ublox_uart_receive_cound = 0;
	gb_nb_ublox_uart_status = 0;
	gb_nb_ublox_uart_direction = NB_UBLOX_UART_RECEIVE;
	gb_nb_ublox_cgdcont_delay_ocunt = 0;
}
//**********************************************************************************************************************
//
// C   P L U S   P L U S   C O M P A T I A B L E   D E F I N I T I O N
//
//**********************************************************************************************************************
#ifdef __cplusplus
}
#endif

