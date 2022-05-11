#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Reference: https://www.jianshu.com/p/69e7413b9e40

/**
 * I: s = "aa", p = "a"
 * O: false
 *
 * I: s = "aa", p = "a*"
 * O: true
 *
 * I: s = "ab", p = ".*"
 * O: true
 */

bool isMatch(char *s, char *p) {
    if (*p == '\0') return *s == '\0';

    if (*(p + 1) != '*') {
        if (*p == *s || (*p == '.' && *s != '\0'))
            return isMatch(s + 1, p + 1);
        else
            return false;
    } else {
        while (*p == *s || (*p == '.' && *s != '\0')) {
            if (isMatch(s, p + 2))
                return true;
            s++;
        }
        return isMatch(s, p + 2);
    }
}

int main(int argc, char const *argv[]) {
    char *s = "ab";
    char *p = ".*";
    printf("%d", isMatch(s, p));
    return 0;
}
