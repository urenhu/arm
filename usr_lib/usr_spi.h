#ifndef __SPI_H
#define __SPI_H

#include "usr_sys.h"
#include "stm32f10x_spi.h"

// SPI_BaudRatePrescaler_2    2   
// SPI_BaudRatePrescaler_8    8   
// SPI_BaudRatePrescaler_16   16  
// SPI_BaudRatePrescaler_256  256 

void usrspi2_init           ( int threewire, int lsbfirst, int spimode ); // void usrspi2_init (void) = (0,0,3)
void usrspi2_setspeed       ( u8 speed  ); 
u8   usrspi2_WriteReadAByte ( u8 TxData );  // shift 8 clocks with data in DO then read receiver's rx () 

void usrspi2_SendByte3Wire  (uint8_t val);
u8   usrspi2_ReadByte3Wire  ();

#endif

