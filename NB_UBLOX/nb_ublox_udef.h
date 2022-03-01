#ifndef NB_UBLOX_UDEF_H
#define NB_UBLOX_UDEF_H
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
//! @file 		 nb_ublox_udef.h
//
//! @author 	 Vic.Chen
//
//! @date 		 2018/09/05
//
//  @brief 		 Here define all API
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// E X T E R N A L   G L O B A L   C O N S T A N C E   /   V A R I A B L E S   I N   E E P R O M 
//
//**********************************************************************************************************************
#define NB_UBLOX_BAUDRATE				115200
#define NB_UBLOX_BITS					FK_UART_8BITS_MODE
#define NB_UBLOX_STOP_BITS				FK_UART_ONE_STOP_BIT
#define NB_UBLOX_PARITY					FK_UART_PARITY_NONE
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
#include "..\fk\fk_udef.h"
#include "..\fk\fk_uart_udef.h"
#include "..\hbtc\hbtc_udef.h"
#include "..\pfc\pfc_udef.h"
#include "..\main.h"
#include "c_src\nb_ublox_init.h"
#include "c_src\nb_ublox_task.h"
//#include "c_src\nb_ublox_network.h"
#include "c_src\nb_ublox_glb_vars.h"

//**********************************************************************************************************************
//
// A P I   F O R   O T H E R   M O D U L E S 
//
//**********************************************************************************************************************
#define	NB_UBLOX_INIT_API()				nb_ublox_init()
#define NB_UBLOX_TASK()					nb_ublox_task()
#define NB_UBLOX_RESET_API()			nb_ublox_power_reset_task()
#define NB_UBLOX_SEND_DATA_API(data,len)        nb_ublox_send_data_task(data,len)
#define NB_UBLOX_READ_API(data)			nb_ublox_receive_task(data)
#define NB_UBLOX_ERROR_CHECK_API(data)	nb_ublox_error_chenk(data)
#define NB_UBLOX_WRITE_CMD_API(id,len)          nb_ublox_write_data_cmd_mode(id,len)    
#define NB_UBLOX_SEND_ACK_API(id)   nb_ublox_send_ack_task(id)
#define NB_UBLOX_REINIT_API()             nb_ublox_init()
//**********************************************************************************************************************
//
// A P I   C A L L   F R O M   O T H E R   M O D U L E S 
//
//**********************************************************************************************************************
#define NB_UBLOX_UART_INIT()			FK_UART1_INTERRUPT_API(NB_UBLOX_BAUDRATE,NB_UBLOX_BITS,NB_UBLOX_STOP_BITS,NB_UBLOX_PARITY,nb_ublox_transmitter_data,nb_ublox_receive_data)
#define NB_UBLOX_RECEIVE_API()			FK_UART1_GET_DATA_API()
#define NB_UBLOX_TIMEOUT_API()			HBTC_SET_TIMER_API(HBTC_EHS_3G_TIMER,gb_nb_ublox_timer_value,nb_ublox_receive_isr)
#define NB_UBLOX_UART_TX_ENABLE()       FK_UART1_TX_INTERRUPT_ENABLE_API()
#define NB_UBLOX_SEND_OUT_API(data)		FK_UART1_SEND_BYTE_API(data)

//**********************************************************************************************************************
//
// F U N C T I O N   P R O T O T Y P E S 
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// C   P L U S   P L U S   C O M P A T I A B L E   D E F I N I T I O N 
//
//**********************************************************************************************************************
#define NB_UBLOX_STATUS_FLAGE			gb_nb_ublox_ststus
#define NB_UBLOX_ERROR_CODE				gb_nb_ublox_error_code
#define NB_UBLOX_CMD_ORDER				gb_nb_ublox_cmd_oder

#ifdef __cplusplus
}
#endif
#endif		// NB_UBLOX_UDEF_H 
