/*************************************
 *
**************************************/ 
#include "usr_sys.h"
#include "queue.h"	  
#include "usr_usart.h"	  

typedef struct tagUSR_USART {   
   QUEUE    qrx;
   u32      baud ; 
}  USR_USART  ;

static USR_USART   usartObj1 ; 

#ifndef  __USE_MICRILIB__

#pragma import(__use_no_semihosting)             
struct __FILE {	int handle; }; 
FILE   __stdout;       

_sys_exit(int x) { 	x = x; } 

// override fputc 
int fputc(int ch, FILE *f)
{      
	while(USART_GetFlagStatus(USART1,USART_FLAG_TC)==RESET); 
    USART_SendData(USART1,(uint8_t)ch);   
	return ch;
}
#endif 

#ifdef  __USE_MICRILIB__
int fputc(int ch, FILE *f)
{
	USART_SendData(USART1, (uint8_t) ch);
	while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET) {}	
    return ch;
}

int GetKey (void)  { 
    while (!(USART1->SR & USART_FLAG_RXNE));
    return ((int)(USART1->DR & 0x1FF));
}
#endif 

void usart_init( u32 bound)
{
    GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1|RCC_APB2Periph_GPIOA, ENABLE);	  // uses  USART1£¬ and GPIOA clocking
 	USART_DeInit(USART1);  

	//USART1_TX   PA.9
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9; //PA.9
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	
    GPIO_Init(GPIOA, &GPIO_InitStructure); // PA9
   
    //USART1_RX	  PA.10
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOA, &GPIO_InitStructure);  // PA10

   //USART 
	USART_InitStructure.USART_BaudRate = bound;                   //default 9600;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	// IMPORTANT!

    USART_Init(USART1, &USART_InitStructure); 

   //Usart1 NVIC config 
    NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3 ;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority        = 3 ;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;	//IRQ enable 
	NVIC_Init(&NVIC_InitStructure);
   
    USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
	
    USART_Cmd(USART1, ENABLE);

    initQueue ( &usartObj1.qrx); 
    usartObj1.baud         = bound; 
} //end 


// irq handler 
void USART1_IRQHandler(void)                	
{
	u8    res;
#ifdef SYSTEM_SUPPORT_FREERTOS	 	
	//portBASE_TYPE xHigherPriorityTaskWoken;
	//xSemaphoreGiveFromISR(xBinarySemaphore,&xHigherPriorityTaskWoken);
	//portEND_SWITCHING_ISR(xHigherPriorityTaskWoken);  // this is not a good way !
#endif
	

	if ( USART_GetITStatus(USART1, USART_IT_RXNE) != RESET ){
		  res  =  USART_ReceiveData(USART1);  //(USART1->DR);
		  enQueue( &usartObj1.qrx, res);
  } 
} 

int usart_getc (void)  
{ 
    u8   data; 
    if ( deQueue ( &usartObj1.qrx, &data) == -1 ){
		return 0;
	} else {
		return (int) (data &0xFF);
	}
}

int usart_hitkey (void)  
{ 
    u8   data; 
    while ( deQueue ( &usartObj1.qrx, &data) == -1 );
    return (int) (data &0xFF);
}



