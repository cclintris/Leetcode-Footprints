#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/**
 * I: s = "1 + 1"
 * O: 2
 *
 * I: s = " 2-1 + 2 "
 * O: 3
 *
 * I: s = "(1+(4+5+2)-3)+(6+8)"
 * O: 23
 */

int calculate(string s);

int main(int argc, char const *argv[]) {
    string s = "- (3 + (4 + 5))";
    cout << calculate(s) << endl;
    return 0;
}

int calculate(string s) {
    int res = 0, n = s.length(), i = 0, sign = 1;
    stack<int> st;
    while (i < n) {
        if (isdigit(s[i])) {
            string tmp = "";
            int num = 0;
            while (s[i] >= '0' && s[i] <= '9') {
                tmp += s[i];
                i++;
            }
            i--;
            num = stoi(tmp) * sign;
            res += num;
        } else if (s[i] == '+') {
            sign = 1;
        } else if (s[i] == '-') {
            sign = -1;
        } else if (s[i] == '(') {
            st.push(res);
            st.push(sign);
            res = 0;
            sign = 1;
        } else if (s[i] == ')') {
            res *= st.top();
            st.pop();
            res += st.top();
            st.pop();
        }
        i++;
    }
    return res;
}
