/*
****************************************************************************
 * dds.c
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
static int set  (const char *fStr);

const CMD_ENTRY ddso[] = {
 {(CMD_FUNC)init,          0, "init",  "",     "initialize AD9850 "},
 {(CMD_FUNC)set,           1, "set",   "freq", "set frequency     "},
 { NULL,                   0,  NULL,   NULL,    NULL               }
};

/*****************************************************************************
*  Private functions 
*****************************************************************************/
static int init()
{
    int ret = CMD_RC_SUCCESS;
	
   	usr_ad9850_init ();
   	printf ("\r\nAD9850 : initialized ! \r\n");
	
    return ret;
}

//
//void usr_ad9850_init(void);
//void usr_ad9850_set (const u32 frequency);

static int set(const char *freqStr)
{
	int ret = CMD_RC_SUCCESS;
    u32 frequency =0;

	sscanf(freqStr, "%d", &frequency);
    usr_ad9850_set (frequency);
	printf ("\r\n set frequency as :%d \r\n", frequency );
			
	return ret;
}

