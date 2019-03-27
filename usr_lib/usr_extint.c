/*************************************************
* @module: usr_extint.c
* @author: tw
* @date:
* @description:
 *************************************************
***/
#include "stm32f10x.h"
#include "stm32f10x_exti.h"
#include "usr_extint.h"

/*************************************************
 * 
 * 
***/
void EXTIX_Init(void)
{
 	EXTI_InitTypeDef EXTI_InitStructure;
 	NVIC_InitTypeDef NVIC_InitStructure;

  // GPIO first be set as input . i.e. KEY_Init()

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);	
	
  GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource2);
  EXTI_InitStructure.EXTI_Line    = EXTI_Line2;	            
  EXTI_InitStructure.EXTI_Mode    = EXTI_Mode_Interrupt;	
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);	 	
	
  GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource3);
  EXTI_InitStructure.EXTI_Line    = EXTI_Line3;
  EXTI_InitStructure.EXTI_Mode    = EXTI_Mode_Interrupt;	
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
  EXTI_Init(&EXTI_InitStructure);	 

  GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource4);
  EXTI_InitStructure.EXTI_Line    = EXTI_Line4;
  EXTI_InitStructure.EXTI_Mode    = EXTI_Mode_Interrupt;	
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
  EXTI_Init(&EXTI_InitStructure);

 	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource0); 
 	EXTI_InitStructure.EXTI_Line    = EXTI_Line0;
  EXTI_InitStructure.EXTI_Mode    = EXTI_Mode_Interrupt;	
  // EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
 	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
 	EXTI_Init(&EXTI_InitStructure);	

  // ============ IRQxxx ==============================
 	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;		
 	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x03;
 	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
 	NVIC_Init(&NVIC_InitStructure); 

  NVIC_InitStructure.NVIC_IRQChannel = EXTI2_IRQn;			        
 	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	
 	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;					
 	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
 	NVIC_Init(&NVIC_InitStructure);

 	NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;		        	
 	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02; 
 	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;				 
 	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;					
 	
	NVIC_Init(&NVIC_InitStructure);  	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn;			        
 	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	 
 	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;					 
 	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								
 	NVIC_Init(&NVIC_InitStructure);  	  
  //================================================================
}


/*************************************************
* function: interrupt handler  
 * 
***/
void EXTI0_IRQHandler(void)
{
	if ( GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0) == 1 ){
		//BEEP=!BEEP;	rasie event 1, enqueue key code 1
	}
	EXTI_ClearITPendingBit(EXTI_Line0); 
}
 
/*************************************************
 * 
 * 
***/
void EXTI2_IRQHandler(void)
{
	if( GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_2) == 0 ){
		// LED0=!LED0;
	}		 
	EXTI_ClearITPendingBit(EXTI_Line2);  //清除LINE2上的中断标志位  
}

/*************************************************
 * 
 * 
***/
void EXTI3_IRQHandler(void)
{
	if ( GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3) == 0 ){				 
		// LED1=!LED1;
	}		 
	EXTI_ClearITPendingBit(EXTI_Line3);
}

/*************************************************
 * 
 * 
***/
void EXTI4_IRQHandler(void)
{
	if( GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4) == 0 ){
		// LED0=!LED0;
		// LED1=!LED1; 
	}		 
	EXTI_ClearITPendingBit(EXTI_Line4);
}
 
