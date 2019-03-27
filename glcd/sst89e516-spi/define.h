//======================================================
#define uchar unsigned char 
#define uint unsigned int
//==========================LCD DEFINE
#define RED     0xf800
#define GREEN   0x07e0
#define BLUE    0x001f
#define WHITE   0xffff
#define BLACK   0x0000
#define YELLOW   0xFFE0

#define TRANSP  1           //字体显示的时候不带背景颜色
#define NORMAL  0           //字体显示的时候有背景颜色

//sbit RS=P1^2; 
sbit CS=P0^0;

sbit RES=P1^3;
 
sbit MOSI=P1^5;
sbit MISO=P1^6;
sbit SCK=P1^7; 

#define	HZ_column  16 //汉字字体大小

//==========================TOUCH DEFINE

sbit touch_CS=P0^1;
sbit touch_DCLK=P1^7;
sbit touch_DIN=P1^5; 
sbit touch_DOUT=P1^6; 
sbit touch_INT=P0^2; 

// A/D 通道选择命令字和工作寄存器
#define CHX     0x90    //通道Y+的选择控制字    
#define CHY     0xD0    //通道X+的选择控制字 

//=================================
void DelayNS(uint time)                
{
    while(time--!=0); 
}