#include <iostream>
#include <stack>
using namespace std;

/**
 * I: s = "3+2*2"
 * O: 7
 *
 * I: s = " 3/2 "
 * O: 1
 *
 * I: s = " 3+5 / 2 "
 * O: 5
 *
 * I: s = "22 - 3 * 5"
 * O: 7
 */

int calculate(string s);

int main(int argc, char const *argv[]) {
    string s = "3/2";
    cout << calculate(s) << endl;
    return 0;
}

int calculate(string s) {
    int len = s.length();
    if (len == 0) return 0;
    stack<int> stack;
    int currentNumber = 0;
    char operation = '+';
    for (int i = 0; i < len; i++) {
        char currentChar = s[i];
        if (isdigit(currentChar)) {
            currentNumber = (currentNumber * 10) + (currentChar - '0');
        }
        if (!isdigit(currentChar) && !iswspace(currentChar) || i == len - 1) {
            if (operation == '-') {
                stack.push(-currentNumber);
            } else if (operation == '+') {
                stack.push(currentNumber);
            } else if (operation == '*') {
                int stackTop = stack.top();
                stack.pop();
                stack.push(stackTop * currentNumber);
            } else if (operation == '/') {
                int stackTop = stack.top();
                stack.pop();
                stack.push(stackTop / currentNumber);
            }
            operation = currentChar;
            currentNumber = 0;
        }
    }
    int result = 0;
    while (!stack.empty()) {
        result += stack.top();
        stack.pop();
    }
    return result;
}