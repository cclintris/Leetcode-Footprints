#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * I: s = "barfoothefoobarman", words = ["foo","bar"]
 * O: [0,9]
 * Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar" respectively.
 * The output order does not matter, returning [9,0] is fine too.

 * I: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
 * O: []
 *
 * I: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
 * O: [6,9,12]
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define MALLOC_UNIT 5000

int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    int* ret = (int*)malloc(sizeof(int) * MALLOC_UNIT);
    *returnSize = 0;

    int sL = strlen(s), wordL = strlen(words[0]),
        unitL = wordL * wordsSize, last = sL - unitL, ret_Sz = 0, index;
    int* count = (int*)malloc(sizeof(int) * wordsSize);
    char* tmp = (char*)malloc(sizeof(char) * (wordL + 1));
    bool flag;

    for (int i = 0; i < last + 1; i++) {
        for (int i = 0; i < wordsSize; i++) {
            count[i] = 1;
        }
        flag = true;
        index = i;
        unitL = wordL * wordsSize;
        while (unitL > 0) {
            memcpy(tmp, &s[index], wordL);
            tmp[wordL] = '\0';
            index += wordL;
            for (int j = 0; j < wordsSize; j++) {
                if (count[j] == 1 && strcmp(tmp, words[j]) == 0) {
                    count[j] = 0;
                    flag = true;
                    break;
                } else {
                    flag = false;
                }
            }
            if (!flag) break;
            unitL -= wordL;
        }
        if (flag) {
            ret_Sz++;
            if (ret_Sz > MALLOC_UNIT) {
                ret = realloc(ret, sizeof(int) * ret_Sz);
            }
            ret[ret_Sz - 1] = i;
        }
    }

    *returnSize = ret_Sz;
    return ret;
}

void printIntList(int* arr, int size) {
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
    printf("]");
}

int main(int argc, char const* argv[]) {
    char* s = "wordgoodgoodgoodbestword";
    int wordsSize = 4;
    int* returnSize = (int*)malloc(sizeof(int));
    char** words = (char**)malloc(sizeof(char*) * wordsSize);
    words[0] = (char*)malloc(sizeof(char) * 4);
    words[1] = (char*)malloc(sizeof(char) * 4);
    words[2] = (char*)malloc(sizeof(char) * 4);
    words[3] = (char*)malloc(sizeof(char) * 4);
    words[0] = "word";
    words[1] = "good";
    words[2] = "best";
    words[3] = "word";
    int* ret = findSubstring(s, words, wordsSize, returnSize);
    printIntList(ret, *returnSize);
    return 0;
}
