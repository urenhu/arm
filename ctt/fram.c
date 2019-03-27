/*
****************************************************************************
 * fram.c
 *
 * Date       Name        Description
 *
****************************************************************************
*/
#include "stdio.h"
#include "menu.h"
#include "gpio.h"
#include "usr_sys.h"
#include "usr_adc.h"
#include "usr_rtc.h"
#include "usr_tsensor.h"
#include "usr_fram.h"
#include "fram.h"


#define BUFL   256


static char sr = 0;
static char buf[BUFL];

/*============  static functions =================*/
static int info_fram   (void);
static int set_fram    (const char *strSR );
static int read_fram   (const char *adrStr, const char *lenStr);
static int write_fram  (const char *adrStr, const char *lenStr);
static int fill_buf    (const char *pattStr);
static int disp_buf    ();

const CMD_ENTRY framo[] = {
 {(CMD_FUNC)info_fram,    0, "info",  "",        "display FREAM SR "},
 {(CMD_FUNC)set_fram,     1, "set",   "sr",      "set FRAM SR"},
 {(CMD_FUNC)read_fram,    2, "read",  "adr len", "read bytes of data fram[adr]"},
 {(CMD_FUNC)write_fram,   2, "write", "adr len", "writebytes of  data to fram[adr]"},
 {(CMD_FUNC)fill_buf,     1, "fill",  "pattern", "fill buffer"},
 {(CMD_FUNC)disp_buf,     0, "disp",  "",        "display buffer content"},
 { NULL,                  0,  NULL,   NULL,   NULL}
};

/*****************************************************************************
*  Private functions 
*****************************************************************************/
static int info_fram   (void)
{
  int ret = CMD_RC_SUCCESS;
  
  sr = usr_fram_read_sr (); 
  printf ("\r\nFRAM:SR:0x%x\r\n", sr);	
  
  return ret;
}

static int set_fram    (const char *strSR )
{
  int ret = CMD_RC_SUCCESS;
  
  sscanf (strSR,"0x%x",&sr);
  usr_fram_write_sr (sr);
  info_fram();
 
  return ret;
}

static int read_fram   (const char *adrStr, const char *lenStr)
{
  int ret = CMD_RC_SUCCESS;
  u16 adr = 0;
  u16 len = 0;
  
  sscanf (adrStr, "0x%x",&adr); 
  sscanf (lenStr, "%d",&len); 

  if (len>BUFL ) len = BUFL;
  
  usr_fram_read  (buf, len, adr);

  printf ("\r\nFRAM:BUF:READ: ADR : 0x%x LEN:%d \r\n", adr, len );	
  
  disp_buf ();
  
  return ret;
}

static int write_fram  (const char *adrStr, const char *lenStr)
{
  int ret = CMD_RC_SUCCESS;
  u16 adr = 0;
  u16 len = 0;
  
  sscanf (adrStr, "0x%x",&adr); 
  sscanf (lenStr, "%d",&len); 

  if (len>BUFL ) len = BUFL;
  
  usr_fram_write  (buf, len, adr);

  printf ("\r\nFRAM:BUF:WRITE: ADR : 0x%x LEN:%d \r\n", adr, len );	

  return ret;
}

static int fill_buf    (const char *pattStr)
{
  int ret = CMD_RC_SUCCESS;
  int pat = 0;
  int i = 0;
  
  sscanf (pattStr, "0x%x",&pat); 
  for (i=0;i<BUFL;i++)
	  buf[i] = pat&0xff;

  printf ("\r\nFRAM:BUF:PATTERN:0x%x\r\n", pat);	
  
  return ret;
}


static int disp_buf    ()
{
  int ret = CMD_RC_SUCCESS;
  int i = 0;
  
  printf ("\r\nFRAM:BUF:=== start===\r\n");	
  for (i=0;i<BUFL;i++){
     if (i%16 == 0 && i != 0 ) printf ("\r\n");	
     printf ("%02x ", (int)buf[i]); 
  }
  printf ("\r\nFRAM:BUF:=== end ===\r\n");	
  return ret;
}


