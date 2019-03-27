#include "usr_spi.h"

// locals

/**********************************************************
    APB2
    
SPIMode	CPOL	CPHA
0	0	0
1	0	1
2	1	0
3	1	1
		
    == three wire mode : use mode 3
    ================================= 
    SPI_InitStructure.SPI_Direction = SPI_Direction_1Line_Tx; // Initially Tx
    SPI_RxFIFOThresholdConfig(SPI1, SPI_RxFIFOThreshold_QF);
    
***********************************************************/
void usrspi2_init ( int threewire, int lsbfirst, int spimode )
{
    GPIO_InitTypeDef   GPIO_InitStructure;
    SPI_InitTypeDef     SPI_InitStructure;

	  // GPIO : enable SCK MOSI MISO and NSS GPIO clocks using =======
		if ( threewire ) {
			GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_13 | GPIO_Pin_15;
	  } else {
    	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_13 |GPIO_Pin_14 | GPIO_Pin_15;
	  }
		GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF_PP;  // push pull  AF: a;ternate Function
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    if ( threewire ) {
    //  GPIO_ResetBits(GPIOB,GPIO_Pin_13|GPIO_Pin_15); // for mode 0  
		} else {
		//  GPIO_ResetBits(GPIOB,GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15); // for mode 0  
		}
		
    RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB, ENABLE );
    //RCC_APB2PeriphClockCmd( RCC_APB2Periph_SPI1,  ENABLE ); 
    RCC_APB1PeriphClockCmd( RCC_APB1Periph_SPI2,  ENABLE );
	  //RCC_APB1PeriphResetCmd( RCC_APB1Periph_SPI3,  ENABLE ); 

    if ( threewire ) {
        SPI_InitStructure.SPI_Direction = SPI_Direction_1Line_Tx; // Initially Tx
    } else {
        SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex; 
    }
    SPI_InitStructure.SPI_Mode = SPI_Mode_Master;       
    SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;       

    switch (spimode) {
    case 0:
    default:
			  SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;     
        SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;      
        break;
    case 1:
        SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;  //   
        SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge; //    
        break;
    case 2:
        SPI_InitStructure.SPI_CPOL = SPI_CPOL_High;   //    
        SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge; //    
        break;
    case 3:
        SPI_InitStructure.SPI_CPOL = SPI_CPOL_High;  // 1   
        SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge; // 1 mode 3   
        break;
    }

    SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;   
    SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_16;    
    if ( lsbfirst ) {
        SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_LSB;
    } else {
        SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;  
    }
    SPI_InitStructure.SPI_CRCPolynomial = 7;    
    SPI_Init(SPI2, &SPI_InitStructure);  
    
		// SPI_I2S_ITConfig(SPI2, SPI_I2S_IT_TXE, ENABLE );
		// SPI_I2S_ITConfig(SPI2, SPI_I2S_IT_RXNE, ENABLE );
    
    SPI_Cmd(SPI2, ENABLE);
}   

//SpeedSet:
//SPI_BaudRatePrescaler_2   2   
//SPI_BaudRatePrescaler_8   8   
//SPI_BaudRatePrescaler_16  16  
//SPI_BaudRatePrescaler_256 256 
void usrspi2_setspeed(u8 SPI_BaudRatePrescaler) 
{
    assert_param(IS_SPI_BAUDRATE_PRESCALER(SPI_BaudRatePrescaler));
    SPI2->CR1&=0XFFC7;
    SPI2->CR1|=SPI_BaudRatePrescaler;   
    SPI_Cmd(SPI2,ENABLE); 
} 

// 
// generate 8 bit clocks for read/write operation
//   to read data from SPI, need call this function twice!!
// 1. send clock for address, 2. send data to generate clock for read !!!! 
// 
// for write data, call twice as well : address | data 
u8 usrspi2_WriteReadAByte (u8 TxData)
{       
    u8 retry=0;                 

    retry=0;
    while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_TXE) == RESET) { // wait tx buffer empty
        retry++;
        //if (retry>200)return 0;
    }             

    SPI_I2S_SendData(SPI2, TxData);  // shift 1 byte out: clk, mosi

    retry=0;
    while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_RXNE) == RESET) {
        retry++;
        //if (retry>200)return 0;
    }                    
	
    return SPI_I2S_ReceiveData(SPI2);                   
}

// for three wire mode ====================
// call twice for write data : address | data 
// ====================================================================
void usrspi2_SendByte3Wire(u8 data)
{
    u8 retry=0;                 

    retry=0;
    while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_TXE) == RESET) { // wait tx buffer empty!
        retry++;
        //if (retry>200)return ;
    }

    SPI_I2S_SendData(SPI2, data); 

    retry=0;
    //while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_RXNE) == RESET) { 3-w mode, this one doesnt work
    while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_BSY) == SET) { // wait finish sending 
        retry++;
        //if (retry>200)return ;
    }                             
    // SPI_I2S_ReceiveData(SPI2); // not for 3 wire mode                   
}


u8   usrspi2_ReadByte3Wire()
{
    u8     result;
    u8     retry=0;                 

    SPI_BiDirectionalLineConfig (SPI2, SPI_Direction_Rx);  // change data pin to input mode 
    SPI_I2S_SendData(SPI2, 0x00); // shift dumy to generate SPI clock   
    retry = 0;
    while (!(SPI2->SR & SPI_I2S_FLAG_RXNE)) {  // wait data received
        retry++;
        //if (retry>200) 
				//	break; // return 0;
    }
    SPI_BiDirectionalLineConfig(SPI2, SPI_Direction_Tx);// SPI1->CR1 |= SPI_Direction_Tx;  change data pin to output mode 

    result = SPI_I2S_ReceiveData(SPI2);

    return result;
}



