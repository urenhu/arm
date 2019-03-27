/*****************************************************************************
 * Microchip Graphics Library Demo Application
 * This program shows how to use the Graphics Primitives Layer.
 *****************************************************************************
 * FileName:        MainDemo.c
 * Dependencies:    MainDemo.h
 * Processor:       PIC24
 * Compiler:       	MPLAB C30
 * Linker:          MPLAB LINK30
 * Company:         Microchip Technology Incorporated
 *
 * Software License Agreement
 *
 * Copyright © 2007 Microchip Technology Inc.  All rights reserved.
 * Microchip licenses to you the right to use, modify, copy and distribute
 * Software only when embedded on a Microchip microcontroller or digital
 * signal controller, which is integrated into your product or third party
 * product (pursuant to the sublicense terms in the accompanying license
 * agreement).  
 *
 * You should refer to the license agreement accompanying this Software
 * for additional information regarding your rights and obligations.
 *
 * SOFTWARE AND DOCUMENTATION ARE PROVIDED “AS IS” WITHOUT WARRANTY OF ANY
 * KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY
 * OF MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR
 * PURPOSE. IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR
 * OBLIGATED UNDER CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION,
 * BREACH OF WARRANTY, OR OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT
 * DAMAGES OR EXPENSES INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL,
 * INDIRECT, PUNITIVE OR CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA,
 * COST OF PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY
 * CLAIMS BY THIRD PARTIES (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF),
 * OR OTHER SIMILAR COSTS.
 *
 * Author               Date        Comment
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Anton Alkhimenok		30/05/07	...
 *****************************************************************************/


#if defined(__dsPIC33F__)
#include "p33Fxxxx.h"
#elif defined(__PIC24H__)
#include "p24Hxxxx.h"
#elif defined(__PIC30F__)
#include "p30Hxxxx.h"
#elif defined(__PIC24F__)
#include <p24Fxxxx.h>
#endif

#include "MainDemo.h"

// Configuration bits
#if defined(__PIC24H__)
_FOSCSEL(FNOSC_PRIPLL);
_FOSC(FCKSM_CSDCMD & OSCIOFNC_ON & POSCMD_EC);
_FWDT(FWDTEN_OFF);
_FPOR(FPWRT_PWR1);
#endif

#if defined(__PIC24F__)
_CONFIG2(FNOSC_PRIPLL & POSCMOD_XT) // Primary XT OSC with PLL
_CONFIG1(JTAGEN_OFF & FWDTEN_OFF)   // JTAG off, watchdog timer off
#endif

///////////////////////////////// FONTS ///////////////////////////////////////
extern FONT_FLASH Font25;
extern FONT_FLASH Font35;


/////////////////////////////// PICTURES //////////////////////////////////////
extern BITMAP_FLASH flower16bit;
extern BITMAP_FLASH flower8bit;
extern BITMAP_FLASH flower4bit;
extern BITMAP_FLASH flower1bit;

const SHORT polyPoints[] = {
160,60,
240,120,
160,180,
80,120,
160,60,
};

#define WAIT() { DelayMs(100); SetColor(BLACK); ClearDevice(); }

int main(void){
SHORT width, height;
SHORT counter;
SHORT i, j;


// Using external clock at 4MHz
// Configure Oscillator to operate the device at 40Mhz
// Fosc= Fin*M/(N1*N2), Fcy=Fosc/2
// Fosc= 4M*80/(2*2)=80Mhz for 4M input clock

  OSCCONbits.COSC = 3;		/* Primary oscilator with PLL, EC is 4Mhz */
	PLLFBD=78;					// M=80
	CLKDIVbits.ROI = 0;			/* Interrupts have no effect on the DOZEN bit 	*/
	CLKDIVbits.DOZE = 0;		/* Device clock is cpu clock 					*/
	CLKDIVbits.DOZEN = 0;		/* Device clock is cpu clock 					*/
	CLKDIVbits.FRCDIV = 0;		/* Don't care since external clock				*/
	CLKDIVbits.PLLPOST=1;		// N1=2
	CLKDIVbits.PLLPRE=0;		// N2=2
//	OSCTUN=0;					// Tune FRC oscillator, if FRC is used

// Disable Watch Dog Timer
	RCONbits.SWDTEN=0;
// Wait for PLL to lock
	while(OSCCONbits.LOCK!=1) {};


    InitGraph();

    while(1){

		  SetColor(WHITE);
		  // put pixel to see if we can set every pixel
		  for (i = 0; i < GetMaxX(); i++)
		    for(j = 0; j< GetMaxY(); j++)
		    {
		      PutPixel(i, j);
		    }
		    
        WAIT();
        SetColor(WHITE);
        for(counter=0; counter<GetMaxX(); counter+=20){
            Line(counter,0,GetMaxX()-1-counter,GetMaxY()-1);
        }

        WAIT();
        
        SetColor(BRIGHTRED);
        for(counter=5; counter<GetMaxY()>>1; counter+=5){
            Circle(GetMaxX()>>1,GetMaxY()>>1,counter);
        }

        WAIT();
        
        SetColor(BRIGHTBLUE);
        FillCircle(GetMaxX()>>1,GetMaxY()>>1,25);
        WAIT();
        
        SetColor(WHITE);
        FillCircle(GetMaxX()>>1,GetMaxY()>>1,15);
        WAIT();
        
        SetColor(BRIGHTRED);
        FillCircle(GetMaxX()>>1,GetMaxY()>>1,10);
        WAIT();

        SetColor(BRIGHTBLUE);
        Bevel((GetMaxX()>>1)-10,(GetMaxY()>>1)-10,(GetMaxX()>>1)+10,(GetMaxY()>>1)+10,10);
        WAIT();
       
         SetColor(BRIGHTBLUE);
        Arc((GetMaxX()>>1)-10,(GetMaxY()>>1)-10,(GetMaxX()>>1)+10,(GetMaxY()>>1)+10,20,30,0xFF);
        WAIT();
   
        SetColor(BRIGHTGREEN);
        FillBevel((GetMaxX()>>1)-20,(GetMaxY()>>1)-20,(GetMaxX()>>1)+20,(GetMaxY()>>1)+10,10);
        WAIT();
        
        SetColor(BRIGHTBLUE);
        Arc((GetMaxX()>>1),(GetMaxY()>>1)-10,(GetMaxX()>>1),(GetMaxY()>>1)+10,10,10,0x11);
        WAIT();
    
        SetColor(BRIGHTBLUE);

        for(counter=0; counter<GetMaxY()>>1; counter+=5){
            Rectangle(GetMaxX()/2-counter,
                      GetMaxY()/2-counter,
                      GetMaxX()/2+counter,
                      GetMaxY()/2+counter);
        }

        WAIT();
        
        SetColor(BRIGHTBLUE);
        Bar(GetMaxX()/2-20,GetMaxY()/2-20, GetMaxX()/2+20,GetMaxY()/2+20);
        WAIT();
        
        SetColor(BRIGHTGREEN);
        Bar(GetMaxX()/2-10,GetMaxY()/2-10,GetMaxX()/2+10,GetMaxY()/2+10);
        WAIT();
        
        SetColor(BRIGHTRED);
        Bar(GetMaxX()/2-5,GetMaxY()/2-5,
            GetMaxX()/2+5,GetMaxY()/2+5);
        WAIT();

        SetColor(WHITE);
        DrawPoly(5,(SHORT*)polyPoints);
        WAIT();


        SetFont(&Font25);
        SetColor(BRIGHTGREEN);
        width = GetTextWidth("Rocketdawg.",&Font25);
        height = GetTextHeight(&Font25);

        OutTextXY( (GetMaxX()-width)>>1,
                   (GetMaxY()-height)>>1,
                    "Rocketdawg.");

        WAIT();

        SetFont(&Font35);
        SetColor(WHITE);
        width = GetTextWidth("Rocketdawg.",&Font35);
        height = GetTextHeight(&Font35);

        OutTextXY( (GetMaxX()-width)>>1,
                   (GetMaxY()-height)>>1,
                    "Rocketdawg.");

        WAIT();
        SetFont(&Font25);
        PutImage(0,0,&flower1bit,2);
        SetColor(WHITE);
        OutTextXY(10,0,"1BPP");
        WAIT();

        PutImage(0,0,&flower4bit,2);
        SetColor(WHITE);
        OutTextXY(10,0,"4BPP");
        WAIT();

        PutImage(0,0,&flower8bit,2);
        SetColor(WHITE);
        OutTextXY(10,0,"8BPP");
        WAIT();

        PutImage(0,0,&flower16bit,2);
        SetColor(WHITE);
        OutTextXY(10,0,"16BPP");
        WAIT();

        PutImage(84,0,&flower1bit,1);
        PutImage(169,0,&flower4bit,1);
        PutImage(84,114,&flower8bit,1);
        PutImage(169,114,&flower16bit,1);
        WAIT();
    } 

}
