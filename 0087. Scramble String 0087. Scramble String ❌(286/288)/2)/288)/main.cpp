#include <algorithm>
#include <iostream>
using namespace std;

/**
 * I: s1 = "great", s2 = "rgeat"
 * O: true
 *
 * I: s1 = "abcde", s2 = "caebd"
 * O: false
 *
 * I: s1 = "a", s2 = "a"
 * O: true
 */

bool isScramble(string s1, string s2);

int main(int argc, char const* argv[]) {
    string s1 = "abcde", s2 = "caebd";
    cout << isScramble(s1, s2) << endl;
    return 0;
}

bool isScramble(string s1, string s2) {
    if (s1.length() != s2.length()) return false;
    if (s1 == s2) return true;
    string str1 = s1, str2 = s2;
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    if (str1 != str2) return false;
    for (int i = 1; i < s1.length(); i++) {
        string s11 = s1.substr(0, i);
        string s12 = s1.substr(i);
        string s21 = s2.substr(0, i);
        string s22 = s2.substr(i);
        if (isScramble(s11, s21) && isScramble(s12, s22)) return true;
        s21 = s2.substr(s1.length() - i);
        s22 = s2.substr(0, s1.length() - i);
        if (isScramble(s11, s21) && isScramble(s12, s22)) return true;
    }
    return false;
}
