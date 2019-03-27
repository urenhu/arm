/*******************************************************************************
  @Module: usr_dds.h    
  @Description:
  @Copyright © 2015-2016 released URENHU Inc.  All rights reserved.
*******************************************************************************/
#ifndef __USR_DDS_H
#define __USR_DDS_H

#define PIN_WCLK       0
#define PIN_DATA       1        
#define PIN_FQUP       2 
#define PIN_REST       3        

/********************/
void ad9850_freq(double freq, unsigned char cw); 
void DDSInitialize(void);
void DDSUnInitialize(void);

#endif