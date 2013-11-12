#include<stdio.h>
#include "queue.h"

Queue CreateQueue(){
    Queue Q = (Queue) malloc(sizeof(struct QueueRecord));
    if(Q == NULL){
        printf("queue init error!\n");
        return NULL;
    }

    //printf("create succesfully\n");

    return Q;
}

void MakeQueueEmpty(Queue Q){
    if(Q == NULL)
        return;

    Element e = Q->front;
    Element temp;
    while(e){
        temp = e->next;
        free(e);
        e = temp;
    }

    Q->front = NULL;
    Q->rear = NULL;
}

void Enqueue(Queue Q,int value){
    if(Q == NULL)
        return;

    //printf("enqueue \n");

    Element e = (Element) malloc(sizeof(struct ElementRecord));
    e->value = value;
    e->next = NULL;

    if(Q->rear != NULL){
        Q->rear->next = e;
    }
    
    Q->rear = e;
    Q->size += 1;

    if(Q->front == NULL)
        Q->front = e;
}

int Dequeue(Queue Q){
    if(Q == NULL){
        printf("Q is null,Dequeue error\n");
        return -1;
    }

    if(Q->size == 0){
        printf("Q is empty\n");
        return -1;
    }    
    
    int value = Q->front->value;
    Element temp = Q->front;
    Q->front = Q->front->next;
    free(temp);
    Q->size -= 1;

    return value;
}
