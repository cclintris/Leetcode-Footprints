#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/**
 * I: s = ["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]
 * O: ["b","l","u","e"," ","i","s"," ","s","k","y"," ","t","h","e"]
 *
 * I: s = ["a"]
 * O: ["a"]
 */

void reverseWords(vector<char>& s);

void printVec(vector<char>& vec);

int main(int argc, char const* argv[]) {
    vector<char> s{'t', 'h', 'e', ' ', 's', 'k', 'y', ' ', 'i', 's', ' ', 'b', 'l', 'u', 'e'};
    printVec(s);
    reverseWords(s);
    printVec(s);
    return 0;
}

void reverseWords(vector<char>& s) {
    if (s.size() == 0) return;
    int l = s.size();
    stack<char> st;
    string tmp = "";
    int pos = 0;
    st.push(' ');
    for (int i = 0; i < l; i++) st.push(s[i]);
    while (!st.empty()) {
        tmp = "";
        while (st.top() != ' ') {
            tmp = st.top() + tmp;
            st.pop();
        }
        st.pop();
        if (!st.empty()) tmp += ' ';
        for (int i = 0; i < tmp.length(); i++) {
            s[pos++] = tmp[i];
        }
    }
}

void printVec(vector<char>& vec) {
    int len = vec.size();
    cout << "[";
    for (int i = 0; i < len; i++) {
        if (i == len - 1)
            cout << vec[i];
        else
            cout << vec[i] << ',';
    }
    cout << "]\n";
}
