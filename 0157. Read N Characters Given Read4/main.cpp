#include <iostream>
using namespace std;

/**
* I: file = "abc", n = 4
* O: 3
Explanation: After calling your read method, buf should contain "abc".
We read a total of 3 characters from the file, so return 3.
Note that "abc" is the file's content, not buf. buf is the destination buffer that you will have to write the results to.
*
* I: file = "abcde", n = 5
* O: 5
Explanation: After calling your read method, buf should contain "abcde". We read a total of 5 characters from the file, so return 5.
*
* I: Input: file = "abcdABCD1234", n = 12
* O: 12
Explanation: After calling your read method, buf should contain "abcdABCD1234". We read a total of 12 characters from the file, so return 12.
*
* I: Input: file = "leetcode", n = 5
* O: 5
* Explanation: After calling your read method, buf should contain "leetc". We read a total of 5 characters from the file, so return 5.
*/

int read4(char *buf);

int read(char *buf, int n);

int main(int argc, char const *argv[]) {
    return 0;
}

int read(char *buf, int n) {
    int res = 0;
    for (int i = 0; i <= n / 4; i++) {
        int num = read4(buf + res);
        if (num == 0) break;
        res += num;
    }
    return min(res, n);
}
