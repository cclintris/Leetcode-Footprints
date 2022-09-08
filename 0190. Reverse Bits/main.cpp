#include <iostream>
using namespace std;

/**
 * I: n = 00000010100101000001111010011100
 * O: 964176192 (00111001011110000010100101000000)
 *
 * I: n = 11111111111111111111111111111101
 * O: 3221225471 (10111111111111111111111111111111)
 */

uint32_t reverseBits(uint32_t n);

int main(int argc, char const *argv[]) {
    uint32_t n = 43261596;
    cout << reverseBits(n) << endl;
    return 0;
}

uint32_t reverseBits(uint32_t n) {
    uint32_t res = 0;
    for (int i = 0; i < 32; i++) {
        if ((n & 1) == 1) {
            res = (res << 1) + 1;
        } else {
            res = res << 1;
        }
        n = n >> 1;
    }
    return res;
}
