/*
****************************************************************************
 * glcd.c
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


/*============  static functions =================*/
static int init ();
static int lightOn(const char *xStr,const char *yStr);
static int lightOff(const char *xStr,const char *yStr);
static int putstr (const char *cStr);


const CMD_ENTRY glcdo[] = {
 {(CMD_FUNC)init,          0, "init",  "",     "initialize ADNS5020 "},
 {(CMD_FUNC)lightOn,       2, "on",    "x y",  "turn pixcle xy on"},
 {(CMD_FUNC)lightOff,      2, "off",   "x y",  "turn pixcle xy off"},
 {(CMD_FUNC)putstr,        1, "disp",   "str", "display string"},
 { NULL,                   0,  NULL,   NULL,    NULL               }
};


//extern void LCD_Init(void); 
//extern void LCD_ClearRam(void); 
//extern void LCD_GraphModeSet(unsigned char Select); 
//extern void LCD_DisplayStrings(unsigned char x,unsigned char y,const char *p); 
//extern void LCD_Point(unsigned char x,unsigned char y,unsigned char color); 
//extern void LCD_DisplayString(int X,int Y,char *ptr, int len);

/*****************************************************************************
 *  Private functions 
*****************************************************************************/
static int init()
{
  int ret = CMD_RC_SUCCESS;
	
	//LCD_Init (); 
  // st7066_init();
	ili9328_init_display();
  printf ("\r\n ST7920 init: initialized ! \r\n");
  return ret;
}


static int lightOn(const char *xStr,const char *yStr)
{
    int ret = CMD_RC_SUCCESS;
	  int x , y;
    sscanf ( xStr, "%d", &x);	
    sscanf ( yStr, "%d", &y);	
	
  	//LCD_Point(x, y , 0xff); 

		printf ("\r\n turn on pixel :x = %d y = %d \r\n", x, y );
    
    return ret;
}

static int lightOff(const char *xStr,const char *yStr)
{
    int ret = CMD_RC_SUCCESS;
	  int x , y;
    sscanf ( xStr, "%d", &x);	
    sscanf ( yStr, "%d", &y);	
	
  	//LCD_Point(x, y , 0x0); 

		printf ("\r\n turn off pixel :x = %d y = %d \r\n", x, y );
    
    return ret;
}

static int putstr (const char *cStr)
{
    int ret = CMD_RC_SUCCESS;
	  int x , y;
  
    x  = 0;
    y  = 0;
   
  	//st7066_puts(x, y,(char *) cStr);
		lcd_draw_pixel(x+10,y+10, 0x55);
		printf ("\r\n display %s at %d,%d \r\n", cStr, x, y );
    
    return ret;
}
