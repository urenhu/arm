//--------------------------------------------------------------
#ifndef __ST7066_H
#define __ST7066_H

#include "usr_sys.h"   

#define  LCD_CMD_INIT_DISPLAY  0x28   // 2 Zeilen Display, display 0ff 
#define  LCD_CMD_ENTRY_MODE    0x06   // Cursor increase, Display fix
#define  LCD_CMD_DISP_M0       0x08   // display off, cur off, blink off
#define  LCD_CMD_DISP_M1       0x0C   // display on,  cur off,  blink off
#define  LCD_CMD_DISP_M2       0x0E   // display on,  cur on,  blink off
#define  LCD_CMD_DISP_M3       0x0F   // display on,  cur on,  blink on
#define  LCD_CMD_CLEAR         0x01   // clear Display
#define  LCD_CMD_DISPOFF       0x08   // Display Off

#define  LCD_OFF               0
#define  LCD_ON                1 
#define  LCD_CURSOR            2 
#define  LCD_BLINK             3   



//--------------------------------------------------------------
// Globale Function
//--------------------------------------------------------------
void  st7066_init(void);
void  st7066_clear(void);
void  st7066_setmode(int mode);
void  st7066_puts    (uint8_t x, uint8_t y, char *ptr);
void  st7066_writecg (uint8_t nr, uint8_t *pixeldata);
void  st7066_putc    (uint8_t nr);


//--------------------------------------------------------------
#endif // __ST7066_H
