#include <iostream>
#include <string>
using namespace std;

/**
 * I: num1 = "11", num2 = "123"
 * O: "134"
 *
 * I: num1 = "456", num2 = "77"
 * O: "533"
 *
 * I: num1 = "0", num2 = "0"
 * O: "0"
 */

string addStrings(string num1, string num2);

int main(int argc, char const *argv[]) {
    string num1 = "0";
    string num2 = "0";
    cout << addStrings(num1, num2) << endl;
    return 0;
}

string addStrings(string num1, string num2) {
    string res = "";
    int carry = 0;
    int p1 = num1.length() - 1, p2 = num2.length() - 1;
    while (p1 >= 0 && p2 >= 0) {
        int num = (num1[p1] - '0') + (num2[p2] - '0') + carry;
        if (num >= 10) {
            num -= 10;
            carry = 1;
        } else {
            carry = 0;
        }
        res = to_string(num) + res;
        // cout << "res: " << res << endl;
        p1--;
        p2--;
    }
    // cout << "p1: " << p1 << endl;
    // cout << "p2: " << p2 << endl;
    if (p1 >= 0) {
        while (p1 >= 0) {
            int num = (num1[p1] - '0') + carry;
            if (num >= 10) {
                num -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            res = to_string(num) + res;
            p1--;
        }
    }
    if (p2 >= 0) {
        while (p2 >= 0) {
            int num = (num2[p2] - '0') + carry;
            if (num >= 10) {
                num -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            res = to_string(num) + res;
            p2--;
        }
    }

    if (carry) res = "1" + res;
    return res;
}
