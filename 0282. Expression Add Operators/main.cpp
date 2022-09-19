#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * I: num = "123", target = 6
 * O: ["1*2*3","1+2+3"]
 * Explanation: Both "1*2*3" and "1+2+3" evaluate to 6.
 *
 * I: num = "232", target = 8
 * O: ["2*3+2","2+3*2"]
 * Explanation: Both "2*3+2" and "2+3*2" evaluate to 8.
 *
 * I: num = "3456237490", target = 9191
 * O: []
 * Explanation: There are no expressions that can be created from "3456237490" to evaluate to 91
 */

vector<string> addOperators(string num, int target);

void dfs(string& num, int target, vector<string>& expressions, int index, string path, long int res, long int prev);

void printVec(vector<string>& vec);

int main(int argc, char const* argv[]) {
    string num = "123";
    int target = 6;
    vector<string> res = addOperators(num, target);
    printVec(res);
    return 0;
}

vector<string> addOperators(string num, int target) {
    vector<string> expressions;
    dfs(num, target, expressions, 0, "", 0, 0);
    return expressions;
}

void dfs(string& num, int target, vector<string>& expressions, int index, string path, long int res, long int prev) {
    if (index == num.size() && res == target) {
        expressions.push_back(path);
        return;
    }

    long int number = 0;
    string sub_string = "";

    for (int i = index; i < num.size(); ++i) {
        sub_string += num[i];
        number = (number * 10) + num[i] - '0';

        if (sub_string.size() > 1 && sub_string[0] == '0')  // skipping numbers with leading 0's
            break;

        if (index == 0) {  // first number of expression is picked without operator
            dfs(num, target, expressions, i + 1, sub_string, number, number);
        } else {
            // (1) + operation inserted
            dfs(num, target, expressions, i + 1, path + "+" + sub_string, res + number, number);

            // (2) - operation inserted
            dfs(num, target, expressions, i + 1, path + "-" + sub_string, res - number, -number);

            // (3) * operation inserted
            dfs(num, target, expressions, i + 1, path + "*" + sub_string, (res - prev) + (prev * number), prev * number);
        }
    }
}

void printVec(vector<string>& vec) {
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
