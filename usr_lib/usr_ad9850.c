/*
 * DDS 
 */
#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "usr_sys.h"
#include "usr_delay.h"
#include "usr_ad9850.h"


#define AD9850_CLOCK	125000000


//===============  local prototypes 
static void   pulse(const u8 pin);
static void   send_byte(u8 byte) ;


static void pulse(const u8 pin) 
{
	GPIO_SetBits(AD9850_PORT, pin );
	delay_us(10);
	GPIO_ResetBits(AD9850_PORT, pin );
	delay_us(10);
}

static void send_byte (u8 byte) 
{
	u8 i;
	for (i = 0; i < 8; i++) {
		if (byte & 1)
			GPIO_SetBits(AD9850_PORT, AD9850_DATA);
		else
			GPIO_ResetBits(AD9850_PORT, AD9850_DATA);
		pulse(AD9850_WCLK);
		byte >>= 1;
	}
}

void usr_ad9850_set (const u32 frequency)
{
	float freq;
	u32 word;
	u8 i;

	freq = (float)4294967295 / AD9850_CLOCK;
	freq *= frequency;
	word = (u32)freq;

	for (i = 0; i < 4; i++) {
		send_byte((u8) (word & 0xff));
		word >>= 8;
	}
	send_byte(0);
	pulse(AD9850_FQUD);
}


void usr_ad9850_init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;

  //GPIO_DeInit(AD9850_PORT);		// dont call this !			 
 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); // m 
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 
 
  GPIO_InitStructure.GPIO_Pin = AD9850_RST;				 
  GPIO_Init(AD9850_PORT, &GPIO_InitStructure);					 
  GPIO_ResetBits(AD9850_PORT,AD9850_RST);						 

  GPIO_InitStructure.GPIO_Pin = AD9850_WCLK;				 
  GPIO_Init(AD9850_PORT, &GPIO_InitStructure);					 
  GPIO_ResetBits(AD9850_PORT,AD9850_WCLK);						 

	GPIO_InitStructure.GPIO_Pin = AD9850_DATA;				 
  GPIO_Init(AD9850_PORT, &GPIO_InitStructure);					 
  GPIO_ResetBits(AD9850_PORT,AD9850_DATA);						 
  
	GPIO_InitStructure.GPIO_Pin = AD9850_FQUD;				 
  GPIO_Init(AD9850_PORT, &GPIO_InitStructure);					 
  GPIO_ResetBits(AD9850_PORT,AD9850_FQUD);						 
	
	// init AD9850 Controller
	pulse(AD9850_RST);
	pulse(AD9850_WCLK);
	pulse(AD9850_FQUD);
}


