#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/output/print.h"

/**
 * I: strs = ["eat","tea","tan","ate","nat","bat"]
 * O: [["bat"],["nat","tan"],["ate","eat","tea"]]
 *
 * I: strs = [""]
 * O: [[""]]
 *
 * I: strs = ["a"]
 * O: [["a"]]
 */

#define MALLOC_UNIT 5000

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes);

void sortString(char* s);

int cmp(const void* a, const void* b);

int main(int argc, char const* argv[]) {
    int strsSize = 6;
    int* returnSize = (int*)malloc(sizeof(int));
    int** returnColumnSize = (int**)malloc(sizeof(int*));
    char** strs = (char**)malloc(sizeof(char*) * strsSize);
    strs[0] = (char*)malloc(sizeof(char) * 4);
    strs[0][0] = 'e';
    strs[0][1] = 'a';
    strs[0][2] = 't';
    strs[0][3] = '\0';
    strs[1] = (char*)malloc(sizeof(char) * 4);
    strs[1][0] = 't';
    strs[1][1] = 'e';
    strs[1][2] = 'a';
    strs[1][3] = '\0';
    strs[2] = (char*)malloc(sizeof(char) * 4);
    strs[2][0] = 't';
    strs[2][1] = 'a';
    strs[2][2] = 'n';
    strs[2][3] = '\0';
    strs[3] = (char*)malloc(sizeof(char) * 4);
    strs[3][0] = 'a';
    strs[3][1] = 't';
    strs[3][2] = 'e';
    strs[3][3] = '\0';
    strs[4] = (char*)malloc(sizeof(char) * 4);
    strs[4][0] = 'n';
    strs[4][1] = 'a';
    strs[4][2] = 't';
    strs[4][3] = '\0';
    strs[5] = (char*)malloc(sizeof(char) * 4);
    strs[5][0] = 'b';
    strs[5][1] = 'a';
    strs[5][2] = 't';
    strs[5][3] = '\0';
    char*** ret = groupAnagrams(strs, strsSize, returnSize, returnColumnSize);
    printString2DList(ret, *returnSize, *returnColumnSize);
    free(strs);
    free(returnColumnSize);
    free(returnSize);
    return 0;
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    char*** ret = (char***)malloc(sizeof(char**) * MALLOC_UNIT);
    *returnColumnSizes = (int*)malloc(sizeof(int) * MALLOC_UNIT);
    int* arr = (int*)malloc(sizeof(int) * strsSize);
    memset(arr, 0, sizeof(int) * strsSize);
    int count = 1, flag = 0, empty = 0;
    for (int i = 0; i < strsSize; i++) {
        if (strlen(strs[i]) == 0) {
            flag = 1;
            arr[i] = 1;
            empty++;
        }
    }
    if (flag) {
        *returnSize += 1;
        ret[*returnSize - 1] = (char**)malloc(sizeof(char*) * empty);
        int index = 0;
        for (int i = 0; i < strsSize; i++) {
            if (strlen(strs[i]) == 0) {
                ret[*returnSize - 1][index++] = "";
            }
        }
        (*returnColumnSizes)[*returnSize - 1] = empty;
    }
    for (int i = 0; i < strsSize; i++) {
        if (arr[i])
            continue;
        *returnSize += 1;
        count = 1;
        ret[*returnSize - 1] = (char**)malloc(sizeof(char*));
        ret[*returnSize - 1][0] = (char*)malloc(sizeof(char) * (strlen(strs[i]) + 1));
        memcpy(ret[*returnSize - 1][0], strs[i], sizeof(char) * strlen(strs[i]));
        ret[*returnSize - 1][0][strlen(strs[i])] = '\0';
        sortString(strs[i]);
        for (int j = i + 1; j < strsSize; j++) {
            if (strlen(strs[i]) != strlen(strs[j]))
                continue;
            char* tmp = (char*)malloc(sizeof(char) * (strlen(strs[j]) + 1));
            memcpy(tmp, strs[j], sizeof(char) * (strlen(strs[j]) + 1));
            sortString(strs[j]);
            if (memcmp(strs[i], strs[j], sizeof(char) * strlen(strs[i])) == 0) {
                count += 1;
                ret[*returnSize - 1] = realloc(ret[*returnSize - 1], sizeof(char*) * count);
                ret[*returnSize - 1][count - 1] = (char*)malloc(sizeof(char) * (strlen(tmp) + 1));
                memcpy(ret[*returnSize - 1][count - 1], tmp, sizeof(char) * strlen(tmp));
                ret[*returnSize - 1][count - 1][strlen(tmp)] = '\0';
                arr[j] = 1;
            }
            memcpy(strs[j], tmp, sizeof(char) * (strlen(strs[j]) + 1));
        }
        (*returnColumnSizes)[*returnSize - 1] = count;
    }

    free(arr);
    return ret;
}

void sortString(char* s) {
    for (int i = 0; i < strlen(s) - 1; i++) {
        for (int j = i + 1; j < strlen(s); j++) {
            if (s[i] > s[j]) {
                char tmp = s[i];
                s[i] = s[j];
                s[j] = tmp;
            }
        }
    }
}

int cmp(const void* a, const void* b) {
    return strcmp((const char*)a, (const char*)b);
}
