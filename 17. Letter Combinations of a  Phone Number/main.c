#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 *
 * I: digits = "23"
 * O: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

 * I: digits = ""
 * O: []
 *
 * I: digits = "2"
 * O: ["a","b","c"]
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

char** letterCombinations(char* digits, int* returnSize) {
    int len = strlen(digits);
    if (digits == 0) {
        *returnSize = 0;
        return NULL;
    }

    char letterDic[8][5] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    char** res;
    *returnSize = 1;
    for (int i = 0; i < len; i++) {
        *returnSize *= (digits[i] == '7' || digits[i] == '9') ? 4 : 3;
    }

    res = (char**)malloc(sizeof(char*) * (*returnSize));
    for (int i = 0; i < *returnSize; i++) {
        res[i] = (char*)malloc(sizeof(char) * (len + 1));
        res[i][len] = '\0';
    }

    int ret_Sz = *returnSize;
    for (int i = 0; i < len; i++) {
        for (int pos = 0; pos < *returnSize; pos++) {
            res[pos][i] = letterDic
                [digits[i] - '2']
                [(pos) % ret_Sz / (ret_Sz / ((digits[i] == '7' || digits[i] == '9') ? 4 : 3))];
        }
        ret_Sz /= ((digits[i] == '7' || digits[i] == '9') ? 4 : 3);
    }

    return res;
}

void printLetterCombinations(char** arr, int* size) {
    printf("[");
    for (int i = 0; i < *size; i++) {
        int index = 0;
        while (arr[i][index] != '\0') {
            printf("%c", arr[i][index]);
            index++;
        }
        if (i != *size - 1) {
            printf(",");
        }
    }
    printf("]");
}

int main(int argc, char const* argv[]) {
    char* digits = "23";
    int* size = (int*)malloc(sizeof(int));
    char** res = letterCombinations(digits, size);
    printLetterCombinations(res, size);
    free(size);
    free(res);
    return 0;
}
