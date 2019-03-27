
#include "usr_sys.h"
#include "usr_delay.h"
//#include "usart.h"
#include "usr_rtc.h" 		    


 _calendar_obj    calendar; 

u8 const     table_week[12] = {0,3,3,6,1,4,6,2,5,0,3,5};
const u8     mon_table[12]  = {31,28,31,30,31,30,31,31,30,31,30,31};


static u8 is_leap_year(u16 year);
static u8 get_week(u16 year,u8 month,u8 day);

 
/*
void set_clock(u16 divx)
{
 	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR | RCC_APB1Periph_BKP, ENABLE);	//使能PWR和BKP外设时钟  
	PWR_BackupAccessCmd(ENABLE);	//使能RTC和后备寄存器访问 

	RTC_EnterConfigMode();/// 允许配置	
 
	RTC_SetPrescaler(divx); //设置RTC预分频的值          									 
	RTC_ExitConfigMode();//退出配置模式  				   		 									  
	RTC_WaitForLastTask();	//等待最近一次对RTC寄存器的写操作完成		 									  
}	   
*/

static void RTC_NVIC_Config(void)
{	
    NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = RTC_IRQn;		//RTC
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	//
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;	//
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;		//
	NVIC_Init(&NVIC_InitStructure);		
}

u8 usrrtc_init(void)
{
	u8 temp=0;
 
	if (BKP_ReadBackupRegister(BKP_DR1) != 0x5050){	 			
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR | RCC_APB1Periph_BKP, ENABLE);	   
		PWR_BackupAccessCmd(ENABLE);	 
		BKP_DeInit(); 	
		RCC_LSEConfig(RCC_LSE_ON);	//(LSE) use lowspeed crystal 
		while (RCC_GetFlagStatus(RCC_FLAG_LSERDY) == RESET)	{
			temp++;
			delay_ms(10);
		}
		if(temp>=250)  return 1;
		
		RCC_RTCCLKConfig(RCC_RTCCLKSource_LSE);	
		RCC_RTCCLKCmd(ENABLE);  
		RTC_WaitForLastTask();
		RTC_WaitForSynchro();  
		RTC_ITConfig(RTC_IT_SEC, ENABLE);
		RTC_WaitForLastTask();
		RTC_EnterConfigMode();   // allow setting 	
		RTC_SetPrescaler(32767); 
		RTC_WaitForLastTask();	
		usrrtc_set(2016,05,24,10,0,55);  // set time 
		RTC_ExitConfigMode();  
		BKP_WriteBackupRegister(BKP_DR1, 0X5050);
	}else {
		RTC_WaitForSynchro();
		RTC_ITConfig(RTC_IT_SEC, ENABLE);	
		RTC_WaitForLastTask();
	}
	RTC_NVIC_Config();
	usrrtc_get();
	return 0; 
}		 				    

// every 1 second occurs ! 
void RTC_IRQHandler(void)
{		 
	if (RTC_GetITStatus(RTC_IT_SEC) != RESET){							
		usrrtc_get();  
 	}
	if(RTC_GetITStatus(RTC_IT_ALR)!= RESET)	{ // alarm 
		RTC_ClearITPendingBit(RTC_IT_ALR);			  	   
  	} 				  								 
	RTC_ClearITPendingBit(RTC_IT_SEC|RTC_IT_OW);
	RTC_WaitForLastTask();	  	    						 	   	 
}


static u8 is_leap_year(u16 year)
{			  
	if(year%4==0){ 
		if(year%100==0) { 
			if(year%400==0) {
				return 1;   
			} else {  
				return 0;
			}				
		} else  {
			return 1;
		}			
	} else { 
		return 0;
	}		
}	 		

u8 usrrtc_set(u16 syear,u8 smon,u8 sday,u8 hour,u8 min,u8 sec)
{
	u16 t;
	u32 seccount=0;
	
	if (syear<1970||syear>2099)return 1;	   
	for (t=1970;t<syear;t++) {
		if(is_leap_year(t))seccount+=31622400;
		else seccount+=31536000;			  
	}
	smon-=1;
	for(t=0;t<smon;t++){
		seccount+=(u32)mon_table[t]*86400;
		if(is_leap_year(syear)&&t==1)
			seccount+=86400;	   
	}
	seccount+=(u32)(sday-1)*86400;
	seccount+=(u32)hour*3600;
	seccount+=(u32)min*60;	 
	seccount+=sec;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR | RCC_APB1Periph_BKP, ENABLE);  // Enable PWR and BKP external clock  
	PWR_BackupAccessCmd(ENABLE);	
	RTC_SetCounter(seccount); // set RTC counter

	RTC_WaitForLastTask();

	return 0;	    
}


u8 usrrtc_get(void)
{
	static u16 daycnt=0;
	u32 timecount=0; 
	u32 temp=0;
	u16 temp1=0;	  
 	
	timecount = RTC->CNTH;
	timecount<<=16;
	timecount += RTC->CNTL;			 
 	temp=timecount/86400;
	if(daycnt!=temp){	  
		daycnt=temp;
		temp1=1970;	
		while(temp>=365){				 
			if(is_leap_year(temp1))	{
				if(temp>=366) {
					temp-=366;
				} else {
					temp1++;
					break;
				}  
			} else {
				temp-=365;	   
			}
			temp1++;  
		}   
		calendar.w_year=temp1; 
		temp1=0;
		while(temp>=28){
			if(is_leap_year(calendar.w_year)&&temp1==1){
				if(temp>=29)temp-=29;
				else 
					break; 
			}else{ 
				if(temp>=mon_table[temp1])
					temp-=mon_table[temp1];
				else 
					break;
			}
			temp1++;  
		}
		calendar.w_month=temp1+1;
		calendar.w_date=temp+1; 
	}
	temp=timecount%86400; 
	calendar.hour=temp/3600;     	
	calendar.min=(temp%3600)/60; 		
	calendar.sec=(temp%3600)%60; 	
	calendar.week=get_week(calendar.w_year,calendar.w_month,calendar.w_date);    
	return 0;
}	 

u8 get_week(u16 year,u8 month,u8 day)
{	
	u16 temp2;
	u8 yearH,yearL;
	
	yearH=year/100;	
	yearL=year%100; 
	if (yearH>19)
		yearL+=100;
	temp2=yearL+yearL/4;
	temp2=temp2%7; 
	temp2=temp2+day+table_week[month-1];
	if (yearL%4==0&&month<3)
		temp2--;
	return(temp2%7);
}			  

