#include <iostream>
using namespace std;

/**
 * I: n = 00000000000000000000000000001011
 * O: 3
 *
 * I: n = 00000000000000000000000010000000
 * O: 1
 *
 * I: n = 11111111111111111111111111111101
 * O: 31
 */

int hammingWeight(uint32_t n);

int main(int argc, char const *argv[]) {
    uint32_t n = 11;
    cout << hammingWeight(n) << endl;
    return 0;
}

int hammingWeight(uint32_t n) {
    int res = 0;
    for (int i = 0; i < 32; i++) {
        if ((n & 1) == 1)
            res++;
        n = n >> 1;
    }
    return res;
}
