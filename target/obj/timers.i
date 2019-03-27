#line 1 "..\\free_rtos\\timers.c"








































































 



 


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





















































 




#line 81 "..\\free_rtos\\timers.c"
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








#line 82 "..\\free_rtos\\timers.c"
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








#line 83 "..\\free_rtos\\timers.c"
#line 1 "..\\free_rtos\\timers.h"








































































 









#line 84 "..\\free_rtos\\timers.h"
#line 85 "..\\free_rtos\\timers.h"
#line 86 "..\\free_rtos\\timers.h"







 







 

 




 
typedef void * xTimerHandle;

 
typedef void (*tmrTIMER_CALLBACK)( xTimerHandle xTimer );































































































































 
xTimerHandle xTimerCreate( const signed char * const pcTimerName, portTickType xTimerPeriodInTicks, unsigned long uxAutoReload, void * pvTimerID, tmrTIMER_CALLBACK pxCallbackFunction ) ;




















 
void *pvTimerGetTimerID( xTimerHandle xTimer ) ;


































 
long xTimerIsTimerActive( xTimerHandle xTimer ) ;







 
xTaskHandle xTimerGetTimerDaemonTaskHandle( void );


















































 









































 














































































 





































 


























































































































 



















































































 





























































 







































































 




















































































 





 
long xTimerCreateTimerTask( void ) ;
long xTimerGenericCommand( xTimerHandle xTimer, long xCommandID, portTickType xOptionalValue, signed long *pxHigherPriorityTaskWoken, portTickType xBlockTime ) ;








#line 84 "..\\free_rtos\\timers.c"






 
#line 693 "..\\free_rtos\\timers.c"



