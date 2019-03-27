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

#define TRANSP  1           //������ʾ��ʱ�򲻴�������ɫ
#define NORMAL  0           //������ʾ��ʱ���б�����ɫ

//sbit RS=P1^2; 
sbit CS=P0^0;

sbit RES=P1^3;
 
sbit MOSI=P1^5;
sbit MISO=P1^6;
sbit SCK=P1^7; 

#define	HZ_column  16 //���������С

//==========================TOUCH DEFINE

sbit touch_CS=P0^1;
sbit touch_DCLK=P1^7;
sbit touch_DIN=P1^5; 
sbit touch_DOUT=P1^6; 
sbit touch_INT=P0^2; 

// A/D ͨ��ѡ�������ֺ͹����Ĵ���
#define CHX     0x90    //ͨ��Y+��ѡ�������    
#define CHY     0xD0    //ͨ��X+��ѡ������� 

//=================================
void DelayNS(uint time)                
{
    while(time--!=0); 
}