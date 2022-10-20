#include <iostream>
using namespace std;

/**
 * I:
 * O:
 *
 * I:
 * O:
 *
 * I:
 * O:
 */

bool isPowerOfThree(int n);

int main(int argc, char const *argv[]) {
    return 0;
}

bool isPowerOfThree(int n) {
    if (n <= 0) return false;
    while (n && n % 3 == 0) {
        n /= 3;
    }
    return n == 1;
}

bool isPowerOfThree(int n) {
    return (n > 0 && 1162261467 % n == 0);
}
