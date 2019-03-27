/*********************************  *************************************
* All rights reserved.
*******************************************************************************/
#include "TFTLCD_Init.h"


u8                                lcd_id[12];
#define LCD_ILI9341_CMD           LCD_WR_REG
#define LCD_ILI9341_Parameter     LCD_WR_DATA
#define delayms                   delay_ms

/*************************************
 *
**************************************/
void LCD_Init(void) {
   LCD_RESET(); //
   LCD_Set();   //
   ILI9341_HSD32_Initial();
}

/*************************************
 *
**************************************/
void ILI9341_HSD32_Initial(void) {
   LCD_ILI9341_CMD(0xcf);
   LCD_ILI9341_Parameter(0x00);
   LCD_ILI9341_Parameter(0xC1); //0x99
   LCD_ILI9341_Parameter(0x30);
   LCD_ILI9341_CMD(0xed);
   LCD_ILI9341_Parameter(0x64);
   LCD_ILI9341_Parameter(0x03);
   LCD_ILI9341_Parameter(0x12);
   LCD_ILI9341_Parameter(0x81);
   LCD_ILI9341_CMD(0xe8);
   LCD_ILI9341_Parameter(0x85);
   LCD_ILI9341_Parameter(0x00);
   LCD_ILI9341_Parameter(0x78);
   LCD_ILI9341_CMD(0xcb);
   LCD_ILI9341_Parameter(0x39);
   LCD_ILI9341_Parameter(0x2c);
   LCD_ILI9341_Parameter(0x00);
   LCD_ILI9341_Parameter(0x34);
   LCD_ILI9341_Parameter(0x02);
   LCD_ILI9341_CMD(0xF7);
   LCD_ILI9341_Parameter(0x20);
   LCD_ILI9341_CMD(0xea);
   LCD_ILI9341_Parameter(0x00);
   LCD_ILI9341_Parameter(0x00);

   LCD_ILI9341_CMD(0xC0); //Power control
   LCD_ILI9341_Parameter(0x23); //VRH[5:0]  23 20171122

   LCD_ILI9341_CMD(0xC1); //Power control
   LCD_ILI9341_Parameter(0x12); //SAP[2:0];BT[3:0]

   LCD_ILI9341_CMD(0xC2);
   LCD_ILI9341_Parameter(0x11);

   LCD_ILI9341_CMD(0xC5); //VCM control
   LCD_ILI9341_Parameter(0x40);
   LCD_ILI9341_Parameter(0x30); //调对比度，调大变浅，调小变深

   LCD_ILI9341_CMD(0xC7);
   LCD_ILI9341_Parameter(0xA8); //调水波纹,VCOML调小时，C7要调大  B6  A5

   LCD_ILI9341_CMD(0xB1); // Frame Rate Control
   LCD_ILI9341_Parameter(0x00);
   LCD_ILI9341_Parameter(0x18); //18

   LCD_ILI9341_CMD(0x3A);
   LCD_ILI9341_Parameter(0x55);

   LCD_ILI9341_CMD(0x36); // Memory Access Control
   LCD_ILI9341_Parameter(0x08); //48

   LCD_ILI9341_CMD(0xB6); // Display Function Control
   LCD_ILI9341_Parameter(0x0a);
   LCD_ILI9341_Parameter(0xa2);

   LCD_ILI9341_CMD(0xF6); //20171122
   LCD_ILI9341_Parameter(0x01);
   LCD_ILI9341_Parameter(0x30);

   LCD_ILI9341_CMD(0xF2); // 3Gamma Function Disable
   LCD_ILI9341_Parameter(0x00);

   LCD_ILI9341_CMD(0xF7); //Pump ratio control (F7h)
   LCD_ILI9341_Parameter(0x20);

   LCD_ILI9341_CMD(0x26); //Gamma curve selected
   LCD_ILI9341_Parameter(0x01);

   LCD_ILI9341_CMD(0xE0); //Set Gamma
   LCD_ILI9341_Parameter(0x1f);
   LCD_ILI9341_Parameter(0x24);
   LCD_ILI9341_Parameter(0x23);
   LCD_ILI9341_Parameter(0x0b);
   LCD_ILI9341_Parameter(0x0f);
   LCD_ILI9341_Parameter(0x08);
   LCD_ILI9341_Parameter(0x50);
   LCD_ILI9341_Parameter(0xd8);
   LCD_ILI9341_Parameter(0x3b);
   LCD_ILI9341_Parameter(0x08);
   LCD_ILI9341_Parameter(0x0a);
   LCD_ILI9341_Parameter(0x00);
   LCD_ILI9341_Parameter(0x00);
   LCD_ILI9341_Parameter(0x00);
   LCD_ILI9341_Parameter(0x00);

   LCD_ILI9341_CMD(0XE1); //Set Gamma
   LCD_ILI9341_Parameter(0x00);
   LCD_ILI9341_Parameter(0x1b);
   LCD_ILI9341_Parameter(0x1c);
   LCD_ILI9341_Parameter(0x04);
   LCD_ILI9341_Parameter(0x10);
   LCD_ILI9341_Parameter(0x07);
   LCD_ILI9341_Parameter(0x2f);
   LCD_ILI9341_Parameter(0x27);
   LCD_ILI9341_Parameter(0x44);
   LCD_ILI9341_Parameter(0x07);
   LCD_ILI9341_Parameter(0x15);
   LCD_ILI9341_Parameter(0x0f);
   LCD_ILI9341_Parameter(0x3f);
   LCD_ILI9341_Parameter(0x3f);
   LCD_ILI9341_Parameter(0x1F);

   LCD_ILI9341_CMD(0x11); //Exit Sleep
   delay_ms(60);
   LCD_ILI9341_CMD(0x29); //display on
}

/**********************************************
 * 
***********************************************/
void LCD_Set(void) {
   lcddev.dir = 0;         //竖屏
   lcddev.width = 240;     //LCD 宽度
   lcddev.height = 320;    //LCD 高度
   lcddev.setxcmd = 0X2A;  //设置x坐标指令
   lcddev.setycmd = 0X2B;  //设置y坐标指令
   lcddev.wramcmd = 0X2C;  //开始写gram指令
}

/**********************************************
 * 
***********************************************/
void BlockWrite(unsigned int Xstart, unsigned int Xend, unsigned int Ystart, unsigned int Yend)
{    //9163,9340,9341,7735,7789,8357D,9327,9488.HX8357C//OK
   LCD_WR_8REG(0x2a);
   LCD_WR_8DATA(Xstart >> 8);
   LCD_WR_8DATA(Xstart & 0xff);
   LCD_WR_8DATA(Xend >> 8);
   LCD_WR_8DATA(Xend & 0xff);

   LCD_WR_8REG(0x2b);
   LCD_WR_8DATA(Ystart >> 8);
   LCD_WR_8DATA(Ystart & 0xff);
   LCD_WR_8DATA(Yend >> 8);
   LCD_WR_8DATA(Yend & 0xff);

   LCD_WR_8REG(0x2C);

}

/*******************************************************************************
 * 
******************************************************************************/
void LCD_SetCursor(u16 Xpos, u16 Ypos) {
   LCD_WR_8REG(lcddev.setxcmd);
   LCD_WR_8DATA(Xpos >> 8); LCD_WR_8DATA(Xpos & 0XFF);
   LCD_WR_8REG(lcddev.setycmd);
   LCD_WR_8DATA(Ypos >> 8); LCD_WR_8DATA(Ypos & 0XFF); 
   LCD_WR_8REG(0x2C);
}

void TFT_Scan_Dir(u8 dir)	{
   switch (dir) {
   case 0: //  屏ＩＣ在下方　　　默认模式
      LCD_WriteReg(0x36, 0x08); //08
      break;
   case 1: //　屏ＩＣ在左方　
      LCD_WriteReg(0x36, 0x08);
      break;
   case 2: //	屏ＩＣ在上方
      LCD_WriteReg(0x36, 0x08);
      break;
   case 3: //	屏ＩＣ在右方
      LCD_WriteReg(0x36, 0x08);
      break;
   }
}

/**********************************************
 * 
**********************************************/
void LCD_ReadID(void) {
   unsigned char i;

   LCD_RESET(); 
   LCD_WR_REG(0XD3);
   lcddev.id = LCD_RD_DATA();    //dummy read
   lcddev.id = LCD_RD_DATA();    //00
   lcddev.id = LCD_RD_DATA();    //93
   lcddev.id <<= 8;
   lcddev.id |= LCD_RD_DATA();   //41
   sprintf((char *)lcd_id, "LCD ID:%04X", lcddev.id);
}

/*******************************************************************************
* Function Name  : LCD_WriteRAM_Prepare  
*******************************************************************************/
void TFT_WriteRAM(void) {
   LCD_WR_REG(0X2C);
}

void LCD_DisplayOn(void) {
   LCD_WR_8REG(0X29);
}

void LCD_DisplayOff(void) {
   LCD_WR_8REG(0X28);
}


