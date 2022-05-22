#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../constant/integer.h"

void printStr(char *s, int index) {
    while (s[index] != '\n') {
        printf("%c", s[index]);
        index++;
    }
    printf("\n");
}

int myAtoi(char *s) {
    long int res = 0;
    int index = 0;
    int sign = 1;
    char *digitS = (char *)malloc(sizeof(char) * 1000);

    // Step1: Read in and ignore any leading whitespace
    while (s[index] == ' ') {
        index++;
    }

    // Step2: Check if the next character (if not already at the end of the string) is '-' or '+'
    if (s[index] == '-') {
        sign = -1;
        index++;
        if (s[index] == '-' || s[index] == '+') return 0;
    }
    if (s[index] == '+') {
        index++;
        if (s[index] == '-' || s[index] == '+') return 0;
    }

    // Step3: Read in next the characters until the next non-digit character or the end of the input is reached
    int ptr = 0;
    while ((int)(s[index]) >= 48 && (int)(s[index]) <= 57) {
        digitS[ptr++] = s[index++];
    }
    digitS[ptr] = '\n';

    // Step4: Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32)
    // If no digits were read, then the integer is 0
    if (ptr == 0) return 0;
    int len = ptr;
    ptr = 0;
    while (digitS[ptr] != '\n') {
        if ((int)(digitS[ptr]) == 48) {
            ptr++;
            len--;
        } else {
            break;
        }
    }
    while (digitS[ptr] != '\n') {
        long int m1 = pow(10, len - 1);
        if (m1 > INT_POS_LIMIT || m1 < INT_NEG_LIMIT) {
            return sign > 0 ? INT_POS_LIMIT : INT_NEG_LIMIT;
        }
        int m2 = (int)(digitS[ptr]) - 48;
        res += m1 * m2;
        len--;
        ptr++;
    }

    if (sign < 0) res *= -1;

    if (res > INT_POS_LIMIT) res = INT_POS_LIMIT;
    if (res < INT_NEG_LIMIT) res = INT_NEG_VALUE;

    return res;
}

int main(int argc, char const *argv[]) {
    char *s = "20000000000000000000";
    printf("%d\n", myAtoi(s));
    return 0;
}
