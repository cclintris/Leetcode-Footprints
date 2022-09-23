#include <iostream>
using namespace std;

/**
 * I: s = "aba"
 * O: 1
 *
 * I: s = "abca"
 * O: 1
 *
 * I: s = "abc"
 * O: 0
 */

bool validPalindrome(string s);

bool checkPalindrome(string s, int l, int r);

int main(int argc, char const *argv[]) {
    return 0;
}

bool validPalindrome(string s) {
    int l = 0, r = s.length() - 1;
    if (checkPalindrome(s, l, r)) return true;
    while (l < r) {
        if (s[l] != s[r]) {
            return checkPalindrome(s, l + 1, r) || checkPalindrome(s, l, r - 1);
        }
        l++;
        r--;
    }
    return true;
}

bool checkPalindrome(string s, int l, int r) {
    while (l < r) {
        if (s[l] != s[r])
            return false;
        l++;
        r--;
    }
    return true;
}
