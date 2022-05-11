#include <stdio.h>
#include <stdlib.h>

/**
 *
 * I: "III"
 * O: 3

 * I: "LVIII"
 * O: 58
 * Explanation: L = 50, V = 5, III = 3.

 * I: "MCMXCIV"
 * O: 1994
 * * Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 */

int romanToInt(char *s) {
    int res = 0;
    int index = 0;
    while (s[index] != '\0') {
        switch (s[index]) {
            case 'I':
                if (s[index + 1] == 'V') {  // 4
                    res += 4;
                    index += 2;
                } else if (s[index + 1] == 'X') {  // 9
                    res += 9;
                    index += 2;
                } else {  // 1
                    res++;
                    index++;
                }
                break;
            case 'V':  // 5
                res += 5;
                index++;
                break;
            case 'X':
                if (s[index + 1] == 'L') {  // 40
                    res += 40;
                    index += 2;
                } else if (s[index + 1] == 'C') {  // 90
                    res += 90;
                    index += 2;
                } else {  // 10
                    res += 10;
                    index++;
                }
                break;
            case 'L':  // 50
                res += 50;
                index++;
                break;
            case 'C':
                if (s[index + 1] == 'D') {  // 400
                    res += 400;
                    index += 2;
                } else if (s[index + 1] == 'M') {  // 900
                    res += 900;
                    index += 2;
                } else {  // 100
                    res += 100;
                    index++;
                }
                break;
            case 'D':  // 500
                res += 500;
                index++;
                break;
            case 'M':  // 1000
                res += 1000;
                index++;
                break;
            default:
                break;
        }
    }

    return res;
}

int main(int argc, char const *argv[]) {
    char *s = "MCMXCIV";
    printf("%d", romanToInt(s));
    return 0;
}
