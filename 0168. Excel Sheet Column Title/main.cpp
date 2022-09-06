#include <iostream>
using namespace std;

/**
 * I: columnNumber = 1
 * O: A
 *
 * I: columnNumber = 28
 * O: AB
 *
 * I: columnNumber = 701
 * O: ZY
 */

string convertToTitle(int columnNumber);

int main(int argc, char const *argv[]) {
    int columnNumber = 701;
    cout << convertToTitle(columnNumber) << endl;
    return 0;
}

string convertToTitle(int columnNumber) {
    string res = "";
    while (columnNumber > 26) {
        int rem = columnNumber % 26;
        if (rem == 0) {
            res = 'Z' + res;
        } else {
            res = char(rem + 64) + res;
        }
        columnNumber /= 26;
        if (rem == 0) columnNumber -= (rem + 1);
    }
    res = char(columnNumber + 64) + res;
    return res;
}
