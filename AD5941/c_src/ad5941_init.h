#ifndef AD5941_INIT_H
#define AD5941_INIT_H
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 ad5941_init.h
//
//! @author 	 Roger
//
//! @date 		 2021/10
//
//  @brief 		 Here declare initial function
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S 
//
//**********************************************************************************************************************
#define         AD5941_Impedance_Mode           1
#define         AD5941_CV_Mode                  0
// #define         AD5941_SWV_Mode                 0
// #define         AD5941_DPV_Mode                 0

#if AD5941_Impedance_Mode == 1 && AD5941_CV_Mode == 1
#Error  "Plz choose a mode once!"
#endif

//**********************************************************************************************************************
//
// F U N C T I O N   P R O T O T Y P E S 
//
//**********************************************************************************************************************
void ad5941_init(void);
void AD5941_Main(void);
static UINT32 AD5941PlatformCfg(void);
void AD5941ImpedanceStructInit(void);

// Impedance data capturing function
static UINT32 ImpedanceShowResult(UINT32 *pData, UINT32 DataCount);

// CV data capturing function
static INT32 RampShowResult(float *pData, UINT32 DataCount, float *Volt, int PointNumber);

// AD5941 Measurement function
void AD5941_Impedance_measurement(int MeasureNum);
void AD5941_CV_measurement(int MeasureCycleNum);

// BLE data transferring function
void AD5941_TX_data_transmit(float Freq, float Impedance, float Phase, float Volt, float Current);

#endif		// AD5941_INIT_H 
