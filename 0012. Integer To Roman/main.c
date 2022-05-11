#include <stdio.h>
#include <stdlib.h>

/**
 *
 * I: num = 3
 * O: "III"

 * I: num = 4
 * O: "IV"

 * I: num = 9
 * O: "IX"

 * I: num = 58
 * O: "LVIII"
 * Explanation: L = 50, V = 5, III = 3.

 * I: num = 1994
 * O: "MCMXCIV"
 * Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 */

char* intToRoman(int num) {
    char* res = (char*)malloc(20 * sizeof(char));
    int index = 0;
    while (num > 0) {
        if (num >= 1000) {
            num -= 1000;
            res[index++] = 'M';
        } else if (num >= 900) {
            num -= 900;
            res[index++] = 'C';
            res[index++] = 'M';
        } else if (num >= 500) {
            num -= 500;
            res[index++] = 'D';
        } else if (num >= 400) {
            num -= 400;
            res[index++] = 'C';
            res[index++] = 'D';
        } else if (num >= 100) {
            num -= 100;
            res[index++] = 'C';
        } else if (num >= 90) {
            num -= 90;
            res[index++] = 'X';
            res[index++] = 'C';
        } else if (num >= 50) {
            num -= 50;
            res[index++] = 'L';
        } else if (num >= 40) {
            num -= 40;
            res[index++] = 'X';
            res[index++] = 'L';
        } else if (num >= 10) {
            num -= 10;
            res[index++] = 'X';
        } else if (num >= 9) {
            num -= 9;
            res[index++] = 'I';
            res[index++] = 'X';
        } else if (num >= 5) {
            num -= 5;
            res[index++] = 'V';
        } else if (num >= 4) {
            num -= 4;
            res[index++] = 'I';
            res[index++] = 'V';
        } else {
            num--;
            res[index++] = 'I';
        }
    }
    res[index] = '\0';
    return res;
}

int main(int argc, char const* argv[]) {
    int num = 58;
    printf("%s", intToRoman(num));
    return 0;
}
