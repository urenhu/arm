#ifndef __LED_H
#define __LED_H
	 
#include "usr_sys.h"

#define LED0 PAout(6)
#define LED1 PAout(7)

void usrled_init (void);
void usrled_on (int idx);
void usrled_off (int idx);

#endif
