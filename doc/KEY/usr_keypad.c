/*********************************  *************************************
* Copyright (c) 2017
* All rights reserved.
*******************************************************************************/
#include "stm32f10x.h"
#include "key.h"

void KEY_Init(void) {
   GPIO_InitTypeDef GPIO_InitStructure;

   RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); 
   GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_3 | GPIO_Pin_2 | GPIO_Pin_1;
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 
   GPIO_Init(GPIOA, &GPIO_InitStructure);        
   GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0;
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 
   GPIO_Init(GPIOA, &GPIO_InitStructure);        
}

u8 KEY_Scan(u8 mode) {
   static u8 key_up = 1; 
   if (mode) key_up = 1; 
   if (key_up && (KEY0 == 0 || KEY1 == 0 || KEY2 == 0 || WK_UP == 0)){
      delay_ms(10); 
      key_up = 0;
      if (KEY2 == 0) return KEY2_PRES;
      else if (KEY1 == 0) return KEY1_PRES;
      else if (KEY0 == 0) return KEY0_PRES;
      else if (WK_UP == 0) return WKUP_PRES; 
   } else if (KEY0 == 1 && KEY1 == 1 && KEY2 == 1 && WK_UP == 1)
      key_up = 1;
   return 0;
}

void WaitKey(void) {
   while ((GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_3))) {
      delay_ms(10);
   }
   delay_ms(10);
   while (!(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_3)));
   delay_ms(10);
}


#define WKUP_PRES       0x01   
#define DOWN_PRES 	0x02   
#define ENTER_PRES	0x04   
#define ESC_PRES	0x08   
unsigned char	        TrgDown = 0x00;
unsigned char           TrgUp = 0x00;
unsigned char           Prev = 0x00;
u8                      auto_key,disp_num,disp_num_tem,Key_flag,f_num;

void KeyRead() {
   static u8 Curr = 0;
   static u8 tmp, i = 0, ii = 0;
   if (ii == 0) {
      ii = 1;
      tmp = ((GPIOA->IDR ^ 0xff));
      return;
   } else {
      ii = 0;
      Curr = ((GPIOA->IDR ^ 0xff));
      if (Curr != tmp)  return;
   }
   Curr = (Key1 << 1);            
   Curr = (Key2 << 2);            
   Curr = (Key3 << 3);            
   Curr = (Key4 << 0);            
   TrgDown = Curr & (Curr ^ Prev);
   TrgUp   = Prev & (Curr ^ Prev);
   Prev = Curr;                   
}

void KeyProcess() {
   static u8 Curr;

   if (TrgDown & ESC_PRES){
      auto_key = 0; 
      Key_flag = 1;                       
      disp_num++;
      if (disp_num == 7) 
         disp_num_tem = 0;
   } else if (TrgDown & ENTER_PRES) {
      auto_key = 1;            
      Key_flag = 1;            
      disp_num = disp_num_tem; 
   } else if (TrgDown & WKUP_PRES) {
      auto_key = 1;
      Key_flag = 1;
      if (disp_num == 7){
         disp_num_tem = 0; 
      } else {
         disp_num_tem--;
      }
   } else if (TrgDown & DOWN_PRES) {
      auto_key = 1;
      Key_flag = 1;
      if ((disp_num++) == 8){
         disp_num_tem = 0;	
      } else {
         disp_num_tem++;
      }
   } else {
      auto_key = 0; 
      Key_flag = 0; 
      if ((disp_num++) == 8){
         disp_num_tem = 0;	
      } else {
         disp_num_tem++;
      }
   }
}

void Scan_Key(void) {
   KeyRead();
   KeyProcess();
}

