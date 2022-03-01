#include "main.h"

int main()
{
    FK_INIT_API();
    PFC_INIT_API();
//=======================================//
//BTC Module Initial
//=======================================//
#if MAIN_USE_BTC == 1
    BTC_INIT_API();
#endif
//=======================================//
//HBTC Module Initial
//=======================================//
#if MAIN_USE_HBTC == 1
    HBTC_INIT_API();
#endif      
//=======================================//
//AD421 Module Initial
//=======================================//
#if MAIN_USE_AD421 == 1
    AD421_INIT_API();
#endif
//=======================================//
//AD5421 Module Initial
//=======================================//
#if MAIN_USE_AD5421 	== 1
    AD5421_INIT_API();
#endif
//=======================================//
//CRC Module Initial
//=======================================//
#if MAIN_USE_CRC 	== 1
    CRC_INIT_API();
#endif
//=======================================//
//MODBUS Module Initial
//=======================================//
#if MAIN_USE_MODBUS == 1
    //if (PFC_USE_MODBUS)
      MODBUS_SLAVE_INIT_API();
#endif
//=======================================//
//BLE Module Initial
//=======================================//
#if MAIN_USE_BLE == 1
      BLE_INIT_API();
#endif    
//=======================================//
//HART Module Initial
//=======================================//
#if MAIN_USE_HART == 1
    if (PFC_USE_HART)
      HART_INIT_API();
#endif
//=======================================//
//AD9833 Module Initial
//=======================================//
#if MAIN_USE_AD9833 == 1
    AD9833_INIT_API();
#endif
//=======================================//
//CDCE925 Module Initial
//=======================================//
#if MAIN_USE_CDCE925 == 1
    CDCE925_INIT_API();
#endif
//=======================================//
//DAC7578 Module Initial
//=======================================//
#if MAIN_USE_DAC7578 == 1
    DAC7578_INIT_API();
#endif
//=======================================//
//DAC8562 Module Initial
//=======================================//
 #if MAIN_USE_DAC8562 == 1
    DAC8562_INIT_API();
    DAC8562_CHANNEL_ALL_API(0);
#endif   
//=======================================//
//ADS1114 Module Initial
//=======================================//
#if MAIN_USE_ADS1114 == 1  
    ADS1114_INIT_API();
#endif    
//=======================================//
//TCA9539 Module Initial
//=======================================//
#if MAIN_USE_TCA9539 == 1
    TCA9539_INIT_API();
#endif
//=======================================//
//MCP3422 Module Initial
//=======================================//
#if MAIN_USE_MCP3422 == 1
    MCP3422_INIT_API();
#endif
//=======================================//
//TMP100 Module Initial
//=======================================//    
#if MAIN_USE_TMP100 == 1
    TMP100_INIT_API();
#endif
//=======================================//
//AD5245 Module Initial
//=======================================//     
#if MAIN_USE_AD5245 == 1  
    AD5245_INIT_API();
#endif 
//=======================================//
//TCA9539 Module Initial
//=======================================//
#if MAIN_USE_TCA9539 == 1
    TCA9539_INIT_API();
#endif
//=======================================//
//GDM Module Initial
//=======================================//
#if MAIN_USE_GDM == 1
    GDM_INIT_API();
#endif
//=======================================//
//KEY Module Initial
//=======================================//
#if MAIN_USE_KEY == 1
    KEY_INIT_API();
#endif
//=======================================//
//ST7565 Module Initial
//=======================================//  
#if MAIN_USE_ST7565 == 1
    ST7565_INIT_API();
#endif
//=======================================//
//BU9795AFV Module Initial
//=======================================//
#if MAIN_USE_BU9795AFV == 1
    BU9795AFV_INIT_API();
#endif
//=======================================//
//LCD Module Initial
//=======================================//
#if MAIN_USE_LCD == 1
    LCD_INIT_API();
#endif
//=======================================//
//UIF Module Initial
//=======================================//
#if MAIN_USE_UIF == 1
    UIF_INIT_API();
#endif
//=======================================//
//AD5422 Module Initial
//=======================================//
#if MAIN_USE_AD5422 == 1
    AD5422_INIT_API();
#endif
//=======================================//
//ADS1115 Module Initial
//=======================================//
#if MAIN_USE_ADS1115 == 1
    ADS1115_INIT_API();
#endif
//=======================================//
//ADT7410 Module Initial
//=======================================//
#if MAIN_USE_ADT7410 == 1
    ADT7410_INIT_API();
#endif

#if MAIN_USE_AD5941 == 1
    AD5941_INIT_API();
#endif
    
//=======================================//
//PFC Module Main Finction Start
//=======================================//
    PFC_MAIN_LOOP_API();
}
  