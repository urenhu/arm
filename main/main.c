/******************************************************************************
  * @file     main.c 
  * @author   tom wu 
  * @version  0.0
  * @date     
  * @brief    for application uses free rtos to inlcude 
  ******************************************************************************
  */ 

#include "usr_sys.h"  // this is tell if project use RTOS

#include "usr_led.h"
#include "usr_delay.h"
#include "usr_key.h"
#include "usr_sys.h"
#include "usr_usart.h"
#include "usr_timer.h"
#include "usr_adc.h"
#include "usr_tsensor.h"
#include "usr_rtc.h" 		    
#include "usr_fram.h" 		    
#include "console.h"
#include "main.h"

//=====================
// global
//=====================
xQueueHandle             USART1_MSGQ;                      //To receive the usart characters's queue
volatile unsigned long   mainDELAY_LOOP_COUNT = 0xffff;


void vTask1( void *pvParameters )
{
	volatile unsigned long   ul;
	for( ;; ){	//	xSemaphoreTake( xBinarySemaphore, portMAX_DELAY );
		xQueueSend( USART1_MSGQ, "This is task 1 !\n",portMAX_DELAY);
		for( ul = 0; ul < mainDELAY_LOOP_COUNT; ul++ );
	}
}
void vTask2( void *pvParameters )
{
	volatile unsigned long ul;
	for( ;; ){
		xQueueSend( USART1_MSGQ, "This is task 2 !\n",portMAX_DELAY);
		for( ul = 0; ul < mainDELAY_LOOP_COUNT; ul++ );
	}
}


void USART1OUT( void *pvParameters )
{
	static char str[100];
	volatile unsigned long ul;
	for( ;; )	{
		//while( xQueueReceive( USART1_MSGQ, str, portMAX_DELAY ) != pdPASS );
		xQueueReceive( USART1_MSGQ, str, portMAX_DELAY );
		// printf("%s",str);
	}
}

void vTask3( void *pvParameters )
{
	volatile unsigned long ul;
	for( ;; ){
		xQueueSend( USART1_MSGQ, "This is task 3 !\n",portMAX_DELAY);
		for( ul = 0; ul < mainDELAY_LOOP_COUNT; ul++ );
	}
}

void vTaskIdle( void *pvParameters )
{
	  console_main();
}

/* ================================
 * @function : main 
 *
*==================================
**/
int main(void)
 {		
	int data; 

	NVIC_Configuration();

	delay_init();
	usrrtc_init(); 
	usart_init(115200);	 
 
  usrled_init();
	//usrkey_init();
 	TIM2_Int_Init(4999,3599);   // 1000ms  
 	//TIM3_PWM_Init(899,0);       // F_pwm = 8khz  72M = 900, out PB5
	usradc_init ();             // ADC on chip Temp sensor  
	usrtadc_init ();		   		  // ADC PA5
	//usr_fram_init();
	//usr_ad9850_init();
  
	 printf ("welcom tom wu!\r\n");
	
	//data =   usart_hitkey();  
	if (data == 'a' ){
	printf ("welcom tom wu!\r\n");
	}
 	//st7066_init();
  //st7066_puts(0,0,"help mt, tom."); 
	
	USART1_MSGQ = xQueueCreate ( 10, (sizeof(char))*100 );
	
	xTaskCreate ( vTask1,    "Task1",     100,  NULL, 2, NULL );
	xTaskCreate ( vTask2,    "Task2",     100,  NULL, 2, NULL );
	xTaskCreate ( vTask3,    "Task3",     100,  NULL, 2, NULL );
	xTaskCreate ( USART1OUT, "USART1OUT", 100,  NULL, 3, NULL );
	xTaskCreate ( vTaskIdle, "idle",      500, NULL, 4, NULL );

	vTaskStartScheduler();
	// never hit 
}

