
#include "tft.h"

#define FONT_SPACE 6
#define FONT_X 8
#define FONT_Y 8

void TFT::sendCMD(unsigned char index)
{
    TFT_DC_LOW;
    TFT_CS_LOW;
    SPI.transfer(index);
    TFT_CS_HIGH;
}

void TFT::WRITE_DATA(unsigned char data)
{
    TFT_DC_HIGH;
    TFT_CS_LOW;
    SPI.transfer(data);
    TFT_CS_HIGH;
}

void TFT::sendData(unsigned short int data)
{
    unsigned char data1 = data>>8;
    unsigned char data2 = data&0xff;
    TFT_DC_HIGH;
    TFT_CS_LOW;
    SPI.transfer(data1);
    SPI.transfer(data2);
    TFT_CS_HIGH;
}

void TFT::WRITE_Package(unsigned short int *data, unsigned char howmany)
{
    unsigned short int    data1 = 0;
    unsigned char   data2 = 0;

    TFT_DC_HIGH;
    TFT_CS_LOW;
    unsigned char count=0;
    for (count=0;count<howmany;count++) {
        data1 = data[count]>>8;
        data2 = data[count]&0xff;
        SPI.transfer(data1);
        SPI.transfer(data2);
    }
    TFT_CS_HIGH;
}

unsigned char TFT::Read_Register(unsigned char Addr, unsigned char xParameter)
{
    unsigned char data=0;

    sendCMD(0xd9);                                                      /* ext command                  */
    WRITE_DATA(0x10+xParameter);                                        /* 0x11 is the first Parameter  */
    TFT_DC_LOW;
    TFT_CS_LOW;
    SPI.transfer(Addr);
    TFT_DC_HIGH;
    data = SPI.transfer(0);
    TFT_CS_HIGH;
    return data;
}

void TFT::TFTinit (void)
{
    SPI.begin();
    TFT_CS_HIGH;
    TFT_DC_HIGH;
    unsigned char i=0, TFTDriver=0;

    TFT_RST_ON;
    delay(10);
    TFT_RST_OFF;

    for (i=0;i<3;i++) {
        TFTDriver = readID();
    }

    sendCMD(0xCB);  
    WRITE_DATA(0x39); 
    WRITE_DATA(0x2C); 
    WRITE_DATA(0x00); 
    WRITE_DATA(0x34); 
    WRITE_DATA(0x02); 

    sendCMD(0xCF);  
    WRITE_DATA(0x00); 
    WRITE_DATA(0XC1); 
    WRITE_DATA(0X30); 

    sendCMD(0xE8);  
    WRITE_DATA(0x85); 
    WRITE_DATA(0x00); 
    WRITE_DATA(0x78); 

    sendCMD(0xEA);  
    WRITE_DATA(0x00); 
    WRITE_DATA(0x00); 

    sendCMD(0xED);  
    WRITE_DATA(0x64); 
    WRITE_DATA(0x03); 
    WRITE_DATA(0X12); 
    WRITE_DATA(0X81); 

    sendCMD(0xF7);  
    WRITE_DATA(0x20); 

    sendCMD(0xC0);      //Power control 
    WRITE_DATA(0x23);       //VRH[5:0] 

    sendCMD(0xC1);      //Power control 
    WRITE_DATA(0x10);       //SAP[2:0];BT[3:0] 

    sendCMD(0xC5);      //VCM control 
    WRITE_DATA(0x3e);       //Contrast
    WRITE_DATA(0x28); 

    sendCMD(0xC7);      //VCM control2 
    WRITE_DATA(0x86);    //--

    sendCMD(0x36);      // Memory Access Control 
    WRITE_DATA(0x48);   //C8	   //48 68???//28 E8 ???

    sendCMD(0x3A);    
    WRITE_DATA(0x55); 

    sendCMD(0xB1);    
    WRITE_DATA(0x00);  
    WRITE_DATA(0x18); 

    sendCMD(0xB6);      // Display Function Control 
    WRITE_DATA(0x08); 
    WRITE_DATA(0x82);
    WRITE_DATA(0x27);  

    sendCMD(0xF2);      // 3Gamma Function Disable 
    WRITE_DATA(0x00); 

    sendCMD(0x26);      //Gamma curve selected 
    WRITE_DATA(0x01); 

    sendCMD(0xE0);      //Set Gamma 
    WRITE_DATA(0x0F); 
    WRITE_DATA(0x31); 
    WRITE_DATA(0x2B); 
    WRITE_DATA(0x0C); 
    WRITE_DATA(0x0E); 
    WRITE_DATA(0x08); 
    WRITE_DATA(0x4E); 
    WRITE_DATA(0xF1); 
    WRITE_DATA(0x37); 
    WRITE_DATA(0x07); 
    WRITE_DATA(0x10); 
    WRITE_DATA(0x03); 
    WRITE_DATA(0x0E); 
    WRITE_DATA(0x09); 
    WRITE_DATA(0x00); 

    sendCMD(0XE1);      //Set Gamma 
    WRITE_DATA(0x00); 
    WRITE_DATA(0x0E); 
    WRITE_DATA(0x14); 
    WRITE_DATA(0x03); 
    WRITE_DATA(0x11); 
    WRITE_DATA(0x07); 
    WRITE_DATA(0x31); 
    WRITE_DATA(0xC1); 
    WRITE_DATA(0x48); 
    WRITE_DATA(0x08); 
    WRITE_DATA(0x0F); 
    WRITE_DATA(0x0C); 
    WRITE_DATA(0x31); 
    WRITE_DATA(0x36); 
    WRITE_DATA(0x0F); 

    sendCMD(0x11);      //Exit Sleep 
    delay(120); 

    sendCMD(0x29);    //Display on 
    sendCMD(0x2c);   
    fillScreen();
}

unsigned char TFT::readID(void)
{
    unsigned char i=0;
    unsigned char data[3] ;
    unsigned char ID[3] = {0x00, 0x93, 0x41};
    unsigned char ToF=1;
    for (i=0;i<3;i++) {
        data[i]=Read_Register(0xd3,i+1);
        if (data[i] != ID[i]) {
            ToF=0;
        }
    }
    if (!ToF) {                                                            /* data!=ID                     */
        Serial.print("Read TFT ID failed, ID should be 0x09341, but read ID = 0x");
        for (i=0;i<3;i++) {
            Serial.print(data[i],HEX);
        }
        Serial.println();
    }
    return ToF;
}

void TFT::setCol(unsigned short int StartCol,unsigned short int EndCol)
{
    sendCMD(0x2A);                                                      /* Column Command address       */
    sendData(StartCol);
    sendData(EndCol);
}

void TFT::setPage(unsigned short int StartPage,unsigned short int EndPage)
{
    sendCMD(0x2B);                                                      /* Column Command address       */
    sendData(StartPage);
    sendData(EndPage);
}

void TFT::fillScreen(unsigned short int XL, unsigned short int XR, unsigned short int YU, unsigned short int YD, unsigned short int color)
{
    unsigned long  XY=0;
    unsigned long i=0;

    if (XL > XR) {
        XL = XL^XR;
        XR = XL^XR;
        XL = XL^XR;
    }
    if (YU > YD) {
        YU = YU^YD;
        YD = YU^YD;
        YU = YU^YD;
    }
    XL = constrain(XL, MIN_X,MAX_X);
    XR = constrain(XR, MIN_X,MAX_X);
    YU = constrain(YU, MIN_Y,MAX_Y);
    YD = constrain(YD, MIN_Y,MAX_Y);

    XY = (XR-XL+1);
    XY = XY*(YD-YU+1);

    Tft.setCol(XL,XR);
    Tft.setPage(YU, YD);
    Tft.sendCMD(0x2c);                                                  /* start to write to display ra */
                                                                        /* m                            */

    TFT_DC_HIGH;
    TFT_CS_LOW;

    unsigned char Hcolor = color>>8;
    unsigned char Lcolor = color&0xff;
    for (i=0; i < XY; i++) {
        SPI.transfer(Hcolor);
        SPI.transfer(Lcolor);
    }

    TFT_CS_HIGH;
}

void TFT::fillScreen(void)
{
    Tft.setCol(0, 239);
    Tft.setPage(0, 319);
    Tft.sendCMD(0x2c);                                                  /* start to write to display ra */

    TFT_DC_HIGH;
    TFT_CS_LOW;
    for (unsigned short int i=0; i<38400; i++) {
        SPI.transfer(0);
        SPI.transfer(0);
        SPI.transfer(0);
        SPI.transfer(0);
    }
    TFT_CS_HIGH;
}

void TFT::setXY(unsigned short int poX, unsigned short int poY)
{
    setCol(poX, poX);
    setPage(poY, poY);
    sendCMD(0x2c);
}

void TFT::setPixel(unsigned short int poX, unsigned short int poY,unsigned short int color)
{
    setXY(poX, poY);
    sendData(color);
}

void TFT::drawChar( unsigned char ascii, unsigned short int poX, unsigned short int poY,unsigned short int size, unsigned short int fgcolor)
{
    if ((ascii>=32)&&(ascii<=127)) {
        ;
    } else {
        ascii = '?'-32;
    }
    for (int i =0; i<FONT_X; i++ ) {
        unsigned char temp = pgm_read_byte(&simpleFont[ascii-0x20][i]);
        for (unsigned char f=0;f<8;f++) {
            if ((temp>>f)&0x01) {
                fillRectangle(poX+i*size, poY+f*size, size, size, fgcolor);
            }

        }

    }
}

void TFT::drawString(char *string,unsigned short int poX, unsigned short int poY, unsigned short int size,unsigned short int fgcolor)
{
    while (*string) {
        drawChar(*string, poX, poY, size, fgcolor);
        *string++;

        if (poX < MAX_X) {
            poX += FONT_SPACE*size;                                     /* Move cursor right            */
        }
    }
}

//fillRectangle(poX+i*size, poY+f*size, size, size, fgcolor);
void TFT::fillRectangle(unsigned short int poX, unsigned short int poY, unsigned short int length, unsigned short int width, unsigned short int color)
{
    fillScreen(poX, poX+length, poY, poY+width, color);
}

void  TFT::drawHorizontalLine( unsigned short int poX, unsigned short int poY,
                               unsigned short int length,unsigned short int color)
{
    setCol(poX,poX + length);
    setPage(poY,poY);
    sendCMD(0x2c);
    for (int i=0; i<length; i++)
        sendData(color);
}

void TFT::drawLine( unsigned short int x0,unsigned short int y0,unsigned short int x1, unsigned short int y1,unsigned short int color)
{

    int x = x1-x0;
    int y = y1-y0;
    int dx = abs(x), sx = x0<x1 ? 1 : -1;
    int dy = -abs(y), sy = y0<y1 ? 1 : -1;
    int err = dx+dy, e2;                                                /* error value e_xy             */
    for (;;) {                                                           /* loop                         */
        setPixel(x0,y0,color);
        e2 = 2*err;
        if (e2 >= dy) {                                                 /* e_xy+e_x > 0                 */
            if (x0 == x1) break;
            err += dy; x0 += sx;
        }
        if (e2 <= dx) {                                                 /* e_xy+e_y < 0                 */
            if (y0 == y1) break;
            err += dx; y0 += sy;
        }
    }

}

void TFT::drawVerticalLine( unsigned short int poX, unsigned short int poY, unsigned short int length,unsigned short int color)
{
    setCol(poX,poX);
    setPage(poY,poY+length);
    sendCMD(0x2c);
    for (int i=0; i<length; i++)
        sendData(color);
}

void TFT::drawRectangle(unsigned short int poX, unsigned short int poY, unsigned short int length, unsigned short int width,unsigned short int color)
{
    drawHorizontalLine(poX, poY, length, color);
    drawHorizontalLine(poX, poY+width, length, color);
    drawVerticalLine(poX, poY, width,color);
    drawVerticalLine(poX + length, poY, width,color);

}

void TFT::drawCircle(int poX, int poY, int r,unsigned short int color)
{
    int x = -r, y = 0, err = 2-2*r, e2;
    do {
        setPixel(poX-x, poY+y,color);
        setPixel(poX+x, poY+y,color);
        setPixel(poX+x, poY-y,color);
        setPixel(poX-x, poY-y,color);
        e2 = err;
        if (e2 <= y) {
            err += ++y*2+1;
            if (-x == y && e2 <= x) e2 = 0;
        }
        if (e2 > x) err += ++x*2+1;
    } while (x <= 0);
}

void TFT::fillCircle(int poX, int poY, int r,unsigned short int color)
{
    int x = -r, y = 0, err = 2-2*r, e2;
    do {

        drawVerticalLine(poX-x, poY-y, 2*y, color);
        drawVerticalLine(poX+x, poY-y, 2*y, color);

        e2 = err;
        if (e2 <= y) {
            err += ++y*2+1;
            if (-x == y && e2 <= x) e2 = 0;
        }
        if (e2 > x) err += ++x*2+1;
    } while (x <= 0);

}

void TFT::drawTraingle( int poX1, int poY1, int poX2, int poY2, int poX3, int poY3, unsigned short int color)
{
    drawLine(poX1, poY1, poX2, poY2,color);
    drawLine(poX1, poY1, poX3, poY3,color);
    drawLine(poX2, poY2, poX3, poY3,color);
}

unsigned char TFT::drawNumber(long long_num,unsigned short int poX, unsigned short int poY,unsigned short int size,unsigned short int fgcolor)
{
    unsigned char char_buffer[10] = "";
    unsigned char i = 0;
    unsigned char f = 0;

    if (long_num < 0) {
        f=1;
        drawChar('-',poX, poY, size, fgcolor);
        long_num = -long_num;
        if (poX < MAX_X) {
            poX += FONT_SPACE*size;                                     /* Move cursor right            */
        }
    } else if (long_num == 0) {
        f=1;
        drawChar('0',poX, poY, size, fgcolor);
        return f;
        if (poX < MAX_X) {
            poX += FONT_SPACE*size;                                     /* Move cursor right            */
        }
    }


    while (long_num > 0) {
        char_buffer[i++] = long_num % 10;
        long_num /= 10;
    }

    f = f+i;
    for (; i > 0; i--) {
        drawChar('0'+ char_buffer[i - 1],poX, poY, size, fgcolor);
        if (poX < MAX_X) {
            poX+=FONT_SPACE*size;                                       /* Move cursor right            */
        }
    }
    return f;
}

unsigned char TFT::drawFloat(float floatNumber,unsigned char decimal,unsigned short int poX, unsigned short int poY,unsigned short int size,unsigned short int fgcolor)
{
    unsigned short int temp=0;
    float decy=0.0;
    float rounding = 0.5;
    unsigned char f=0;
    if (floatNumber<0.0) {
        drawChar('-',poX, poY, size, fgcolor);
        floatNumber = -floatNumber;
        if (poX < MAX_X) {
            poX+=FONT_SPACE*size;                                       /* Move cursor right            */
        }
        f =1;
    }
    for (unsigned char i=0; i<decimal; ++i) {
        rounding /= 10.0;
    }
    floatNumber += rounding;

    temp = (unsigned short int)floatNumber;
    unsigned char howlong=drawNumber(temp,poX, poY, size, fgcolor);
    f += howlong;
    if ((poX+8*size*howlong) < MAX_X) {
        poX+=FONT_SPACE*size*howlong;                                   /* Move cursor right            */
    }

    if (decimal>0) {
        drawChar('.',poX, poY, size, fgcolor);
        if (poX < MAX_X) {
            poX+=FONT_SPACE*size;                                       /* Move cursor right            */
        }
        f +=1;
    }
    decy = floatNumber-temp;                                            /* decimal part,  4             */
    for (unsigned char i=0;i<decimal;i++) {
        decy *=10;                                                      /* for the next decimal         */
        temp = decy;                                                    /* get the decimal              */
        drawNumber(temp,poX, poY, size, fgcolor);
        floatNumber = -floatNumber;
        if (poX < MAX_X) {
            poX+=FONT_SPACE*size;                                       /* Move cursor right            */
        }
        decy -= temp;
    }
    f +=decimal;
    return f;
}

unsigned char TFT::drawFloat(float floatNumber,unsigned short int poX, unsigned short int poY,unsigned short int size,unsigned short int fgcolor)
{
    unsigned char decimal=2;
    unsigned short int temp=0;
    float decy=0.0;
    float rounding = 0.5;
    unsigned char f=0;
    if (floatNumber<0.0) {                                                 /* floatNumber < 0              */
        drawChar('-',poX, poY, size, fgcolor);                          /* add a '-'                    */
        floatNumber = -floatNumber;
        if (poX < MAX_X) {
            poX+=FONT_SPACE*size;                                       /* Move cursor right            */
        }
        f =1;
    }
    for (unsigned char i=0; i<decimal; ++i) {
        rounding /= 10.0;
    }
    floatNumber += rounding;

    temp = (unsigned short int)floatNumber;
    unsigned char howlong=drawNumber(temp,poX, poY, size, fgcolor);
    f += howlong;
    if ((poX+8*size*howlong) < MAX_X) {
        poX+=FONT_SPACE*size*howlong;                                   /* Move cursor right            */
    }


    if (decimal>0) {
        drawChar('.',poX, poY, size, fgcolor);
        if (poX < MAX_X) {
            poX += FONT_SPACE*size;                                     /* Move cursor right            */
        }
        f +=1;
    }
    decy = floatNumber-temp;                                            /* decimal part,                */
    for (unsigned char i=0;i<decimal;i++) {
        decy *=10;                                                      /* for the next decimal         */
        temp = decy;                                                    /* get the decimal              */
        drawNumber(temp,poX, poY, size, fgcolor);
        floatNumber = -floatNumber;
        if (poX < MAX_X) {
            poX += FONT_SPACE*size;                                     /* Move cursor right            */
        }
        decy -= temp;
    }
    f += decimal;
    return f;
}

// TFT Tft = TFT();