#ifndef NB_UBLOX_IDEF_H
#define NB_UBLOX_IDEF_H
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 nb_ublox_idef.h
//
//! @author 	 Vic.Chen
//
//! @date 		 2018/09/05
//
//  @brief 		 Here define internal constant
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// E X T E R N A L   G L O B A L   C O N S T A N C E   /   V A R I A B L E S   I N   E E P R O M 
//
//**********************************************************************************************************************
// usrt direction (gb_ehs_uart_direction)
enum
{
    NB_UBLOX_UART_RECEIVE = 0,
    NB_UBLOX_UART_SEND,
};

//===== NB1 module status (gb_ehs_ststus)======
enum
{
    NB_UBLOX_MODULE_READY = 0,
    NB_UBLOX_INIT_TASK,
    NB_UBLOX_IDEL,
    NB_UBLOX_SOCKET_CONNECT_TASK,
    NB_UBLOX_SOCKET_CLOSE_TASK, 
    NB_UBLOX_STANDBY, 
    NB_UBLOX_SEND_CMD,
    NB_UBLOX_SEND_DATA,		
    NB_UBLOX_SEND_ACK,
    NB_UBLOX_RECEIVE_DATA,
    NB_UBLOX_ERROR,
    NB_UBLOX_POWER_ON,
    NB_UBLOX_POWER_OFF,
    NB_UBLOX_POWER_TOTAL,
};

//===== ehs init task command order======
enum
{
    NB_UBLOX_ORDER_ATZ = 0,
    NB_UBLOX_ORDER_ATE,
    //NB_UBLOX_ORDER_AT,
    NB_UBLOX_ORDER_URAT,
    NB_UBLOX_ORDER_CMEE,
    //NB_UBLOX_ORDER_SCFG,
    //NB_UBLOX_ORDER_SLED,
    //NB_UBLOX_ORDER_ATI,
    //NB_UBLOX_ORDER_COPS,
    NB_UBLOX_ORDER_COPS0,
    NB_UBLOX_ORDER_LED_INIT,
    NB_UBLOX_ORDER_CGDCONT,
    NB_UBLOX_ORDER_OK,
};

//===== ehs online command order======
//enum
//{
//    NB_UBLOX_ORDER_ONLINE_1 =0,  //AT+CGDCONT=1,"IP","APN_name" or  AT+CGDCONT=1,"IPV4V6","APN","0.0.0.0 0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0",0,0
    //NB_UBLOX_ORDER_ONLINE_2,  //AT+CGDCONT?
//    NB_UBLOX_ORDER_ONLINE_OK,
//};

//===== ehs offlink command order=====
enum
{
    NB_UBLOX_ORDER_OFF_1 = 0, //AT+USOCL
    NB_UBLOX_ORDER_OFF_OK,
};

//===== ehs power off command order===
enum
{
    NB_UBLOX_ORDER_PWR_OFF_1 = 0, //AT+CPWROFF
    NB_UBLOX_ORDER_PWR_OFF_2,  //Power Pin Reset
    NB_UBLOX_ORDER_PWR_OFF_OK,
};

//===== connect task command order===
enum
{
    NB_UBLOX_ORDER_ONLINE_1 = 0, //AT+USOCR
    NB_UBLOX_ORDER_ONLINE_2,  //at+udconf=8,0,1000
	NB_UBLOX_ORDER_ONLINE_3,  //AT+USOCO=0,"xxx.xxx.xxx.xxx",xxxx,1
	NB_UBLOX_ORDER_ONLINE_4,  //AT+USODL=0
	NB_UBLOX_ORDER_ONLINE_OK,
};

//===== send task command order===
enum
{
    NB_UBLOX_ORDER_NET_SEND_1,       //at+usowr=
    NB_UBLOX_ORDER_NET_SEND_2,      //data
    NB_UBLOX_ORDER_NET_SEND_3,      //at+usord=0,250
};

//===== socket status ===
enum
{
    NB_UBLOX_INACTIVE = 0, //
    NB_UBLOX_LISTEN,
    NB_UBLOX_SYN_SENT,
    NB_UBLOX_SYN_RCVD,
    NB_UBLOX_ESTABILSHED,
    NB_UBLOX_FIN_WATE_1,
    NB_UBLOX_FIN_WATE_2,
    NB_UBLOX_CLOSE_WAIT,
    NB_UBLOX_CLOSING,
    NB_UBLOX_LAST_ACK,
    NB_UBLOX_TIME_WAIT,
};


//#define NB_UBLOX_CMD_SCFG			"AT^SCFG=\"Gpio/mode/SYNC\",\"std\"\r\n"
//#define NB_UBLOX_CMD_SLED			"AT^SLED=2\r\n"
//#define NB_UBLOX_READY_STR			"+PBREADY"
#define NB_UBLOX_CMD_ATZ			"ATZ\r\n"		 // command init
#define NB_UBLOX_CMD_AT				"AT\r\n"		 // command init
#define NB_UBLOX_CMD_ATE			"ATE0\r\n" 	 // command Echo
#define NB_UBLOX_CMD_ATI			"ATI\r\n"		 // command init
#define NB_UBLOX_CMD_CPWROFF		"AT+CPWROFF\r\n"  // module power off
//#define NB_UBLOX_CMD_CEER			"AT+CEER\r\n"  //Exrwnded Error Report
//#define NB_UBLOX_CMD_ATH			"ATH\r\n"		 //Disconnect existing connection
#define NB_UBLOX_CMD_COPS			"AT+COPS?\r\n"	 //op status selection
#define NB_UBLOX_CMD_CMEE			"AT+CMEE=1\r\n"  //read error code
#define NB_UBLOX_CMD_CGDCONT		"AT+CGDCONT?\r\n" //cgdcont
#define NB_UBLOX_CMD_URAT               "AT+URAT=8\r\n"
#define NB_UBLOX_CMD_COPS0              "AT+COPS=0\r\n"
/*====================NB1 connect server program=====================*/
#define NB_UBLOX_PRO_1				"at+usocr=6\r\n"
#define NB_UBLOX_PRO_2				"at+udconf=8,0,1000\r\n"
#define NB_UBLOX_PRO_3				"at+usoco=0,\""
#define NB_UBLOX_PRO_3_end			",1\r\n"
#define NB_UBLOX_PRO_4				"at+USODL=" //socket in Direct Link mode
/*====================NB1 disconnect server program=====================*/
#define NB_UBLOX_OFF_LINE_1			"+++\r\n"	 	 //switch for data mode or ppp online mode to command mode
#define NB_UBLOX_OFF_LINE_2			"AT\r\n"
#define NB_UBLOX_OFF_LINE_3			"AT^SISC=0\r\n"  //off line 
/*====================outh command==============================*/
#define NB_UBLOX_NET_STATUS 		"at+usoer\r\n"
#define NB_UBLOX_NET_SEND			"at+usowr="
#define NB_UBLOX_NET_RECEIVE		"at+usord=0,250\r\n"
#define NB_UBLOX_MAX_BUFFER			512
#define NB_UBLOX_MAX_SMS_BUFFER  	160
#define NB_UBLOX_LED_INIT			"AT+UGPIOC=16,0\r\n"  //init led
#define NB_UBLOX_LED_GREEN		    "AT+UGPIOW=16,0\r\n"  //turn gree
#define NB_UBLOX_LED_RED		    "AT+UGPIOW=16,1\r\n"  //turn red
#define NB_UBLOX_OK					"OK"
#define NB_UBLOX_MAX_SMS_NM_BUFFER  	20
#define NB_UBLOX_CGDCONT_TIME		5

#endif		// NB_UBLOX_IDEF_H 
