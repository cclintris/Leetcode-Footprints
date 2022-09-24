#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

/**
 * I: s = "())"
 * O: 1
 *
 * I: s = "((("
 * O: 3
 */

int minAddToMakeValid(string s);

int main(int argc, char const *argv[]) {
    string s = "()))((";
    cout << minAddToMakeValid(s) << endl;
    return 0;
}

int minAddToMakeValid(string s) {
    stack<char> st;
    int res = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            st.push(s[i]);
        } else {
            if (st.empty()) {
                res++;
            } else {
                st.pop();
            }
        }
    }
    return res + int(st.size());
}
