#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * I: num = 2736
 * O: 7236
 * Explanation: Swap the number 2 and the number 7.
 *
 * I: num = 9973
 * O: 9973
 * Explanation: No swap.
 */

int maximumSwap(int num);

void swap(string& s, int i, int j);

int main(int argc, char const* argv[]) {
    int num = 2736;
    cout << maximumSwap(num) << endl;
    return 0;
}

int maximumSwap(int num) {
    vector<int> numArr(10, -1);
    string s = to_string(num);
    for (int i = 0; i < s.length(); i++) {
        numArr[s[i] - '0'] = i;
    }
    for (int i = 0; i < s.length(); i++) {
        for (int j = 9; j >= 0; j--) {
            if (numArr[j] != -1 && numArr[j] > i && j > s[i] - '0') {
                swap(s, i, numArr[j]);
                return stoi(s);
            }
        }
    }

    return num;
}

void swap(string& s, int i, int j) {
    // cout << i << j << endl;
    char c = s[i];
    s[i] = s[j];
    s[j] = c;
}
