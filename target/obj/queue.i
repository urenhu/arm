#line 1 "..\\free_rtos\\queue.c"








































































 

#line 1 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"
 
 
 




 
 



 






   














  


 








#line 54 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"


  



    typedef unsigned int size_t;    
#line 70 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"






    



    typedef unsigned short wchar_t;  
#line 91 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"

typedef struct div_t { int quot, rem; } div_t;
    
typedef struct ldiv_t { long int quot, rem; } ldiv_t;
    

typedef struct lldiv_t { long long quot, rem; } lldiv_t;
    


#line 112 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"
   



 

   




 
#line 131 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"
   


 
extern __declspec(__nothrow) int __aeabi_MB_CUR_MAX(void);

   




 

   




 




extern __declspec(__nothrow) double atof(const char *  ) __attribute__((__nonnull__(1)));
   



 
extern __declspec(__nothrow) int atoi(const char *  ) __attribute__((__nonnull__(1)));
   



 
extern __declspec(__nothrow) long int atol(const char *  ) __attribute__((__nonnull__(1)));
   



 

extern __declspec(__nothrow) long long atoll(const char *  ) __attribute__((__nonnull__(1)));
   



 


extern __declspec(__nothrow) double strtod(const char * __restrict  , char ** __restrict  ) __attribute__((__nonnull__(1)));
   

















 

extern __declspec(__nothrow) float strtof(const char * __restrict  , char ** __restrict  ) __attribute__((__nonnull__(1)));
extern __declspec(__nothrow) long double strtold(const char * __restrict  , char ** __restrict  ) __attribute__((__nonnull__(1)));
   

 

extern __declspec(__nothrow) long int strtol(const char * __restrict  ,
                        char ** __restrict  , int  ) __attribute__((__nonnull__(1)));
   



























 
extern __declspec(__nothrow) unsigned long int strtoul(const char * __restrict  ,
                                       char ** __restrict  , int  ) __attribute__((__nonnull__(1)));
   


























 

 
extern __declspec(__nothrow) long long strtoll(const char * __restrict  ,
                                  char ** __restrict  , int  )
                          __attribute__((__nonnull__(1)));
   




 
extern __declspec(__nothrow) unsigned long long strtoull(const char * __restrict  ,
                                            char ** __restrict  , int  )
                                   __attribute__((__nonnull__(1)));
   



 

extern __declspec(__nothrow) int rand(void);
   







 
extern __declspec(__nothrow) void srand(unsigned int  );
   






 

struct _rand_state { int __x[57]; };
extern __declspec(__nothrow) int _rand_r(struct _rand_state *);
extern __declspec(__nothrow) void _srand_r(struct _rand_state *, unsigned int);
struct _ANSI_rand_state { int __x[1]; };
extern __declspec(__nothrow) int _ANSI_rand_r(struct _ANSI_rand_state *);
extern __declspec(__nothrow) void _ANSI_srand_r(struct _ANSI_rand_state *, unsigned int);
   


 

extern __declspec(__nothrow) void *calloc(size_t  , size_t  );
   



 
extern __declspec(__nothrow) void free(void *  );
   





 
extern __declspec(__nothrow) void *malloc(size_t  );
   



 
extern __declspec(__nothrow) void *realloc(void *  , size_t  );
   













 

extern __declspec(__nothrow) int posix_memalign(void **  , size_t  , size_t  );
   









 

typedef int (*__heapprt)(void *, char const *, ...);
extern __declspec(__nothrow) void __heapstats(int (*  )(void *  ,
                                           char const *  , ...),
                        void *  ) __attribute__((__nonnull__(1)));
   










 
extern __declspec(__nothrow) int __heapvalid(int (*  )(void *  ,
                                           char const *  , ...),
                       void *  , int  ) __attribute__((__nonnull__(1)));
   














 
extern __declspec(__nothrow) __declspec(__noreturn) void abort(void);
   







 

extern __declspec(__nothrow) int atexit(void (*  )(void)) __attribute__((__nonnull__(1)));
   




 
#line 436 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"


extern __declspec(__nothrow) __declspec(__noreturn) void exit(int  );
   












 

extern __declspec(__nothrow) __declspec(__noreturn) void _Exit(int  );
   







      

extern __declspec(__nothrow) char *getenv(const char *  ) __attribute__((__nonnull__(1)));
   









 

extern __declspec(__nothrow) int  system(const char *  );
   









 

extern  void *bsearch(const void *  , const void *  ,
              size_t  , size_t  ,
              int (*  )(const void *, const void *)) __attribute__((__nonnull__(1,2,5)));
   












 
#line 524 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"


extern  void qsort(void *  , size_t  , size_t  ,
           int (*  )(const void *, const void *)) __attribute__((__nonnull__(1,4)));
   









 

#line 553 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"

extern __declspec(__nothrow) __attribute__((const)) int abs(int  );
   



 

extern __declspec(__nothrow) __attribute__((const)) div_t div(int  , int  );
   









 
extern __declspec(__nothrow) __attribute__((const)) long int labs(long int  );
   



 




extern __declspec(__nothrow) __attribute__((const)) ldiv_t ldiv(long int  , long int  );
   











 







extern __declspec(__nothrow) __attribute__((const)) long long llabs(long long  );
   



 




extern __declspec(__nothrow) __attribute__((const)) lldiv_t lldiv(long long  , long long  );
   











 
#line 634 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"




 
typedef struct __sdiv32by16 { int quot, rem; } __sdiv32by16;
typedef struct __udiv32by16 { unsigned int quot, rem; } __udiv32by16;
    
typedef struct __sdiv64by32 { int rem, quot; } __sdiv64by32;

__value_in_regs extern __declspec(__nothrow) __attribute__((const)) __sdiv32by16 __rt_sdiv32by16(
     int  ,
     short int  );
   

 
__value_in_regs extern __declspec(__nothrow) __attribute__((const)) __udiv32by16 __rt_udiv32by16(
     unsigned int  ,
     unsigned short  );
   

 
__value_in_regs extern __declspec(__nothrow) __attribute__((const)) __sdiv64by32 __rt_sdiv64by32(
     int  , unsigned int  ,
     int  );
   

 




 
extern __declspec(__nothrow) unsigned int __fp_status(unsigned int  , unsigned int  );
   







 























 
extern __declspec(__nothrow) int mblen(const char *  , size_t  );
   












 
extern __declspec(__nothrow) int mbtowc(wchar_t * __restrict  ,
                   const char * __restrict  , size_t  );
   















 
extern __declspec(__nothrow) int wctomb(char *  , wchar_t  );
   













 





 
extern __declspec(__nothrow) size_t mbstowcs(wchar_t * __restrict  ,
                      const char * __restrict  , size_t  ) __attribute__((__nonnull__(2)));
   














 
extern __declspec(__nothrow) size_t wcstombs(char * __restrict  ,
                      const wchar_t * __restrict  , size_t  ) __attribute__((__nonnull__(2)));
   














 

extern __declspec(__nothrow) void __use_realtime_heap(void);
extern __declspec(__nothrow) void __use_realtime_division(void);
extern __declspec(__nothrow) void __use_two_region_memory(void);
extern __declspec(__nothrow) void __use_no_heap(void);
extern __declspec(__nothrow) void __use_no_heap_region(void);

extern __declspec(__nothrow) char const *__C_library_version_string(void);
extern __declspec(__nothrow) int __C_library_version_number(void);











#line 892 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"





 
#line 76 "..\\free_rtos\\queue.c"
#line 1 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\string.h"
 
 
 
 




 








 












#line 38 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\string.h"


  



    typedef unsigned int size_t;    
#line 54 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\string.h"




extern __declspec(__nothrow) void *memcpy(void * __restrict  ,
                    const void * __restrict  , size_t  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) void *memmove(void *  ,
                    const void *  , size_t  ) __attribute__((__nonnull__(1,2)));
   







 
extern __declspec(__nothrow) char *strcpy(char * __restrict  , const char * __restrict  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) char *strncpy(char * __restrict  , const char * __restrict  , size_t  ) __attribute__((__nonnull__(1,2)));
   





 

extern __declspec(__nothrow) char *strcat(char * __restrict  , const char * __restrict  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) char *strncat(char * __restrict  , const char * __restrict  , size_t  ) __attribute__((__nonnull__(1,2)));
   






 






 

extern __declspec(__nothrow) int memcmp(const void *  , const void *  , size_t  ) __attribute__((__nonnull__(1,2)));
   





 
extern __declspec(__nothrow) int strcmp(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) int strncmp(const char *  , const char *  , size_t  ) __attribute__((__nonnull__(1,2)));
   






 
extern __declspec(__nothrow) int strcasecmp(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   





 
extern __declspec(__nothrow) int strncasecmp(const char *  , const char *  , size_t  ) __attribute__((__nonnull__(1,2)));
   






 
extern __declspec(__nothrow) int strcoll(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   







 

extern __declspec(__nothrow) size_t strxfrm(char * __restrict  , const char * __restrict  , size_t  ) __attribute__((__nonnull__(2)));
   













 


#line 193 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\string.h"
extern __declspec(__nothrow) void *memchr(const void *  , int  , size_t  ) __attribute__((__nonnull__(1)));

   





 

#line 209 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\string.h"
extern __declspec(__nothrow) char *strchr(const char *  , int  ) __attribute__((__nonnull__(1)));

   




 

extern __declspec(__nothrow) size_t strcspn(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   




 

#line 232 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\string.h"
extern __declspec(__nothrow) char *strpbrk(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));

   




 

#line 247 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\string.h"
extern __declspec(__nothrow) char *strrchr(const char *  , int  ) __attribute__((__nonnull__(1)));

   





 

extern __declspec(__nothrow) size_t strspn(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   



 

#line 270 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\string.h"
extern __declspec(__nothrow) char *strstr(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));

   





 

extern __declspec(__nothrow) char *strtok(char * __restrict  , const char * __restrict  ) __attribute__((__nonnull__(2)));
extern __declspec(__nothrow) char *_strtok_r(char *  , const char *  , char **  ) __attribute__((__nonnull__(2,3)));

extern __declspec(__nothrow) char *strtok_r(char *  , const char *  , char **  ) __attribute__((__nonnull__(2,3)));

   

































 

extern __declspec(__nothrow) void *memset(void *  , int  , size_t  ) __attribute__((__nonnull__(1)));
   



 
extern __declspec(__nothrow) char *strerror(int  );
   





 
extern __declspec(__nothrow) size_t strlen(const char *  ) __attribute__((__nonnull__(1)));
   



 

extern __declspec(__nothrow) size_t strlcpy(char *  , const char *  , size_t  ) __attribute__((__nonnull__(1,2)));
   
















 

extern __declspec(__nothrow) size_t strlcat(char *  , const char *  , size_t  ) __attribute__((__nonnull__(1,2)));
   






















 

extern __declspec(__nothrow) void _membitcpybl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpybb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpyhl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpyhb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpywl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpywb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovebl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovebb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovehl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovehb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovewl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovewb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
    














































 







#line 502 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\string.h"



 

#line 77 "..\\free_rtos\\queue.c"



 


#line 1 "..\\free_rtos\\FreeRTOS.h"








































































 







 
#line 1 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stddef.h"
 






 

 
 
 





 





#line 34 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stddef.h"




  typedef signed int ptrdiff_t;



  



    typedef unsigned int size_t;    
#line 57 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stddef.h"



   



      typedef unsigned short wchar_t;  
#line 82 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stddef.h"



    




   




  typedef long double max_align_t;









#line 114 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stddef.h"



 

#line 83 "..\\free_rtos\\FreeRTOS.h"

 
#line 1 "..\\free_rtos\\projdefs.h"








































































 




 
typedef void (*pdTASK_CODE)( void * );









 









#line 86 "..\\free_rtos\\FreeRTOS.h"

 
#line 1 "..\\free_rtos\\FreeRTOSConfig.h"








































































 














 

#line 102 "..\\free_rtos\\FreeRTOSConfig.h"

 




 

#line 117 "..\\free_rtos\\FreeRTOSConfig.h"


 


 






 




#line 89 "..\\free_rtos\\FreeRTOS.h"


 




 
#line 1 "..\\free_rtos\\portable.h"








































































 



 




 


























































	



































	







	



























	








































#line 261 "..\\free_rtos\\portable.h"

#line 269 "..\\free_rtos\\portable.h"







#line 283 "..\\free_rtos\\portable.h"

































	



	





 
#line 1 "..\\free_rtos\\portmacro.h"








































































 

















 

 
#line 101 "..\\free_rtos\\portmacro.h"





	typedef unsigned long                 portTickType;


 
 



 
 
extern void                        vPortYield( void );




 
 
extern unsigned long   ulPortSetInterruptMask( void );
extern void            vPortClearInterruptMask( unsigned long ulNewMask );
extern void            vPortEnterCritical( void );
extern void            vPortExitCritical( void );

#line 134 "..\\free_rtos\\portmacro.h"
 

 

	extern void vPortSuppressTicksAndSleep( portTickType xExpectedIdleTime );


 

 
#line 156 "..\\free_rtos\\portmacro.h"
 


 



 
 






#line 329 "..\\free_rtos\\portable.h"

	




























#line 1 "..\\free_rtos\\mpu_wrappers.h"








































































 





 
#line 152 "..\\free_rtos\\mpu_wrappers.h"










#line 360 "..\\free_rtos\\portable.h"






 



	unsigned long *pxPortInitialiseStack( unsigned long *pxTopOfStack, pdTASK_CODE pxCode, void *pvParameters );




 
void *pvPortMalloc( size_t xSize ) ;
void vPortFree( void *pv ) ;
void vPortInitialiseBlocks( void ) ;
size_t xPortGetFreeHeapSize( void ) ;




 
long xPortStartScheduler( void ) ;





 
void vPortEndScheduler( void ) ;







 











#line 98 "..\\free_rtos\\FreeRTOS.h"



 
typedef long (*pdTASK_HOOK_CODE)( void * );









 





























































































































 
#line 254 "..\\free_rtos\\FreeRTOS.h"







































 

	
 




	
 




	
 




	
 




	



 




	


 




	


 




	


 







 





















































































































































#line 518 "..\\free_rtos\\FreeRTOS.h"





















































 




#line 84 "..\\free_rtos\\queue.c"
#line 1 "..\\free_rtos\\task.h"








































































 









#line 84 "..\\free_rtos\\task.h"
#line 1 "..\\free_rtos\\list.h"








































































 



























 










 
struct xLIST_ITEM
{
	portTickType xItemValue;				 
	volatile struct xLIST_ITEM * pxNext;	 
	volatile struct xLIST_ITEM * pxPrevious; 
	void * pvOwner;							 
	void * pvContainer;						 
};
typedef struct xLIST_ITEM xListItem;		 

struct xMINI_LIST_ITEM
{
	portTickType xItemValue;
	volatile struct xLIST_ITEM *pxNext;
	volatile struct xLIST_ITEM *pxPrevious;
};
typedef struct xMINI_LIST_ITEM xMiniListItem;



 
typedef struct xLIST
{
	volatile unsigned long uxNumberOfItems;
	volatile xListItem * pxIndex;			 
	volatile xMiniListItem xListEnd;		 
} xList;







 








 








 









 








 








 




 




















 
#line 232 "..\\free_rtos\\list.h"

















 











 







 






 











 
void vListInitialise( xList *pxList );









 
void vListInitialiseItem( xListItem *pxItem );











 
void vListInsert( xList *pxList, xListItem *pxNewListItem );



















 
void vListInsertEnd( xList *pxList, xListItem *pxNewListItem );













 
unsigned long uxListRemove( xListItem *pxItemToRemove );







#line 85 "..\\free_rtos\\task.h"







 












 
typedef void * xTaskHandle;



 
typedef struct xTIME_OUT
{
	long xOverflowCount;
	portTickType  xTimeOnEntering;
} xTimeOutType;



 
typedef struct xMEMORY_REGION
{
	void *pvBaseAddress;
	unsigned long ulLengthInBytes;
	unsigned long ulParameters;
} xMemoryRegion;



 
typedef struct xTASK_PARAMTERS
{
	pdTASK_CODE pvTaskCode;
	const signed char * const pcName;
	unsigned short usStackDepth;
	void *pvParameters;
	unsigned long uxPriority;
	unsigned long *puxStackBuffer;
	xMemoryRegion xRegions[ 1 ];
} xTaskParameters;

 
typedef enum
{
	eRunning = 0,	 
	eReady,			 
	eBlocked,		 
	eSuspended,		 
	eDeleted		 
} eTaskState;

 
typedef enum
{
	eAbortSleep = 0,		 
	eStandardSleep,			 
	eNoTasksWaitingTimeout	 
} eSleepModeStatus;






 









 













 













 









 









 


 






 












































































 




































































 















































 
void vTaskAllocateMPURegions( xTaskHandle xTask, const xMemoryRegion * const pxRegions ) ;







































 
void vTaskDelete( xTaskHandle xTaskToDelete ) ;



 
















































 
void vTaskDelay( portTickType xTicksToDelay ) ;

























































 
void vTaskDelayUntil( portTickType * const pxPreviousWakeTime, portTickType xTimeIncrement ) ;













































 
unsigned long uxTaskPriorityGet( xTaskHandle xTask ) ;
















 
eTaskState eTaskGetState( xTaskHandle xTask ) ;








































 
void vTaskPrioritySet( xTaskHandle xTask, unsigned long uxNewPriority ) ;

















































 
void vTaskSuspend( xTaskHandle xTaskToSuspend ) ;















































 
void vTaskResume( xTaskHandle xTaskToResume ) ;


















 
long xTaskResumeFromISR( xTaskHandle xTaskToResume ) ;



 
































 
void vTaskStartScheduler( void ) ;



















































 
void vTaskEndScheduler( void ) ;

















































 
void vTaskSuspendAll( void ) ;


















































 
signed long xTaskResumeAll( void ) ;









 
signed long xTaskIsTaskSuspended( xTaskHandle xTask ) ;



 









 
portTickType xTaskGetTickCount( void ) ;














 
portTickType xTaskGetTickCountFromISR( void ) ;












 
unsigned long uxTaskGetNumberOfTasks( void ) ;












 
signed char *pcTaskGetTaskName( xTaskHandle xTaskToQuery );
























 
void vTaskList( signed char *pcWriteBuffer ) ;






























 
void vTaskGetRunTimeStats( signed char *pcWriteBuffer ) ;


















 
unsigned long uxTaskGetStackHighWaterMark( xTaskHandle xTask ) ;






 
#line 1179 "..\\free_rtos\\task.h"










 
long xTaskCallApplicationTaskHook( xTaskHandle xTask, void *pvParameter ) ;







 
xTaskHandle xTaskGetIdleTaskHandle( void );



 










 
void vTaskIncrementTick( void ) ;





















 
void vTaskPlaceOnEventList( const xList * const pxEventList, portTickType xTicksToWait ) ;













 
void vTaskPlaceOnEventListRestricted( const xList * const pxEventList, portTickType xTicksToWait ) ;















 
signed long xTaskRemoveFromEventList( const xList * const pxEventList ) ;








 
void vTaskSwitchContext( void ) ;



 
xTaskHandle xTaskGetCurrentTaskHandle( void ) ;



 
void vTaskSetTimeOutState( xTimeOutType * const pxTimeOut ) ;




 
long xTaskCheckForTimeOut( xTimeOutType * const pxTimeOut, portTickType * const pxTicksToWait ) ;




 
void vTaskMissedYield( void ) ;




 
long xTaskGetSchedulerState( void ) ;




 
void vTaskPriorityInherit( xTaskHandle * const pxMutexHolder ) ;




 
void vTaskPriorityDisinherit( xTaskHandle * const pxMutexHolder ) ;




 
signed long xTaskGenericCreate( pdTASK_CODE pxTaskCode, const signed char * const pcName, unsigned short usStackDepth, void *pvParameters, unsigned long uxPriority, xTaskHandle *pxCreatedTask, unsigned long *puxStackBuffer, const xMemoryRegion * const xRegions ) ;



 
unsigned long uxTaskGetTaskNumber( xTaskHandle xTask );




 
void vTaskSetTaskNumber( xTaskHandle xTask, unsigned long uxHandle );







 
void vTaskStepTick( portTickType xTicksToJump );













 
eSleepModeStatus eTaskConfirmSleepModeStatus( void );








#line 85 "..\\free_rtos\\queue.c"
#line 1 "..\\free_rtos\\queue.h"








































































 














#line 89 "..\\free_rtos\\queue.h"





 
typedef void * xQueueHandle;





 
typedef void * xQueueSetHandle;





 
typedef void * xQueueSetMemberHandle;

 



 
#line 122 "..\\free_rtos\\queue.h"
























































 

















































































 

















































































 



















































































 























































































 
signed long xQueueGenericSend( xQueueHandle xQueue, const void * const pvItemToQueue, portTickType xTicksToWait, long xCopyPosition );




























































































 




























































































 


































































































 
signed long xQueueGenericReceive( xQueueHandle xQueue, void * const pvBuffer, portTickType xTicksToWait, long xJustPeek );













 
unsigned long uxQueueMessagesWaiting( const xQueueHandle xQueue );












 
void vQueueDelete( xQueueHandle xQueue );




































































 






































































 









































































 













































































 
signed long xQueueGenericSendFromISR( xQueueHandle xQueue, const void * const pvItemToQueue, signed long *pxHigherPriorityTaskWoken, long xCopyPosition );























































































 
signed long xQueueReceiveFromISR( xQueueHandle xQueue, void * const pvBuffer, signed long *pxHigherPriorityTaskWoken );




 
signed long xQueueIsQueueEmptyFromISR( const xQueueHandle xQueue );
signed long xQueueIsQueueFullFromISR( const xQueueHandle xQueue );
unsigned long uxQueueMessagesWaitingFromISR( const xQueueHandle xQueue );















 
signed long xQueueAltGenericSend( xQueueHandle xQueue, const void * const pvItemToQueue, portTickType xTicksToWait, long xCopyPosition );
signed long xQueueAltGenericReceive( xQueueHandle xQueue, void * const pvBuffer, portTickType xTicksToWait, long xJustPeeking );













 
signed long xQueueCRSendFromISR( xQueueHandle xQueue, const void *pvItemToQueue, signed long xCoRoutinePreviouslyWoken );
signed long xQueueCRReceiveFromISR( xQueueHandle xQueue, void *pvBuffer, signed long *pxTaskWoken );
signed long xQueueCRSend( xQueueHandle xQueue, const void *pvItemToQueue, portTickType xTicksToWait );
signed long xQueueCRReceive( xQueueHandle xQueue, void *pvBuffer, portTickType xTicksToWait );





 
xQueueHandle xQueueCreateMutex( unsigned char ucQueueType );
xQueueHandle xQueueCreateCountingSemaphore( unsigned long uxCountValue, unsigned long uxInitialCount );
void* xQueueGetMutexHolder( xQueueHandle xSemaphore );




 
long xQueueTakeMutexRecursive( xQueueHandle xMutex, portTickType xBlockTime );
long xQueueGiveMutexRecursive( xQueueHandle pxMutex );






 





















 







 
xQueueHandle xQueueGenericCreate( unsigned long uxQueueLength, unsigned long uxItemSize, unsigned char ucQueueType );
















































 
xQueueSetHandle xQueueCreateSet( unsigned long uxEventQueueLength );






















 
long xQueueAddToSet( xQueueSetMemberHandle xQueueOrSemaphore, xQueueSetHandle xQueueSet );

















 
long xQueueRemoveFromSet( xQueueSetMemberHandle xQueueOrSemaphore, xQueueSetHandle xQueueSet );


































 
xQueueSetMemberHandle xQueueSelectFromSet( xQueueSetHandle xQueueSet, portTickType xBlockTimeTicks );



 
xQueueSetMemberHandle xQueueSelectFromSetFromISR( xQueueSetHandle xQueueSet );

 
void vQueueWaitForMessageRestricted( xQueueHandle xQueue, portTickType xTicksToWait );
long xQueueGenericReset( xQueueHandle xQueue, long xNewQueue );
void vQueueSetQueueNumber( xQueueHandle xQueue, unsigned char ucQueueNumber ) ;
unsigned char ucQueueGetQueueType( xQueueHandle xQueue ) ;








#line 86 "..\\free_rtos\\queue.c"







 





 






 








 
typedef struct QueueDefinition
{
	signed char *pcHead;					 
	signed char *pcTail;					 

	signed char *pcWriteTo;					 
	signed char *pcReadFrom;				 

	xList xTasksWaitingToSend;				 
	xList xTasksWaitingToReceive;			 

	volatile unsigned long uxMessagesWaiting; 
	unsigned long uxLength;		 
	unsigned long uxItemSize;		 

	volatile signed long xRxLock;	 
	volatile signed long xTxLock;	 










} xQUEUE;
 




 
#line 171 "..\\free_rtos\\queue.c"








 
static void prvUnlockQueue( xQUEUE *pxQueue ) ;





 
static signed long prvIsQueueEmpty( const xQUEUE *pxQueue ) ;





 
static signed long prvIsQueueFull( const xQUEUE *pxQueue ) ;




 
static void prvCopyDataToQueue( xQUEUE *pxQueue, const void *pvItemToQueue, long xPosition ) ;



 
static void prvCopyDataFromQueue( xQUEUE * const pxQueue, const void *pvBuffer ) ;

#line 214 "..\\free_rtos\\queue.c"

 




 
#line 234 "..\\free_rtos\\queue.c"
 

long xQueueGenericReset( xQueueHandle xQueue, long xNewQueue )
{
xQUEUE *pxQueue;

	pxQueue = ( xQUEUE * ) xQueue;
	;

	vPortEnterCritical();
	{
		pxQueue->pcTail = pxQueue->pcHead + ( pxQueue->uxLength * pxQueue->uxItemSize );
		pxQueue->uxMessagesWaiting = ( unsigned long ) 0U;
		pxQueue->pcWriteTo = pxQueue->pcHead;
		pxQueue->pcReadFrom = pxQueue->pcHead + ( ( pxQueue->uxLength - ( unsigned long ) 1U ) * pxQueue->uxItemSize );
		pxQueue->xRxLock = ( ( signed long ) -1 );
		pxQueue->xTxLock = ( ( signed long ) -1 );

		if( xNewQueue == ( 0 ) )
		{
			



 
			if( ( ( &( pxQueue ->xTasksWaitingToSend ) )->uxNumberOfItems == ( unsigned long ) 0 ) == ( 0 ) )
			{
				if( xTaskRemoveFromEventList( &( pxQueue->xTasksWaitingToSend ) ) == ( 1 ) )
				{
					vPortYield();
				}
			}
		}
		else
		{
			 
			vListInitialise( &( pxQueue->xTasksWaitingToSend ) );
			vListInitialise( &( pxQueue->xTasksWaitingToReceive ) );
		}
	}
	vPortExitCritical();

	
 
	return ( 1 );
}
 

xQueueHandle xQueueGenericCreate( unsigned long uxQueueLength, unsigned long uxItemSize, unsigned char ucQueueType )
{
xQUEUE *pxNewQueue;
size_t xQueueSizeInBytes;
xQueueHandle xReturn = 0;

	
 
	( void ) ucQueueType;

	 
	if( uxQueueLength > ( unsigned long ) 0 )
	{
		pxNewQueue = ( xQUEUE * ) pvPortMalloc( sizeof( xQUEUE ) );
		if( pxNewQueue != 0 )
		{
			
 
			xQueueSizeInBytes = ( size_t ) ( uxQueueLength * uxItemSize ) + ( size_t ) 1;

			pxNewQueue->pcHead = ( signed char * ) pvPortMalloc( xQueueSizeInBytes );
			if( pxNewQueue->pcHead != 0 )
			{
				
 
				pxNewQueue->uxLength = uxQueueLength;
				pxNewQueue->uxItemSize = uxItemSize;
				xQueueGenericReset( pxNewQueue, ( 1 ) );













				;
				xReturn = pxNewQueue;
			}
			else
			{
				;
				vPortFree( pxNewQueue );
			}
		}
	}

	;

	return xReturn;
}
 

#line 403 "..\\free_rtos\\queue.c"
 

#line 433 "..\\free_rtos\\queue.c"
 

#line 484 "..\\free_rtos\\queue.c"
 

#line 526 "..\\free_rtos\\queue.c"
 

#line 552 "..\\free_rtos\\queue.c"
 

signed long xQueueGenericSend( xQueueHandle xQueue, const void * const pvItemToQueue, portTickType xTicksToWait, long xCopyPosition )
{
signed long xEntryTimeSet = ( 0 );
xTimeOutType xTimeOut;
xQUEUE *pxQueue;

	pxQueue = ( xQUEUE * ) xQueue;
	;
	;

	

 
	for( ;; )
	{
		vPortEnterCritical();
		{
			
 
			if( pxQueue->uxMessagesWaiting < pxQueue->uxLength )
			{
				;
				prvCopyDataToQueue( pxQueue, pvItemToQueue, xCopyPosition );

#line 608 "..\\free_rtos\\queue.c"
				{
					
 
					if( ( ( &( pxQueue ->xTasksWaitingToReceive ) )->uxNumberOfItems == ( unsigned long ) 0 ) == ( 0 ) )
					{
						if( xTaskRemoveFromEventList( &( pxQueue->xTasksWaitingToReceive ) ) == ( 1 ) )
						{
							


 
							vPortYield();
						}
					}
				}


				vPortExitCritical();

				
 
				return ( 1 );
			}
			else
			{
				if( xTicksToWait == ( portTickType ) 0 )
				{
					
 
					vPortExitCritical();

					
 
					;
					return ( 0 );
				}
				else if( xEntryTimeSet == ( 0 ) )
				{
					
 
					vTaskSetTimeOutState( &xTimeOut );
					xEntryTimeSet = ( 1 );
				}
			}
		}
		vPortExitCritical();

		
 

		vTaskSuspendAll();
		vPortEnterCritical(); { if( ( pxQueue )->xRxLock == ( ( signed long ) -1 ) ) { ( pxQueue )->xRxLock = ( ( signed long ) 0 ); } if( ( pxQueue )->xTxLock == ( ( signed long ) -1 ) ) { ( pxQueue )->xTxLock = ( ( signed long ) 0 ); } } vPortExitCritical();

		 
		if( xTaskCheckForTimeOut( &xTimeOut, &xTicksToWait ) == ( 0 ) )
		{
			if( prvIsQueueFull( pxQueue ) != ( 0 ) )
			{
				;
				vTaskPlaceOnEventList( &( pxQueue->xTasksWaitingToSend ), xTicksToWait );

				



 
				prvUnlockQueue( pxQueue );

				



 
				if( xTaskResumeAll() == ( 0 ) )
				{
					vPortYield();
				}
			}
			else
			{
				 
				prvUnlockQueue( pxQueue );
				( void ) xTaskResumeAll();
			}
		}
		else
		{
			 
			prvUnlockQueue( pxQueue );
			( void ) xTaskResumeAll();

			
 
			;
			return ( 0 );
		}
	}
}
 

#line 785 "..\\free_rtos\\queue.c"
 

#line 918 "..\\free_rtos\\queue.c"
 

signed long xQueueGenericSendFromISR( xQueueHandle xQueue, const void * const pvItemToQueue, signed long *pxHigherPriorityTaskWoken, long xCopyPosition )
{
signed long xReturn;
unsigned long uxSavedInterruptStatus;
xQUEUE *pxQueue;

	pxQueue = ( xQUEUE * ) xQueue;
	;
	;

	



 
	uxSavedInterruptStatus = ulPortSetInterruptMask();
	{
		if( pxQueue->uxMessagesWaiting < pxQueue->uxLength )
		{
			;

			prvCopyDataToQueue( pxQueue, pvItemToQueue, xCopyPosition );

			
 
			if( pxQueue->xTxLock == ( ( signed long ) -1 ) )
			{
#line 979 "..\\free_rtos\\queue.c"
				{
					if( ( ( &( pxQueue ->xTasksWaitingToReceive ) )->uxNumberOfItems == ( unsigned long ) 0 ) == ( 0 ) )
					{
						if( xTaskRemoveFromEventList( &( pxQueue->xTasksWaitingToReceive ) ) != ( 0 ) )
						{
							
 
							if( pxHigherPriorityTaskWoken != 0 )
							{
								*pxHigherPriorityTaskWoken = ( 1 );
							}
						}
					}
				}

			}
			else
			{
				
 
				++( pxQueue->xTxLock );
			}

			xReturn = ( 1 );
		}
		else
		{
			;
			xReturn = ( 0 );
		}
	}
	vPortClearInterruptMask(uxSavedInterruptStatus);

	return xReturn;
}
 

signed long xQueueGenericReceive( xQueueHandle xQueue, void * const pvBuffer, portTickType xTicksToWait, long xJustPeeking )
{
signed long xEntryTimeSet = ( 0 );
xTimeOutType xTimeOut;
signed char *pcOriginalReadPosition;
xQUEUE *pxQueue;

	pxQueue = ( xQUEUE * ) xQueue;
	;
	;

	

 

	for( ;; )
	{
		vPortEnterCritical();
		{
			
 
			if( pxQueue->uxMessagesWaiting > ( unsigned long ) 0 )
			{
				 
				pcOriginalReadPosition = pxQueue->pcReadFrom;

				prvCopyDataFromQueue( pxQueue, pvBuffer );

				if( xJustPeeking == ( 0 ) )
				{
					;

					 
					--( pxQueue->uxMessagesWaiting );

#line 1061 "..\\free_rtos\\queue.c"

					if( ( ( &( pxQueue ->xTasksWaitingToSend ) )->uxNumberOfItems == ( unsigned long ) 0 ) == ( 0 ) )
					{
						if( xTaskRemoveFromEventList( &( pxQueue->xTasksWaitingToSend ) ) == ( 1 ) )
						{
							vPortYield();
						}
					}
				}
				else
				{
					;

					
 
					pxQueue->pcReadFrom = pcOriginalReadPosition;

					
 
					if( ( ( &( pxQueue ->xTasksWaitingToReceive ) )->uxNumberOfItems == ( unsigned long ) 0 ) == ( 0 ) )
					{
						
 
						if( xTaskRemoveFromEventList( &( pxQueue->xTasksWaitingToReceive ) ) != ( 0 ) )
						{
							 
							vPortYield();
						}
					}
				}

				vPortExitCritical();
				return ( 1 );
			}
			else
			{
				if( xTicksToWait == ( portTickType ) 0 )
				{
					
 
					vPortExitCritical();
					;
					return ( 0 );
				}
				else if( xEntryTimeSet == ( 0 ) )
				{
					
 
					vTaskSetTimeOutState( &xTimeOut );
					xEntryTimeSet = ( 1 );
				}
			}
		}
		vPortExitCritical();

		
 

		vTaskSuspendAll();
		vPortEnterCritical(); { if( ( pxQueue )->xRxLock == ( ( signed long ) -1 ) ) { ( pxQueue )->xRxLock = ( ( signed long ) 0 ); } if( ( pxQueue )->xTxLock == ( ( signed long ) -1 ) ) { ( pxQueue )->xTxLock = ( ( signed long ) 0 ); } } vPortExitCritical();

		 
		if( xTaskCheckForTimeOut( &xTimeOut, &xTicksToWait ) == ( 0 ) )
		{
			if( prvIsQueueEmpty( pxQueue ) != ( 0 ) )
			{
				;

#line 1141 "..\\free_rtos\\queue.c"

				vTaskPlaceOnEventList( &( pxQueue->xTasksWaitingToReceive ), xTicksToWait );
				prvUnlockQueue( pxQueue );
				if( xTaskResumeAll() == ( 0 ) )
				{
					vPortYield();
				}
			}
			else
			{
				 
				prvUnlockQueue( pxQueue );
				( void ) xTaskResumeAll();
			}
		}
		else
		{
			prvUnlockQueue( pxQueue );
			( void ) xTaskResumeAll();
			;
			return ( 0 );
		}
	}
}
 

signed long xQueueReceiveFromISR( xQueueHandle xQueue, void * const pvBuffer, signed long *pxHigherPriorityTaskWoken )
{
signed long xReturn;
unsigned long uxSavedInterruptStatus;
xQUEUE *pxQueue;

	pxQueue = ( xQUEUE * ) xQueue;
	;
	;

	uxSavedInterruptStatus = ulPortSetInterruptMask();
	{
		 
		if( pxQueue->uxMessagesWaiting > ( unsigned long ) 0 )
		{
			;

			prvCopyDataFromQueue( pxQueue, pvBuffer );
			--( pxQueue->uxMessagesWaiting );

			

 
			if( pxQueue->xRxLock == ( ( signed long ) -1 ) )
			{
				if( ( ( &( pxQueue ->xTasksWaitingToSend ) )->uxNumberOfItems == ( unsigned long ) 0 ) == ( 0 ) )
				{
					if( xTaskRemoveFromEventList( &( pxQueue->xTasksWaitingToSend ) ) != ( 0 ) )
					{
						
 
						if( pxHigherPriorityTaskWoken != 0 )
						{
							*pxHigherPriorityTaskWoken = ( 1 );
						}
					}
				}
			}
			else
			{
				
 
				++( pxQueue->xRxLock );
			}

			xReturn = ( 1 );
		}
		else
		{
			xReturn = ( 0 );
			;
		}
	}
	vPortClearInterruptMask(uxSavedInterruptStatus);

	return xReturn;
}
 

unsigned long uxQueueMessagesWaiting( const xQueueHandle xQueue )
{
unsigned long uxReturn;

	;

	vPortEnterCritical();
		uxReturn = ( ( xQUEUE * ) xQueue )->uxMessagesWaiting;
	vPortExitCritical();

	return uxReturn;
}
 

unsigned long uxQueueMessagesWaitingFromISR( const xQueueHandle xQueue )
{
unsigned long uxReturn;

	;

	uxReturn = ( ( xQUEUE * ) xQueue )->uxMessagesWaiting;

	return uxReturn;
}
 

void vQueueDelete( xQueueHandle xQueue )
{
xQUEUE *pxQueue;

	pxQueue = ( xQUEUE * ) xQueue;
	;

	;





	vPortFree( pxQueue->pcHead );
	vPortFree( pxQueue );
}
 

#line 1278 "..\\free_rtos\\queue.c"
 

#line 1288 "..\\free_rtos\\queue.c"
 

#line 1298 "..\\free_rtos\\queue.c"
 

static void prvCopyDataToQueue( xQUEUE *pxQueue, const void *pvItemToQueue, long xPosition )
{
	if( pxQueue->uxItemSize == ( unsigned long ) 0 )
	{
#line 1314 "..\\free_rtos\\queue.c"
	}
	else if( xPosition == ( 0 ) )
	{
		memcpy( ( void * ) pxQueue->pcWriteTo, pvItemToQueue, ( size_t ) pxQueue->uxItemSize );
		pxQueue->pcWriteTo += pxQueue->uxItemSize;
		if( pxQueue->pcWriteTo >= pxQueue->pcTail )
		{
			pxQueue->pcWriteTo = pxQueue->pcHead;
		}
	}
	else
	{
		memcpy( ( void * ) pxQueue->pcReadFrom, pvItemToQueue, ( size_t ) pxQueue->uxItemSize );
		pxQueue->pcReadFrom -= pxQueue->uxItemSize;
		if( pxQueue->pcReadFrom < pxQueue->pcHead )
		{
			pxQueue->pcReadFrom = ( pxQueue->pcTail - pxQueue->uxItemSize );
		}
	}

	++( pxQueue->uxMessagesWaiting );
}
 

static void prvCopyDataFromQueue( xQUEUE * const pxQueue, const void *pvBuffer )
{
	if( pxQueue->pcHead != 0 )
	{
		pxQueue->pcReadFrom += pxQueue->uxItemSize;
		if( pxQueue->pcReadFrom >= pxQueue->pcTail )
		{
			pxQueue->pcReadFrom = pxQueue->pcHead;
		}
		memcpy( ( void * ) pvBuffer, ( void * ) pxQueue->pcReadFrom, ( size_t ) pxQueue->uxItemSize );
	}
}
 

static void prvUnlockQueue( xQUEUE *pxQueue )
{
	 

	


 
	vPortEnterCritical();
	{
		 
		while( pxQueue->xTxLock > ( ( signed long ) 0 ) )
		{
			
 
#line 1399 "..\\free_rtos\\queue.c"
			{
				
 
				if( ( ( &( pxQueue ->xTasksWaitingToReceive ) )->uxNumberOfItems == ( unsigned long ) 0 ) == ( 0 ) )
				{
					if( xTaskRemoveFromEventList( &( pxQueue->xTasksWaitingToReceive ) ) != ( 0 ) )
					{
						
 
						vTaskMissedYield();
					}
				}
				else
				{
					break;
				}
			}


			--( pxQueue->xTxLock );
		}

		pxQueue->xTxLock = ( ( signed long ) -1 );
	}
	vPortExitCritical();

	 
	vPortEnterCritical();
	{
		while( pxQueue->xRxLock > ( ( signed long ) 0 ) )
		{
			if( ( ( &( pxQueue ->xTasksWaitingToSend ) )->uxNumberOfItems == ( unsigned long ) 0 ) == ( 0 ) )
			{
				if( xTaskRemoveFromEventList( &( pxQueue->xTasksWaitingToSend ) ) != ( 0 ) )
				{
					vTaskMissedYield();
				}

				--( pxQueue->xRxLock );
			}
			else
			{
				break;
			}
		}

		pxQueue->xRxLock = ( ( signed long ) -1 );
	}
	vPortExitCritical();
}
 

static signed long prvIsQueueEmpty( const xQUEUE *pxQueue )
{
signed long xReturn;

	vPortEnterCritical();
	{
		if( pxQueue->uxMessagesWaiting == 0 )
		{
			xReturn = ( 1 );
		}
		else
		{
			xReturn = ( 0 );
		}
	}
	vPortExitCritical();

	return xReturn;
}
 

signed long xQueueIsQueueEmptyFromISR( const xQueueHandle xQueue )
{
signed long xReturn;

	;
	if( ( ( xQUEUE * ) xQueue )->uxMessagesWaiting == 0 )
	{
		xReturn = ( 1 );
	}
	else
	{
		xReturn = ( 0 );
	}

	return xReturn;
}
 

static signed long prvIsQueueFull( const xQUEUE *pxQueue )
{
signed long xReturn;

	vPortEnterCritical();
	{
		if( pxQueue->uxMessagesWaiting == pxQueue->uxLength )
		{
			xReturn = ( 1 );
		}
		else
		{
			xReturn = ( 0 );
		}
	}
	vPortExitCritical();

	return xReturn;
}
 

signed long xQueueIsQueueFullFromISR( const xQueueHandle xQueue )
{
signed long xReturn;

	;
	if( ( ( xQUEUE * ) xQueue )->uxMessagesWaiting == ( ( xQUEUE * ) xQueue )->uxLength )
	{
		xReturn = ( 1 );
	}
	else
	{
		xReturn = ( 0 );
	}

	return xReturn;
}
 

#line 1598 "..\\free_rtos\\queue.c"
 

#line 1674 "..\\free_rtos\\queue.c"
 

#line 1708 "..\\free_rtos\\queue.c"
 

#line 1754 "..\\free_rtos\\queue.c"
 

#line 1777 "..\\free_rtos\\queue.c"
 

#line 1800 "..\\free_rtos\\queue.c"
 

#line 1834 "..\\free_rtos\\queue.c"
 

#line 1848 "..\\free_rtos\\queue.c"
 

#line 1874 "..\\free_rtos\\queue.c"
 

#line 1912 "..\\free_rtos\\queue.c"
 

#line 1925 "..\\free_rtos\\queue.c"
 

#line 1938 "..\\free_rtos\\queue.c"
 

#line 1969 "..\\free_rtos\\queue.c"

