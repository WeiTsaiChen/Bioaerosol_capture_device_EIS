;/******************** (C) COPYRIGHT 2014 STMicroelectronics ********************
;* File Name          : startup_stm32l1xx_xl.s
;* Author             : MCD Application Team
;* Version            : V1.3.2
;* Date               : 10-April-2014
;* Description        : STM32L1xx Ultra Low Power XL-density Devices vector 
;*                      table for EWARM toolchain.
;*                      This module performs:
;*                      - Set the initial SP
;*                      - Set the initial PC == __iar_program_start,
;*                      - Set the vector table entries with the exceptions ISR 
;*                        address.
;*                      After Reset the Cortex-M3 processor is in Thread mode,
;*                      priority is Privileged, and the Stack is set to Main.
;********************************************************************************
;* 
;* Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
;* You may not use this file except in compliance with the License.
;* You may obtain a copy of the License at:
;* 
;*        http://www.st.com/software_license_agreement_liberty_v2
;* 
;* Unless required by applicable law or agreed to in writing, software 
;* distributed under the License is distributed on an "AS IS" BASIS, 
;* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
;* See the License for the specific language governing permissions and
;* limitations under the License.
;* 
;*******************************************************************************/
;
;
; The modules in this file are included in the libraries, and may be replaced
; by any user-defined modules that define the PUBLIC symbol _program_start or
; a user defined start symbol.
; To override the cstartup defined in the library, simply add your modified
; version to the workbench project.
;
; The vector table is normally located at address 0.
; When debugging in RAM, it can be located in RAM, aligned to at least 2^6.
; The name "__vector_table" has special meaning for C-SPY:
; it is where the SP start value is found, and the NVIC vector
; table register (VTOR) is initialized to this address if != 0.
;
; Cortex-M version
;

        MODULE  ?cstartup

        ;; Forward declaration of sections.
        SECTION CSTACK:DATA:NOROOT(3)

        SECTION .intvec:CODE:NOROOT(2)

        EXTERN  __iar_program_start
        EXTERN  SystemInit  
        EXTERN fk_NMI_Handler
        EXTERN fk_PVD_Handler
        EXTERN fk_HardFault_Handler
        EXTERN fk_MemManage_Handler
        EXTERN fk_BusFault_Handler
        EXTERN fk_UsageFault_Handler
        EXTERN fk_SVC_Handler
        EXTERN fk_DebugMon_Handler
        EXTERN fk_PendSV_Handler
        EXTERN fk_SysTick_Handler
        EXTERN fk_EXTI0_Handler
        EXTERN fk_EXTI1_Handler
        EXTERN fk_EXTI2_Handler
        EXTERN fk_EXTI3_Handler
        EXTERN fk_EXTI4_Handler
        EXTERN fk_EXTI9_5_Handler
        EXTERN fk_EXTI15_10_Handler
        EXTERN fk_rtc_Handler
        EXTERN fk_rtc_alarm_Handler
        EXTERN fk_wwatchdog_Handler
        EXTERN fk_dma_Handler
        EXTERN fk_tim5_cc_Handler
        EXTERN fk_tim2_Handler
        EXTERN fk_tim3_Handler
        EXTERN fk_tim4_Handler
        EXTERN fk_tim9_Handler
        EXTERN fk_uart1_Handler
        EXTERN fk_uart2_Handler
        EXTERN fk_uart3_Handler
        EXTERN fk_adc1_2_Handler
        PUBLIC  __vector_table

        DATA
__vector_table
        DCD     sfe(CSTACK)
        DCD     Reset_Handler             ; Reset Handler

        DCD     NMI_Handler               ; NMI Handler
        DCD     HardFault_Handler         ; Hard Fault Handler
        DCD     MemManage_Handler         ; MPU Fault Handler
        DCD     BusFault_Handler          ; Bus Fault Handler
        DCD     UsageFault_Handler        ; Usage Fault Handler
        DCD     0                         ; Reserved
        DCD     0                         ; Reserved
        DCD     0                         ; Reserved
        DCD     0                         ; Reserved
        DCD     SVC_Handler               ; SVCall Handler
        DCD     DebugMon_Handler          ; Debug Monitor Handler
        DCD     0                         ; Reserved
        DCD     PendSV_Handler            ; PendSV Handler
        DCD     SysTick_Handler           ; SysTick Handler

         ; External Interrupts
        DCD     WWDG_IRQHandler           ; Window Watchdog
        DCD     PVD_IRQHandler            ; PVD through EXTI Line detect
        DCD     TAMPER_STAMP_IRQHandler   ; Tamper and Time Stamp
        DCD     RTC_WKUP_IRQHandler       ; RTC Wakeup
        DCD     FLASH_IRQHandler          ; FLASH
        DCD     RCC_IRQHandler            ; RCC
        DCD     EXTI0_IRQHandler          ; EXTI Line 0
        DCD     EXTI1_IRQHandler          ; EXTI Line 1
        DCD     EXTI2_IRQHandler          ; EXTI Line 2
        DCD     EXTI3_IRQHandler          ; EXTI Line 3
        DCD     EXTI4_IRQHandler          ; EXTI Line 4
        DCD     DMA1_Channel1_IRQHandler  ; DMA1 Channel 1
        DCD     DMA1_Channel2_IRQHandler  ; DMA1 Channel 2
        DCD     DMA1_Channel3_IRQHandler  ; DMA1 Channel 3
        DCD     DMA1_Channel4_IRQHandler  ; DMA1 Channel 4
        DCD     DMA1_Channel5_IRQHandler  ; DMA1 Channel 5
        DCD     DMA1_Channel6_IRQHandler  ; DMA1 Channel 6
        DCD     DMA1_Channel7_IRQHandler  ; DMA1 Channel 7
        DCD     ADC1_IRQHandler           ; ADC1
        DCD     USB_HP_IRQHandler         ; USB High Priority
        DCD     USB_LP_IRQHandler         ; USB Low  Priority
        DCD     DAC_IRQHandler            ; DAC
        DCD     COMP_IRQHandler           ; COMP through EXTI Line
        DCD     EXTI9_5_IRQHandler        ; EXTI Line 9..5
        DCD     LCD_IRQHandler            ; LCD
        DCD     TIM9_IRQHandler           ; TIM9
        DCD     TIM10_IRQHandler          ; TIM10
        DCD     TIM11_IRQHandler          ; TIM11
        DCD     TIM2_IRQHandler           ; TIM2
        DCD     TIM3_IRQHandler           ; TIM3
        DCD     TIM4_IRQHandler           ; TIM4
        DCD     I2C1_EV_IRQHandler        ; I2C1 Event
        DCD     I2C1_ER_IRQHandler        ; I2C1 Error
        DCD     I2C2_EV_IRQHandler        ; I2C2 Event
        DCD     I2C2_ER_IRQHandler        ; I2C2 Error
        DCD     SPI1_IRQHandler           ; SPI1
        DCD     SPI2_IRQHandler           ; SPI2
        DCD     USART1_IRQHandler         ; USART1
        DCD     USART2_IRQHandler         ; USART2
        DCD     USART3_IRQHandler         ; USART3
        DCD     EXTI15_10_IRQHandler      ; EXTI Line 15..10
        DCD     RTC_Alarm_IRQHandler      ; RTC Alarm through EXTI Line
        DCD     USB_FS_WKUP_IRQHandler    ; USB FS Wakeup from suspend
        DCD     TIM6_IRQHandler           ; TIM6
        DCD     TIM7_IRQHandler           ; TIM7
        DCD     0                         ; Reserved
        DCD     TIM5_IRQHandler           ; TIM5                
        DCD     SPI3_IRQHandler           ; SPI3
        DCD     UART4_IRQHandler          ; UART4
        DCD     UART5_IRQHandler          ; UART5
        DCD     DMA2_Channel1_IRQHandler  ; DMA2 Channel 1
        DCD     DMA2_Channel2_IRQHandler  ; DMA2 Channel 2
        DCD     DMA2_Channel3_IRQHandler  ; DMA2 Channel 3
        DCD     DMA2_Channel4_IRQHandler  ; DMA2 Channel 4
        DCD     DMA2_Channel5_IRQHandler  ; DMA2 Channel 5
        DCD     AES_IRQHandler            ; AES
        DCD     COMP_ACQ_IRQHandler       ; Comparator Channel Acquisition 
        
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Default interrupt handlers.
;;
        THUMB

        PUBWEAK Reset_Handler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reset_Handler
        LDR     R0, =SystemInit
        BLX     R0
        LDR     R0, =__iar_program_start
        BX      R0
        
        PUBWEAK NMI_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
NMI_Handler
        B fk_NMI_Handler
        
        
        PUBWEAK HardFault_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
HardFault_Handler
        B fk_HardFault_Handler
        
        
        PUBWEAK MemManage_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
MemManage_Handler
        B fk_MemManage_Handler
        
                
        PUBWEAK BusFault_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
BusFault_Handler
        B fk_BusFault_Handler
        
        
        PUBWEAK UsageFault_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
UsageFault_Handler
        B fk_UsageFault_Handler
        
        
        PUBWEAK SVC_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
SVC_Handler
        B fk_SVC_Handler
        
        
        PUBWEAK DebugMon_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
DebugMon_Handler
        B fk_DebugMon_Handler
        
        
        PUBWEAK PendSV_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
PendSV_Handler
        B fk_PendSV_Handler
        
        
        PUBWEAK SysTick_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
SysTick_Handler
        B fk_SysTick_Handler
        
        
        PUBWEAK WWDG_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
WWDG_IRQHandler
        B fk_wwatchdog_Handler
        
        
        PUBWEAK PVD_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
PVD_IRQHandler
        B PVD_IRQHandler
        
        
        PUBWEAK TAMPER_STAMP_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
TAMPER_STAMP_IRQHandler
        B TAMPER_STAMP_IRQHandler
        
        
        PUBWEAK RTC_WKUP_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
RTC_WKUP_IRQHandler
        B fk_rtc_Handler
        
        
        PUBWEAK FLASH_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
FLASH_IRQHandler
        B FLASH_IRQHandler
        
        
        PUBWEAK RCC_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
RCC_IRQHandler
        B RCC_IRQHandler
        
        
        PUBWEAK EXTI0_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EXTI0_IRQHandler
        B fk_EXTI0_Handler
        
        
        PUBWEAK EXTI1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EXTI1_IRQHandler
        B fk_EXTI1_Handler
        
        
        PUBWEAK EXTI2_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EXTI2_IRQHandler
        B fk_EXTI2_Handler
        
        
        PUBWEAK EXTI3_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EXTI3_IRQHandler
        B fk_EXTI3_Handler
        
        
        PUBWEAK EXTI4_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EXTI4_IRQHandler
        B fk_EXTI4_Handler
        
        
        PUBWEAK DMA1_Channel1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
DMA1_Channel1_IRQHandler
        B fk_dma_Handler
        
        
        PUBWEAK DMA1_Channel2_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
DMA1_Channel2_IRQHandler
        B fk_dma_Handler
        
        
        PUBWEAK DMA1_Channel3_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
DMA1_Channel3_IRQHandler
        B fk_dma_Handler
        
        
        PUBWEAK DMA1_Channel4_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
DMA1_Channel4_IRQHandler
        B fk_dma_Handler
        
        
        PUBWEAK DMA1_Channel5_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
DMA1_Channel5_IRQHandler
        B fk_dma_Handler
        
        
        PUBWEAK DMA1_Channel6_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
DMA1_Channel6_IRQHandler
        B fk_dma_Handler
        
        
        PUBWEAK DMA1_Channel7_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
DMA1_Channel7_IRQHandler
        B fk_dma_Handler
        
        
        PUBWEAK ADC1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
ADC1_IRQHandler
        B fk_adc1_2_Handler
        
        
        PUBWEAK USB_HP_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
USB_HP_IRQHandler
        B USB_HP_IRQHandler
        
        
        PUBWEAK USB_LP_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
USB_LP_IRQHandler
        B USB_LP_IRQHandler
        
        
        PUBWEAK DAC_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
DAC_IRQHandler
        B DAC_IRQHandler
        
        
        PUBWEAK COMP_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
COMP_IRQHandler
        B COMP_IRQHandler
        
        
        PUBWEAK EXTI9_5_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EXTI9_5_IRQHandler
        B fk_EXTI9_5_Handler
        
        
        PUBWEAK LCD_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
LCD_IRQHandler
        B LCD_IRQHandler
        
        
        PUBWEAK TIM9_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
TIM9_IRQHandler
        B fk_tim9_Handler
        
        
        PUBWEAK TIM10_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
TIM10_IRQHandler
        B TIM10_IRQHandler
        
        
        PUBWEAK TIM11_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
TIM11_IRQHandler
        B TIM11_IRQHandler
        
        
        PUBWEAK TIM2_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
TIM2_IRQHandler
        B fk_tim2_Handler
        
        
        PUBWEAK TIM3_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
TIM3_IRQHandler
        B fk_tim3_Handler
        
        
        PUBWEAK TIM4_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
TIM4_IRQHandler
        B fk_tim4_Handler
        
        
        PUBWEAK I2C1_EV_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
I2C1_EV_IRQHandler
        B I2C1_EV_IRQHandler
        
        
        PUBWEAK I2C1_ER_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
I2C1_ER_IRQHandler
        B I2C1_ER_IRQHandler
        
        
        PUBWEAK I2C2_EV_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
I2C2_EV_IRQHandler
        B I2C2_EV_IRQHandler
        
        
        PUBWEAK I2C2_ER_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
I2C2_ER_IRQHandler
        B I2C2_ER_IRQHandler
        
        
        PUBWEAK SPI1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
SPI1_IRQHandler
        B SPI1_IRQHandler
        
        
        PUBWEAK SPI2_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
SPI2_IRQHandler
        B SPI2_IRQHandler
        
        
        PUBWEAK USART1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
USART1_IRQHandler
        B fk_uart1_Handler
        
        
        PUBWEAK USART2_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
USART2_IRQHandler
        B fk_uart2_Handler
        
        
        PUBWEAK USART3_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
USART3_IRQHandler
        B fk_uart3_Handler
        
        
        PUBWEAK EXTI15_10_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EXTI15_10_IRQHandler
        B fk_EXTI15_10_Handler
        
        
        PUBWEAK RTC_Alarm_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
RTC_Alarm_IRQHandler
        B fk_rtc_alarm_Handler
        
        
        PUBWEAK USB_FS_WKUP_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
USB_FS_WKUP_IRQHandler
        B USB_FS_WKUP_IRQHandler
        

        PUBWEAK TIM6_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
TIM6_IRQHandler
        B TIM6_IRQHandler
        

        PUBWEAK TIM7_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
TIM7_IRQHandler
        B TIM7_IRQHandler

        PUBWEAK TIM5_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
TIM5_IRQHandler
        B fk_tim5_cc_Handler

        PUBWEAK SPI3_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
SPI3_IRQHandler
        B SPI3_IRQHandler
        
        
        PUBWEAK UART4_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
UART4_IRQHandler
        B UART4_IRQHandler
        
        
        PUBWEAK UART5_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
UART5_IRQHandler
        B UART5_IRQHandler

        PUBWEAK DMA2_Channel1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
DMA2_Channel1_IRQHandler
        B fk_dma_Handler
        
        
        PUBWEAK DMA2_Channel2_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
DMA2_Channel2_IRQHandler
        B fk_dma_Handler
        
        
        PUBWEAK DMA2_Channel3_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
DMA2_Channel3_IRQHandler
        B fk_dma_Handler
        
        
        PUBWEAK DMA2_Channel4_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
DMA2_Channel4_IRQHandler
        B fk_dma_Handler
        
        
        PUBWEAK DMA2_Channel5_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
DMA2_Channel5_IRQHandler
        B fk_dma_Handler


        PUBWEAK AES_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
AES_IRQHandler
        B AES_IRQHandler
        

        PUBWEAK COMP_ACQ_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
COMP_ACQ_IRQHandler
        B COMP_ACQ_IRQHandler                
                
        END
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
