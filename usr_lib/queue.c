/********************************************************
 *    Description:		queue.c
**/

#include "queue.h"

// void initQueue (QUEUE *q);
// int  enQueue   (QUEUE *q, int data) ;
// char deQueue   (QUEUE *q, int data) ;

/*****************************
 * @Function: initQueue
 *   QUEUE:  *q
 *   Return: void
 * @Comment: 
*******************************/
void initQueue (QUEUE *q)
{
    int i = 0;

    q->in = q->out = 0;
    q->flag = 0;
    for (i=0; i<QUEUE_SIZE; i++){
      q->queue[i] = 0;
    }
}

/*****************************
  @Function: initQueue
    QUEUE:  *q
    Return:  good : 0
             queue is full : -1
  @Comment: 
*******************************/
int  enQueue   (QUEUE *q, unsigned char  data) 
{
    int  ret = 0; 
	  int  inpos = 0;
    
	  inpos =  (q->in+1) & QUEUE_MASK; 
    if ( inpos != q->out) {
        q->queue[q->in] = data ;
        q->in++;
        q->in &= QUEUE_MASK;
    } else { // queu empty!
        ret = -1;
    }
  	return ret;
}

/*****************************
  @Function: initQueue
    QUEUE:  *q
    Return:  good : 0
             queue is empty : -1
  @Comment: 
*******************************/
int deQueue   (QUEUE *q, unsigned char *data) 
{
    int ret = 0;

    if (q->in != q->out){   
        *data  = q->queue[q->out];
      	q->out++;
				q->out &= QUEUE_MASK;
    } else { // queu empty!
        ret = -1;
    }
		return ret;
}
