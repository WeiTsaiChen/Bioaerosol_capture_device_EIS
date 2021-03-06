#ifndef CRC_TASK_H
#define CRC_TASK_H
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 crc_task.h
//
//! @author 	 Elin Lee
//
//! @date 		 2009/09/02
//
//  @brief 		 This function calculates a two byte CRC value on the incomming message.
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S
//
//**********************************************************************************************************************
#include "..\crc_udef.h"
//**********************************************************************************************************************
//
// M A C R O   D E F I N I T I O N
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// F U N C T I O N   P R O T O T Y P E S
//
//**********************************************************************************************************************
UINT32 crc_generate( UINT8* pabMessage, UINT32 iLength );
#endif		// CRC_TASK_H 
