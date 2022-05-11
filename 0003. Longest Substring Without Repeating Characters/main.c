#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * I: pwwkew
 * O: 3
 * wke
 */

// abacabc
// ht[97] = 0

int lengthOfLongestSubstring(char *s) {
    // hashmap
    // k: ascci code of character, v: index of character in string
    int *ht = (int *)malloc((sizeof(int) * 128));
    for (int i = 0; i < 128; i++) {
        ht[i] = -1;
    }

    int max = 0, substring_start = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (ht[s[i]] >= substring_start) {  // in substring
            // update substring
            substring_start = ht[s[i]] + 1;
        } else {  // not in substring
            // compare old and new max, no need to change substring
            int len = i - substring_start + 1;
            if (len > max) {
                max = len;
            }
        }
        ht[s[i]] = i;
    }

    return max;
}

int main(int argc, char const *argv[]) {
    char *str = "abcabcbb";
    printf("%d", lengthOfLongestSubstring(str));
    return 0;
}
