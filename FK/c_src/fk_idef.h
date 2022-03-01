#ifndef FK_IDEF_H
#define FK_IDEF_H
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 fk_idef.h
//
//! @author 	 Willman Chen
//
//! @date 		 2010/10/25
//
//  @brief 		 Here define internal constant
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// E X T E R N A L   G L O B A L   C O N S T A N C E   /   V A R I A B L E S   I N   E E P R O M
//
//**********************************************************************************************************************
//! @brief : IO Redeifne
enum
{
    FK_GPIO_PIN_HIGH,
    FK_GPIO_PIN_LOW,
    FK_GPIO_PIN_TOGGLE,
    FK_GPIO_ALL,
};
//! @brief : GPIO Function
enum
{
    FK_GPIO_ADC_TYPE,
    FK_GPIO_IO_TYPE,
    FK_GPIO_ALTERNATE_FUNCTION_TYPE,
    FK_GPIO_TIMER_TYPE,
    FK_GPIO_SPI_TYPE,
    FK_GPIO_I2C_TYPE,
    FK_GPIO_UART_TYPE,
};
//! @brief :
enum
{
    FK_INTERRUPT5_INPUT_CAPTURE,  // TIMER 5
    FK_INTERRUPT1_FUNC_ONCE,      // TIMER 2
    FK_INTERRUPT2_FUNC_ONCE,      // TIMER 3
    FK_INTERRUPT3_FUNC_CONTINUE,  // TIMER 4
    FK_INTERRUPT4_FUNC_CONTINUE,  // TIMER 9
    FK_INTERRUPT_FUNC_TOTAL,
};
//! @brief :
enum
{
    FK_UART1_DEFAULT,
    FK_UART1_REMAP,
    FK_UART2_DEFAULT,
    FK_UART2_REMAP,
    FK_UART3_DEFAULT,
    FK_UART3_REMAP,
    FK_UART_TOTAL,
};
//! @brief :
enum
{
    FK_UART_POLLING_MODE,
    FK_UART_INTERRUPT_MODE,
    FK_UART_DMA_MODE,
    FK_UART_MODE_TOTAL,
};
//! @brief :
enum
{
    FK_ADC_POLLING_FUNC,
    FK_ADC_DMA_FUNC,
    FK_ADC_INTERRUPT_FUNC,
    FK_ADC_DUAL_DMA_FUNC,
    FK_ADC_DUAL_INTERRUPT_FUNC,
};
//! @brief :
enum
{
    FK_ADC_SET1,
    FK_ADC_SET2,
    FK_ADC_SET3,
    FK_ADC_SET_TOTAL,
};
//! @brief :
enum
{
    FK_ADC_SINGLE_MODE,
    FK_ADC_CONTINUOUS_MODE,
    FK_ADC_MODE_TOTAL,
};

//! @brief :
enum
{
    FK_DAC_CHANNEL1,
    FK_DAC_CHANNEL2,
    FK_DAC_TOTAL,
};
//! @brief :
enum
{
    FK_I2C1,
    FK_I2C2,
    FK_I2C_TOTAL,
};
//! @brief :
enum
{
    FK_SPI1,
    FK_SPI2,
    FK_SPI3,
    FK_SPI_TOTAL,
};
//! @brief :
#define FK_DMA_TOTAL							12
#define FK_UART_SETS							3
#define FK_PHERIPH_CLKA                 RCC_APB2Periph_GPIOA
#define FK_PHERIPH_CLKB                 RCC_APB2Periph_GPIOB
#define FK_PHERIPH_CLKC                 RCC_APB2Periph_GPIOC
#define FK_PHERIPH_CLKD                 RCC_APB2Periph_GPIOD
#define FK_PHERIPH_CLKE                 RCC_APB2Periph_GPIOE
#define FK_PHERIPH_CLKF                 RCC_APB2Periph_GPIOF
#define FK_PHERIPH_CLKG                 RCC_APB2Periph_GPIOG

#define FK_PORTSOURCEA                  GPIO_PortSourceGPIOA
#define FK_PORTSOURCEB                  GPIO_PortSourceGPIOB
#define FK_PORTSOURCEC                  GPIO_PortSourceGPIOC
#define FK_PORTSOURCED                  GPIO_PortSourceGPIOD
#define FK_PORTSOURCEE                  GPIO_PortSourceGPIOE
#define FK_PORTSOURCEF                  GPIO_PortSourceGPIOF
#define FK_PORTSOURCEG                  GPIO_PortSourceGPIOG

#define FK_PIN_SOURCE0                  GPIO_PinSource0
#define FK_PIN_SOURCE1                  GPIO_PinSource1
#define FK_PIN_SOURCE2                  GPIO_PinSource2
#define FK_PIN_SOURCE3                  GPIO_PinSource3
#define FK_PIN_SOURCE4                  GPIO_PinSource4
#define FK_PIN_SOURCE5                  GPIO_PinSource5
#define FK_PIN_SOURCE6                  GPIO_PinSource6
#define FK_PIN_SOURCE7                  GPIO_PinSource7
#define FK_PIN_SOURCE8                  GPIO_PinSource8
#define FK_PIN_SOURCE9                  GPIO_PinSource9
#define FK_PIN_SOURCE10                 GPIO_PinSource10
#define FK_PIN_SOURCE11                 GPIO_PinSource11
#define FK_PIN_SOURCE12                 GPIO_PinSource12
#define FK_PIN_SOURCE13                 GPIO_PinSource13
#define FK_PIN_SOURCE14                 GPIO_PinSource14
#define FK_PIN_SOURCE15                 GPIO_PinSource15

#define FK_EXTI0    			EXTI_Line0
#define FK_EXTI1    			EXTI_Line1
#define FK_EXTI2    			EXTI_Line2
#define FK_EXTI3    			EXTI_Line3
#define FK_EXTI4    			EXTI_Line4
#define FK_EXTI5    			EXTI_Line5
#define FK_EXTI6    			EXTI_Line6
#define FK_EXTI7    			EXTI_Line7
#define FK_EXTI8    			EXTI_Line8
#define FK_EXTI9    			EXTI_Line9
#define FK_EXTI10    			EXTI_Line10
#define FK_EXTI11    			EXTI_Line11
#define FK_EXTI12    			EXTI_Line12
#define FK_EXTI13    			EXTI_Line13
#define FK_EXTI14    			EXTI_Line14
#define FK_EXTI15    			EXTI_Line15
#define FK_EXTI_TOTAL                   16

#define FK_EXTI_PVD    		        EXTI_Line16
#define FK_EXTI_RTC    		        EXTI_Line17
#define FK_EXTI_USB    		        EXTI_Line18
#define FK_EXTI_ETHERNET_WAKEUP    	EXTI_Line19

#define FK_EXTI_IRQ0	                EXTI0_IRQn
#define FK_EXTI_IRQ1	                EXTI1_IRQn
#define FK_EXTI_IRQ2	                EXTI2_IRQn
#define FK_EXTI_IRQ3	                EXTI3_IRQn
#define FK_EXTI_IRQ4                    EXTI4_IRQn
#define FK_EXTI_IRQ9_5                  EXTI9_5_IRQn
#define FK_EXTI_IRQ15_10                EXTI15_10_IRQn
#define FK_RTC_DATA_TOTAL               42

#define FK_I2C_SPEED_100K		100000
#define FK_I2C_SPEED_200K		200000
#define	FK_I2C_SPEED_300K		300000
#define	FK_I2C_SPEED_400K		400000


//! @brief what many bits in a byte,it's a good news for us ,we don't need to change it usually.
#define     FK_I2C_IO_BYTE_BITS						8
//! @brief the mask of the most bit in a byte,we shouldn't change it before we die.
#define     FK_I2C_IO_BYTE_BIT7						0x80
//! @brief the mask for making sure read command 
#define     FK_I2C_IO_READ_CMD_MASK				0x01
//! @brief The mask for making sure write command
#define     FK_I2C_IO_WRITE_CMD_MASK			0xFE
//! @brief delay time
#define     FK_I2C_IO_DELAY_TIME					5          // Max: 255

//! @brief the delay for waitting signal from slave
#define     FK_I2C_IO_DELAY_FOR_NACK				5         // Max: 65535
#define     FK_I2C_IO_DELAY_FOR_ACK				5         // Max: 65535
  
enum FK_I2C_STATUS
{
    FK_I2C_FAIL,
    FK_I2C_OK,
};

#define CR1_ACK_Reset										((UINT16)0xFBFF)
#define CR1_STOP_Reset										((UINT16)0xFDFF)
#define CR1_ACK_Set										((UINT16)0x0400)
#define CR1_STOP_Set										((UINT16)0x0200)
#define CR1_POS_Reset										((UINT16)0xF7FF)
#define CR1_POS_Set           								((UINT16)0x0800)

#define FK_I2C1_HW_CLAEN_TIMEOUT_STATUS()			(gb_fk_i2c1_hw_time_out_sw=0,gb_fk_i2c1_hw_time_out_counter=0,gb_fk_i2c1_hw_repeat_flag=0)
#define FK_I2C1_HW_STM32_SYSTEM_ISR_DISABLE()		__disable_irq()			
#define FK_I2C1_HW_STM32_SYSTEM_ISR_ENABLE()		__enable_irq()													
#define FK_I2C1_HW_CHK_STOP_API()							//(while (((I2C1->CR1&0x200) == 0x200))	
#define FK_I2C1_HW_ACK_RESET_API()						(I2C1->CR1 &= CR1_ACK_Reset)	
#define FK_I2C1_HW_SET_POS_BIT_API()						(I2C1->CR1 |= CR1_POS_Set)
#define FK_I2C1_HW_RESET_POS_BIT_API()					(I2C1->CR1  &= CR1_POS_Reset)

#define FK_I2C1_HW_ENABLE_API(I2C_SPEED)				FK_I2C1_ENABLE_API(I2C_SPEED)
#define FK_I2C1_HW_START_API() 		 					FK_I2C1_START_API()
#define FK_I2C1_HW_STOP_API()								FK_I2C1_STOP_API()
#define FK_I2C1_HW_WRITE_API(data)						FK_I2C1_WRITE_API(data)
#define FK_I2C1_HW_READ_API()								FK_I2C1_READ_API()
#define FK_I2C1_HW_CHK_START_API()						FK_I2C1_CHK_START_API()
#define FK_I2C1_HW_CHK_TX_API()		 					FK_I2C1_CHK_TRANSMITTED_API()
#define FK_I2C1_HW_CHK_RX_API()		 					FK_I2C1_CHK_RECEIVED_API()
#define FK_I2C1_HW_CHK_7BITADDR_API()					FK_I2C1_CHK_7BIT_API()
#define FK_I2C1_HW_CHK_ACK_API()							FK_I2C1_CHK_ACK_API()
#define FK_I2C1_HW_SEND7BIT_ADDR(m_addr)				FK_I2C1_SEND7BIT_ADDR(m_addr)
#define FK_I2C1_HW_ACK_ENABLE_API()						FK_I2C1_ACK_ENABLE()
#define FK_I2C1_HW_CLEAR_FLAG_API()						FK_I2C1_CLEAR_AF_FLAG_API()




#define FK_I2C_IO_HAS_DELAY_WITH_EACH_COMMAND                                      			1
  
#define FK_I2C_IO_1_SCL_PORT                         													FK_PORTB
#define FK_I2C_IO_1_SCL_PIN                          													FK_PIN6
#define FK_I2C_IO_1_SCL_INIT()                       													FK_SET_PIN_OUPUT_PUSH_PUMP_API(FK_I2C_IO_1_SCL_PORT,FK_I2C_IO_1_SCL_PIN)
            
#define FK_I2C_IO_1_SDA_PORT                         													FK_PORTB
#define FK_I2C_IO_1_SDA_PIN                          													FK_PIN7
#define FK_I2C_IO_1_SDA_INIT()                       													FK_SET_PIN_OUPUT_PUSH_PUMP_API(FK_I2C_IO_1_SDA_PORT,FK_I2C_IO_1_SDA_PIN)
  
//! @brief Check SDA state is high or low.                             
#define FK_I2C_IO_CHK_SDA_STATE()                    													FK_CHK_PIN_STATE_API(FK_I2C_IO_1_SDA_PORT,FK_I2C_IO_1_SDA_PIN) 
//! @brief Set SDA as output pin                                       
#define FK_I2C_IO_SET_SDA_OUT()                      													FK_SET_PIN_OUPUT_PUSH_PUMP_API(FK_I2C_IO_1_SDA_PORT,FK_I2C_IO_1_SDA_PIN)
//! @brief Set SDA as input pin                                        
#define FK_I2C_IO_SET_SDA_IN()                       													FK_SET_PIN_INPUT_FLOATING_API(FK_I2C_IO_1_SDA_PORT,FK_I2C_IO_1_SDA_PIN)
//! @brief Set SCL as output pin                                       
#define FK_I2C_IO_SET_SCL_OUT()                 											     		FK_SET_PIN_OUPUT_PUSH_PUMP_API(FK_I2C_IO_1_SCL_PORT,FK_I2C_IO_1_SCL_PIN) 
//! @brief Set SCL as input pin                                        
#define FK_I2C_IO_SET_SCL_IN()                       													FK_SET_PIN_INPUT_FLOATING_API(FK_I2C_IO_1_SCL_PORT,FK_I2C_IO_1_SCL_PIN) 
//! @brief Set high SCL pin                         
#define FK_I2C_IO_SCL_H()                            														FK_SET_OUTPUT_PIN_HIGH_API(FK_I2C_IO_1_SCL_PORT,FK_I2C_IO_1_SCL_PIN)
//! @brief Set low SCL pin                                             
#define FK_I2C_IO_SCL_L()                  					          									FK_SET_OUTPUT_PIN_LOW_API(FK_I2C_IO_1_SCL_PORT,FK_I2C_IO_1_SCL_PIN)
//! @brief Set high SDA pin                                            
#define FK_I2C_IO_SDA_H()                           													 	FK_SET_OUTPUT_PIN_HIGH_API(FK_I2C_IO_1_SDA_PORT,FK_I2C_IO_1_SDA_PIN)
//! @brief Set low SDA pin                                             
#define FK_I2C_IO_SDA_L()                            														FK_SET_OUTPUT_PIN_LOW_API(FK_I2C_IO_1_SDA_PORT,FK_I2C_IO_1_SDA_PIN)
//**********************************************************************************************************************
//
// A P I   F O R   O T H E R   M O D U L E S
//
//**********************************************************************************************************************
//**********************************************************************************************************************    
// I2C Function
#define FK_I2C1_ENABLE_API(speed)													fk_i2c_init(FK_I2C1,speed)
#define FK_I2C1_START_API()															I2C_GenerateSTART(I2C1,ENABLE)
#define FK_I2C1_STOP_API()															I2C_GenerateSTOP(I2C1,ENABLE)
#define FK_I2C1_WRITE_API(data)														I2C_SendData(I2C1,data)
#define FK_I2C1_READ_API()															I2C_ReceiveData(I2C1)
#define FK_I2C1_CHK_TRANSMITTED_API()											I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED)
#define FK_I2C1_CHK_RECEIVED_API()													I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_RECEIVED)
#define FK_I2C1_CHK_START_API()													I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT)
#define FK_I2C1_CHK_7BIT_API()														I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED)
#define FK_I2C1_ACK_ENABLE()														I2C_AcknowledgeConfig(I2C1, ENABLE);
#define FK_I2C1_ACK_DISABLE()														I2C_AcknowledgeConfig(I2C1,DISABLE);
#define FK_I2C1_SEND7BIT_ADDR(m_addr)											I2C_Send7bitAddress(I2C1,m_addr,I2C_Direction_Transmitter);
#define FK_I2C1_CHK_ACK_API()														I2C_CheckEvent(I2C1, I2C_EVENT_SLAVE_ACK_FAILURE)
#define FK_I2C1_CLEAR_AF_FLAG_API()												I2C_ClearFlag(I2C1,I2C_FLAG_AF);

#define FK_I2C2_ENABLE_API(speed)													fk_i2c_init(FK_I2C2,speed)
#define FK_I2C2_START_API()															I2C_GenerateSTART(I2C2,ENABLE)
#define FK_I2C2_STOP_API()															I2C_GenerateSTOP(I2C2,ENABLE)
#define FK_I2C2_WRITE_API(data)														I2C_SendData(I2C2,data)
#define FK_I2C2_READ_API()															I2C_ReceiveData(I2C2)
#define FK_I2C2_CHK_TRANSMITTED_API()											I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_BYTE_TRANSMITTED)
#define FK_I2C2_CHK_RECEIVED_API()													I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_BYTE_RECEIVED)
#define FK_I2C2_CHK_START_API()													I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_MODE_SELECT)
#define FK_I2C2_CHK_7BIT_API()														I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED)
#define FK_I2C2_ACK_ENABLE()														I2C_AcknowledgeConfig(I2C2, ENABLE)
#define FK_I2C2_ACK_DISABLE()														I2C_AcknowledgeConfig(I2C2,DISABLE)
#define FK_I2C2_SEND7BIT_ADDR(m_addr)											I2C_Send7bitAddress(I2C2,m_addr,I2C_Direction_Transmitter)
#define FK_I2C2_CHK_ACK_API()														I2C_CheckEvent(I2C2, I2C_EVENT_SLAVE_ACK_FAILURE)
#define FK_I2C2_CLEAR_AF_FLAG_API()												I2C_ClearFlag(I2C2,I2C_FLAG_AF)
#define FK_I2C_TOTAL_ENABLE_API(speed)											fk_i2c_init(FK_I2C_TOTAL,UINT32 speed)

#define	FK_SYS_CONFIG_PLLCLK														0x08
#define	FK_SYS_CONFIG_HSE														0x04
#define	FK_SYS_CONFIG_HSI														0x00


#endif		// FK_IDEF_H 
