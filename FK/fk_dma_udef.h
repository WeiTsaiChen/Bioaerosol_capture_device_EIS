#ifndef FK_DMA_UDEF_H
#define FK_DMA_UDEF_H
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
enum
{
    FK_DMA_CHANNEL1,
    FK_DMA_CHANNEL2,
    FK_DMA_CHANNEL3,
    FK_DMA_CHANNEL4,
    FK_DMA_CHANNEL5,
    FK_DMA_CHANNEL6,
    FK_DMA_CHANNEL7,
    FK_DMA_CHANNEL8,
    FK_DMA_CHANNEL9,
    FK_DMA_CHANNEL10,
    FK_DMA_CHANNEL11,
    FK_DMA_CHANNEL12,
    FK_DMA_CHANNEL_TOTAL,
};
//**********************************************************************************************************************
//
// A P I   F O R   O T H E R   M O D U L E S
//
//**********************************************************************************************************************
// DMA Function
//! @brief The API for checking DMA is done or not
#define FK_DMA_CHK_DONE_API(channel)                                (*((UINT16*)&gs_fk_dma_interrupt)&((0x01)<<(channel)))

//! @brief The API for clearing DMA done flag
#define FK_DMA_CLR_DONE_API(channel)                                *((UINT16*)&gs_fk_dma_interrupt)&=(~((0x01)<<(channel)))

//! @brief The API for enabling DMA function for copying data from one space to another
#define FK_DMA_ENABLE_API(channel,source,dest,size)                 fk_dma_enable(channel,(UINT32*)source,(UINT32*)dest,size,fk_null)

//! @brief The API for enabling DMA functino for copying data from one space to another,as it's done,it will execute the function
#define FK_DMA_ENABLE_WITH_FUNC_API(channel,source,dest,size,func)  fk_dma_enable(channel,(UINT32*)source,(UINT32*)dest,size,func)

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
#endif		// FK_DMA_UDEF_H 
