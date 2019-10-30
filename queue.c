

#include "queue.h"
#include "stdlib.h"


static int * queueBasePtr = NULL;
static int queueSize;

void createQueue(ST_queueInfo* info, int maxSize){
    queueBasePtr = (int *)malloc(maxSize * sizeof(int));
    queueSize = maxSize;
    info->head = -1;
    info->tail = 0;
}

void enqueue(ST_queueInfo *info, int data){
    if((info->tail) < queueSize){
        queueBasePtr[info->tail] = data;
        info->tail ++;
    }
}
void dequeue(ST_queueInfo *info, int* data){

    if((info->head) < (info->tail)){
        info->head ++;
        if((info->head) != (info->tail)){
            *data = queueBasePtr[info->head];
        }else{
            info->tail = 0;
            info->head = -1;
        }
    }
}
