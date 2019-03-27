/**
  ******************************************************************************
    @file     ili9328_.c
  * @author   
  *
  ******************************************************************************
*/
/* Includes ------------------------------------------------------------------*/
#include "usr_sys.h"   
#include "usr_delay.h"   
#include "usr_spi.h"   
#include "ili9328.h"
//#include "fonts.c"

typedef struct {
		uint16_t    width;         // LCD width in pixels (default orientation)
		uint16_t    height;        // LCD height in pixels (default orientation)
		uint16_t    touchscreen;   // Whether the LCD has a touch screen
		uint16_t    orientation;   // Whether the LCD orientation can be modified
		uint16_t    hwscrolling;   // Whether the LCD support HW scrolling
} lcdProperties_t;

typedef struct {
  int               idx;         // pin 
  GPIO_TypeDef*     port;        // Port
  const uint16_t    pin;         // Pin
  const uint32_t    clk;         // Clock
  BitAction         initValue;   // Init
  //char              name[4];
} lcdDevGPIO;


typedef struct {
   int                orientation;
   int                color;	
	 lcdProperties_t   *property;
	 lcdDevGPIO        *gpio;
} ili9328_driver; 


//--------------------------------------------------------------
#define  LCD_RST    0  // match arrary index  
#define  LCD_CS     1  // match arrary index  
#define  LCD_BL     2  // match arrary index  

static lcdDevGPIO   oGPIO[] = { 
	// Name   , PORT , PIN         , CLOCK               , Init
  { LCD_RST, GPIOB,  GPIO_Pin_8 , RCC_APB2Periph_GPIOB, Bit_SET},
  { LCD_CS , GPIOA,  GPIO_Pin_11, RCC_APB2Periph_GPIOA, Bit_RESET},
};

static  lcdProperties_t  oProperty = {240, 320, 0, 1, 1};

#define PIN_NUM      (sizeof(oGPIO)/sizeof(lcdDevGPIO))


// ========================================
//  static global object 
// ========================================
static ili9328_driver   oDev 
#if 0 
= {
  .orientation      = 0,
 	.color            = 1,	
	.property         = &oProperty, // {240, 320, 0, 1, 1}, 
	.gpio             = &oGPIO[0],
}
#endif
;

//--------------------------------------------------------------
static void PIN_RESET(int pin) {  GPIO_ResetBits(oGPIO[pin].port, oGPIO[pin].pin ); }
static void PIN_SET  (int pin) {  GPIO_SetBits  (oGPIO[pin].port, oGPIO[pin].pin ); }

/**************************************************************************
    @brief  Writes the supplied 16-bit command using an 8-bit interface
**************************************************************************/
static void ili9328_write_command(uint16_t command) 
{
  unsigned char temp;   

  PIN_RESET (LCD_CS) ;     // CS enable 
  temp = 0x70;      //RS = 1, data  RW = 0, write mode   
  usrspi2_SendByte3Wire  (temp); 
	temp = (command >>8)&0xff;   
  usrspi2_SendByte3Wire (temp); 
	temp = (command>>0)&0xff;   
  usrspi2_SendByte3Wire (temp);
  PIN_SET (LCD_CS) ;     // CS enable 
}

/**************************************************************************
    @brief  Writes the supplied 16-bit data using an 8-bit interface
**************************************************************************/
static void ili9328_write_data(uint16_t data)
{
  unsigned char temp;   

  PIN_RESET (LCD_CS) ;     // CS enable 
  temp = 0x72;      //RS = 1, data  RW = 0, write mode   
  usrspi2_SendByte3Wire  (temp); //LCD_SendByte(temp);// send SPI frame 
  temp = (data>>8)&0xff;   
  usrspi2_SendByte3Wire  (temp); //LCD_SendByte(temp);// send SPI frame 
  temp = (data>>0)&0xff;   
  usrspi2_SendByte3Wire  (temp); //LCD_SendByte(temp);// send SPI frame 
	PIN_SET (LCD_CS) ;     // CS enable 
  
}
  


/**************************************************************************
    @brief  Reads a 16-bit value
**************************************************************************/
static uint16_t ili9328_read_data(uint16_t addr)
{
  uint16_t data ; 

  PIN_RESET (LCD_CS) ;     // CS enable 
  ili9328_write_command (addr);
  data = usrspi2_WriteReadAByte (0x00);
  PIN_SET (LCD_CS) ;     
}

/**************************************************************************/
/*! 
    @brief  Sends a 16-bit command + 16-bit data
*/
/**************************************************************************/
static void ili9328_command (uint16_t command, uint16_t data)
{
  PIN_RESET (LCD_CS) ;     // CS enable 
  ili9328_write_command (command);
  ili9328_write_data    (data);
  PIN_SET (LCD_CS) ;     // CS disable 
}


/**************************************************************************
    @brief  Sets the cursor to the specified X/Y position
**************************************************************************/
void ili9328_set_cursor(uint16_t x, uint16_t y)
{
  uint16_t al, ah;
  
  if (oDev.orientation == LCD_ORIENTATION_LANDSCAPE)  {
    al = y;
    ah = x;
  }  else  {
    al = x;
    ah = y;
  }
  ili9328_command ( CMD_HORIZONTALGRAMADDRESSSET, al);
  ili9328_command ( CMD_VERTICALGRAMADDRESSSET  , ah);
}


/**************************************************************************
*   @brief  Sends the initialisation sequence to the display controller
**************************************************************************/
void ili9328_init_display(void)
{
  GPIO_InitTypeDef        GPIO_InitStructure;
  int  pin;

  oDev.orientation      = 0;
 	oDev.color            = 1;	
	oDev.property         = &oProperty; // {240, 320, 0, 1, 1}, 
	oDev.gpio             = &oGPIO[0];
	
  for(pin=0; pin < PIN_NUM; pin++) {
    // Clock Enable
    RCC_APB2PeriphClockCmd(oDev.gpio[pin].clk, ENABLE);

    // Config als Digital-output
    GPIO_InitStructure.GPIO_Pin     = oDev.gpio[pin].pin;
    GPIO_InitStructure.GPIO_Mode    = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(oDev.gpio[pin].port, &GPIO_InitStructure);

    // set default of each pin 
    if (oDev.gpio[pin].initValue == Bit_RESET) {
        PIN_RESET(pin);
    } else {
        PIN_SET(pin);
    }
  }

  usrspi2_init (2, 0, 0); // three wire, MSB first, mode = 0       
  usrspi2_setspeed(SPI_BaudRatePrescaler_256);  // SPI_BaudRatePrescaler_2); clk PW=0.025us = 28 ns/ 256 clk PW = 4us; 128 = 1.8us ( confirmed!!)

  // reset LCD module ==========
  PIN_RESET (LCD_RST );    
  delay_ms(100);   
  PIN_SET (LCD_RST );    
  delay_ms(1);   

  // set commands  
  ili9328_command(CMD_DRIVEROUTPUTCONTROL1, 0x0100);  // Driver Output Control Register (R01h)
  ili9328_command(CMD_LCDDRIVINGCONTROL, 0x0700);     // LCD Driving Waveform Control (R02h)
  ili9328_command(CMD_ENTRYMODE, 0x1030);             // Entry Mode (R03h)  
  ili9328_command(CMD_DISPLAYCONTROL2, 0x0302);
  ili9328_command(CMD_DISPLAYCONTROL3, 0x0000);
  ili9328_command(CMD_DISPLAYCONTROL4, 0x0000);       // Fmark On
  ili9328_command(CMD_POWERCONTROL1, 0x0000);         // Power Control 1 (R10h)
  ili9328_command(CMD_POWERCONTROL2, 0x0007);         // Power Control 2 (R11h)
  ili9328_command(CMD_POWERCONTROL3, 0x0000);         // Power Control 3 (R12h)
  ili9328_command(CMD_POWERCONTROL4, 0x0000);         // Power Control 4 (R13h)
  
	delay_ms(1000);  
  
	ili9328_command(CMD_POWERCONTROL1, 0x14B0);         // Power Control 1 (R10h)  
  
	delay_ms(500);  
  
	ili9328_command(CMD_POWERCONTROL2, 0x0007);         // Power Control 2 (R11h)  
  
	delay_ms(500);  
  
	ili9328_command(CMD_POWERCONTROL3, 0x008E);         // Power Control 3 (R12h)
  ili9328_command(CMD_POWERCONTROL4, 0x0C00);         // Power Control 4 (R13h)
  ili9328_command(CMD_POWERCONTROL7, 0x0015);         // NVM read data 2 (R29h)
  
	delay_ms(500);
  
	ili9328_command(CMD_GAMMACONTROL1, 0x0000);         // Gamma Control 1
  ili9328_command(CMD_GAMMACONTROL2, 0x0107);         // Gamma Control 2
  ili9328_command(CMD_GAMMACONTROL3, 0x0000);         // Gamma Control 3
  ili9328_command(CMD_GAMMACONTROL4, 0x0203);         // Gamma Control 4
  ili9328_command(CMD_GAMMACONTROL5, 0x0402);         // Gamma Control 5
  ili9328_command(CMD_GAMMACONTROL6, 0x0000);         // Gamma Control 6
  ili9328_command(CMD_GAMMACONTROL7, 0x0207);         // Gamma Control 7
  ili9328_command(CMD_GAMMACONTROL8, 0x0000);         // Gamma Control 8
  ili9328_command(CMD_GAMMACONTROL9, 0x0203);         // Gamma Control 9
  ili9328_command(CMD_GAMMACONTROL10, 0x0403);        // Gamma Control 10
  ili9328_command(CMD_HORIZONTALADDRESSSTARTPOSITION, 0x0000);                      // Window Horizontal RAM Address Start (R50h)
  
	//ili9328_command(CMD_HORIZONTALADDRESSENDPOSITION, ili9328_Properties.width - 1);   // Window Horizontal RAM Address End (R51h)
  
	ili9328_command(CMD_VERTICALADDRESSSTARTPOSITION, 0X0000);                        // Window Vertical RAM Address Start (R52h)
  
	//ili9328_command(CMD_VERTICALADDRESSENDPOSITION, ili9328_Properties.height - 1);    // Window Vertical RAM Address End (R53h)
  
	ili9328_command(CMD_DRIVEROUTPUTCONTROL2, 0xa700);    // Driver Output Control (R60h)
  ili9328_command(CMD_BASEIMAGEDISPLAYCONTROL, 0x0003); // Driver Output Control (R61h) - enable VLE
  ili9328_command(CMD_PANELINTERFACECONTROL1, 0X0010);  // Panel Interface Control 1 (R90h)

  // Display On
  ili9328_command(CMD_DISPLAYCONTROL1, 0x0133);     // Display Control (R07h)
  
	delay_ms (500);
  
	ili9328_write_command (CMD_WRITEDATATOGRAM);
}

/**************************************************************************
 *    @brief  Sets the cursor to the home position (0,0)
 *************************************************************************
*/
void ili9328_home(void)
{
  ili9328_set_cursor(0, 0);
  ili9328_write_command (CMD_WRITEDATATOGRAM); 
	// Write Data to GRAM (R22h)
}

/**************************************************************************
    @brief  Sets the window confines
**************************************************************************/
void ili9328_set_window(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1)
{
  ili9328_command(CMD_HORIZONTALADDRESSSTARTPOSITION, x0);
  ili9328_command(CMD_HORIZONTALADDRESSENDPOSITION,   x1);
  ili9328_command(CMD_VERTICALADDRESSSTARTPOSITION,   y0);
  ili9328_command(CMD_VERTICALADDRESSENDPOSITION,     y1);
  ili9328_set_cursor(x0, y0);
}

/*************************************************/
/* Public Methods                                */
/*************************************************/
void lcd_init(void)
{
  // Set control line pins to output
  
  // Set data port pins to output

  // Disable pullups
  
  // Set backlight pin to output and turn it on

  // Set reset pin to output
  PIN_RESET (LCD_RST);
  delay_ms(100);
  PIN_SET (LCD_RST);
  delay_ms(100);

  // Initialize the display
  ili9328_init_display();

  // Set lcd to default orientation
  lcd_set_orientation(LCD_ORIENTATION_PORTRAIT);

  // Fill black
  lcd_fill_RGB(0xff);
  
  // Initialise the touch screen (and calibrate if necessary)
  // tsInit();
}

/**************************************************************************/
/*! 
    @brief  Enables or disables the LCD backlight
*/
/**************************************************************************/
//void lcdBacklight(int  state)


/**************************************************************************/
/*! 
    @brief  Sets the LCD orientation to horizontal and vertical
*/
/**************************************************************************/
void lcd_set_orientation (int orientation)
{
  uint16_t entryMode     = 0x1030;
  uint16_t outputControl = 0x0100;

  switch (orientation)  {
    case LCD_ORIENTATION_PORTRAIT:
      entryMode = 0x1030;
      outputControl = 0x0100;
      break;
    case LCD_ORIENTATION_LANDSCAPE:
      entryMode = 0x1028;
      outputControl = 0x0000;
      break;
  }

  ili9328_command(CMD_ENTRYMODE, entryMode);
  ili9328_command(CMD_DRIVEROUTPUTCONTROL1, outputControl);
  oDev.orientation = orientation;

  ili9328_set_cursor(0, 0);
}


/**************************************************************************/
/*! 
    @brief  Fills the LCD with the specified 16-bit color
*/
/**************************************************************************/
void lcd_fill_RGB(uint16_t data)
{
  unsigned int i;
  uint32_t pixels = 320*240;
  
  ili9328_home();
  
  for ( i=0; i < pixels; i++ ){
    ili9328_write_data(data);
  } 
}

/**************************************************************************/
/*! 
    @brief  Draws a single pixel at the specified X/Y location
*/
/**************************************************************************/
void lcd_draw_pixel(uint16_t x, uint16_t y, uint16_t color)
{
  ili9328_set_cursor     (x, y);
  ili9328_write_command  (CMD_WRITEDATATOGRAM);  // Write Data to GRAM (R22h)
  ili9328_write_data     (color);
}

/**************************************************************************/
/*! 
    @brief  Draws an array of consecutive RGB565 pixels (much
            faster than addressing each pixel individually)
*/
/**************************************************************************/
void lcd_draw_pixels (uint16_t x, uint16_t y, uint16_t *data, uint32_t len)
{
  uint32_t i = 0;
  ili9328_set_cursor(x, y);
  ili9328_write_command  (CMD_WRITEDATATOGRAM);
  do {
    ili9328_write_data (data[i]);
    i++;
  } while (i<len);
}

/**************************************************************************/
/*! 
    @brief  Optimised routine to draw a horizontal line faster than
            setting individual pixels
*/
/**************************************************************************/
void lcd_draw_line(uint16_t x0, uint16_t x1, uint16_t y, uint16_t color)
{
  // Allows for slightly better performance than setting individual pixels
  uint16_t x, pixels;
  if (x1 < x0) {   // Switch x1 and x0
    x = x1;
    x1 = x0;
    x0 = x;
  }
  // Check limits
  if (x1 >= lcd_get_width() ) {
    x1 = lcd_get_width()  - 1;
  }
  if (x0 >= lcd_get_width() )  {
    x0 = lcd_get_width()  - 1;
  }

  ili9328_set_cursor(x0, y);
  ili9328_write_command (CMD_WRITEDATATOGRAM);  // Write Data to GRAM (R22h)
  for (pixels = 0; pixels < x1 - x0 + 1; pixels++)  {
    ili9328_write_data (color);
  }
}

/**************************************************************************/
/*! 
    @brief  Optimised routine to draw a vertical line faster than
            setting individual pixels
*/
/**************************************************************************/
#if 0
void lcd_draw_vline(uint16_t x, uint16_t y0, uint16_t y1, uint16_t color)
{
  int  oldOrientation = lcd_get_orientation ();

  if (oldOrientation == LCD_ORIENTATION_PORTRAIT)
  {
    lcd_set_orientation (LCD_ORIENTATION_LANDSCAPE);
    lcd_draw_hline (y0, y1, lcd_get_height() - (x + 1), color);
  }  else  {
    lcd_set_orientation (LCD_ORIENTATION_PORTRAIT);
    lcd_draw_hline (lcd_get_width() - (y0 + 1), lcd_get_width() - (y1 + 1), x, color);
  }
  // Switch orientation back
  lcd_set_orientation  (oldOrientation);
}
#endif

/**************************************************************************/
/*! 
    @brief  Gets the 16-bit color of the pixel at the specified location
*/
/**************************************************************************/
//uint16_t lcd_get_pixel(uint16_t x, uint16_t y)
//{
//  ili9328_SetCursor(x, y);
//  ili9328_WriteCmd(CMD_WRITEDATATOGRAM);
//  // prefetch
//  ili9328_ReadData();
  // Eeek ... why does this need to be done twice for a proper value?!?
//  ili9328_SetCursor(x, y);
//  ili9328_WriteCmd(CMD_WRITEDATATOGRAM);
//  return ili9328_ReadData();
//}


/**************************************************************************/
/*! 
    @brief  Gets the current screen orientation (horizontal or vertical)
*/
/**************************************************************************/
int lcd_get_orientation(void)
{
  return oDev.orientation;
}

/**************************************************************************/
/*! 
    @brief  Gets the width in pixels of the LCD screen (varies depending
            on the current screen orientation)
*/
/**************************************************************************/
uint16_t lcd_get_width (void)
{
  switch (oDev.orientation)  {
    case LCD_ORIENTATION_PORTRAIT:
      return (uint16_t)oDev.property->width;
      break;
    case LCD_ORIENTATION_LANDSCAPE:
    default:
      return (uint16_t)oDev.property->height;
  }
}

/**************************************************************************/
/*! 
    @brief  Gets the height in pixels of the LCD screen (varies depending
            on the current screen orientation)
*/
/**************************************************************************/
uint16_t lcd_get_height (void)
{
	
  switch (oDev.orientation)  {
    case LCD_ORIENTATION_PORTRAIT:
      return (uint16_t)oDev.property->height;
      break;
    case LCD_ORIENTATION_LANDSCAPE:
    default:
      return (uint16_t)oDev.property->width;
  }
}

/**************************************************************************/
/*! 
    @brief  Scrolls the contents of the LCD screen vertically the
            specified number of pixels using a HW optimised routine
*/
/**************************************************************************/
void lcd_scroll(int16_t pixels, uint16_t fillColor)
{
  int16_t y = pixels;
  while (y < 0)
    y += 320;
  while (y >= 320)
    y -= 320;

  ili9328_write_command (CMD_VERTICALSCROLLCONTROL);
  ili9328_write_data (y);
}

/**************************************************************************/
/*! 
    @brief  Gets the controller's 16-bit (4 hexdigit) ID
*/
/**************************************************************************/
//uint16_t lcdGetControllerID(void)
//{
//  return ili9328_Type();
//}

/**************************************************************************/
/*! 
    @brief  Returns the LCDs 'lcdProperties_t' that describes the LCDs
            generic capabilities and dimensions
*/
/**************************************************************************/
//int lcd_get_properties(void)
//{
//    return oDev->property;
//}