//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 ad5941_drv.c
//
//! @author 	 Roger
//
//! @date 		 2021/10
//
//  @brief 		 Driver Subroutine
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S 
//
//**********************************************************************************************************************
#include "ad5941_drv.h" 

/**
  * @brief  Initializes the SWO, SWD interface to deal with the remapping
* @param  None
  * @retval None
  */
void STLINK_Debugger_init()
{
  GPIO_InitTypeDef GPIO_Init_Structure;

  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);

  GPIO_Init_Structure.GPIO_Pin = GPIO_Pin_14;
  GPIO_Init_Structure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init_Structure.GPIO_Mode = GPIO_Mode_AF;         // Recover the SWCLK inside SWD function
  GPIO_Init_Structure.GPIO_OType = GPIO_OType_PP;
  GPIO_Init_Structure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  
  GPIO_Init(GPIOA, &GPIO_Init_Structure);
  
  GPIO_SetBits(GPIOA, GPIO_Pin_14); // RESET = 0;
}

/**
  * @brief  Initializes the SPI interface for EEPROM
  * @param  None
  * @retval None
  */
void spi_params_init()
{
  GPIO_InitTypeDef GPIO_InitStructure;
  SPI_InitTypeDef SPI_Params_InitStruct;
  
  /*!< sEE_CS_GPIO, sEE_MOSI_GPIO, sEE_MISO_GPIO and sEE_SCK_GPIO 
       Periph clock enable */
  RCC_AHBPeriphClockCmd(sEE_SPI_CS_GPIO_CLK | sEE_SPI_MOSI_GPIO_CLK | sEE_SPI_MISO_GPIO_CLK |
                        sEE_SPI_SCK_GPIO_CLK , ENABLE);

  /*!< sEE Periph clock enable */
  RCC_APB2PeriphClockCmd(sEE_SPI_CLK, ENABLE); 
  
  /*!< Configure sEE pins: SCK */
  GPIO_InitStructure.GPIO_Pin = sEE_SPI_SCK_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
  GPIO_Init(sEE_SPI_SCK_GPIO_PORT, &GPIO_InitStructure);

  /*!< Configure sEE_SPI pins: MISO */
  GPIO_InitStructure.GPIO_Pin = sEE_SPI_MISO_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
  GPIO_Init(sEE_SPI_MISO_GPIO_PORT, &GPIO_InitStructure);

  /*!< Configure sEE_SPI pins: MOSI */
  GPIO_InitStructure.GPIO_Pin = sEE_SPI_MOSI_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
  GPIO_Init(sEE_SPI_MOSI_GPIO_PORT, &GPIO_InitStructure);

  /*!< Configure sEE_SPI_CS_PIN pin: sEE_SPI Card CS pin */
  GPIO_InitStructure.GPIO_Pin = sEE_SPI_CS_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
  GPIO_Init(sEE_SPI_CS_GPIO_PORT, &GPIO_InitStructure);

  /* Connect PXx to sEE_SPI_SCK */
  GPIO_PinAFConfig(sEE_SPI_SCK_GPIO_PORT, sEE_SPI_SCK_SOURCE, sEE_SPI_SCK_AF);

  /* Connect PXx to sEE_SPI_MISO */
  GPIO_PinAFConfig(sEE_SPI_MISO_GPIO_PORT, sEE_SPI_MISO_SOURCE, sEE_SPI_MISO_AF); 

  /* Connect PXx to sEE_SPI_MOSI */
  GPIO_PinAFConfig(sEE_SPI_MOSI_GPIO_PORT, sEE_SPI_MOSI_SOURCE, sEE_SPI_MOSI_AF);  
  
  SPI_Params_InitStruct.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_32; // Output speed = System CLK / Prescaler_X
  SPI_Params_InitStruct.SPI_CPHA = SPI_CPHA_1Edge;
  SPI_Params_InitStruct.SPI_CPOL = SPI_CPOL_Low ;
  SPI_Params_InitStruct.SPI_CRCPolynomial = 7; // NOTE
  SPI_Params_InitStruct.SPI_DataSize = SPI_DataSize_8b;
  SPI_Params_InitStruct.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
  SPI_Params_InitStruct.SPI_FirstBit = SPI_FirstBit_MSB;
  SPI_Params_InitStruct.SPI_Mode = SPI_Mode_Master;
  SPI_Params_InitStruct.SPI_NSS = SPI_NSS_Soft;
  
  SPI_Init(SPI1, &SPI_Params_InitStruct);
  
  // SPI Enable
  SPI_Cmd(SPI1, ENABLE);
  
}

//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 NVIC_Configuration
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
//static void NVIC_Configuration(void) {
//    NVIC_InitTypeDef key_nvic;
//
//    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
//
//    key_nvic.NVIC_IRQChannel = EXTI0_IRQn;
//    key_nvic.NVIC_IRQChannelCmd = ENABLE;
//    key_nvic.NVIC_IRQChannelPreemptionPriority = 0;
//    key_nvic.NVIC_IRQChannelSubPriority = 0;
//    NVIC_Init(&key_nvic);
//}

//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 key_exti
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
//void key_exti(void) {
//    GPIO_InitTypeDef key_struct;
//    EXTI_InitTypeDef key_exti_struct;
//
//    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO, ENABLE);
//    NVIC_Configuration();
//
//    key_struct.GPIO_Mode = GPIO_Mode_IPD;   // pull down input
//    key_struct.GPIO_Pin = GPIO_Pin_0;
//    GPIO_Init(GPIOA, &key_struct);
//
//    GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource0);
//    key_exti_struct.EXTI_Line = EXTI_Line0;
//    key_exti_struct.EXTI_Mode = EXTI_Mode_Interrupt;
//    key_exti_struct.EXTI_Trigger = EXTI_Trigger_Falling;
//    key_exti_struct.EXTI_LineCmd = ENABLE;
//    EXTI_Init(&key_exti_struct);
//    
//}

//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 ad5941_sfr_init
//
//! @author 	 Roger
//
//! @date 		 2021/10
//
//! @brief 		 Register initial function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void ad5941_sfr_init()
{
  // AD5941_GPIO0_INIT();  // Interrupt pin
  AD5941_GPIO1_INIT();
  AD5941_GPIO2_INIT();
  AD5941_RESET_INIT();
  // AD5941_CS_INIT();
  // AD5941_SCLK_INIT();
  // AD5941_MISO_INIT();    
  // AD5941_MOSI_INIT();
  
  // SWO, SWD Initialize
  // STLINK_Debugger_init(); // Useless function
  
  // SPI Initialize
  // FLASH_SPI_APBxClock_FUN();
  
  // FK_SPI1_ENABLE_API(NULL, 8);
  
  // HWi initialize - GPIO0, falling to enable
  AD5941_HW_INTERRUPT_INIT();
  
  spi_params_init();
  
  // External hardware interrupt initialization
  // key_exti();

}
