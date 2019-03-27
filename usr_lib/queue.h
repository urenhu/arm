/********************************************************
 *    Description: queue.h
**/
#ifndef __QUEUE_H__
#define __QUEUE_H__

#define  QUEUE_SIZE         16
#define  QUEUE_MASK       (QUEUE_SIZE-1)

typedef struct tagQUEUE {   
    unsigned char queue[QUEUE_SIZE];
    int   in;
    int   out;
    int   flag; 
}  QUEUE ;

#ifndef ERROR
#define ERROR  -1
#endif 
#ifndef OK
#define OK     0
#endif

 void initQueue (QUEUE *q);
 int  enQueue   (QUEUE *q, unsigned char data) ;
 int deQueue    (QUEUE *q, unsigned char  *data) ;

#endif /* */
