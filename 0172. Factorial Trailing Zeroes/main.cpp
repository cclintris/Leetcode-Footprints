#include <iostream>
using namespace std;

/**
 * I: n = 3
 * O: 0
 *
 * I: n = 5
 * O: 1
 *
 * I: n = 0
 * O: 0
 */

int trailingZeroes(int n);

int main(int argc, char const *argv[]) {
    int n = 125;
    cout << trailingZeroes(n) << endl;
    return 0;
}

int trailingZeroes(int n) {
    int cnt = 0;
    while (n) {
        cnt += n / 5;
        n /= 5;
    }
    return cnt;
}
