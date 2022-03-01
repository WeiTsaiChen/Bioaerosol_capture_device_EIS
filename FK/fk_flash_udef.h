#ifndef FK_FLASH_UDEF_H
#define FK_FLASH_UDEF_H
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
/*
Block Name Memory addresses Size
Program memory 1   256KBytes
    bank 1
        Sector 0
            Page 0 0x0800 0000 - 0x0800 00FF 256 bytes
            Page 1 0x0800 0100 - 0x0800 01FF 256 bytes
            Page 2 0x0800 0200 - 0x0800 02FF 256 bytes
            Page 3 0x0800 0300 - 0x0800 03FF 256 bytes
            Page 4 to 7 0x0800 0400 - 0x0800 07FF 1 Kbytes
            Page 8 to 11 0x0800 0800 - 0x0800 0BFF 1 Kbytes
            Page 12 to 15 0x0800 0C00 - 0x0800 0FFF 1 Kbytes
        Sector 1 Page 16 to 31 0x0800 1000 - 0x0800 1FFF 4 Kbytes
        Sector 2 Page 32 to 47 0x0800 2000 - 0x0800 2FFF 4 Kbytes
        Sector 3 Page 48 to 63 0x0800 3000 - 0x0800 3FFF 4 Kbytes
        ....
        Sector 30 Page 478 to 495 0x0801 E000 - 0x0801 EFFF 4 Kbytes
        Sector 31 Page 496 to 511 0x0801 F000 - 0x0801 FFFF 4 Kbytes
        Sector 32 to Sector 63  Page 512 to 1023 0x0802 0000 - 0x0803 FFFF 128 Kbytes
  
Program memory 2  256KBytes
    bank 2
        Sector 64 to Sector 95    Page 1024 to 1535 0x0804 0000 - 0x0805 FFFF 128 Kbytes
        Sector 96 to Sector 127   Page 1536 to 2047 0x0806 0000 - 0x0807 FFFF 128 Kbytes

Data EEPROM bank 1 0x0808 0000 - 0x0808 1FFF 8 Kbytes
Data EEPROM bank 2 0x0808 2000 - 0x0808 3FFF 8 Kbytes
*/
#define FK_M3_FLASH_START               0x8000000

#define	FK_FLASH_SIZE           		(256*1024)
#define FK_FLASH_PAGE_SIZE              ((uint16_t)0x1000)

#define FK_TOTAL_PAGE                   (FK_FLASH_SIZE/FK_FLASH_PAGE_SIZE)
#define FK_NEED_PAGE                    1

#define FK_USER_START_PAGE              (FK_TOTAL_PAGE-2*FK_NEED_PAGE)
#define FK_FACTORY_START_PAGE           (FK_USER_START_PAGE+FK_NEED_PAGE)
//**********************************************************************************************************************
//
// A P I   F O R   O T H E R   M O D U L E S
//
//**********************************************************************************************************************
// FLASH Function
//! @brief The API for writting data into flash ( user space )
#define FK_WRITE_USER_DATA_API(buf,size)                          fk_write_flash(FK_USER_START_PAGE,buf,size)

//! @brief The API for reading data from flash ( user space )
#define FK_READ_USER_DATA_API(buf,size)                           fk_read_flash(FK_USER_START_PAGE,buf,size)

//! @brief The API for writting data into flash ( factory space )
#define FK_WRITE_FACTORY_DATA_API(buf,size)                       fk_write_flash(FK_FACTORY_START_PAGE,buf,size)

//! @brief The API for reading data from flash ( factory space )
#define FK_READ_FACTORY_DATA_API(buf,size)                        fk_read_flash(FK_FACTORY_START_PAGE,buf,size)

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
#endif		// FK_FLASH_UDEF_H 
