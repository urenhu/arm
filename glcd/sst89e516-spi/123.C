#include <SST89x5x4.h>
#include<stdio.h>
#include<define.h>
#include<asc_zimo.h>
#include<Hz_zimo.h>
#include<meinv1.c>
#include<lcd.c>
#include<touch.c>

																		  

//=================================    
main()
{
    uint T_x = 3;
    uint T_y = 4;
    uchar R_data=0;
	uchar G_data=0;
	uchar B_data=0;
	uint i,j,k=0;

    SPCR=0X5C;                          //4分频，时钟极性高电平，上升边沿触发	
    RES=0;
	DelayNS(1000);
    RES=1;
    //-------------------SPI设置

	lcd_init();
    touch_Init();
	DispOneColor(RED);
    DispClear();        
    send_command(0x22);

	DrawString(0, 70, "触摸测试:", WHITE, BLACK, NORMAL);
    DrawString(0, 152, "Easy Do It!!", RED, YELLOW, NORMAL);
	DrawString(0, 168, "支持各种单片机", RED,YELLOW,TRANSP);
	DrawString(0, 184, "提供Keil C51演示程序",YELLOW,RED,NORMAL);
    DispSmallPic(120, 0, 120, 160, gImage_meinv1);
	//==============================  
 	Set_ramaddr(0,200);
	send_command(0x22);
 	R_data=0;G_data=0;B_data=0;  	
    for(j=0;j<20;j++)//红色渐强条
	{
        for(i=0;i<240;i++)
            {R_data=i/8;send_data(R_data<<11|G_data<<5|B_data);}
	}
    R_data=0x1f;G_data=0x3f;B_data=0x1f;
    for(j=0;j<20;j++)
	{
        for(i=0;i<240;i++)
            {
			G_data=0x3f-(i/4);
			B_data=0x1f-(i/8);
			send_data(R_data<<11|G_data<<5|B_data);}
	}
//----------------------------------
	R_data=0;G_data=0;B_data=0;
    for(j=0;j<20;j++)//绿色渐强条
	{
        for(i=0;i<240;i++)
            {G_data=i/4;send_data(R_data<<11|G_data<<5|B_data);}
	}
    R_data=0x1f;G_data=0x3f;B_data=0x1f;
    for(j=0;j<20;j++)
	{
        for(i=0;i<240;i++)
            {
			R_data=0x1f-(i/8);
			B_data=0x1f-(i/8);
			send_data(R_data<<11|G_data<<5|B_data);}
	}
//----------------------------------
	R_data=0;G_data=0;B_data=0;
    for(j=0;j<20;j++)//蓝色渐强条
	{
        for(i=0;i<240;i++)
            {B_data=i/8;send_data(R_data<<11|G_data<<5|B_data);}
	} 
	B_data=0; 
    R_data=0x1f;G_data=0x3f;B_data=0x1f;
    for(j=0;j<20;j++)
	{
        for(i=0;i<240;i++)
            {
			G_data=0x3f-(i/4);
			R_data=0x1f-(i/8);
			send_data(R_data<<11|G_data<<5|B_data);}
	}						   
 //==============================                
    while(1)
    {   
        if (touch_INT==0)
        {
            touch_GetAdXY(&T_x, &T_y);

            DispNum(20, 90, T_x);
            DispNum(20, 110, T_y);
        }
    }
}
