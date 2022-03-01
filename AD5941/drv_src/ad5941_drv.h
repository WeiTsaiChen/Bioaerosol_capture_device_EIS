#ifndef AD5941_DRV_H
#define AD5941_DRV_H
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 ad5941_drv.h
//
//! @author 	 Roger
//
//! @date 		 2021/10
//
//  @brief 		 Here declare driver function
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S 
//
//**********************************************************************************************************************
#include "..\ad5941_udef.h"
//**********************************************************************************************************************
//
// I / O   P O R T   D E F I N I T I O N 
//
//**********************************************************************************************************************
#define AD5941_GPIO0_PORT                   FK_PORTC
#define AD5941_GPIO0_PIN                    FK_PIN5
#define AD5941_GPIO0_LOW()                  FK_SET_OUTPUT_PIN_LOW_API(AD5941_GPIO0_PORT,AD5941_GPIO0_PIN)
#define AD5941_GPIO0_HIGH()                 FK_SET_OUTPUT_PIN_HIGH_API(AD5941_GPIO0_PORT,AD5941_GPIO0_PIN)
#define AD5941_GPIO0_INIT()                 FK_SET_PIN_OUPUT_PUSH_PUMP_API(AD5941_GPIO0_PORT,AD5941_GPIO0_PIN);AD5941_GPIO0_LOW()  
#define AD5941_HW_INTERRUPT_INIT()          FK_SET_FALLING_INTERRUPT_PIN_API(AD5941_GPIO0_PORT, AD5941_GPIO0_PIN, SetucInterrupted)

#define AD5941_GPIO1_PORT                   FK_PORTB
#define AD5941_GPIO1_PIN                    FK_PIN0
#define AD5941_GPIO1_LOW()                  FK_SET_OUTPUT_PIN_LOW_API(AD5941_GPIO1_PORT,AD5941_GPIO1_PIN)
#define AD5941_GPIO1_HIGH()                 FK_SET_OUTPUT_PIN_HIGH_API(AD5941_GPIO1_PORT,AD5941_GPIO1_PIN)
#define AD5941_GPIO1_INIT()                 FK_SET_PIN_OUPUT_PUSH_PUMP_API(AD5941_GPIO1_PORT,AD5941_GPIO1_PIN);AD5941_GPIO1_LOW()  

#define AD5941_GPIO2_PORT                   FK_PORTB
#define AD5941_GPIO2_PIN                    FK_PIN1
#define AD5941_GPIO2_LOW()                  FK_SET_OUTPUT_PIN_LOW_API(AD5941_GPIO2_PORT,AD5941_GPIO2_PIN)
#define AD5941_GPIO2_HIGH()                 FK_SET_OUTPUT_PIN_HIGH_API(AD5941_GPIO2_PORT,AD5941_GPIO2_PIN)
#define AD5941_GPIO2_INIT()                 FK_SET_PIN_OUPUT_PUSH_PUMP_API(AD5941_GPIO2_PORT,AD5941_GPIO2_PIN);AD5941_GPIO2_LOW()  

#define AD5941_RESET_PORT                   FK_PORTC
#define AD5941_RESET_PIN                    FK_PIN4
#define AD5941_RstClr()                     FK_SET_OUTPUT_PIN_LOW_API(AD5941_RESET_PORT,AD5941_RESET_PIN)
#define AD5941_RstSet()                     FK_SET_OUTPUT_PIN_HIGH_API(AD5941_RESET_PORT,AD5941_RESET_PIN)
#define AD5941_RESET_INIT()                 FK_SET_PIN_OUPUT_PUSH_PUMP_API(AD5941_RESET_PORT,AD5941_RESET_PIN);AD5941_RstSet() 

#define AD5941_CS_PORT                      FK_PORTA
#define AD5941_CS_PIN                       FK_PIN4
#define AD5941_CsClr()                      FK_SET_OUTPUT_PIN_LOW_API(AD5941_CS_PORT,AD5941_CS_PIN)
#define AD5941_CsSet()                      FK_SET_OUTPUT_PIN_HIGH_API(AD5941_CS_PORT,AD5941_CS_PIN)
#define AD5941_CS_INIT()                    FK_SET_PIN_OUPUT_PUSH_PUMP_API(AD5941_CS_PORT,AD5941_CS_PIN);AD5941_CsSet() 

#define AD5941_SCLK_PORT                    FK_PORTA
#define AD5941_SCLK_PIN                     FK_PIN5
#define AD5941_SCLK_LOW()                   FK_SET_OUTPUT_PIN_LOW_API(AD5941_SCLK_PORT,AD5941_SCLK_PIN)
#define AD5941_SCLK_HIGH()                  FK_SET_OUTPUT_PIN_HIGH_API(AD5941_SCLK_PORT,AD5941_SCLK_PIN)
#define AD5941_SCLK_INIT()                  FK_SET_PIN_OUPUT_PUSH_PUMP_API(AD5941_SCLK_PORT,AD5941_SCLK_PIN);AD5941_SCLK_HIGH() 

#define AD5941_MISO_PORT                    FK_PORTA
#define AD5941_MISO_PIN                     FK_PIN6
#define AD5941_MISO_GET()                   FK_CHK_PIN_STATE_API(AD5941_MISO_PORT,AD5941_MISO_PIN)
#define AD5941_MISO_INIT()                  FK_SET_PIN_INPUT_FLOATING_API(AD5941_MISO_PORT,AD5941_MISO_PIN);

#define AD5941_MOSI_PORT                    FK_PORTA
#define AD5941_MOSI_PIN                     FK_PIN7
#define AD5941_MOSI_LOW()                   FK_SET_OUTPUT_PIN_LOW_API(AD5941_MOSI_PORT,AD5941_MOSI_PIN)
#define AD5941_MOSI_HIGH()                  FK_SET_OUTPUT_PIN_HIGH_API(AD5941_MOSI_PORT,AD5941_MOSI_PIN)
#define AD5941_MOSI_GET()                   FK_CHK_PIN_STATE_API(AD5941_MOSI_PORT,AD5941_MOSI_PIN)
#define AD5941_MOSI_INIT()                  FK_SET_PIN_OUPUT_PUSH_PUMP_API(AD5941_MOSI_PORT,AD5941_MOSI_PIN);AD5941_MOSI_LOW() 

// SPI Interface pins
#define sEE_SPI                             SPI1
#define sEE_SPI_CLK                         RCC_APB2Periph_SPI1

#define sEE_SPI_SCK_PIN                     GPIO_Pin_5                  /* PA.05 */
#define sEE_SPI_SCK_GPIO_PORT               GPIOA                       /* GPIOA */
#define sEE_SPI_SCK_GPIO_CLK                RCC_AHBPeriph_GPIOA
#define sEE_SPI_SCK_SOURCE                  GPIO_PinSource5
#define sEE_SPI_SCK_AF                      GPIO_AF_SPI1

#define sEE_SPI_MISO_PIN                    GPIO_Pin_6                 /* PE.14 */
#define sEE_SPI_MISO_GPIO_PORT              GPIOA // GPIOE                       
#define sEE_SPI_MISO_GPIO_CLK               RCC_AHBPeriph_GPIOA // RCC_AHBPeriph_GPIOE
#define sEE_SPI_MISO_SOURCE                 GPIO_PinSource6
#define sEE_SPI_MISO_AF                     GPIO_AF_SPI1

#define sEE_SPI_MOSI_PIN                    GPIO_Pin_7                 /* PE.15 */
#define sEE_SPI_MOSI_GPIO_PORT              GPIOA // GPIOE                       
#define sEE_SPI_MOSI_GPIO_CLK               RCC_AHBPeriph_GPIOA // RCC_AHBPeriph_GPIOE
#define sEE_SPI_MOSI_SOURCE                 GPIO_PinSource7
#define sEE_SPI_MOSI_AF                     GPIO_AF_SPI1

#define sEE_SPI_CS_PIN                      GPIO_Pin_4                  /* PC.05 */
#define sEE_SPI_CS_GPIO_PORT                GPIOA // GPIOC                       
#define sEE_SPI_CS_GPIO_CLK                 RCC_AHBPeriph_GPIOA // RCC_AHBPeriph_GPIOC 

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
void ad5941_sfr_init();

void STLINK_Debugger_init(void);
void spi_params_init(void);

static void NVIC_Configuration(void);
void key_exti(void);
#endif		// AD5941_DRV_H 
