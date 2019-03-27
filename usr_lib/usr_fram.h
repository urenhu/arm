#ifndef __USRFRAM_H
#define __USRFRAM_H			    

#include "usr_sys.h"


/****************************************************
 * FM25256 datasheet 
 *  256Kbits
 *  Max 15Mhz clock speed 
 *  Mode: 
 *  0:   CPOL=0 CPHA=0
 *  3:   CPOL=1 CPHA=1
Opcode :
=======================================================
  wren    0000 0110
  wrdi    0000 0100
  rdsr    0000 0101
  wrsr    0000 0001
  read    0000 0011
  write   0000 0010
status register :
=======================================================
 wpen 7  control hard ware wp pin
 BP1  3
 BP0  2
 WEL  1  for 
=======================================================
=======================================================
*/

#define FRAM_WRITE_ENABLE	  	0x06 
#define FRAM_WRITE_DISABLE		0x04 
#define FRAM_READ_SR        	0x05 
#define FRAM_WRITE_SR   		0x01 
#define FRAM_READ_DATA  	  	0x03 
#define FRAM_WRITE_DATA         0x02 

void usr_fram_init(void);
u8   usr_fram_read_sr (void);      
void usr_fram_write_sr(u8 sr);     
void usr_fram_write_enable(void);  
void usr_fram_write_disable(void); 
void usr_fram_read  (u8* pBuffer, u16 NumByteToRead, u16 adr );   
void usr_fram_write (u8* pBuffer, u16 NumByteToRead, u16 adr );  
void usr_fram_wait_busy(void);          


#endif
















