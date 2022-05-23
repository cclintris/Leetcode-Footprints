#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * I: n = 1
 * O: 1
 * Explanation: This is the base case.
 *
 * I: n = 4
 * O: "1211"
 * Explanation
 * countAndSay(1) = "1"
 * countAndSay(2) = say "1" = one 1 = "11"
 * countAndSay(3) = say "11" = two 1's = "21"
 * countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"
 *
 */

#define MALLOC_UNIT 5000

char *countAndSay(int n);

int main(int argc, char const *argv[]) {
    int n = 3;
    printf("%s", countAndSay(n));
    return 0;
}

// countAndSay(n) = say countAndSay(n-1)
char *countAndSay(int n) {
    if (n == 1) {
        char *ret = (char *)malloc(sizeof(char) * 2);
        ret[0] = '1';
        ret[1] = '\0';
        return ret;
    } else {
        // printf("here n %d\n", n);
        char *ret = (char *)malloc(sizeof(char) * MALLOC_UNIT), tmp[MALLOC_UNIT];
        strcpy(tmp, countAndSay(n - 1));
        // say
        int index = 1, count = 1, len = 0;
        // printf("n %d\n", n);
        // printf("say %s\n", tmp);
        while (tmp[index] != '\0') {
            if (tmp[index] != tmp[index - 1]) {
                ret[len++] = count + 48;
                ret[len++] = tmp[index - 1];
                count = 0;
            }
            count++;
            index++;
        }
        ret[len++] = count + 48;
        ret[len++] = tmp[index - 1];
        ret[len] = '\0';
        return ret;
    }
}
