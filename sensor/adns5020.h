#ifndef __ADNS5020_H__
#define __ADNS5020_H__

/*
    ADNS_5020 is an introductory optical tracking mouse sensor.

    HARDWARE NOTE: The ADNS_5020 does NOT implement SPI in the standard
    way.  In the psuedo-standard SPI (SPI is not an ISO or IEEE Standard)
    requires 4 wires and is full duplex.

    On the ADNS 5020 the timing is SPI compliant, but the chip
    consolidates the MOSI and MISO pins into a single SDIO (Serial Data
    Input/Output) pin.  Therefore, in order to use the Arduino SPI
    library to handle the communicaiton timing users will have to run two
    wires from the Arduino MOSI and MISO to the same pin on the ADNS 5020.
    Then when the sensor is communicating back to the Arduino, YOU MUST
    TAKE THE MOSI PIN TO INPUT MODE IN ORDER TO TRI-STATE THE PIN AND
    PUT IT IN A HIGH IMPEDENCE STATE.  If this precaution is not 
    taken then the MOSI pin may present a ground for signals coming
    toward it from the sensor.
*/

/**  *
*    http://www.ba0sh1.com/2014/05/31/howto-use-stm32-spi-half-duplex-mode/**
*  tutorial of 3 wire spi mode 
* 
********/
#include "usr_spi.h"

// ADNS5020 uses 3 wire mode spi, so stm32 mosi pin connect to sdio.
// =======================================
// #define ADNS5020_PORT 	        GPIOA

void adns5020_init ();
void adns5020_reset();
int  adns5020_config();
u8   adns5020_dx();
u8   adns5020_dy();
u8   adns5020_squal();
void adns5020_pixels(u8 *buffer); 
u8 adns5020_reg_read(u8 reg) ;

#endif //__ADNS5020_H__ 
