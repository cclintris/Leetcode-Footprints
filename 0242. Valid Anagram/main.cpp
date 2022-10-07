#include <iostream>
#include <unordered_map>
using namespace std;

/**
 * I: s = "anagram", t = "nagaram"
 * O: 1
 *
 * I: s = "rat", t = "car"
 * O: 0
 */

bool isAnagram(string s, string t);

int main(int argc, char const *argv[]) {
    return 0;
}

bool isAnagram(string s, string t) {
    unordered_map<char, int> mp_s;
    unordered_map<char, int> mp_t;
    int len_s = s.size(), len_t = t.size();
    if (len_s != len_t) return false;
    for (int i = 0; i < len_s; i++) {
        mp_s[s[i]]++;
        mp_t[t[i]]++;
    }
    for (auto it : mp_t) {
        if (mp_s.find(it.first) == mp_s.end()) return false;
        if (it.second != mp_s[it.first]) return false;
    }
    return true;
}
