/******************************************************************************
 * @module: usr_delay.c
 ******************************************************************************
**/ 
#include "usr_sys.h"
#include "usr_delay.h"

#if SYSTEM_SUPPORT_UCOS
#include "includes.h"
#endif

////////////////////////////////////////////////////////////////////////////////// 	 
static u8  fac_us=0;
static u16 fac_ms=0;

#ifdef OS_CRITICAL_METHOD
void SysTick_Handler(void)
{				   
  OSIntEnter();
  OSTimeTick();
  OSIntExit();
}
#endif

void delay_init()	 
{
#ifdef OS_CRITICAL_METHOD 	
	u32 reload;
#endif

	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);	//selecting external clock : HCLK/8
	fac_us = SystemCoreClock/8000000;	//为系统时钟的1/8  
	 
#ifdef OS_CRITICAL_METHOD 	//如果OS_CRITICAL_METHOD定义了,说明使用ucosII了.
	reload=SystemCoreClock/8000000;		//每秒钟的计数次数 单位为K	   
	reload*=1000000/OS_TICKS_PER_SEC;//根据OS_TICKS_PER_SEC设定溢出时间
							//reload为24位寄存器,最大值:16777216,在72M下,约合1.86s左右	
	fac_ms=1000/OS_TICKS_PER_SEC;//代表ucos可以延时的最少单位	   
	SysTick->CTRL|=SysTick_CTRL_TICKINT_Msk;   	//开启SYSTICK中断
	SysTick->LOAD=reload; 	//每1/OS_TICKS_PER_SEC秒中断一次	
	SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk;   	//开启SYSTICK    
#else
	fac_ms=(u16)fac_us*1000;  
#endif
}								    

#ifdef OS_CRITICAL_METHOD	//使用了ucos
void delay_us(u32 nus)
{		
	u32 ticks;
	u32 told,tnow,tcnt=0;
	u32 reload=SysTick->LOAD;	//LOAD的值	    	 
	ticks=nus*fac_us; 			//需要的节拍数	  		 
	tcnt=0;
	told=SysTick->VAL;        	//刚进入时的计数器值
	while(1)
	{
		tnow=SysTick->VAL;	
		if(tnow!=told)
		{	    
			if(tnow<told)tcnt+=told-tnow;//这里注意一下SYSTICK是一个递减的计数器就可以了.
			else tcnt+=reload-tnow+told;	    
			told=tnow;
			if(tcnt>=ticks)break;//时间超过/等于要延迟的时间,则退出.
		}  
	}; 									    
}

void delay_ms(u16 nms)
{	
	if(OSRunning==TRUE)//如果os已经在跑了	    
	{		  
		if(nms>=fac_ms)//延时的时间大于ucos的最少时间周期 
		{
   			OSTimeDly(nms/fac_ms);//ucos延时
		}
		nms%=fac_ms;				//ucos已经无法提供这么小的延时了,采用普通方式延时    
	}
	delay_us((u32)(nms*1000));	//普通方式延时,此时ucos无法启动调度.
}

#else

void delay_us(u32 nus)
{		
	u32 temp;	    	 
	
	SysTick->LOAD  = nus*fac_us;    		 
	SysTick->VAL   = 0x00;        
	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk ;	 
	
	do {
		temp=SysTick->CTRL;
	} while(temp&0x01&&!(temp&(1<<16)));
	
	SysTick->CTRL  &= ~SysTick_CTRL_ENABLE_Msk; 
	SysTick->VAL    = 0X00;         
}


void delay_ms(u16 nms)
{	 		  	  
	u32 temp;		   
	SysTick->LOAD=(u32)nms*fac_ms;//时间加载(SysTick->LOAD为24bit)
	SysTick->VAL =0x00;           //清空计数器
	SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk ;          //开始倒数  
	do
	{
		temp=SysTick->CTRL;
	}
	while(temp&0x01&&!(temp&(1<<16)));//等待时间到达   
	SysTick->CTRL&=~SysTick_CTRL_ENABLE_Msk;       //关闭计数器
	SysTick->VAL =0X00;       //清空计数器	  	    
} 
#endif
































