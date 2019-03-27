/*
****************************************************************************
 * imgsens.c
 *
 * Date       Name        Description
 *
****************************************************************************
*/
#include "stdio.h"
#include "menu.h"
#include "usr_sys.h"
#include "usr_adc.h"
#include "usr_rtc.h"
#include "usr_tsensor.h"
#include "usr_ad9850.h"
#include "adns5020.h"


/*============  static functions =================*/
static int init ();
static int cap  ();
static int rreg (const char *regAdrStr);


const CMD_ENTRY imgo[] = {
 {(CMD_FUNC)init,          0, "init",  "",     "initialize ADNS5020 "},
 {(CMD_FUNC)cap,           0, "c",     "",     "capture one frame   "},
 {(CMD_FUNC)rreg,          1, "rg",    "adr",  "read register  "},
 { NULL,                   0,  NULL,   NULL,    NULL               }
};



/*****************************************************************************
 *  Private functions 
*****************************************************************************/
static int init()
{
    int ret = CMD_RC_SUCCESS;
	

    adns5020_init ();
    adns5020_reset();
    //adns5020_config();
    //adns5020_dx();
    //adns5020_dy();
    //adns5020_squal();
    //adns5020_pixels(u8 *buffer); 


    printf ("\r\nADN5020 : initialized ! \r\n");
    
    return ret;
}

static int rreg (const char *regAdrStr)
{
    int ret = CMD_RC_SUCCESS;
	  int regadr = 0;
	  u8  regdata = 0;
	
	  sscanf (regAdrStr, "0x%x", &regadr);
	  regadr &= 0xff;
    regdata = adns5020_reg_read(regadr ); 

    printf ("\r\n ADN5020:REG[0x%x]=0x%x \r\n", regadr,regdata );
    
    return ret;
}


static int cap()
{
    int ret = CMD_RC_SUCCESS;
	  int k   = 0;
    char  buf[255];   

	  for (k=0; k<255; k++){
		    buf[k] = 0;
		}
    
		adns5020_pixels (buf); 

    printf ("\r\nADNS5020 : cap! ! \r\n");
    printf ("\r\n ====== start ========= \r\n");
	  for (k=0; k<255; k++){
		    printf ("%02x ", buf[k] );
		}
    printf ("\r\n ====== end   ========= \r\n");
	  
    return ret;
}

