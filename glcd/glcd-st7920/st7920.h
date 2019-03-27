/************************************************************
 *  @module:   st7920.h 
 *  @author(s): tom wu
 *  @date: 2016 for mailbox detection project  
 *  @copyright urenhu coporation  
 *  
**/
 
#ifndef __ST7920_H__ 
#define __ST7920_H__ 
 
#include <stdio.h>  
#include <string.h>  
#include "usr_sys.h"   

// basic command set ============================================= 
#define LCD_DATA               	0     	// data  
#define LCD_COMMAND            	1	   	 	// command  
#define	LCD_CLEAR_SCREEN       	0x01 	 	// clear display  
#define	LCD_ADDRESS_RESET      	0x02		// reset address
#define	LCD_BASIC_FUNCTION	  	0x30		// basic command set 
#define	LCD_EXTEND_FUNCTION	   	0x34		// extended command set 
 
// extended command set ============================================= 
#define	LCD_AWAIT_MODE			  0x01	 	// 
#define LCD_ROLLADDRESS_ON		0x03		// allow vertical address scroll
#define LCD_IRAMADDRESS_ON		0x02		// 	 
#define	LCD_SLEEP_MODE		  	0x08	 	// sleep mode enterting  
#define	LCD_NO_SLEEP_MODE		  0x0c	 	// sleep mode escaping  
#define LCD_GRAPH_ON			    0x36		// graphic mode on   8bit+
#define LCD_GRAPH_OFF			    0x34		// graphic mode off 
 
#define LCD_COLOR_BLACK			1 
#define LCD_COLOR_WHITE			0 
 
extern void LCD_Init(void); 
extern void LCD_ClearRam(void); 
extern void LCD_GraphModeSet(unsigned char Select); 
extern void LCD_DisplayStrings(unsigned char x,unsigned char y,const char *p); 
extern void LCD_Point(unsigned char x,unsigned char y,unsigned char color); 
extern void LCD_DisplayString(int X,int Y,char *ptr, int len);
 
#endif

