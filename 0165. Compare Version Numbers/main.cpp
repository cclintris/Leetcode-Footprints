#include <iostream>
using namespace std;

/**
 * I: version1 = "1.01", version2 = "1.001"
 * O: 0
 * Explanation: Ignoring leading zeroes, both "01" and "001" represent the same integer "1".
 *
 * I: version1 = "1.0", version2 = "1.0.0"
 * O: 0
 * Explanation: version1 does not specify revision 2, which means it is treated as "0".
 *
 * I: version1 = "0.1", version2 = "1.1"
 * O: -1
 * Explanation: version1's revision 0 is "0",
 * while version2's revision 0 is "1". 0 < 1, so version1 < version2.
 */

int compareVersion(string version1, string version2);

int main(int argc, char const *argv[]) {
    string version1 = "1.0";
    string version2 = "1.0.1";
    cout << compareVersion(version1, version2) << endl;
    return 0;
}

int compareVersion(string version1, string version2) {
    int l1 = version1.length(), l2 = version2.length();
    int p1 = 0, p2 = 0;
    long int num1 = 0, num2 = 0;
    while (p1 < l1 || p2 < l2) {
        while (p1 < l1 && version1[p1] != '.') {
            num1 += num1 * 10 + (version1[p1] - '0');
            p1++;
        }
        while (p2 < l2 && version2[p2] != '.') {
            num2 += num2 * 10 + (version2[p2] - '0');
            p2++;
        }
        if (num1 > num2) return 1;
        if (num1 < num2) return -1;
        num1 = 0;
        num2 = 0;
        p1++;
        p2++;
    }
    return 0;
}
