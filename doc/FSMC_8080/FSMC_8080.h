/*********************************  *************************************
* Copyright (c) 2017 ����Һ����ʾ��
* All rights reserved.
*
* �ļ���   ��__FSMC_8080_H    
* ����     ��������
*
* ��ǰ�汾 ��V1.0
* ��    �� ��CGY
* ������� ��2017-10-31
* �޸����� ����һ�汾
*	΢�źţ�wxjcgy20120815
*	E-mail : 68771083@qq.com
*	�Ա���ʾ���������� https://shop150276963.taobao.com/?spm=a313o.7775905.1998679131.d0011.pdIFpT           						                          	
*******************************************************************************/
#ifndef __FSMC_8080_H
#define __FSMC_8080_H		
#include "sys.h"
#include "delay.h"

/***************************************************************************************/
//LCD��Ҫ������
typedef struct  
{										    
	u16 width;			//LCD ���
	u16 height;			//LCD �߶�
	u16 id;				//LCD ID
	u8  dir;			//���������������ƣ�0��������1��������	
	u16	wramcmd;		//��ʼдgramָ��
	u16  setxcmd;		//����x����ָ��
	u16  setycmd;		//����y����ָ�� 
}_lcd_dev; 	  

//LCD����
extern _lcd_dev lcddev;	//����LCD��Ҫ����
//LCD�Ļ�����ɫ�ͱ���ɫ	   
extern u16  POINT_COLOR;//Ĭ�Ϻ�ɫ    
extern u16  BACK_COLOR; //������ɫ.Ĭ��Ϊ��ɫ

//////////////////////////////////////////////////////////////////////////////////	 
//-----------------LCD�˿ڶ���---------------- 
/***************************************************************************************/
//                     STM32F103�ڲ�FSCM����
/***************************************************************************************
STM32F1 �� FSMC �洢�� 1�� Bank1������Ϊ 4 ������ÿ�������� 64M �ֽڿռ䣬ÿ�������ж����ļĴ����������ӵĴ洢���������á�
Bank1 �� 256M �ֽڿռ��� 28 ����ַ�ߣ� HADDR[27:0]��Ѱַ������ HADDR ���ڲ� AHB ��ַ ���ߣ����� HADDR[25:0] �����ⲿ�洢����ַFSMC_A[25:0]��
�� HADDR[26:27]�� 4 ��������Ѱַ��FSMC_A[25:0]��2^26 =0X0400 0000 = 64MB,ÿ��BANK ��4*64MB = 256MB,�� HADDR[26:27]�� 4 ��������Ѱַ��������ʾ��
Bank1 ��ѡ�� Ƭѡ�ź� ��ַ��Χ [25:0]	 HADDR[27:26]
�� 1 �� FSMC_NE1 0X6000,0000~63FF,FFFF 00
�� 2 �� FSMC_NE2 0X6400,0000~67FF,FFFF 01    
�� 3 �� FSMC_NE3 0X6800,0000~6BFF,FFFF 10
�� 4 �� FSMC_NE4 0X6C00,0000~6FFF,FFFF 11

$$$LCD_CS�ӵ�PD7(FSCM_NE1)����ѡ��NORSRAM1
ѡ��BANK1-BORSRAM1 ����TFT,��ַ��Χ0X6000 0000 ~ 0X3FFF FFFF  
FSMC_A11��LCD��DC(�Ĵ�������/��ַѡ���)
16λ:A0��Ч,��ʱA1�൱������A0,ע������ʱSTM32�ڲ�������һλ����!
RS:A11  0x3FF    ������Ч��A0λ�õ�0x3FF<<1=0x7FE
�Ĵ�����ַ = 0X6000 0000
RAM����ַ =  0X6001 FFFE = 0X6000 0000+2^11��A11���Ծ���11�η���*2 = 0X6000 0000 + 0X001 FFFE = 0X6001 FFFE
��ַ�߲�ͬ��Ҫ���¼���RAM����ַ
****************************************************************************************/
//#if  MCU

//LCD��ַ�ṹ�� 16BIT
typedef struct
{
	vu16 LCD_REG;
	vu16 LCD_RAM;
} LCD_TypeDef;
//ʹ��NOR/SRAM�� Bank1.sector4,��ַλHADDR[27,26]=11 A16��Ϊ�������������� 
//ע������ʱSTM32�ڲ�������һλ����! 			    
//LCD>>16BIT FSMC   OK
#define LCD_BASE        ((u32)(0x60000000 | 0X1FFFE))
#define LCD             ((LCD_TypeDef *) LCD_BASE)

////YZ
//#define LCD_BASE        ((u32)(0x6C000000 | 0x000007FE))
//#define LCD             ((LCD_TypeDef *) LCD_BASE)

//#else


/*
//LCD��ַ�ṹ��8BIT
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
//ɨ�跽����
#define L2R_U2D  0 //������,���ϵ���
#define L2R_D2U  1 //������,���µ���
#define R2L_U2D  2 //���ҵ���,���ϵ���
#define R2L_D2U  3 //���ҵ���,���µ���

#define U2D_L2R  4 //���ϵ���,������
#define U2D_R2L  5 //���ϵ���,���ҵ���
#define D2U_L2R  6 //���µ���,������
#define D2U_R2L  7 //���µ���,���ҵ���	 

#define DFT_SCAN_DIR  L2R_U2D  //Ĭ�ϵ�ɨ�跽��

//������ɫ
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
#define BROWN 			 0XBC40 //��ɫ
#define BRRED 			 0XFC07 //�غ�ɫ
#define GRAY  			 0X8430 //��ɫ
//GUI��ɫ

#define DARKBLUE      	 0X01CF	//����ɫ
#define LIGHTBLUE      	 0X7D7C	//ǳ��ɫ  
#define GRAYBLUE       	 0X5458 //����ɫ
//������ɫΪPANEL����ɫ 
 
#define LIGHTGREEN     	 0X841F //ǳ��ɫ
//#define LIGHTGRAY        0XEF5B //ǳ��ɫ(PANNEL)
#define LGRAY 			 0XC618 //ǳ��ɫ(PANNEL),���屳��ɫ

#define LGRAYBLUE        0XA651 //ǳ����ɫ(�м����ɫ)
#define LBBLUE           0X2B12 //ǳ����ɫ(ѡ����Ŀ�ķ�ɫ)

//*******************************************************************************//
void LCD_CtrlLinesConfig(void);
void LCD_FSMCConfig(void);

void LCD_SPICtrlLinesConfig(void);

void LCD_RESET(void);  //�̣ãĽ��и�λ����

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
u16  LCD_ReadPoint(u16 x,u16 y); 	//���� 

void LCD_SSD_BackLightSet(u8 pwm);							//SSD1963 �������

void LCD_Clear(u16 Color);	//����
void LCD_Display(u16 color);
void LCD_DisplayJiuGongGe(void);
void LCD_Frame(u16 RGB_Data,u16 f_data);
void Show_Gray(void);

void LCD_Fill(u16 sx,u16 sy,u16 ex,u16 ey,u16 color);		   				//��䵥ɫ
void LCD_Color_Fill(u16 sx,u16 sy,u16 ex,u16 ey,u16 *color);				//���ָ����ɫ

void DisplayPicture(void);
void DisplayPicture1(void);

void LCD_SetCursor(u16 Xpos, u16 Ypos);										//���ù��

void LCD_DrawPoint(u16 x,u16 y);											//����
void LCD_Fast_DrawPoint(u16 x,u16 y,u16 color);								//���ٻ���
void LCD_DrawLine(u16 x1, u16 y1, u16 x2, u16 y2);							//����
void LCD_DrawRectangle(u16 x1, u16 y1, u16 x2, u16 y2);		   				//������
void LCD_Draw_Circle(u16 x0,u16 y0,u8 r);						 			//��Բ

void LCD_ShowChar(u16 x,u16 y,u8 num,u8 size,u8 mode);						//��ʾһ���ַ�
u32 LCD_Pow(u8 m,u8 n);
void LCD_ShowNum(u16 x,u16 y,u32 num,u8 len,u8 size);  						//��ʾһ������
void LCD_ShowxNum(u16 x,u16 y,u32 num,u8 len,u8 size,u8 mode);				//��ʾ ����
void LCD_ShowString(u16 x,u16 y,u16 width,u16 height,u8 size,u8 *p);		//��ʾһ���ַ���,12/16����

void SSD1963_SetRGB(void);

//LCD�ֱ�������
#define SSD_HOR_RESOLUTION		800		//LCDˮƽ�ֱ���
#define SSD_VER_RESOLUTION		480		//LCD��ֱ�ֱ���
//LCD������������
#define SSD_HOR_PULSE_WIDTH		1		//ˮƽ����
#define SSD_HOR_BACK_PORCH		210		//ˮƽǰ��
#define SSD_HOR_FRONT_PORCH		45		//ˮƽ����

#define SSD_VER_PULSE_WIDTH		1		//��ֱ����
#define SSD_VER_BACK_PORCH		34		//��ֱǰ��
#define SSD_VER_FRONT_PORCH		10		//��ֱǰ��
//���¼����������Զ�����
#define SSD_HT	(SSD_HOR_RESOLUTION+SSD_HOR_BACK_PORCH+SSD_HOR_FRONT_PORCH)
#define SSD_HPS	(SSD_HOR_BACK_PORCH)
#define SSD_VT 	(SSD_VER_RESOLUTION+SSD_VER_BACK_PORCH+SSD_VER_FRONT_PORCH)
#define SSD_VPS (SSD_VER_BACK_PORCH)


///////////SD///////////
u16 pic_get_tnum(u8 *path);
void SD_DisPic(void);




#endif  

