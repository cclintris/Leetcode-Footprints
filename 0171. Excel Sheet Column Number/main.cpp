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

int titleToNumber(string columnTitle);

int main(int argc, char const *argv[]) {
    return 0;
}

int titleToNumber(string columnTitle) {
    int result = 0;
    for (char c : columnTitle) {
        int d = c - 'A' + 1;
        result = result * 26 + d;
    }
    return result;
}
