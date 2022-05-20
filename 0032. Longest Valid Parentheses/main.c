#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * I: s = "(()"
 * O: 2

 * I: s = ")()())"
 * O: 4
 *
 * I: s = ""
 * O: 0
 */

typedef struct {
    int top;
    int size;
    int *arr;
} Stack;

bool isStackFull(Stack *stack);

bool isStackEmpty(Stack *stack);

void push(Stack *stack, int c);

int pop(Stack *stack);

int longestValidParentheses(char *s);

void printIntList(int *arr, int size);

int main(int argc, char const *argv[]) {
    char *s = "(()";
    printf("%d", longestValidParentheses(s));
    return 0;
}

bool isStackFull(Stack *stack) {
    return stack->top == stack->size - 1;
}

bool isStackEmpty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, int index) {
    if (isStackFull(stack)) return;
    stack->arr[++(stack->top)] = index;
}

int pop(Stack *stack) {
    if (isStackEmpty(stack)) return '\0';
    return stack->arr[(stack->top)--];
}

int peek(Stack *stack) {
    if (isStackEmpty(stack)) return '\0';
    return stack->arr[stack->top];
}

int longestValidParentheses(char *s) {
    if (s == NULL) return 0;

    Stack stack;
    stack.top = -1;
    stack.size = strlen(s) + 1;
    stack.arr = (int *)malloc(sizeof(int) * stack.size);
    push(&stack, -1);

    int max = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '(') {
            push(&stack, i);
        } else {
            int popEle = pop(&stack);
            if (isStackEmpty(&stack)) {
                push(&stack, i);
            } else {
                int peekEle = peek(&stack);
                if (i - peekEle > max) {
                    max = i - peekEle;
                }
            }
        }
    }

    return max;
}

void printIntList(int *arr, int size) {
    printf("[");
    int index = 0;
    while (size > 0) {
        if (size == 1) {
            printf("%d", arr[index]);
        } else {
            printf("%d,", arr[index]);
        }
        index++;
        size--;
    }
    printf("]\n");
}
