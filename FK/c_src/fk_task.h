#ifndef FK_TASK_H
#define FK_TASK_H
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
//! @file 		 fk_task.h
//
//! @author 	 Willman Chen
//
//! @date 		 2010/10/25
//
//  @brief 		 Here declare task function
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S
//
//**********************************************************************************************************************
#include "..\fk_udef.h"
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
    void		fk_set_io(UINT32 port,UINT32 pin,UINT32 speed,UINT32 mode);
    void		fk_set_io_interrupt(UINT32 port,UINT32 pin,UINT32 mode,void(*func)(void),UINT32 enable);
    UINT32 	    fk_get_crc(UINT32 *data,UINT32 size);
    void 		fk_null(void);
    void 		fk_rtc_enable(UINT32 time);
    UINT32 	    fk_write_flash(UINT32 page,UINT32 *buf,UINT32 size);
    void 		fk_read_flash(UINT32 page,UINT32 *buf,UINT32 size);
    void 		fk_set_rtc_second_func(void(*func)(void));
    void 		fk_watchdog_enable();
    void 		fk_wwatchdog_enable();
    void 		fk_enter_stop_mode();
    void 		fk_dma_enable(UINT8 channel,UINT32 *source,UINT32 *dest,UINT32 size,void(*func)(void));
    void 		fk_nvic_enable(UINT32 irq_channel,UINT32 priority,UINT32 enable);
    void 		fk_nvic_disable(UINT32 irq_channel);
    void 		fk_timer_interrupt_enable(UINT8 timer,UINT32 prescale,UINT32 count,void(*func)(void));
    void 		fk_uart_init(UINT8 comport,UINT32 baudrate,UINT16 bits,UINT16 stop_bits,UINT16 parity,UINT8 mode,UINT8(*tx_func)(void),void(*rx_func)(void));
    void 		fk_adc_functions(UINT32 port,UINT32 pin,UINT8 channel,UINT8 dma_channel,UINT8 func_index,UINT8 func_mode,void (*func)(void),UINT16 *buf,UINT32 size);
    UINT16 	    fk_adc_polling(UINT8 set);
    void 		fk_set_dac(UINT8 channel,UINT32 port,UINT32 pin,UINT8 dma_channel,UINT16 *buf,UINT32 size,UINT32 wave);
    void 		fk_speed_up(void);
    void 		fk_spi_init(UINT8 set,UINT8 dma,UINT8 *buf,UINT32 len);
    void 		fk_i2c_init(UINT8 channel,UINT32 speed);
    void 		fk_timer_capture_enable(UINT8 timer,UINT16 channel,UINT32 port,UINT32 pin,UINT16 edge,void(*func)(void));
    void		fk_pvd_enable(UINT32 voltage,void(*func)(void));
    
    UINT8 	fk_i2c_io_rx_ack();
	void 		fk_i2c_io_tx_ack();
	void 		fk_i2c_io_rx_nanack();
	void 		fk_i2c_io_tx_nanack();
	void 		fk_i2c_io_delay(UINT8);
	void 		fk_i2c_tx_start();
	void 		fk_i2c_tx_stop();
	void 		fk_i2c_tx_byte(UINT8);
	//UINT8	 	fk_i2c_tx_byte();
	UINT8 	fk_i2c_rx_byte(void);
	UINT8 	fk_i2c_master_receive(UINT8 cmd, UINT8* data,  UINT8 length);
	UINT8 	fk_i2c_master_send(UINT8, UINT8*, UINT8);
	UINT8 	fk_i2c1_hw_timeout_check(void);
	void		fk_i2c1_hw_task();
	void  		fk_i2c1_hw_byte_read(UINT8 Addr_Counter,UINT16 Addr_buf[],UINT8 Read_Counter,UINT16 iic_hw_read_buf[]);
	void  		fk_i2c1_hw_byte_write(UINT16 addr,UINT8 counter,UINT16 *data);
	void 		fk_i2c1_hw_check_timeout_func(void);
    void fk_timer_pwm_enable(UINT8 timer,UINT16 channel,UINT32 port,UINT32 pin,UINT32 period,UINT32 pulse);
//**********************************************************************************************************************
//
// C   P L U S   P L U S   C O M P A T I A B L E   D E F I N I T I O N
//
//**********************************************************************************************************************
#ifdef __cplusplus
}
#endif
#endif		// FK_TASK_H 
