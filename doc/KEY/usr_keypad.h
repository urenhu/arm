/**********************************************************************
* Copyright (c) 2017 
* All rights reserved.
*******************************************************************************/
#ifndef __USR_KEYPAD_H
#define __USR_KEYPAD_H
#include "stm32f10x.h"

//////////////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////////////////
#define Key1 GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_1)
#define Key2 GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_2)
#define Key3 GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_3)
#define Key4 GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0)
#define WKUP_PRES          0x01 
#define DOWN_PRES          0x02 
#define ENTER_PRES         0x04 
#define ESC_PRES           0x08 

void KEY_Init(void);
u8   KEY_Scan(u8);
void WaitKey(void);
void KeyRead();
void KeyProcess();
void Scan_Key(void);

#endif



