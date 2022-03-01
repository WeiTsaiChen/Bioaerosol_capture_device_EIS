//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 	 pfc_task.c
//
//! @author	 Willman Chen
//
//! @date 	 2009/06/19
//
// @brief 	 Task Subroutine
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S
//
//**********************************************************************************************************************
#include "..\drv_src\pfc_drv.h"
#include "pfc_glb_vars.h"
#include "pfc_task.h"
#include "pfc_idef.h"
#include "..\pfc_udef.h"


//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 pfc_task
//
//! @author	 Willman Chen
//
//! @date 	 2009/06/19
//
//! @brief 	 This function will make the zero-checksum of an array,and fill the zero-checksum value in the last two-bytes.
//
//**********************************************************************************************************************
void pfc_task()
{
    //===FUNCTION TEST ====// 
//    if(PFC_GET_SEC_CNT_API() ==20)
//    {
//      PFC_FAN_CTRL_HIGH();
//      PFC_AIR_PUMP_CTRL_LOW();
//    }
//    if(PFC_GET_SEC_CNT_API() ==15)
//    {
//      PFC_AIR_PUMP_CTRL_HIGH();
//      PFC_FAN_CTRL_LOW(); 
//    }
//    if(PFC_GET_SEC_CNT_API() ==10)
//    {
//      PFC_WATER_PUMP_CTRL_HIGH();
//      PFC_AIR_PUMP_CTRL_LOW();
//    }
//    if(PFC_GET_SEC_CNT_API() ==5)
//    {
//       PFC_WATER_PUMP_CTRL_LOW();
//       PFC_SET_SEC_CNT_API(25);
//    }    

//    if(PFC_CHK_FAN_TASK_API())
//    {
//      PFC_CLR_FAN_TASK_API();
//    }
//    
//    if(PFC_CHK_AIR_PUMP_TASK_API())
//    {
//      PFC_CLR_AIR_PUMP_TASK_API();
//    }
//    
//    if(PFC_CHK_WATER_PUMP_TASK_API())
//    {
//      PFC_CLR_WATER_PUMP_TASK_API();
//    }    
//    
//    if(PFC_CHK_AD5941_TASK_API())
//    {
//      PFC_CLR_AD5941_TASK_API();
//    }
    //AD5941_RstSet();
    //PFC_ADI_ID=AD5941_GetADIID();   /* Read ADIID */
    PFC_CHIP_ID=AD5941_GetChipID();  /* Read Chip ID */
    if(PFC_FAN_CTRL)                    /* Code = 4152 */
       PFC_FAN_CTRL_HIGH();
    else
       PFC_FAN_CTRL_LOW();
    
    if(PFC_AIR_PUMP_CTRL)               /* Code = 4153 */
       PFC_AIR_PUMP_CTRL_HIGH();
    else
       PFC_AIR_PUMP_CTRL_LOW();
    
    if(PFC_WATER_PUMP_CTRL)             /* Code = 4154 */
       PFC_WATER_PUMP_CTRL_HIGH();
    else
       PFC_WATER_PUMP_CTRL_LOW();
    if(PFC_AD5941_MEASUREMENT_CTRL)     /* Code = 4157 */
    {
      /* Modify the measurement here */
      AD5941_Impedance_measurement(42); // Get the result once
    
      // AD5941_CV_measurement(6);
    }
    
    if (PFC_LOAD_FIRMWARE_SETTING)
    {
        pfc_glb_vars_load_default();
        PFC_MAKE_EEPROM_ZERO_CHECKSUM_API();
        PFC_RESTORE_USER_DATA_API();
        PFC_RESTORE_FACTORY_DATA_API();
    }

    if (PFC_LOAD_DEFAULT_SETTING)
    {
        PFC_READ_FACTORY_DATA_API();
        PFC_RESTORE_USER_DATA_API();
    }

    if (PFC_SAVE_CALIBRATION_SETTING)
    {
        PFC_SAVE_CALIBRATION_SETTING=0;
        PFC_MAKE_EEPROM_ZERO_CHECKSUM_API();
        PFC_RESTORE_FACTORY_DATA_API();
    }

    if (PFC_SAVE_SYSTEM_VAR_TO_EEPROM)
    {
        PFC_SAVE_SYSTEM_VAR_TO_EEPROM=0;
        PFC_SAVE_CALIBRATION_SETTING=0;
        PFC_MAKE_EEPROM_ZERO_CHECKSUM_API();
        PFC_RESTORE_USER_DATA_API();
    }
   
    PFC_ENTER_STOP_MODE_API();
}

//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 pfc_make_zero_checksum
//
//! @author	 Willman Chen
//
//! @date 	 2009/06/19
//
//! @brief 	 This function will make the zero-checksum of an array,and fill the zero-checksum value in the last two-bytes.
//
//**********************************************************************************************************************
void pfc_make_zero_checksum(UINT16 *array,UINT32 len)
{
    UINT16 chksum=0;
    UINT32 i;
    UINT16 *data=array;
    len=(len-2)/2;
    for (i=0; i<len; i++)
    {
        chksum+=*data++;
    }
    *(data)=(~chksum+1);
}

//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 pfc_add_sec
//
//! @author	 Willman Chen
//
//! @date 	 2009/06/19
//
//! @brief 	 This function will make the zero-checksum of an array,and fill the zero-checksum value in the last two-bytes.
//
//**********************************************************************************************************************
void pfc_add_sec()
{
    if (++PFC_SEC>=60)
    {
      PFC_SEC=0;
      if (++PFC_MIN>=60)
      {
         PFC_MIN=0;
         if (++PFC_HOUR>=24)
         {
            PFC_HOUR=0;
            if (++PFC_DAY>gt_pfc_days_of_month[PFC_MONTH])
            {
                PFC_DAY=1;
                if (++PFC_MONTH>12)
                {
                    PFC_MONTH=1;
                    ++PFC_YEAR;
                }
            }
         }
      }
      
    }
}
