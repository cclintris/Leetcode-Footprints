#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * I: s = "PAYPALISHIRING", numRows = 3
 * O: "PAHNAPLSIIGYIR"
 *
 * I: s = "PAYPALISHIRING", numRows = 4
 * O: "PINALSIGYAHRPI"
 */

char *convert(char *s, int numRows) {
    if (numRows == 1) {
        return s;
    }

    int length = strlen(s);
    int cycleLen = 2 * numRows - 2;

    //长度比原字符串多1，有个'\0'
    char *ret = (char *)malloc(sizeof(char) * (length + 1));
    int index = 0;

    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j + i < length; j += cycleLen) {
            //第一行、最后一行和中间行的列部分
            ret[index++] = s[j + i];
            //中间行字符串的对角线部分
            if (i != 0 && i != numRows - 1 && j + cycleLen - i < length) {
                ret[index++] = s[j + cycleLen - i];
            }
        }
    }
    ret[index] = '\0';
    return ret;
}

int main(int argc, char const *argv[]) {
    return 0;
}
