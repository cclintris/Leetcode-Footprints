#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 *
 * I: n = 3
 * O: ["((()))","(()())","(())()","()(())","()()()"]

 * I: n = 1
 * O: ["()"]
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/**
 * @used: already used (
 * @single: unpaired (
 */
void backTracking(char*** ret, int* size, char* str, int used, int n, int single) {
    int cur = (used - single) * 2 + single;  // character used
    if (used == n) {
        for (int i = cur; i < n * 2; i++) {
            str[i] = ')';
        }
        (*size)++;
        *ret = (char**)realloc(*ret, *size * sizeof(char*));
        (*ret)[*size - 1] = (char*)malloc(sizeof(char) * (n * 2 + 1));
        memcpy((*ret)[*size - 1], str, sizeof(char) * (n * 2 + 1));
        return;
    }
    if (single == 0) {
        str[cur] = '(';
        backTracking(ret, size, str, used + 1, n, single + 1);
    } else {
        str[cur] = '(';
        backTracking(ret, size, str, used + 1, n, single + 1);
        str[cur] = ')';
        backTracking(ret, size, str, used, n, single - 1);
    }
}

char** generateParenthesis(int n, int* returnSize) {
    char** ret = NULL;
    char* str = (char*)malloc(sizeof(char) * (n * 2 + 1));
    str[n * 2] = '\0';
    backTracking(&ret, returnSize, str, 0, n, 0);
    return ret;
}

void print2DStrArray(char** arr, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        if (i == size - 1) {
            printf("%s", arr[i]);
        } else {
            printf("%s,", arr[i]);
        }
    }
    printf("]\n");
}

int main(int argc, char const* argv[]) {
    int n = 3;
    int* returnSize = (int*)malloc(sizeof(int*));
    char** ret = generateParenthesis(n, returnSize);
    print2DStrArray(ret, *returnSize);
    free(ret);
    free(returnSize);
    return 0;
}
