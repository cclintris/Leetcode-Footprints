#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../STL/stack/CharStack.h"

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

bool isValid(char *s) {
    CharStack stack;
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
    char *s = "[]";
    printf("%d\n", isValid(s));
    return 0;
}
