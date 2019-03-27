#ifndef TFTv2_h
#define TFTv2_h


//#include <SPI.h>

//Basic Colors
#define RED	               0xf800
#define GREEN              0x07e0
#define BLUE               0x001f
#define BLACK              0x0000
#define YELLOW             0xffe0
#define WHITE              0xffff

//Other Colors
#define CYAN	           0x07ff	
#define BRIGHT_RED         0xf810	
#define GRAY1	           0x8410  
#define GRAY2	           0x4208  

//TFT resolution 240*320
#define MIN_X              0
#define MIN_Y              0
#define MAX_X              239
#define MAX_Y              319

#define TS_MINX            (116*2)
#define TS_MAXX            (890*2)
#define TS_MINY            (83*2)
#define TS_MAXY            (913*2)


class TFT {
public:
    void TFTinit (void);
    void setCol  (unsigned short int StartCol,unsigned short int EndCol);
    void setPage (unsigned short int StartPage,unsigned short int EndPage);
    void setXY(unsigned short int poX, unsigned short int poY);
    void setPixel(unsigned short int poX, unsigned short int poY,unsigned short int color);
    void sendCMD(unsigned char index);
    void WRITE_Package(unsigned short int *data,unsigned char howmany);
    void WRITE_DATA(unsigned char data);
    void sendData(unsigned short int data);
    unsigned char Read_Register(unsigned char Addr,unsigned char xParameter);
    void fillScreen(unsigned short int XL,unsigned short int XR,unsigned short int YU,unsigned short int YD,unsigned short int color);
    void fillScreen(void);
    unsigned char readID(void);

    void drawChar(unsigned char ascii,unsigned short int poX, unsigned short int poY,unsigned short int size, unsigned short int fgcolor);
    void drawString(char *string,unsigned short int poX, unsigned short int poY,unsigned short int size,unsigned short int fgcolor);
    void fillRectangle(unsigned short int poX, unsigned short int poY, unsigned short int length, unsigned short int width, unsigned short int color);

    void drawLine(unsigned short int x0,unsigned short int y0,unsigned short int x1,unsigned short int y1,unsigned short int color);
    void drawVerticalLine(unsigned short int poX, unsigned short int poY,unsigned short int length,unsigned short int color);
    void drawHorizontalLine(unsigned short int poX, unsigned short int poY,unsigned short int length,unsigned short int color);
    void drawRectangle(unsigned short int poX, unsigned short int poY, unsigned short int length,unsigned short int width,unsigned short int color);

    void drawCircle(int poX, int poY, int r,unsigned short int color);
    void fillCircle(int poX, int poY, int r,unsigned short int color);

    void drawTraingle(int poX1, int poY1, int poX2, int poY2, int poX3, int poY3, unsigned short int color);
    unsigned char drawNumber(long long_num,unsigned short int poX, unsigned short int poY,unsigned short int size,unsigned short int fgcolor);
    unsigned char drawFloat(float floatNumber,unsigned char decimal,unsigned short int poX, unsigned short int poY,unsigned short int size,unsigned short int fgcolor);
    unsigned char drawFloat(float floatNumber,unsigned short int poX, unsigned short int poY,unsigned short int size,unsigned short int fgcolor);

};

// extern TFT Tft;

#endif
