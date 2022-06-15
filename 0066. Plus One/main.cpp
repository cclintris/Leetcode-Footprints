#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

/**
 * I: digits = [1,2,3]
 * O: [1,2,4]
 *
 * I: digits = [4,3,2,1]
 * O: [4,3,2,2]
 *
 * I: digits = [9]
 * O: [1,0]
 */

vector<int> plusOne(vector<int>& digits);

void printVec(vector<int>& vec);

int main(int argc, char const* argv[]) {
    int m = 10;
    int arr[] = {9, 9, 9, 9, 9, 9, 9, 9, 9, 9};

    vector<int> digits;
    for (int i = 0; i < m; i++)
        digits.push_back(arr[i]);

    vector<int> vec = plusOne(digits);
    printVec(vec);
    return 0;
}

vector<int> plusOne(vector<int>& digits) {
    int carry = 0;
    int len = digits.size();
    vector<int> res(len + 1);
    for (int i = len - 1; i >= 0; i--) {
        int num = 0;
        if (i == len - 1)
            num = digits[i] + carry + 1;
        else
            num = digits[i] + carry;

        if (num >= 10) {
            num = num % 10;
            carry = 1;
        } else {
            carry = 0;
        }

        res[i + 1] = num;
    }

    if (carry == 1) {
        res[0] = 1;
    } else {
        res.erase(res.begin(), res.begin() + 1);
    }

    return res;
}

void printVec(vector<int>& vec) {
    int len = vec.size();
    cout << "[";
    for (int i = 0; i < len; i++) {
        if (i == len - 1)
            cout << vec[i];
        else
            cout << vec[i] << ',';
    }
    cout << "]";
}
