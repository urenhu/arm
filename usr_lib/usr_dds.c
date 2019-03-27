/*******************************************************************************
  @Module: usr_dds.c    
  @Description:
  @Copyright © 2015-2016 released URENHU Inc.  All rights reserved.
*******************************************************************************/
/********************************************************************
 Section: Includes 
********************************************************************/
#include <stdio.h>
#include <p18f24j50.h>
#include "usr_dds.h"

#define AD0850_MAX     4294967295
#define AD9850_CLOCK   125  // MHZ

#define PIN_WCLK_REG        LATBbits.LATB2       
#define PIN_DATA_REG        LATBbits.LATB0       
#define PIN_FQUP_REG        LATBbits.LATB1
#define PIN_REST_REG        LATBbits.LATB3       
       
/********************************************************************
 Section: Local Variables 
********************************************************************/
/********************************************************************
 delay calibration 
======================
 count   measue 
 2000    500 ms 
 20      5   ms
 10      2.5 ms
 4       1   ms
 2       500 us
 1       250 us
     
********************************************************************/
static void spinlock_delay(int delay_count)
{
    do {
        delay_count--;
    } while(delay_count);
}

static void output_low(char pin_name)
{
  switch (pin_name){
  case PIN_WCLK:
       PIN_WCLK_REG = 0;
       break;
  case PIN_DATA  :
       PIN_DATA_REG = 0;
       break;
  case PIN_FQUP :
       PIN_FQUP_REG = 0;
       break;  
  case PIN_REST  :
       PIN_REST_REG = 0;
       break; 
  }
}

static void output_high(char pin_name)
{
  switch (pin_name){
  case PIN_WCLK:
       PIN_WCLK_REG = 1;
       break;
  case PIN_DATA  :
       PIN_DATA_REG = 1;
       break;
  case PIN_FQUP :
       PIN_FQUP_REG = 1;
       break;  
  case PIN_REST  :
       PIN_REST_REG = 1;
       break; 
  }
}

void output_pulse(char pin_name, int width_ms)
{
  switch (pin_name){
  case PIN_WCLK:
       PIN_WCLK_REG = 1;
       spinlock_delay(width_ms*4);
       PIN_WCLK_REG = 0;
       break;
  case PIN_DATA  :
       PIN_DATA_REG = 1;
       spinlock_delay(width_ms*4);
       PIN_DATA_REG = 0;
       break;
  case PIN_FQUP :
       PIN_FQUP_REG = 1;
       spinlock_delay(width_ms*4);
       PIN_FQUP_REG = 0;
       break;  
  case PIN_REST  :
       PIN_REST_REG = 1;
       spinlock_delay(width_ms*4);
       PIN_REST_REG = 0;
       break; 
  }
}

static void send_byte(unsigned char byte) 
{ char  i; 
  for (i = 0; i < 8; i++) {
    if (byte & 1)
     output_high (PIN_DATA); 
	else
     output_low  (PIN_DATA);
	output_pulse(PIN_WCLK, 1);
	byte >>= 1;
  }
}

/**********************************
  unsigned long tuning_freq;               
***********************************/
void ad9850_freq(double freq, unsigned char cw) 
{	
    unsigned long temp, tuning_freq;                            
	unsigned char word;
    double        x;

	x    = AD0850_MAX/ AD9850_CLOCK;
	freq = freq / 1000000;
	freq = freq * x;
	tuning_freq = (unsigned long) freq;
	
    temp = tuning_freq & 0x000000ff;                         
	word = temp;
    send_byte(word);

    temp = tuning_freq & 0x0000ff00;                         
	word = temp>>8;
    send_byte(word);

    temp = tuning_freq & 0x00ff0000;                         
	word = temp>>16;
    send_byte(word);

    temp = tuning_freq & 0xFF000000;                         
	word = temp>>24;
    send_byte(word);

    temp = tuning_freq & 0x000000ff;                         
	word = temp;
    send_byte(word);

    send_byte(cw);
	output_pulse(PIN_FQUP,1);
}

/********************************************************************
 Funciton:
 *******************************************************************/
void DDSInitialize(void)
{   
  output_low   (PIN_WCLK);
  output_low   (PIN_FQUP);
  output_pulse (PIN_REST, 10 );
  output_pulse (PIN_WCLK, 1);
  output_pulse (PIN_FQUP, 1);
}

/********************************************************************
 Funciton:
 *******************************************************************/
void DDSUnInitialize(void)
{   
}



