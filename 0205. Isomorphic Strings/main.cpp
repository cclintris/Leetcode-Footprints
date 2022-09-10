#include <iostream>
#include <unordered_map>
using namespace std;

/**
 * I: s = "egg", t = "add"
 * O: true
 *
 * I: s = "foo", t = "bar
 * O: false
 *
 * I: s = "paper", t = "title"
 * O: true
 */

bool isIsomorphic(string s, string t);

int main(int argc, char const *argv[]) {
    string s = "badc";
    string t = "baba";
    cout << isIsomorphic(s, t) << endl;
    return 0;
}

bool isIsomorphic(string s, string t) {
    int l1 = s.length(), l2 = t.length();
    if (l1 != l2) return false;
    unordered_map<char, char> mp;
    for (int i = 0; i < l1; i++) {
        for (auto it : mp) {
            if (it.second == t[i] && s[i] != it.first)
                return false;
        }
        if (mp.find(s[i]) == mp.end())
            mp[s[i]] = t[i];
        s[i] = mp[s[i]];
    }
    return s == t;
}
