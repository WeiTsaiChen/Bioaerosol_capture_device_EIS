//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 modbus_slave_drv.c
//
//! @author 	 Willman Chen
//
//! @date 		 2009/11/10
//
//  @brief 		 Driver Subroutine
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S
//
//**********************************************************************************************************************
#include "modbus_slave_drv.h"
#include "..\modbus_slave_udef.h"
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 modbus_sfr_init
//
//! @author 	 Willman Chen
//
//! @date 		 2009/10/26
//
//! @brief 		 Register initial function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void modbus_slave_sfr_init()
{
#if MAIN_USE_MODBUS == 1  
    //FK_SET_PIN_OUPUT_PUSH_PUMP_API(FK_PORTA,FK_PIN1);
    MODBUS_SLAVE_DIRECTION_INIT();
    MODBUS_SLAVE_SET_READ_IN_API();
    MODBUS_SLAVE_RESET_TIMEOUT_TIMER_API();
    MODBUS_SLAVE_UART_LOW_SPEED_API();
#if MAIN_LOW_POWER_MODE == 1
    MODBUS_SLAVE_RX_INTERRUPT_ENABLE_API();
#else
    MODBUS_UART_INIT_API(MODBUS_SLAVE_BAUDRATE,MODBUS_SLAVE_BITS,PFC_MODBUS_STOP_BITS,MODBUS_SLAVE_PARITY);
#endif
#endif  
}

