/*********************************  *************************************
*******************************************************************************/
#include "stdlib.h"
#include "font.h"
#include "TFTLCD_Init.h"
#include "string.h"		
#include "math.h"
#include "FSMC_8080.h"

u16          POINT_COLOR   = 0x0000;	
u16          BACK_COLOR    = 0xFFFF;    
_lcd_dev     lcddev;
#define      MCU                   1

/*******************************************************************************
* Function Name  : LCD_CtrlLinesConfig
* Description    : Configures LCD Control lines (FSMC Pins) in alternate function
                   Push-Pull mode.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void LCD_CtrlLinesConfig(void)
{
 	GPIO_InitTypeDef	GPIO_InitStructure;	
	
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD | RCC_APB2Periph_GPIOB |RCC_APB2Periph_GPIOE , ENABLE); 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13 ;            //LCD reset
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(GPIOD, &GPIO_InitStructure); 
	
//	FSMC-D0--D15: 
//	D0   D1   D2   D3   D4   D5   D6   D7   D8   D9   D10   D11   D12   D13  D14   D15       
//  PD14 PD15  PD0  PD1  PE7  PE8  PE9 PE10 PE11 PE12  PE13  PE14  PE15  PD8  PD9   PD10 
//  FSMC_CMD:
//  FSMC_NOE      FSMC_NWE       FSMC_NE1     FSMC_A16
//  LCD_RD        LCD_WR         LCD_CS       LCD_RS  
//	 PD4            PD5           PD7         PD11	
	GPIO_InitStructure.GPIO_Pin= GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_7|GPIO_Pin_11|      // LCD_RD,LCD_WR,LCD_CS,LCD_RS
								 GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_8|GPIO_Pin_9|
								 GPIO_Pin_10|GPIO_Pin_14|GPIO_Pin_15; 	            // FSMC_D0-D3,FSMC_D13-D15
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  
 	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOD, &GPIO_InitStructure);
 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10|
								  GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15; //PORTE, FSMC_D4-D12
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; 
 	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 	GPIO_Init(GPIOE, &GPIO_InitStructure);   
}

	
/*******************************************************************************
* Function Name  : LCD_FSMCConfig
* Description    : Configures the Parallel interface (FSMC) for LCD(Parallel mode)
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void LCD_FSMCConfig(void)
{
	FSMC_NORSRAMInitTypeDef  FSMC_NORSRAMInitStructure;
	FSMC_NORSRAMTimingInitTypeDef  readWriteTiming; 
	FSMC_NORSRAMTimingInitTypeDef  writeTiming;
	
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_FSMC,ENABLE);	// FSMC enable , setup clock
	readWriteTiming.FSMC_AddressSetupTime = 0x01;	    // ��ַ����ʱ�䣨ADDSET��Ϊ2��HCLK 1/36M=27ns
	readWriteTiming.FSMC_AddressHoldTime = 0x00;	    // ��ַ����ʱ�䣨ADDHLD��ģʽAδ�õ�	
	readWriteTiming.FSMC_DataSetupTime = 0x0f;		    // ���ݱ���ʱ��Ϊ16��HCLK,��ΪҺ������IC�Ķ����ݵ�ʱ���ٶȲ���̫�죬�����1289���IC��
	readWriteTiming.FSMC_BusTurnAroundDuration = 0x00;
	readWriteTiming.FSMC_CLKDivision = 0x00;
	readWriteTiming.FSMC_DataLatency = 0x00;
	readWriteTiming.FSMC_AccessMode = FSMC_AccessMode_A;	 // mode A 
		

	writeTiming.FSMC_AddressSetupTime = 0x00;	 // ��ַ����ʱ�䣨ADDSET��Ϊ1��HCLK  
	writeTiming.FSMC_AddressHoldTime = 0x00;	 // ��ַ����ʱ�䣨A		
	writeTiming.FSMC_DataSetupTime = 0x03;		 // ���ݱ���ʱ��Ϊ4��HCLK	
	writeTiming.FSMC_BusTurnAroundDuration = 0x00;
	writeTiming.FSMC_CLKDivision = 0x00;
	writeTiming.FSMC_DataLatency = 0x00;
	writeTiming.FSMC_AccessMode = FSMC_AccessMode_A;	 // mode A 

	FSMC_NORSRAMInitStructure.FSMC_Bank = FSMC_Bank1_NORSRAM1;                    // FSMC_Bank1_NORSRAM4;//  ����ʹ��NE1 ��Ҳ�Ͷ�ӦBTCR[6],[7]��
	FSMC_NORSRAMInitStructure.FSMC_DataAddressMux = FSMC_DataAddressMux_Disable;  // ���������ݵ�ַ
	FSMC_NORSRAMInitStructure.FSMC_MemoryType =FSMC_MemoryType_SRAM;              // FSMC_MemoryType_SRAM;  //SRAM 
	
	FSMC_NORSRAMInitStructure.FSMC_MemoryDataWidth = FSMC_MemoryDataWidth_16b;    // �洢�����ݿ��Ϊ16bit	
	FSMC_NORSRAMInitStructure.FSMC_BurstAccessMode =FSMC_BurstAccessMode_Disable; // FSMC_BurstAccessMode_Disable; 
	FSMC_NORSRAMInitStructure.FSMC_WaitSignalPolarity = FSMC_WaitSignalPolarity_Low;
	FSMC_NORSRAMInitStructure.FSMC_AsynchronousWait=FSMC_AsynchronousWait_Disable; 
	FSMC_NORSRAMInitStructure.FSMC_WrapMode = FSMC_WrapMode_Disable;   
	FSMC_NORSRAMInitStructure.FSMC_WaitSignalActive = FSMC_WaitSignalActive_BeforeWaitState;  
	FSMC_NORSRAMInitStructure.FSMC_WriteOperation = FSMC_WriteOperation_Enable;	   // �洢��дʹ��
	FSMC_NORSRAMInitStructure.FSMC_WaitSignal = FSMC_WaitSignal_Disable;   
	FSMC_NORSRAMInitStructure.FSMC_ExtendedMode = FSMC_ExtendedMode_Enable;        // ��дʹ�ò�ͬ��ʱ��
	FSMC_NORSRAMInitStructure.FSMC_WriteBurst = FSMC_WriteBurst_Disable; 
	FSMC_NORSRAMInitStructure.FSMC_ReadWriteTimingStruct = &readWriteTiming;       // ��дʱ��
	FSMC_NORSRAMInitStructure.FSMC_WriteTimingStruct = &writeTiming;               // дʱ��
	FSMC_NORSRAMInit(&FSMC_NORSRAMInitStructure);  // ��ʼ��FSMC����
	FSMC_NORSRAMCmd(FSMC_Bank1_NORSRAM1, ENABLE);  // ʹ��BANK1 
}


/*******************************************************************************
* Function Name  : LCD_Reset
* Description    : �ԣ̣ãĽ��и�λ����
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void LCD_RESET(void)
{   
	GPIO_SetBits(GPIOD, GPIO_Pin_13 );		 
	delay_ms(30);
	GPIO_ResetBits(GPIOD, GPIO_Pin_13);	  
	delay_ms(50);					   
	GPIO_SetBits(GPIOD, GPIO_Pin_13 );		 
	delay_ms(30);		 
}


/*******************************************************************************
* Function Name  : LCD_WR_REG����
* Input          : regval
* Output         : None
* Return         : None
*******************************************************************************/
void LCD_WR_REG(u16 regval)
{  
	LCD->LCD_REG=regval;
}

void LCD_WR_8REG(u16 regval)    
{   
	LCD->LCD_REG=regval;
}

/*******************************************************************************
* Function Name  : LCD_WR_DATA   
* Input          : data
* Output         : None
* Return         : None
*******************************************************************************/
void LCD_WR_DATA(u16 data)
{
	LCD->LCD_RAM=data;
}

void LCD_WR_8DATA(u16 data)  //8BIT REG
{
	LCD->LCD_RAM=data;
}

/*******************************************************************************
* Function Name  : LCD_WriteReg    
* Input          : LCD_Reg,LCD_RegValue
* Output         : None
* Return         : None
*******************************************************************************/
void LCD_WriteReg(u16 LCD_Reg,u16 LCD_RegValue)  
{	
	LCD->LCD_REG = LCD_Reg;		   	 
	LCD->LCD_RAM = LCD_RegValue; 		
}

/*******************************************************************************
* Function Name  : LCD_RD_DATA
*******************************************************************************/
u16 LCD_RD_DATA(void)
{
	vu16   ram;
	ram = LCD->LCD_RAM;	
	return ram;	 
}

/*******************************************************************************
* Function Name  : LCD_ReadReg     
*******************************************************************************/
u16 LCD_ReadReg(u16 LCD_Reg)
{	u16 info;
	LCD_WR_REG(LCD_Reg);
	delay_us(5);
	info=LCD_RD_DATA();
	info<<=8;
	info|=LCD_RD_DATA();
	return info;
}   

/*******************************************************************************
* Function Name  : LCD_WriteRAM_Prepare
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void LCD_WriteRAM_Prepare(void)
{
	TFT_WriteRAM(); // @TFTLCD_Init.c
}

/*******************************************************************************
* Function Name  : LCD_WriteRAM    
* Description    : LCD write gram 
* Input          : RGB_Code
* Output         : None
* Return         : None
*******************************************************************************/
void LCD_WriteRAM(u16 RGB_Code)
{
	LCD->LCD_RAM = RGB_Code;
}

/*******************************************************************************
* Function Name  : LCD_BGR2RGB     �٣�
*******************************************************************************/
u16 LCD_BGR2RGB(u16 c)
{
	u16  r,g,b,rgb;   

	b=(c>>0)&0x1f;
	g=(c>>5)&0x3f;
	r=(c>>11)&0x1f;	 
	rgb=(b<<11)+(g<<5)+(r<<0);		 
	return(rgb);
} 

/*******************************************************************************
*******************************************************************************/
void opt_delay(u8 i)
{
	while(i--);
}

/*******************************************************************************
* Function Name  : LCD_ReadPoint    �٣�
*******************************************************************************/
u16 LCD_ReadPoint(u16 x,u16 y)
{
 	u16 r=0,g=0,b=0;

	if(x>=lcddev.width||y>=lcddev.height)
		return 0;
	LCD_SetCursor(x,y);	    
	if(lcddev.id==0X9341||lcddev.id==0X6804||lcddev.id==0X5310||lcddev.id==0X1963)LCD_WR_REG(0X2E);//9341/6804/3510/1963 ���Ͷ�GRAMָ��
	else if(lcddev.id==0X5510)LCD_WR_REG(0X2E00);	//5510 ���Ͷ�GRAMָ��
	else LCD_WR_REG(0X22);      		 			//����IC���Ͷ�GRAMָ��
	if(lcddev.id==0X9320)opt_delay(2);				//FOR 9320,��ʱ2us	    
 	r=LCD_RD_DATA();								//dummy Read	   
	if(lcddev.id==0X1963)return r;					//1963ֱ�Ӷ��Ϳ��� 
	opt_delay(2);	  
 	r=LCD_RD_DATA();  		  						//ʵ��������ɫ
 	if(lcddev.id==0X9341||lcddev.id==0X5310||lcddev.id==0X5510){
		opt_delay(2);	  
		b=LCD_RD_DATA(); 
		g=r&0XFF;		//����9341/5310/5510,��һ�ζ�ȡ����RG��ֵ,R��ǰ,G�ں�,��ռ8λ
		g<<=8;
	} 
	if(lcddev.id==0X9325||lcddev.id==0X4535||lcddev.id==0X4531||lcddev.id==0XB505||lcddev.id==0XC505)return r;	//�⼸��ICֱ�ӷ�����ɫֵ
	else if(lcddev.id==0X9341||lcddev.id==0X5310||lcddev.id==0X5510)return (((r>>11)<<11)|((g>>10)<<5)|(b>>11));//ILI9341/NT35310/NT35510��Ҫ��ʽת��һ��
	else return LCD_BGR2RGB(r);
}	


/*******************************************************************************
* Function Name  : LCD_Clear   modify YZ
*******************************************************************************/
void LCD_Clear(u16 color)
{
	u16 i,j;
	u32 index=0;     
	u32 totalpoint=lcddev.width;
	totalpoint*=lcddev.height;
	BlockWrite(0,lcddev.width,0,lcddev.height);
	for(index=0;index<totalpoint;index++){
		LCD_WriteRAM(color);
	}	
} 


/*******************************************************************************
* Function Name  : LCD_Display
* Return         : None
*******************************************************************************/
void LCD_Display(u16 color)
{
	u16 i,j;
	
	u16 sx=0,sy=0;
	u16 twidth,theight;
	twidth=sx+lcddev.width-1;
	theight=sy+lcddev.height-1;
	BlockWrite(0,lcddev.width,0,lcddev.height);
	for(i=0;i<lcddev.height;i++){
		for(j=0;j<lcddev.width;j++)	{	
			LCD_WriteRAM(color);
		}
	}
}

/*******************************************************************************
* Function Name  : LCD_DisplayJiuGongGe
* Description    : �Ź�����ʾ:RGB-BGR-RGB
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void LCD_DisplayJiuGongGe(void)
{

	u16 Row,Column,aa;
	
	BlockWrite(0,lcddev.width,0,lcddev.height);
	
	aa=lcddev.height/3;

	for(Row=0;Row<aa;Row++)
	{
		for(Column=0;Column<(lcddev.width/3);Column++)	LCD_WriteRAM(0xf800);
//		LCD->LCD_RAM=0xf800;
		for(Column=0;Column<(lcddev.width/3);Column++)	LCD_WriteRAM(0x07e0);
//		LCD->LCD_RAM=0x07e0;
		for(Column=0;Column<(lcddev.width/3);Column++)	LCD_WriteRAM(0x001f);
//		LCD->LCD_RAM=0x001f;
		for(Column=0;Column<(lcddev.width%3);Column++) 	LCD_WriteRAM(0x001f);
//		LCD->LCD_RAM=0x001f;
	}

	for(Row=0;Row<aa;Row++)
	{			  
		for(Column=0;Column<(lcddev.width/3);Column++)	LCD_WriteRAM(0x001f);
//		LCD->LCD_RAM=0x001f;
		for(Column=0;Column<(lcddev.width/3);Column++)	LCD_WriteRAM(0xf800);		
//		LCD->LCD_RAM=0xf800;
		for(Column=0;Column<(lcddev.width/3);Column++)	LCD_WriteRAM(0x07e0);
//		LCD->LCD_RAM=0x07e0;
		for(Column=0;Column<(lcddev.width%3);Column++)	LCD_WriteRAM(0x07e0); 
//		LCD->LCD_RAM=0x07e0;
	}

	for(Row=0;Row<aa;Row++)
	{			  				   
		for(Column=0;Column<(lcddev.width/3);Column++)	LCD_WriteRAM(0x07e0); 
//		LCD->LCD_RAM=0x07e0;
		for(Column=0;Column<(lcddev.width/3);Column++)	LCD_WriteRAM(0x001f);  
//		LCD->LCD_RAM=0x001f;
		for(Column=0;Column<(lcddev.width/3);Column++)	LCD_WriteRAM(0xf800); 
//		LCD->LCD_RAM=0xf800;
		for(Column=0;Column<(lcddev.width%3);Column++)	LCD_WriteRAM(0xf800);  
//		LCD->LCD_RAM=0xf800;
	}

	for(Row=0;Row<(lcddev.height%3);Row++)
	{			  				   
		for(Column=0;Column<(lcddev.width/3);Column++)	LCD_WriteRAM(0x07e0); 
//		LCD->LCD_RAM=0x07e0;
		for(Column=0;Column<(lcddev.width/3);Column++)	LCD_WriteRAM(0x001f);  
//		LCD->LCD_RAM=0x001f;
		for(Column=0;Column<(lcddev.width/3);Column++)	LCD_WriteRAM(0xf800); 
//		LCD->LCD_RAM=0xf800;
		for(Column=0;Column<(lcddev.width%3);Column++)	LCD_WriteRAM(0xf800);  
//		LCD->LCD_RAM=0xf800;
	}

}

/*******************************************************************************
* Function Name  : LCD_Frame
* Description    : �ı��ߣ��м���������䵥����ɫ  
* Input          :RGB_DataΪ�м䴿ɫ�� f_dataΪ�ı߿���ɫ
* Output         : None
* Return         : None
*******************************************************************************/
void LCD_Frame(u16 RGB_Data,u16 f_data)
{
	u16 i,j;

	BlockWrite(0,lcddev.width,0,lcddev.height);

	for(i=0;i<1;i++)
	{
		for(j=0;j<lcddev.width;j++)	LCD_WriteRAM(f_data);	
//		LCD->LCD_RAM=f_data;
	}
	
	for (i=0;i<(lcddev.height-2);i++)
	{
		for (j=0;j<1;j++)	LCD_WriteRAM(f_data);
//		LCD->LCD_RAM=f_data;
			
		for (j=0;j<(lcddev.width-2);j++)	LCD_WriteRAM(RGB_Data);	
//		LCD->LCD_RAM=RGB_Data;
			
		for (j=0;j<1;j++)	LCD_WriteRAM(f_data);
//		LCD->LCD_RAM=f_data;
	}

	for(i=0;i<1;i++)
	{
		for(j=0;j<lcddev.width;j++)	LCD_WriteRAM(f_data);
//		LCD->LCD_RAM=f_data;
	}	
	
}	
	

/*******************************************************************************
* Function Name  : Show_Gray
* Description    : �ҽ���ʾ
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void Show_Gray(void) 
{
	unsigned int i,j,k,c16h;
	
	BlockWrite(0,lcddev.width,0,lcddev.height);
	
	for(j=0;j<(lcddev.height);j++)  
		{
		c16h=0x0000;
		for(k=0;k<16;k++)
			{
		    for(i=0;i<(lcddev.width/16);i++)
				{
					LCD_WriteRAM(c16h);	
//					LCD->LCD_RAM=c16h;
				}
			c16h=c16h+0x1082;//32�� 0841 16�� 1082 8��2104
			}
		}
}	

/*******************************************************************************
* Function Name  : LCD_Fill   Modify YZ
* Description    : ��ָ����������䵥����ɫ��(sx,sy),(ex,ey):�����ζԽ�����,�����СΪ:(ex-sx+1)*(ey-sy+1)  
* Input          : color:Ҫ������ɫ
* Output         : None
* Return         : None
*******************************************************************************/
void LCD_Fill(u16 sx,u16 sy,u16 ex,u16 ey,u16 color)
{          
	u16 i,j;
	u16 xlen=0;
	u16 temp;

	xlen=ex-sx+1;
	for(i=sy;i<=ey;i++){
		LCD_SetCursor(sx,i);
		LCD_WriteRAM_Prepare();
		for(j=0;j<xlen;j++)	
		LCD_WriteRAM(color);
	}
	
}  

/*******************************************************************************
//��ָ�����������ָ����ɫ��		YZ	 
//(sx,sy),(ex,ey):�����ζԽ�����,�����СΪ:(ex-sx+1)*(ey-sy+1)   
//color:Ҫ������ɫ
*******************************************************************************/
void LCD_Color_Fill(u16 sx,u16 sy,u16 ex,u16 ey,u16 *color)
{  
	u16 height,width;
	u16 i,j;
	width=ex-sx+1; 	
	height=ey-sy+1;	
 	for(i=0;i<height;i++){
 		LCD_SetCursor(sx,sy+i);
		LCD_WriteRAM_Prepare(); 
		for(j=0;j<width;j++)
		LCD_WriteRAM(color[i*width+j]);
	}		  
} 

/*******************************************************************************
* Function Name  : DisplayPicture
* Description    : ͼƬ��������Ļ����ʾ 
* Input          : 
* Output         : None
* Return         : None
*һ��TFT�Ĳ�ɫ,һ����ռ2���ֽ�RGB565,Ҳ����һ���������2^16��ɫ��,һ�����������ͼƬ
* ͼƬΪ���������������� �����м���ʾ
*******************************************************************************/
void DisplayPicture(void)
{
	u16 temp,pos,t;  

	BlockWrite(0,lcddev.width,0,lcddev.height);
	
//	BlockWrite((lcddev.width-240)/2,(lcddev.width+240)/2-1,(lcddev.height-320)/2,(lcddev.height+320)/2-1); //OK 20170927
  
	for(pos=0;pos<320;pos++) //(pos=0;pos<lcddev.height;pos++)
	{
		for(t=0;t<240*2;t++) //(t=0;t<lcddev.width*2;t++)
		{
			//temp=gImage[pos*lcddev.width*2+t]*256+gImage[pos*lcddev.width*2+t+1];  //����ط�  �ĳ�gImage[pos*480+t]<<8+gImage[pos*480+t+1];  ����������
			temp=gImage[pos*240*2+t]*256+gImage[pos*240*2+t+1];
		
			t++;                                
			LCD_WriteRAM(temp);      //����������  ������ͷ��һ�²��������������                            
		}                                
	}         	
	
}	

//ͼƬ128-128��������Ļ�����м���ʾ 
void DisplayPicture1(void)
{

	u16 temp,pos,t;  

//	BlockWrite(113,207,193,287);//OK 20170927
	BlockWrite((lcddev.width-128)/2,(lcddev.width+128)/2-1,(lcddev.height-128)/2,(lcddev.height+128)/2-1); //OK 20171005	
	
	for(pos=0;pos<128;pos++)
	{
		for(t=0;t<128*2;t++)
		{
			temp=gImage_128128[pos*128*2+t]*256+gImage_128128[pos*128*2+t+1];  
			t++;                                
			LCD_WriteRAM(temp);                                 
		}                                
	}

}	

/*******************************************************************************
*******************************************************************************/
void LCD_DrawPoint(u16 x,u16 y)
{
	LCD_SetCursor(x,y);		//���ù��λ�� 
	LCD_WriteRAM(POINT_COLOR);
}

/*******************************************************************************
*******************************************************************************/
void LCD_Fast_DrawPoint(u16 x,u16 y,u16 color)
{	  
	LCD_SetCursor(x,y);	
	LCD_WriteRAM(color);
}

/*******************************************************************************
*******************************************************************************/
void LCD_DrawLine(u16 x1, u16 y1, u16 x2, u16 y2)
{
	u16 t; 
	int xerr=0,yerr=0,delta_x,delta_y,distance; 
	int incx,incy,uRow,uCol; 
	delta_x=x2-x1; //������������ 
	delta_y=y2-y1; 
	uRow=x1; 
	uCol=y1; 
	if(delta_x>0)incx=1; //���õ������� 
	else if(delta_x==0)incx=0;//��ֱ�� 
	else {incx=-1;delta_x=-delta_x;} 
	if(delta_y>0)incy=1; 
	else if(delta_y==0)incy=0;//ˮƽ�� 
	else{incy=-1;delta_y=-delta_y;} 
	if( delta_x>delta_y)distance=delta_x; //ѡȡ�������������� 
	else distance=delta_y; 
	for(t=0;t<=distance+1;t++ )//������� 
	{  
		LCD_DrawPoint(uRow,uCol);//���� 
		xerr+=delta_x ; 
		yerr+=delta_y ; 
		if(xerr>distance) 
		{ 
			xerr-=distance; 
			uRow+=incx; 
		} 
		if(yerr>distance) 
		{ 
			yerr-=distance; 
			uCol+=incy; 
		} 
	}  
}    

/*******************************************************************************
//������	  YZ
//(x1,y1),(x2,y2):���εĶԽ�����
*******************************************************************************/
void LCD_DrawRectangle(u16 x1, u16 y1, u16 x2, u16 y2)
{
	LCD_DrawLine(x1,y1,x2,y1);
	LCD_DrawLine(x1,y1,x1,y2);
	LCD_DrawLine(x1,y2,x2,y2);
	LCD_DrawLine(x2,y1,x2,y2);
}

/*******************************************************************************
//��ָ��λ�û�һ��ָ����С��Բ  YZ
//(x,y):���ĵ�
//r    :�뾶
*******************************************************************************/
void LCD_Draw_Circle(u16 x0,u16 y0,u8 r)
{
	int a,b;
	int di;
	a=0;b=r;	  
	di=3-(r<<1);             //�ж��¸���λ�õı�־
	while(a<=b)
	{
		LCD_DrawPoint(x0+a,y0-b);             //5
 		LCD_DrawPoint(x0+b,y0-a);             //0           
		LCD_DrawPoint(x0+b,y0+a);             //4               
		LCD_DrawPoint(x0+a,y0+b);             //6 
		LCD_DrawPoint(x0-a,y0+b);             //1       
 		LCD_DrawPoint(x0-b,y0+a);             
		LCD_DrawPoint(x0-a,y0-b);             //2             
  		LCD_DrawPoint(x0-b,y0-a);             //7     	         
		a++;
		//ʹ��Bresenham�㷨��Բ     
		if(di<0)di +=4*a+6;	  
		else
		{
			di+=10+4*(a-b);   
			b--;
		} 						    
	}
} 

/*******************************************************************************
//��ָ��λ����ʾһ���ַ�   YZ
//x,y:��ʼ����
//num:Ҫ��ʾ���ַ�:" "--->"~"
//size:�����С 12/16/24
//mode:���ӷ�ʽ(1)���Ƿǵ��ӷ�ʽ(0)
//���ͣ�
//1���ַ����(size/2)���߶�(size)һ�롣
//2���ַ�ȡģΪ����ȡģ����ÿ��ռ�����ֽڣ���󲻹������ֽ�����ռһ�ֽڡ�
//3���ַ���ռ�ռ�Ϊ��ÿ����ռ�ֽڣ�������
//csize=(size/8+((size%8)?1:0))*(size/2)
//�˺�*ǰΪ����ÿ����ռ�ֽ������˺�*��Ϊ�������ַ��߶�һ�룩
*******************************************************************************/
void LCD_ShowChar(u16 x,u16 y,u8 num,u8 size,u8 mode)
{  							  
    u8 temp,t1,t;
	u16 y0=y;
	u8 csize=(size/8+((size%8)?1:0))*(size/2);		//�õ�����һ���ַ���Ӧ������ռ���ֽ���	
 	num=num-' ';//�õ�ƫ�ƺ��ֵ��ASCII�ֿ��Ǵӿո�ʼȡģ������-' '���Ƕ�Ӧ�ַ����ֿ⣩
	for(t=0;t<csize;t++)
	{   
		if(size==12)temp=asc2_1206[num][t]; 	 	//����1206����
		else if(size==16)temp=asc2_1608[num][t];	//����1608����
		else if(size==24)temp=asc2_2412[num][t];	//����2412����
		else return;								//û�е��ֿ�
		for(t1=0;t1<8;t1++)
		{			    
			if(temp&0x80)LCD_Fast_DrawPoint(x,y,POINT_COLOR);
			else if(mode==0)LCD_Fast_DrawPoint(x,y,BACK_COLOR);
			temp<<=1;
			y++;
			if(y>=lcddev.height)return;		//��������
			if((y-y0)==size)
			{
				y=y0;
				x++;
				if(x>=lcddev.width)return;	//��������
				break;
			}
		}  	 
	}  	    	   	 	  
}  

/*******************************************************************************
//m^n����  YZ
//����ֵ:m^n�η�.
*******************************************************************************/
u32 LCD_Pow(u8 m,u8 n)
{
	u32 result=1;	 
	while(n--)result*=m;    
	return result;
}	

/*******************************************************************************
//��ʾ����,��λΪ0,����ʾ  YZ
//x,y :�������	 
//len :���ֵ�λ��
//size:�����С
//color:��ɫ 
//num:��ֵ(0~4294967295);
*******************************************************************************/
void LCD_ShowNum(u16 x,u16 y,u32 num,u8 len,u8 size)
{         	
	u8 t,temp;
	u8 enshow=0;						   
	for(t=0;t<len;t++)
	{
		temp=(num/LCD_Pow(10,len-t-1))%10;
		if(enshow==0&&t<(len-1))
		{
			if(temp==0)
			{
				LCD_ShowChar(x+(size/2)*t,y,' ',size,0);
				continue;
			}else enshow=1; 
		 	 
		}
	 	LCD_ShowChar(x+(size/2)*t,y,temp+'0',size,0); 
	}
} 

/*******************************************************************************
//��ʾ����,��λΪ0,������ʾ  YZ
//x,y:�������
//num:��ֵ(0~999999999);	 
//len:����(��Ҫ��ʾ��λ��)
//size:�����С
//mode:
//[7]:0,�����;1,���0.
//[6:1]:����
//[0]:0,�ǵ�����ʾ;1,������ʾ.
*******************************************************************************/
void LCD_ShowxNum(u16 x,u16 y,u32 num,u8 len,u8 size,u8 mode)
{  
	u8 t,temp;
	u8 enshow=0;						   
	for(t=0;t<len;t++)
	{
		temp=(num/LCD_Pow(10,len-t-1))%10;
		if(enshow==0&&t<(len-1))
		{
			if(temp==0)
			{
				if(mode&0X80)LCD_ShowChar(x+(size/2)*t,y,'0',size,mode&0X01);  
				else LCD_ShowChar(x+(size/2)*t,y,' ',size,mode&0X01);  
 				continue;
			}else enshow=1; 
		 	 
		}
	 	LCD_ShowChar(x+(size/2)*t,y,temp+'0',size,mode&0X01); 
	}
} 

/*******************************************************************************
//��ʾ�ַ���
//x,y:�������
//width,height:�����С  
//size:�����С
//*p:�ַ�����ʼ��ַ		
//˵�����ַ����е���ɵģ������ַ������в��ϵ��û��㺯��LCD_DrawPoint();�����㣨��LCD->LCD_RAM��д��ɫֵ�������ɫֵ��lcd.h�ﱻ����Ϊ16λ�ĵ�ַ����
*******************************************************************************/
void LCD_ShowString(u16 x,u16 y,u16 width,u16 height,u8 size,u8 *p)
{         
	u8 x0=x;
	width+=x;
	height+=y;
    while((*p<='~')&&(*p>=' '))//�ж��ǲ��ǷǷ��ַ�!
    {       
        if(x>=width){x=x0;y+=size;}
        if(y>=height)break;//�˳�
        LCD_ShowChar(x,y,*p,size,0);
        x+=size/2;
        p++;
    }  
}

////////////////End SD Card///////////////








