
#include "stack.h"
#include "stdlib.h"

static int * stackBasePtr = NULL;
static int stackSize = 0;

void createStack(ST_stackInfo *info, int size){
    stackBasePtr = (int *)malloc(size * sizeof(int));
    info->stackPtr = 0;
    stackSize = size;
}
void push(ST_stackInfo *info, int data){
    if((info->stackPtr) < stackSize){
        stackBasePtr[info->stackPtr] = data;
        info->stackPtr ++;
    }
}
void pop(ST_stackInfo *info, int* data){
    if((info->stackPtr > 0)){
        info->stackPtr --;
        *data = stackBasePtr[info->stackPtr];
    }
}
