#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../STL/stack/IntStack.h"
#include "../utils/output/print.h"

/**
 * I: s = "(()"
 * O: 2

 * I: s = ")()())"
 * O: 4
 *
 * I: s = ""
 * O: 0
 */

int longestValidParentheses(char *s);

int main(int argc, char const *argv[]) {
    char *s = "(()";
    printf("%d\n", longestValidParentheses(s));
    return 0;
}

int longestValidParentheses(char *s) {
    if (s == NULL) return 0;

    IntStack stack;
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
