#include "CharStack.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool isStackFull(CharStack *stack) {
    return stack->top == stack->size - 1 ? 1 : 0;
}

bool isStackEmpty(CharStack *stack) {
    return stack->top == -1 ? 1 : 0;
}

void push(CharStack *stack, char c) {
    if (isStackFull(stack)) return;
    stack->arr[++(stack->top)] = c;
}

char pop(CharStack *stack) {
    if (isStackEmpty(stack)) return '\0';
    return stack->arr[(stack->top)--];
}

char peek(CharStack *stack) {
    if (isStackEmpty(stack)) return '\0';
    return stack->arr[stack->top];
}
