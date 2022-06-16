#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

/**
 * I: a = "11", b = "1"
 * O: 100
 *
 * I: a = "1010", b = "1011"
 * O: "10101"
 */

string addBinary(string a, string b);

vector<int> remainAddBinary(vector<int>& vec, string s, int& index, int& carry);

void printVec(vector<int>& vec);

int main(int argc, char const* argv[]) {
    string a = "11";
    string b = "1011";
    string res = addBinary(a, b);
    cout << res << endl;
    return 0;
}

string addBinary(string a, string b) {
    vector<int> vec;
    int aIndex = a.length() - 1, bIndex = b.length() - 1;
    int carry = 0;
    while (aIndex >= 0 && bIndex >= 0) {
        int num1 = int(a[aIndex]) - 48;
        int num2 = int(b[bIndex]) - 48;
        // cout << "num1: " << num1 << endl;
        // cout << "num2: " << num2 << endl;
        int tmp = num1 + num2 + carry;
        if (tmp >= 2) {
            tmp -= 2;
            carry = 1;
        } else {
            carry = 0;
        }
        vec.insert(vec.begin(), tmp);
        aIndex--;
        bIndex--;
    }

    // printVec(vec);

    vec = remainAddBinary(vec, a, aIndex, carry);
    vec = remainAddBinary(vec, b, bIndex, carry);

    // printVec(vec);

    if (carry == 1)
        vec.insert(vec.begin(), 1);

    // printVec(vec);
    
    stringstream ss;
    for (int i = 0; i < vec.size(); i++)
        ss << vec[i];

    return ss.str();
}

vector<int> remainAddBinary(vector<int>& vec, string s, int& index, int& carry) {
    if (index >= 0) {
        while (index >= 0) {
            int tmp = int(s[index]) + carry - 48;
            if (tmp >= 2) {
                tmp -= 2;
                carry = 1;
            } else {
                carry = 0;
            }
            vec.insert(vec.begin(), tmp);
            index--;
        }
    }

    return vec;
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
