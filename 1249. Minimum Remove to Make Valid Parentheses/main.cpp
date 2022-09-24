#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/**
 * I: s = "lee(t(c)o)de)"
 * O: "lee(t(c)o)de"
 * Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
 *
 * I: s = "a)b(c)d"
 * O: "ab(c)d"
 *
 * I: s = "))(("
 * O: ""
 * Explanation: An empty string is also valid.
 */

string minRemoveToMakeValid(string s);

void printVec(vector<int>& vec);

int main(int argc, char const* argv[]) {
    string s = "())";
    cout << minRemoveToMakeValid(s) << endl;
    return 0;
}

string minRemoveToMakeValid(string s) {
    string res = "";
    stack<int> st;
    vector<int> arr1;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 97 && s[i] <= 122) {
            continue;
        }
        if (s[i] == '(') {
            st.push(i);
        } else {
            if (st.empty()) {
                arr1.push_back(i);
            } else {
                st.pop();
            }
        }
    }
    vector<int> arr2;
    while (!st.empty()) {
        arr2.push_back(st.top());
        st.pop();
    }
    // printVec(arr1);
    // printVec(arr2);
    for (int i = 0; i < s.length(); i++) {
        if (find(arr1.begin(), arr1.end(), i) != arr1.end() || find(arr2.begin(), arr2.end(), i) != arr2.end()) continue;
        res += s[i];
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
