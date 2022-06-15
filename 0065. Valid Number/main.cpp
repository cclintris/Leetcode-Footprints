#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

/**
 * I: s = "0"
 * O: true
 *
 * I: s = "e"
 * O: false
 *
 * I: s = "."
 * O: false
 */

bool isNumber(string s);

bool isDecimal(string s);

vector<string> split(string s, char sep);

bool isInteger(string s);

bool hasOneOrMoreDigits(string s);

bool isDigit(char c);

int main(int argc, char const *argv[]) {
    string s = "-123.456e789";
    cout << isNumber(s) << endl;
    return 0;
}

bool isNumber(string s) {
    if (isInteger(s) || isDecimal(s))
        return true;

    vector<string> tokens = split(s, 'e');
    if (tokens.size() == 2)
        return ((isInteger(tokens[0]) || isDecimal(tokens[0]))) && isInteger(tokens[1]);

    tokens = split(s, 'E');
    if (tokens.size() == 2)
        return ((isInteger(tokens[0]) || isDecimal(tokens[0]))) && isInteger(tokens[1]);

    return false;
}

bool isDecimal(string s) {
    if (s.empty())
        return false;

    if (s.front() == '+' || s.front() == '-')
        s = s.substr(1);

    vector<string> tokens = split(s, '.');
    if (tokens.size() != 2)
        return false;

    string left = tokens[0];
    string right = tokens[1];

    if (hasOneOrMoreDigits(left) && right.empty())
        return true;

    if (hasOneOrMoreDigits(left) && hasOneOrMoreDigits(right))
        return true;

    if (left.empty() && hasOneOrMoreDigits(right))
        return true;

    return false;
}

vector<string> split(string s, char sep) {
    vector<string> res;
    stringstream ss(s + sep);
    string token;
    while (getline(ss, token, sep))
        res.__emplace_back(token);
    return res;
}

bool isInteger(string s) {
    if (s.empty())
        return false;

    if (s.front() == '+' || s.front() == '-')
        s = s.substr(1);
    return hasOneOrMoreDigits(s);
}

bool hasOneOrMoreDigits(string s) {
    if (s.empty())
        return false;

    for (char c : s) {
        if (!isDigit(c))
            return false;
    }
    return true;
}

bool isDigit(char c) {
    return c >= '0' && c < '9';
}
