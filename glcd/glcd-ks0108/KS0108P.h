/*****************************************************************************
 *  Module for Microchip Graphics Library
 *  KS0108 LCD controller driver 
 *  Portrait orientation
 *****************************************************************************
 * FileName:        KS0108.h
 * Dependencies:    p24Fxxxx.h
 * Dependencies:    p24Hxxxx.h
 * Processor:       PIC24
 * Compiler:        MPLAB C30 V3.00
 * Linker:          MPLAB LINK30
 * Company:         Rocket Software Systems
 *
 * Software License Agreement
 *
 * Copyright © 2007 Rocket Software Systems (RSS)
 * RSS licenses to you the right to use, modify, copy and distribute
 * Software.
 *
 * I don't get paid by lines of code.  Needless white space removed.
 *
 * Author               Date        Comment
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * dET		01/11/07	Beta release
 *****************************************************************************/

#ifndef _KS0108_H
#define _KS0108_H

#if defined(__dsPIC33F__)
#include "p33Fxxxx.h"
#elif defined(__PIC24H__)
#include "p24Hxxxx.h"
#elif defined(__PIC30F__)
#include "p30Hxxxx.h"
#elif defined(__PIC24F__)
#include <p24Fxxxx.h>
#endif

// Additional hardware-accelerated functions implemented in the driver.
// These definitions exclude from compilation the PutPixel()-based functions
// in the graphic primitive layer (Primitive.c file).

//#define USE_DRV_FONT
//#define USE_DRV_LINE
//#define USE_DRV_CIRCLE
//#define USE_DRV_FILLCIRCLE
#define USE_DRV_BAR
#define USE_DRV_CLEARDEVICE



// Horizontal and vertical screen size
#define SCREEN_PAGE_SIZE   64
#define SCREEN_HOR_SIZE    128
#define SCREEN_VER_SIZE    64

// Memory pitch for line
#define LINE_MEM_PITCH   0x100 

#define Reparse(a,b)  #a" #"#b
#define Nops(c) __asm__(Reparse(repeat, c)); __asm__("nop")


// Definitions for reset pin
#define RESET   _LATC2 /* RESET pin (active low) */     
#define RESET_TRIS  _TRISC2

// Definitions for CS pin
#define CS1       _LATC3 /* CHIP 1 SELECTION pin */
#define CS2       _LATC4 /* CHIP 2 SELECTION pin */
#define CS1_TRIS  _TRISC3
#define CS2_TRIS  _TRISC4

// define WHICH_BYTE 0 if the hardware is connected
// to the low byte of a port
#define WHICH_BYTE  0 
#define GETSETBYTE(var,index) *(((unsigned char*)&var)+index)
#define DATA_TRIS_OUTPUT 0
#define DATA_TRIS_INPUT 1

#define DATALATCH    LATE               /*DATA port */
#define TRISDATA     TRISE 
#define PORTDATA     PORTE              /*READ port */
#define RS_TRIS  _TRISG0
#define E_TRIS   _TRISF0
#define RW_TRIS  _TRISF1
#define DIR_TRIS _TRISG1

#define RS  _LATG0    /*CMD or DATA */
#define E   _LATF0    /*ENABLE transfer */
#define RW  _LATF1    /*READ or WRITE */
#define DIR _LATG1   /* level translator direction, high write, low read */

/* Graphic operations defines */

#define CONTROLLER_ONE 0x1
#define CONTROLLER_TWO 0x2
#define CONTROLLER_BOTH (CONTROLLER_ONE | CONTROLLER_TWO)
#define PAGE_COMMAND        0xB8
#define ADDRESS_COMMAND     0x40
#define LCD_ON_COMMAND      0x3F
#define LCD_OFF_COMMAND     0x3E
#define LCD_START_COMMAND   0xC0

// Definitions for FLASH CS pin 
#define CS_FLASH      _LATG12
#define CS_FLASH_TRIS _TRISG12

// Image stretch codes
#define IMAGE_NORMAL       1
#define IMAGE_X2           2

// Clipping region control codes
#define CLIP_DISABLE       0 
#define CLIP_ENABLE        1

// Color codes
                                 //RRRRRGGGGGGBBBBB 
#define BLACK              (WORD)0b0000000000000000
#define BRIGHTBLUE         (WORD)0b0000000000011111
#define BRIGHTGREEN        (WORD)0b0000011111100000
#define BRIGHTCYAN         (WORD)0b0000011111111111
#define BRIGHTRED          (WORD)0b1111100000000000
#define BRIGHTMAGENTA      (WORD)0b1111100000011111
#define BRIGHTYELLOW       (WORD)0b1111111111100000
#define BLUE               (WORD)0b0000000000010000
#define GREEN              (WORD)0b0000010000000000
#define CYAN               (WORD)0b0000010000010000
#define RED                (WORD)0b1000000000000000
#define MAGENTA            (WORD)0b1000000000010000
#define BROWN              (WORD)0b1111110000000000
#define LIGHTGRAY          (WORD)0b1000010000010000
#define DARKGRAY           (WORD)0b0100001000001000
#define LIGHTBLUE          (WORD)0b1000010000011111
#define LIGHTGREEN         (WORD)0b1000011111110000
#define LIGHTCYAN          (WORD)0b1000011111111111
#define LIGHTRED           (WORD)0b1111110000010000
#define LIGHTMAGENTA       (WORD)0b1111110000011111
#define YELLOW             (WORD)0b1111111111110000
#define WHITE              (WORD)0b1111111111111111

#define GRAY0       	   (WORD)0b1110011100011100
#define GRAY1         	   (WORD)0b1100011000011000   
#define GRAY2              (WORD)0b1010010100010100   
#define GRAY3              (WORD)0b1000010000010000
#define GRAY4              (WORD)0b0110001100001100
#define GRAY5              (WORD)0b0100001000001000
#define GRAY6	           (WORD)0b0010000100000100


// Color
extern WORD_VAL _color;

// Clipping region control
extern SHORT _clipRgn;

// Clipping region borders
extern SHORT _clipLeft;
extern SHORT _clipTop;
extern SHORT _clipRight;
extern SHORT _clipBottom;


/*********************************************************************
* Macros:  SetIndex(index)
* PreCondition: none
* Input: index - index register
* Output: none
* Side Effects: none
* Overview: writes S6D0129 index register
* Note: none
********************************************************************/
#define SetIndex(index)

//  PMADDR=0x0000;PMDIN1=0;Nop();Nop();PMDIN1=index;Nop();

/*********************************************************************
* Macros:  SetAddress(addr2,addr1,addr0)
* PreCondition: none
* Input: addr0,addr1,addr2 - address bytes
* Output: none
* Side Effects: none
* Overview: writes S6D0129 address pointer
* Note: none
********************************************************************/
#define SetAddress(addr2,addr1,addr0)

#if 0
PMADDR=0x0000;PMDIN1=0;Nop();Nop();PMDIN1=0x20;Nop();\
PMADDR=0x0001;PMDIN1=0;Nop();Nop();PMDIN1=addr0;Nop();\
PMADDR=0x0000;PMDIN1=0;Nop();Nop();PMDIN1=0x21;Nop();\
PMADDR=0x0001;PMDIN1=addr2;Nop();Nop();PMDIN1=addr1;Nop();\
PMADDR=0x0000;PMDIN1=0;Nop();Nop();PMDIN1=0x22;Nop();
#endif

/*********************************************************************
* Function:  void ResetDevice()
* PreCondition: none
* Input: none
* Output: none
* Side Effects: none
* Overview: resets device, initialize PMP
* Note: none
********************************************************************/
void ResetDevice(void);

/*********************************************************************
* Macros:  GetMaxX()
* PreCondition: none
* Input: none
* Output: maximum horizontal coordinate
* Side Effects: none
* Overview: returns maximum horizontal coordinate
* Note: none
********************************************************************/
#define GetMaxX() (SCREEN_HOR_SIZE-1)

/*********************************************************************
* Macros:  GetMaxY()
* PreCondition: none
* Input: none
* Output: maximum vertical coordinate
* Side Effects: none
* Overview: returns maximum vertical coordinate
* Note: none
********************************************************************/
#define GetMaxY() (SCREEN_VER_SIZE-1)

/*********************************************************************
* Macros:  SetColor(color)
* PreCondition: none
* Input: color coded in format:
*           bits 15 14 13 12 11 10 09 08 07 06 05 04 03 02 01 00 
*          color  R  R  R  R  R  G  G  G  G  G  G  B  B  B  B  B
* Output: none
* Side Effects: none
* Overview: sets current color
* Note: none
********************************************************************/
#define SetColor(color) _color.Val = (color) ? 1 : 0;

/*********************************************************************
* Macros:  GetColor()
* PreCondition: none
* Input: none
* Output:  color coded in format:
*           bits 15 14 13 12 11 10 09 08 07 06 05 04 03 02 01 00 
*          color  R  R  R  R  R  G  G  G  G  G  G  B  B  B  B  B
* Side Effects: none
* Overview: returns current color
* Note: none
********************************************************************/
#define GetColor() _color.Val

/*********************************************************************
* Macros:  SetActivePage(page)
* PreCondition: none
* Input: graphic page number
* Output: none
* Side Effects: none
* Overview: sets active graphic page 
* Note: KS0108 has only page
********************************************************************/
#define SetActivePage(page)

/*********************************************************************
* Macros: SetVisualPage(page)
* PreCondition: none
* Input: graphic page number
* Output: none
* Side Effects: none
* Overview: sets graphic page to display
* Note: KS0108 has only page
*
********************************************************************/
#define SetVisualPage(page)

/*********************************************************************
* Function: void PutPixel(SHORT x, SHORT y)
* PreCondition: none
* Input: x,y - pixel coordinates 
* Output: none
* Side Effects: none
* Overview: puts pixel
* Note: none
********************************************************************/
void PutPixel(SHORT x, SHORT y);

/*********************************************************************
* Function: WORD GetPixel(SHORT x, SHORT y)
* PreCondition: none
* Input: x,y - pixel coordinates 
* Output: pixel color
* Side Effects: none
* Overview: return pixel color at x,y position
* Note: none
********************************************************************/
WORD GetPixel(SHORT x, SHORT y);

/*********************************************************************
* Function: void PutImage(SHORT left, SHORT top, void* bitmap, BYTE stretch)
* PreCondition: none
* Input: left,top - left top image corner, bitmap - image pointer,
*        stretch - image stretch factor
* Output: none
* Side Effects: none
* Overview: outputs image starting from left,top coordinates
* Note: image must be located in flash.  This controller will perform
* better by drawing horizontally and using the auto address increment.
* We may want to read controller memory into a page buffer, then OR in
* the new data in memory, the write to the controller memory.
*
********************************************************************/
void PutImage(SHORT left, SHORT top, void* bitmap, BYTE stretch);

/*********************************************************************
* Function: WORD GetImageWidth(void* bitmap)
* PreCondition: none
* Input: bitmap - image pointer
* Output: none
* Side Effects: none
* Overview: returns image width
* Note: image must be located in flash
********************************************************************/
//WORD GetImageWidth(void* bitmap);

/*********************************************************************
* Function: WORD GetImageHeight(void* bitmap)
* PreCondition: none
* Input: bitmap - image pointer
* Output: none
* Side Effects: none
* Overview: returns image height
* Note: image must be located in flash
********************************************************************/
//WORD GetImageHeight(void* bitmap);
 
/*********************************************************************
* Macros: SetClipRgn(left, top, right, bottom)
* PreCondition: none
* Input: left,top,right,bottom - clipping region borders
* Output: none
* Side Effects: none
* Overview: sets clipping region 
* Note: none
********************************************************************/
#define SetClipRgn(left,top,right,bottom) _clipLeft=left; _clipTop=top; _clipRight=right; _clipBottom=bottom;

/*********************************************************************
* Macros: GetClipLeft()
* PreCondition: none
* Input: none
* Output: left clipping border
* Side Effects: none
* Overview: returns left clipping border
* Note: none
********************************************************************/
#define GetClipLeft() _clipLeft

/*********************************************************************
* Macros: GetClipRight()
* PreCondition: none
* Input: none
* Output: right clipping border
* Side Effects: none
* Overview: returns right clipping border
* Note: none
********************************************************************/
#define GetClipRight() _clipRight

/*********************************************************************
* Macros: GetClipTop()
* PreCondition: none
* Input: none
* Output: top clipping border
* Side Effects: none
* Overview: returns top clipping border
* Note: none
********************************************************************/
#define GetClipTop() _clipTop

/*********************************************************************
* Macros: GetClipBottom()
* PreCondition: none
* Input: none
* Output: bottom clipping border
* Side Effects: none
* Overview: returns bottom clipping border
* Note: none
********************************************************************/
#define GetClipBottom() _clipBottom

/*********************************************************************
* Macros: SetClip(control)
* PreCondition: none
* Input: control - 0 disable/ 1 enable
* Output: none
* Side Effects: none
* Overview: enables/disables clipping 
* Note: none
********************************************************************/
#define SetClip(control) _clipRgn=control;

/*********************************************************************
* Macros: IsDeviceBusy()
* PreCondition: none
* Input: none
* Output: busy status
* Side Effects: none
* Overview:  returns non-zero if LCD controller is busy 
* (previous drawing operation is not complete).
* Note: KS0180 may be busy.
*
********************************************************************/
WORD IsDeviceBusy();

/*********************************************************************
* Macros: SetPalette(colorNum, color)
* PreCondition: none
* Input: colorNum - register number, color - color
* Output: none
* Side Effects: none
* Overview:  sets palette register
* Note: KS0108 has no palette
********************************************************************/
#define SetPalette(colorNum, color)

/*********************************************************************
* Function:  void  DelayMs(WORD time)
* PreCondition: none
* Input: time - delay in ms
* Output: none
* Side Effects: none
* Overview: delays execution on time specified in ms
* Note: delay is defined for 16MIPS
********************************************************************/
void DelayMs(WORD time);

/*********************************************************************
* Macros: RGB565CONVERT(red, green, blue)
* PreCondition: none
* Input: red, green, blue components
* Output: 5 bits red, 6 bits green, 5 bits blue color
* Side Effects: none
* Overview: converts true color into 5:6:5 bits format
* Note: none
********************************************************************/
//#define RGB565CONVERT(red, green, blue) (WORD)( ((red)|(green)|(blue)) ? 1 : 0;

#endif
