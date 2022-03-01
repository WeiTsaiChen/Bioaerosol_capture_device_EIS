#ifndef NB_UBLOX_TASK_H
#define NB_UBLOX_TASK_H
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
//! @file 		 nb_ublox_task.h
//
//! @author 	 Vic.Chen
//
//! @date 		 2018/09/05
//
//  @brief 		 Here declare task function
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S 
//
//**********************************************************************************************************************
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
void nb_ublox_task();
UINT8 nb_ublox_string_compare(INT8* source,INT8* search);
void nb_ublox_clear_receive_variable();
void nb_ublox_clear_send_variable();
void nb_ublox_clear_error_variable();
void nb_ublox_receive_isr();
UINT8 nb_ublox_transmitter_data();
void nb_ublox_receive_data();
void nb_ublox_module_ready_task();
void nb_ublox_module_init_task();
void nb_ublox_error_task();
void nb_ublox_power_on_task();
void nb_ublox_power_off_task();
void nb_ublox_power_reset_task();
void nb_ublox_int_to_ascii(UINT8 m_len,UINT8* m_data);
void nb_ublox_send_data_task(UINT8* m_data,UINT16 m_len);
UINT16 nb_ublox_receive_task(UINT8* m_data);
void nb_ublox_connect_task();
void nb_ublox_error_chenk(INT8* m_data);
void nb_ublox_receive_analysis(UINT8* buf);
void nb_ublox_write_data_cmd_mode(UINT8 m_id, UINT16 m_len);
void nb_ublox_send_ack_task(UINT8 m_id);
//**********************************************************************************************************************
//
// C   P L U S   P L U S   C O M P A T I A B L E   D E F I N I T I O N 
//
//**********************************************************************************************************************
#ifdef __cplusplus
}
#endif
#endif		// NB_UBLOX_TASK_H 
