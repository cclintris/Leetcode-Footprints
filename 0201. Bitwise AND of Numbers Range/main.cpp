#include <iostream>
using namespace std;

/**
 * I: left = 5, right = 7
 * O: 4
 *
 * I: left = 0, right = 0
 * O: 0
 *
 * I: left = 1, right = 2147483647
 * O: 0
 */

int rangeBitwiseAnd(int left, int right);

int main(int argc, char const *argv[]) {
    int left = 5;
    int right = 7;
    cout << rangeBitwiseAnd(left, right) << endl;
    return 0;
}

// TLE
// int rangeBitwiseAnd(int left, int right) {
//     uint32_t l = uint32_t(left);
//     uint32_t r = uint32_t(right);
//     int res = left;
//     for (uint32_t i = l + 1; i <= r; i++) {
//         res = (int)(res & i);
//     }
//     return res;
// }

int rangeBitwiseAnd(int left, int right) {
    int res = 0;
    for (int i = 31; i >= 0; i--) {
        if ((left & (1 << i)) == (right & (1 << i)))
            res += (left & (1 << i));
        else
            break;
    }
    return res;
}
