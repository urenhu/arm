#include "stm32f10x.h"
#include "usr_key.h"
#include "usr_sys.h" 
#include "usr_delay.h"



//////////////////////////////////////////////////////////////////////////////////	 
void usrkey_init ( void )
{ 
 	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOE,ENABLE);//使能PORTA,PORTE时钟

	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4;//PE2~4
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //设置成上拉输入
 	GPIO_Init(GPIOE, &GPIO_InitStructure);//初始化GPIOE2,3,4

	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; //PA0设置成输入，默认下拉	  
	GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化GPIOA.0

}


u8   usrkey_scan ( u8 mode) 						    
{	 
	static u8 key_up  = 1;
	
	if (mode) key_up  =  1;
	if (key_up&&(KEY0==0||KEY1==0||KEY2==0||KEY3==1)){
		delay_ms(10);   
		key_up = 0;
		if(KEY0==0)       return KEY_RIGHT;
		else if(KEY1==0)  return KEY_DOWN;
		else if(KEY2==0)  return KEY_LEFT;
		else if(KEY3==1)  return KEY_UP;
	} else if (KEY0==1&&KEY1==1&&KEY2==1&&KEY3==0) { 
	    key_up = 1;
	} 	    
 	return 0;
}
