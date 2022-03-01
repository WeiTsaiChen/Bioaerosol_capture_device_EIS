#ifndef FK_WATCH_DOG_UDEF_H
#define FK_WATCH_DOG_UDEF_H
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

//**********************************************************************************************************************
//
// A P I   F O R   O T H E R   M O D U L E S
//
//**********************************************************************************************************************

// Watch Dog Function
// Warning ! Once start,it can't be stop at any situation.
//! @brief The IWatchDog clock definition
#define FK_IWATCH_DOG_PRESCALE                                                        IWDG_Prescaler_16
#define FK_IWATCH_DOG_CLOCK                                                           (40000/16)   // LSI about 40K Hz
#define FK_IWATCH_DOG_TIME                                                            (FK_IWATCH_DOG_CLOCK/4-1)  // 1 sec
#if MAIN_USE_WATCHDOG == 1
    //! @brief The API for enabling IWatchDog function
#define FK_IWATCHDOG_ENABLE_API()                                                     fk_watchdog_enable()
    //! @brief The API for reloading IWatchDog Timer
#define FK_RELOAD_IWATCHDOG_API()                                                     IWDG_ReloadCounter()
#else
    //! @brief The API for enabling IWatchDog function
#define FK_IWATCHDOG_ENABLE_API()
    //! @brief The API for reloading IWatchDog Timer
#define FK_RELOAD_IWATCHDOG_API()
#endif
// Window Watch Dog Function
// WWDG clock counter = (PCLK1 (56MHz)/4096)/8 = 1708 Hz)
// (1/1708) * (0x7f- 0x01 ) = 73.77ms
//! @brief The WWatchDog clock definition
#define FK_WWATCH_DOG_CLOCK                                                           (FK_SYSTEM_CLOCK/4096/8)
//! @brief The WWatchDog reload value
#define FK_WWATCH_DOG_RESET_VALUE                                                     0x7f

#define FK_WWATCHDOG_ENABLE_API()                                                     fk_wwatchdog_enable()
#define FK_WWATCHDOG_RESET_API()                                                      WWDG_SetCounter(FK_WWATCH_DOG_RESET_VALUE);WWDG_ClearFlag()
#define FK_WWATCHDOG_DISABLE_API()                                                    RCC_APB1PeriphClockCmd(RCC_APB1Periph_WWDG, DISABLE)

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
#endif		// FK_WATCH_DOG_UDEF_H 
