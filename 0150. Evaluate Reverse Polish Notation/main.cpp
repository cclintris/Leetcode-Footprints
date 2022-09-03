#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

/**
 * I: tokens = ["2","1","+","3","*"]
 * O: 9
 * Explanation: ((2 + 1) * 3) = 9
 *
 * I: tokens = ["4","13","5","/","+"]
 * O: 6
 * Explanation: (4 + (13 / 5)) = 6
 *
 * I: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
 * O: 22
 * Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
 */

int evalRPN(vector<string>& tokens);

int main(int argc, char const* argv[]) {
    vector<string> tokens{"10", "6", "+"};
    cout << evalRPN(tokens) << endl;
    // vector<string>::iterator it = tokens.begin();
    // cout << stoi(*it) + 4 << endl;
    return 0;
}

int evalRPN(vector<string>& tokens) {
    stack<int> operand;
    int res = stoi(tokens[0]);
    vector<string>::iterator it = tokens.begin();
    while (it != tokens.end()) {
        if ((*it) != "+" && (*it) != "-" && (*it) != "*" && (*it) != "/") {
            operand.push(stoi(*it));
        } else {
            int num1 = operand.top();
            operand.pop();
            int num2 = operand.top();
            operand.pop();
            if ((*it) == "+") {
                operand.push(num1 + num2);
            } else if ((*it) == "-") {
                operand.push(num2 - num1);
            } else if ((*it) == "*") {
                operand.push(num1 * num2);
            } else {
                operand.push(num2 / num1);
            }
            res = operand.top();
        }
        it++;
    }
    return res;
}
