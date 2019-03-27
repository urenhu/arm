/*
 * DDS AD985
 *
 */

#ifndef _USRAD9850_H
#define _USRAD9850_H

#include "usr_sys.h"

// AD9850
#define AD9850_PORT 	  GPIOA
#define AD9850_WCLK			GPIO_Pin_0 //or use PBout(9) for direct read write    
#define AD9850_FQUD			GPIO_Pin_1 //PBout(8)   
#define AD9850_DATA			GPIO_Pin_2 //PBout(7)   
#define AD9850_RST			GPIO_Pin_3 //PBout(6)   

void usr_ad9850_init(void);
void usr_ad9850_set (const u32 frequency);

#endif
