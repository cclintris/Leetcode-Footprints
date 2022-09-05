#include <iostream>
#include <string>
using namespace std;

/**
 * I: s = "ab", t = "acb"
 * O: true
 * Explanation: We can insert 'c' into s to get t.
 *
 * I: s = "", t = ""
 * O: false
 * Explanation: We cannot get t from s by only one step.
 */

bool isOneEditDistance(string s, string t);

int main(int argc, char const *argv[]) {
    string s = "";
    string t = "";
    cout << isOneEditDistance(s, t) << endl;
    return 0;
}

bool isOneEditDistance(string s, string t) {
    if (s.length() < t.length()) swap(s, t);
    int n = s.length(), m = t.length();
    int diff = n - m;
    if (abs(diff) > 1) {
        return false;
    } else if (abs(diff) == 1) {  // length differs by one
        for (int i = 0; i < n; i++) {
            string s1 = s.substr(0, i);
            string s2 = s.substr(i + 1, n - i - 1);
            if (s1 + s2 == t) return true;
        }
        return false;
    } else {  // same length
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != t[i]) {
                cnt++;
            }
        }
        return cnt == 1;
    }
}
