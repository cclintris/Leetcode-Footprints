#include <string.h>

#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

/**
 * I: s = "ADOBECODEBANC", t = "ABC"
 * O: "BANC"
 * Explanation:
 * The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
 *
 * I: s = "a", t = "a"
 * O: "a"
 * Explanation:
 * The entire string s is the minimum window.
 *
 * I: s = "a", t = "aa"
 * O: ""
 * Explanation:
 * Both 'a's from t must be included in the window.
 * Since the largest window of s only has one 'a', return empty string.
 */

string minWindow(string s, string t);

bool checkWindow(string sub, unordered_map<char, int> ht, set<char> ch);

int main(int argc, char const *argv[]) {
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << minWindow(s, t) << endl;
    return 0;
}

string minWindow(string s, string t) {
    int m = s.length(), n = t.length();
    if (m == 0 && n == 0) return "";

    unordered_map<char, int> ht;
    set<char> distinctCh;
    for (int i = 0; i < n; i++) {
        if (ht.find(t[i]) == ht.end()) {
            ht[t[i]] = 1;
        } else {
            ht[t[i]]++;
        }
        distinctCh.insert(t[i]);
    }

    int l = 0, r = 0, min = m + 1;
    vector<int> lrIndex(2);
    while (r <= m) {
        int count = r - l;
        string str = s.substr(l, count);
        if (checkWindow(str, ht, distinctCh)) {
            int tmp = r - l;
            if (tmp < min) {
                min = tmp;
                lrIndex[0] = l;
                lrIndex[1] = r;
            }
            l++;
        } else {
            r++;
        }
    }

    return s.substr(lrIndex[0], lrIndex[1] - lrIndex[0]);
}

bool checkWindow(string sub, unordered_map<char, int> ht, set<char> ch) {
    int len = sub.length();
    for (int i = 0; i < len; i++) {
        if (ht.find(sub[i]) != ht.end()) {
            if (ht[sub[i]] != 0)
                ht[sub[i]]--;
        }
    }
    for (const char c : ch) {
        if (ht[c] != 0)
            return false;
    }
    return true;
}
