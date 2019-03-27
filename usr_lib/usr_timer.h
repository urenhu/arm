#ifndef __TIMER_H
#define __TIMER_H

#include "usr_sys.h"

void TIM2_Int_Init(u16 arr,u16 psc);
void TIM3_Int_Init(u16 arr,u16 psc);
 
void TIM3_PWM_Init(u16 arr,u16 psc);
 
#endif
