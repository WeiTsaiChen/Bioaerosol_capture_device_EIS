#ifndef FK_I2C_UDEF_H
#define FK_I2C_UDEF_H
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
//========================================================================================================//
//! @brief I2C1 Bus use H/W Driver
//========================================================================================================//
//#define	FK_IIC_HW_INIT_API()						        iic_hw_init()
#define FK_I2C1_HW_TASK_API() 						                                    fk_i2c1_hw_task()
#define	FK_I2C1_HW_CHECK_TIMEOUT_API()						                            fk_i2c1_hw_check_timeout_func()//HTBC
#define	FK_I2C1_HW_BYTE_WRITE_API(addr,counter,data)  				                    fk_i2c1_hw_byte_write(addr,counter,data)
#define	FK_I2C1_HW_BYTE_READ_API(Addr_Counter,Addr_buf,Read_Counter,iic_hw_read_buf)  	fk_i2c1_hw_byte_read(Addr_Counter,Addr_buf,Read_Counter,iic_hw_read_buf)

//========================================================================================================//
//! @brief I2C Bus use I/O simulation
//========================================================================================================//
//! @brief Send data use I/O simulation
#define FK_I2C_IO_SEND_API(device_addr,data,len)	        		        fk_i2c_master_send(device_addr,data,len)
//! @brief Read data I/O simulation
#define FK_I2C_IO_READ_API(device_addr,data,len)				        fk_i2c_master_receive(device_addr,data,len)

//========================================================================================================//
//**********************************************************************************************************************
// I / O   P O R T   D E F I N I T I O N
//
//********************************************************************************************************************** 
//**********************************************************************************************************************
//
// A P I   F O R   O T H E R   M O D U L E S
//
//**********************************************************************************************************************
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
#endif		// FK_I2C_UDEF_H 