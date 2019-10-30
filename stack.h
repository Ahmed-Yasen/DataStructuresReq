#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED


typedef struct {
    int stackPtr;
} ST_stackInfo;


void createStack(ST_stackInfo *info, int size);
void push(ST_stackInfo *info, int data);
void pop(ST_stackInfo *info, int* data);

#endif // STACK_H_INCLUDED
