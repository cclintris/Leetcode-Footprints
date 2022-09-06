#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

/**
 * I: numerator = 1, denominator = 2
 * O: "0.5"
 *
 * I: numerator = 2, denominator = 1
 * O: "2"
 *
 * I: numerator = 4, denominator = 333
 * O: "0.(012)"
 */

string fractionToDecimal(int numerator, int denominator);

int main(int argc, char const *argv[]) {
    int numerator = 1;
    int denominator = 17;
    cout << fractionToDecimal(numerator, denominator) << endl;
    return 0;
}

string fractionToDecimal(int numerator, int denominator) {
    int s1 = numerator >= 0 ? 1 : -1;
    int s2 = denominator >= 0 ? 1 : -1;
    long long num = abs((long long)numerator);
    long long den = abs((long long)denominator);
    long long out = num / den;
    long long rem = num % den;
    unordered_map<long long, int> m;
    string res = to_string(out);
    if (s1 * s2 == -1 && (out > 0 || rem > 0)) res = "-" + res;
    if (rem == 0) return res; 
    res += ".";
    string s = "";
    int pos = 0;
    while (rem != 0) {
        if (m.find(rem) != m.end()) {
            s.insert(m[rem], "(");
            s += ")";
            return res + s;
        }
        m[rem] = pos;
        s += to_string((rem * 10) / den);
        rem = (rem * 10) % den;
        pos++;
    }
    return res + s;
}
