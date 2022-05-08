#include <stdio.h>
#include <stdlib.h>

/**
 *
 * I: strs = ["flower","flow","flight"]
 * O: "fl"

 * I: strs = ["dog","racecar","car"]
 * O: ""
 * Explanation: There is no common prefix among the input strings.
 */

char *longestCommonPrefix(char **strs, int strsSize) {
    char *res = (char *)malloc(sizeof(char) * 1000);
    int ptr = 0;
    int index = 0;
    int i;
    while (strs[0][ptr] != '\0') {
        i = 0;
        while (i != strsSize - 1) {
            if ((strs[i][ptr] != strs[i + 1][ptr]) || (strs[i + 1][ptr] == '\0')) {
                res[index] = '\0';
                return index == 0 ? "" : res;
            }
            i++;
        }
        res[index++] = strs[i][ptr];
        ptr++;
    }

    res[index] = '\0';
    return res;
}

int main(int argc, char const *argv[]) {
    char *strs[3] = {"flgwer", "flgw", "flght"};
    printf("%s", longestCommonPrefix(strs, 3));
    return 0;
}
