//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 ad5941_init.c
//
//! @author 	 Roger
//
//! @date 		 2021/10
//
//  @brief 		 Initial Subroutine
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S 
//
//**********************************************************************************************************************
#include "../drv_src/ad5941_drv.h" 
#include "ad5941_glb_vars.h"

/* AC-Method */
#include "ad5941_impedance.h"

/* DC-Method */
#include "ad5941_ramp.h"

#include "ad5941_task.h"
/**
   User could configure following parameters
**/

#if AD5941_Impedance_Mode
#define APPBUFF_SIZE 512
#endif

#if AD5941_CV_Mode
#define APPBUFF_SIZE 1024
#endif

uint32_t AppBuff[APPBUFF_SIZE];

float LFOSCFreq;                /* Measured LFOSC frequency */

int counter = 0;                /* Data counter */
int index = 0;                  /* Data index */

// Meaasurment data Monitoring
MeasurementData_Type MData;

//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 ImpedanceShowResult
//
//! @author 	 WTC
//
//! @date 		 2021/10
//
//! @brief 		 initial function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
static UINT32 ImpedanceShowResult(UINT32 *pData, UINT32 DataCount)
{
  float freq;
  // UINT32 rd;

  fImpPol_Type *pImp = (fImpPol_Type*)pData;
  AppIMPCtrl(IMPCTRL_GETFREQ, &freq);
  
  // printf("Freq:%.2f ", freq);
  MData.Freq[counter] = freq;
  
  /* Process data */
  for(int i=0;i<DataCount;i++)
  {
    // printf("RzMag: %f Ohm , RzPhase: %f \n",pImp[i].Magnitude,pImp[i].Phase*180/MATH_PI);
    // MData.tRzMag = pImp[i].Magnitude;
    // MData.tRzPhase = pImp[i].Phase*180/MATH_PI;
    
    MData.RzMag[counter] = pImp[i].Magnitude;
    MData.RzPhase[counter] = (-1)*pImp[i].Phase*180/MATH_PI;

    // MData.tRzX[counter] = (pImp[i].Magnitude)*cos(MData.tRzPhase[counter]);
    // MData.tRzY[counter] = (pImp[i].Magnitude)*sin(MData.tRzPhase[counter]);
    
    // BLE function
    AD5941_TX_data_transmit(freq, pImp[i].Magnitude, (-1)*pImp[i].Phase*180/MATH_PI, 0, 0);
        
    // rd = AD5940_ReadAfeResult(AFERESULT_SINC2);
    // float diff_volt = AD5940_ADCCode2Volt(rd, ADCPGA_1P5, 1.82);
        
    // MData->ADCvolt[counter] = diff_volt+1.11;
        
    // printf("ADC Code:%d, diff-volt: %.4f, volt:%.4f\n",rd, (-1)*diff_volt, diff_volt+1.11);
    // MData.tADCvolt[counter] = diff_volt;
        
  }
 
  return 0;
  
}

/**
 * @brief An example to deal with data read back from AD5940. Here we just print data to UART
 * @note UART has limited speed, it has impact when sample rate is fast. Try to print some of the data not all of them.
 * @param pData: the buffer stored data for this application. The data from FIFO has been pre-processed.
 * @param DataCount: The available data count in buffer pData.
 * @return return 0.
*/
static INT32 RampShowResult(float *pData, uint32_t DataCount, float *Volt, int PointNumber)
{
  // static uint32_t index;
  // uint32_t rd;
    
  /* Print data */
  for(int i=0;i<DataCount;i++)
  { 
    if(PointNumber/2 >= index)
    {
      if(index == 0)
      {
        Volt[3] = Volt[2];
      }
      else
      {
        Volt[3] = Volt[3] + Volt[0];
      }  
    }
    else if(index >= PointNumber/2)
    {
      if(index == PointNumber-1)
      {
        Volt[3] = Volt[2];
      }
      else
      {
        Volt[3] = Volt[3] + Volt[1];
      }
    }
    
    // printf("index:%d, %.3f\n", index++, pData[i]);
    //i += 10;  /* Print though UART consumes too much time. */
    
    MData.tVolt[i] = -Volt[3];         // Need to invert the result.
    AD5941_Delay10us(50);
    MData.tmAmpere[i] = -pData[i];     // Need to invert the result.
    AD5941_Delay10us(50);
    
    index++;
      
    if(index == PointNumber) // Re-initialize the parameters
    {
      index = 0;
      Volt[3] = Volt[2];
    }
    
    // BLE function
    AD5941_TX_data_transmit(0, 0, 0, Volt[3], pData[i]);
    
  }
  
  // rd = AD5940_ReadAfeResult(AFERESULT_SINC3);
  // float diff_volt = AD5940_ADCCode2Volt(rd, ADCPGA_1P5, 1.82);
  
  // printf("ADC Code:%d, diff-volt: %.4f, volt:%.4f\n",rd, diff_volt, diff_volt+1.11);
  
  counter++;
  
  return 0;
}

//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 AD5941PlatformCfg
//
//! @author 	 WTC
//
//! @date 		 2021/10
//
//! @brief 		 initial function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************


static UINT32 AD5941PlatformCfg(void)
{
  CLKCfg_Type clk_cfg;
  FIFOCfg_Type fifo_cfg;
  AGPIOCfg_Type gpio_cfg;

  /* Use hardware reset */
  AD5941_HWReset();
  AD5941_Initialize();
  /* Platform configuration */
  /* Step1. Configure clock */
  clk_cfg.ADCClkDiv = ADCCLKDIV_1;
  clk_cfg.ADCCLkSrc = ADCCLKSRC_HFOSC;
  clk_cfg.SysClkDiv = SYSCLKDIV_1;
  clk_cfg.SysClkSrc = SYSCLKSRC_HFOSC;
  clk_cfg.HfOSC32MHzMode = bFALSE;
  clk_cfg.HFOSCEn = bTRUE;
  clk_cfg.HFXTALEn = bFALSE;
  clk_cfg.LFOSCEn = bTRUE;
  AD5941_CLKCfg(&clk_cfg);
  /* Step2. Configure FIFO and Sequencer*/
  fifo_cfg.FIFOEn = bFALSE;
  fifo_cfg.FIFOMode = FIFOMODE_FIFO;
  fifo_cfg.FIFOSize = FIFOSIZE_4KB;                       /* 4kB for FIFO, The reset 2kB for sequencer */
  fifo_cfg.FIFOSrc = FIFOSRC_DFT;
  fifo_cfg.FIFOThresh = 4;//AppIMPCfg.FifoThresh;        /* DFT result. One pair for RCAL, another for Rz. One DFT result have real part and imaginary part */
  AD5941_FIFOCfg(&fifo_cfg);
  fifo_cfg.FIFOEn = bTRUE;
  AD5941_FIFOCfg(&fifo_cfg);
  
  /* Step3. Interrupt controller */
  AD5941_INTCCfg(AFEINTC_1, AFEINTSRC_ALLINT, bTRUE);   /* Enable all interrupt in INTC1, so we can check INTC flags */
  AD5941_INTCClrFlag(AFEINTSRC_ALLINT);
  AD5941_INTCCfg(AFEINTC_0, AFEINTSRC_DATAFIFOTHRESH, bTRUE); 
  AD5941_INTCClrFlag(AFEINTSRC_ALLINT);
  /* Step4: Reconfigure GPIO */
  gpio_cfg.FuncSet = GP0_INT|GP1_SLEEP|GP2_SYNC;
  gpio_cfg.InputEnSet = 0;
  gpio_cfg.OutputEnSet = AGPIO_Pin0|AGPIO_Pin1|AGPIO_Pin2;
  gpio_cfg.OutVal = 0;
  gpio_cfg.PullEnSet = 0;
  AD5941_AGPIOCfg(&gpio_cfg);
  AD5941_SleepKeyCtrlS(SLPKEY_UNLOCK);  /* Allow AFE to enter sleep mode. */
  return 0;
}

/* Initial settings of Impedance */
void AD5941ImpedanceStructInit(void)
{
  AppIMPCfg_Type *pImpedanceCfg;
  
  AppIMPGetCfg(&pImpedanceCfg);
  /* Step1: configure initialization sequence Info */
  pImpedanceCfg->SeqStartAddr = 0;
  pImpedanceCfg->MaxSeqLen = 512; /* @todo add checker in function */

  pImpedanceCfg->RcalVal = 215.0; // Evaluation board standard: 10000.0
  // Test board: 225, 230
  pImpedanceCfg->SinFreq = 10000.0;
  pImpedanceCfg->FifoThresh = 4;
	
  /* Set switch matrix to onboard(EVAL-AD5940ELECZ) dummy sensor. */
  /* Note the RCAL0 resistor is 10kOhm. */
  pImpedanceCfg->DswitchSel = SWD_CE0;
  pImpedanceCfg->PswitchSel = SWP_RE0;
  pImpedanceCfg->NswitchSel = SWN_SE0;  // Note, original: SWT_SE0
  pImpedanceCfg->TswitchSel = SWT_SE0LOAD; // Note, original: SWT_SE0LOAD
  /* The dummy sensor is as low as 5kOhm. We need to make sure RTIA is small enough that HSTIA won't be saturated. */
  pImpedanceCfg->HstiaRtiaSel = HSTIARTIA_10K; // Can use number to replace	
  
  // #define HSTIARTIA_200               0     /**< HSTIA Internal RTIA resistor 200  */
  // #define HSTIARTIA_1K                1     /**< HSTIA Internal RTIA resistor 1K   */
  // #define HSTIARTIA_5K                2     /**< HSTIA Internal RTIA resistor 5K   */
  // #define HSTIARTIA_10K               3     /**< HSTIA Internal RTIA resistor 10K  */
  // #define HSTIARTIA_20K               4     /**< HSTIA Internal RTIA resistor 20K  */
  // #define HSTIARTIA_40K               5     /**< HSTIA Internal RTIA resistor 40K  */
  // #define HSTIARTIA_80K               6     /**< HSTIA Internal RTIA resistor 80K  */
  // #define HSTIARTIA_160K              7     /**< HSTIA Internal RTIA resistor 160K */
  // #define HSTIARTIA_OPEN              8     /**< Open internal resistor */
  
  /* Configure the sweep function. */
  pImpedanceCfg->SweepCfg.SweepEn = bTRUE;
  pImpedanceCfg->SweepCfg.SweepStart = 10000.0;	/* Start from 1kHz */
  pImpedanceCfg->SweepCfg.SweepStop = 1.0;		/* Stop at 100kHz */
  // 10000Hz - 1000Hz is the best region of measurement.
  // Using the parameters below 1000Hz may cause incorrect data output spontinously.
  
  pImpedanceCfg->SweepCfg.SweepPoints = 41;		/* Points is 101 */
  pImpedanceCfg->SweepCfg.SweepLog = bTRUE;
  /* Configure Power Mode. Use HP mode if frequency is higher than 80kHz. */
  pImpedanceCfg->PwrMod = AFEPWR_LP;
  /* Configure filters if necessary */
  // pImpedanceCfg->ADCSinc3Osr = ADCSINC3OSR_4;		/* Sample rate is 800kSPS/2 = 400kSPS */
  pImpedanceCfg->ADCSinc2Osr = ADCSINC2OSR_44;
  
  pImpedanceCfg->DftNum = DFTNUM_16384;
  // pImpedanceCfg->DftSrc = DFTSRC_SINC3;                 /* High speed mode */
  pImpedanceCfg->DftSrc = DFTSRC_SINC2NOTCH;            /* Low speed mode */
  
  // pImpedanceCfg->DftSrc = DFTSRC_ADCRAW;
  
  pImpedanceCfg->AdcPgaGain = ADCPGA_1P5;               /* PGA gain select 1 (Original setting)*/
  
  pImpedanceCfg->ExcitBufGain = EXCITBUFGAIN_0P25;
  // pImpedanceCfg->HsDacGain = HSDACGAIN_1;
  pImpedanceCfg->HsDacGain = HSDACGAIN_0P2;
  // HSDACGAIN_1
  pImpedanceCfg->DacVoltPP = 200; // DC, min = 200mV
  pImpedanceCfg->BiasVolt =  -18.3;
  // BiasVolt = -18.3 mV
  /* Configure Excitation Waveform 
	*
  *	 Output waveform = DacVoltPP * ExcitBufGain * HsDacGain 
	* 	
	*		= 300 * 0.25 * 0.2 = 15mV pk-pk ac
	*
	*/
  
}

/* Initiali settings of CV */
void AD5940RampStructInit(void) // COMPLIE FROM THIS SESSION, main function
{
  AppRAMPCfg_Type *pRampCfg;
  
  AppRAMPGetCfg(&pRampCfg);
  
  /* Step1: configure general parmaters */
  pRampCfg->SeqStartAddr = 0x10;                /* leave 16 commands for LFOSC calibration.  */
  pRampCfg->MaxSeqLen = 1024-0x10;              /* 4kB/4 = 1024  */
  pRampCfg->RcalVal = 10000.0;                  /* 10kOhm RCAL */   
  // Evaluation board: 10000
  // Test circuit: 220, 230
  // PCB Impedance Project: 210
  // PCB CV Project: ? in passive unit combination
  // PCB CV Project: 350, 400 in hexacyanoferrate, Potassium hexacyanoferrate and PBS combination
  // PCB CV Project: 210 in PBS
  
  pRampCfg->ADCRefVolt = 1820.0f;               /* The real ADC reference voltage. Measure it from capacitor C12 with DMM. */
  pRampCfg->FifoThresh = 480;                   /* Maximum value is 2kB/4-1 = 512-1. Set it to higher value to save power. */ 
  pRampCfg->SysClkFreq = 16000000.0f;           /* System clock is 16MHz by default */
  pRampCfg->LFOSCClkFreq = LFOSCFreq;           /* LFOSC frequency */
  /* Configure ramp signal parameters */
  // pRampCfg->RampStartVolt =  -300.0f;           /* -0.3V */
  // pRampCfg->RampPeakVolt = 2300.0f;           /* +2.3V */
  
  // Need to invert the range of voltage you want to measure
  pRampCfg->RampStartVolt = 600.0f;               /* -0.5V */
  pRampCfg->RampPeakVolt = -600.0f;               /* 0.5V */
  
  pRampCfg->VzeroStart = 1300.0f;               /* 1.3V */
  pRampCfg->VzeroPeak =  1300.0f;                /* 1.3V , midscale of the LPDAC*/
  
  pRampCfg->StepNumber = 240;                   /* Total steps. Equals to ADC sample number, originally = 800 */
  // pRampCfg->RampDuration = 24*1000;            /* X * 1000, where x is total duration of ramp signal. Unit is ms. */
  pRampCfg->RampDuration = 20*1000;            
  // pRampCfg->SampleDelay = 7.0f;                 /* 7ms. Time between update DAC and ADC sample. Unit is ms. */
  pRampCfg->SampleDelay = 20.0f;
  pRampCfg->LPTIARtiaSel = LPTIARTIA_2K;       /* Maximum current decides RTIA value */
                                                 // 200 -> 200R
  pRampCfg->LPTIARloadSel = LPTIARLOAD_SHORT; // Choose the suitable Rload here
  // pRampCfg->LPTIARloadSel = LPTIARLOAD_100R;
  pRampCfg->AdcPgaGain = ADCPGA_1P5;            // We must ensure signal is in range of +-1.5V which is limited by ADC input stage
     
  pRampCfg->ADCSinc3Osr = ADCSINC3OSR_4;
  
  // The postive peak voltage = RampPeakVolt - VzeroStart, 2300-1300=1000(+1V)
  // On the other hand, the negative peak voltage = -(VzeroStart) - RampStartVolt, 300 - 1300 = -1000(-1V)
  // The range of signal = +-1V
  // 0.4
  
}

void AD5941_Main(void)
{
  // uint32_t temp;  
  // int Manutrg = 0;
  
  AD5941PlatformCfg();
  
  if(AD5941_Impedance_Mode)
  {
    AD5941ImpedanceStructInit(); // Initialize system, also calibrate manual

    AppIMPInit(AppBuff, APPBUFF_SIZE);    /* Initialize IMP application. Provide a buffer, which is used to store sequencer commands */
    
    // Start measurment
    AD5941_Impedance_measurement(42);
  }
  else if(AD5941_CV_Mode)
  {
    AD5940RampStructInit();
    
    AppRAMPInit(AppBuff, APPBUFF_SIZE);    /* Initialize RAMP application. Provide a buffer, which is used to store sequencer commands */
    
    // Start measurement
    AD5941_CV_measurement(6);
  }
  

}

//**********************************************************************************************************************
//
// Copyright (C) 2022, UTL
//
//! @fn                  AD5941_Impedance_measurement
//
//! @author 	         WTC
//
//! @date 		 2021/10
//
//! @brief 		 measurement function in impedance mode
//
//! @param 		 Number of measuring data
//
//! @return 	         None
//
//**********************************************************************************************************************

void AD5941_Impedance_measurement(int MeasureNum)
{
  uint32_t temp;
  AppIMPCtrl(IMPCTRL_START, 0);
  
  while(MeasureNum > counter)
  { 
    // uint32_t rd;
    
    if(AD5941_GetMCUIntFlag())
    {    
      MData.counter = counter;
      
      AD5941_ClrMCUIntFlag(); // clear the flag
      temp = APPBUFF_SIZE;
      AppIMPISR(AppBuff, &temp); // Data start from this section
     
      ImpedanceShowResult(AppBuff, temp);
      
      // rd = AD5940_ReadAfeResult(AFERESULT_SINC2);
      // float diff_volt = AD5940_ADCCode2Volt(rd, ADCPGA_1P5, 1.82);
      // printf("ADC Code:%d, diff-volt: %.4f, volt:%.4f\n",rd, diff_volt, diff_volt+1.11);
      
      // rd = AD5940_ReadAfeResult(AFERESULT_SINC2);
      // float diff_volt = AD5940_ADCCode2Volt(rd, ADCPGA_1P5, 1.82);
      
      // printf("ADC Code:%d, diff-volt: %.4f, volt:%.4f\n",rd, (-1)*diff_volt, diff_volt+1.11);
      // MData.tADCvolt[counter] = diff_volt;
      
      counter++;
    }
  }
  
  if(MeasureNum == counter)
  {
    counter = 0;
    AppIMPCtrl(IMPCTRL_STOPNOW, 0);
    AD5941_Delay10us(10);
  }
  
}

//**********************************************************************************************************************
//
// Copyright (C) 2022, UTL
//
//! @fn                  AD5941_CV_measurement
//
//! @author 	         WTC
//
//! @date 		 2022/02
//
//! @brief 		 measurement function in CV mode, a measurement will generate 240 data. If you want to tune it, please calculate in detail.
//
//! @param 		 The cycle of measurement
//
//! @return 	         None
//
//**********************************************************************************************************************
void AD5941_CV_measurement(int MeasureCycleNum)
{
  uint32_t temp; 
  float V_list[4];
  
  AppRAMPCfg_Type *pRampCfg;	
  
  AppRAMPGetCfg(&pRampCfg);
  V_list[0] = (pRampCfg->RampPeakVolt - pRampCfg->RampStartVolt) / (pRampCfg->StepNumber/2);        // Vstep phase 1
  V_list[1] = -(V_list[0]);             // Vstep phase 2
  V_list[2] = pRampCfg->RampStartVolt;  // Voltage initially
  V_list[3] = pRampCfg->RampStartVolt;  // Voltage recently
  
  AppRAMPCtrl(APPCTRL_START, 0);          /* Control RAMP measurement to start. Second parameter has no meaning with this command. */

  // while(1)
  while(MeasureCycleNum > counter)
  {
    if(AD5941_GetMCUIntFlag())
    {
      MData.counter = counter;
      
      AD5941_ClrMCUIntFlag();
      temp = APPBUFF_SIZE;
      AppRAMPISR(AppBuff, &temp);       // ** //
      RampShowResult((float*)AppBuff, temp, (float*)V_list, pRampCfg->StepNumber);
    }
		/* Repeat Measurement continuously*/
		if(pRampCfg->bTestFinished == bTRUE)
		{
			AD5941_Delay10us(200000);
			pRampCfg->bTestFinished = bFALSE;
			AD5941_SEQCtrlS(bTRUE);   /* Enable sequencer, and wait  for trigger */
			AppRAMPCtrl(APPCTRL_START, 0);  // Control the waveform sequence from DAC
		}
    
    if(MeasureCycleNum == counter)
    {
      counter = 0;
      AppRAMPCtrl(APPCTRL_STOPNOW, 0);
      AD5941_Delay10us(10);
    }
    
  }
}

//**********************************************************************************************************************
//
// Copyright (C) 2022, UTL
//
//! @fn                  SPI_test
//
//! @author 	         WTC
//
//! @date 		 2022/02
//
//! @brief 		 SPI Transferring test
//
//! @param 		 None
//
//! @return 	         None
//
//**********************************************************************************************************************

void SPI_test(void)
{
  UINT8 TX_Buffer[2] = {0xF3, 0x69};    
  UINT8 RX_Buffer[2] = {0, 0};
  int Buffer_length = 2; // sizeof(TX_Buffer);
  // SPI_Para.SPI_TX[0] = *TX;
  
  // SCLK initialize
  // AD5941_SCLK_LOW(); 

  // SPI Initialize
  // FK_SPI1_ENABLE_API(TX_Buffer, 16);
  
  /*
  AD5941_CsSet();
  AD5941_CsClr();
  AD5941_CsSet();
  */
  
  // SPI Test
  while(1)
  {
    // AD5941_CsClr();
    
    // for(int i = 0; i<8; i++)
    // {
      // AD5941_SCLK_HIGH();
      // AD5941_MOSI_HIGH();
      
      // AD5941_SCLK_LOW();
      // AD5941_MOSI_LOW();
    // }

    AD5941_ReadWriteNBytes(TX_Buffer, RX_Buffer, Buffer_length);
    // AD5941_Delay10us(0.2*10); // 10 = 10us
    // AD5941_CsSet();
    
  }
}

//**********************************************************************************************************************
//
// Copyright (C) 2022, UTL
//
//! @fn                  ad5941_TX_data_transmit
//
//! @author 	         WTC
//
//! @date 		 2022/02
//
//! @brief 		 BLE data transferring
//
//! @param 		 Impedance using - Frequency, Impedance, Phase, CV using - Volt, Current
//
//! @return 	         None
//
//**********************************************************************************************************************

void AD5941_TX_data_transmit(float Freq, float Impedance, float Phase, float Volt, float Current)
{
  if(AD5941_Impedance_Mode)
  {
    float buffer_temp1;
    float buffer_temp2;
    float buffer_temp3;
    
    /* Transfer the integer data */
    PFC_AD5941_IMPEDANCE_FREQ_INT = (int)Freq;
    buffer_temp1 = Freq - (int)Freq;
  
    PFC_AD5941_IMPEDANCE_MAG_INT = (int)Impedance;
    buffer_temp2 = Impedance - (int)Impedance;
  
    PFC_AD5941_IMPEDANCE_PHASE_INT = (int)Phase;
    buffer_temp3 = Phase - (int)Phase;
    
    for(int i=0; i<5; i++)
    {
      buffer_temp1 *= 10;
      buffer_temp2 *= 10;
      buffer_temp3 *= 10;
    }
  
    /* Transfer the decimal data */
    PFC_AD5941_IMPEDANCE_FREQ_DECI = (int)buffer_temp1;
    PFC_AD5941_IMPEDANCE_MAG_DECI = (int)buffer_temp2;
    PFC_AD5941_IMPEDANCE_PHASE_DECI = (int)buffer_temp3;
  }
  else if(AD5941_CV_Mode)
  {
    float buffer_temp1;
    float buffer_temp2;
    
    /* Transfer the integer data */
    PFC_AD5941_RAMP_VOL_INT = (int)Volt;
    buffer_temp1 = Volt - (int)Volt;
  
    PFC_AD5941_RAMP_CURRENT_INT = (int)Current;
    buffer_temp2 = Current - (int)Current;

    for(int i=0; i<5; i++)
    {
      buffer_temp1 *= 10;
      buffer_temp2 *= 10;
    }
  
    /* Transfer the decimal data */
    PFC_AD5941_RAMP_VOL_DECI = (int)buffer_temp1;
    PFC_AD5941_RAMP_CURRENT_DECI = (int)buffer_temp2;
  }
  
}

//**********************************************************************************************************************
//
// Copyright (C) 2022, UTL
//
//! @fn                  ad5941_init
//
//! @author 	         WTC
//
//! @date 		 2022/02
//
//! @brief 		 AD5941 initialize
//
//! @param 		 None
//
//! @return 	         None
//
//**********************************************************************************************************************

void ad5941_init()
{
	ad5941_sfr_init();
	ad5941_glb_vars_init();
        
        // HAL_Init();
        
        AD5941_Main();
        
        // SPI Testing
        // SPI_test();

}
