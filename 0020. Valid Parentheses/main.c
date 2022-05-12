#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 *
 * I: s = "()"
 * O: true

 * I: s = "()[]{}"
 * O: true
 *
 * I: s = "(]"
 * O: false
 */

typedef struct
{
    int top;
    int size;
    char *arr;
} Stack;

bool isStackFull(Stack *stack) {
    return stack->top == stack->size - 1 ? 1 : 0;
}

bool isStackEmpty(Stack *stack) {
    return stack->top == -1 ? 1 : 0;
}

void push(Stack *stack, char c) {
    if (isStackFull(stack)) return;
    stack->arr[++(stack->top)] = c;
}

char pop(Stack *stack) {
    if (isStackEmpty(stack)) return '\0';
    return stack->arr[(stack->top)--];
}

bool isValid(char *s) {
    Stack stack;
    stack.top = -1;
    stack.size = strlen(s);
    stack.arr = (char *)malloc(sizeof(char) * stack.size);

    int index = 0;
    while (s[index] != '\0') {
        if (s[index] == '(' || s[index] == '[' || s[index] == '{') {
            push(&stack, s[index]);
        } else {
            char popEle = pop(&stack);
            if (s[index] == ')') {
                if (popEle != '(') return false;
            }
            if (s[index] == ']') {
                if (popEle != '[') return false;
            }
            if (s[index] == '}') {
                if (popEle != '{') return false;
            }
        }
        index++;
    }

    return isStackEmpty(&stack) ? 1 : 0;
}

int main(int argc, char const *argv[]) {
    char *s = "[";
    printf("%d", isValid(s));
    return 0;
}
