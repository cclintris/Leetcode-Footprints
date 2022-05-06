#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void printStr(char* s, int index) {
    while (s[index] != '\n') {
        printf("%c", s[index]);
        index++;
    }
    printf("\n");
}

char* reverse(char* s, int len) {
    char* rs = (char*)malloc(sizeof(char) * len);
    int index = 0;
    int ptr = len - 1;
    rs[ptr] = '\n';
    while (s[index] != '\n') {
        rs[--ptr] = s[index++];
    }

    return rs;
}

bool isEqual(char* s1, char* s2) {
    int index = 0;
    while (s1[index] != '\n' && s2[index] != '\n') {
        if (s1[index] == s2[index]) {
            index++;
            continue;
        } else {
            return false;
        }
    }
    return true;
}

bool isPalindrome(int x) {
    if (x == 0) return true;
    if (x < 0) return false;
    char* s = (char*)malloc(sizeof(char) * 1000);
    int index = 0;
    int len = 0;
    while (x > 0) {
        int digit = x % 10;
        char c = (char)(digit + 48);
        s[index++] = c;
        len++;
        x /= 10;
    }
    len++;
    s[index] = '\n';
    // printStr(s, 0);
    char* rs = reverse(s, len);
    // printf("%s", rs);

    return isEqual(s, rs);
}

int main(int argc, char const* argv[]) {
    int a = 10;
    printf("%d", isPalindrome(a));
    return 0;
}
