#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * I: babad
 * O: bab / aba
 *
 * I: cbbd
 * O: bb
 */

void print(char *s, int num) {
    printf("%s: %d\n", s, num);
}

typedef enum {
    true = 1,
    false = 0
} bool;

char *longestPalindrome(char *s) {
    int len = strlen(s);
    if (len <= 1) return s;

    int max = 0;
    int start = 0;
    int curLen = 0;
    for (int i = 1; i < len; i++) {
        // even length palindrome
        int right = i;
        int left = i - 1;
        while (left >= 0 && right < len && s[left] == s[right]) {
            left--;
            right++;
        }

        curLen = right - left - 1;
        if (curLen > max) {
            max = curLen;
            start = left + 1;
        }

        // odd length palindrome
        right = i + 1;
        left = i - 1;
        while (left >= 0 && right < len && s[left] == s[right]) {
            left--;
            right++;
        }
        curLen = right - left - 1;
        if (curLen > max) {
            max = curLen;
            start = left + 1;
        }
    }

    char *arr = (char *)malloc(sizeof(int) * max);
    int i = 0;
    for (; i < max; i++) {
        arr[i] = s[start++];
    }
    arr[i] = '\0';
    return arr;
}

int main(int argc, char const *argv[]) {
    char *str = "aca";
    printf("%s", longestPalindrome(str));
    return 0;
}
