#ifndef __USRRTC_H
#define __USRRTC_H	 

#include "usr_sys.h"
#include "usr_delay.h"
#include "usr_rtc.h" 		    

typedef struct   {
	vu8  hour;
	vu8  min;
	vu8  sec;			
	vu16 w_year;
	vu8  w_month;
	vu8  w_date;
	vu8  week;		 
}  _calendar_obj;					 

extern _calendar_obj   calendar;	
extern u8 const        mon_table[12];

u8 usrrtc_init(void); 
u8 usrrtc_get(void);       
u8 usrrtc_set (u16 syear,u8 smon,u8 sday,u8 hour,u8 min,u8 sec);

#endif  //__USRRTC_H


