#line 1 "..\\usr_lib\\usr_delay.c"



  
#line 1 "..\\usr_lib\\usr_sys.h"





#line 1 "..\\main\\stm32f10x.h"







































 



 



 
    






  


 
  


 

#line 75 "..\\main\\stm32f10x.h"


















 





#line 107 "..\\main\\stm32f10x.h"







            



#line 125 "..\\main\\stm32f10x.h"





 






 
#line 146 "..\\main\\stm32f10x.h"



 



 



 
#line 165 "..\\main\\stm32f10x.h"




 
typedef enum IRQn
{
 
  NonMaskableInt_IRQn         = -14,     
  MemoryManagement_IRQn       = -12,     
  BusFault_IRQn               = -11,     
  UsageFault_IRQn             = -10,     
  SVCall_IRQn                 = -5,      
  DebugMonitor_IRQn           = -4,      
  PendSV_IRQn                 = -2,      
  SysTick_IRQn                = -1,      

 
  WWDG_IRQn                   = 0,       
  PVD_IRQn                    = 1,       
  TAMPER_IRQn                 = 2,       
  RTC_IRQn                    = 3,       
  FLASH_IRQn                  = 4,       
  RCC_IRQn                    = 5,       
  EXTI0_IRQn                  = 6,       
  EXTI1_IRQn                  = 7,       
  EXTI2_IRQn                  = 8,       
  EXTI3_IRQn                  = 9,       
  EXTI4_IRQn                  = 10,      
  DMA1_Channel1_IRQn          = 11,      
  DMA1_Channel2_IRQn          = 12,      
  DMA1_Channel3_IRQn          = 13,      
  DMA1_Channel4_IRQn          = 14,      
  DMA1_Channel5_IRQn          = 15,      
  DMA1_Channel6_IRQn          = 16,      
  DMA1_Channel7_IRQn          = 17,      

#line 224 "..\\main\\stm32f10x.h"

#line 245 "..\\main\\stm32f10x.h"


  ADC1_2_IRQn                 = 18,      
  USB_HP_CAN1_TX_IRQn         = 19,      
  USB_LP_CAN1_RX0_IRQn        = 20,      
  CAN1_RX1_IRQn               = 21,      
  CAN1_SCE_IRQn               = 22,      
  EXTI9_5_IRQn                = 23,      
  TIM1_BRK_IRQn               = 24,      
  TIM1_UP_IRQn                = 25,      
  TIM1_TRG_COM_IRQn           = 26,      
  TIM1_CC_IRQn                = 27,      
  TIM2_IRQn                   = 28,      
  TIM3_IRQn                   = 29,      
  TIM4_IRQn                   = 30,      
  I2C1_EV_IRQn                = 31,      
  I2C1_ER_IRQn                = 32,      
  I2C2_EV_IRQn                = 33,      
  I2C2_ER_IRQn                = 34,      
  SPI1_IRQn                   = 35,      
  SPI2_IRQn                   = 36,      
  USART1_IRQn                 = 37,      
  USART2_IRQn                 = 38,      
  USART3_IRQn                 = 39,      
  EXTI15_10_IRQn              = 40,      
  RTCAlarm_IRQn               = 41,      
  USBWakeUp_IRQn              = 42         


#line 299 "..\\main\\stm32f10x.h"

#line 344 "..\\main\\stm32f10x.h"

#line 384 "..\\main\\stm32f10x.h"

#line 429 "..\\main\\stm32f10x.h"

#line 475 "..\\main\\stm32f10x.h"
} IRQn_Type;



 

#line 1 "..\\cmsis\\core_cm3.h"
 




















 





































 

 
 
 
 
 
 
 
 








 











#line 1 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"
 
 





 









     
#line 27 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"
     











#line 46 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"





 

     

     
typedef   signed          char int8_t;
typedef   signed short     int int16_t;
typedef   signed           int int32_t;
typedef   signed       __int64 int64_t;

     
typedef unsigned          char uint8_t;
typedef unsigned short     int uint16_t;
typedef unsigned           int uint32_t;
typedef unsigned       __int64 uint64_t;

     

     
     
typedef   signed          char int_least8_t;
typedef   signed short     int int_least16_t;
typedef   signed           int int_least32_t;
typedef   signed       __int64 int_least64_t;

     
typedef unsigned          char uint_least8_t;
typedef unsigned short     int uint_least16_t;
typedef unsigned           int uint_least32_t;
typedef unsigned       __int64 uint_least64_t;

     

     
typedef   signed           int int_fast8_t;
typedef   signed           int int_fast16_t;
typedef   signed           int int_fast32_t;
typedef   signed       __int64 int_fast64_t;

     
typedef unsigned           int uint_fast8_t;
typedef unsigned           int uint_fast16_t;
typedef unsigned           int uint_fast32_t;
typedef unsigned       __int64 uint_fast64_t;

     




typedef   signed           int intptr_t;
typedef unsigned           int uintptr_t;


     
typedef   signed     long long intmax_t;
typedef unsigned     long long uintmax_t;




     

     





     





     





     

     





     





     





     

     





     





     





     

     






     






     






     

     


     


     


     

     
#line 216 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"

     



     






     
    
 



#line 241 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"

     







     










     











#line 305 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"






 
#line 91 "..\\cmsis\\core_cm3.h"

















 

#line 117 "..\\cmsis\\core_cm3.h"





 


 





 
typedef struct
{
  volatile uint32_t ISER[8];                       
       uint32_t RESERVED0[24];                                   
  volatile uint32_t ICER[8];                       
       uint32_t RSERVED1[24];                                    
  volatile uint32_t ISPR[8];                       
       uint32_t RESERVED2[24];                                   
  volatile uint32_t ICPR[8];                       
       uint32_t RESERVED3[24];                                   
  volatile uint32_t IABR[8];                       
       uint32_t RESERVED4[56];                                   
  volatile uint8_t  IP[240];                       
       uint32_t RESERVED5[644];                                  
  volatile  uint32_t STIR;                          
}  NVIC_Type;                                               
   





 
typedef struct
{
  volatile const  uint32_t CPUID;                         
  volatile uint32_t ICSR;                          
  volatile uint32_t VTOR;                          
  volatile uint32_t AIRCR;                         
  volatile uint32_t SCR;                           
  volatile uint32_t CCR;                           
  volatile uint8_t  SHP[12];                       
  volatile uint32_t SHCSR;                         
  volatile uint32_t CFSR;                          
  volatile uint32_t HFSR;                          
  volatile uint32_t DFSR;                          
  volatile uint32_t MMFAR;                         
  volatile uint32_t BFAR;                          
  volatile uint32_t AFSR;                          
  volatile const  uint32_t PFR[2];                        
  volatile const  uint32_t DFR;                           
  volatile const  uint32_t ADR;                           
  volatile const  uint32_t MMFR[4];                       
  volatile const  uint32_t ISAR[5];                       
} SCB_Type;                                                

 












 






























 






 





















 









 


















 
































                                     









 









 









 














   





 
typedef struct
{
  volatile uint32_t CTRL;                          
  volatile uint32_t LOAD;                          
  volatile uint32_t VAL;                           
  volatile const  uint32_t CALIB;                         
} SysTick_Type;

 












 



 



 








   





 
typedef struct
{
  volatile  union  
  {
    volatile  uint8_t    u8;                        
    volatile  uint16_t   u16;                       
    volatile  uint32_t   u32;                       
  }  PORT [32];                                
       uint32_t RESERVED0[864];                                 
  volatile uint32_t TER;                           
       uint32_t RESERVED1[15];                                  
  volatile uint32_t TPR;                           
       uint32_t RESERVED2[15];                                  
  volatile uint32_t TCR;                           
       uint32_t RESERVED3[29];                                  
  volatile uint32_t IWR;                           
  volatile uint32_t IRR;                           
  volatile uint32_t IMCR;                          
       uint32_t RESERVED4[43];                                  
  volatile uint32_t LAR;                           
  volatile uint32_t LSR;                           
       uint32_t RESERVED5[6];                                   
  volatile const  uint32_t PID4;                          
  volatile const  uint32_t PID5;                          
  volatile const  uint32_t PID6;                          
  volatile const  uint32_t PID7;                          
  volatile const  uint32_t PID0;                          
  volatile const  uint32_t PID1;                          
  volatile const  uint32_t PID2;                          
  volatile const  uint32_t PID3;                          
  volatile const  uint32_t CID0;                          
  volatile const  uint32_t CID1;                          
  volatile const  uint32_t CID2;                          
  volatile const  uint32_t CID3;                          
} ITM_Type;                                                

 



 
























 



 



 



 








   





 
typedef struct
{
       uint32_t RESERVED0;
  volatile const  uint32_t ICTR;                          



       uint32_t RESERVED1;

} InterruptType_Type;

 



 








   


#line 614 "..\\cmsis\\core_cm3.h"





 
typedef struct
{
  volatile uint32_t DHCSR;                         
  volatile  uint32_t DCRSR;                         
  volatile uint32_t DCRDR;                         
  volatile uint32_t DEMCR;                         
} CoreDebug_Type;

 




































 






 






































   


 
#line 721 "..\\cmsis\\core_cm3.h"

#line 728 "..\\cmsis\\core_cm3.h"






   




 





#line 758 "..\\cmsis\\core_cm3.h"


 


 




#line 783 "..\\cmsis\\core_cm3.h"


 
 
 
 








 
extern uint32_t __get_PSP(void);








 
extern void __set_PSP(uint32_t topOfProcStack);








 
extern uint32_t __get_MSP(void);








 
extern void __set_MSP(uint32_t topOfMainStack);








 
extern uint32_t __REV16(uint16_t value);








 
extern int32_t __REVSH(int16_t value);


#line 933 "..\\cmsis\\core_cm3.h"





 








 
static __inline uint32_t  __get_BASEPRI(void)
{
  register uint32_t __regBasePri         __asm("basepri");
  return(__regBasePri);
}







 
static __inline void __set_BASEPRI(uint32_t basePri)
{
  register uint32_t __regBasePri         __asm("basepri");
  __regBasePri = (basePri & 0xff);
}







 
static __inline uint32_t __get_PRIMASK(void)
{
  register uint32_t __regPriMask         __asm("primask");
  return(__regPriMask);
}







 
static __inline void __set_PRIMASK(uint32_t priMask)
{
  register uint32_t __regPriMask         __asm("primask");
  __regPriMask = (priMask);
}







 
static __inline uint32_t __get_FAULTMASK(void)
{
  register uint32_t __regFaultMask       __asm("faultmask");
  return(__regFaultMask);
}







 
static __inline void __set_FAULTMASK(uint32_t faultMask)
{
  register uint32_t __regFaultMask       __asm("faultmask");
  __regFaultMask = (faultMask & 1);
}







 
static __inline uint32_t __get_CONTROL(void)
{
  register uint32_t __regControl         __asm("control");
  return(__regControl);
}







 
static __inline void __set_CONTROL(uint32_t control)
{
  register uint32_t __regControl         __asm("control");
  __regControl = control;
}





#line 1445 "..\\cmsis\\core_cm3.h"







 
 

 











 
static __inline void NVIC_SetPriorityGrouping(uint32_t PriorityGroup)
{
  uint32_t reg_value;
  uint32_t PriorityGroupTmp = (PriorityGroup & 0x07);                          
  
  reg_value  =  ((SCB_Type *) ((0xE000E000) + 0x0D00))->AIRCR;                                                    
  reg_value &= ~((0xFFFFul << 16) | (7ul << 8));              
  reg_value  =  (reg_value                       |
                (0x5FA << 16) | 
                (PriorityGroupTmp << 8));                                      
  ((SCB_Type *) ((0xE000E000) + 0x0D00))->AIRCR =  reg_value;
}








 
static __inline uint32_t NVIC_GetPriorityGrouping(void)
{
  return ((((SCB_Type *) ((0xE000E000) + 0x0D00))->AIRCR & (7ul << 8)) >> 8);    
}








 
static __inline void NVIC_EnableIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000) + 0x0100))->ISER[((uint32_t)(IRQn) >> 5)] = (1 << ((uint32_t)(IRQn) & 0x1F));  
}








 
static __inline void NVIC_DisableIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000) + 0x0100))->ICER[((uint32_t)(IRQn) >> 5)] = (1 << ((uint32_t)(IRQn) & 0x1F));  
}









 
static __inline uint32_t NVIC_GetPendingIRQ(IRQn_Type IRQn)
{
  return((uint32_t) ((((NVIC_Type *) ((0xE000E000) + 0x0100))->ISPR[(uint32_t)(IRQn) >> 5] & (1 << ((uint32_t)(IRQn) & 0x1F)))?1:0));  
}








 
static __inline void NVIC_SetPendingIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000) + 0x0100))->ISPR[((uint32_t)(IRQn) >> 5)] = (1 << ((uint32_t)(IRQn) & 0x1F));  
}








 
static __inline void NVIC_ClearPendingIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000) + 0x0100))->ICPR[((uint32_t)(IRQn) >> 5)] = (1 << ((uint32_t)(IRQn) & 0x1F));  
}









 
static __inline uint32_t NVIC_GetActive(IRQn_Type IRQn)
{
  return((uint32_t)((((NVIC_Type *) ((0xE000E000) + 0x0100))->IABR[(uint32_t)(IRQn) >> 5] & (1 << ((uint32_t)(IRQn) & 0x1F)))?1:0));  
}












 
static __inline void NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority)
{
  if(IRQn < 0) {
    ((SCB_Type *) ((0xE000E000) + 0x0D00))->SHP[((uint32_t)(IRQn) & 0xF)-4] = ((priority << (8 - 4)) & 0xff); }  
  else {
    ((NVIC_Type *) ((0xE000E000) + 0x0100))->IP[(uint32_t)(IRQn)] = ((priority << (8 - 4)) & 0xff);    }         
}















 
static __inline uint32_t NVIC_GetPriority(IRQn_Type IRQn)
{

  if(IRQn < 0) {
    return((uint32_t)(((SCB_Type *) ((0xE000E000) + 0x0D00))->SHP[((uint32_t)(IRQn) & 0xF)-4] >> (8 - 4)));  }  
  else {
    return((uint32_t)(((NVIC_Type *) ((0xE000E000) + 0x0100))->IP[(uint32_t)(IRQn)]           >> (8 - 4)));  }  
}
















 
static __inline uint32_t NVIC_EncodePriority (uint32_t PriorityGroup, uint32_t PreemptPriority, uint32_t SubPriority)
{
  uint32_t PriorityGroupTmp = (PriorityGroup & 0x07);           
  uint32_t PreemptPriorityBits;
  uint32_t SubPriorityBits;

  PreemptPriorityBits = ((7 - PriorityGroupTmp) > 4) ? 4 : 7 - PriorityGroupTmp;
  SubPriorityBits     = ((PriorityGroupTmp + 4) < 7) ? 0 : PriorityGroupTmp - 7 + 4;
 
  return (
           ((PreemptPriority & ((1 << (PreemptPriorityBits)) - 1)) << SubPriorityBits) |
           ((SubPriority     & ((1 << (SubPriorityBits    )) - 1)))
         );
}
















 
static __inline void NVIC_DecodePriority (uint32_t Priority, uint32_t PriorityGroup, uint32_t* pPreemptPriority, uint32_t* pSubPriority)
{
  uint32_t PriorityGroupTmp = (PriorityGroup & 0x07);           
  uint32_t PreemptPriorityBits;
  uint32_t SubPriorityBits;

  PreemptPriorityBits = ((7 - PriorityGroupTmp) > 4) ? 4 : 7 - PriorityGroupTmp;
  SubPriorityBits     = ((PriorityGroupTmp + 4) < 7) ? 0 : PriorityGroupTmp - 7 + 4;
  
  *pPreemptPriority = (Priority >> SubPriorityBits) & ((1 << (PreemptPriorityBits)) - 1);
  *pSubPriority     = (Priority                   ) & ((1 << (SubPriorityBits    )) - 1);
}



 












 
static __inline uint32_t SysTick_Config(uint32_t ticks)
{ 
  if (ticks > (0xFFFFFFul << 0))  return (1);             
                                                               
  ((SysTick_Type *) ((0xE000E000) + 0x0010))->LOAD  = (ticks & (0xFFFFFFul << 0)) - 1;       
  NVIC_SetPriority (SysTick_IRQn, (1<<4) - 1);   
  ((SysTick_Type *) ((0xE000E000) + 0x0010))->VAL   = 0;                                           
  ((SysTick_Type *) ((0xE000E000) + 0x0010))->CTRL  = (1ul << 2) | 
                   (1ul << 1)   | 
                   (1ul << 0);                     
  return (0);                                                   
}






 





 
static __inline void NVIC_SystemReset(void)
{
  ((SCB_Type *) ((0xE000E000) + 0x0D00))->AIRCR  = ((0x5FA << 16)      | 
                 (((SCB_Type *) ((0xE000E000) + 0x0D00))->AIRCR & (7ul << 8)) | 
                 (1ul << 2));                    
  __dsb(0);                                                                    
  while(1);                                                     
}

   



 






 
 

extern volatile int ITM_RxBuffer;                     












 
static __inline uint32_t ITM_SendChar (uint32_t ch)
{
  if ((((CoreDebug_Type *) (0xE000EDF0))->DEMCR & (1ul << 24))  &&       
      (((ITM_Type *) (0xE0000000))->TCR & (1ul << 0))                  &&       
      (((ITM_Type *) (0xE0000000))->TER & (1ul << 0)        )                    )      
  {
    while (((ITM_Type *) (0xE0000000))->PORT[0].u32 == 0);
    ((ITM_Type *) (0xE0000000))->PORT[0].u8 = (uint8_t) ch;
  }  
  return (ch);
}










 
static __inline int ITM_ReceiveChar (void) {
  int ch = -1;                                

  if (ITM_RxBuffer != 0x5AA55AA5) {
    ch = ITM_RxBuffer;
    ITM_RxBuffer = 0x5AA55AA5;        
  }
  
  return (ch); 
}









 
static __inline int ITM_CheckChar (void) {

  if (ITM_RxBuffer == 0x5AA55AA5) {
    return (0);                                  
  } else {
    return (1);                                  
  }
}

   






   



 
#line 482 "..\\main\\stm32f10x.h"
#line 1 "..\\main\\system_stm32f10x.h"



















 



 



   
  


 









 



 




 

extern uint32_t SystemCoreClock;           



 



 



 



 



 



 
  
extern void SystemInit(void);
extern void SystemCoreClockUpdate(void);


 









 
  


   
 
#line 483 "..\\main\\stm32f10x.h"
#line 484 "..\\main\\stm32f10x.h"



   

 
typedef int32_t  s32;
typedef int16_t s16;
typedef int8_t  s8;

typedef const int32_t sc32;   
typedef const int16_t sc16;   
typedef const int8_t sc8;    

typedef volatile int32_t  vs32;
typedef volatile int16_t  vs16;
typedef volatile int8_t   vs8;

typedef volatile const int32_t vsc32;   
typedef volatile const int16_t vsc16;   
typedef volatile const int8_t vsc8;    

typedef uint32_t  u32;
typedef uint16_t u16;
typedef uint8_t  u8;

typedef const uint32_t uc32;   
typedef const uint16_t uc16;   
typedef const uint8_t uc8;    

typedef volatile uint32_t  vu32;
typedef volatile uint16_t vu16;
typedef volatile uint8_t  vu8;

typedef volatile const uint32_t vuc32;   
typedef volatile const uint16_t vuc16;   
typedef volatile const uint8_t vuc8;    

typedef enum {RESET = 0, SET = !RESET} FlagStatus, ITStatus;

typedef enum {DISABLE = 0, ENABLE = !DISABLE} FunctionalState;


typedef enum {ERROR = 0, SUCCESS = !ERROR} ErrorStatus;

 





 



    



 

typedef struct
{
  volatile uint32_t SR;
  volatile uint32_t CR1;
  volatile uint32_t CR2;
  volatile uint32_t SMPR1;
  volatile uint32_t SMPR2;
  volatile uint32_t JOFR1;
  volatile uint32_t JOFR2;
  volatile uint32_t JOFR3;
  volatile uint32_t JOFR4;
  volatile uint32_t HTR;
  volatile uint32_t LTR;
  volatile uint32_t SQR1;
  volatile uint32_t SQR2;
  volatile uint32_t SQR3;
  volatile uint32_t JSQR;
  volatile uint32_t JDR1;
  volatile uint32_t JDR2;
  volatile uint32_t JDR3;
  volatile uint32_t JDR4;
  volatile uint32_t DR;
} ADC_TypeDef;



 

typedef struct
{
  uint32_t  RESERVED0;
  volatile uint16_t DR1;
  uint16_t  RESERVED1;
  volatile uint16_t DR2;
  uint16_t  RESERVED2;
  volatile uint16_t DR3;
  uint16_t  RESERVED3;
  volatile uint16_t DR4;
  uint16_t  RESERVED4;
  volatile uint16_t DR5;
  uint16_t  RESERVED5;
  volatile uint16_t DR6;
  uint16_t  RESERVED6;
  volatile uint16_t DR7;
  uint16_t  RESERVED7;
  volatile uint16_t DR8;
  uint16_t  RESERVED8;
  volatile uint16_t DR9;
  uint16_t  RESERVED9;
  volatile uint16_t DR10;
  uint16_t  RESERVED10; 
  volatile uint16_t RTCCR;
  uint16_t  RESERVED11;
  volatile uint16_t CR;
  uint16_t  RESERVED12;
  volatile uint16_t CSR;
  uint16_t  RESERVED13[5];
  volatile uint16_t DR11;
  uint16_t  RESERVED14;
  volatile uint16_t DR12;
  uint16_t  RESERVED15;
  volatile uint16_t DR13;
  uint16_t  RESERVED16;
  volatile uint16_t DR14;
  uint16_t  RESERVED17;
  volatile uint16_t DR15;
  uint16_t  RESERVED18;
  volatile uint16_t DR16;
  uint16_t  RESERVED19;
  volatile uint16_t DR17;
  uint16_t  RESERVED20;
  volatile uint16_t DR18;
  uint16_t  RESERVED21;
  volatile uint16_t DR19;
  uint16_t  RESERVED22;
  volatile uint16_t DR20;
  uint16_t  RESERVED23;
  volatile uint16_t DR21;
  uint16_t  RESERVED24;
  volatile uint16_t DR22;
  uint16_t  RESERVED25;
  volatile uint16_t DR23;
  uint16_t  RESERVED26;
  volatile uint16_t DR24;
  uint16_t  RESERVED27;
  volatile uint16_t DR25;
  uint16_t  RESERVED28;
  volatile uint16_t DR26;
  uint16_t  RESERVED29;
  volatile uint16_t DR27;
  uint16_t  RESERVED30;
  volatile uint16_t DR28;
  uint16_t  RESERVED31;
  volatile uint16_t DR29;
  uint16_t  RESERVED32;
  volatile uint16_t DR30;
  uint16_t  RESERVED33; 
  volatile uint16_t DR31;
  uint16_t  RESERVED34;
  volatile uint16_t DR32;
  uint16_t  RESERVED35;
  volatile uint16_t DR33;
  uint16_t  RESERVED36;
  volatile uint16_t DR34;
  uint16_t  RESERVED37;
  volatile uint16_t DR35;
  uint16_t  RESERVED38;
  volatile uint16_t DR36;
  uint16_t  RESERVED39;
  volatile uint16_t DR37;
  uint16_t  RESERVED40;
  volatile uint16_t DR38;
  uint16_t  RESERVED41;
  volatile uint16_t DR39;
  uint16_t  RESERVED42;
  volatile uint16_t DR40;
  uint16_t  RESERVED43;
  volatile uint16_t DR41;
  uint16_t  RESERVED44;
  volatile uint16_t DR42;
  uint16_t  RESERVED45;    
} BKP_TypeDef;
  


 

typedef struct
{
  volatile uint32_t TIR;
  volatile uint32_t TDTR;
  volatile uint32_t TDLR;
  volatile uint32_t TDHR;
} CAN_TxMailBox_TypeDef;



 
  
typedef struct
{
  volatile uint32_t RIR;
  volatile uint32_t RDTR;
  volatile uint32_t RDLR;
  volatile uint32_t RDHR;
} CAN_FIFOMailBox_TypeDef;



 
  
typedef struct
{
  volatile uint32_t FR1;
  volatile uint32_t FR2;
} CAN_FilterRegister_TypeDef;



 
  
typedef struct
{
  volatile uint32_t MCR;
  volatile uint32_t MSR;
  volatile uint32_t TSR;
  volatile uint32_t RF0R;
  volatile uint32_t RF1R;
  volatile uint32_t IER;
  volatile uint32_t ESR;
  volatile uint32_t BTR;
  uint32_t  RESERVED0[88];
  CAN_TxMailBox_TypeDef sTxMailBox[3];
  CAN_FIFOMailBox_TypeDef sFIFOMailBox[2];
  uint32_t  RESERVED1[12];
  volatile uint32_t FMR;
  volatile uint32_t FM1R;
  uint32_t  RESERVED2;
  volatile uint32_t FS1R;
  uint32_t  RESERVED3;
  volatile uint32_t FFA1R;
  uint32_t  RESERVED4;
  volatile uint32_t FA1R;
  uint32_t  RESERVED5[8];

  CAN_FilterRegister_TypeDef sFilterRegister[14];



} CAN_TypeDef;



 
typedef struct
{
  volatile uint32_t CFGR;
  volatile uint32_t OAR;
  volatile uint32_t PRES;
  volatile uint32_t ESR;
  volatile uint32_t CSR;
  volatile uint32_t TXD;
  volatile uint32_t RXD;  
} CEC_TypeDef;



 

typedef struct
{
  volatile uint32_t DR;
  volatile uint8_t  IDR;
  uint8_t   RESERVED0;
  uint16_t  RESERVED1;
  volatile uint32_t CR;
} CRC_TypeDef;



 

typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t SWTRIGR;
  volatile uint32_t DHR12R1;
  volatile uint32_t DHR12L1;
  volatile uint32_t DHR8R1;
  volatile uint32_t DHR12R2;
  volatile uint32_t DHR12L2;
  volatile uint32_t DHR8R2;
  volatile uint32_t DHR12RD;
  volatile uint32_t DHR12LD;
  volatile uint32_t DHR8RD;
  volatile uint32_t DOR1;
  volatile uint32_t DOR2;



} DAC_TypeDef;



 

typedef struct
{
  volatile uint32_t IDCODE;
  volatile uint32_t CR;	
}DBGMCU_TypeDef;



 

typedef struct
{
  volatile uint32_t CCR;
  volatile uint32_t CNDTR;
  volatile uint32_t CPAR;
  volatile uint32_t CMAR;
} DMA_Channel_TypeDef;

typedef struct
{
  volatile uint32_t ISR;
  volatile uint32_t IFCR;
} DMA_TypeDef;



 

typedef struct
{
  volatile uint32_t MACCR;
  volatile uint32_t MACFFR;
  volatile uint32_t MACHTHR;
  volatile uint32_t MACHTLR;
  volatile uint32_t MACMIIAR;
  volatile uint32_t MACMIIDR;
  volatile uint32_t MACFCR;
  volatile uint32_t MACVLANTR;              
       uint32_t RESERVED0[2];
  volatile uint32_t MACRWUFFR;              
  volatile uint32_t MACPMTCSR;
       uint32_t RESERVED1[2];
  volatile uint32_t MACSR;                  
  volatile uint32_t MACIMR;
  volatile uint32_t MACA0HR;
  volatile uint32_t MACA0LR;
  volatile uint32_t MACA1HR;
  volatile uint32_t MACA1LR;
  volatile uint32_t MACA2HR;
  volatile uint32_t MACA2LR;
  volatile uint32_t MACA3HR;
  volatile uint32_t MACA3LR;                
       uint32_t RESERVED2[40];
  volatile uint32_t MMCCR;                  
  volatile uint32_t MMCRIR;
  volatile uint32_t MMCTIR;
  volatile uint32_t MMCRIMR;
  volatile uint32_t MMCTIMR;                
       uint32_t RESERVED3[14];
  volatile uint32_t MMCTGFSCCR;             
  volatile uint32_t MMCTGFMSCCR;
       uint32_t RESERVED4[5];
  volatile uint32_t MMCTGFCR;
       uint32_t RESERVED5[10];
  volatile uint32_t MMCRFCECR;
  volatile uint32_t MMCRFAECR;
       uint32_t RESERVED6[10];
  volatile uint32_t MMCRGUFCR;
       uint32_t RESERVED7[334];
  volatile uint32_t PTPTSCR;
  volatile uint32_t PTPSSIR;
  volatile uint32_t PTPTSHR;
  volatile uint32_t PTPTSLR;
  volatile uint32_t PTPTSHUR;
  volatile uint32_t PTPTSLUR;
  volatile uint32_t PTPTSAR;
  volatile uint32_t PTPTTHR;
  volatile uint32_t PTPTTLR;
       uint32_t RESERVED8[567];
  volatile uint32_t DMABMR;
  volatile uint32_t DMATPDR;
  volatile uint32_t DMARPDR;
  volatile uint32_t DMARDLAR;
  volatile uint32_t DMATDLAR;
  volatile uint32_t DMASR;
  volatile uint32_t DMAOMR;
  volatile uint32_t DMAIER;
  volatile uint32_t DMAMFBOCR;
       uint32_t RESERVED9[9];
  volatile uint32_t DMACHTDR;
  volatile uint32_t DMACHRDR;
  volatile uint32_t DMACHTBAR;
  volatile uint32_t DMACHRBAR;
} ETH_TypeDef;



 

typedef struct
{
  volatile uint32_t IMR;
  volatile uint32_t EMR;
  volatile uint32_t RTSR;
  volatile uint32_t FTSR;
  volatile uint32_t SWIER;
  volatile uint32_t PR;
} EXTI_TypeDef;



 

typedef struct
{
  volatile uint32_t ACR;
  volatile uint32_t KEYR;
  volatile uint32_t OPTKEYR;
  volatile uint32_t SR;
  volatile uint32_t CR;
  volatile uint32_t AR;
  volatile uint32_t RESERVED;
  volatile uint32_t OBR;
  volatile uint32_t WRPR;
#line 923 "..\\main\\stm32f10x.h"
} FLASH_TypeDef;



 
  
typedef struct
{
  volatile uint16_t RDP;
  volatile uint16_t USER;
  volatile uint16_t Data0;
  volatile uint16_t Data1;
  volatile uint16_t WRP0;
  volatile uint16_t WRP1;
  volatile uint16_t WRP2;
  volatile uint16_t WRP3;
} OB_TypeDef;



 

typedef struct
{
  volatile uint32_t BTCR[8];   
} FSMC_Bank1_TypeDef; 



 
  
typedef struct
{
  volatile uint32_t BWTR[7];
} FSMC_Bank1E_TypeDef;



 
  
typedef struct
{
  volatile uint32_t PCR2;
  volatile uint32_t SR2;
  volatile uint32_t PMEM2;
  volatile uint32_t PATT2;
  uint32_t  RESERVED0;   
  volatile uint32_t ECCR2; 
} FSMC_Bank2_TypeDef;  



 
  
typedef struct
{
  volatile uint32_t PCR3;
  volatile uint32_t SR3;
  volatile uint32_t PMEM3;
  volatile uint32_t PATT3;
  uint32_t  RESERVED0;   
  volatile uint32_t ECCR3; 
} FSMC_Bank3_TypeDef; 



 
  
typedef struct
{
  volatile uint32_t PCR4;
  volatile uint32_t SR4;
  volatile uint32_t PMEM4;
  volatile uint32_t PATT4;
  volatile uint32_t PIO4; 
} FSMC_Bank4_TypeDef; 



 

typedef struct
{
  volatile uint32_t CRL;
  volatile uint32_t CRH;
  volatile uint32_t IDR;
  volatile uint32_t ODR;
  volatile uint32_t BSRR;
  volatile uint32_t BRR;
  volatile uint32_t LCKR;
} GPIO_TypeDef;



 

typedef struct
{
  volatile uint32_t EVCR;
  volatile uint32_t MAPR;
  volatile uint32_t EXTICR[4];
  uint32_t RESERVED0;
  volatile uint32_t MAPR2;  
} AFIO_TypeDef;


 

typedef struct
{
  volatile uint16_t CR1;
  uint16_t  RESERVED0;
  volatile uint16_t CR2;
  uint16_t  RESERVED1;
  volatile uint16_t OAR1;
  uint16_t  RESERVED2;
  volatile uint16_t OAR2;
  uint16_t  RESERVED3;
  volatile uint16_t DR;
  uint16_t  RESERVED4;
  volatile uint16_t SR1;
  uint16_t  RESERVED5;
  volatile uint16_t SR2;
  uint16_t  RESERVED6;
  volatile uint16_t CCR;
  uint16_t  RESERVED7;
  volatile uint16_t TRISE;
  uint16_t  RESERVED8;
} I2C_TypeDef;



 

typedef struct
{
  volatile uint32_t KR;
  volatile uint32_t PR;
  volatile uint32_t RLR;
  volatile uint32_t SR;
} IWDG_TypeDef;



 

typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t CSR;
} PWR_TypeDef;



 

typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t CFGR;
  volatile uint32_t CIR;
  volatile uint32_t APB2RSTR;
  volatile uint32_t APB1RSTR;
  volatile uint32_t AHBENR;
  volatile uint32_t APB2ENR;
  volatile uint32_t APB1ENR;
  volatile uint32_t BDCR;
  volatile uint32_t CSR;










} RCC_TypeDef;



 

typedef struct
{
  volatile uint16_t CRH;
  uint16_t  RESERVED0;
  volatile uint16_t CRL;
  uint16_t  RESERVED1;
  volatile uint16_t PRLH;
  uint16_t  RESERVED2;
  volatile uint16_t PRLL;
  uint16_t  RESERVED3;
  volatile uint16_t DIVH;
  uint16_t  RESERVED4;
  volatile uint16_t DIVL;
  uint16_t  RESERVED5;
  volatile uint16_t CNTH;
  uint16_t  RESERVED6;
  volatile uint16_t CNTL;
  uint16_t  RESERVED7;
  volatile uint16_t ALRH;
  uint16_t  RESERVED8;
  volatile uint16_t ALRL;
  uint16_t  RESERVED9;
} RTC_TypeDef;



 

typedef struct
{
  volatile uint32_t POWER;
  volatile uint32_t CLKCR;
  volatile uint32_t ARG;
  volatile uint32_t CMD;
  volatile const uint32_t RESPCMD;
  volatile const uint32_t RESP1;
  volatile const uint32_t RESP2;
  volatile const uint32_t RESP3;
  volatile const uint32_t RESP4;
  volatile uint32_t DTIMER;
  volatile uint32_t DLEN;
  volatile uint32_t DCTRL;
  volatile const uint32_t DCOUNT;
  volatile const uint32_t STA;
  volatile uint32_t ICR;
  volatile uint32_t MASK;
  uint32_t  RESERVED0[2];
  volatile const uint32_t FIFOCNT;
  uint32_t  RESERVED1[13];
  volatile uint32_t FIFO;
} SDIO_TypeDef;



 

typedef struct
{
  volatile uint16_t CR1;
  uint16_t  RESERVED0;
  volatile uint16_t CR2;
  uint16_t  RESERVED1;
  volatile uint16_t SR;
  uint16_t  RESERVED2;
  volatile uint16_t DR;
  uint16_t  RESERVED3;
  volatile uint16_t CRCPR;
  uint16_t  RESERVED4;
  volatile uint16_t RXCRCR;
  uint16_t  RESERVED5;
  volatile uint16_t TXCRCR;
  uint16_t  RESERVED6;
  volatile uint16_t I2SCFGR;
  uint16_t  RESERVED7;
  volatile uint16_t I2SPR;
  uint16_t  RESERVED8;  
} SPI_TypeDef;



 

typedef struct
{
  volatile uint16_t CR1;
  uint16_t  RESERVED0;
  volatile uint16_t CR2;
  uint16_t  RESERVED1;
  volatile uint16_t SMCR;
  uint16_t  RESERVED2;
  volatile uint16_t DIER;
  uint16_t  RESERVED3;
  volatile uint16_t SR;
  uint16_t  RESERVED4;
  volatile uint16_t EGR;
  uint16_t  RESERVED5;
  volatile uint16_t CCMR1;
  uint16_t  RESERVED6;
  volatile uint16_t CCMR2;
  uint16_t  RESERVED7;
  volatile uint16_t CCER;
  uint16_t  RESERVED8;
  volatile uint16_t CNT;
  uint16_t  RESERVED9;
  volatile uint16_t PSC;
  uint16_t  RESERVED10;
  volatile uint16_t ARR;
  uint16_t  RESERVED11;
  volatile uint16_t RCR;
  uint16_t  RESERVED12;
  volatile uint16_t CCR1;
  uint16_t  RESERVED13;
  volatile uint16_t CCR2;
  uint16_t  RESERVED14;
  volatile uint16_t CCR3;
  uint16_t  RESERVED15;
  volatile uint16_t CCR4;
  uint16_t  RESERVED16;
  volatile uint16_t BDTR;
  uint16_t  RESERVED17;
  volatile uint16_t DCR;
  uint16_t  RESERVED18;
  volatile uint16_t DMAR;
  uint16_t  RESERVED19;
} TIM_TypeDef;



 
 
typedef struct
{
  volatile uint16_t SR;
  uint16_t  RESERVED0;
  volatile uint16_t DR;
  uint16_t  RESERVED1;
  volatile uint16_t BRR;
  uint16_t  RESERVED2;
  volatile uint16_t CR1;
  uint16_t  RESERVED3;
  volatile uint16_t CR2;
  uint16_t  RESERVED4;
  volatile uint16_t CR3;
  uint16_t  RESERVED5;
  volatile uint16_t GTPR;
  uint16_t  RESERVED6;
} USART_TypeDef;



 

typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t CFR;
  volatile uint32_t SR;
} WWDG_TypeDef;



 
  


 











 




#line 1315 "..\\main\\stm32f10x.h"

#line 1338 "..\\main\\stm32f10x.h"



#line 1357 "..\\main\\stm32f10x.h"




















 
  


   

#line 1457 "..\\main\\stm32f10x.h"



 



 
  
  

 
    
 
 
 

 
 
 
 
 

 



 



 


 
 
 
 
 

 











 
#line 1518 "..\\main\\stm32f10x.h"




 





 
 
 
 
 

 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 





 



 






 
 
 
 
 

 
#line 1694 "..\\main\\stm32f10x.h"

#line 1701 "..\\main\\stm32f10x.h"

 
 








 








 






#line 1737 "..\\main\\stm32f10x.h"

 











 











 













 






#line 1853 "..\\main\\stm32f10x.h"




#line 1873 "..\\main\\stm32f10x.h"

 





#line 1886 "..\\main\\stm32f10x.h"

 
#line 1905 "..\\main\\stm32f10x.h"

#line 1914 "..\\main\\stm32f10x.h"

 
#line 1922 "..\\main\\stm32f10x.h"



















#line 1947 "..\\main\\stm32f10x.h"












 













#line 1979 "..\\main\\stm32f10x.h"





#line 1993 "..\\main\\stm32f10x.h"

#line 2000 "..\\main\\stm32f10x.h"

#line 2010 "..\\main\\stm32f10x.h"











 


















#line 2046 "..\\main\\stm32f10x.h"

 
#line 2054 "..\\main\\stm32f10x.h"



















#line 2079 "..\\main\\stm32f10x.h"












 













#line 2111 "..\\main\\stm32f10x.h"





#line 2125 "..\\main\\stm32f10x.h"

#line 2132 "..\\main\\stm32f10x.h"

#line 2142 "..\\main\\stm32f10x.h"











 








 








   
#line 2181 "..\\main\\stm32f10x.h"

#line 2276 "..\\main\\stm32f10x.h"

#line 2303 "..\\main\\stm32f10x.h"
 
 
 
 
 
 

 




































































 




































































 
#line 2465 "..\\main\\stm32f10x.h"

 
#line 2483 "..\\main\\stm32f10x.h"

 
#line 2501 "..\\main\\stm32f10x.h"

#line 2518 "..\\main\\stm32f10x.h"

 
#line 2536 "..\\main\\stm32f10x.h"

 
#line 2555 "..\\main\\stm32f10x.h"

 

 






 
#line 2582 "..\\main\\stm32f10x.h"






 








 









 








 








 









 










 




#line 2657 "..\\main\\stm32f10x.h"

 










#line 2688 "..\\main\\stm32f10x.h"

 





 
#line 2703 "..\\main\\stm32f10x.h"

 
#line 2712 "..\\main\\stm32f10x.h"

   
#line 2721 "..\\main\\stm32f10x.h"

 
#line 2730 "..\\main\\stm32f10x.h"

 





 
#line 2745 "..\\main\\stm32f10x.h"

 
#line 2754 "..\\main\\stm32f10x.h"

   
#line 2763 "..\\main\\stm32f10x.h"

 
#line 2772 "..\\main\\stm32f10x.h"

 





 
#line 2787 "..\\main\\stm32f10x.h"

 
#line 2796 "..\\main\\stm32f10x.h"

   
#line 2805 "..\\main\\stm32f10x.h"

 
#line 2814 "..\\main\\stm32f10x.h"

 





 
#line 2829 "..\\main\\stm32f10x.h"

 
#line 2838 "..\\main\\stm32f10x.h"

   
#line 2847 "..\\main\\stm32f10x.h"

 
#line 2856 "..\\main\\stm32f10x.h"

#line 2865 "..\\main\\stm32f10x.h"

#line 2874 "..\\main\\stm32f10x.h"

#line 2884 "..\\main\\stm32f10x.h"

 
 
 
 
 

 





 


 


 




 
 
 
 
 

 
#line 2948 "..\\main\\stm32f10x.h"

 
#line 2983 "..\\main\\stm32f10x.h"

 
#line 3018 "..\\main\\stm32f10x.h"

 
#line 3053 "..\\main\\stm32f10x.h"

 
#line 3088 "..\\main\\stm32f10x.h"

 





 





 





 





 





 





 





 





 






 
#line 3155 "..\\main\\stm32f10x.h"

 



 









 
#line 3179 "..\\main\\stm32f10x.h"




 




 
#line 3195 "..\\main\\stm32f10x.h"

 





 
#line 3217 "..\\main\\stm32f10x.h"

 
 





 
#line 3232 "..\\main\\stm32f10x.h"
 
#line 3239 "..\\main\\stm32f10x.h"

 




 






 


 


 


 
 
 
 
 

 
#line 3288 "..\\main\\stm32f10x.h"

 
#line 3310 "..\\main\\stm32f10x.h"

 
#line 3332 "..\\main\\stm32f10x.h"

 
#line 3354 "..\\main\\stm32f10x.h"

 
#line 3376 "..\\main\\stm32f10x.h"

 
#line 3398 "..\\main\\stm32f10x.h"

 
 
 
 
 

 
#line 3434 "..\\main\\stm32f10x.h"

 
#line 3464 "..\\main\\stm32f10x.h"

 
#line 3474 "..\\main\\stm32f10x.h"















 
#line 3498 "..\\main\\stm32f10x.h"















 
#line 3522 "..\\main\\stm32f10x.h"















 
#line 3546 "..\\main\\stm32f10x.h"















 
#line 3570 "..\\main\\stm32f10x.h"















 
#line 3594 "..\\main\\stm32f10x.h"















 
#line 3618 "..\\main\\stm32f10x.h"















 


 


 


 


 


 


 


 


 


 



 


 


 



 


 


 


 



 


 


 


 


 
 
 
 
 

 






 
#line 3719 "..\\main\\stm32f10x.h"

#line 3728 "..\\main\\stm32f10x.h"















  
 
#line 3751 "..\\main\\stm32f10x.h"


















 








































 


















































 


 


 


 


 


 


 
#line 3886 "..\\main\\stm32f10x.h"

#line 3893 "..\\main\\stm32f10x.h"

#line 3900 "..\\main\\stm32f10x.h"

#line 3907 "..\\main\\stm32f10x.h"







 
#line 3921 "..\\main\\stm32f10x.h"

#line 3928 "..\\main\\stm32f10x.h"

#line 3935 "..\\main\\stm32f10x.h"

#line 3942 "..\\main\\stm32f10x.h"

#line 3949 "..\\main\\stm32f10x.h"

#line 3956 "..\\main\\stm32f10x.h"

 
#line 3964 "..\\main\\stm32f10x.h"

#line 3971 "..\\main\\stm32f10x.h"

#line 3978 "..\\main\\stm32f10x.h"

#line 3985 "..\\main\\stm32f10x.h"

#line 3992 "..\\main\\stm32f10x.h"

#line 3999 "..\\main\\stm32f10x.h"

 
#line 4007 "..\\main\\stm32f10x.h"

#line 4014 "..\\main\\stm32f10x.h"

#line 4021 "..\\main\\stm32f10x.h"

#line 4028 "..\\main\\stm32f10x.h"





 


 


 


 


 



 
 
 
 
 

 









































 



 


 


 


 


 


 


 



 



 



 


 


 



 
 
 
 
 
 





 






 


 
#line 4170 "..\\main\\stm32f10x.h"

 
#line 4180 "..\\main\\stm32f10x.h"

 


 


 
 
 
 
 

 
















 









#line 4228 "..\\main\\stm32f10x.h"

 

























 
#line 4271 "..\\main\\stm32f10x.h"

 
#line 4285 "..\\main\\stm32f10x.h"

 
#line 4295 "..\\main\\stm32f10x.h"

 




























 





















 




























 





















 
#line 4414 "..\\main\\stm32f10x.h"

 


 


 


 


 


 


 


 


 
#line 4449 "..\\main\\stm32f10x.h"





#line 4460 "..\\main\\stm32f10x.h"

 
#line 4468 "..\\main\\stm32f10x.h"

#line 4475 "..\\main\\stm32f10x.h"

 


 
 
 
 
 

 




 
#line 4497 "..\\main\\stm32f10x.h"

 


 


 


 


 


 


 


 


 
 
 
 
 

 


 





 


 



 
 
 
 
 

 
#line 4559 "..\\main\\stm32f10x.h"



 
#line 4571 "..\\main\\stm32f10x.h"







 


 
 
 
 
 

 











#line 4609 "..\\main\\stm32f10x.h"

 











#line 4632 "..\\main\\stm32f10x.h"

 











#line 4655 "..\\main\\stm32f10x.h"

 











#line 4678 "..\\main\\stm32f10x.h"

 








































 








































 








































 








































 


































 


































 


































 


































 



























 



























 



























 
#line 5075 "..\\main\\stm32f10x.h"

 
#line 5084 "..\\main\\stm32f10x.h"

 
#line 5093 "..\\main\\stm32f10x.h"

 
#line 5104 "..\\main\\stm32f10x.h"

#line 5114 "..\\main\\stm32f10x.h"

#line 5124 "..\\main\\stm32f10x.h"

#line 5134 "..\\main\\stm32f10x.h"

 
#line 5145 "..\\main\\stm32f10x.h"

#line 5155 "..\\main\\stm32f10x.h"

#line 5165 "..\\main\\stm32f10x.h"

#line 5175 "..\\main\\stm32f10x.h"

 
#line 5186 "..\\main\\stm32f10x.h"

#line 5196 "..\\main\\stm32f10x.h"

#line 5206 "..\\main\\stm32f10x.h"

#line 5216 "..\\main\\stm32f10x.h"

 
#line 5227 "..\\main\\stm32f10x.h"

#line 5237 "..\\main\\stm32f10x.h"

#line 5247 "..\\main\\stm32f10x.h"

#line 5257 "..\\main\\stm32f10x.h"

 
#line 5268 "..\\main\\stm32f10x.h"

#line 5278 "..\\main\\stm32f10x.h"

#line 5288 "..\\main\\stm32f10x.h"

#line 5298 "..\\main\\stm32f10x.h"

 
#line 5309 "..\\main\\stm32f10x.h"

#line 5319 "..\\main\\stm32f10x.h"

#line 5329 "..\\main\\stm32f10x.h"

#line 5339 "..\\main\\stm32f10x.h"

 
#line 5350 "..\\main\\stm32f10x.h"

#line 5360 "..\\main\\stm32f10x.h"

#line 5370 "..\\main\\stm32f10x.h"

#line 5380 "..\\main\\stm32f10x.h"

 


 


 
 
 
 
 

 




 












 


 






#line 5428 "..\\main\\stm32f10x.h"

 


 


 


 


 


 


 


 


 
















 


 
#line 5498 "..\\main\\stm32f10x.h"

 
#line 5513 "..\\main\\stm32f10x.h"

 
#line 5539 "..\\main\\stm32f10x.h"

 


 


 
 
 
 
 

 
 























 























 























 























 























 























 























 























 
 
#line 5760 "..\\main\\stm32f10x.h"

 
#line 5772 "..\\main\\stm32f10x.h"

 






 
#line 5789 "..\\main\\stm32f10x.h"



     


 
 


 


 


 


 


 


 


 


 

 


 


 


 


 


 


 


 


 

 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 

 


 


 


 


 


 


 


 


 

 


#line 5933 "..\\main\\stm32f10x.h"



 


#line 5945 "..\\main\\stm32f10x.h"



 


#line 5957 "..\\main\\stm32f10x.h"



 


#line 5969 "..\\main\\stm32f10x.h"



 


#line 5981 "..\\main\\stm32f10x.h"



 


#line 5993 "..\\main\\stm32f10x.h"



 


#line 6005 "..\\main\\stm32f10x.h"



 


#line 6017 "..\\main\\stm32f10x.h"



 

 


#line 6031 "..\\main\\stm32f10x.h"



 


#line 6043 "..\\main\\stm32f10x.h"



 


#line 6055 "..\\main\\stm32f10x.h"



 


#line 6067 "..\\main\\stm32f10x.h"



 


#line 6079 "..\\main\\stm32f10x.h"



 


#line 6091 "..\\main\\stm32f10x.h"



 


#line 6103 "..\\main\\stm32f10x.h"



 


#line 6115 "..\\main\\stm32f10x.h"



 


#line 6127 "..\\main\\stm32f10x.h"



 


#line 6139 "..\\main\\stm32f10x.h"



 


#line 6151 "..\\main\\stm32f10x.h"



 


#line 6163 "..\\main\\stm32f10x.h"



 


#line 6175 "..\\main\\stm32f10x.h"



 


#line 6187 "..\\main\\stm32f10x.h"



 


#line 6199 "..\\main\\stm32f10x.h"



 


#line 6211 "..\\main\\stm32f10x.h"



 
 
 
 
 

 
 
#line 6231 "..\\main\\stm32f10x.h"

 
#line 6242 "..\\main\\stm32f10x.h"

 
#line 6260 "..\\main\\stm32f10x.h"











 





 





 
#line 6298 "..\\main\\stm32f10x.h"

 












 
#line 6319 "..\\main\\stm32f10x.h"

 
 






 




 





 





 






 




 





 





 






   




 





 





 





 




 





 





 





 




 





 





 
 


 
#line 6459 "..\\main\\stm32f10x.h"

 
#line 6476 "..\\main\\stm32f10x.h"

 
#line 6493 "..\\main\\stm32f10x.h"

 
#line 6510 "..\\main\\stm32f10x.h"

 
#line 6544 "..\\main\\stm32f10x.h"

 
#line 6578 "..\\main\\stm32f10x.h"

 
#line 6612 "..\\main\\stm32f10x.h"

 
#line 6646 "..\\main\\stm32f10x.h"

 
#line 6680 "..\\main\\stm32f10x.h"

 
#line 6714 "..\\main\\stm32f10x.h"

 
#line 6748 "..\\main\\stm32f10x.h"

 
#line 6782 "..\\main\\stm32f10x.h"

 
#line 6816 "..\\main\\stm32f10x.h"

 
#line 6850 "..\\main\\stm32f10x.h"

 
#line 6884 "..\\main\\stm32f10x.h"

 
#line 6918 "..\\main\\stm32f10x.h"

 
#line 6952 "..\\main\\stm32f10x.h"

 
#line 6986 "..\\main\\stm32f10x.h"

 
#line 7020 "..\\main\\stm32f10x.h"

 
#line 7054 "..\\main\\stm32f10x.h"

 
#line 7088 "..\\main\\stm32f10x.h"

 
#line 7122 "..\\main\\stm32f10x.h"

 
#line 7156 "..\\main\\stm32f10x.h"

 
#line 7190 "..\\main\\stm32f10x.h"

 
#line 7224 "..\\main\\stm32f10x.h"

 
#line 7258 "..\\main\\stm32f10x.h"

 
#line 7292 "..\\main\\stm32f10x.h"

 
#line 7326 "..\\main\\stm32f10x.h"

 
#line 7360 "..\\main\\stm32f10x.h"

 
#line 7394 "..\\main\\stm32f10x.h"

 
#line 7428 "..\\main\\stm32f10x.h"

 
#line 7462 "..\\main\\stm32f10x.h"

 
 
 
 
 

 









#line 7489 "..\\main\\stm32f10x.h"

 
#line 7497 "..\\main\\stm32f10x.h"

 
#line 7507 "..\\main\\stm32f10x.h"

 


 


 


 


 





















 




 
 
 
 
 

 
#line 7568 "..\\main\\stm32f10x.h"

 
#line 7577 "..\\main\\stm32f10x.h"







 



#line 7598 "..\\main\\stm32f10x.h"



 



 


 
#line 7623 "..\\main\\stm32f10x.h"

 
#line 7633 "..\\main\\stm32f10x.h"

 




 


 
 
 
 
 

 
#line 7659 "..\\main\\stm32f10x.h"

 


 



 
#line 7683 "..\\main\\stm32f10x.h"

 
#line 7692 "..\\main\\stm32f10x.h"







 
#line 7712 "..\\main\\stm32f10x.h"

 
#line 7723 "..\\main\\stm32f10x.h"



 
 
 
 
 

 


#line 7752 "..\\main\\stm32f10x.h"

 









#line 7786 "..\\main\\stm32f10x.h"

 
 
 
 
 

 









 


 


 





 
#line 7826 "..\\main\\stm32f10x.h"

 


 









 


 

 



 



 



 



 



 



 



 



#line 8290 "..\\main\\stm32f10x.h"



 

 

  

#line 1 "..\\main\\stm32f10x_conf.h"



















 

 



 
 
#line 1 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_adc.h"




















 

 







 
#line 1 "..\\main\\stm32f10x.h"







































 



 



 
    
#line 8330 "..\\main\\stm32f10x.h"



 

  

 

 
#line 33 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_adc.h"



 



 



 



 

typedef struct
{
  uint32_t ADC_Mode;                      

 

  FunctionalState ADC_ScanConvMode;       

 

  FunctionalState ADC_ContinuousConvMode; 

 

  uint32_t ADC_ExternalTrigConv;          

 

  uint32_t ADC_DataAlign;                 
 

  uint8_t ADC_NbrOfChannel;               

 
}ADC_InitTypeDef;


 



 










 

#line 104 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_adc.h"

#line 115 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_adc.h"


 



 

#line 129 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_adc.h"




#line 139 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_adc.h"

#line 154 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_adc.h"


 



 







 



 

#line 192 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_adc.h"




#line 205 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_adc.h"


 



 

#line 229 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_adc.h"


 



 

















#line 266 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_adc.h"


 



 

#line 282 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_adc.h"


 



 

#line 297 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_adc.h"

#line 305 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_adc.h"


 



 











 



 

#line 338 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_adc.h"


 



 





 



 





 



 





 



 





  




 




 



 





 



 





 



 



 



 



 

void ADC_DeInit(ADC_TypeDef* ADCx);
void ADC_Init(ADC_TypeDef* ADCx, ADC_InitTypeDef* ADC_InitStruct);
void ADC_StructInit(ADC_InitTypeDef* ADC_InitStruct);
void ADC_Cmd(ADC_TypeDef* ADCx, FunctionalState NewState);
void ADC_DMACmd(ADC_TypeDef* ADCx, FunctionalState NewState);
void ADC_ITConfig(ADC_TypeDef* ADCx, uint16_t ADC_IT, FunctionalState NewState);
void ADC_ResetCalibration(ADC_TypeDef* ADCx);
FlagStatus ADC_GetResetCalibrationStatus(ADC_TypeDef* ADCx);
void ADC_StartCalibration(ADC_TypeDef* ADCx);
FlagStatus ADC_GetCalibrationStatus(ADC_TypeDef* ADCx);
void ADC_SoftwareStartConvCmd(ADC_TypeDef* ADCx, FunctionalState NewState);
FlagStatus ADC_GetSoftwareStartConvStatus(ADC_TypeDef* ADCx);
void ADC_DiscModeChannelCountConfig(ADC_TypeDef* ADCx, uint8_t Number);
void ADC_DiscModeCmd(ADC_TypeDef* ADCx, FunctionalState NewState);
void ADC_RegularChannelConfig(ADC_TypeDef* ADCx, uint8_t ADC_Channel, uint8_t Rank, uint8_t ADC_SampleTime);
void ADC_ExternalTrigConvCmd(ADC_TypeDef* ADCx, FunctionalState NewState);
uint16_t ADC_GetConversionValue(ADC_TypeDef* ADCx);
uint32_t ADC_GetDualModeConversionValue(void);
void ADC_AutoInjectedConvCmd(ADC_TypeDef* ADCx, FunctionalState NewState);
void ADC_InjectedDiscModeCmd(ADC_TypeDef* ADCx, FunctionalState NewState);
void ADC_ExternalTrigInjectedConvConfig(ADC_TypeDef* ADCx, uint32_t ADC_ExternalTrigInjecConv);
void ADC_ExternalTrigInjectedConvCmd(ADC_TypeDef* ADCx, FunctionalState NewState);
void ADC_SoftwareStartInjectedConvCmd(ADC_TypeDef* ADCx, FunctionalState NewState);
FlagStatus ADC_GetSoftwareStartInjectedConvCmdStatus(ADC_TypeDef* ADCx);
void ADC_InjectedChannelConfig(ADC_TypeDef* ADCx, uint8_t ADC_Channel, uint8_t Rank, uint8_t ADC_SampleTime);
void ADC_InjectedSequencerLengthConfig(ADC_TypeDef* ADCx, uint8_t Length);
void ADC_SetInjectedOffset(ADC_TypeDef* ADCx, uint8_t ADC_InjectedChannel, uint16_t Offset);
uint16_t ADC_GetInjectedConversionValue(ADC_TypeDef* ADCx, uint8_t ADC_InjectedChannel);
void ADC_AnalogWatchdogCmd(ADC_TypeDef* ADCx, uint32_t ADC_AnalogWatchdog);
void ADC_AnalogWatchdogThresholdsConfig(ADC_TypeDef* ADCx, uint16_t HighThreshold, uint16_t LowThreshold);
void ADC_AnalogWatchdogSingleChannelConfig(ADC_TypeDef* ADCx, uint8_t ADC_Channel);
void ADC_TempSensorVrefintCmd(FunctionalState NewState);
FlagStatus ADC_GetFlagStatus(ADC_TypeDef* ADCx, uint8_t ADC_FLAG);
void ADC_ClearFlag(ADC_TypeDef* ADCx, uint8_t ADC_FLAG);
ITStatus ADC_GetITStatus(ADC_TypeDef* ADCx, uint16_t ADC_IT);
void ADC_ClearITPendingBit(ADC_TypeDef* ADCx, uint16_t ADC_IT);









 



 



 

 
#line 29 "..\\main\\stm32f10x_conf.h"
#line 1 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_bkp.h"




















 

 







 
#line 33 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_bkp.h"



 



 



 



 



 



 







 



 

#line 78 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_bkp.h"


 



 

#line 128 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_bkp.h"

#line 143 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_bkp.h"




 



 



 



 



 

void BKP_DeInit(void);
void BKP_TamperPinLevelConfig(uint16_t BKP_TamperPinLevel);
void BKP_TamperPinCmd(FunctionalState NewState);
void BKP_ITConfig(FunctionalState NewState);
void BKP_RTCOutputConfig(uint16_t BKP_RTCOutputSource);
void BKP_SetRTCCalibrationValue(uint8_t CalibrationValue);
void BKP_WriteBackupRegister(uint16_t BKP_DR, uint16_t Data);
uint16_t BKP_ReadBackupRegister(uint16_t BKP_DR);
FlagStatus BKP_GetFlagStatus(void);
void BKP_ClearFlag(void);
ITStatus BKP_GetITStatus(void);
void BKP_ClearITPendingBit(void);








 



 



 

 
#line 30 "..\\main\\stm32f10x_conf.h"



#line 1 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_dac.h"




















 

 







 
#line 33 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_dac.h"



 



 



 



 

typedef struct
{
  uint32_t DAC_Trigger;                      
 

  uint32_t DAC_WaveGeneration;               

 

  uint32_t DAC_LFSRUnmask_TriangleAmplitude; 

 

  uint32_t DAC_OutputBuffer;                 
 
}DAC_InitTypeDef;



 



 



 

#line 94 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_dac.h"

#line 104 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_dac.h"



 



 

#line 119 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_dac.h"


 



 

#line 151 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_dac.h"

#line 176 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_dac.h"


 



 







 



 







 



 

#line 214 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_dac.h"


 



 







 



 




 
#line 261 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_dac.h"



 



 



 



 

void DAC_DeInit(void);
void DAC_Init(uint32_t DAC_Channel, DAC_InitTypeDef* DAC_InitStruct);
void DAC_StructInit(DAC_InitTypeDef* DAC_InitStruct);
void DAC_Cmd(uint32_t DAC_Channel, FunctionalState NewState);



void DAC_DMACmd(uint32_t DAC_Channel, FunctionalState NewState);
void DAC_SoftwareTriggerCmd(uint32_t DAC_Channel, FunctionalState NewState);
void DAC_DualSoftwareTriggerCmd(FunctionalState NewState);
void DAC_WaveGenerationCmd(uint32_t DAC_Channel, uint32_t DAC_Wave, FunctionalState NewState);
void DAC_SetChannel1Data(uint32_t DAC_Align, uint16_t Data);
void DAC_SetChannel2Data(uint32_t DAC_Align, uint16_t Data);
void DAC_SetDualChannelData(uint32_t DAC_Align, uint16_t Data2, uint16_t Data1);
uint16_t DAC_GetDataOutputValue(uint32_t DAC_Channel);
#line 299 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_dac.h"








 



 



 

 
#line 34 "..\\main\\stm32f10x_conf.h"
#line 1 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_dbgmcu.h"




















 

 







 
#line 33 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_dbgmcu.h"



 



 



 



 



 

#line 80 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_dbgmcu.h"
                                              



  



 



 



 

uint32_t DBGMCU_GetREVID(void);
uint32_t DBGMCU_GetDEVID(void);
void DBGMCU_Config(uint32_t DBGMCU_Periph, FunctionalState NewState);








 



 



 

 
#line 35 "..\\main\\stm32f10x_conf.h"




#line 1 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_gpio.h"




















 

 







 
#line 33 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_gpio.h"



 



 



 

#line 53 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_gpio.h"
                                     


 

typedef enum
{ 
  GPIO_Speed_10MHz = 1,
  GPIO_Speed_2MHz, 
  GPIO_Speed_50MHz
}GPIOSpeed_TypeDef;





 

typedef enum
{ GPIO_Mode_AIN = 0x0,
  GPIO_Mode_IN_FLOATING = 0x04,
  GPIO_Mode_IPD = 0x28,
  GPIO_Mode_IPU = 0x48,
  GPIO_Mode_Out_OD = 0x14,
  GPIO_Mode_Out_PP = 0x10,
  GPIO_Mode_AF_OD = 0x1C,
  GPIO_Mode_AF_PP = 0x18
}GPIOMode_TypeDef;








 

typedef struct
{
  uint16_t GPIO_Pin;             
 

  GPIOSpeed_TypeDef GPIO_Speed;  
 

  GPIOMode_TypeDef GPIO_Mode;    
 
}GPIO_InitTypeDef;




 

typedef enum
{ Bit_RESET = 0,
  Bit_SET
}BitAction;





 



 



 

#line 144 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_gpio.h"



#line 163 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_gpio.h"



 



 

#line 204 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_gpio.h"







#line 217 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_gpio.h"






#line 245 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_gpio.h"
                              


  



 

#line 266 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_gpio.h"

#line 274 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_gpio.h"



 



 

#line 299 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_gpio.h"

#line 316 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_gpio.h"



 



  








                                                 


 



 



 



 

void GPIO_DeInit(GPIO_TypeDef* GPIOx);
void GPIO_AFIODeInit(void);
void GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* GPIO_InitStruct);
void GPIO_StructInit(GPIO_InitTypeDef* GPIO_InitStruct);
uint8_t GPIO_ReadInputDataBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
uint16_t GPIO_ReadInputData(GPIO_TypeDef* GPIOx);
uint8_t GPIO_ReadOutputDataBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
uint16_t GPIO_ReadOutputData(GPIO_TypeDef* GPIOx);
void GPIO_SetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void GPIO_ResetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void GPIO_WriteBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, BitAction BitVal);
void GPIO_Write(GPIO_TypeDef* GPIOx, uint16_t PortVal);
void GPIO_PinLockConfig(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void GPIO_EventOutputConfig(uint8_t GPIO_PortSource, uint8_t GPIO_PinSource);
void GPIO_EventOutputCmd(FunctionalState NewState);
void GPIO_PinRemapConfig(uint32_t GPIO_Remap, FunctionalState NewState);
void GPIO_EXTILineConfig(uint8_t GPIO_PortSource, uint8_t GPIO_PinSource);
void GPIO_ETH_MediaInterfaceConfig(uint32_t GPIO_ETH_MediaInterface);








 



 



 

 
#line 40 "..\\main\\stm32f10x_conf.h"


#line 1 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_pwr.h"




















 

 







 
#line 33 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_pwr.h"



 



  



  



  



  



  

#line 70 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_pwr.h"


 



 







 



 




 


 



 










 



 



 



 



 

void PWR_DeInit(void);
void PWR_BackupAccessCmd(FunctionalState NewState);
void PWR_PVDCmd(FunctionalState NewState);
void PWR_PVDLevelConfig(uint32_t PWR_PVDLevel);
void PWR_WakeUpPinCmd(FunctionalState NewState);
void PWR_EnterSTOPMode(uint32_t PWR_Regulator, uint8_t PWR_STOPEntry);
void PWR_EnterSTANDBYMode(void);
FlagStatus PWR_GetFlagStatus(uint32_t PWR_FLAG);
void PWR_ClearFlag(uint32_t PWR_FLAG);








 



 



 

 
#line 43 "..\\main\\stm32f10x_conf.h"
#line 1 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_rcc.h"




















 

 







 
#line 33 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_rcc.h"



 



 



 

typedef struct
{
  uint32_t SYSCLK_Frequency;   
  uint32_t HCLK_Frequency;     
  uint32_t PCLK1_Frequency;    
  uint32_t PCLK2_Frequency;    
  uint32_t ADCCLK_Frequency;   
}RCC_ClocksTypeDef;



 



 



 









  



 



#line 94 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_rcc.h"



  



 
#line 126 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_rcc.h"

#line 141 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_rcc.h"


 



 
#line 175 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_rcc.h"


 




 
#line 196 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_rcc.h"


 

#line 283 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_rcc.h"




 

#line 295 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_rcc.h"


 



 

#line 317 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_rcc.h"


  



 

#line 333 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_rcc.h"


 



 

#line 347 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_rcc.h"

#line 364 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_rcc.h"




 




 








 
#line 396 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_rcc.h"


#line 423 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_rcc.h"
  



 

#line 435 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_rcc.h"


 



 








 



 

#line 462 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_rcc.h"


 



 







#line 489 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_rcc.h"


 



 

#line 518 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_rcc.h"




  



 

#line 553 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_rcc.h"
 




 



 







#line 586 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_rcc.h"



 



 

#line 606 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_rcc.h"

#line 625 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_rcc.h"




 



 



 



 



 

void RCC_DeInit(void);
void RCC_HSEConfig(uint32_t RCC_HSE);
ErrorStatus RCC_WaitForHSEStartUp(void);
void RCC_AdjustHSICalibrationValue(uint8_t HSICalibrationValue);
void RCC_HSICmd(FunctionalState NewState);
void RCC_PLLConfig(uint32_t RCC_PLLSource, uint32_t RCC_PLLMul);
void RCC_PLLCmd(FunctionalState NewState);





#line 666 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_rcc.h"

void RCC_SYSCLKConfig(uint32_t RCC_SYSCLKSource);
uint8_t RCC_GetSYSCLKSource(void);
void RCC_HCLKConfig(uint32_t RCC_SYSCLK);
void RCC_PCLK1Config(uint32_t RCC_HCLK);
void RCC_PCLK2Config(uint32_t RCC_HCLK);
void RCC_ITConfig(uint8_t RCC_IT, FunctionalState NewState);


 void RCC_USBCLKConfig(uint32_t RCC_USBCLKSource);




void RCC_ADCCLKConfig(uint32_t RCC_PCLK2);






void RCC_LSEConfig(uint8_t RCC_LSE);
void RCC_LSICmd(FunctionalState NewState);
void RCC_RTCCLKConfig(uint32_t RCC_RTCCLKSource);
void RCC_RTCCLKCmd(FunctionalState NewState);
void RCC_GetClocksFreq(RCC_ClocksTypeDef* RCC_Clocks);
void RCC_AHBPeriphClockCmd(uint32_t RCC_AHBPeriph, FunctionalState NewState);
void RCC_APB2PeriphClockCmd(uint32_t RCC_APB2Periph, FunctionalState NewState);
void RCC_APB1PeriphClockCmd(uint32_t RCC_APB1Periph, FunctionalState NewState);





void RCC_APB2PeriphResetCmd(uint32_t RCC_APB2Periph, FunctionalState NewState);
void RCC_APB1PeriphResetCmd(uint32_t RCC_APB1Periph, FunctionalState NewState);
void RCC_BackupResetCmd(FunctionalState NewState);
void RCC_ClockSecuritySystemCmd(FunctionalState NewState);
void RCC_MCOConfig(uint8_t RCC_MCO);
FlagStatus RCC_GetFlagStatus(uint8_t RCC_FLAG);
void RCC_ClearFlag(void);
ITStatus RCC_GetITStatus(uint8_t RCC_IT);
void RCC_ClearITPendingBit(uint8_t RCC_IT);








 



 



  

 
#line 44 "..\\main\\stm32f10x_conf.h"
#line 1 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_rtc.h"




















 

 







 
#line 33 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_rtc.h"



 



  



  



  



 



 

#line 64 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_rtc.h"


  



 

#line 82 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_rtc.h"



 



 



 



 



 

void RTC_ITConfig(uint16_t RTC_IT, FunctionalState NewState);
void RTC_EnterConfigMode(void);
void RTC_ExitConfigMode(void);
uint32_t  RTC_GetCounter(void);
void RTC_SetCounter(uint32_t CounterValue);
void RTC_SetPrescaler(uint32_t PrescalerValue);
void RTC_SetAlarm(uint32_t AlarmValue);
uint32_t  RTC_GetDivider(void);
void RTC_WaitForLastTask(void);
void RTC_WaitForSynchro(void);
FlagStatus RTC_GetFlagStatus(uint16_t RTC_FLAG);
void RTC_ClearFlag(uint16_t RTC_FLAG);
ITStatus RTC_GetITStatus(uint16_t RTC_IT);
void RTC_ClearITPendingBit(uint16_t RTC_IT);








 



 



 

 
#line 45 "..\\main\\stm32f10x_conf.h"


#line 1 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_tim.h"




















 

 







 
#line 33 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_tim.h"



 



  



  




 

typedef struct
{
  uint16_t TIM_Prescaler;         
 

  uint16_t TIM_CounterMode;       
 

  uint16_t TIM_Period;            

  

  uint16_t TIM_ClockDivision;     
 

  uint8_t TIM_RepetitionCounter;  






 
} TIM_TimeBaseInitTypeDef;       



 

typedef struct
{
  uint16_t TIM_OCMode;        
 

  uint16_t TIM_OutputState;   
 

  uint16_t TIM_OutputNState;  

 

  uint16_t TIM_Pulse;         
 

  uint16_t TIM_OCPolarity;    
 

  uint16_t TIM_OCNPolarity;   

 

  uint16_t TIM_OCIdleState;   

 

  uint16_t TIM_OCNIdleState;  

 
} TIM_OCInitTypeDef;



 

typedef struct
{

  uint16_t TIM_Channel;      
 

  uint16_t TIM_ICPolarity;   
 

  uint16_t TIM_ICSelection;  
 

  uint16_t TIM_ICPrescaler;  
 

  uint16_t TIM_ICFilter;     
 
} TIM_ICInitTypeDef;




 

typedef struct
{

  uint16_t TIM_OSSRState;        
 

  uint16_t TIM_OSSIState;        
 

  uint16_t TIM_LOCKLevel;        
  

  uint16_t TIM_DeadTime;         

 

  uint16_t TIM_Break;            
 

  uint16_t TIM_BreakPolarity;    
 

  uint16_t TIM_AutomaticOutput;  
 
} TIM_BDTRInitTypeDef;



 

#line 186 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_tim.h"

 



 






 
#line 205 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_tim.h"
									                                 
 
#line 216 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_tim.h"

                                             
#line 225 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_tim.h"

 
#line 236 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_tim.h"

 
#line 249 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_tim.h"

                                         
#line 266 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_tim.h"

 
#line 279 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_tim.h"
                                                                                                                                                                                                                          


  



 

#line 308 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_tim.h"


 



 







  



 

#line 341 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_tim.h"


  



 

#line 355 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_tim.h"


 



 

#line 373 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_tim.h"


  



 







 



 
  






 



 







  



 







  



 







  



 







  



 







  



 







  



 







  



 

#line 497 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_tim.h"


  



 







 



 







  



 







  



 







  



 

#line 561 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_tim.h"


  



 

#line 577 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_tim.h"


  



 

#line 593 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_tim.h"


  



 

#line 610 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_tim.h"

#line 619 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_tim.h"


  



 

#line 665 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_tim.h"


  



 

#line 709 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_tim.h"


  



 

#line 725 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_tim.h"



  



 

#line 742 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_tim.h"


  



 

#line 770 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_tim.h"


  



 

#line 784 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_tim.h"


  



  






 



 







  



 







  



 

#line 833 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_tim.h"


  




 

#line 851 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_tim.h"



  



 

#line 866 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_tim.h"


  



 







  



 





                                     


  



 







  



 

#line 927 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_tim.h"


  



 

#line 943 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_tim.h"


  



 







  



 

#line 987 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_tim.h"
                               
                               



  



 




  



 




  



 

#line 1034 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_tim.h"


 



 



 



  



 

void TIM_DeInit(TIM_TypeDef* TIMx);
void TIM_TimeBaseInit(TIM_TypeDef* TIMx, TIM_TimeBaseInitTypeDef* TIM_TimeBaseInitStruct);
void TIM_OC1Init(TIM_TypeDef* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct);
void TIM_OC2Init(TIM_TypeDef* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct);
void TIM_OC3Init(TIM_TypeDef* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct);
void TIM_OC4Init(TIM_TypeDef* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct);
void TIM_ICInit(TIM_TypeDef* TIMx, TIM_ICInitTypeDef* TIM_ICInitStruct);
void TIM_PWMIConfig(TIM_TypeDef* TIMx, TIM_ICInitTypeDef* TIM_ICInitStruct);
void TIM_BDTRConfig(TIM_TypeDef* TIMx, TIM_BDTRInitTypeDef *TIM_BDTRInitStruct);
void TIM_TimeBaseStructInit(TIM_TimeBaseInitTypeDef* TIM_TimeBaseInitStruct);
void TIM_OCStructInit(TIM_OCInitTypeDef* TIM_OCInitStruct);
void TIM_ICStructInit(TIM_ICInitTypeDef* TIM_ICInitStruct);
void TIM_BDTRStructInit(TIM_BDTRInitTypeDef* TIM_BDTRInitStruct);
void TIM_Cmd(TIM_TypeDef* TIMx, FunctionalState NewState);
void TIM_CtrlPWMOutputs(TIM_TypeDef* TIMx, FunctionalState NewState);
void TIM_ITConfig(TIM_TypeDef* TIMx, uint16_t TIM_IT, FunctionalState NewState);
void TIM_GenerateEvent(TIM_TypeDef* TIMx, uint16_t TIM_EventSource);
void TIM_DMAConfig(TIM_TypeDef* TIMx, uint16_t TIM_DMABase, uint16_t TIM_DMABurstLength);
void TIM_DMACmd(TIM_TypeDef* TIMx, uint16_t TIM_DMASource, FunctionalState NewState);
void TIM_InternalClockConfig(TIM_TypeDef* TIMx);
void TIM_ITRxExternalClockConfig(TIM_TypeDef* TIMx, uint16_t TIM_InputTriggerSource);
void TIM_TIxExternalClockConfig(TIM_TypeDef* TIMx, uint16_t TIM_TIxExternalCLKSource,
                                uint16_t TIM_ICPolarity, uint16_t ICFilter);
void TIM_ETRClockMode1Config(TIM_TypeDef* TIMx, uint16_t TIM_ExtTRGPrescaler, uint16_t TIM_ExtTRGPolarity,
                             uint16_t ExtTRGFilter);
void TIM_ETRClockMode2Config(TIM_TypeDef* TIMx, uint16_t TIM_ExtTRGPrescaler, 
                             uint16_t TIM_ExtTRGPolarity, uint16_t ExtTRGFilter);
void TIM_ETRConfig(TIM_TypeDef* TIMx, uint16_t TIM_ExtTRGPrescaler, uint16_t TIM_ExtTRGPolarity,
                   uint16_t ExtTRGFilter);
void TIM_PrescalerConfig(TIM_TypeDef* TIMx, uint16_t Prescaler, uint16_t TIM_PSCReloadMode);
void TIM_CounterModeConfig(TIM_TypeDef* TIMx, uint16_t TIM_CounterMode);
void TIM_SelectInputTrigger(TIM_TypeDef* TIMx, uint16_t TIM_InputTriggerSource);
void TIM_EncoderInterfaceConfig(TIM_TypeDef* TIMx, uint16_t TIM_EncoderMode,
                                uint16_t TIM_IC1Polarity, uint16_t TIM_IC2Polarity);
void TIM_ForcedOC1Config(TIM_TypeDef* TIMx, uint16_t TIM_ForcedAction);
void TIM_ForcedOC2Config(TIM_TypeDef* TIMx, uint16_t TIM_ForcedAction);
void TIM_ForcedOC3Config(TIM_TypeDef* TIMx, uint16_t TIM_ForcedAction);
void TIM_ForcedOC4Config(TIM_TypeDef* TIMx, uint16_t TIM_ForcedAction);
void TIM_ARRPreloadConfig(TIM_TypeDef* TIMx, FunctionalState NewState);
void TIM_SelectCOM(TIM_TypeDef* TIMx, FunctionalState NewState);
void TIM_SelectCCDMA(TIM_TypeDef* TIMx, FunctionalState NewState);
void TIM_CCPreloadControl(TIM_TypeDef* TIMx, FunctionalState NewState);
void TIM_OC1PreloadConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPreload);
void TIM_OC2PreloadConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPreload);
void TIM_OC3PreloadConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPreload);
void TIM_OC4PreloadConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPreload);
void TIM_OC1FastConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCFast);
void TIM_OC2FastConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCFast);
void TIM_OC3FastConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCFast);
void TIM_OC4FastConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCFast);
void TIM_ClearOC1Ref(TIM_TypeDef* TIMx, uint16_t TIM_OCClear);
void TIM_ClearOC2Ref(TIM_TypeDef* TIMx, uint16_t TIM_OCClear);
void TIM_ClearOC3Ref(TIM_TypeDef* TIMx, uint16_t TIM_OCClear);
void TIM_ClearOC4Ref(TIM_TypeDef* TIMx, uint16_t TIM_OCClear);
void TIM_OC1PolarityConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPolarity);
void TIM_OC1NPolarityConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCNPolarity);
void TIM_OC2PolarityConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPolarity);
void TIM_OC2NPolarityConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCNPolarity);
void TIM_OC3PolarityConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPolarity);
void TIM_OC3NPolarityConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCNPolarity);
void TIM_OC4PolarityConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPolarity);
void TIM_CCxCmd(TIM_TypeDef* TIMx, uint16_t TIM_Channel, uint16_t TIM_CCx);
void TIM_CCxNCmd(TIM_TypeDef* TIMx, uint16_t TIM_Channel, uint16_t TIM_CCxN);
void TIM_SelectOCxM(TIM_TypeDef* TIMx, uint16_t TIM_Channel, uint16_t TIM_OCMode);
void TIM_UpdateDisableConfig(TIM_TypeDef* TIMx, FunctionalState NewState);
void TIM_UpdateRequestConfig(TIM_TypeDef* TIMx, uint16_t TIM_UpdateSource);
void TIM_SelectHallSensor(TIM_TypeDef* TIMx, FunctionalState NewState);
void TIM_SelectOnePulseMode(TIM_TypeDef* TIMx, uint16_t TIM_OPMode);
void TIM_SelectOutputTrigger(TIM_TypeDef* TIMx, uint16_t TIM_TRGOSource);
void TIM_SelectSlaveMode(TIM_TypeDef* TIMx, uint16_t TIM_SlaveMode);
void TIM_SelectMasterSlaveMode(TIM_TypeDef* TIMx, uint16_t TIM_MasterSlaveMode);
void TIM_SetCounter(TIM_TypeDef* TIMx, uint16_t Counter);
void TIM_SetAutoreload(TIM_TypeDef* TIMx, uint16_t Autoreload);
void TIM_SetCompare1(TIM_TypeDef* TIMx, uint16_t Compare1);
void TIM_SetCompare2(TIM_TypeDef* TIMx, uint16_t Compare2);
void TIM_SetCompare3(TIM_TypeDef* TIMx, uint16_t Compare3);
void TIM_SetCompare4(TIM_TypeDef* TIMx, uint16_t Compare4);
void TIM_SetIC1Prescaler(TIM_TypeDef* TIMx, uint16_t TIM_ICPSC);
void TIM_SetIC2Prescaler(TIM_TypeDef* TIMx, uint16_t TIM_ICPSC);
void TIM_SetIC3Prescaler(TIM_TypeDef* TIMx, uint16_t TIM_ICPSC);
void TIM_SetIC4Prescaler(TIM_TypeDef* TIMx, uint16_t TIM_ICPSC);
void TIM_SetClockDivision(TIM_TypeDef* TIMx, uint16_t TIM_CKD);
uint16_t TIM_GetCapture1(TIM_TypeDef* TIMx);
uint16_t TIM_GetCapture2(TIM_TypeDef* TIMx);
uint16_t TIM_GetCapture3(TIM_TypeDef* TIMx);
uint16_t TIM_GetCapture4(TIM_TypeDef* TIMx);
uint16_t TIM_GetCounter(TIM_TypeDef* TIMx);
uint16_t TIM_GetPrescaler(TIM_TypeDef* TIMx);
FlagStatus TIM_GetFlagStatus(TIM_TypeDef* TIMx, uint16_t TIM_FLAG);
void TIM_ClearFlag(TIM_TypeDef* TIMx, uint16_t TIM_FLAG);
ITStatus TIM_GetITStatus(TIM_TypeDef* TIMx, uint16_t TIM_IT);
void TIM_ClearITPendingBit(TIM_TypeDef* TIMx, uint16_t TIM_IT);








  



  



 

 
#line 48 "..\\main\\stm32f10x_conf.h"
#line 1 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_usart.h"




















 

 







 
#line 33 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_usart.h"



 



  



  



  
  
typedef struct
{
  uint32_t USART_BaudRate;            


 

  uint16_t USART_WordLength;          
 

  uint16_t USART_StopBits;            
 

  uint16_t USART_Parity;              




 
 
  uint16_t USART_Mode;                
 

  uint16_t USART_HardwareFlowControl; 

 
} USART_InitTypeDef;



  
  
typedef struct
{

  uint16_t USART_Clock;   
 

  uint16_t USART_CPOL;    
 

  uint16_t USART_CPHA;    
 

  uint16_t USART_LastBit; 

 
} USART_ClockInitTypeDef;



  



  
  
















  
  


                                    




  



  
  
#line 146 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_usart.h"


  



  
  
#line 160 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_usart.h"


  



  
  





  



  
#line 187 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_usart.h"


  



  






  



 
  






  



 







 



 







  



 
  
#line 264 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_usart.h"


 



 







  



 







 



 
  







 



 







  



 

#line 336 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_usart.h"
                              
#line 344 "..\\STM32F10x_StdPeriph\\inc\\stm32f10x_usart.h"



  



  



  



  



 

void USART_DeInit(USART_TypeDef* USARTx);
void USART_Init(USART_TypeDef* USARTx, USART_InitTypeDef* USART_InitStruct);
void USART_StructInit(USART_InitTypeDef* USART_InitStruct);
void USART_ClockInit(USART_TypeDef* USARTx, USART_ClockInitTypeDef* USART_ClockInitStruct);
void USART_ClockStructInit(USART_ClockInitTypeDef* USART_ClockInitStruct);
void USART_Cmd(USART_TypeDef* USARTx, FunctionalState NewState);
void USART_ITConfig(USART_TypeDef* USARTx, uint16_t USART_IT, FunctionalState NewState);
void USART_DMACmd(USART_TypeDef* USARTx, uint16_t USART_DMAReq, FunctionalState NewState);
void USART_SetAddress(USART_TypeDef* USARTx, uint8_t USART_Address);
void USART_WakeUpConfig(USART_TypeDef* USARTx, uint16_t USART_WakeUp);
void USART_ReceiverWakeUpCmd(USART_TypeDef* USARTx, FunctionalState NewState);
void USART_LINBreakDetectLengthConfig(USART_TypeDef* USARTx, uint16_t USART_LINBreakDetectLength);
void USART_LINCmd(USART_TypeDef* USARTx, FunctionalState NewState);
void USART_SendData(USART_TypeDef* USARTx, uint16_t Data);
uint16_t USART_ReceiveData(USART_TypeDef* USARTx);
void USART_SendBreak(USART_TypeDef* USARTx);
void USART_SetGuardTime(USART_TypeDef* USARTx, uint8_t USART_GuardTime);
void USART_SetPrescaler(USART_TypeDef* USARTx, uint8_t USART_Prescaler);
void USART_SmartCardCmd(USART_TypeDef* USARTx, FunctionalState NewState);
void USART_SmartCardNACKCmd(USART_TypeDef* USARTx, FunctionalState NewState);
void USART_HalfDuplexCmd(USART_TypeDef* USARTx, FunctionalState NewState);
void USART_OverSampling8Cmd(USART_TypeDef* USARTx, FunctionalState NewState);
void USART_OneBitMethodCmd(USART_TypeDef* USARTx, FunctionalState NewState);
void USART_IrDAConfig(USART_TypeDef* USARTx, uint16_t USART_IrDAMode);
void USART_IrDACmd(USART_TypeDef* USARTx, FunctionalState NewState);
FlagStatus USART_GetFlagStatus(USART_TypeDef* USARTx, uint16_t USART_FLAG);
void USART_ClearFlag(USART_TypeDef* USARTx, uint16_t USART_FLAG);
ITStatus USART_GetITStatus(USART_TypeDef* USARTx, uint16_t USART_IT);
void USART_ClearITPendingBit(USART_TypeDef* USARTx, uint16_t USART_IT);








  



  



  

 
#line 49 "..\\main\\stm32f10x_conf.h"

#line 1 "..\\STM32F10x_StdPeriph\\inc\\misc.h"




















 

 







 
#line 33 "..\\STM32F10x_StdPeriph\\inc\\misc.h"



 



 



 



 

typedef struct
{
  uint8_t NVIC_IRQChannel;                    


 

  uint8_t NVIC_IRQChannelPreemptionPriority;  

 

  uint8_t NVIC_IRQChannelSubPriority;         

 

  FunctionalState NVIC_IRQChannelCmd;         

    
} NVIC_InitTypeDef;
 


 



 
























 



 



 



 







 



 

#line 133 "..\\STM32F10x_StdPeriph\\inc\\misc.h"


 



 

#line 151 "..\\STM32F10x_StdPeriph\\inc\\misc.h"















 



 







 



 



 



 



 

void NVIC_PriorityGroupConfig(uint32_t NVIC_PriorityGroup);
void NVIC_Init(NVIC_InitTypeDef* NVIC_InitStruct);
void NVIC_SetVectorTable(uint32_t NVIC_VectTab, uint32_t Offset);
void NVIC_SystemLPConfig(uint8_t LowPowerMode, FunctionalState NewState);
void SysTick_CLKSourceConfig(uint32_t SysTick_CLKSource);









 



 



 

 
#line 51 "..\\main\\stm32f10x_conf.h"

 
 

 
 

 
#line 74 "..\\main\\stm32f10x_conf.h"



 
#line 8301 "..\\main\\stm32f10x.h"




 

















 









 

  

 

 
#line 7 "..\\usr_lib\\usr_sys.h"
																	    







#line 22 "..\\usr_lib\\usr_sys.h"

#line 30 "..\\usr_lib\\usr_sys.h"
 
#line 45 "..\\usr_lib\\usr_sys.h"




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





















































 




#line 50 "..\\usr_lib\\usr_sys.h"
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








#line 51 "..\\usr_lib\\usr_sys.h"
#line 1 "..\\usr_lib\\queue.h"


 






typedef struct tagQUEUE {   
    unsigned char queue[16];
    int   in;
    int   out;
    int   flag; 
}  QUEUE ;

#line 23 "..\\usr_lib\\queue.h"

 void initQueue (QUEUE *q);
 int  enQueue   (QUEUE *q, unsigned char data) ;
 int deQueue    (QUEUE *q, unsigned char  *data) ;

#line 52 "..\\usr_lib\\usr_sys.h"
#line 53 "..\\usr_lib\\usr_sys.h"
#line 54 "..\\usr_lib\\usr_sys.h"
#line 55 "..\\usr_lib\\usr_sys.h"
#line 1 "..\\free_rtos\\semphr.h"








































































 








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








#line 83 "..\\free_rtos\\semphr.h"

typedef xQueueHandle xSemaphoreHandle;











































 
#line 137 "..\\free_rtos\\semphr.h"

































































 




























































































 














 






























































 



















































































 













 


























































































 

































 














































 






















































 






























































 













 














 





#line 56 "..\\usr_lib\\usr_sys.h"

extern xSemaphoreHandle   xBinarySemaphore;  



void NVIC_Configuration(void);

#line 6 "..\\usr_lib\\usr_delay.c"
#line 1 "..\\usr_lib\\usr_delay.h"


			   
#line 5 "..\\usr_lib\\usr_delay.h"

void delay_init(void);
void delay_ms  (u16 nms);
void delay_us  (u32 nus);































#line 7 "..\\usr_lib\\usr_delay.c"






static u8  fac_us=0;
static u16 fac_ms=0;

#line 24 "..\\usr_lib\\usr_delay.c"

void delay_init()	 
{




	SysTick_CLKSourceConfig(((uint32_t)0xFFFFFFFB));	
	fac_us = SystemCoreClock/8000000;	
	 
#line 43 "..\\usr_lib\\usr_delay.c"
	fac_ms=(u16)fac_us*1000;  

}								    

#line 83 "..\\usr_lib\\usr_delay.c"

void delay_us(u32 nus)
{		
	u32 temp;	    	 
	
	((SysTick_Type *) ((0xE000E000) + 0x0010))->LOAD  = nus*fac_us;    		 
	((SysTick_Type *) ((0xE000E000) + 0x0010))->VAL   = 0x00;        
	((SysTick_Type *) ((0xE000E000) + 0x0010))->CTRL |= (1ul << 0) ;	 
	
	do {
		temp=((SysTick_Type *) ((0xE000E000) + 0x0010))->CTRL;
	} while(temp&0x01&&!(temp&(1<<16)));
	
	((SysTick_Type *) ((0xE000E000) + 0x0010))->CTRL  &= ~(1ul << 0); 
	((SysTick_Type *) ((0xE000E000) + 0x0010))->VAL    = 0X00;         
}


void delay_ms(u16 nms)
{	 		  	  
	u32 temp;		   
	((SysTick_Type *) ((0xE000E000) + 0x0010))->LOAD=(u32)nms*fac_ms;
	((SysTick_Type *) ((0xE000E000) + 0x0010))->VAL =0x00;           
	((SysTick_Type *) ((0xE000E000) + 0x0010))->CTRL|=(1ul << 0) ;          
	do
	{
		temp=((SysTick_Type *) ((0xE000E000) + 0x0010))->CTRL;
	}
	while(temp&0x01&&!(temp&(1<<16)));
	((SysTick_Type *) ((0xE000E000) + 0x0010))->CTRL&=~(1ul << 0);       
	((SysTick_Type *) ((0xE000E000) + 0x0010))->VAL =0X00;       
} 

































