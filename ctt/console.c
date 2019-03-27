/*
****************************************************************************
 * console.c
 * Revision History:
 * Date       Name        Description
 *
****************************************************************************
*/
#include <stdio.h>
#include <string.h> /* strerror()*/
#include "menu.h"   /* menu framework */
#include "gpio.h"
#include "fram.h"
//#include "dds.h"
//#include "imgsens.h"
//#include "glcd.h"

/*============  static functions =================*/
static void title (void);
static int gpio_entry(void);
static int fram_entry(void);
//static int dds_entry(void);
//static int img_entry(void);
//static int glcd_entry(void);

#define MSG_OK                "OK\r\n"
#define MSG_FAILED            "***FAILED***\r\n"

static const CMD_ENTRY menu[] = {
 { (CMD_FUNC)gpio_entry,   0, "gpio",       "",         " submenu of GPIO  "},
 { (CMD_FUNC)fram_entry,   0, "fram",       "",         " submenu of FRAM  "},
 { NULL,                   0,  NULL,        NULL,       NULL }
};
 

/********************************************************************
 * console ioctl - ioctls for console terminal and virtual consoles
 **/
int console_main( void )
{
   title ();
   MenuMain("root",menu);
   return 0;
}

/* ---- Private Functions ------------------------------------------------- */
static void title ()
{
	printf ("\r\n\r\n"
			"****************************************************************************" "\r\n"
            "* console: \r\n"
			"****************************************************************************"
	        "\r\n\r\n"
	);
}

/*****************************************************************************
*  Start sub menu
*****************************************************************************/
static int gpio_entry(void)
{
   MenuStart("gpio",gpio,0,NULL);
   return(CMD_RC_SUCCESS);
}

static int fram_entry(void)
{
   MenuStart("fram", framo, 0, NULL);
   return(CMD_RC_SUCCESS);
}

