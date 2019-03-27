/************************************************************
 *  @module: adbs5020.c 
 *  @author(s): tom wu
 *  @date: 2016 for mailbox detection project  
 *  @copyright urenhu coporation  
 *  
**/

#include "usr_sys.h"
#include "usr_delay.h"
#include "usr_spi.h"
#include "adns5020.h"


#define ADNS5020_RST                     0x3a   //reset register
#define ADNS5020_MOR                     0x02   //motion register
#define ADNS5020_DXR                     0x03   //dx register
#define ADNS5020_DYR                     0x04   //dy register
#define ADNS5020_SQR                     0x05   //sensor quality register
#define ADNS5020_PXR                     0x0b   //pixel start register 
#define ADNS5020_MBUR                    0x63   //pixel start register 
#define ADNS5020_MAX_PIX                 225

//===============================================================================
//  LADNS           STM32
//---------------------------------------------------------------------
//  4 # CS  -<---- PB0     GPIO
//  5 # SIO -<-->- PB15    MOSI
//  6 # SCK -<---- PB13    SCK 
//                 PB14    MISO
// 17 # RST -<---- PB1     GPIO
// 
//===============================================================================    
#define ADNS5020_nCS	          PBout(0)	  
//#define ADNS5020_SIO	        PBout(15)	  
//#define ADNS5020_SCK	        PBout(13)	  
#define ADNS5020_nReset         PBout(1 ) 


//--------------Write------------------------------//
static void write(u8 address, u8 data)
{
	  u8   opcode = 0;

  	ADNS5020_nCS = 0; //GPIO_ResetBits(ADNS5020_PORT, ADNS5020_nCS);  
	  opcode = address | 0x80;
    usrspi2_SendByte3Wire(opcode);
    delay_us(5);
    usrspi2_SendByte3Wire(data);
		ADNS5020_nCS = 1; //GPIO_SetBits(ADNS5020_PORT, ADNS5020_nCS);  

	delay_us(30);
}


//--------------Read------------------------------//
static u8 read(u8 address)
{
    u8   data    = 0 ;
	  u8   opcode  = 0;
    
	  opcode = address & 0x7f;

		ADNS5020_nCS = 0; //GPIO_ResetBits(ADNS5020_PORT, ADNS5020_nCS);  
    usrspi2_SendByte3Wire(opcode);
    delay_us(5);
    data = usrspi2_ReadByte3Wire();
    ADNS5020_nCS = 1; //GPIO_ResetBits(ADNS5020_PORT, ADNS5020_nCS);  

    delay_us(4); // T_srad=4us
		return data;
}


//--------------Reset----------------------------//
void adns5020_reset() 
{
    ADNS5020_nReset = 0;  // GPIO_ResetBits(ADNS5020_PORT, ADNS5020_nReset);
    delay_us(750);

    ADNS5020_nReset = 1; //GPIO_SetBits(ADNS5020_PORT, ADNS5020_nReset);  
    delay_us(750);

}

//-------------Config----------------------------//
int adns5020_config()
{
    u8  conf = read(ADNS5020_MOR);
    return (conf==0) ? 500 : 1000;
}

//-------------Motion_detected-------------------//
//int motion_detected() 
//{
//    u8 motion = read(ADNS5020_MOR);
//    return (motion > 127) ? 1 : 0;
//}

//-------------Dx--------------------------------//
u8  adns5020_dx() 
{
    u8  dx_raw = read(ADNS5020_DXR);
    return dx_raw;
}

//-------------Dy--------------------------------//
u8 adns5020_dy() {
    u8  dy_raw = read(ADNS5020_DYR);
    return dy_raw;
}

//-------------Squal-----------------------------//
u8 adns5020_squal() {
    return read(ADNS5020_SQR);
}

u8 adns5020_reg_read(u8 reg) {
    return read(reg);
}


//-------------Pixels----------------------------//
void adns5020_pixels(u8* buffer ) 
{
    u8 pixel_count = 0;
    u8   data    = 0 ;
	  u8   opcode  = 0;

		write(ADNS5020_PXR, 0x00);   // reset grab counte
  	for(pixel_count = 0; pixel_count < ADNS5020_MAX_PIX;  pixel_count++ ) {
        buffer[pixel_count] = read(ADNS5020_PXR);
    }
}

void adns5020_init(void)
{   
    GPIO_InitTypeDef     GPIO_InitStructure;
    RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB, ENABLE );

    GPIO_InitStructure.GPIO_Pin    = GPIO_Pin_0 | GPIO_Pin_1;  // PB12 ==> CS ADNS5020_nReset
    GPIO_InitStructure.GPIO_Mode   = GPIO_Mode_Out_PP;  
    GPIO_InitStructure.GPIO_Speed  = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    GPIO_SetBits(GPIOB, GPIO_Pin_0 | GPIO_Pin_1 );

		GPIO_InitStructure.GPIO_Pin    = GPIO_Pin_3;  // PB3 input PB
    GPIO_InitStructure.GPIO_Mode   = GPIO_Mode_IPD; // GPIO_Mode_Out_PP;  
    GPIO_InitStructure.GPIO_Speed  = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    usrspi2_init(1, 0, 3);        
    usrspi2_setspeed(SPI_BaudRatePrescaler_256);
	
	  write (ADNS5020_RST,0x0); //reset chip
}  

