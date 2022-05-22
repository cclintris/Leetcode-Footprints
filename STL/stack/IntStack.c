#include "IntStack.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool isStackFull(IntStack *stack) {
    return stack->top == stack->size - 1;
}

bool isStackEmpty(IntStack *stack) {
    return stack->top == -1;
}

void push(IntStack *stack, int index) {
    if (isStackFull(stack)) return;
    stack->arr[++(stack->top)] = index;
}

int pop(IntStack *stack) {
    if (isStackEmpty(stack)) return '\0';
    return stack->arr[(stack->top)--];
}

int peek(IntStack *stack) {
    if (isStackEmpty(stack)) return '\0';
    return stack->arr[stack->top];
}
