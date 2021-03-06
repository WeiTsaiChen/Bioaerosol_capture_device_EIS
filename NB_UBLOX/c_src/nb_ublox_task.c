//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 nb_ublox_task.c
//
//! @author 	 Vic.Chen
//
//! @date 		 2018/09/05
//
//  @brief 		 Task Subroutine
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S
//
//**********************************************************************************************************************
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "..\drv_src\nb_ublox_drv.h"
#include "nb_ublox_glb_vars.h"
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
//! @fn 			 nb_ublox_task
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
void nb_ublox_task()
{
    switch(gb_nb_ublox_ststus)
    {
        case NB_UBLOX_MODULE_READY:
            nb_ublox_module_ready_task();
            break;
        case NB_UBLOX_INIT_TASK:
            nb_ublox_module_init_task();
            break;
        case NB_UBLOX_POWER_OFF:
            nb_ublox_power_off_task();
            break;
        case NB_UBLOX_POWER_ON:
            nb_ublox_power_off_task();
            break;
        case NB_UBLOX_SOCKET_CONNECT_TASK:
            nb_ublox_connect_task();
            break;

        default:
            return;
    }
}
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 		 nb_ublox_string_compare
//
//! @author 	        vic.chen
//
//! @date 		  2016/06/13
//
//! @brief 		 clean send buffer
//
//! @param 		 None
//
//! @return 	         None
//
//**********************************************************************************************************************
UINT8 nb_ublox_string_compare(INT8* source,INT8* search)
{
    INT8 *str_loc;
    str_loc = strstr(source, search);
    if(str_loc == 0)
        return 0;
    else
        return (UINT8)(str_loc - source);
}
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 		 nb_ublox_clear_receive_variable
//
//! @author 	        vic.chen
//
//! @date 		  2016/06/13
//
//! @brief 		 clean send buffer
//
//! @param 		 None
//
//! @return 	         None
//
//**********************************************************************************************************************
void nb_ublox_clear_receive_variable()
{
    for(UINT16 kk=0; kk<NB_UBLOX_MAX_BUFFER; kk++)
    {
        gb_nb_ublox_receive_buf[kk] = 0xAA ;
    }
}
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 		 nb_ublox_clear_send_variable
//
//! @author 	        vic.chen
//
//! @date 		  2016/06/13
//
//! @brief 		 clean send buffer
//
//! @param 		 None
//
//! @return 	         None
//
//**********************************************************************************************************************
void nb_ublox_clear_send_variable()
{
    for(UINT16 kk=0; kk<NB_UBLOX_MAX_BUFFER; kk++)
    {
        gb_nb_ublox_send_buf[kk] = 0xAA ;
    }
}
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 		 nb_ublox_clear_error_variable
//
//! @author 	        vic.chen
//
//! @date 		  2016/06/13
//
//! @brief 		 clean send buffer
//
//! @param 		 None
//
//! @return 	         None
//
//**********************************************************************************************************************
void nb_ublox_clear_error_variable()
{
    UINT16 kk;
    for(kk=0; kk<64; kk++)
    {
        gb_ehs_error_buffer[kk] = 0xAA ;
    }
}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 nb_ublox_receive_isr
//
//! @author 	 vic chen
//
//! @date 		 2016/05/03
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void nb_ublox_receive_isr()
{
    if(gb_nb_ublox_ststus >= NB_UBLOX_STANDBY && gb_nb_ublox_ststus <= NB_UBLOX_RECEIVE_DATA )
        gb_nb_ublox_ststus = NB_UBLOX_RECEIVE_DATA;
}
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 		 nb_ublox_transmitter_data
//
//! @author 	         vic.chen
//
//! @date 		 2016/06/13
//
//! @brief 		 receive date from master using UART interface
//
//! @param 		 None
//
//! @return 	         None
//
//**********************************************************************************************************************
UINT8 nb_ublox_transmitter_data()
{
    if(gb_nb_ublox_uart_send_index < gb_nb_ublox_uart_send_count)
    {
        NB_UBLOX_SEND_OUT_API(gb_nb_ublox_send_buf[gb_nb_ublox_uart_send_index++]);
        return 1;
    }
    else
    {
        nb_ublox_clear_send_variable();
        if(gb_nb_ublox_ststus >= NB_UBLOX_STANDBY && gb_nb_ublox_ststus <= NB_UBLOX_RECEIVE_DATA )
            gb_nb_ublox_ststus = NB_UBLOX_STANDBY;
    }
    return 0;
}
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 		 nb_ublox_receive_data
//
//! @author 	        vic.chen
//
//! @date 		  2016/06/13
//
//! @brief 		 receice data function to decode imformation and encode response data
//
//! @param 		 None
//
//! @return 	         None
//
//**********************************************************************************************************************
void nb_ublox_receive_data()
{

    UINT8 byte_value;

    if(gb_nb_ublox_uart_status)
        return;

    NB_UBLOX_TIMEOUT_API();
    byte_value=NB_UBLOX_RECEIVE_API();
    if(gb_nb_ublox_uart_receive_cound >= NB_UBLOX_MAX_BUFFER )
    {
        gb_nb_ublox_uart_receive_cound = NB_UBLOX_MAX_BUFFER;
        gb_nb_ublox_receive_buf[gb_nb_ublox_uart_receive_cound]=byte_value;
    }
    else
        gb_nb_ublox_receive_buf[gb_nb_ublox_uart_receive_cound++]=byte_value;
}

//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 nb_ublox_module_read_task
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
void nb_ublox_module_ready_task()
{
    UINT8 i=0;

    if(gb_nb_ublox_uart_direction == NB_UBLOX_UART_RECEIVE)
    {
        gb_nb_ublox_uart_send_count = sizeof(NB_UBLOX_CMD_ATZ) - 1;
        for(i=0; i<gb_nb_ublox_uart_send_count; i++)
            gb_nb_ublox_send_buf[i] = NB_UBLOX_CMD_ATZ[i];

        gb_nb_ublox_uart_direction = NB_UBLOX_UART_SEND; //???????e???A
        gb_nb_ublox_uart_send_index = 0;
        gb_nb_ublox_uart_receive_cound = 0;
        NB_UBLOX_UART_TX_ENABLE();
    }
    else
    {
        if(gb_nb_ublox_uart_receive_cound == 0)
        {
            gb_nb_ublox_uart_direction = NB_UBLOX_UART_RECEIVE;
            gb_nb_ublox_uart_receive_cound = 0;
        }
        else
        {
            if(nb_ublox_string_compare((INT8*)&gb_nb_ublox_receive_buf,"OK"))
                gb_nb_ublox_ststus++;
            else if(nb_ublox_string_compare((INT8*)&gb_nb_ublox_receive_buf,"ERROR")) //???????~?N?X
            {
                nb_ublox_error_task();
                gb_nb_ublox_uart_direction = NB_UBLOX_UART_RECEIVE;
                gb_nb_ublox_uart_receive_cound = 0;
                return;
            }


            gb_nb_ublox_uart_direction = NB_UBLOX_UART_RECEIVE;
            gb_nb_ublox_uart_receive_cound = 0;
        }
    }
}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 nb_ublox_module_init_task
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
void nb_ublox_module_init_task()
{
    UINT8 i=0;

    if(gb_nb_ublox_uart_direction == NB_UBLOX_UART_RECEIVE)
    {
        //???e?R?O
        switch(gb_nb_ublox_cmd_oder)
        {
            case NB_UBLOX_ORDER_ATZ:
                gb_nb_ublox_uart_send_count = sizeof(NB_UBLOX_CMD_ATZ) - 1;
                for(i=0; i<gb_nb_ublox_uart_send_count; i++)
                    gb_nb_ublox_send_buf[i] = NB_UBLOX_CMD_ATZ[i];

                break;
            case NB_UBLOX_ORDER_ATE:
                gb_nb_ublox_uart_send_count = sizeof(NB_UBLOX_CMD_ATE) - 1;
                for(i=0; i<gb_nb_ublox_uart_send_count; i++)
                    gb_nb_ublox_send_buf[i] = NB_UBLOX_CMD_ATE[i];

                break;
            /*case NB_UBLOX_ORDER_AT:
                gb_nb_ublox_uart_send_count = sizeof(NB_UBLOX_CMD_AT) - 1;
                for(i=0; i<gb_nb_ublox_uart_send_count; i++)
                    gb_nb_ublox_send_buf[i] = NB_UBLOX_CMD_AT[i];

                break;*/
            //===== "AT+URAT=8\r\n"
            case NB_UBLOX_ORDER_URAT:
                gb_nb_ublox_uart_send_count = sizeof(NB_UBLOX_CMD_URAT) - 1;
                for(i=0; i<gb_nb_ublox_uart_send_count; i++)
                    gb_nb_ublox_send_buf[i] = NB_UBLOX_CMD_URAT[i];

                break;                
            case NB_UBLOX_ORDER_CMEE:
                gb_nb_ublox_uart_send_count = sizeof(NB_UBLOX_CMD_CMEE) - 1;
                for(i=0; i<gb_nb_ublox_uart_send_count; i++)
                    gb_nb_ublox_send_buf[i] = NB_UBLOX_CMD_CMEE[i];

                break;
            /*case NB_UBLOX_ORDER_COPS:
                gb_nb_ublox_uart_send_count = sizeof(NB_UBLOX_CMD_COPS) - 1;
                for(i=0; i<gb_nb_ublox_uart_send_count; i++)
                    gb_nb_ublox_send_buf[i] = NB_UBLOX_CMD_COPS[i];

                break;*/
            //===== "AT+COPS=0\r\n"
            case NB_UBLOX_ORDER_COPS0:
                gb_nb_ublox_uart_send_count = sizeof(NB_UBLOX_CMD_COPS0) - 1;
                for(i=0; i<gb_nb_ublox_uart_send_count; i++)
                    gb_nb_ublox_send_buf[i] = NB_UBLOX_CMD_COPS0[i];

                break;                
            case NB_UBLOX_ORDER_LED_INIT:
                gb_nb_ublox_uart_send_count = sizeof(NB_UBLOX_LED_INIT) - 1;
                for(i=0; i<gb_nb_ublox_uart_send_count; i++)
                    gb_nb_ublox_send_buf[i] = NB_UBLOX_LED_INIT[i];

                break;
            case NB_UBLOX_ORDER_CGDCONT:
                //????????
                if(gb_nb_ublox_cgdcont_delay_ocunt > NB_UBLOX_CGDCONT_TIME)
                {
                    gb_nb_ublox_uart_send_count = sizeof(NB_UBLOX_CMD_CGDCONT) - 1;
                    for(i=0; i<gb_nb_ublox_uart_send_count; i++)
                        gb_nb_ublox_send_buf[i] = NB_UBLOX_CMD_CGDCONT[i];
                }

                break;
            case NB_UBLOX_ORDER_OK:  //?T?{?n?J????,????LED?C??
                gb_nb_ublox_uart_send_count = sizeof(NB_UBLOX_LED_GREEN) - 1;
                for(i=0; i<gb_nb_ublox_uart_send_count; i++)
                    gb_nb_ublox_send_buf[i] = NB_UBLOX_LED_GREEN[i];

                break;

            default:
                return;

        }
        gb_nb_ublox_uart_direction = NB_UBLOX_UART_SEND; //???????e???A
        gb_nb_ublox_uart_send_index = 0;
        gb_nb_ublox_uart_receive_cound = 0;
        NB_UBLOX_UART_TX_ENABLE();
    }
    else
    {
        //if(gb_nb_ublox_uart_receive_cound == 0)
        //return;
        //?????^??
        switch(gb_nb_ublox_cmd_oder)
        {
            case NB_UBLOX_ORDER_ATZ:
            case NB_UBLOX_ORDER_ATE:
            //case NB_UBLOX_ORDER_AT:
            case NB_UBLOX_ORDER_URAT:
            case NB_UBLOX_ORDER_CMEE:
            //case NB_UBLOX_ORDER_COPS:
            case NB_UBLOX_ORDER_COPS0:  
            case NB_UBLOX_ORDER_LED_INIT:
            {
                if(nb_ublox_string_compare((INT8*)&gb_nb_ublox_receive_buf,"OK"))
                    gb_nb_ublox_cmd_oder++;
                else if(nb_ublox_string_compare((INT8*)&gb_nb_ublox_receive_buf,"ERROR")) //???????~?N?X
                {
                    nb_ublox_error_task();
                    gb_nb_ublox_uart_direction = NB_UBLOX_UART_RECEIVE;
                    gb_nb_ublox_uart_receive_cound = 0;
                    break;
                }
                else
                {

                    gb_nb_ublox_uart_direction = NB_UBLOX_UART_RECEIVE;
                    gb_nb_ublox_uart_receive_cound = 0;
                    break;
                }

                gb_nb_ublox_uart_direction = NB_UBLOX_UART_RECEIVE;
                gb_nb_ublox_uart_receive_cound = 0;
                break;
            }
            case NB_UBLOX_ORDER_CGDCONT:
            {
                if( gb_nb_ublox_uart_receive_cound == 0 )
                {
                    gb_nb_ublox_cgdcont_delay_ocunt++;
                    gb_nb_ublox_uart_direction = NB_UBLOX_UART_RECEIVE;
                    gb_nb_ublox_uart_receive_cound = 0;
                    break;
                }
                if(nb_ublox_string_compare((INT8*)&gb_nb_ublox_receive_buf,"0.0.0.0"))
                {
                    //?S???U??IP
                    if(++gb_nb_ublox_cgdcont_noreg_count>=20)
                        nb_ublox_error_task();
                    gb_nb_ublox_cgdcont_delay_ocunt=0;
                    gb_nb_ublox_uart_direction = NB_UBLOX_UART_RECEIVE;
                    gb_nb_ublox_uart_receive_cound = 0;
                    break;

                }
                else if(nb_ublox_string_compare((INT8*)&gb_nb_ublox_receive_buf,"ERROR")) //???????~?N?X
                {
                    nb_ublox_error_task();
                    gb_nb_ublox_uart_direction = NB_UBLOX_UART_RECEIVE;
                    gb_nb_ublox_uart_receive_cound = 0;
                    break;
                }
                else
                {
                    //???U???\,???oIP
                    gb_nb_ublox_cmd_oder = NB_UBLOX_ORDER_OK;
                }

                gb_nb_ublox_uart_direction = NB_UBLOX_UART_RECEIVE;
                gb_nb_ublox_uart_receive_cound = 0;
                break;
            }
            case NB_UBLOX_ORDER_OK:
            {
                if(nb_ublox_string_compare((INT8*)&gb_nb_ublox_receive_buf,"OK"))
                {
                    gb_nb_ublox_cmd_oder = 0;
                    gb_nb_ublox_ststus = NB_UBLOX_IDEL;
                }
                else if(nb_ublox_string_compare((INT8*)&gb_nb_ublox_receive_buf,"ERROR")) //???????~?N?X
                {
                    nb_ublox_error_task();
                    gb_nb_ublox_uart_direction = NB_UBLOX_UART_RECEIVE;
                    gb_nb_ublox_uart_receive_cound = 0;
                    break;
                }
                else
                {

                    gb_nb_ublox_uart_direction = NB_UBLOX_UART_RECEIVE;
                    gb_nb_ublox_uart_receive_cound = 0;
                    break;
                }

                gb_nb_ublox_uart_direction = NB_UBLOX_UART_RECEIVE;
                gb_nb_ublox_uart_receive_cound = 0;
                break;
            }
            default:
                gb_nb_ublox_uart_direction = EHS_UART_RECEIVE;
                gb_nb_ublox_uart_receive_cound = 0;
                return;

        }
        nb_ublox_clear_receive_variable(); //clean reveive array
    }

}
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 		 nb_ublox_error_task
//
//! @author 	        vic.chen
//
//! @date 		  2016/06/13
//
//! @brief 		 error message task
//
//! @param 		 None
//
//! @return 	         None
//
//**********************************************************************************************************************
void nb_ublox_error_task()
{
    UINT8 i;
    UINT8 m_start=0;
    UINT8 m_read_start=0;
    UINT8 m_count = 0;
    UINT8 m_stop=0;
    UINT8 m_len=0;
    UINT8 m_error_code[3];

    m_len = gb_nb_ublox_uart_receive_cound;
    m_len -=2; //?????_?l0x0D 0x0A
    for(i=0; i<m_len; i++)
        gb_nb_ublox_error_buffer[i] = gb_nb_ublox_receive_buf[i+2];

    m_start = nb_ublox_string_compare((INT8*)&gb_nb_ublox_error_buffer,"ERROR: ");
    m_stop = nb_ublox_string_compare((INT8*)&gb_nb_ublox_error_buffer,"\r\n");
    if(m_start == 0 || m_stop == 0) //???????????r??
    {
        nb_ublox_clear_error_variable();
        return;
    }

    m_read_start = m_start + (sizeof("ERROR: ") - 1);
    if(m_stop > m_read_start)
        m_count = m_stop - m_read_start;

    if(m_count > 3) //?????L?j???^?????~
    {
        nb_ublox_clear_error_variable();
        return;
    }

    for(i=0; i<m_count; i++)
        m_error_code[i] = gb_ehs_error_buffer[m_read_start+i];

    nb_ublox_clear_error_variable();
    gb_nb_ublox_error_code = atoi((INT8*)&m_error_code); //string to int
    gb_nb_ublox_cgdcont_noreg_count=0;
    gb_nb_ublox_ststus = EHS_ERROR;
}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 nb_ublox_power_off_task
//
//! @author 	 vic chen
//
//! @date 		 2016/05/03
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void nb_ublox_power_off_task()
{

    NB_UBLOX_PWR_EN_OFF();
    gb_nb_ublox_cmd_oder = NB_UBLOX_ORDER_PWR_OFF_OK;

}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 nb_ublox_power_off_task
//
//! @author 	 vic chen
//
//! @date 		 2016/05/03
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void nb_ublox_power_on_task()
{

    NB_UBLOX_PWR_EN_ON();
    gb_nb_ublox_cmd_oder = 0;
    gb_nb_ublox_ststus = NB_UBLOX_MODULE_READY;
}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 nb_ublox_power_reset_task
//
//! @author 	 vic chen
//
//! @date 		 2016/05/03
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void nb_ublox_power_reset_task()
{
    UINT16 i;

    NB_UBLOX_PWR_EN_OFF();
    for(i=0; i<65530; i++) {}
    nb_ublox_power_on_task();
}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 nb_ublox_connect_task
//
//! @author 	 vic chen
//
//! @date 		 2016/05/03
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void nb_ublox_connect_task()
{
    UINT16 i;
    if(gb_nb_ublox_uart_direction == NB_UBLOX_UART_RECEIVE)
    {
        //???e?R?O
        switch(gb_nb_ublox_cmd_oder)
        {
            case NB_UBLOX_ORDER_ONLINE_1:
                gb_nb_ublox_uart_send_count = sizeof(NB_UBLOX_PRO_1) - 1;
                for(i=0; i<gb_nb_ublox_uart_send_count; i++)
                    gb_nb_ublox_send_buf[i] = NB_UBLOX_PRO_1[i];

                break;
            case NB_UBLOX_ORDER_ONLINE_2:
                gb_nb_ublox_uart_send_count = sizeof(NB_UBLOX_PRO_2) - 1;
                for(i=0; i<gb_nb_ublox_uart_send_count; i++)
                    gb_nb_ublox_send_buf[i] = NB_UBLOX_PRO_2[i];

                //????profile id,id?O?_?b0~6?d??
                if(gb_nb_ublox_net_profile_id > 0x30 && gb_nb_ublox_net_profile_id < 0x36)
                    gb_nb_ublox_send_buf[12] = gb_nb_ublox_net_profile_id;
                else
                    gb_nb_ublox_send_buf[12] = gb_nb_ublox_net_profile_id = 0x30;

                break;
            case NB_UBLOX_ORDER_ONLINE_3:
                gb_nb_ublox_cgdcont_delay_ocunt = 0;
                gb_nb_ublox_uart_send_count = sizeof(NB_UBLOX_PRO_3) - 1;
                for(i=0; i<gb_nb_ublox_uart_send_count; i++)
                    gb_nb_ublox_send_buf[i] = NB_UBLOX_PRO_3[i];

                //target IP  xxx.xxx.xxx:port
                for(i=0; i<PFC_LTE_DEST_SERVER_LEN; i++)
                {
                    if(PFC_LTE_DEST_SERVER[i] != ':')
                        gb_nb_ublox_send_buf[gb_nb_ublox_uart_send_count++] = PFC_LTE_DEST_SERVER[i];
                    else
                        break;
                }

                //????profile id,id?O?_?b0~6?d??
                if(gb_nb_ublox_net_profile_id > 0x30 && gb_nb_ublox_net_profile_id < 0x36)
                    gb_nb_ublox_send_buf[9] = gb_nb_ublox_net_profile_id;
                else
                    gb_nb_ublox_send_buf[9] = gb_nb_ublox_net_profile_id = 0x30;

                gb_nb_ublox_send_buf[gb_nb_ublox_uart_send_count++] = '\"';
                gb_nb_ublox_send_buf[gb_nb_ublox_uart_send_count++] = ',';
                i++;
                //port
                for(; i<PFC_LTE_DEST_SERVER_LEN; i++)
                {
                    gb_nb_ublox_send_buf[gb_nb_ublox_uart_send_count++] = PFC_LTE_DEST_SERVER[i];
                }

                for(i=0; i<sizeof(NB_UBLOX_PRO_3_end); i++)
                    gb_nb_ublox_send_buf[gb_nb_ublox_uart_send_count++] = NB_UBLOX_PRO_3_end[i];

                break;
                //???? command mode ?????n?] "at+USODL="
            /*case NB_UBLOX_ORDER_ONLINE_4:
                //???????e?R?O
                if(gb_nb_ublox_cgdcont_delay_ocunt > 2)
                {
                    //Socket in Direct Link mode
                    gb_nb_ublox_uart_send_count = sizeof(NB_UBLOX_PRO_4) - 1;
                    for(i=0; i<gb_nb_ublox_uart_send_count; i++)
                        gb_nb_ublox_send_buf[i] = NB_UBLOX_PRO_4[i];

                    //profile ID
                    gb_nb_ublox_send_buf[gb_nb_ublox_uart_send_count++] = gb_nb_ublox_net_profile_id;
                    gb_nb_ublox_send_buf[gb_nb_ublox_uart_send_count++] = 0x0D;
                    gb_nb_ublox_send_buf[gb_nb_ublox_uart_send_count++] = 0x0A;
                }
                break;*/
        }
        gb_nb_ublox_uart_direction = NB_UBLOX_UART_SEND; //???????e???A
        gb_nb_ublox_uart_send_index = 0;
        gb_nb_ublox_uart_receive_cound = 0;
        NB_UBLOX_UART_TX_ENABLE();
    }
    else
    {
        //if(gb_nb_ublox_uart_receive_cound == 0)
        //return;
        //?????^??
        switch(gb_nb_ublox_cmd_oder)
        {
            case NB_UBLOX_ORDER_ONLINE_1:
            {
                if(nb_ublox_string_compare((INT8*)&gb_nb_ublox_receive_buf,"OK"))
                {
                    //get profile id
                    gb_nb_ublox_net_profile_id = gb_nb_ublox_receive_buf[10];
                    gb_nb_ublox_cmd_oder++;
                }
                else if(nb_ublox_string_compare((INT8*)&gb_nb_ublox_receive_buf,"ERROR")) //???????~?N?X
                {
                    nb_ublox_error_task();
                    gb_nb_ublox_uart_direction = NB_UBLOX_UART_RECEIVE;
                    gb_nb_ublox_uart_receive_cound = 0;
                    break;
                }
                else
                {

                    gb_nb_ublox_uart_direction = NB_UBLOX_UART_RECEIVE;
                    gb_nb_ublox_uart_receive_cound = 0;
                    break;
                }

                gb_nb_ublox_uart_direction = NB_UBLOX_UART_RECEIVE;
                gb_nb_ublox_uart_receive_cound = 0;
                break;
            }
            case NB_UBLOX_ORDER_ONLINE_2:
            {
                if(nb_ublox_string_compare((INT8*)&gb_nb_ublox_receive_buf,"OK"))
                {
                    gb_nb_ublox_cmd_oder++;
                }
                else if(nb_ublox_string_compare((INT8*)&gb_nb_ublox_receive_buf,"ERROR")) //???????~?N?X
                {
                    nb_ublox_error_task();
                    gb_nb_ublox_uart_direction = NB_UBLOX_UART_RECEIVE;
                    gb_nb_ublox_uart_receive_cound = 0;
                    break;
                }
                else
                {

                    gb_nb_ublox_uart_direction = NB_UBLOX_UART_RECEIVE;
                    gb_nb_ublox_uart_receive_cound = 0;
                    break;
                }

                gb_nb_ublox_uart_direction = NB_UBLOX_UART_RECEIVE;
                gb_nb_ublox_uart_receive_cound = 0;
                break;
            }
            case NB_UBLOX_ORDER_ONLINE_3:
            {
                if(nb_ublox_string_compare((INT8*)&gb_nb_ublox_receive_buf,"OK"))
                {
                    gb_nb_ublox_cmd_oder=NB_UBLOX_ORDER_NET_SEND_1;
                    gb_nb_ublox_ststus = NB_UBLOX_STANDBY;
                }
                else if(nb_ublox_string_compare((INT8*)&gb_nb_ublox_receive_buf,"ERROR")) //???????~?N?X
                {
                    nb_ublox_error_task();
                    gb_nb_ublox_uart_direction = NB_UBLOX_UART_RECEIVE;
                    gb_nb_ublox_uart_receive_cound = 0;
                    break;
                }
                else
                {

                    gb_nb_ublox_uart_direction = NB_UBLOX_UART_RECEIVE;
                    gb_nb_ublox_uart_receive_cound = 0;
                    break;
                }

                gb_nb_ublox_uart_direction = NB_UBLOX_UART_RECEIVE;
                gb_nb_ublox_uart_receive_cound = 0;
                break;
            }
            //???? command mode ?????n?] "at+USODL="
            /*case NB_UBLOX_ORDER_ONLINE_4:
            {
                if( gb_nb_ublox_uart_receive_cound == 0 )
                {
                    gb_nb_ublox_cgdcont_delay_ocunt++;
                    gb_nb_ublox_uart_direction = NB_UBLOX_UART_RECEIVE;
                    gb_nb_ublox_uart_receive_cound = 0;
                    break;
                }
                if(nb_ublox_string_compare((INT8*)&gb_nb_ublox_receive_buf,"CONNECT"))
                {
                    gb_nb_ublox_cmd_oder++;
                    gb_nb_ublox_ststus = NB_UBLOX_STANDBY;
                }
                else if(nb_ublox_string_compare((INT8*)&gb_nb_ublox_receive_buf,"ERROR")) //???????~?N?X
                {
                    nb_ublox_error_task();
                    gb_nb_ublox_uart_direction = NB_UBLOX_UART_RECEIVE;
                    gb_nb_ublox_uart_receive_cound = 0;
                    break;
                }
                else
                {

                    gb_nb_ublox_uart_direction = NB_UBLOX_UART_RECEIVE;
                    gb_nb_ublox_uart_receive_cound = 0;
                    break;
                }

                gb_nb_ublox_uart_direction = NB_UBLOX_UART_RECEIVE;
                gb_nb_ublox_uart_receive_cound = 0;
                break;
            }*/
        }
        nb_ublox_clear_receive_variable();
    }
}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 nb_ublox_send_task
//
//! @author 	 vic chen
//
//! @date 		 2016/05/03
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void nb_ublox_int_to_ascii(UINT8 m_len,UINT8* m_data)
{
    UINT8 m_buf = 0;
    UINT8 m_org = m_len;
    if(m_len > 254)
        return;

    if(m_len > 99)
    {
        m_buf = (m_org/100);
        m_data[0] = m_buf + 0x30;
        m_org = m_org - (m_buf*100);
        m_buf = (m_org/10);
        m_data[1] = m_buf + 0x30;
        m_org = m_org - (m_buf*10);
        m_data[2] = m_org + 0x30;
    }
    else if(m_len > 9 && m_len < 100)
    {
        m_buf = (m_org/10);
        m_data[0] = m_buf + 0x30;
        m_org = m_org - (m_buf*10);
        m_data[1] = m_org + 0x30;
        m_data[2] = 0;
    }
    else
    {
        m_data[0] = m_org + 0x30;
        m_data[1] = 0;
        m_data[2] = 0;
    }
}
void nb_ublox_receive_analysis(UINT8* buf)
{
    if(gb_nb_ublox_uart_direction == NB_UBLOX_UART_RECEIVE)
    {
        switch(gb_nb_ublox_cmd_oder)
        {
            case NB_UBLOX_ORDER_NET_SEND_1:
            {
                if(nb_ublox_string_compare((INT8*)&buf,"@"))
                {
                    gb_nb_ublox_cmd_oder++;
                    
                }
                else if(nb_ublox_string_compare((INT8*)&buf,"ERROR")) //???????~?N?X
                {
                    nb_ublox_error_task();
                    gb_nb_ublox_uart_direction = NB_UBLOX_UART_RECEIVE;
                    gb_nb_ublox_uart_receive_cound = 0;
                    break;
                }
                else
                {
                    gb_nb_ublox_uart_direction = NB_UBLOX_UART_RECEIVE;
                    gb_nb_ublox_uart_receive_cound = 0;
                    break;
                }

                gb_nb_ublox_uart_direction = NB_UBLOX_UART_RECEIVE;
                gb_nb_ublox_uart_receive_cound = 0;
                break;              
            }
            case NB_UBLOX_ORDER_NET_SEND_2:
            {
                if(nb_ublox_string_compare((INT8*)&buf,"OK"))
                {
                    gb_nb_ublox_cmd_oder++;
                }
                else if(nb_ublox_string_compare((INT8*)&buf,"ERROR")) //???????~?N?X
                {
                    nb_ublox_error_task();
                    gb_nb_ublox_uart_direction = NB_UBLOX_UART_RECEIVE;
                    gb_nb_ublox_uart_receive_cound = 0;
                    break;
                }
                else
                {
                    gb_nb_ublox_uart_direction = NB_UBLOX_UART_RECEIVE;
                    gb_nb_ublox_uart_receive_cound = 0;
                    break;
                }

                gb_nb_ublox_uart_direction = NB_UBLOX_UART_RECEIVE;
                gb_nb_ublox_uart_receive_cound = 0;
                break;              
            }            
        }
        nb_ublox_clear_receive_variable();
    }
}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 nb_ublox_send_task
//
//! @author 	 vic chen
//
//! @date 		 2016/05/03
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void nb_ublox_write_data_cmd_mode(UINT8 m_id, UINT16 m_len)
{
    UINT16 i;
    INT8 m_temp[4];
    
    for(i=0; i<4; i++)
        m_temp[i]=0x00;  
    sprintf(m_temp,"%d",m_len);//???????r??               
    gb_nb_ublox_uart_send_count = sizeof(NB_UBLOX_NET_SEND) - 1;
    for(i=0; i<gb_nb_ublox_uart_send_count; i++)
        gb_nb_ublox_send_buf[i] = NB_UBLOX_NET_SEND[i];
    gb_nb_ublox_send_buf[gb_nb_ublox_uart_send_count++] = gb_nb_ublox_net_profile_id;
    gb_nb_ublox_send_buf[gb_nb_ublox_uart_send_count++] = ',';
    //????????
    for(i=0; i<4; i++)
    {
        if(m_temp[i] != '\0')
            gb_nb_ublox_send_buf[gb_nb_ublox_uart_send_count++] = m_temp[i];
        else
            break;
    }
    gb_nb_ublox_send_buf[gb_nb_ublox_uart_send_count++]=0x0D;
    gb_nb_ublox_send_buf[gb_nb_ublox_uart_send_count++]=0x0A;        
    gb_nb_ublox_uart_send_index = 0;
    gb_nb_ublox_uart_receive_cound = 0;
    NB_UBLOX_UART_TX_ENABLE();             
}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 nb_ublox_send_task
//
//! @author 	 vic chen
//
//! @date 		 2016/05/03
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void nb_ublox_send_data_task(UINT8* m_data, UINT16 m_len)
{
    UINT16 i;
    gb_nb_ublox_uart_send_count = m_len;
    for(i=0; i<gb_nb_ublox_uart_send_count; i++)
        gb_nb_ublox_send_buf[i] = *(m_data+i);                
    gb_nb_ublox_uart_send_index = 0;
    gb_nb_ublox_uart_receive_cound = 0;
    NB_UBLOX_UART_TX_ENABLE();  
}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 nb_ublox_send_task
//
//! @author 	 vic chen
//
//! @date 		 2016/05/03
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void nb_ublox_send_ack_task(UINT8 m_id)
{
    UINT16 i;  
    gb_nb_ublox_uart_send_count = sizeof(NB_UBLOX_NET_RECEIVE) - 1;
    for(i=0; i<gb_nb_ublox_uart_send_count; i++)
        gb_nb_ublox_send_buf[i] = NB_UBLOX_NET_RECEIVE[i];       
    gb_nb_ublox_uart_send_index = 0;
    gb_nb_ublox_uart_receive_cound = 0;
    NB_UBLOX_UART_TX_ENABLE();            
}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 nb_ublox_send_task
//
//! @author 	 vic chen
//
//! @date 		 2016/05/03
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
UINT16 nb_ublox_receive_task(UINT8* m_data)
{
    UINT16 i;
    gb_nb_ublox_uart_direction = NB_UBLOX_UART_RECEIVE; //???????e???A
    for(i=0; i<gb_nb_ublox_uart_receive_cound; i++)
        m_data[i] = gb_nb_ublox_receive_buf[i];
    nb_ublox_clear_receive_variable();
    gb_nb_ublox_uart_receive_cound = 0;
    return i;
}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 nb_ublox_error_chenk
//
//! @author 	 vic chen
//
//! @date 		 2016/05/03
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void nb_ublox_error_chenk(INT8* m_data)
{
    if(nb_ublox_string_compare(m_data,"DISCONN"))
    {
        PFC_MQTT_PWR_OFF_INTERVAL();
        NB_UBLOX_STATUS_FLAGE = NB_UBLOX_ERROR;
        return;
    }
    else if(nb_ublox_string_compare(m_data,"ERROR"))
    {
        PFC_MQTT_PWR_OFF_INTERVAL();
        NB_UBLOX_STATUS_FLAGE = NB_UBLOX_ERROR;
        return;
    }
}

#ifdef __cplusplus
}
#endif

