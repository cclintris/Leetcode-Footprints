#include <iostream>
using namespace std;

/**
 * I: x = 4
 * O: 2
 *
 * I: x = 8
 * O: 2
 */

int mySqrt(int x);

int main(int argc, char const *argv[]) {
    int x = 8;
    cout << mySqrt(x) << endl;
    return 0;
}

int mySqrt(int x) {
    if (x == 0 || x == 1) return x;
    int l = 0, r = x;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (x / mid == mid) return mid;
        if (x / mid < mid) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    return r;
}
