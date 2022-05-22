#ifndef STL_CHAR_STACK
#define STL_CHAR_STACK

#include <stdbool.h>

typedef struct
{
    int top;
    int size;
    char *arr;
} CharStack;

bool isStackFull(CharStack *stack);

bool isStackEmpty(CharStack *stack);

void push(CharStack *stack, char c);

char pop(CharStack *stack);

#endif
