#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * I: 123
 * O: 321
 *
 * I: -123
 * O: -321
 *
 * I: 120
 * O: 21
 */

// typedef enum {
//     TRUE = 1,
//     FALSE = 0
// } Bool;

// char* int_2_reverse_string(int num) {
//     char* res = (char*)malloc(sizeof(char) * 10000);
//     int index = 0;
//     Bool Pflag = TRUE;

//     if (num < 0) {
//         Pflag = FALSE;
//         num *= -1;
//     }

//     while (num > 0) {
//         int remainder = num % 10;
//         char c = (char)(remainder + 48);  // ascii code
//         res[index++] = c;
//         num = num / 10;
//     }

//     res[index] = '\n';

//     // resolve head 0s
//     index = 0;
//     while (res[index] != '\n') {
//         if (res[index] == '0') {
//             index++;
//         } else {
//             break;
//         }
//     }

//     char* s = (char*)malloc(sizeof(char) * 10000);
//     int ptr = 0;
//     if (!Pflag) {
//         s[ptr++] = '-';
//     }
//     while (res[index] != '\n') {
//         s[ptr++] = res[index++];
//     }
//     s[ptr] = '\n';

//     return s;
// }

// int reverse(int x) {
//     char* str = int_2_reverse_string(x);
//     Bool PFLag = TRUE;
//     int index = 0;
//     int len = strlen(str);
//     int res = 0;

//     if (str[index] == '-') {
//         PFLag = FALSE;
//         len--;
//         index++;
//     }

//     while (str[index] != '\n') {
//         int m1 = (int)(str[index]) - 48;  // ascci code
//         int m2 = pow(10, len - 2);
//         res += m1 * m2;
//         if (res > INT_LIMIT) return 0;
//         index++;
//         len--;
//     }

//     if (!PFLag) {
//         res *= -1;
//     }

//     return res;
// }

#define INT_LIMIT 2147483647
#define INT_NEG_LIMIT -2147483648

int reverse(int x) {
    int sign = 1;
    long int res = 0;

    if (x == INT_NEG_LIMIT) return 0;

    if (x < 0) {
        sign = 0;
        x *= -1;
    }

    while (x > 0) {
        int digit = x % 10;
        res += res * 10 + digit - res;
        if (res > INT_LIMIT) return 0;
        x /= 10;
    }

    if (sign == 0) {
        res *= -1;
    }

    return res;
}

int main(int argc, char const* argv[]) {
    int a = -23;
    printf("%d", reverse(a));
    return 0;
}
