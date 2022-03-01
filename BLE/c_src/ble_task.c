//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 ble_task.c
//
//! @author 	 Roger
//
//! @date 		 2021/10
//
//  @brief 		 Task Subroutine
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S 
//
//**********************************************************************************************************************
#include "../drv_src/ble_drv.h" 
#include "ble_glb_vars.h"
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 ble_task
//
//! @author 	 Roger
//
//! @date 		 2021/10
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	     ble_write_multi_register
//
//! @author 	 Willman Chen
//
//! @date 		 2009/10/26
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void ble_write_multi_register()
{
    UINT16 register_addr,i;
    UINT16 register_value;
    UINT8  check=0,check2=BLE_EXCEPTION_CODE_ILLEGAL_DATA_ADDRESS,type=0;
    STC_BLE_READ_WRITE_REGISTER_PACKAGE *cmd=(STC_BLE_READ_WRITE_REGISTER_PACKAGE *)&gb_ble_buffer[BLE_BYTE_NAME_ADDRESS];
    register_addr=(cmd->register_address_h<<BLE_BYTE_BITS)|(cmd->register_address_l);
    register_value=(cmd->register_value_h<<BLE_BYTE_BITS)|(cmd->register_value_l);
    
    if (register_addr<BLE_DDF_START_ADDRESS && register_addr>=BLE_READ_WRITE_START_ADDRESS && register_addr+register_value<=BLE_DDF_START_ADDRESS)
    {
      check=1;
      type=1;
    }
    if (register_addr>=BLE_READWRITE_REMAP_ADDRESS && register_addr<BLE_READWRITE_REMAP_ADDRESS+BLE_READ_WRITE_NUM && register_addr+register_value<BLE_READWRITE_REMAP_ADDRESS+BLE_READ_WRITE_NUM)
    {
      check=1;
      type=2;
    }

    if (register_value==0)
        check=0;

    if (check==0)
    {
        if (register_addr<BLE_DDF_START_ADDRESS && register_addr>=BLE_READ_WRITE_START_ADDRESS)
            check2=BLE_EXCEPTION_CODE_ILLEGAL_DATA_VALUE;
        if (register_addr>=BLE_READWRITE_REMAP_ADDRESS && register_addr<BLE_READWRITE_REMAP_ADDRESS+BLE_READ_WRITE_NUM )
            check2=BLE_EXCEPTION_CODE_ILLEGAL_DATA_VALUE;
        if (register_value==0)
            check2=BLE_EXCEPTION_CODE_ILLEGAL_DATA_VALUE;

        if (check2==BLE_EXCEPTION_CODE_ILLEGAL_DATA_ADDRESS)
        {
          gs_ble_error_package.error_code=BLE_ERROR_CODE_MASK|(cmd->function_code);
          gs_ble_error_package.exception_code=BLE_EXCEPTION_CODE_ILLEGAL_DATA_ADDRESS;
        }
        else 
        {
          gs_ble_error_package.error_code=BLE_ERROR_CODE_MASK|(cmd->function_code);
          gs_ble_error_package.exception_code=BLE_EXCEPTION_CODE_ILLEGAL_DATA_VALUE;
        }
    }

    // after all check tasks , we need to fill something they want.
    if (gs_ble_error_package.error_code==0)
    {
        UINT16 start_addr;
        UINT16 data_value;
        UINT8 *data_ptr;
        UINT8  high_byte,low_byte,byte_count;
        // get the address and value
        STC_BLE_WRITE_MULTI_REGISTER_CMD_PACKAGE *ptr=(STC_BLE_WRITE_MULTI_REGISTER_CMD_PACKAGE *)&gb_ble_buffer[BLE_BYTE_NAME_ADDRESS];
        start_addr=(ptr->register_address_h<<BLE_BYTE_BITS)|(ptr->register_address_l);
        if (type==1)
            start_addr-=BLE_READ_WRITE_START_ADDRESS;
        else
            start_addr-=BLE_READWRITE_REMAP_ADDRESS;
        data_value=(ptr->register_value_h<<BLE_BYTE_BITS)|(ptr->register_value_l);
        // action
        for (i=0; i<data_value; i++)
        {
            data_ptr=(UINT8*)gt_ble_read_write[start_addr+i];
            high_byte=*((UINT8*)&ptr->data+2*i);
            low_byte=*((UINT8*)&ptr->data+2*i+1);
            *(data_ptr)=low_byte;
            *(data_ptr+1)=high_byte;
        }
        // fill response value
        STC_BLE_WRITE_MULTI_REGISTER_RESPONSE_PACKAGE *response=(STC_BLE_WRITE_MULTI_REGISTER_RESPONSE_PACKAGE*)&gb_ble_buffer[BLE_BYTE_NAME_ADDRESS];
        response->function_code=gs_ble_package_ptr->id_code;
        response->register_address_h=(register_addr&BLE_HIGH_BYTE_MASK)>>BLE_BYTE_BITS;
        response->register_address_l=(register_addr&BLE_LOW_BYTE_MASK);
        byte_count=data_value/gs_ble_package_ptr->return_byte_cnt;
        response->byte_count_h=(byte_count&BLE_HIGH_BYTE_MASK)>>BLE_BYTE_BITS;
        response->byte_count_l=(byte_count&BLE_LOW_BYTE_MASK);
        gb_ble_response_length=sizeof(STC_BLE_WRITE_MULTI_REGISTER_RESPONSE_PACKAGE);
    }
}

//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	     ble_write_variable_value
//
//! @author 	 Willman Chen
//
//! @date 		 2009/10/26
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
UINT8 ble_write_variable_value(UINT16 register_addr,UINT16 value)
{
    UINT16 *data_ptr;
    if (register_addr>=BLE_DDF_START_ADDRESS || register_addr<BLE_READ_WRITE_START_ADDRESS)
       return 0;
    data_ptr=(UINT16*)gt_ble_read_write[register_addr-BLE_READ_WRITE_START_ADDRESS];
    *(data_ptr)=value;
    return 1;
}

//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	     ble_write_single_register
//
//! @author 	 Willman Chen
//
//! @date 		 2009/10/26
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void ble_write_single_register()
{
    UINT16 register_addr;
    UINT8  check=0,type=0;
    STC_BLE_READ_WRITE_REGISTER_PACKAGE *cmd=(STC_BLE_READ_WRITE_REGISTER_PACKAGE *)&gb_ble_buffer[BLE_BYTE_NAME_ADDRESS];
    register_addr=(cmd->register_address_h<<BLE_BYTE_BITS)|(cmd->register_address_l);

    if (register_addr<BLE_DDF_START_ADDRESS && register_addr>=BLE_READ_WRITE_START_ADDRESS)
    {
       check=1;
       type=1;
    }
    if (register_addr>=BLE_READWRITE_REMAP_ADDRESS && register_addr<BLE_READWRITE_REMAP_ADDRESS+BLE_READ_WRITE_NUM)
    {
       check=1;
       type=2;
    }

    if (check==0)
    {
        gs_ble_error_package.error_code=BLE_ERROR_CODE_MASK|(cmd->function_code);
        gs_ble_error_package.exception_code=BLE_EXCEPTION_CODE_ILLEGAL_DATA_ADDRESS;
    }

    // after all check tasks , we need to fill something they want.
    if (gs_ble_error_package.error_code==0)
    {
        UINT16 *data_ptr;
        // get the address and value
        STC_BLE_READ_WRITE_REGISTER_PACKAGE *ptr=(STC_BLE_READ_WRITE_REGISTER_PACKAGE *)&gb_ble_buffer[BLE_BYTE_NAME_ADDRESS];
        // we don't fill response value,'cause the response is same as command code
        if (type==1)
            data_ptr=(UINT16*)gt_ble_read_write[register_addr-BLE_READ_WRITE_START_ADDRESS];
        else
            data_ptr=(UINT16*)gt_ble_read_write[register_addr-BLE_READWRITE_REMAP_ADDRESS];
        *(data_ptr)=(ptr->register_value_h<<BLE_BYTE_BITS)|(ptr->register_value_l);
        gb_ble_response_length=sizeof(STC_BLE_READ_WRITE_REGISTER_PACKAGE);
    }
}
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 ble_get_variable_pointer
//
//! @author 	 Willman Chen
//
//! @date 	 2009/10/26
//
//! @brief 	 task function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
UINT16* ble_get_variable_pointer(UINT16 register_addr)
{
    UINT16 *data_ptr;
    if (register_addr>=BLE_HEADER_START_ADDRESS && register_addr<BLE_READONLY_START_ADDRESS)
    {
        data_ptr=(UINT16*)gt_ble_header[register_addr-BLE_HEADER_START_ADDRESS];
    }
    else if (register_addr>=BLE_READONLY_START_ADDRESS && register_addr<BLE_READ_WRITE_START_ADDRESS)
    {
        data_ptr=(UINT16*)gt_ble_readonly[register_addr-BLE_READONLY_START_ADDRESS];
    }
   else if (register_addr>=BLE_READ_WRITE_START_ADDRESS && register_addr<BLE_DDF_START_ADDRESS)
   {
        data_ptr=(UINT16*)gt_ble_read_write[register_addr-BLE_READ_WRITE_START_ADDRESS];
   }
   else if (register_addr>=BLE_DDF_START_ADDRESS && register_addr<BLE_LAST_ADDRESS)
   {
        data_ptr=(UINT16*)&gt_ble_ddf_file[register_addr-BLE_DDF_START_ADDRESS];
   }
   return data_ptr;
}
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	     ble_read_input_registers
//
//! @author 	 Willman Chen
//
//! @date 		 2009/10/26
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void ble_read_input_registers()
{
    UINT16  i;
    INT32 register_addr;
    UINT16 register_value;
    UINT8 check=0,type=0,check2=0;
    STC_BLE_READ_WRITE_REGISTER_PACKAGE *cmd=(STC_BLE_READ_WRITE_REGISTER_PACKAGE *)&gb_ble_buffer[BLE_BYTE_NAME_ADDRESS];
    register_addr=(cmd->register_address_h<<BLE_BYTE_BITS)|(cmd->register_address_l);
    if (register_addr < BLE_LAST_ADDRESS && register_addr>=BLE_HEADER_START_ADDRESS)
    {
      check=1;
      type=1;
    }
    if (register_addr>=BLE_READONLY_REMAP_ADDRESS && register_addr<BLE_READONLY_REMAP_ADDRESS+BLE_READONLY_NUM)
    {
      check=1;
      type=2;
    }
    if (register_addr >=BLE_READWRITE_REMAP_ADDRESS && register_addr<BLE_READWRITE_REMAP_ADDRESS+BLE_READ_WRITE_NUM)
    {
      check=1;
      type=3;
    }
    if (BLE_READONLY_REMAP_ADDRESS+BLE_READONLY_NUM==BLE_READWRITE_REMAP_ADDRESS)
    {
        if (register_addr>=BLE_READONLY_REMAP_ADDRESS && register_addr<BLE_READWRITE_REMAP_ADDRESS+BLE_READ_WRITE_NUM)
        {
          check=1;
          type=4;
        }
    }

    if (check==0)
    {
        gs_ble_error_package.error_code=BLE_ERROR_CODE_MASK|(cmd->function_code);
        gs_ble_error_package.exception_code=BLE_EXCEPTION_CODE_ILLEGAL_DATA_ADDRESS;
    }

    register_value=(cmd->register_value_h<<BLE_BYTE_BITS)|(cmd->register_value_l);
    if (check==1)
    {
        if (type==1 && register_value+register_addr>BLE_LAST_ADDRESS)
            check2=1;
        if (type==2 && register_value+register_addr>BLE_READONLY_REMAP_ADDRESS+BLE_READONLY_NUM)
            check2=1;
        if (type==3 && register_value+register_addr>BLE_READWRITE_REMAP_ADDRESS+BLE_READ_WRITE_NUM)
            check2=1;
        if (type==4 && register_value+register_addr>BLE_READWRITE_REMAP_ADDRESS+BLE_READ_WRITE_NUM)
            check2=1;
        if (register_value==0 || check2==1)
        {
            gs_ble_error_package.error_code=BLE_ERROR_CODE_MASK|(cmd->function_code);
            gs_ble_error_package.exception_code=BLE_EXCEPTION_CODE_ILLEGAL_DATA_VALUE;
        }
    }
    // after all check tasks , we need to fill something they want.
    if (gs_ble_error_package.error_code==0)
    {
        UINT16 data_length;
        UINT16 *data_ptr;
        UINT8  high_byte,low_byte;
        // get the address and value
        STC_BLE_READ_WRITE_REGISTER_PACKAGE *ptr=(STC_BLE_READ_WRITE_REGISTER_PACKAGE *)&gb_ble_buffer[BLE_BYTE_NAME_ADDRESS];
        data_length=(ptr->register_value_h<<BLE_BYTE_BITS)|(ptr->register_value_l);
        // fill response value
        STC_BLE_RESPONSE_READ_HOLDING_REGISTER_PACKAGE *response=(STC_BLE_RESPONSE_READ_HOLDING_REGISTER_PACKAGE *)&gb_ble_buffer[BLE_BYTE_NAME_ADDRESS];
        response->function_code=gs_ble_package_ptr->id_code;
        response->byte_count=gs_ble_package_ptr->return_byte_cnt*data_length;
        for (i=0; i<data_length; i++)
        {
            if (register_addr+i>=BLE_HEADER_START_ADDRESS && register_addr+i<BLE_READONLY_START_ADDRESS)
            {
                data_ptr=(UINT16*)gt_ble_header[register_addr-BLE_HEADER_START_ADDRESS+i];
            }
            else if (register_addr+i>=BLE_READONLY_START_ADDRESS && register_addr+i<BLE_READ_WRITE_START_ADDRESS)
            {
                data_ptr=(UINT16*)gt_ble_readonly[register_addr-BLE_READONLY_START_ADDRESS+i]; 
            }
            else if (register_addr+i>=BLE_READONLY_REMAP_ADDRESS && register_addr+i<BLE_READONLY_REMAP_ADDRESS+BLE_READONLY_NUM)
            {
                data_ptr=(UINT16*)gt_ble_readonly[register_addr-BLE_READONLY_REMAP_ADDRESS+i]; 
            }
            else if (register_addr+i>=BLE_READ_WRITE_START_ADDRESS && register_addr+i<BLE_DDF_START_ADDRESS)
            {
                data_ptr=(UINT16*)gt_ble_read_write[register_addr-BLE_READ_WRITE_START_ADDRESS+i];
            }
            else if (register_addr+i>=BLE_READWRITE_REMAP_ADDRESS && register_addr+i<BLE_READWRITE_REMAP_ADDRESS+BLE_READ_WRITE_NUM)
            {
                data_ptr=(UINT16*)gt_ble_read_write[register_addr-BLE_READWRITE_REMAP_ADDRESS+i];
            }
            else if (register_addr+i>=BLE_DDF_START_ADDRESS && register_addr+i<BLE_LAST_ADDRESS)
            {
                data_ptr=(UINT16*)&gt_ble_ddf_file[register_addr-BLE_DDF_START_ADDRESS+i];
            }

            high_byte=(*(data_ptr)&BLE_HIGH_BYTE_MASK)>>BLE_BYTE_BITS;
            low_byte=(*(data_ptr)&BLE_LOW_BYTE_MASK);
            *((UINT8*)&response->data+2*i)=high_byte;
            *((UINT8*)&response->data+2*i+1)=low_byte;
        }
        gb_ble_response_length=sizeof(STC_BLE_RESPONSE_READ_HOLDING_REGISTER_PACKAGE)+response->byte_count+BLE_CRC_LEN-1;
    }
}

//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	     ble_receiving_and_checking
//
//! @author 	 Willman Chen
//
//! @date 		 2009/10/26
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void ble_receiving_and_checking()
{
    UINT8 byte_value;
    // we don't want do anything as we are not on "STOP" or "RECEIVING".
    BLE_RESET_TIMEOUT_TIMER_API();
    byte_value=BLE_RECEIVE_API();
    if (gb_ble_state!=BLE_STATE_RECEIVING_AND_CHECKING && gb_ble_state!=BLE_STATE_STOP)
        return ;

    if (BLE_MODE==BLE_RTU_MODE)
	{
		gb_ble_ptr %= BLE_MAX_BUFFER_SIZE;
        gb_ble_buffer[gb_ble_ptr++]=byte_value;
	}

    if (BLE_MODE==BLE_ASCII_MODE)
    {
        // byte code transform
        UINT8 char_value=BLE_ASCII_NULL_VALUE;
        if (byte_value>=BLE_ASCII_ZERO_CHAR && byte_value<=BLE_ASCII_NINE_CHAR)
            char_value=byte_value-BLE_ASCII_ZERO_CHAR;
        if (byte_value>=BLE_ASCII_A_CHAR && byte_value<=BLE_ASCII_F_CHAR)
            char_value=byte_value-BLE_ASCII_A_CHAR+BLE_HEX_A;
        if (byte_value==BLE_ASCII_START_CHAR)
            char_value=BLE_ASCII_START_CHAR;

        // present for ':' and error char code
        if (byte_value==BLE_ASCII_START_CHAR || char_value==BLE_ASCII_NULL_VALUE)
            gb_ble_char_ptr=0;
        if (char_value==BLE_ASCII_NULL_VALUE)
            return ;

        switch (gb_ble_char_ptr++)
        {
        case 0:
        {
            if (byte_value==BLE_ASCII_START_CHAR)
            {
                gb_ble_char_ptr++;
                gb_ble_ptr=0;
            }
            return ;
        }
        default:
        {
            UINT8 low_byte=(gb_ble_char_ptr-1)%2;
            if (low_byte==1)
            {
                gb_ble_buffer[gb_ble_ptr++]|=char_value;
                byte_value=gb_ble_buffer[gb_ble_ptr-1];
            }
            else
            {
                gb_ble_buffer[gb_ble_ptr]=(char_value<<BLE_HALF_BYTE_BITS);
                return ;
            }
        }
        }
    } //  if (gs_ble_status.modbus_mode==BLE_ASCII_MODE)
    switch (gb_ble_ptr-1)
    {
    case BLE_BYTE_NAME_ADDRESS:
    {
        if (gb_ble_buffer[BLE_BYTE_NAME_ADDRESS]!=BLE_ID)
        {
            gb_ble_state=BLE_STATE_BACK_TO_STOP;
        }
        else
        {
            gb_ble_state=BLE_STATE_RECEIVING_AND_CHECKING;
            gs_ble_package_ptr=(STC_BLE_COMMAND_INFO*)&gt_ble_valid_function[BLE_BYTE_NAME_ADDRESS];
        }
        break;
    }
    case BLE_BYTE_NAME_FUNCTION_BYTE:
    {
        if (byte_value>=BLE_MAX_COMMAND || (gs_ble_package_ptr+byte_value)->supported==BLE_SUPPORTED_CMD_NO)
        {
            gs_ble_error_package.error_code=BLE_ERROR_CODE_MASK|byte_value;
            gs_ble_error_package.exception_code=BLE_EXCEPTION_CODE_ILLEGAL_FUNCTION;
        }
        else
        {
            gs_ble_package_ptr+=byte_value;
        }
        break;
    }
    default:
        break;
    }
}

//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	     ble_sending
//
//! @author 	 Willman Chen
//
//! @date 		 2009/10/26
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
UINT8 ble_sending()
{
    if (gb_ble_state==BLE_STATE_SENDING)
    {
        if (BLE_MODE==BLE_RTU_MODE)
        {
            if (gb_ble_ptr!=gb_ble_response_length )
            {
                BLE_SEND_OUT_API(gb_ble_buffer[gb_ble_ptr++]);
                BLE_RESET_TIMEOUT_TIMER_API();
                return 1;
            }
            if (gb_ble_ptr==gb_ble_response_length)
            {
                BLE_RESET_TIMEOUT_TIMER_API();
                gb_ble_state=BLE_STATE_BACK_TO_STOP;
            }
        }
        else
        {
            UINT8 char_value;
            UINT8 value,return_value=1;
            if (gb_ble_ptr<gb_ble_response_length)
            {
                if (gb_ble_char_ptr==0)
                {
                    char_value=BLE_ASCII_START_CHAR;
                }
                else
                {
                    value=gb_ble_buffer[gb_ble_ptr];
                    if (((gb_ble_char_ptr-1)%2)==1)
                    {
                        value=(value&BLE_LOW_FOUR_BITS);
                        gb_ble_ptr++;
                    }
                    else
                    {
                        value=(value&BLE_HIGH_FOUR_BITS)>>BLE_HALF_BYTE_BITS;
                    }
                    if (value<=BLE_HEX_9)
                        char_value=value+BLE_ASCII_ZERO_CHAR;
                    if (value>=BLE_HEX_A && value<=BLE_HEX_F)
                        char_value=value+BLE_ASCII_A_CHAR-BLE_HEX_TEN;
                }
            }
            else // sending CR & LF
            {
                if (((gb_ble_char_ptr-1)%2)==1)
                {
                    char_value=BLE_LF_CODE;
                    gb_ble_state=BLE_STATE_BACK_TO_STOP;
                    return_value=0;
                }
                else
                {
                    char_value=BLE_CR_CODE;
                }
            } // if (gb_ble_ptr<gb_ble_response_length)
            gb_ble_char_ptr++;
            BLE_SEND_OUT_API(char_value);
            BLE_RESET_TIMEOUT_TIMER_API();
            return return_value;
        } // if (gs_ble_status.modbus_mode==BLE_RTU_MODE)
    } // if (gs_ble_status.state==BLE_STATE_SENDING)
    return 0;
}
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	     ble_null_func
//
//! @author 	 Willman Chen
//
//! @date 		 2009/10/26
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void ble_null_func()
{
  
}

//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 ble_null_func
//
//! @author 	 Willman Chen
//
//! @date        2009/10/26
//
//! @brief 	 task function
//
//! @param       None
//
//! @return 	 None
//
//**********************************************************************************************************************
#if MAIN_LOW_POWER_MODE == 1
void ble_disable_rx()
{
    BLE_UART_HIGH_SPEED_API();
    BLE_SPEED_UP_API();
    BLE_RX_INTERRUPT_DISABLE_API();
    BLE_RESET_TIMEOUT_TIMER_API();
    BLE_UART_INIT_API(BLE_BAUDRATE,BLE_BITS,PFC_MODBUS_STOP_BITS,BLE_PARITY);
}
#endif
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 ble_go_back_stop
//
//! @author 	 Willman Chen
//
//! @date 	 2009/10/26
//
//! @brief 	 timer isr
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void ble_go_back_stop(void)
{
#if MAIN_LOW_POWER_MODE == 1
    BLE_UART_DISABLE_API();
#endif
    BLE_INIT_API();
    BLE_UART_LOW_SPEED_API();
}
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 ble_timeout_isr
//
//! @author 	 Willman Chen
//
//! @date 	 2009/10/26
//
//! @brief 	 timer isr
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void ble_timeout_isr(void)
{
    UINT8 check_pass=0,lrc,i;
    UINT16 crc;
    if (gb_ble_state!=BLE_STATE_RECEIVING_AND_CHECKING&&gb_ble_state!=BLE_STATE_BACK_TO_STOP)
        return ;
    switch (gb_ble_state)
    {
    case BLE_STATE_RECEIVING_AND_CHECKING:
    {
        if (BLE_MODE==BLE_RTU_MODE)
        {
            // check CRC
            UINT32 crc,hi_byte,low_byte;
            crc=BLE_CRC_CODE_API(gb_ble_buffer,gb_ble_ptr-BLE_CRC_LEN);
            hi_byte=(crc&BLE_HIGH_BYTE_MASK)>>BLE_BYTE_BITS;
            low_byte=crc&BLE_LOW_BYTE_MASK;
            // crc pass
            if (hi_byte==gb_ble_buffer[gb_ble_ptr-BLE_CRC_HI_BYTE_POS] && low_byte==gb_ble_buffer[gb_ble_ptr-BLE_CRC_LOW_BYTE_POS])
                check_pass=1;
        }
        else // ASCII Mode
        {
            // check LRC
            UINT8 lrc=0x00;
            UINT8 i;
            for (i=0; i<gb_ble_ptr; i++)
                lrc+=gb_ble_buffer[i];
            if (lrc==0)
                check_pass=1;
        }
        if (check_pass==1)
        {
            gb_ble_state=BLE_STATE_ACTION;
            if (gs_ble_error_package.error_code==0)
                gs_ble_package_ptr->action();
            if (gs_ble_error_package.error_code!=0)
            {
                UINT8 *ptr=(UINT8*)&gs_ble_error_package;
                UINT8 i;
                for (i=0; i<BLE_ERROR_PACKAGE_LEN; i++)
                    gb_ble_buffer[i]=*(ptr+i);
                gb_ble_response_length=BLE_ERROR_PACKAGE_LEN;
            }
            // fill PDU's fields
            gb_ble_buffer[BLE_BYTE_NAME_ADDRESS]=BLE_ID;
            if (BLE_MODE==BLE_RTU_MODE)
            {
                // CRC
                crc=BLE_CRC_CODE_API(gb_ble_buffer,gb_ble_response_length-BLE_CRC_LEN);
                gb_ble_buffer[gb_ble_response_length-BLE_CRC_HI_BYTE_POS]=(crc&BLE_HIGH_BYTE_MASK)>>BLE_BYTE_BITS;
                gb_ble_buffer[gb_ble_response_length-BLE_CRC_LOW_BYTE_POS]=crc&BLE_LOW_BYTE_MASK;
            }
            else // ASCII Mode
            {
                // 'cause we uses LRC (1 byte) instead of CRC ( 2 bytes )
                gb_ble_response_length--;
                lrc=0x00;
                for (i=0; i<gb_ble_response_length-1; i++)
                    lrc+=gb_ble_buffer[i];
                // making LRC code
                lrc=(~lrc)+1;
                gb_ble_buffer[gb_ble_response_length-1]=lrc;
                gb_ble_char_ptr=0;
            } // if (gs_ble_status.modbus_mode==BLE_RTU_MODE)
            gb_ble_state=BLE_STATE_RESPONSE;
            gb_ble_ptr=0;
            gb_ble_state=BLE_STATE_SENDING;
            BLE_SET_WRITE_OUT_API();
            if (BLE_MODE==BLE_RTU_MODE)
            {
                BLE_START_TX_API();
            }
            else
            {
                BLE_SEND_OUT_API(BLE_ASCII_START_CHAR);
                gb_ble_char_ptr++;
            }
            BLE_RESET_TIMEOUT_TIMER_API();
        }
        else	// crc or lrc fail
        {
            ble_go_back_stop();
        }
        break;
    }
    case BLE_STATE_SENDING:
    case BLE_STATE_BACK_TO_STOP:
        ble_go_back_stop();
        break;
    default:
        break;
    }
    return ;
}
