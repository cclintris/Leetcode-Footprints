#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/**
 * I: order = "cba", s = "abcd"
 * O: "cbad"
 * Explanation:
    "a", "b", "c" appear in order, so the order of "a", "b", "c" should be "c", "b", and "a".
    Since "d" does not appear in order, it can be at any position in the returned string. "dcba", "cdba", "cbda" are also valid outputs.
 *
 * I: order = "cbafg", s = "abcd"
 * O: "cbad"
 */

string customSortString(string order, string s);

void printVec(vector<int>& vec);

int main(int argc, char const* argv[]) {
    string order = "cbafg";
    string s = "abcd";
    cout << customSortString(order, s) << endl;
    return 0;
}

string customSortString(string order, string s) {
    vector<int> ch(26, 0);
    for (int i = 0; i < s.length(); i++) {
        ch[s[i] - 97]++;
    }
    // printVec(ch);
    string res = "";
    for (int i = 0; i < order.length(); i++) {
        if (ch[order[i] - 97] > 0) {
            while (ch[order[i] - 97] > 0) {
                res += order[i];
                ch[order[i] - 97]--;
            }
            // cout << "res: " << res << endl;
        }
    }
    for (int i = 0; i < ch.size(); i++) {
        if (ch[i] > 0) {
            while (ch[i] > 0) {
                res += (i + 97);
                ch[i]--;
            }
        }
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
    cout << "]" << endl;
}
