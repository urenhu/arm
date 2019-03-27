#ifndef __USART_H
#define __USART_H

#include "stdio.h"	
#include "usr_sys.h"

void usart_init   (u32 bound);
int  usart_getc   (void) ; 
int  usart_hitkey (void) ; 

#endif


