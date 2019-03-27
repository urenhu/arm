/*****************************************************************************
 *  Module for Microchip Graphics Library
 *  KS0108 LCD controller driver
 *  Portrait orientation
 *****************************************************************************
 * FileName:        KS0108.c
 * Dependencies:    GraphicLibrary.h
 * Processor:       PIC24
 * Compiler:       	MPLAB C30 V3.00
 * Linker:          MPLAB LINK30
 * Company:         Rocket Software Systems
 *
 * Software License Agreement
 *
 * Copyright © 2007 Rocket Software Systems.  All rights reserved.
 * Rocket Software Systems licenses to you the right to use, modify,
 *  copy and distribute Software.
 *
 * Author               Date        Comment
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * dET		01/11/07	...
 *****************************************************************************/
#include "Graphics.h"

/////////////////////// LOCAL FUNCTIONS PROTOTYPES ////////////////////////////
void SetReg(BYTE index, WORD value);
void PutImage1BPP(SHORT left, SHORT top, FLASH_BYTE* bitmap, BYTE stretch);
void PutImage4BPP(SHORT left, SHORT top, FLASH_BYTE* bitmap, BYTE stretch);
void PutImage8BPP(SHORT left, SHORT top, FLASH_BYTE* bitmap, BYTE stretch);
void PutImage16BPP(SHORT left, SHORT top, FLASH_BYTE* bitmap, BYTE stretch);

/* static prototypes */

#define SELECT_CHIPS(a) { if (a & CONTROLLER_ONE) CS1 = 1; if (a & CONTROLLER_TWO) CS2 = 1; }
#define DeSelect() { CS1 = 0; CS2 = 0; }
static void WriteCommand(BYTE chip_select, BYTE value);

static void WriteInst(BYTE value);
static BYTE ReadDataSingle(void);
static BYTE ReadData(void);
#define ReadDataLatch() ReadData()
static void WriteData(BYTE y);
static void PollReady(void);
static WORD GetChipSelect(WORD chip);
static void SetColumnSelect(WORD x);
static WORD GetPageSelect(WORD y);
static BYTE GetData(void);


#ifdef USE_DRV_BAR
static void FillRect(SHORT left, SHORT top, SHORT right, SHORT bottom);
#endif

#define LCDINST  0
#define LCDDATA  1
#define RW_READ  1
#define RW_WRITE 0

//#define USE_INLINE_FUNCTIONS 1

/* inlineable functions */
#ifdef USE_INLINE_FUNCTIONS

inline void SetTRISInput(void) { GETSETBYTE(TRISDATA, WHICH_BYTE) = 0xFF; DIR = 0; }
inline void SetTRISOutput(void) { GETSETBYTE(TRISDATA, WHICH_BYTE) = 0x0; DIR = 1; }
inline void SetData(BYTE value) { GETSETBYTE(DATALATCH, WHICH_BYTE) = value; }
inline void RW_RS_CMD(void)    { RW = RW_WRITE; RS = LCDINST; Nop(); }
inline void RW_RS_STATUS(void) { RW = RW_READ;  RS = LCDINST; Nop(); }
inline void RW_RS_WDATA(void)  { RW = RW_WRITE; RS = LCDDATA; Nop(); }
inline void RW_RS_RDATA(void)  { RW = RW_READ;  RS = LCDDATA; Nop(); }
inline void STROBE_WRITE() { E = 1;  Nops(8); E = 0; }
  
#else

static void SetTRISInput(void);
static void SetTRISOutput(void);
static void SetData(BYTE value);
static void RW_RS_CMD(void);
static void RW_RS_STATUS(void);
static void RW_RS_WDATA(void);
static void RW_RS_RDATA(void);
static void STROBE_WRITE(); 
#endif

// Color
WORD_VAL    _color;
// Clipping region control
SHORT _clipRgn;
// Clipping region borders
SHORT _clipLeft;
SHORT _clipTop;
SHORT _clipRight;
SHORT _clipBottom;


/*********************************************************************
* Function:  void  DelayMs(WORD time)
* PreCondition: none
* Input: time - delay in ms
* Output: none
* Side Effects: none
* Overview: delays execution on time specified in ms
* Note: delay is defined for 16MIPS
* modify for 24H
********************************************************************/
//#define DELAY_1MS 16000/9
#define DELAY_1MS 40000/9
void  DelayMs(WORD time){
unsigned delay;
	while(time--)
		for(delay=0; delay<DELAY_1MS; delay++);	
}


/*********************************************************************
* Function:  void ResetDevice()
* PreCondition: none
* Input: none
* Output: none
* Side Effects: none
* Overview: configures pins, resets LCD, initializes PMP
* Note: none
********************************************************************/
void ResetDevice(void)
{
  AD1PCFGH = 0xFFFF;  //set PORT E pins, and other pins to digital
  
  // Set reset pin as output
  RESET_TRIS = 0;
  // Hold in reset
  RESET = 0;

  // Set LCD CS pin as output
  CS1_TRIS = 0;
  CS2_TRIS = 0;
  // Disable LCD 
  CS1 = 0;
  CS2 = 0;
  
  // level translator 
  DIR_TRIS = 0;
  DIR = 1;
  
  // Set FLASH CS pin as output
  CS_FLASH_TRIS = 0;
  // Disable FLASH
  CS_FLASH = 1;

  E = 0;
  E_TRIS = 0;
  RS = 0;
  RS_TRIS = 0;
  RW = 0;
  RW_TRIS = 0;

#ifdef PMP_SETUP    
  // PMP setup 
  PMMODEbits.MODE  = 0b10;  // Master 2
  PMMODEbits.WAITB = 0b00;
  PMMODEbits.WAITM = 0b0001;
  PMMODEbits.WAITE = 0b00;
  PMAENbits.PTEN0  = 1;     // Address line 0 is enabled
  PMCONbits.CSF    = 0b00;
  PMCONbits.PTRDEN = 1;    
  PMCONbits.PTWREN = 1;
  PMCONbits.PMPEN  = 1; 
#else
  SetData(0);
  SetTRISOutput();
#endif



  // let controller come out of reset
  RESET = 1;
  DelayMs(20);

  // Enable LCD
  // Init display RAM starting location
  WriteCommand(CONTROLLER_BOTH, LCD_START_COMMAND);
  // Turn ON each screen portion
  WriteCommand(CONTROLLER_BOTH, LCD_ON_COMMAND);

  DelayMs(20);
}

/*********************************************************************
* Function: void PutPixel(SHORT x, SHORT y)
*
* PreCondition: none
*
* Input: x,y - pixel coordinates
*
* Output: none
*
* Side Effects: none
*
* Overview: puts pixel
*
* Note: none
*
********************************************************************/
void PutPixel(SHORT x, SHORT y)
{
  BYTE value, new_value;
  
  if(_clipRgn)
  {
    if(x<_clipLeft)
      return;
    if(x>_clipRight)
      return;
    if(y<_clipTop)
      return;
    if(y>_clipBottom)
      return;
  }
  //return if the pixel is off the display.
  // the controller will turn off is it given bad addresses
  if (( x < 0)|| (x > SCREEN_HOR_SIZE - 1) || (y < 0) || (y > SCREEN_VER_SIZE - 1) )
    return;

  x = GetChipSelect(x);
  y = GetPageSelect(y);
  SetColumnSelect(x);
  value = ReadDataSingle();
  new_value = (GetColor()) ? (value | (1 << y)) : (value & ~(1 << y));  
  if (new_value != value)
  {  
    SetColumnSelect(x);  // set back auto address increment
    WriteData(new_value);
  }  
  DeSelect();
}

/*********************************************************************
* Function: WORD GetPixel(SHORT x, SHORT y)
*
* PreCondition: none
*
* Input: x,y - pixel coordinates 
*
* Output: pixel color
*
* Side Effects: none
*
* Overview: return pixel color at x,y position
*
* Note: none
*
********************************************************************/
WORD GetPixel(SHORT x, SHORT y)
{
  BYTE data;
  //return if the pixel is off the display.
  // the controller will turn off is it given bad addresses
  if (( x < 0)|| (x > SCREEN_HOR_SIZE - 1) || (y < 0) || (y > SCREEN_VER_SIZE - 1) )
    return BLACK;
    
  x = GetChipSelect(x);
  SetColumnSelect(x);
  y = GetPageSelect(y);
  data = ReadDataSingle();
  DeSelect();
  if (data & (1 << y))
    return WHITE;
  else
    return BLACK;
}

/*********************************************************************
* Function: void PutImage(SHORT left, SHORT top, void* bitmap, BYTE stretch)
*
* PreCondition: none
*
* Input: left,top - left top image corner, bitmap - image pointer,
*        stretch - image stretch factor
*
* Output: none
*
* Side Effects: none
*
* Overview: outputs image starting from left,top coordinates
*
* Note: image must be located in flash
*
********************************************************************/
void PutImage(SHORT left, SHORT top, void* bitmap, BYTE stretch)
{
  FLASH_BYTE* flashAddress;
  BYTE colorDepth;
  BYTE compression;
  WORD colorTemp;

  // Save current color
  colorTemp = _color.Val;

  // This version supports only internal flash memory 
  if(((BITMAP_FLASH*)bitmap)->type != FLASH)
    return;

  flashAddress = ((BITMAP_FLASH*)bitmap)->address;

  // Read compession info
  compression = *flashAddress;

  // Read color depth
  colorDepth = *(flashAddress+1);

  if(compression){

  }else{
    switch(colorDepth){
      case 1:
        PutImage1BPP(left, top, flashAddress, stretch);
        break;
      case 4:
        PutImage4BPP(left, top, flashAddress, stretch);
        break;
      case 8:
        PutImage8BPP(left, top, flashAddress, stretch);
        break;
      case 16:
        PutImage16BPP(left, top, flashAddress, stretch);
        break;
    }
  }
  // Restore current color
  _color.Val = colorTemp;
}
/*********************************************************************
* Function: void PutImage1BPP(SHORT left, SHORT top, FLASH_BYTE* bitmap, BYTE stretch)
*
* PreCondition: none
*
* Input: left,top - left top image corner, bitmap - image pointer,
*        stretch - image stretch factor
*
* Output: none
*
* Side Effects: none
*
* Overview: outputs monochrome image starting from left,top coordinates
*
* Note: image must be located in flash
* Use a page buffer so that we can read all of the image into the buffer
* and then output it onto the controller of interest.
* 
* With this orientation, we just need to get the bits or'ed into the column data
* I am going to ignore the stretch for now.  It complicates things.
********************************************************************/
BYTE ImageBuffer[64];
void PutImage1BPP(SHORT left, SHORT top, FLASH_BYTE* bitmap, BYTE stretch)
{

  register FLASH_BYTE *flashAddress;
  register FLASH_BYTE *tempFlashAddress;
  register WORD address;
  BYTE temp;
  register WORD sizeX, sizeY;
  WORD x,y;
  register BYTE stretchX,stretchY;
  WORD pallete[2];
  BYTE mask;

  // Move pointer to size information
  flashAddress = bitmap + 2;

  // Set start address
  address = left;

  // Read image size
  sizeY = *((FLASH_WORD*)flashAddress);
  flashAddress += 2;
  sizeX = *((FLASH_WORD*)flashAddress);
  flashAddress += 2;
  pallete[0] = *((FLASH_WORD*)flashAddress);
  flashAddress += 2;
  pallete[1] = *((FLASH_WORD*)flashAddress);
  flashAddress += 2;

 // three cases, left, right, or both controllers
  if (left > SCREEN_PAGE_SIZE)   // all on controller 2
  {
    BitBlit(left, top, right - SCREEN_PAGE_SIZE, bottom);
  }  
  else // left is on first contoller
  if (right < SCREEN_PAGE_SIZE) // all on controller 1
  {
    FillRect(left, top, right, bottom);
  }  
  else  // both
  {
    FillRect(left, top, SCREEN_PAGE_SIZE-1, bottom);
    FillRect(SCREEN_PAGE_SIZE, top, right - SCREEN_PAGE_SIZE, bottom);
  }
  
  
  mask = top % 8;
  for(y=0; y<sizeY; y++)
  {
    tempFlashAddress = flashAddress;
    for(stretchY = 0; stretchY<stretch; stretchY++)
    {
      flashAddress = tempFlashAddress;
      address = left;
      for(x=0; x<sizeX; x++){
        // Read 8 pixels from flash
        if(mask == 0)
        {
          // write the buffer
          temp = *flashAddress;
          flashAddress++;
          mask = 0x80;
        }
        // Set color
        if(mask&temp){
          SetColor(pallete[1]);
        }else{
          SetColor(pallete[0]);
        }
        // Write pixel to screen
        for(stretchX=0; stretchX<stretch; stretchX++)
        {
          if (_color.v[0])
            ImageBuffer[address+x+stretchX] |= mask;
          else
            ImageBuffer[address+x+stretchX] &= ~mask;
        }

        // Shift to the next pixel
        mask >>= 1;
        address++;
      }
    }
  }
}

/*********************************************************************
* Function: void PutImage4BPP(SHORT left, SHORT top, FLASH_BYTE* bitmap, BYTE stretch)
*
* PreCondition: none
*
* Input: left,top - left top image corner, bitmap - image pointer,
*        stretch - image stretch factor
*
* Output: none
*
* Side Effects: none
*
* Overview: outputs 16 color image starting from left,top coordinates
*
* Note: image must be located in flash
*
********************************************************************/
void PutImage4BPP(SHORT left, SHORT top, FLASH_BYTE* bitmap, BYTE stretch)
{
#if 0
  register DWORD_VAL address;
  register FLASH_BYTE* flashAddress;
  register FLASH_BYTE* tempFlashAddress;
  WORD sizeX, sizeY;
  register WORD x,y;
  BYTE temp;
  register BYTE stretchX,stretchY;
  WORD pallete[16];
  WORD counter;

  // Move pointer to size information
  flashAddress = bitmap + 2;

  // Set start address
  address.Val = (long)LINE_MEM_PITCH*top + left;

  // Read image size
  sizeY = *((FLASH_WORD*)flashAddress);
  flashAddress += 2;
  sizeX = *((FLASH_WORD*)flashAddress);
  flashAddress += 2;

  // Read pallete
  for(counter=0;counter<16;counter++){
    pallete[counter] = *((FLASH_WORD*)flashAddress);
    flashAddress += 2;
  }

  //    CS_LAT = 0;     
  for(y=0; y<sizeY; y++){
    tempFlashAddress = flashAddress;
    for(stretchY = 0; stretchY<stretch; stretchY++){
      flashAddress = tempFlashAddress;
      SetAddress(address.v[2],address.v[1],address.v[0]);
      for(x=0; x<sizeX; x++){
        // Read 2 pixels from flash
        if((x&0x0001) == 0){
          temp = *flashAddress;
          flashAddress++;
        }
        // Set color
        SetColor(pallete[temp&0x0f]);

        // Write pixel to screen       
        for(stretchX=0; stretchX<stretch; stretchX++){
          WriteData(_color.v[0]);
        }

        // Shift to the next pixel
        temp >>= 4;
      }
      address.Val += LINE_MEM_PITCH;
    }
  }
  //    CS_LAT = 1;
#endif  
}

/*********************************************************************
* Function: void PutImage8BPP(SHORT left, SHORT top, FLASH_BYTE* bitmap, BYTE stretch)
*
* PreCondition: none
*
* Input: left,top - left top image corner, bitmap - image pointer,
*        stretch - image stretch factor
*
* Output: none
*
* Side Effects: none
*
* Overview: outputs 256 color image starting from left,top coordinates
*
* Note: image must be located in flash
*
********************************************************************/
void PutImage8BPP(SHORT left, SHORT top, FLASH_BYTE* bitmap, BYTE stretch)
{
#if 0  
  register DWORD_VAL address;
  register FLASH_BYTE* flashAddress;
  register FLASH_BYTE* tempFlashAddress;
  WORD sizeX, sizeY;
  register WORD x,y;
  BYTE temp;
  register BYTE stretchX,stretchY;
  WORD pallete[256];
  WORD counter;

  // Move pointer to size information
  flashAddress = bitmap + 2;

  // Set start address
  address.Val = (long)LINE_MEM_PITCH*top + left;

  // Read image size
  sizeY = *((FLASH_WORD*)flashAddress);
  flashAddress += 2;
  sizeX = *((FLASH_WORD*)flashAddress);
  flashAddress += 2;

  // Read pallete
  for(counter=0;counter<256;counter++){
    pallete[counter] = *((FLASH_WORD*)flashAddress);
    flashAddress += 2;
  }

  //    CS_LAT = 0;     
  for(y=0; y<sizeY; y++){
    tempFlashAddress = flashAddress;
    for(stretchY = 0; stretchY<stretch; stretchY++){
      flashAddress = tempFlashAddress;
      SetAddress(address.v[2],address.v[1],address.v[0]);
      for(x=0; x<sizeX; x++){
        // Read pixels from flash
        temp = *flashAddress;
        flashAddress++;

        // Set color
        SetColor(pallete[temp]);

        // Write pixel to screen       
        for(stretchX=0; stretchX<stretch; stretchX++){
          WriteData(_color.v[0]);
        }
      }
      address.Val += LINE_MEM_PITCH;
    }
  }
  //    CS_LAT = 1;
#endif  
}

/*********************************************************************
* Function: void PutImage16BPP(SHORT left, SHORT top, FLASH_BYTE* bitmap, BYTE stretch)
*
* PreCondition: none
*
* Input: left,top - left top image corner, bitmap - image pointer,
*        stretch - image stretch factor
*
* Output: none
*
* Side Effects: none
*
* Overview: outputs hicolor image starting from left,top coordinates
*
* Note: image must be located in flash
*
********************************************************************/
void PutImage16BPP(SHORT left, SHORT top, FLASH_BYTE* bitmap, BYTE stretch)
{
#if 0
  register DWORD_VAL address;
  register FLASH_WORD* flashAddress;
  register FLASH_WORD* tempFlashAddress;
  WORD sizeX, sizeY;
  register WORD x,y;
  WORD temp;
  register BYTE stretchX,stretchY;

  // Move pointer to size information
  flashAddress = (FLASH_WORD*)bitmap + 1;

  // Set start address
  address.Val = (long)LINE_MEM_PITCH*top + left;

  // Read image size
  sizeY = *flashAddress;
  flashAddress++;
  sizeX = *flashAddress;
  flashAddress++;

  //    CS_LAT = 0;     
  for(y=0; y<sizeY; y++){
    tempFlashAddress = flashAddress;
    for(stretchY = 0; stretchY<stretch; stretchY++){
      flashAddress = tempFlashAddress;
      SetAddress(address.v[2],address.v[1],address.v[0]);
      for(x=0; x<sizeX; x++){
        // Read pixels from flash
        temp = *flashAddress;
        flashAddress++;

        // Set color
        SetColor(temp);

        // Write pixel to screen       
        for(stretchX=0; stretchX<stretch; stretchX++){
          WriteData(_color.v[0]);
        }
      }
      address.Val += LINE_MEM_PITCH; 
    }
  }
  //    CS_LAT = 1;
#endif  
}

/*********************************************************************
* Function: WORD GetImageWidth(void* bitmap)
*
* PreCondition: none
*
* Input: bitmap - image pointer
*
* Output: none
*
* Side Effects: none
*
* Overview: returns image width
*
* Note: image must be located in flash
*
********************************************************************/
#if 0
WORD GetImageWidth(void* bitmap){
    return *( (FLASH_WORD*)((BITMAP_FLASH*)bitmap)->address+2 );
}
#endif

/*********************************************************************
* Function: WORD GetImageHeight(void* bitmap)
* PreCondition: none
* Input: bitmap - image pointer
* Output: none
* Side Effects: none
* Overview: returns image height
* Note: image must be located in flash
*
********************************************************************/
#if 0
WORD GetImageHeight(void* bitmap){
    return *( (FLASH_WORD*)((BITMAP_FLASH*)bitmap)->address+1 );
}
#endif

/*********************************************************************
* Function: void Bar(SHORT left, SHORT top, SHORT right, SHORT bottom)
* PreCondition: none
* Input: left,top - top left corner coordinates,
*        right,bottom - bottom right corner coordinates
* Output: none
* Side Effects: none
* Overview: draws rectangle filled with current color
* Note:
*  This can be optimized a bit by using a buffer to read the current
*  LCD ram contents, then OR or AND in the new contents.  Do this on one
*  controller at a time.
********************************************************************/
#ifdef USE_DRV_BAR
BYTE PageBuffer[64];

 
void Bar(SHORT left, SHORT top, SHORT right, SHORT bottom)
{
  if(_clipRgn)
  {
    if(left < _clipLeft)
      left = _clipLeft;
    if(right > _clipRight)
      right= _clipRight;
    if(top < _clipTop)
      top = _clipTop;
    if(bottom > _clipBottom)
      bottom = _clipBottom;
  }
  // three cases, left, right, or both controllers
  if (left > SCREEN_PAGE_SIZE)   // all on controller 2
  {
    FillRect(left, top, right - SCREEN_PAGE_SIZE, bottom);
  }  
  else // left is on first contoller
  if (right < SCREEN_PAGE_SIZE) // all on controller 1
  {
    FillRect(left, top, right, bottom);
  }  
  else  // both
  {
    FillRect(left, top, SCREEN_PAGE_SIZE-1, bottom);
    FillRect(SCREEN_PAGE_SIZE, top, right - SCREEN_PAGE_SIZE, bottom);
  }
  MoveTo(right,bottom);
}  
/*********************************************************************
* Function: void FillRect(SHORT left, SHORT top, SHORT right, SHORT bottom)
* PreCondition: none
* Input: left,top - top left corner coordinates,
*        right,bottom - bottom right corner coordinates
* Output: none
* Side Effects: none
* Overview: will fill rectangle with current color
* Note:
*  retangle must be normalized to fit on one controller.
*  right - left ! > SCREEN_PAGE_SIZE
********************************************************************/ 
static void FillRect(SHORT left, SHORT top, SHORT right, SHORT bottom)
{
  register BYTE mask;
  register WORD i;
  WORD h, y, x;
  WORD height;
  

  height = (bottom + 1) - top;
  // first strip, perhaps, the only strip if it is narrow 
  x = GetChipSelect(left);
  y = GetPageSelect(top);
  top -= y;
  mask = 0xFF;
  if (height < (8 - y))
  {
		mask >>= (8 - height);
		h = height;
	}
	else
	{
		h = 8 - y;
	}
  mask <<= y;
  SetColumnSelect(x);
  ReadDataLatch(); // sets the latch
  for (i = x; i <= right; i++)
  {
    PageBuffer[i] = ReadData();
    if(GetColor())
      PageBuffer[i] |= mask;
    else
       PageBuffer[i] &= ~mask;
  }
  SetColumnSelect(x);
  for (i = x; i <= right; i++)
    WriteData(PageBuffer[i]);
 
 // middle strips of page size    
  while(h + 8 <= height)
  {
		h += 8;
		top += 8;
		y = GetPageSelect(top);
		SetColumnSelect(x);
		for (i = x; i<= right; i++)
			WriteData((GetColor()) ? 0xFF : 0);
	}
	// remainder strip
	if(h < height)
  {
		mask = ~(0xFF << (height - h));
		y = GetPageSelect(top + 8);
		SetColumnSelect(x);
		ReadDataLatch();
	  for (i = x; i <= right; i++)
    {
      PageBuffer[i] = ReadData();
      if(GetColor())
        PageBuffer[i] |= mask;
      else
         PageBuffer[i] &= ~mask;
    }
    SetColumnSelect(x);
    for (i = x; i <= right; i++)
      WriteData(PageBuffer[i]);
  }
}
#endif

/*********************************************************************
* Function: void ClearDevice(void)
* PreCondition: none
* Input: none
* Output: none
* Side Effects: none
* Overview: clears screen with current color 
* Note: Select both controllers and write each page 
********************************************************************/
void ClearDevice(void)
{
  WORD page;
  BYTE color = 0;
  WORD i;
  
   if(_color.v[0] | _color.v[1])
      color = 0xFF;
      
  // bad commands will turn off the LCD      
  WriteCommand(CONTROLLER_BOTH, LCD_START_COMMAND);
  WriteCommand(CONTROLLER_BOTH, LCD_ON_COMMAND);
  
  CS1 = 1;
  CS2 = 1;
  for(page = 0; page < 8; page++)
  {
    WriteInst(PAGE_COMMAND | page);
    SetColumnSelect(0);
    for (i=0; i<64; i++)
    {
      WriteData(color);
    }
  }
  WriteInst(PAGE_COMMAND);  // page 0
  SetColumnSelect(0);
  MoveTo(0,0);
  DeSelect();
}

/*********************************************************************
* Function: WORD IsDeviceBusy(void)
* PreCondition: none
* Input: none
* Output: none
* Side Effects: none
* Overview: clears screen with current color 
* Note: returns true if device busy
********************************************************************/

WORD IsDeviceBusy(void)
{
  return 0;
#if 0
  BYTE value;
  SetTRISInput();
  RW_RS_STATUS();
  value = GetData();
  value &= 0x80;
  return (WORD) value;
#endif
}

/*******************  static functions ***************/

/*********************************************************************
* Function: static void BitBlit(BYTE chip_select)
* PreCondition: none
* Input:
*   page - 0 - 7
*   column - the starting column
*   length - how many bytes to blit
*   data - pointer to buffer with data
* Output: none
* Side Effects: none
* Overview: 
* Note: 
********************************************************************/
static void BitBlit(WORD left, WORD column, WORD lenght, BYTE * data)
{
}  
  


/*********************************************************************
* Function: static void PollReady()
* PreCondition: none
* Input: none
* Output: none
* Side Effects: none
* Overview: 
* Note: 
********************************************************************/
static void PollReady(void)
{
  volatile BYTE value;
  
  SetTRISInput();
  RW_RS_STATUS();
  do
  {
    value = GetData();
    if (value & 0x20)
    {
      SetData(LCD_ON_COMMAND);
      SetTRISOutput();
      RW_RS_CMD();
      STROBE_WRITE();
      SetTRISInput();
    }  
    value &= 0x80;
  } while(value);

}


/*********************************************************************
* Function: static void WriteInst(BYTE chip_select, BYTE value)
* PreCondition: none
* Input:
*   chip_select - for multiple controllers
*   value - of command
* Output: none
* Side Effects: none
* Overview: 
* Note: 
********************************************************************/
static void WriteCommand(BYTE chip_select, BYTE value)
{
  SELECT_CHIPS(chip_select);
  PollReady();
  SetData(value);
  SetTRISOutput();
  RW_RS_CMD();
  STROBE_WRITE();
  DeSelect();
}

static void WriteInst(BYTE value)
{
  PollReady();
  SetData(value);
  SetTRISOutput();
  RW_RS_CMD();
  STROBE_WRITE();
}

/*********************************************************************
* Function: static void WriteData(BYTE chip_select, BYTE value)
* PreCondition: none
* Input:
*   chip_select - for multiple controllers
*   value - of data
* Output: none
* Side Effects: none
* Overview: 
* Note: 
********************************************************************/
static void WriteData(BYTE value)
{
  PollReady();
  SetData(value);
  SetTRISOutput();
  RW_RS_WDATA();
  STROBE_WRITE();
}
/******************************************************************************************************
 * Read data value. 
 *
 * @return value      OUT  value read of the display strip at memory location of coordinates (y, page)
 ******************************************************************************************************/
static BYTE ReadDataSingle()
{
  BYTE value;
  
  PollReady();
  RW_RS_RDATA();
  value = GetData(); // The first read performed is a latch
  PollReady();
  RW_RS_RDATA();
  value = GetData(); // The second read is the value
  return(value);
}
/******************************************************************************************************
 * Read data value. 
 *
 * @return value      OUT  value read of the display strip at memory location of coordinates (y, page)
 * Note: don't need to set latch if we are reading multiple bytes
 ******************************************************************************************************/
static BYTE ReadData()
{
  BYTE value;
  
  PollReady();
  RW_RS_RDATA();
  value = GetData(); // The first read performed is a latch
  return(value);
}

static WORD GetChipSelect(WORD x)
{
  if (x < SCREEN_PAGE_SIZE)
   { CS1 = 1; CS2 = 0; }
  else
   { x -= SCREEN_PAGE_SIZE; CS1 = 0; CS2 = 1; }
  return x;
}


static WORD GetPageSelect(WORD y)
{
  BYTE page = (BYTE)(y >> 3);
  if (page > 7)
    page = 7;
  WriteInst(PAGE_COMMAND | page);
//  return (y == 0) ? y : y % 8;  // don't trust compiler to avoid divide by zero
  return y % 8;
}

static void SetColumnSelect(WORD x)
{
//  if(x > 63)
//    x = 63;
  WriteInst(ADDRESS_COMMAND | (BYTE)x);
}

static BYTE GetData(void)
{
  volatile char data;
  E = 1;
  Nops(8);
  data = GETSETBYTE(PORTDATA, WHICH_BYTE);
  E = 0;
  return data;
}



// these could be inline
#ifndef USE_INLINE_FUNCTIONS


void SetTRISInput(void)
{
 GETSETBYTE(TRISDATA, WHICH_BYTE) = 0xFF;
 DIR = 0;
}

void SetTRISOutput(void)
{
   GETSETBYTE(TRISDATA, WHICH_BYTE) = 0x0;
   DIR = 1;
}


static void SetData(BYTE value)
{
  GETSETBYTE(DATALATCH, WHICH_BYTE) = value;
}



static void RW_RS_CMD(void)
{
  RW = RW_WRITE;
  RS = LCDINST;
  Nop();
}

static void RW_RS_STATUS(void)
{
  RW = RW_READ;
  RS = LCDINST;
  Nop();
}
static void RW_RS_WDATA(void)
{
  RW = RW_WRITE;
  RS = LCDDATA;
  Nop();
}
static void RW_RS_RDATA(void)
{
  RW = RW_READ;
  RS = LCDDATA;
  Nop();
}
   
static void STROBE_WRITE()
{
  E = 1;
  Nops(8);
  E = 0;
}

#endif
