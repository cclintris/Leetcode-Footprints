#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * I: haystack = "hello", needle = "ll"
 * O: 2

 * I: haystack = "aaaaa", needle = "bba"
 * O: -1
 */

int strStr(char *haystack, char *needle) {
    // What should we return when needle is an empty string?
    // This is a great question to ask during an interview.
    // For the purpose of this problem, we will return 0 when needle is an empty string.
    // This is consistent to C's strstr() and Java's indexOf().
    if (needle == NULL) return 0;

    int index = 0;
    int ret;
    int needleL = strlen(needle), haystackL = strlen(haystack);

    if (needleL > haystackL) return -1;

    for (int i = 0; i < haystackL - needleL + 1; i++) {
        index = 0;
        for (int j = i; j < i + needleL; j++) {
            if (haystack[j] != needle[index]) {
                break;
            } else {
                ret = j;
                index++;
            }
        }
        if (index == needleL) {
            return ret - needleL + 1;
        }
    }

    return -1;
}

int main(int argc, char const *argv[]) {
    char *haystack = "hello";
    char *needle = "ll";
    printf("%d", strStr(haystack, needle));
    return 0;
}
