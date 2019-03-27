
#include "usr_spi.h"
#include "usr_delay.h"   
#include "usr_fram.h"

#define	FRAM_CS     PBout(12)

static void usr_fram_write_enable(void);  
static void usr_fram_write_disable(void); 

// ================= API ======================================

void usr_fram_init(void)
{   
    GPIO_InitTypeDef     GPIO_InitStructure;
    RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOD|RCC_APB2Periph_GPIOG, ENABLE );

    GPIO_InitStructure.GPIO_Pin    = GPIO_Pin_12;       // PB12 ==> CS 
    GPIO_InitStructure.GPIO_Mode   = GPIO_Mode_Out_PP;  // DO 
    GPIO_InitStructure.GPIO_Speed  = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    GPIO_SetBits(GPIOB,GPIO_Pin_12);

    usrspi2_init(0,0,3);        
    usrspi2_setspeed(SPI_BaudRatePrescaler_2);
}  

u8   usr_fram_read_sr (void)
{  
    u8 byte=0;

    FRAM_CS = 0;                           
    usrspi2_WriteReadAByte(FRAM_READ_SR);
    byte=usrspi2_WriteReadAByte(0Xff); // any dammy data, as it is for clock generating !!!!            
    FRAM_CS =1;                           

    return byte;   
} 

void usr_fram_write_sr(u8 sr)   
{   
    FRAM_CS=0;    
    usrspi2_WriteReadAByte(FRAM_WRITE_SR);
    usrspi2_WriteReadAByte(sr);                
    FRAM_CS=1;    
}   

void usr_fram_write_enable(void)   
{
    FRAM_CS=0;                            
    usrspi2_WriteReadAByte(FRAM_WRITE_ENABLE); 
    FRAM_CS=1;                    
} 

void usr_fram_write_disable(void)   
{  
    FRAM_CS=0;                            
    usrspi2_WriteReadAByte(FRAM_WRITE_DISABLE);     
    FRAM_CS=1;                            
}               

void usr_fram_read  (u8* pBuffer, u16 len, u16 adr )   
{ 
    u16 i;                                                      
    FRAM_CS=0;   // enable chip selection                         
    usrspi2_WriteReadAByte(FRAM_READ_DATA);         
    //usrspi2_WriteReadAByte((u8)((adr)>>16));      
    usrspi2_WriteReadAByte((u8)((adr)>>8));   
    usrspi2_WriteReadAByte((u8)adr);   
    for (i=0;i<len;i++) {
        pBuffer[i]=usrspi2_WriteReadAByte(0XFF);   
    }
    FRAM_CS=1;                                    
}  

void usr_fram_write  (u8* pBuffer, u16 len, u16 adr )   
{ 
    u16 i;                                                      
    usr_fram_write_enable();         
	
    FRAM_CS=0;   // enable chip selection             
    usrspi2_WriteReadAByte(FRAM_WRITE_DATA);         
    //usrspi2_WriteReadAByte((u8)((adr)>>16));      
    usrspi2_WriteReadAByte((u8)((adr)>>8));   
    usrspi2_WriteReadAByte((u8)adr);   
    for (i=0;i<len;i++) {
        usrspi2_WriteReadAByte(pBuffer[i]);   
    }
 	FRAM_CS=1;                                    

	usr_fram_write_disable();         
}

void usr_fram_wait_busy(void)   
{   
    while ((usr_fram_read_sr()&0x01)==0x01);   
}  


