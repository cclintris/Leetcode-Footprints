#include <iostream>
using namespace std;

/**
 * I: s = "A man, a plan, a canal: Panama"
 * O: 1
 * Explanation: "amanaplanacanalpanama" is a palindrome.
 *
 * I: s = "race a car"
 * O: 0
 * Explanation: "raceacar" is not a palindrome.
 *
 * I: s = " "
 * O: 1
 * Explanation: s is an empty string "" after removing non-alphanumeric characters.
   Since an empty string reads the same forward and backward, it is a palindrome.
 */

bool isPalindrome(string s);

int main(int argc, char const *argv[]) {
    string s = "0P";
    cout << isPalindrome(s) << endl;
    return 0;
}

bool isPalindrome(string s) {
    string str = "";
    for (char c : s) {
        int code = (int)c;
        if (code >= 65 && code <= 90) {
            c = char(code + 32);
            str += c;
        }
        if ((code >= 97 && code <= 122) ||
            (code >= 48 && code <= 57)) {
            str += c;
        }
    }

    int l = 0, r = str.length() - 1;
    while (l < r) {
        if (str[l] != str[r])
            return false;
        l++;
        r--;
    }
    return true;
}
