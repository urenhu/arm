//--------------------------------------------------------------
// File     : stm32_ub_lcd_2x16.c
// Datum    : 24.09.2015
// Funktion : Text-LCD Funktionen (2x16 Zeichen)
//            im 4Bit-Mode
//             PE5  -> LCD_RS
//             PE6  -> LCD_E
//             PE7  -> LCD_DB4
//             PE8  -> LCD_DB5
//             PE9  -> LCD_DB6
//             PE10 -> LCD_DB7
//--------------------------------------------------------------
#include "usr_sys.h"   
#include "usr_delay.h"   
#include "usr_spi.h"   
#include "st7066.h"

// =========== 4 bits interface ==============
#define  LCD_CMD_WAIT        40      // 40 us 
#define  LCD_CLK_PAUSE       1      // E pulse > 150ns  

#define  LCD_MAXY   2  // max y-Position (0...1)
#define  LCD_MAXX   16

#define  LCD_RST    0  // match arrary index  
#define  LCD_RS     1  // match arrary index  
#define  LCD_RW     2  // match arrary index  
#define  LCD_E      3  // match arrary index  
#define  LCD_D4     4  // match arrary index 
#define  LCD_D5     5  // match arrary index 
#define  LCD_D6     6  // match arrary index 
#define  LCD_D7     7  // match arrary index 

//--------------------------------------------------------------
// Struktur eines Pins
//--------------------------------------------------------------
typedef struct {
  int               idx;         // pin 
  GPIO_TypeDef*     port;        // Port
  const uint16_t    pin;         // Pin
  const uint32_t    clk;         // Clock
  BitAction         initValue;   // Init
  char              name[4];
} lcd_dev;

//--------------------------------------------------------------
static lcd_dev   oDev[] = {
 // Name   , PORT , PIN         , CLOCK               , Init
  { LCD_RST, GPIOB,  GPIO_Pin_8 , RCC_APB2Periph_GPIOB, Bit_SET},
  { LCD_RS , GPIOA,  GPIO_Pin_11, RCC_APB2Periph_GPIOA, Bit_RESET},
  { LCD_RW , GPIOA,  GPIO_Pin_12, RCC_APB2Periph_GPIOA, Bit_RESET},
  { LCD_E  , GPIOA,  GPIO_Pin_15, RCC_APB2Periph_GPIOA, Bit_RESET},
  { LCD_D4 , GPIOB,  GPIO_Pin_4 , RCC_APB2Periph_GPIOE, Bit_RESET},
  { LCD_D5 , GPIOB,  GPIO_Pin_5 , RCC_APB2Periph_GPIOE, Bit_RESET},
  { LCD_D6 , GPIOB,  GPIO_Pin_6 , RCC_APB2Periph_GPIOE, Bit_RESET},
  { LCD_D7 , GPIOB,  GPIO_Pin_7 , RCC_APB2Periph_GPIOE, Bit_RESET}
};

#define PIN_NUM                      (sizeof(oDev)/sizeof(lcd_dev))

//--------------------------------------------------------------
// local prototype
//--------------------------------------------------------------
static void PIN_RESET(int pin) {  GPIO_ResetBits(oDev[pin].port, oDev[pin].pin ); }
static void PIN_SET  (int pin) {  GPIO_SetBits  (oDev[pin].port, oDev[pin].pin ); }
static void dev_GPIO_init(void);
static void dev_lcd_strob(void);
static void dev_write_command(uint8_t data );
static void dev_write_data(uint8_t data);
static void dev_set_cursor(uint8_t x, uint8_t y);

//--------------------------------------------------------------
// Init vom Text-LCDisplay
//--------------------------------------------------------------
void st7066_init(void)
{
  dev_GPIO_init();

  // after power on wait 15 ms 
  delay_ms( 20 );
  
  PIN_RESET (LCD_RS);      // RS=Lo (Command)
  PIN_RESET (LCD_RW);
  PIN_RESET (LCD_D7);
  PIN_RESET (LCD_D6);
  PIN_SET   (LCD_D5);
  PIN_SET   (LCD_D4); 
  dev_lcd_strob();
  
  delay_ms( 5 );
  dev_lcd_strob();
	
  delay_us( 100 );
  dev_lcd_strob();
	
  delay_ms( 5 );
  dev_lcd_strob();

  PIN_RESET(LCD_D4); 
  dev_lcd_strob();          // set 4 bits mode,
     
  dev_write_command (0x20); // function set 4 bits, basic,  
  dev_write_command (0x08); // disp off 
  dev_write_command (0x01); // clear display
  dev_write_command (0x06); // LCD_CMD_ENTRY_MODE, basic, increase
  dev_write_command(LCD_CMD_DISP_M1);
  dev_write_command(LCD_CMD_CLEAR);

}


//--------------------------------------------------------------
// clear Text LCD Display
//--------------------------------------------------------------
void st7066_clear(void)
{
  dev_write_command(LCD_CMD_CLEAR);
}


//--------------------------------------------------------------
// mode : [LCD_OFF, LCD_ON, LCD_CURSOR, LCD_BLINK]
//--------------------------------------------------------------
void st7066_setmode(int mode)
{
	switch (mode) {
	case  LCD_OFF:
	  dev_write_command(LCD_CMD_DISP_M0);
	  break;
	case  LCD_ON:
	  dev_write_command(LCD_CMD_DISP_M1);
	  break;
	case  LCD_CURSOR:
      dev_write_command(LCD_CMD_DISP_M2);
	  break;
	case  LCD_BLINK:
	  dev_write_command(LCD_CMD_DISP_M3);
	  break;
	}
}

// set ddram address to address counter 
// 
void st7066_setline(int line)
{
	switch (line){
	case 1: 
		dev_write_command(0xC0);
		break;
	case 2:
	case 3:
	case 4:
	default:
		dev_write_command(0x80);
		break;
	}
}


//--------------------------------------------------------------
// Ausgabe von einem String auf dem Display an x,y Position
// x : 0 bis 15
// y : 0 bis 1
//--------------------------------------------------------------
void st7066_puts(uint8_t x, uint8_t y, char *ptr)
{
  dev_set_cursor(x,y);
  while (*ptr != 0) {
    dev_write_data(*ptr);
    ptr++;
  }
}

//--------------------------------------------------------------
// CG-RAM vom Display
// nr : 0 bis 7 (nummer der sonderzeichens)
// pixeldata : 8 bytes mit Pixeldaten für das Zeichen
//--------------------------------------------------------------
void st7066_writecg(uint8_t nr, uint8_t *pixeldata)
{
  uint8_t n;

  if ( nr>7 ){ 
	  nr = 7;
  }
  nr   = (nr<<3);
  nr  |= 0x40;
  dev_write_command(nr);
  for(n=0; n<8; n++) {
    dev_write_data(pixeldata[n]);
  }
}

//--------------------------------------------------------------
//--------------------------------------------------------------
static void st7066_putc(uint8_t nr)
{
  //if (nr>7) nr = 7;
  //dev_set_cursor(x,y);
  dev_write_data(nr);
}

//--------------------------------------------------------------
static void dev_GPIO_init(void)
{
  GPIO_InitTypeDef  GPIO_InitStructure;
  int  pin;
  
  for(pin=0; pin<PIN_NUM; pin++) {
    // Clock Enable
    RCC_APB2PeriphClockCmd(oDev[pin].clk, ENABLE);

    // Config als Digital-output
    GPIO_InitStructure.GPIO_Pin     = oDev[pin].pin;
    GPIO_InitStructure.GPIO_Mode    = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(oDev[pin].port, &GPIO_InitStructure);

    // set default of each pin 
    if (oDev[pin].initValue == Bit_RESET) {
	      PIN_RESET(pin);
    } else {
	      PIN_SET(pin);
	  }
  } // for end   
}

//--------------------------------------------------------------
//--------------------------------------------------------------
static void dev_lcd_strob(void)
{
  PIN_SET   (LCD_E);
  delay_us  (LCD_CLK_PAUSE); // 1.6ms  	
  PIN_RESET (LCD_E);
  delay_us  (LCD_CLK_PAUSE); // 1.6ms 
}

//--------------------------------------------------------------
//--------------------------------------------------------------
static void dev_write_command(uint8_t data )
{
  delay_us  (LCD_CMD_WAIT); // command and data wait  
  PIN_RESET (LCD_RS);       // RS=Lo (Command)
  PIN_RESET (LCD_RW);
  
  if((data&0x80)!=0) PIN_SET(LCD_D7); else PIN_RESET(LCD_D7);
  if((data&0x40)!=0) PIN_SET(LCD_D6); else PIN_RESET(LCD_D6);
  if((data&0x20)!=0) PIN_SET(LCD_D5); else PIN_RESET(LCD_D5);
  if((data&0x10)!=0) PIN_SET(LCD_D4); else PIN_RESET(LCD_D4);
  dev_lcd_strob();
  if((data&0x08)!=0) PIN_SET(LCD_D7); else PIN_RESET(LCD_D7);
  if((data&0x04)!=0) PIN_SET(LCD_D6); else PIN_RESET(LCD_D6);
  if((data&0x02)!=0) PIN_SET(LCD_D5); else PIN_RESET(LCD_D5);
  if((data&0x01)!=0) PIN_SET(LCD_D4); else PIN_RESET(LCD_D4);
  dev_lcd_strob();
}


//--------------------------------------------------------------
//--------------------------------------------------------------
static void dev_write_data(uint8_t data)
{
  delay_us  (LCD_CMD_WAIT); // command and data wait  
  PIN_SET   (LCD_RS);      //   RS=Hi (Data)
  PIN_RESET (LCD_RW);
  
  if((data&0x80)!=0) PIN_SET(LCD_D7); else PIN_RESET(LCD_D7);
  if((data&0x40)!=0) PIN_SET(LCD_D6); else PIN_RESET(LCD_D6);
  if((data&0x20)!=0) PIN_SET(LCD_D5); else PIN_RESET(LCD_D5);
  if((data&0x10)!=0) PIN_SET(LCD_D4); else PIN_RESET(LCD_D4);
  dev_lcd_strob();

  if((data&0x08)!=0) PIN_SET(LCD_D7); else PIN_RESET(LCD_D7);
  if((data&0x04)!=0) PIN_SET(LCD_D6); else PIN_RESET(LCD_D6);
  if((data&0x02)!=0) PIN_SET(LCD_D5); else PIN_RESET(LCD_D5);
  if((data&0x01)!=0) PIN_SET(LCD_D4); else PIN_RESET(LCD_D4);
  dev_lcd_strob();
}


//--------------------------------------------------------------
// interne Funktion
//--------------------------------------------------------------
void dev_set_cursor(uint8_t x, uint8_t y)
{
  uint8_t data;

  if (x >= LCD_MAXX) x = 0;
  if (y >= LCD_MAXY) y = 0;

  data  = (y<<6);
  data |= x;
  data |= 0x80;
  dev_write_command( data );
}
