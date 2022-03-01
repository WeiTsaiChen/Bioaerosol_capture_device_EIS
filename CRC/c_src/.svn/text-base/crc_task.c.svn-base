//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 crc_task.c
//
//! @author 	 Elin Lee
//
//! @date 		 2009/09/02
//
//  @brief 		 Task Subroutine
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S
//
//**********************************************************************************************************************
#include "..\drv_src\crc_drv.h"
#include "crc_glb_vars.h"
#include "..\crc_udef.h"
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 crc_generate
//
//! @author 	 Elin Lee
//
//! @date 		 2009/09/02
//
//! @brief 		 This function calculates a two byte CRC value on the incomming message.
//
//! @param 		 pabMessage - Pointer to the message that the crc should be
//                            calculated on
//               iLength    - The length of the message
//
//! @return 	 CRC value
//
//**********************************************************************************************************************
UINT32 crc_generate( UINT8* pabMessage, UINT32 iLength )
{
    const UINT32 iCRCGen = 0xA001;
    UINT32 iCRCReg = 0xFFFF;
    UINT8 i,j;
    iLength%=256;
    if (iLength != 0)
    {
        for(i=0; i<iLength; i++)
        {
            iCRCReg ^= (UINT32)pabMessage[i];
            for(j=0; j<8; j++)
            {
                if (iCRCReg & 0x01)
                {
                    iCRCReg >>= 1;
                    iCRCReg ^= iCRCGen;
                }
                else
                    iCRCReg >>= 1;
            }
        }
    }
    return iCRCReg;
}

