/************************************************************
 *  @module:   st7920.c 
 *  @author(s): tom wu
 *  @date: 2016 for mailbox detection project  
 *  @copyright urenhu coporation  
 *  
**/

#include "usr_sys.h"   
#include "usr_delay.h"   
#include "usr_spi.h"   
#include "st7920.h"   

//===============================================================================
//  #define	FRAM_CS     PBout(12)
//          FRAM_CS = 0;
//  #define AD9850_PORT  GPIOA
//  #define AD9850_WCLK  GPIO_Pin_0 
//  or use PBout(9) for direct read write    
//	GPIO_SetBits(AD9850_PORT, pin );
//===============================================================================
//  LCD           STM32
//---------------------------------------------------------------------
//  4 # CS  -<---- PB12    GPIO
//  5 # SIO -<-->- PB15    MOSI
//  6 # SCK -<---- PB13    SCK 
//                 PB14    MISO
// 17 # RST -<---- PB11    GPIO
// 
//===============================================================================    
#define LCD_CS	        PBout(12)	  
//#define LCD_SIO	      PBout(15)	  
//#define LCD_SCK	      PBout(13)	  
#define LCD_RST	        PBout(11)   
 

//************************************************************************************   
//*@brief: LCD_Write(unsigned char Data_Command , unsigned char uc_Content ) *   
//************************************************************************************   
static void LCD_Write( unsigned char command , unsigned char uc_Content )   
{    
  unsigned char temp;   

  LCD_CS = 1;	  

  if ( command && uc_Content==0x01)
		delay_us(1600); // 1.6ms 
	else 
		delay_us(72);   // 72 us
	
  if (command) {
    temp = 0xFA;    //RS = 1, data  RW = 0, write mode   
  } else {
    temp = 0xF8;    //RS = 0, command  RW = 0, write mode    
  }   
  usrspi2_SendByte3Wire  (temp); //LCD_SendByte(temp);// send SPI frame 
	
  temp = uc_Content&0xF0;   
  usrspi2_SendByte3Wire  (temp); //LCD_SendByte(temp);   
	
  temp = (uc_Content<<4)&0xF0;   
  usrspi2_SendByte3Wire  (temp); //LCD_SendByte(temp);   
	

  if ( command && uc_Content==0x01)
		delay_us(1600); // 1.6ms 
	else 
		delay_us(72);   // 72 us

	LCD_CS = 0;

  if ( command && uc_Content==0x01)
		delay_us(1600); // 1.6ms 
	else 
		delay_us(72);   // 72 us
}   

//************************************************************************************   
static unsigned char LCD_ReadRam( unsigned char addr )   
{    
  unsigned char temp;   

  LCD_CS = 1;	  
	delay_us(72);   // 72 us
  
	usrspi2_SendByte3Wire  (temp); //LCD_SendByte(temp);// send SPI frame   
  
  temp = addr&0xF0;  
  usrspi2_SendByte3Wire  (temp); //LCD_SendByte(temp);   
  
  temp = (addr<<4)&0xF0;   
  usrspi2_ReadByte3Wire  (temp); //LCD_SendByte(temp);   
  
	temp = usrspi2_ReadByte3Wire(); 
  
	delay_us(72);   // 72 us
  LCD_CS = 0;	  
	delay_us(72);   // 72 us
}   

static unsigned char LCD_ReadCurrentRam(  )   
{    
  unsigned char temp;   
  temp = 0xfe;

  LCD_CS = 1;	  
  delay_us(72);   // 72 us
  usrspi2_SendByte3Wire  (temp); //LCD_SendByte(temp);// send SPI frame   
  temp = usrspi2_ReadByte3Wire(); 
	delay_us(72);   // 72 us
  LCD_CS = 0;	  

}   

//*******************************************************************************   
//*函数名称:void LCD_GDRAM_AddressSet(unsigned char ucGDramAdd)                   *   
//*函数功能:设定GDRAM(图形区)地址到地址计数器AC                                 *   
//*形式参数:unsigned char ucGDramAdd                                                    *   
//*形参说明:具体地址值                                                          *   
//*     RS  RW  DB7 DB6 DB5 DB4 DB3 DB2 DB1 DB0                                 *   
//*     0   0   1   AC6 AC5 AC4 AC3 AC2 AC1 AC0                                 *   
//*     先设定垂直位置再设定水平位置(连续写入两个字节完成垂直和水平位置的设置)  *    
//*     垂直地址范围:AC6~AC0                                                    *   
//*     水平地址范围:AC3~AC0                                                    *   
//*返回参数:无                                                                  *   
//*使用说明:必须在扩展指令集的情况下使用                                        *   
//*******************************************************************************   
void LCD_GDRAM_AddressSet(unsigned char ucGDramAdd)   
{   
    LCD_Write(LCD_COMMAND,LCD_EXTEND_FUNCTION);         //扩展指令集   
    LCD_Write(LCD_COMMAND,ucGDramAdd);         
}   


//*******************************************   
//*函数名称:void LCD_Init(void) *   
//*******************************************   
void LCD_Init(void)   
{   
    GPIO_InitTypeDef     GPIO_InitStructure;
    RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB, ENABLE );

    GPIO_InitStructure.GPIO_Pin    = GPIO_Pin_12;       // PB12 ==> CS 
    GPIO_InitStructure.GPIO_Mode   = GPIO_Mode_Out_PP;  // DO 
    GPIO_InitStructure.GPIO_Speed  = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    GPIO_ResetBits(GPIOB,GPIO_Pin_12);

    GPIO_InitStructure.GPIO_Pin    = GPIO_Pin_11;       // PB11 ==> RST 
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    GPIO_SetBits(GPIOB,GPIO_Pin_11);

    usrspi2_init(1, 0, 0); // three wire, MSB first, mode = 0       
    usrspi2_setspeed(SPI_BaudRatePrescaler_256);  // SPI_BaudRatePrescaler_2); clk PW=0.025us = 28 ns
                                                  // 256 clk PW = 4us; 128 = 1.8us ( confirmed!!)
    LCD_RST = 0;    
    delay_ms(100);   
    LCD_RST = 1; // 复位后拉高，停止复位   
    delay_ms(1);   
	  
		LCD_Write(LCD_COMMAND,LCD_BASIC_FUNCTION);       
    LCD_Write(LCD_COMMAND,LCD_CLEAR_SCREEN);    //clear AC <= 00H   
    LCD_Write(LCD_COMMAND,0x06);                // entry mode: increase !  
    LCD_Write(LCD_COMMAND,0x0C);                // display on   
    LCD_Write(LCD_COMMAND,0x80);                // set ddram address <= 0 

		LCD_GraphModeSet(1);	
		
}   

//********************************************************   
//*函数名称:void LCD_ClearRam(void)              *   
//********************************************************   
void LCD_ClearRam(void)   
{   
    LCD_Write(LCD_COMMAND,LCD_BASIC_FUNCTION);          //基本指令集   
    LCD_Write(LCD_COMMAND,LCD_CLEAR_SCREEN);            //清屏   
}   


//*****************************************************   
//*函数名称:void LCD_GraphModeSet(unsigned char bSelect) *   
//*函数功能:打开或关闭绘图显示                         *   
//*形式参数:unsigned char Select                      *   
//*形参说明:打开或关闭绘图显示的标志位,1打开,0关闭     *   
//*格式说明:                                          *   
//*     RS  RW  DB7 DB6 DB5 DB4 DB3 DB2 DB1 DB0       *   
//*     0   0   0   0   1   1   X   RE   G   X        *   
//*                                                   *   
//*     RE:0,基本指令集                                *   
//*     RE:1,扩充指令集                                *   
//*     G :0,绘图显示OFF                              *   
//*     G :1,绘图显示ON                               *   
//*返回参数:无                                         *   
//*使用说明:无                                         *   
//*****************************************************   
void LCD_GraphModeSet(unsigned char Select)   
{   
    LCD_Write(LCD_COMMAND,LCD_EXTEND_FUNCTION); //扩展指令集   
    if (Select) {
        LCD_Write(LCD_COMMAND,LCD_GRAPH_ON);        //打开绘图模式   
    } else {
        LCD_Write(LCD_COMMAND,LCD_GRAPH_OFF);       //关闭绘图模式       
    }   
}   


//*********************************************************************   
//*函数名称:void LCD_ImgDisplay(unsigned char code *img)         *   
//*函数功能:全屏显示128*64个象素的图形                                *   
//*形式参数:unsigned char code *img                                   *   
//*形参说明:要显示的图形                                              *   
//*液晶屏坐标说明:                                                    *   
//*      ________________128个像素______________________              *   
//*      |(0,0)                                    (7,0)|             *   
//*      |                                              |             *   
//*   64 |                                              |             *   
//*   个 |(0,31)                                  (7,31)|             *   
//*   像 |(8,0)                                   (15,0)|             *   
//*   素 |                                              |             *   
//*      |                                              |             *   
//*      |(8,31)                                 (15,31)|             *   
//*      |______________________________________________|             *   
//*                                                                   *   
//返回参数:无                                                         *   
//使用说明:此函数适用于CM12864-12型液晶                               *   
//*********************************************************************   
void LCD_ImgDisplay(unsigned char *img)   
{   
    unsigned char i,j;   

    LCD_GraphModeSet(0x00); //先关闭图形显示功能   
    for (j=0;j<32;j++) {
        for (i=0;i<8;i++) {
            LCD_Write(LCD_COMMAND,0x80+j);      //设定垂直坐标   
            LCD_Write(LCD_COMMAND,0x80+i);      //设定水平坐标   
            LCD_Write(LCD_DATA,img[j*16+i*2]);  //放入数据高字节   
            LCD_Write(LCD_DATA,img[j*16+i*2+1]);    //放入数据低字节   
        }   
    }   
    for (j=32;j<64;j++) {
        for (i=0;i<8;i++) {
            LCD_Write(LCD_COMMAND,0x80+j-32);   
            LCD_Write(LCD_COMMAND,0x88+i);   
            LCD_Write(LCD_DATA,img[j*16+i*2]);   
            LCD_Write(LCD_DATA,img[j*16+i*2+1]);   
        }   
    }   
    LCD_GraphModeSet(0x01);//最后打开图形显示功能   
}   

void LCD_DisplayCLR()   
{   
    unsigned char i,j;   
    LCD_GraphModeSet(0x00); //先关闭图形显示功能   
    for (j=0;j<32;j++) {
        for (i=0;i<8;i++) {
            LCD_Write(LCD_COMMAND,0x80+j);      //设定垂直坐标   
            LCD_Write(LCD_COMMAND,0x80+i);      //设定水平坐标   
            LCD_Write(LCD_DATA,0x00);   //放入数据高字节   
            LCD_Write(LCD_DATA,0x00);   //放入数据低字节   
        }   
    }   
    for (j=32;j<64;j++) {
        for (i=0;i<8;i++) {
            LCD_Write(LCD_COMMAND,0x80+j-32);   
            LCD_Write(LCD_COMMAND,0x88+i);   
            LCD_Write(LCD_DATA,0x00);   
            LCD_Write(LCD_DATA,0x00);   
        }   
    }   
    LCD_GraphModeSet(0x01);//最后打开图形显示功能   
}   


//******************************************************************************   
//*函数名称:void LCD_ImgDisplayCharacter(unsigned char x,unsigned char y,unsigned char code *img) *   
//*函数功能:使用绘图的方法,在(x,y)处画一个16*16点阵的图案,也可以是字符        *   
//*形式参数:unsigned char x,unsigned char y,unsigned char code *img                                    *   
//*         x取值范围:0~7                                                      *   
//*         y取值范围:0~31 (针对CM12864-12型液晶)                               *   
//*形参说明:坐标水平位置,坐标垂直位置,要显示的图形                               *   
//*液晶屏坐标说明:                                                            *   
//*      ________________128个像素______________________              *   
//*      |(0,0)                                    (7,0)|             *   
//*      |                                              |             *   
//*   64 |                                              |             *   
//*   个 |(0,31)                                  (7,31)|             *   
//*   像 |(8,0)                                   (15,0)|             *   
//*   素 |                                              |             *   
//*      |                                              |             *   
//*      |(8,31)                                 (15,31)|             *   
//*      |______________________________________________|             *   
//*                                                                   *   
//*返回参数:无                                                              *   
//*使用说明:此函数适用于CM12864-12型液晶         *   
//******************************************************************************   
void LCD_ImgDisplayCharacter(unsigned char x,unsigned char y,unsigned char *img)   
{   
    unsigned char i;   
    LCD_GraphModeSet(0x00);     //先关闭图形显示功能   
    LCD_Write(LCD_COMMAND,LCD_EXTEND_FUNCTION);   
    for (i=0;i<16;i++) {
        LCD_GDRAM_AddressSet(0x80+y+i);   
        LCD_GDRAM_AddressSet(0x80+x);   
        LCD_Write(LCD_DATA,img[i*2]);   
        LCD_Write(LCD_DATA,img[i*2+1]);   
    }   
    LCD_GraphModeSet(0x01);              //最后打开图形显示功能   
}   



//******************************************************************************   
//*函数名称:void LCD_Point(unsigned char x,unsigned char y,unsigned char color)*   
//*函数功能:使用绘图的方法,在(x,y)处画一个16*16点阵的图案,也可以是字符        *   
//*形式参数:unsigned char x,unsigned char y,unsigned char color                *   
//*         x取值范围:0~127                                                    *   
//*         y取值范围:0~63 (针对CM12864-12型液晶)                               *   
//*形参说明:坐标水平位置,坐标垂直位置                                          *   
//*液晶屏坐标说明:                                                            *   
//*      ________________128个像素______________________              *   
//*      |(0,0)                                    (7,0)|             *   
//*      |                                              |             *   
//*   64 |                                              |             *   
//*   个 |(0,31)                                  (7,31)|             *   
//*   像 |(8,0)                                   (15,0)|             *   
//*   素 |                                              |             *   
//*      |                                              |             *   
//*      |(8,31)                                 (15,31)|             *   
//*      |______________________________________________|             *   
//*                                                                   *   
//*返回参数:无                                                              *   
//*使用说明:此函数适用于CM12864-12型液晶         *   
//******************************************************************************   
void LCD_Point(unsigned char x,unsigned char y,unsigned char color)   
{   
    unsigned char i,AddrX,AddrY;    //寄存器地址   
    unsigned char BitTemp;      //该点在16bit的位置   
    unsigned char DataH,DataL;   

    AddrX = x>>4;             // x/16   
    AddrY = y&0x3F;             // y%64   
    if (y > 31) {
        AddrX += 8;   
        AddrY -= 32;   
    }
    BitTemp = x&0x0F;           // x%16   

    LCD_GraphModeSet(0x00);   
    for (i=0;i<4;i++) {
        LCD_GDRAM_AddressSet(0x80+AddrY);   
        LCD_GDRAM_AddressSet(0x80+AddrX);   
        DataH = LCD_ReadCurrentRam();   
        DataH = LCD_ReadCurrentRam();   
        DataL = LCD_ReadCurrentRam();   
    }   

    if (color == LCD_COLOR_BLACK) {
        if (BitTemp > 7) {
            DataL |= (0x80>>(BitTemp-8));   
        } else {
            DataH |= (0x80>>(BitTemp));   
        }   
    }
    
    LCD_GDRAM_AddressSet(0x80+AddrY);   
    LCD_GDRAM_AddressSet(0x80+AddrX);   
    LCD_Write(LCD_DATA,DataH);   
    LCD_Write(LCD_DATA,DataL);   

    LCD_GraphModeSet(0x01); 
    // 
}   

void LCD_DisplayString(int X, int Y,char *ptrt, int len)
{
  int i;

  switch(X){
     case 0:  Y|=0x80;break;
     case 1:  Y|=0x90;break;
     case 2:  Y|=0x88;break;
     case 3:  Y|=0x98;break;
     default: break;
  }

  LCD_Write(LCD_COMMAND, Y); // set start address of string in text mode 
  for(i=0; i<len; i++){ 
    	LCD_Write(LCD_DATA, ptrt[i]); //
  }
}
