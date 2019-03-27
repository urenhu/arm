

/**************************************************************************************
* ��    ��: 
* ��    ��:
* ��    ��:
* �� �� ֵ:
*
* �޸���ʷ:
*   �汾    ����     ����     
*   ----------------------------------------------------
*   1.0   2008.5.3  ���ݽ�       www.http://shop35330111.taobao.com
**************************************************************************************/
uchar spi_send(uchar out_data)
 {
    SPDR=out_data;         //spi���
    while((SPSR&0x80)==0);
    SPSR=0;
	return SPDR;	  
 }/*	   
 uchar spi_send(uchar out_data)
 {
 	uchar i,n;
 	for(i=0;i<8;i++)
	{
		n<<=1;
		SCK=0;
		MOSI=(out_data&0x80);
		if(MISO)	n++;
		SCK=1;
		out_data<<=1;
	}
	return n;  
 } */
/**************************************************************************************
* ��    ��: 
* ��    ��:
* ��    ��:
* �� �� ֵ:
*
* �޸���ʷ:
*   �汾    ����     ����     
*   ----------------------------------------------------
*   1.0   2008.5.3  ���ݽ�       www.http://shop35330111.taobao.com
**************************************************************************************/
void send_command(uchar out_data)              
{
	CS=0;
	spi_send(0x70);
	spi_send(0x00);
	spi_send(out_data);
	CS=1;
}

/**************************************************************************************
* ��    ��: 
* ��    ��:
* ��    ��:
* �� �� ֵ:
*
* �޸���ʷ:
*   �汾    ����     ����     
*   ----------------------------------------------------
*   1.0   2008.5.3  ���ݽ�       www.http://shop35330111.taobao.com
**************************************************************************************/
void send_data(uint out_data)           
{
	CS=0;
	spi_send(0x72);
	spi_send(out_data>>8);
	spi_send(out_data);
	CS=1;
}
/**************************************************************************************
* ��    ��: 
* ��    ��:
* ��    ��:
* �� �� ֵ:
*
* �޸���ʷ:
*   �汾    ����     ����     
*   ----------------------------------------------------
*   1.0   2008.5.3  ���ݽ�       www.http://shop35330111.taobao.com
**************************************************************************************/
void write_com(uchar address,uint num)
{
    send_command(address);
    send_data(num);;
}
/**************************************************************************************
* ��    ��: 
* ��    ��:
* ��    ��:
* �� �� ֵ:
*
* �޸���ʷ:
*   �汾    ����     ����     
*   ----------------------------------------------------
*   1.0   2008.5.3  ���ݽ�       www.http://shop35330111.taobao.com
**************************************************************************************/
void lcd_init(void)
{
	write_com(0x0001,0x0100);				//Driver Output Contral Register 
   	write_com(0x0002,0x0700);    //0x0701	//LCD Driving Waveform Contral
  	write_com(0x0003,0x1030);				//Entry Mode����
  												//ָ������������϶��µ��Զ���ģʽ
  												//Normal Mode(Window Mode disable)
  												//RGB��ʽ
  												//16λ����2�δ����8��������
   	write_com(0x0004,0x0000);				//Scalling Control register
   	write_com(0x0008,0x0207);				//Display Control 2
   	write_com(0x0009,0x0000);				//Display Control 3
   	write_com(0x000A,0x0000);				//Frame Cycle Control
   	write_com(0x000C,0x0000);				//External Display Interface Control 1
    write_com(0x000D,0x0000);				//Frame Maker Position
   	write_com(0x000F,0x0000);				//External Display Interface Control 2
   	DelayNS(1000);
   	write_com(0x0007,0x0101);				//Display Control
   	DelayNS(1000);
   	write_com(0x0010,0x16B0);    //0x14B0	//Power Control 1
   	write_com(0x0011,0x0001);    //0x0007	//Power Control 2
   	write_com(0x0017,0x0001);    //0x0000	//Power Control 3
   	write_com(0x0012,0x0138);    //0x013B	//Power Control 4
   	write_com(0x0013,0x0800);    //0x0800	//Power Control 5
   	write_com(0x0029,0x0009);				//NVM read data 2
   	write_com(0x002a,0x0009);				//NVM read data 3
   	write_com(0x00a4,0x0000);

   	write_com(0x0050,0x0000);				//���ò������ڵ�X�Ὺʼ��
   	write_com(0x0051,0x00EF);				//���ò������ڵ�X�������
   	write_com(0x0052,0x0000);				//���ò������ڵ�Y�Ὺʼ��
   	write_com(0x0053,0x013F);				//���ò������ڵ�Y�������
   	write_com(0x0060,0x2700);				//Driver Output Control
   												//������Ļ�ĵ����Լ�ɨ�����ʼ��
   	write_com(0x0061,0x0001);				//Driver Output Control
   	write_com(0x006A,0x0000);				//Vertical Scroll Control
   	//-------------- Partial Display Control ---------//
   	write_com(0x0080,0x0000);				//Display Position �C Partial Display 1
   	write_com(0x0081,0x0000);				//RAM Address Start �C Partial Display 1
   	write_com(0x0082,0x0000);				//RAM address End - Partial Display 1
   	write_com(0x0083,0x0000);				//Display Position �C Partial Display 2
   	write_com(0x0084,0x0000);				//RAM Address Start �C Partial Display 2
   	write_com(0x0085,0x0000);				//RAM address End �C Partail Display2
	//-------------- Panel Control -------------------//
   	write_com(0x0090,0x0013);				//Frame Cycle Control
   	write_com(0x0092,0x0000);				//Panel Interface Control 2
   	write_com(0x0093,0x0003);				//Panel Interface control 3
   	write_com(0x0095,0x0110);				//Frame Cycle Control
	write_com(0x97, 0x0000);
    write_com(0x98, 0x0000);

   	write_com(0x0007,0x0173);
}

/**************************************************************************************
* ��    ��: DispOneColor
* ��    ��: ȫ����ʾĳ����ɫ
* ��    ��: Color   : ��ɫֵ
* �� �� ֵ: ��
*
* �޸���ʷ:
*   �汾    ����     ����     
*   ----------------------------------------------------
*   1.0   2008.5.3  ���ݽ�       www.http://shop35330111.taobao.com
**************************************************************************************/
void DispOneColor(uint Color)
{
    int i,j;
    write_com(0x0021,0);        //����ַ0
    write_com(0x0020,0);        //����ַ0
    send_command(0x22);
    for(j=0;j<320;j++)
        for(i=0;i<240;i++)
            send_data(Color);
}
/**************************************************************************************
* ��    ��: DispClear
* ��    ��: �����ʾ������ʾ����
* ��    ��: ��
* �� �� ֵ: ��
*
* �޸���ʷ:
*   �汾    ����     ����     
*   ----------------------------------------------------
*   1.0   2008.5.3  ���ݽ�       www.http://shop35330111.taobao.com
**************************************************************************************/
void DispClear(void)
{
    DispOneColor(BLACK);
}
//==============================================
void Set_ramaddr(uint x,uint y)
{
    write_com(0x0021,y);        //����ַ
	write_com(0x0020,x);        //����ַ
}/**************************************************************************************
* ��    ��: DrawSingleAscii
* ��    ��: ��ָ����λ�õ����ַ�
* ��    ��: x           : x����
*                       y         : y����
*               LineColor : �ַ�����ɫ
*           FillColor   : �ַ�������ɫ
* �� �� ֵ: ��
*
* �޸���ʷ:
*   �汾    ����     ����     
*   ----------------------------------------------------
*   1.0   2008.5.3  ���ݽ�       www.http://shop35330111.taobao.com
**************************************************************************************/
void DrawSingleAscii(uint x, uint y, uchar *pAscii, uint LineColor,uint FillColor, uchar Mod)
{
    uchar i, j;
    uchar str;
    uint OffSet;

    OffSet = (*pAscii - 32)*16;

    for (i=0;i<16;i++)
    {
        Set_ramaddr(x,y+i);
        send_command(0x22);
        str = *(AsciiLib + OffSet + i);  
        for (j=0;j<8;j++)
        {
            if ( str & (0x80>>j) )     //0x80>>j
            {
                send_data((uint)(LineColor&0xffff));
            }
            else
            {
                if (NORMAL == Mod) 
                    send_data((uint)(FillColor&0xffff));
                else
                {
                    Set_ramaddr(x+j+1,y+i);
                    send_command(0x22);  
                }
            }               
        } 
    }
}
/**************************************************************************************
* ��    ��: DrawSingleHz
* ��    ��: ��ָ����λ����ʾ����
* ��    ��: x           : x����
*                       y       : y����
*               LineColor : ���ֵ���ɫ
*           FillColor   : ���ֱ�����ɫ
* �� �� ֵ: ��
*
* �޸���ʷ:
*   �汾    ����     ����     
*   ----------------------------------------------------
*   1.0   2008.5.3  ���ݽ�       www.http://shop35330111.taobao.com
**************************************************************************************/
void DrawSingleHz(uint x, uint y, uchar *pHz, uint LineColor,uint FillColor, uchar Mod)
{
uint j=0,i=0,k=0;
uint str,len;
//---------------------------ͳ���Ƿ����ֿ��г��� 
len=sizeof(HzLib)/sizeof(HzLib[0]);
for(j=0;j<sizeof(HzLib)/sizeof(HzLib[0]);j++)   
    if((uchar)HzLib[j].Index[0]==pHz[0]&&(uchar)HzLib[j].Index[1]==pHz[1])break;
//--------------------------      
    if(j<len)
    {
        for (i=0;i<HZ_column;i++)
        {
            Set_ramaddr(x,y+i);
            send_command(0x22);

            str = (uchar)HzLib[j].Msk[i*2]<<8|(uchar)HzLib[j].Msk[i*2+1]; 

            for (k=0;k<HZ_column;k++)
            {
                if ( str & (0x8000>>k) )     //0x8000>>k
                {
                    send_data((uint)(LineColor&0xffff));
                }
                else
                {
                    if (NORMAL == Mod) 
                        send_data((uint)(FillColor&0xffff));
                    else
                    {
                        Set_ramaddr(x+k+1,y+i);
                        send_command(0x22);  
                    }
                }               
            } 
        }
    }
}

/**************************************************************************************
* ��    ��: DrawString
* ��    ��: ��ָ����λ����ʾ����ַ�
* ��    ��: x           : x����
*                       y         : y����
*               LineColor : �ַ�����ɫ
*           FillColor   : �ַ�������ɫ
* �� �� ֵ: ��
*
* �޸���ʷ:
*   �汾    ����     ����     
*   ----------------------------------------------------
*   1.0   2008.5.3  ���ݽ�       www.http://shop35330111.taobao.com
**************************************************************************************/
void DrawString(uint x, uint y, uchar *pStr, uint LineColor,uint FillColor, uchar Mod)
{

    while(1)
    {
        if (*pStr == 0)
        {
            return;
        }

        if (*pStr > 0x80)           //����
        {
            DrawSingleHz(x, y, pStr, LineColor, FillColor, Mod);
            x += HZ_column;
            pStr += 2;              
        }
        else                        //Ӣ���ַ�
        {
            DrawSingleAscii(x, y, pStr, LineColor, FillColor, Mod);
            x += 8;
            pStr += 1;              
        }
    }   
}
//================================= 
void DispNum(unsigned int x, unsigned int y, unsigned short num)
{
    unsigned char str[5];

    str[0] = num/1000+0x30;
    str[1] = (num%1000)/100+0x30;
    str[2] = (num%1000)%100/10+0x30;
    str[3] = (num%1000)%100%10+0x30;
    str[4] = '\0';

    DrawString(x, y, str, RED, YELLOW, NORMAL);
}
/**************************************************************************************
* ��    ��: DispSmallPic
* ��    ��: ��ָ����λ����ʾһ��65Kɫ��ͼƬ
* ��    ��: str     : ͼƬ������
* �� �� ֵ: ��
*
* �޸���ʷ:
*   �汾    ����     ����     
*   ----------------------------------------------------
*   1.0   2008.5.3  ���ݽ�       www.http://shop35330111.taobao.com
**************************************************************************************/
void DispSmallPic(uint x, uint y, uint w, uint h, const uchar *str)
{
    uint i,j,temp;
    for(j=0;j<h;j++)
    {
        Set_ramaddr(x,y+j);
        send_command(0x22); 
        for(i=0;i<w;i++)
        {   //send_data(*(unsigned short *)(&str[(j*w+i)*2]));       //��λ��ǰ
            temp=str[(j*w+i)*2+1]<<8;     //��λ��ǰ
            temp|=str[(j*w+i)*2];
            send_data(temp);
        }
    }
}