#ifndef FK_UART_UDEF_H
#define FK_UART_UDEF_H
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
// E X T E R N A L   G L O B A L   C O N S T A N C E   /   V A R I A B L E S   I N   E E P R O M
//
//**********************************************************************************************************************
#define FK_UART_8BITS_MODE                            USART_WordLength_8b
#define FK_UART_9BITS_MODE                            USART_WordLength_9b
#define FK_UART_ONE_STOP_BIT                          USART_StopBits_1
#define FK_UART_TWO_STOP_BITS                         USART_StopBits_2
#define FK_UART_PARITY_NONE                           USART_Parity_No
#define FK_UART_PARITY_EVEN                           USART_Parity_Even
#define FK_UART_PARITY_ODD                            USART_Parity_Odd
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S
//
//**********************************************************************************************************************
#include "..\main.h"
#include "stm32l1xx.h"
#include "c_src\fk_idef.h"
#include "c_src\fk_init.h"
#include "c_src\fk_task.h"
#include "c_src\fk_glb_vars.h" 
//**********************************************************************************************************************
//
// C O N D I C T I O N   C O M P I L E
//
//**********************************************************************************************************************
// UART1  -------->  TX: PA.9   RX: PA.10
// UART1  Remap -->  TX: PB.6   RX: PB.7
// UART2  -------->  TX: PD.5   RX: PD.6
// UART2  Remap -->  TX: PA.2   RX: PA.3
// UART3  -------->  TX: PD.8   RX: PD.9
// UART3  Remap -->  TX: PB.10  RX: PB.11
//**********************************************************************************************************************
//
// A P I   F O R   O T H E R   M O D U L E S
//
//**********************************************************************************************************************
//**It is commonly used function*//
// UART Function
//! @brief Initial default UART1 function as interrupt mode
#define FK_UART1_INTERRUPT_API(baudrate,bits,stop_bits,parity,tx_func,rx_func)        fk_uart_init(FK_UART1_DEFAULT,baudrate,bits,stop_bits,parity,FK_UART_INTERRUPT_MODE,tx_func,rx_func)
  //! @brief Initial default UART1 function as polling mode
#define FK_UART1_POLLING_API(baudrate,bits,stop_bits,parity)                          fk_uart_init(FK_UART1_DEFAULT,baudrate,bits,stop_bits,parity,FK_UART_POLLING_MODE,(UINT8(*)())fk_null,fk_null)  
//! @brief The API for Sending out data by default UART1 pins
#define FK_UART1_SEND_BYTE_API(byte)                                                  USART_SendData((USART_TypeDef*)gt_fk_uart_name[FK_UART1_DEFAULT],byte)
//! @brief The API for UART1 Receving data
#define FK_UART1_GET_DATA_API()                                                       USART_ReceiveData(USART1)
//! @brief The API for starting UART1 transfer interrupt
#define FK_UART1_TX_INTERRUPT_ENABLE_API()                                            USART_ITConfig((USART_TypeDef*)gt_fk_uart_name[FK_UART1_DEFAULT], USART_IT_TXE, ENABLE)
//! @brief The API for stoping UART1 transfer interrupt
#define FK_UART1_TX_INTERRUPT_DISABLE_API()                                           USART_ITConfig((USART_TypeDef*)gt_fk_uart_name[FK_UART1_DEFAULT], USART_IT_TXE, DISABLE)
//! @brief The API for UART2 waitting send out finish
#define FK_UART1_TX_WAIT_API()                                                        while(USART_GetFlagStatus(USART1,USART_FLAG_TC)==RESET)

//! @brief Initial default UART2 function as interrupt mode
#define FK_UART2_INTERRUPT_API(baudrate,bits,stop_bits,parity,tx_func,rx_func)        fk_uart_init(FK_UART2_DEFAULT,baudrate,bits,stop_bits,parity,FK_UART_INTERRUPT_MODE,(UINT8(*)())tx_func,rx_func)
  //! @brief Initial default UART2 function as polling mode
#define FK_UART2_POLLING_API(baudrate,bits,stop_bits,parity)                          fk_uart_init(FK_UART2_DEFAULT,baudrate,bits,stop_bits,parity,FK_UART_POLLING_MODE,(UINT8(*)())fk_null,fk_null)
//! @brief Sending out data by default UART2 pins
#define FK_UART2_SEND_BYTE_API(byte)                                                  USART_SendData((USART_TypeDef*)gt_fk_uart_name[FK_UART2_DEFAULT],byte)
//! @brief The API for UART2 Receving data
#define FK_UART2_GET_DATA_API()                                                       USART_ReceiveData(USART2)
//! @brief The API for starting UART1 transfer interrupt
#define FK_UART2_TX_INTERRUPT_ENABLE_API()                                            USART_ITConfig((USART_TypeDef*)gt_fk_uart_name[FK_UART2_DEFAULT], USART_IT_TXE, ENABLE)
//! @brief The API for stoping UART1 transfer interrupt
#define FK_UART2_TX_INTERRUPT_DISABLE_API()                                           USART_ITConfig((USART_TypeDef*)gt_fk_uart_name[FK_UART2_DEFAULT], USART_IT_TXE, DISABLE)
//! @brief The API for UART2 waitting send out finish
#define FK_UART2_TX_WAIT_API()                                                        while(USART_GetFlagStatus(USART2,USART_FLAG_TC)==RESET)

  //! @brief Initial default UART3 function as interrupt mode
#define FK_UART3_INTERRUPT_API(baudrate,bits,stop_bits,parity,tx_func,rx_func)        fk_uart_init(FK_UART3_DEFAULT,baudrate,bits,stop_bits,parity,FK_UART_INTERRUPT_MODE,(UINT8(*)())tx_func,rx_func)
  //! @brief Initial default UART3 function as polling mode
#define FK_UART3_POLLING_API(baudrate,bits,stop_bits,parity)                          fk_uart_init(FK_UART3_DEFAULT,baudrate,bits,stop_bits,parity,FK_UART_POLLING_MODE,(UINT8(*)())fk_null,fk_null)
//! @brief Sending out data by default UART3 pins
#define FK_UART3_SEND_BYTE_API(byte)                                                  USART_SendData((USART_TypeDef*)gt_fk_uart_name[FK_UART3_DEFAULT],byte)
//! @brief The API for UART3 Receving data
#define FK_UART3_GET_DATA_API()                                                       USART_ReceiveData(USART3)
//! @brief The API for starting UART1 transfer interrupt
#define FK_UART3_TX_INTERRUPT_ENABLE_API()                                            USART_ITConfig((USART_TypeDef*)gt_fk_uart_name[FK_UART3_DEFAULT], USART_IT_TXE, ENABLE)
//! @brief The API for stoping UART1 transfer interrupt
#define FK_UART3_TX_INTERRUPT_DISABLE_API()                                           USART_ITConfig((USART_TypeDef*)gt_fk_uart_name[FK_UART3_DEFAULT], USART_IT_TXE, DISABLE)
//! @brief The API for checking UART3 is busy or not
#define FK_UART3_IS_BUS_APIY()                                                        (USART_GetFlagStatus(USART3,USART_FLAG_TC)==RESET)
//! @brief The API for UART2 waitting send out finish
#define FK_UART3_TX_WAIT_API()                                                        while(FK_UART3_IS_BUS_APIY())

  

//**It is not commonly used function*//  
//! @brief Initial remap UART1 function as polling mode
#define FK_UART1_REMAP_POLLING_API(baudrate,bits,stop_bits,parity)                    fk_uart_init(FK_UART1_REMAP,baudrate,bits,stop_bits,parity,FK_UART_POLLING_MODE,(UINT8(*)())fk_null,fk_null)
//! @brief Initial remap UART1 function as interrupt mode
#define FK_UART1_REMAP_INTERRUPT_API(baudrate,bits,stop_bits,parity,tx_func,rx_func)  fk_uart_init(FK_UART1_REMAP,baudrate,bits,stop_bits,parity,FK_UART_INTERRUPT_MODE,tx_func,rx_func)
//! @brief The API for Sending out data by remap UART1 pins
#define FK_UART1_REMAP_SEND_BYTE_API(byte)                                            USART_SendData((USART_TypeDef*)gt_fk_uart_name[FK_UART1_REMAP],byte)

//! @brief Initial remap UART2 function as polling mode
#define FK_UART2_REMAP_POLLING_API(baudrate,bits,stop_bits,parity)                    fk_uart_init(FK_UART2_REMAP,baudrate,bits,stop_bits,parity,FK_UART_POLLING_MODE,(UINT8(*)())fk_null,fk_null)
//! @brief Initial remap UART2 function as interrupt mode
#define FK_UART2_REMAP_INTERRUPT_API(baudrate,bits,stop_bits,parity,tx_func,rx_func)  fk_uart_init(FK_UART2_REMAP,baudrate,bits,stop_bits,parity,FK_UART_INTERRUPT_MODE,(UINT8(*)())tx_func,rx_func)
//! @brief Sending out data by remap UART2 pins
#define FK_UART2_REMAP_SEND_BYTE_API(byte)                                            USART_SendData((USART_TypeDef*)gt_fk_uart_name[FK_UART2_REMAP],byte)

//! @brief Initial remap UART3 function as polling mode
#define FK_UART3_REMAP_POLLING_API(baudrate,bits,stop_bits,parity)                    fk_uart_init(FK_UART3_REMAP,baudrate,bits,stop_bits,parity,FK_UART_POLLING_MODE,(UINT8(*)())fk_null,fk_null)
//! @brief Initial remap UART3 function as interrupt mode
#define FK_UART3_REMAP_INTERRUPT_API(baudrate,bits,stop_bits,parity,tx_func,rx_func)  fk_uart_init(FK_UART3_REMAP,baudrate,bits,stop_bits,parity,FK_UART_INTERRUPT_MODE,(UINT8(*)())tx_func,rx_func)
//! @brief Sending out data by remap UART3 pins
#define FK_UART3_REMAP_SEND_BYTE_API(byte)                                            USART_SendData((USART_TypeDef*)gt_fk_uart_name[FK_UART3_REMAP],byte)

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
#ifdef __cplusplus
}
#endif
#endif		// FK_UART_UDEF_H 
