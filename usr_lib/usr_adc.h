#ifndef __ADC_H
#define __ADC_H	
#include "usr_sys.h"
 
void usradc_init(void);
u16  usradc_get(u8 ch); 
u16  usradc_getav(u8 ch,u8 times); 
 
#endif 
