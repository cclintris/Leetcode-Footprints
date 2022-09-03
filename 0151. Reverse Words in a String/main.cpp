#include <iostream>
#include <stack>
#include <string>
using namespace std;

/**
 * I: s = "the sky is blue"
 * O: "blue is sky the"
 *
 * I: s = "  hello world  "
 * O: "world hello"
 * Explanation: Your reversed string should not contain leading or trailing spaces.
 *
 * I: s = "a good   example"
 * O: "example good a"
 * Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 */

string reverseWords(string s);

int findFirstLetter(string s);

int main(int argc, char const *argv[]) {
    string s = "  hello world  ";
    cout << reverseWords(s) << endl;
    return 0;
}

string reverseWords(string s) {
    if (s == "") return "";
    stack<string> stack;
    string tmp = "";
    int firstChar = findFirstLetter(s);
    if (firstChar < 0) return "";
    for (int i = firstChar; i < s.length(); i++) {
        if (s[i] == ' ') {
            if (tmp == "") {
                continue;
            } else {
                stack.push(tmp);
                tmp = "";
            }
        } else {
            tmp += s[i];
        }
    }
    if (tmp != "")
        stack.push(tmp);

    string res = "";
    while (!stack.empty()) {
        // cout << "stack.top(): " << stack.top() << endl;
        res += stack.top() + " ";
        stack.pop();
    }
    res.erase(res.end() - 1);
    return res;
}

int findFirstLetter(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            continue;
        } else {
            return i;
        }
    }
    return -1;
}
