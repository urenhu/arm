#ifndef __TSENSOR_H
#define __TSENSOR_H	

#include "stm32f10x.h"
#define ADC_CH_TEMP  	ADC_Channel_16 // T sensor channel
   
void  usrtadc_init   (void );   
u16   usrtadc_getadc (u8 ch);   
u16   usrtadc_gettm  (int filter_len);

#endif 
