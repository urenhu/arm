#ifndef __RS485_H
#define __RS485_H			 
#include "usr_sys.h"	 								  
	  		  	
//extern u8 RS485_RX_BUF[64]; 		//接收缓冲,最大64个字节
//extern u8 RS485_RX_CNT;   			//接收到的数据长度
//#define RS485_TX_EN		PGout(9)	//485模式控制.0,接收;1,发送.
//#define EN_USART2_RX 	1			//0,不接收;1,接收.

void RS485_Init(u32 bound);
void RS485_Send_Data(u8 *buf,u8 len);
void RS485_Receive_Data(u8 *buf,u8 *len);

#endif	   
















