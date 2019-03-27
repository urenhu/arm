/*********************************  *************************************
* Copyright (c) 2017 金鑫液晶显示屏
* All rights reserved.
*
* 文件名   ：__FSMC_8080_H    
* 描述     ：主函数
*
* 當前版本 ：V1.0
* 作    者 ：CGY
* 完成日期 ：2017-10-31
* 修改描述 ：第一版本
*	微信号：wxjcgy20120815
*	E-mail : 68771083@qq.com
*	淘宝显示屏范例屏： https://shop150276963.taobao.com/?spm=a313o.7775905.1998679131.d0011.pdIFpT           						                          	
*******************************************************************************/
#ifndef __FSMC_8080_H
#define __FSMC_8080_H		
#include "sys.h"
#include "delay.h"

/***************************************************************************************/
//LCD重要参数集
typedef struct  
{										    
	u16 width;			//LCD 宽度
	u16 height;			//LCD 高度
	u16 id;				//LCD ID
	u8  dir;			//横屏还是竖屏控制：0，竖屏；1，横屏。	
	u16	wramcmd;		//开始写gram指令
	u16  setxcmd;		//设置x坐标指令
	u16  setycmd;		//设置y坐标指令 
}_lcd_dev; 	  

//LCD参数
extern _lcd_dev lcddev;	//管理LCD重要参数
//LCD的画笔颜色和背景色	   
extern u16  POINT_COLOR;//默认红色    
extern u16  BACK_COLOR; //背景颜色.默认为白色

//////////////////////////////////////////////////////////////////////////////////	 
//-----------------LCD端口定义---------------- 
/***************************************************************************************/
//                     STM32F103内部FSCM介绍
/***************************************************************************************
STM32F1 的 FSMC 存储块 1（ Bank1）被分为 4 个区，每个区管理 64M 字节空间，每个区都有独立的寄存器对所连接的存储器进行配置。
Bank1 的 256M 字节空间由 28 根地址线（ HADDR[27:0]）寻址。这里 HADDR 是内部 AHB 地址 总线，其中 HADDR[25:0] 来自外部存储器地址FSMC_A[25:0]，
而 HADDR[26:27]对 4 个区进行寻址。FSMC_A[25:0]，2^26 =0X0400 0000 = 64MB,每个BANK 有4*64MB = 256MB,而 HADDR[26:27]对 4 个区进行寻址。如下所示：
Bank1 所选区 片选信号 地址范围 [25:0]	 HADDR[27:26]
第 1 区 FSMC_NE1 0X6000,0000~63FF,FFFF 00
第 2 区 FSMC_NE2 0X6400,0000~67FF,FFFF 01    
第 3 区 FSMC_NE3 0X6800,0000~6BFF,FFFF 10
第 4 区 FSMC_NE4 0X6C00,0000~6FFF,FFFF 11

$$$LCD_CS接的PD7(FSCM_NE1)所以选的NORSRAM1
选择BANK1-BORSRAM1 连接TFT,地址范围0X6000 0000 ~ 0X3FFF FFFF  
FSMC_A11接LCD的DC(寄存器数据/地址选择脚)
16位:A0无效,此时A1相当于真正A0,注意设置时STM32内部会右移一位对其!
RS:A11  0x3FF    加上无效的A0位得到0x3FF<<1=0x7FE
寄存器地址 = 0X6000 0000
RAM基地址 =  0X6001 FFFE = 0X6000 0000+2^11（A11所以就是11次方）*2 = 0X6000 0000 + 0X001 FFFE = 0X6001 FFFE
地址线不同，要重新计算RAM基地址
****************************************************************************************/
//#if  MCU

//LCD地址结构体 16BIT
typedef struct
{
	vu16 LCD_REG;
	vu16 LCD_RAM;
} LCD_TypeDef;
//使用NOR/SRAM的 Bank1.sector4,地址位HADDR[27,26]=11 A16作为数据命令区分线 
//注意设置时STM32内部会右移一位对其! 			    
//LCD>>16BIT FSMC   OK
#define LCD_BASE        ((u32)(0x60000000 | 0X1FFFE))
#define LCD             ((LCD_TypeDef *) LCD_BASE)

////YZ
//#define LCD_BASE        ((u32)(0x6C000000 | 0x000007FE))
//#define LCD             ((LCD_TypeDef *) LCD_BASE)

//#else


/*
//LCD地址结构体8BIT
typedef struct
{
	u8 LCD_REG;
	u8 LCD_RAM;
} LCD_TypeDef;

//LCD>>8BIT FSMC  OK
#define LCD_BASE        ((u32)(0x60000000 | 0X0FFFF))
#define LCD             ((LCD_TypeDef *) LCD_BASE)
*/
//#endif
	
////////////////////////////

////////////////////////////////////////////////////////////////////////////////////						
//扫描方向定义
#define L2R_U2D  0 //从左到右,从上到下
#define L2R_D2U  1 //从左到右,从下到上
#define R2L_U2D  2 //从右到左,从上到下
#define R2L_D2U  3 //从右到左,从下到上

#define U2D_L2R  4 //从上到下,从左到右
#define U2D_R2L  5 //从上到下,从右到左
#define D2U_L2R  6 //从下到上,从左到右
#define D2U_R2L  7 //从下到上,从右到左	 

#define DFT_SCAN_DIR  L2R_U2D  //默认的扫描方向

//画笔颜色
#define WHITE         	 0xFFFF
#define BLACK         	 0x0000	  
#define BLUE         	 0x001F  
#define BRED             0XF81F
#define GRED 			 0XFFE0
#define GBLUE			 0X07FF
#define RED           	 0xF800
#define MAGENTA       	 0xF81F
#define GREEN         	 0x07E0
#define CYAN          	 0x7FFF
#define YELLOW        	 0xFFE0
#define BROWN 			 0XBC40 //棕色
#define BRRED 			 0XFC07 //棕红色
#define GRAY  			 0X8430 //灰色
//GUI颜色

#define DARKBLUE      	 0X01CF	//深蓝色
#define LIGHTBLUE      	 0X7D7C	//浅蓝色  
#define GRAYBLUE       	 0X5458 //灰蓝色
//以上三色为PANEL的颜色 
 
#define LIGHTGREEN     	 0X841F //浅绿色
//#define LIGHTGRAY        0XEF5B //浅灰色(PANNEL)
#define LGRAY 			 0XC618 //浅灰色(PANNEL),窗体背景色

#define LGRAYBLUE        0XA651 //浅灰蓝色(中间层颜色)
#define LBBLUE           0X2B12 //浅棕蓝色(选择条目的反色)

//*******************************************************************************//
void LCD_CtrlLinesConfig(void);
void LCD_FSMCConfig(void);

void LCD_SPICtrlLinesConfig(void);

void LCD_RESET(void);  //ＬＣＤ进行复位操作

void LCD_WriteByteSPI(unsigned char byte);
void SPI4W_WriteRegIndex(u16 Index);
void SPI4W_WriteData(u16 dat);

void SPI4W_WriteDisplayData(u16 dat);
void SPI3W_WriteDisplayData(u16 dat);

void SPI3W_WriteRegIndex(u8 Index);
void SPI3W_WriteData(u8 dat);

void LCD_WR_REG(u16 regval); //16BIT REG
void LCD_WR_8REG(u16 regval);//8BIT REG
void LCD_WR_DATA(u16 data);
void LCD_WR_8DATA(u16 data);

void LCD_WriteReg(u16 LCD_Reg, u16 LCD_RegValue);

u16 LCD_RD_DATA(void);

u16 LCD_SPI_RD_DATA(void);
	
u16 LCD_ReadReg(u16 LCD_Reg);
void LCD_WriteRAM_Prepare(void);
void LCD_WriteRAM(u16 RGB_Code);
u16 LCD_BGR2RGB(u16 c);
void opt_delay(u8 i);
u16  LCD_ReadPoint(u16 x,u16 y); 	//读点 

void LCD_SSD_BackLightSet(u8 pwm);							//SSD1963 背光控制

void LCD_Clear(u16 Color);	//清屏
void LCD_Display(u16 color);
void LCD_DisplayJiuGongGe(void);
void LCD_Frame(u16 RGB_Data,u16 f_data);
void Show_Gray(void);

void LCD_Fill(u16 sx,u16 sy,u16 ex,u16 ey,u16 color);		   				//填充单色
void LCD_Color_Fill(u16 sx,u16 sy,u16 ex,u16 ey,u16 *color);				//填充指定颜色

void DisplayPicture(void);
void DisplayPicture1(void);

void LCD_SetCursor(u16 Xpos, u16 Ypos);										//设置光标

void LCD_DrawPoint(u16 x,u16 y);											//画点
void LCD_Fast_DrawPoint(u16 x,u16 y,u16 color);								//快速画点
void LCD_DrawLine(u16 x1, u16 y1, u16 x2, u16 y2);							//画线
void LCD_DrawRectangle(u16 x1, u16 y1, u16 x2, u16 y2);		   				//画矩形
void LCD_Draw_Circle(u16 x0,u16 y0,u8 r);						 			//画圆

void LCD_ShowChar(u16 x,u16 y,u8 num,u8 size,u8 mode);						//显示一个字符
u32 LCD_Pow(u8 m,u8 n);
void LCD_ShowNum(u16 x,u16 y,u32 num,u8 len,u8 size);  						//显示一个数字
void LCD_ShowxNum(u16 x,u16 y,u32 num,u8 len,u8 size,u8 mode);				//显示 数字
void LCD_ShowString(u16 x,u16 y,u16 width,u16 height,u8 size,u8 *p);		//显示一个字符串,12/16字体

void SSD1963_SetRGB(void);

//LCD分辨率设置
#define SSD_HOR_RESOLUTION		800		//LCD水平分辨率
#define SSD_VER_RESOLUTION		480		//LCD垂直分辨率
//LCD驱动参数设置
#define SSD_HOR_PULSE_WIDTH		1		//水平脉宽
#define SSD_HOR_BACK_PORCH		210		//水平前廊
#define SSD_HOR_FRONT_PORCH		45		//水平后廊

#define SSD_VER_PULSE_WIDTH		1		//垂直脉宽
#define SSD_VER_BACK_PORCH		34		//垂直前廊
#define SSD_VER_FRONT_PORCH		10		//垂直前廊
//如下几个参数，自动计算
#define SSD_HT	(SSD_HOR_RESOLUTION+SSD_HOR_BACK_PORCH+SSD_HOR_FRONT_PORCH)
#define SSD_HPS	(SSD_HOR_BACK_PORCH)
#define SSD_VT 	(SSD_VER_RESOLUTION+SSD_VER_BACK_PORCH+SSD_VER_FRONT_PORCH)
#define SSD_VPS (SSD_VER_BACK_PORCH)


///////////SD///////////
u16 pic_get_tnum(u8 *path);
void SD_DisPic(void);




#endif  

