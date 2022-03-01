#ifndef FK_DAC_UDEF_H
#define FK_DAC_UDEF_H
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
enum
{
   FK_DAC_NONE_WAVE,
   FK_DAC_NOISE_WAVE,
   FK_DAC_TRIANGLE_WAVE,
   FK_DAC_WAVE_TOTAL,
};
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
#define FK_DAC1_DMA                                                FK_DMA_CHANNEL2
#define FK_DAC2_DMA                                                FK_DMA_CHANNEL3
//**********************************************************************************************************************
//
// A P I   F O R   O T H E R   M O D U L E S
//
//**********************************************************************************************************************
// DAC Function
//! @brief The API for enabling DAC1 function
// PA.4
#define FK_DAC1_ENABLE_API()                                    fk_set_dac(FK_DAC_CHANNEL1,(UINT32)FK_PORTA,FK_PIN4,FK_DMA_CHANNEL_TOTAL,0,0,FK_DAC_NONE_WAVE)
#define FK_DAC1_NOISE_WAVE_API()                                fk_set_dac(FK_DAC_CHANNEL1,(UINT32)FK_PORTA,FK_PIN4,FK_DAC1_DMA,0,0,FK_DAC_NOISE_WAVE)
#define FK_DAC1_TRIANGLE_WAVE_API()                             fk_set_dac(FK_DAC_CHANNEL1,(UINT32)FK_PORTA,FK_PIN4,FK_DAC1_DMA,0,0,FK_DAC_TRIANGLE_WAVE)
#define FK_DAC1_DMA_ENABLE_API(buf,size)                        fk_set_dac(FK_DAC_CHANNEL1,(UINT32)FK_PORTA,FK_PIN4,FK_DAC1_DMA,buf,size,FK_DAC_NONE_WAVE)
//! @brief The API for enabling DAC2 function
// PA.5
#define FK_DAC2_ENABLE_API()                                    fk_set_dac(FK_DAC_CHANNEL2,(UINT32)FK_PORTA,FK_PIN5,FK_DMA_CHANNEL_TOTAL,0,0,FK_DAC_NONE_WAVE)
#define FK_DAC2_NOISE_WAVE_API()                                fk_set_dac(FK_DAC_CHANNEL2,(UINT32)FK_PORTA,FK_PIN5,FK_DAC2_DMA,0,0,FK_DAC_NOISE_WAVE)
#define FK_DAC2_TRIANGLE_WAVE_API()                             fk_set_dac(FK_DAC_CHANNEL2,(UINT32)FK_PORTA,FK_PIN5,FK_DAC2_DMA,0,0,FK_DAC_TRIANGLE_WAVE)
#define FK_DAC2_DMA_ENABLE_API(buf,size)                        fk_set_dac(FK_DAC_CHANNEL2,(UINT32)FK_PORTA,FK_PIN5,FK_DAC2_DMA,buf,size,FK_DAC_NONE_WAVE)
//! @brief The API for setting DAC1 value
#define FK_DAC1_SET_VALUE_API(val)                              DAC_SetChannel1Data(DAC_Align_12b_R,val)
//! @brief The API for setting DAC2 value
#define FK_DAC2_SET_VALUE_API(val)                              DAC_SetChannel2Data(DAC_Align_12b_R,val)

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
#endif		// FK_DAC_UDEF_H 
