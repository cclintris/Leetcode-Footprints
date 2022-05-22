#ifndef STL_INT_STACK
#define STL_INT_STACK

#include <stdbool.h>

typedef struct {
    int top;
    int size;
    int *arr;
} IntStack;

bool isStackFull(IntStack *stack);

bool isStackEmpty(IntStack *stack);

void push(IntStack *stack, int c);

int pop(IntStack *stack);

int peek(IntStack *stack);

#endif
