#include <iostream>
using namespace std;

/**
 * I: word = "internationalization", abbr = "i12iz4n"
 * O: true
 * Explanation: The word "internationalization" can be abbreviated as "i12iz4n" ("i nternational iz atio n").
 *
 * I: word = "apple", abbr = "a2e"
 * O: false
 * Explanation: The word "apple" cannot be abbreviated as "a2e".
 */

bool validWordAbbreviation(string word, string abbr);

int main(int argc, char const *argv[]) {
    string word = "hi";
    string abbr = "hi1";
    cout << validWordAbbreviation(word, abbr) << endl;
    return 0;
}

bool validWordAbbreviation(string word, string abbr) {
    int p1 = 0, p2 = 0;
    while (p1 < word.length() && p2 < abbr.length()) {
        // cout << "start" << endl;
        // cout << "p1: " << p1 << endl;
        // cout << "p2: " << p2 << endl;
        if (abbr[p2] == '0') return false;
        if (abbr[p2] <= '9' && abbr[p2] > '0') {
            // cout << "digits" << endl;
            int num = 0;
            while (abbr[p2] <= '9' && abbr[p2] >= '0') {
                num = (num * 10 + (abbr[p2] - '0'));
                p2++;
            }
            if (num == 0) return false;
            // cout << "num: " << num << endl;
            p1 += num;
            if (p1 > word.length()) return false;
            // cout << "p1: " << p1 << endl;
            // cout << "p2: " << p2 << endl;
        } else {
            // cout << "char" << endl;
            if (word[p1] != abbr[p2])
                return false;
            p1++;
            p2++;
            // cout << "p1: " << p1 << endl;
            // cout << "p2: " << p2 << endl;
        }
    }
    if (p1 != word.length() || p2 != abbr.length()) return false;
    return true;
}
