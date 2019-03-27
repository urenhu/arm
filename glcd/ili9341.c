//////////////////////////////////////////////////////////////////////////////
//      Filename:       Board.c
//-----------------------------------------------------------------------------
//      Target:                 STM32F103C8
//-----------------------------------------------------------------------------
//      Revision History:
//-----------------------------------------------------------------------------
#include "stm32f10x.h"
#include "ili9341.h"

// TFT control ports
#define TFT_nRESET_Port         GPIOB
#define TFT_nRESET_Bit          11
#define TFT_RS_Port             GPIOC
#define TFT_RS_Bit              14
#define TFT_nCS_Port            GPIOC
#define TFT_nCS_Bit             13
#define TFT_nWR_Port            GPIOC
#define TFT_nWR_Bit             15
#define TFT_nRD_Port            GPIOB
#define TFT_nRD_Bit             10

#define TFT_Port                (GPIOB->ODR)
#define LED_Base                 GPIOA

#define LED_Port                (GPIOA->ODR)
#define LED_Bit                  15

// Pushbuttons
#define PB_Port                (GPIOB->IDR)
#define PB_Bits                 0xF000


/**==============================================================
  * @brief  port_init () 
  * @param  None
  * @retval None
  */
static void ili9341_port_init(void) {

   // ====== ADC port ======
   // // ADC1_IN0
   // trig, Tx1 Rx1
   // ====== PWM port ======
   // ====== LED port ======
   // TFT port - D0
   // TFT port - D1
   // TFT port - D2
   // TFT port - D3
   // TFT port - D4
   // TFT port - D5
   // TFT port - D6
   // TFT port - D7

   // ====== KEYPAD port ======

   // ====== LCD port ======
   // Remap to make PB3 & PB4 available
   PORTB    // Output, Trigger level
            // Output, Gen
            // Output, TFT_nRD
            // Output, TFT_nReset
            // SW4
            // SW3
            // SW2
            // SW1
   PORTC    // TFT_nCS
            // TFT_RS
            // TFT_nWR
   // Remap to make PB3 & PB4 available
   // AFIO->MAPR &= ~AFIO_MAPR_SWJ_CFG;
   // AFIO->MAPR |= AFIO_MAPR_SWJ_CFG_1;
}

/**==============================================================
  * @brief  write_comm 
  * @param  commport
  * @retval None
  */
static void write_comm(U8 commport) {
   SetToLow(TFT_nCS_Port, (1 << TFT_nCS_Bit));   // Set TFT_nCS low
   SetToLow(TFT_RS_Port, (1 << TFT_RS_Bit));     // Set up to access Index Register (RS == 0)
   TFT_Port = (TFT_Port & 0xFF00) | commport;    // low byte write data to bus 
   SetToLow(TFT_nWR_Port, (1 << TFT_nWR_Bit));
   SetToHigh(TFT_nWR_Port, (1 << TFT_nWR_Bit));
   SetToHigh(TFT_RS_Port, (1 << TFT_RS_Bit));    // Set up to access Data Register (RS == 1)
   SetToHigh(TFT_nCS_Port, (1 << TFT_nCS_Bit));  // Set TFT_nCS high
}

/**==============================================================
  * @brief  write_data 
  * @param  data, 
  * @retval None
  */
static void write_data(U8 data) {
   SetToLow(TFT_nCS_Port, (1 << TFT_nCS_Bit));    // Set TFT_nCS low
   SetToHigh(TFT_RS_Port, (1 << TFT_RS_Bit));     // Set up to access Data Register (RS == 1)
   TFT_Port = (TFT_Port & 0xFF00) | data;
   SetToLow(TFT_nWR_Port, (1 << TFT_nWR_Bit));
   SetToHigh(TFT_nWR_Port, (1 << TFT_nWR_Bit));
   SetToHigh(TFT_nCS_Port, (1 << TFT_nCS_Bit));   // Set TFT_nCS high
}


/**==============================================================
  * @brief  ili9341_init() 
  * @param  None
  * @retval None
  */
void ili9341_init(void) {
   U8  tmp;

   ili9341_port_init(void); // setup ports that wired to LCD

   SetToHigh(TFT_nRESET_Port, (1 << TFT_nRESET_Bit)); // Reset TFT controller (Ili9341)
   // Delay(5000);   // About 1.1ms
   SetToLow(TFT_nRESET_Port, (1 << TFT_nRESET_Bit));
   // Delay(65000);  // About 15ms
   SetToHigh(TFT_nRESET_Port, (1 << TFT_nRESET_Bit));
   // Delay(65535 x 10);
   write_comm(0xcf);
   write_data(0x00);
   write_data(0xC1);
   write_data(0x30);

   write_comm(0xed);
   write_data(0x67);
   write_data(0x03);
   write_data(0x12);
   write_data(0x81);

   write_comm(0xcb);
   write_data(0x39);
   write_data(0x2c);
   write_data(0x00);
   write_data(0x34);
   write_data(0x02);

   write_comm(0xea);
   write_data(0x00);
   write_data(0x00);

   write_comm(0xe8);
   write_data(0x85);
   write_data(0x0a);
   write_data(0x78);

   write_comm(0xF7);
   write_data(0x20);

   write_comm(0xC0); //Power control
   write_data(0x26); //VRH[5:0]

   write_comm(0xC1); //Power control
   write_data(0x01); //SAP[2:0];BT[3:0]

   write_comm(0xC5); //VCM control
   write_data(0x2b);
   write_data(0x2F);

   write_comm(0xc7);
   write_data(0xc7);

   write_comm(0x3A);
   write_data(0x55);

   write_comm(0x36); // Memory Access Control
   write_data(0x20); // write_data(0x08);

   write_comm(0xB1); // Frame Rate Control
   write_data(0x00);
   write_data(0x18);

   write_comm(0xB6); // Display Function Control
   write_data(0x0a);
   write_data(0xE2);

   write_comm(0xF2); // 3Gamma Function Disable
   write_data(0x00);
   write_comm(0x26); // Gamma curve selected
   write_data(0x01);
   write_comm(0xE0); // Set Gamma
   write_data(0x0f);
   write_data(0x1d);
   write_data(0x1a);
   write_data(0x09);
   write_data(0x0f);
   write_data(0x09);
   write_data(0x46);
   write_data(0x88);
   write_data(0x39);
   write_data(0x05);
   write_data(0x0f);
   write_data(0x03);
   write_data(0x07);
   write_data(0x05);
   write_data(0x00);

   write_comm(0XE1); //Set Gamma
   write_data(0x00);
   write_data(0x22);
   write_data(0x25);
   write_data(0x06);
   write_data(0x10);
   write_data(0x06);
   write_data(0x39);
   write_data(0x22);
   write_data(0x4a);
   write_data(0x0a);
   write_data(0x10);
   write_data(0x0c);
   write_data(0x38);
   write_data(0x3a);
   write_data(0x0F);

   write_comm(0x11); //Exit Sleep
   //   Delay(50000 x 100);
   write_comm(0x29); //display on write_comm(0x2C);
   // Delay ( 50000x 2 );
}


