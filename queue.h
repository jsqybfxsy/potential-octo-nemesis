#include<stdio.h>

#ifndef _QUEUE_H_
#define _QUEUE_H_

struct ElementRecord{
    int value;
    struct ElementRecord *next;
};


typedef struct ElementRecord *Element;

struct QueueRecord{
    int size;
    Element front;
    Element rear;
};

typedef struct QueueRecord *Queue;


Queue CreateQueue();
void MakeQueueEmpty(Queue Q);
void Enqueue(Queue Q,int value);
int Dequeue(Queue Q);

#endif
