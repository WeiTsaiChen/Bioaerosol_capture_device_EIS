#ifndef AD5941_TASK_H
#define AD5941_TASK_H
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 ad5941_task.h
//
//! @author 	 Roger
//
//! @date 		 2021/10
//
//  @brief 		 Here declare task function
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S 
//
//**********************************************************************************************************************
#include "..\ad5941_udef.h"
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
void ad5941_write_cmd(UINT8 cmd,UINT16 *data);
void ad5941_read(UINT8 cmd,UINT16 *data);

/**
 * @} TypeDefinitions
*/

/**
 * @defgroup Exported_Functions
 * @{
*/
/* 1. Basic SPI functions */
void      AD5941_WriteReg(uint16_t RegAddr, uint32_t RegData);
uint32_t  AD5941_ReadReg(uint16_t RegAddr);
void      AD5941_FIFORd(uint32_t *pBuffer,uint32_t uiReadCount);

/* 2. AD5941 Top Control functions */
void      AD5941_Initialize(void); /* Call this function firstly once AD5941 power on or come from soft reset */
void      AD5941_AFECtrlS(uint32_t AfeCtrlSet, BoolFlag State);
AD5941Err AD5941_LPModeCtrlS(uint32_t EnSet);
void      AD5941_AFEPwrBW(uint32_t AfePwr, uint32_t AfeBw); /* AFE power mode and system bandwidth control */
void      AD5941_REFCfgS(AFERefCfg_Type *pBufCfg);

/* 3. High_Speed_Loop Functions */
void      AD5941_HSLoopCfgS(HSLoopCfg_Type *pHsLoopCfg);
void      AD5941_SWMatrixCfgS(SWMatrixCfg_Type *pSwMatrix);
void      AD5941_HSDacCfgS(HSDACCfg_Type *pHsDacCfg);
AD5941Err AD5941_HSTIACfgS(HSTIACfg_Type *pHsTiaCfg);
void      AD5941_HSRTIACfgS(uint32_t HSTIARtia);

/* 4. Low_Power_Loop Functions*/
void      AD5941_LPLoopCfgS(LPLoopCfg_Type *pLpLoopCfg);
void      AD5941_LPDACCfgS(LPDACCfg_Type *pLpDacCfg);
//void      AD5941_LPDACWriteS(uint16_t Data12Bit, uint8_t Data6Bit);
void      AD5941_LPDAC0WriteS(uint16_t Data12Bit, uint8_t Data6Bit);
void      AD5941_LPDAC1WriteS(uint16_t Data12Bit, uint8_t Data6Bit);
void      AD5941_LPAMPCfgS(LPAmpCfg_Type *pLpAmpCfg);

/* 5. DSP_Block_Functions */
void      AD5941_DSPCfgS(DSPCfg_Type *pDSPCfg);
uint32_t  AD5941_ReadAfeResult(uint32_t AfeResultSel);
/* 5.1 ADC Block */
void      AD5941_ADCBaseCfgS(ADCBaseCfg_Type *pADCInit);
void      AD5941_ADCFilterCfgS(ADCFilterCfg_Type *pFiltCfg);
void      AD5941_ADCPowerCtrlS(BoolFlag State);
void      AD5941_ADCConvtCtrlS(BoolFlag State);
void      AD5941_ADCMuxCfgS(uint32_t ADCMuxP, uint32_t ADCMuxN);
void      AD5941_ADCDigCompCfgS(ADCDigComp_Type *pCompCfg);
void      AD5941_StatisticCfgS(StatCfg_Type *pStatCfg);
void      AD5941_ADCRepeatCfgS(uint32_t Number);
void      AD5941_DFTCfgS(DFTCfg_Type *pDftCfg);
/* 5.2 Waveform Generator Block */
void      AD5941_WGCfgS(WGCfg_Type *pWGInit);
AD5941Err AD5941_WGDACCodeS(uint32_t code); /* Directly write DAC Code */
void      AD5941_WGFreqCtrlS(float SinFreqHz, float WGClock);
uint32_t  AD5941_WGFreqWordCal(float SinFreqHz, float WGClock);
//uint32_t AD5941_WGAmpWordCal(float Amp, BoolFlag DacGain, BoolFlag ExcitGain);

/* 6. Sequencer_FIFO */
void      AD5941_FIFOCfg(FIFOCfg_Type *pFifoCfg);
AD5941Err AD5941_FIFOGetCfg(FIFOCfg_Type *pFifoCfg);  /* Read back current configuration */
void      AD5941_FIFOCtrlS(uint32_t FifoSrc, BoolFlag FifoEn);   /* Configure FIFO data source. And disable/enable it.*/
void      AD5941_FIFOThrshSet(uint32_t FIFOThresh);
uint32_t  AD5941_FIFOGetCnt(void);     /* Get current FIFO count */
void      AD5941_SEQCfg(SEQCfg_Type *pSeqCfg);
AD5941Err AD5941_SEQGetCfg(SEQCfg_Type *pSeqCfg);    /* Read back current configuration */
void      AD5941_SEQCtrlS(BoolFlag SeqEn);
void      AD5941_SEQHaltS(void);
void      AD5941_SEQMmrTrig(uint32_t SeqId); /* Manually trigger sequence */
void      AD5941_SEQCmdWrite(uint32_t StartAddr, const uint32_t *pCommand, uint32_t CmdCnt);
void      AD5941_SEQInfoCfg(SEQInfo_Type *pSeq);
AD5941Err AD5941_SEQInfoGet(uint32_t SeqId, SEQInfo_Type *pSeqInfo);
void      AD5941_SEQGpioCtrlS(uint32_t GpioSet);   /* Sequencer can control GPIO0~7 if the GPIO function is set to SYNC */
uint32_t  AD5941_SEQTimeOutRd(void);  /* Read back current sequence time out value */
AD5941Err AD5941_SEQGpioTrigCfg(SeqGpioTrig_Cfg *pSeqGpioTrigCfg);
void      AD5941_WUPTCfg(WUPTCfg_Type *pWuptCfg);
void      AD5941_WUPTCtrl(BoolFlag Enable);  /* Enable or disable Wakeup timer */
AD5941Err AD5941_WUPTTime(uint32_t SeqId, uint32_t SleepTime, uint32_t WakeupTime);

/* 7. MISC_Block */
/* 7.1 Clock system */
void      AD5941_CLKCfg(CLKCfg_Type *pClkCfg);
void      AD5941_HFOSC32MHzCtrl(BoolFlag Mode32MHz);
void 			AD5941_HPModeEn(BoolFlag Enable);	/* Switch system clocks to high power mode for EIS >80kHz)*/
/* 7.2 AFE Interrupt */
void      AD5941_INTCCfg(uint32_t AfeIntcSel, uint32_t AFEIntSrc, BoolFlag State);
uint32_t  AD5941_INTCGetCfg(uint32_t AfeIntcSel);
void      AD5941_INTCClrFlag(uint32_t AfeIntSrcSel);
BoolFlag  AD5941_INTCTestFlag(uint32_t AfeIntcSel, uint32_t AfeIntSrcSel); /* Check if selected interrupt happened */
uint32_t  AD5941_INTCGetFlag(uint32_t AfeIntcSel); /* Get current INTC interrupt flag */
/* 7.3 GPIO */
void      AD5941_AGPIOCfg(AGPIOCfg_Type *pAgpioCfg);
void      AD5941_AGPIOFuncCfg(uint32_t uiCfgSet);
void      AD5941_AGPIOOen(uint32_t uiPinSet);
void      AD5941_AGPIOIen(uint32_t uiPinSet);
uint32_t  AD5941_AGPIOIn(void);
void      AD5941_AGPIOPen(uint32_t uiPinSet);
void      AD5941_AGPIOSet(uint32_t uiPinSet);
void      AD5941_AGPIOClr(uint32_t uiPinSet);
void      AD5941_AGPIOToggle(uint32_t uiPinSet);

/* 7.4 LPMODE */
AD5941Err AD5941_LPModeEnS(BoolFlag LPModeEn); /* Enable LP mode or disable it. */
void      AD5941_LPModeClkS(uint32_t LPModeClk);
void      AD5941_ADCRepeatCfg(uint32_t Number);
/* 7.5 Power */
void      AD5941_SleepKeyCtrlS(uint32_t SlpKey); /* enter the correct key to allow AFE to enter sleep mode */
void      AD5941_EnterSleepS(void);      /* Put AFE to hibernate/sleep mode and keep LP loop as the default settings. */
void      AD5941_ShutDownS(void);    /* Unlock the key, turn off LP loop and enter sleep/hibernate mode  */
uint32_t  AD5941_WakeUp(int32_t TryCount);   /* Try to wakeup AFE by read register */
uint32_t  AD5941_GetADIID(void);   /* Read ADIID */
uint32_t  AD5941_GetChipID(void);  /* Read Chip ID */
AD5941Err AD5941_SoftRst(void);
void      AD5941_HWReset(void);       /* Do hardware reset to AD5941 using RESET pin */
/* Calibration functions */
/* 8. Calibration */
AD5941Err AD5941_ADCPGACal(ADCPGACal_Type *ADCPGACal);
AD5941Err AD5941_LPDACCal(LPDACCal_Type *pCalCfg, LPDACPara_Type *pResult);
AD5941Err AD5941_LPTIAOffsetCal(LPTIAOffsetCal_Type *pLPTIAOffsetCal);
AD5941Err AD5941_HSRtiaCal(HSRTIACal_Type *pCalCfg, void *pResult);
AD5941Err AD5941_HSDACCal(HSDACCal_Type *pCalCfg);
AD5941Err AD5941_LPRtiaCal(LPRTIACal_Type *pCalCfg, void *pResult);
AD5941Err AD5941_LFOSCMeasure(LFOSCMeasure_Type *pCfg, float *pFreq);

/* 9. Pure software functions. Functions with no register access. These functions are helpers */
  /* Sequence Generator */
void      AD5941_SEQGenInit(uint32_t *pBuffer, uint32_t BufferSize);/* Initialize sequence generator workspace */
void      AD5941_SEQGenCtrl(BoolFlag bFlag);  /* Enable or disable sequence generator */
void      AD5941_SEQGenInsert(uint32_t CmdWord); /* Manually insert a sequence command */
AD5941Err AD5941_SEQGenFetchSeq(const uint32_t **ppSeqCmd, uint32_t *pSeqCount);  /* Fetch generated sequence and start a new sequence */
void      AD5941_ClksCalculate(ClksCalInfo_Type *pFilterInfo, uint32_t *pClocks);
uint32_t  AD5941_SEQCycleTime(void);
void      AD5941_SweepNext(SoftSweepCfg_Type *pSweepCfg, float *pNextFreq);
void      AD5941_StructInit(void *pStruct, uint32_t StructSize);
float     AD5941_ADCCode2Volt(uint32_t code, uint32_t ADCPga, float VRef1p82); /* Calculate ADC code to voltage */
BoolFlag  AD5941_Notch50HzAvailable(ADCFilterCfg_Type *pFilterInfo, uint8_t *dl);
BoolFlag  AD5941_Notch60HzAvailable(ADCFilterCfg_Type *pFilterInfo, uint8_t *dl);
fImpCar_Type AD5941_ComplexDivFloat(fImpCar_Type *a, fImpCar_Type *b);
fImpCar_Type AD5941_ComplexMulFloat(fImpCar_Type *a, fImpCar_Type *b);
fImpCar_Type AD5941_ComplexAddFloat(fImpCar_Type *a, fImpCar_Type *b);
fImpCar_Type AD5941_ComplexSubFloat(fImpCar_Type *a, fImpCar_Type *b);

fImpCar_Type AD5941_ComplexDivInt(iImpCar_Type *a, iImpCar_Type *b);
fImpCar_Type AD5941_ComplexMulInt(iImpCar_Type *a, iImpCar_Type *b);
float     AD5941_ComplexMag(fImpCar_Type *a);
float     AD5941_ComplexPhase(fImpCar_Type *a);
FreqParams_Type AD5941_GetFreqParameters(float freq);
/**
 * @} Exported_Functions
*/
void AD5940_HWReset(void);

/**
 * @defgroup Library_Interface
 *  The functions user should provide for specific MCU platform
 * @{
*/
void AD5941_Delay10us(UINT32 delay);
/* (Not used for now.)AD5941 has 8 GPIOs, some of them are connected to MCU. MCU can set or read the status of these pins. */
void      AD5941_MCUGpioWrite(uint32_t data);   /*  */
uint32_t  AD5941_MCUGpioRead(uint32_t);
void      AD5941_MCUGpioCtrl(uint32_t, BoolFlag);
void      AD5941_ReadWriteNBytes(unsigned char *pSendBuffer,unsigned char *pRecvBuff,unsigned long length);
/* Below functions are frequently used in example code but not necessary for library */
uint32_t  AD5941_GetMCUIntFlag(void);
uint32_t  AD5941_ClrMCUIntFlag(void);
void  AD5941_MCUResourceInit();

//void SetucInterrupted(uint32_t value);
void SetucInterrupted(void);

#endif		// AD5941_TASK_H 
