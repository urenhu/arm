#include "stdio.h"
#include "string.h"
#include "usr_led.h"

typedef struct {
    int  idx;                   /*redandant, equals to arry index. */ 
		char port;
		int  pin;
	  int  def_val;
} ledMapper, *pLedMapper;


#define LEDS_NUM              2

static ledMapper oLedAry[LEDS_NUM] = {
 {0, 'A', GPIO_Pin_6, 0 },
 {1, 'A', GPIO_Pin_7, 0 }
};


/************************************************************************
 * initialization led port and setup diection and default of GPIO 
*************************************/
void usrled_init (void)
{
  int  k = 0;
	GPIO_InitTypeDef     GPIO_InitStructure;
 	
	// we only assign LEDs on port A, if using any other ports, code change of follwing is required. TBD!!!
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); 
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 

  //RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); 
  //GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 
  //GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 

	for (k=0; k<LEDS_NUM; k++){
    switch ( oLedAry[k].port ) {
		case 'A':
		  GPIO_InitStructure.GPIO_Pin = oLedAry[k].pin;				 
      GPIO_Init(GPIOA, &GPIO_InitStructure);
      if (oLedAry[k].def_val){ 		
        GPIO_SetBits(GPIOA,oLedAry[k].pin);						 
		  } else {
		    GPIO_ResetBits(GPIOA,oLedAry[k].pin);						 
		  }
			break;
			
		//case 'B':
		//  GPIO_InitStructure.GPIO_Pin = oLedAry[k].pin;				 
    //  GPIO_Init(GPIOB, &GPIO_InitStructure);
    //  if (oLedAry[k].def_val){ 		
    //    GPIO_SetBits(GPIOB,oLedAry[k].pin);						 
		//  } else {
		//    GPIO_ResetBits(GPIOB,oLedAry[k].pin);						 
		//  }
		//	break;
			
		default:
      break;			
	  }
  }
	// GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
  // GPIO_Init(GPIOA, &GPIO_InitStructure);
  // GPIO_SetBits(GPIOA,GPIO_Pin_7); 		
}
 
/************************************************************************
 * turn on LED
*************************************/
void usrled_on (int idx)
{
	if (idx < LEDS_NUM) {
    switch ( oLedAry[idx].port ) {
		case 'A':
	    GPIO_SetBits(GPIOA,oLedAry[idx].pin);
      break;
   
    default:
      break;			
	  }
	}
}

/************************************************************************
 * turn off LED
*************************************/
void usrled_off (int idx)
{
	if (idx < LEDS_NUM) {
    switch ( oLedAry[idx].port ) {
		case 'A':
	    GPIO_ResetBits(GPIOA,oLedAry[idx].pin);
      break;
   
    default:
      break;			
	  }
	}
}
