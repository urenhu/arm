/*
****************************************************************************
 * gpio.c
 *
 * Date       Name        Description
 *
****************************************************************************
*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "menu.h"
#include "gpio.h"
#include "usr_sys.h"
#include "usr_adc.h"
#include "usr_rtc.h"
#include "usr_tsensor.h"



/*============  static functions =================*/
static int open_gpio(void);
static int close_gpio(void);
static int read_gpio (const char *portStr);
static int write_gpio(const char *portStr);
static int read_rtc();
static int write_rtc(const char *,const char *,const char *,const char *,const char *,const char *);
static int dir_gpio (const char *portStr,const char *pinStr,const char *dirStr);
static int set_gpio (const char *portStr,const char *pinStr);
static int reset_gpio (const char *portStr,const char *pinStr);
static int get_gpio (const char *portStr,const char *pinStr);
static int loop_gpio (const char *portStr,const char *pinStr,const char *dlyStr,const char *numStr);

const CMD_ENTRY gpio[] = {
 {(CMD_FUNC)open_gpio,     0, "open",  "",    "open device driver."},
 {(CMD_FUNC)dir_gpio,      3, "dir",   "port pin dir", "set gpio direction"},
 {(CMD_FUNC)set_gpio,      2, "set",   "port pin", "set gpio "},
 {(CMD_FUNC)reset_gpio,    2, "reset", "port pin", "reset gpio "},
 {(CMD_FUNC)get_gpio,      2, "get",   "port pin", "get gpio"},
 {(CMD_FUNC)read_gpio,     1, "read",  "t|a", "read adc channel "},
 {(CMD_FUNC)write_gpio,    1, "write", "t|a", "write pwm channel "},
 {(CMD_FUNC)loop_gpio,     4, "loop",  "port pin dely num", ""},
 {(CMD_FUNC)read_rtc,      0, "rtc",   "",    "read rtc "},
 {(CMD_FUNC)write_rtc,     6, "rtcset","y m d h m s ",    "read rtc "},
 {(CMD_FUNC)close_gpio,    0, "close", "",    "close device driver."},
 { NULL,                   0,  NULL,   NULL,   NULL}
};

/*****************************************************************************
*  Private functions 
*****************************************************************************/
static int open_gpio()
{
    int ret = CMD_RC_SUCCESS;
    return ret;
}

static int close_gpio()
{
    int ret = CMD_RC_SUCCESS;
    return ret;
}

static int read_rtc()
{
  int ret = CMD_RC_SUCCESS;
  
	printf ("[%d:%d:%d][%d-%d-%d][W:%d]\t\n",
	calendar.hour,
	calendar.min,
	calendar.sec,			
	calendar.w_year,
	calendar.w_month,
	calendar.w_date,
	calendar.week );		     
	
	return ret;
}

static int write_rtc(const char *ys,const char *mons,const char *ds,const char *hs,const char *ms,const char *ss)
{
  int ret = CMD_RC_SUCCESS;
  u16 syear ;
	u8 smon;
	u8 sday;
	u8 hour;
	u8 min;
	u8 sec;
	
	sscanf(ys, "%d", (int *)&syear );
	sscanf(mons, "%d",(int *) &smon );
	sscanf(ds, "%d", (int *)&sday );
	sscanf(hs, "%d", (int *)&hour );
	sscanf(ms, "%d", (int *)&min );
	sscanf(ss, "%d", (int *)&sec );

  usrrtc_set( syear, smon, sday, hour, min, sec);
  printf ("RTC[Y:%d][M:%d][M:%d][D:%d][h:%d][m:%d][s:%d]\r\n", 
	 syear ,smon, sday,	 hour,	 min,	 sec);
	
  return ret;
}


static int read_gpio(const char *portStr)
{
  int ret = CMD_RC_SUCCESS;
 	u16   adcx;
	float temp;
	float temperate;
	u16   voltageR =0;
	float voltageF =0;

	printf ("\r\n");
	adcx = usrtadc_gettm(10);
	temp = (float)adcx*(3.3/4096);
	temperate = temp;
	temperate=(1.43-temperate)/0.0043+25;		//????????	 
			
	voltageR = usradc_getav(ADC_Channel_1, 10 );
	voltageF = voltageR * 3.3F / 4096.0F;

	printf ("TADC: [T:%f]\r\n", temperate);
	printf ("ADC   [R:%d][A:%f]\r\n", voltageR, voltageF);
			
  return ret;
}

static int write_gpio(const char *portStr)
{
  int ret = CMD_RC_SUCCESS;
 	int led0pwmval = 0;
	
	sscanf(portStr, "%d", &led0pwmval);
	
	TIM_SetCompare2(TIM3, (u16)led0pwmval);		   
  
	printf ("PWM  [%d]\r\n", led0pwmval);
			
  return ret;
}

static int dir_gpio (const char *portStr,const char *pinStr,const char *dirStr)
{
  int ret  = CMD_RC_SUCCESS;
 	int pin = atoi(pinStr);
 	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA
	                      | RCC_APB2Periph_GPIOB
	                      | RCC_APB2Periph_GPIOC
	                      , ENABLE);
	
	GPIO_InitStructure.GPIO_Pin  = 1 << pin;      // GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4;
	switch (dirStr[0]) {
	case 'i':
	case 'I':
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU ; 	
    break;		
  case 'o':
	case 'O':
	default:	
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 	
    break; 	
  }
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 

 	switch (portStr[0]) {
  case 'a':
  case 'A':
	  GPIO_Init(GPIOA, &GPIO_InitStructure);        // 
		break;
  case 'b':
  case 'B':
	  GPIO_Init(GPIOB, &GPIO_InitStructure);        // 
		break;
  case 'c':
  case 'C':
	  GPIO_Init(GPIOC, &GPIO_InitStructure);        // 
		break;
  default:
		  break;
  }
	printf ("\r\n[%s][pin:%d][%s][%08x]\r\n", portStr,pin,dirStr,GPIO_InitStructure.GPIO_Pin);
  return ret;
}

static int get_gpio (const char *portStr,const char *pinStr)
{
  int ret  = CMD_RC_SUCCESS;
 	//int port = atoi(portStr);
 	int pin = atoi(pinStr);
	int value = 0;

 	switch (portStr[0]) {
  case 'a':
  case 'A':
	  value = GPIO_ReadInputDataBit(GPIOA,1<<pin);
	  break; 
  case 'b':
  case 'B':
	  value = GPIO_ReadInputDataBit(GPIOB,1<<pin);
	  break; 
  case 'c':
  case 'C':
	  value = GPIO_ReadInputDataBit(GPIOC,1<<pin);
	  break; 
  default:
    break;
  }	
	printf ("\r\n[%s][pin:%d][%d]\r\n", portStr, pin,value);

  return ret;
}

static int set_gpio (const char *portStr,const char *pinStr)
{
  int ret  = CMD_RC_SUCCESS;
 	int pin = atoi(pinStr);
	
 	switch (portStr[0]) {
  case 'a':
  case 'A':
		GPIO_SetBits(GPIOA,1<<pin);
	  break; 
  case 'b':
  case 'B':
		GPIO_SetBits(GPIOB,1<<pin);
	  break; 
  case 'c':
  case 'C':
		GPIO_SetBits(GPIOC,1<<pin);
	  break; 
  default:
    break;
  }	
  return ret;
}

static int reset_gpio (const char *portStr,const char *pinStr)
{
  int ret  = CMD_RC_SUCCESS;
 	int pin = atoi(pinStr);
	
 	switch (portStr[0]) {
  case 'a':
  case 'A':
		GPIO_ResetBits(GPIOA,1<<pin);
	  break; 
  case 'b':
  case 'B':
		GPIO_ResetBits(GPIOB,1<<pin);
	  break; 
  case 'c':
  case 'C':
		GPIO_ResetBits(GPIOC,1<<pin);
	  break; 
  default:
    break;
  }	
  return ret;
}

static int loop_gpio (const char *portStr,const char *pinStr,const char *dlyStr,const char *numStr)
{
  int ret  = CMD_RC_SUCCESS;
 	int pin = atoi(pinStr);
	int dly = atoi(dlyStr);
	int num = atoi(numStr);
	int k = 0;
	
	for (k=0; k<num; k++) {
		switch (portStr[0]) {
		case 'a':
		case 'A':
			GPIO_ResetBits(GPIOA,1<<pin);
			break; 
		case 'b':
		case 'B':
			GPIO_ResetBits(GPIOB,1<<pin);
			break; 
		case 'c':
		case 'C':
			GPIO_ResetBits(GPIOC,1<<pin);
			break; 
		default:
			break;
		}	
    delay_ms (dly);	 
		switch (portStr[0]) {
		case 'a':
		case 'A':
			GPIO_SetBits(GPIOA,1<<pin);
			break; 
		case 'b':
		case 'B':
			GPIO_SetBits(GPIOB,1<<pin);
			break; 
		case 'c':
		case 'C':
			GPIO_SetBits(GPIOC,1<<pin);
			break; 
		default:
			break;
		}	
    delay_ms (dly);	 
	}
	
	return ret;
}



