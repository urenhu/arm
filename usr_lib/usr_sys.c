#include "usr_sys.h"

//define system wide globals ==========================
#ifdef SYSTEM_SUPPORT_FREERTOS
xSemaphoreHandle   xBinarySemaphore;  // for uart interrupt to signal uart application
#endif 

//define system wide routines  ==========================
/**
  * @brief  NVIC_Config 
  * @param  None
  * @retval None
  */
void NVIC_Configuration(void)
{
  NVIC_InitTypeDef NVIC_InitStructure; 
	
	//NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0);  // NVIC_SetVectorTable(NVIC_VectTab_RAM, 0);
  // Enable the TIM1 Interrupt
  NVIC_InitStructure.NVIC_IRQChannel = TIM1_CC_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);

  // Enable the ADC1 Interrupt
  NVIC_InitStructure.NVIC_IRQChannel = ADC1_2_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);

  // Enable the DMA1 channel1 Interrupt
  NVIC_InitStructure.NVIC_IRQChannel = DMA1_Channel1_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;

#ifdef SYSTEM_SUPPORT_FREERTOS
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);  
#else
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	
#endif  
  NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;				
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;					
  NVIC_Init(&NVIC_InitStructure);
  
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
}


