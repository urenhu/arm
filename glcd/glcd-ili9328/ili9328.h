/**************************************************************************/
/*! 
    @file     ILI9328.h
*/
/**************************************************************************/
#ifndef __ILI9328_H__
#define __ILI9328_H__

#include "usr_sys.h"   

#define  LCD_ORIENTATION_PORTRAIT    0
#define  LCD_ORIENTATION_LANDSCAPE   1

// Control pins
enum {
  CMD_DRIVERCODEREAD                 = 0x0000,
  CMD_DRIVEROUTPUTCONTROL1           = 0x0001,
  CMD_LCDDRIVINGCONTROL              = 0x0002,
  CMD_ENTRYMODE                      = 0x0003,
  CMD_RESIZECONTROL                  = 0x0004,
  CMD_DISPLAYCONTROL1                = 0x0007,
  CMD_DISPLAYCONTROL2                = 0x0008,
  CMD_DISPLAYCONTROL3                = 0x0009,
  CMD_DISPLAYCONTROL4                = 0x000A,
  CMD_RGBDISPLAYINTERFACECONTROL1    = 0x000C,
  CMD_FRAMEMAKERPOSITION             = 0x000D,
  CMD_RGBDISPLAYINTERFACECONTROL2    = 0x000F,
  CMD_POWERCONTROL1                  = 0x0010,
  CMD_POWERCONTROL2                  = 0x0011,
  CMD_POWERCONTROL3                  = 0x0012,
  CMD_POWERCONTROL4                  = 0x0013,
  CMD_HORIZONTALGRAMADDRESSSET       = 0x0020,
  CMD_VERTICALGRAMADDRESSSET         = 0x0021,
  CMD_WRITEDATATOGRAM                = 0x0022,
  CMD_POWERCONTROL7                  = 0x0029,
  CMD_FRAMERATEANDCOLORCONTROL       = 0x002B,
  CMD_GAMMACONTROL1                  = 0x0030,
  CMD_GAMMACONTROL2                  = 0x0031,
  CMD_GAMMACONTROL3                  = 0x0032,
  CMD_GAMMACONTROL4                  = 0x0035,
  CMD_GAMMACONTROL5                  = 0x0036,
  CMD_GAMMACONTROL6                  = 0x0037,
  CMD_GAMMACONTROL7                  = 0x0038,
  CMD_GAMMACONTROL8                  = 0x0039,
  CMD_GAMMACONTROL9                  = 0x003C,
  CMD_GAMMACONTROL10                 = 0x003D,
  CMD_HORIZONTALADDRESSSTARTPOSITION = 0x0050,
  CMD_HORIZONTALADDRESSENDPOSITION   = 0x0051,
  CMD_VERTICALADDRESSSTARTPOSITION   = 0x0052,
  CMD_VERTICALADDRESSENDPOSITION     = 0x0053,
  CMD_DRIVEROUTPUTCONTROL2           = 0x0060,
  CMD_BASEIMAGEDISPLAYCONTROL        = 0x0061,
  CMD_VERTICALSCROLLCONTROL          = 0x006A,
  CMD_PARTIALIMAGE1DISPLAYPOSITION   = 0x0080,
  CMD_PARTIALIMAGE1AREASTARTLINE     = 0x0081,
  CMD_PARTIALIMAGE1AREAENDLINE       = 0x0082,
  CMD_PARTIALIMAGE2DISPLAYPOSITION   = 0x0083,
  CMD_PARTIALIMAGE2AREASTARTLINE     = 0x0084,
  CMD_PARTIALIMAGE2AREAENDLINE       = 0x0085,
  CMD_PANELINTERFACECONTROL1         = 0x0090,
  CMD_PANELINTERFACECONTROL2         = 0x0092,
  CMD_PANELINTERFACECONTROL4         = 0x0095,
  CMD_OTPVCMPROGRAMMINGCONTROL       = 0x00A1,
  CMD_OTPVCMSTATUSANDENABLE          = 0x00A2,
  CMD_OTPPROGRAMMINGIDKEY            = 0x00A5
};

// ===============================================

void  lcd_set_orientation (int orientation);
void  lcd_fill_RGB(uint16_t data);
void  lcd_draw_pixel(uint16_t x, uint16_t y, uint16_t color);
int   lcd_get_orientation(void);
uint16_t  lcd_get_width (void);
uint16_t  lcd_get_height (void);
void  lcd_scroll(int16_t pixels, uint16_t fillColor);
//void lcd_draw_vline(uint16_t x, uint16_t y0, uint16_t y1, uint16_t color);
//void lcd_draw_hline(uint16_t x, uint16_t y0, uint16_t y1, uint16_t color);
void  lcd_draw_line(uint16_t x, uint16_t y0, uint16_t y1, uint16_t color);

#endif // 
