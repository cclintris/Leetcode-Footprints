#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/**
 * I: s = "abcde", words = ["a","bb","acd","ace"]
 * O: 3
 * Explanation: There are three strings in words that are a subsequence of s: "a", "acd", "ace".
 *
 * I: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
 * O: 2
 */

int numMatchingSubseq(string s, vector<string>& words);

bool checkSubseq(string s, string word);

int main(int argc, char const* argv[]) {
    string s = "dsahjpjauf";
    vector<string> words{"ahjpjau", "ja", "ahbwzgqnuk", "tnmlanowax"};
    cout << numMatchingSubseq(s, words) << endl;
    return 0;
}

// Using hashmaps passes OA
int numMatchingSubseq(string s, vector<string>& words) {
    int res = 0;
    unordered_map<string, int> mp;
    for (string word : words) {
        mp[word]++;
    }
    for (auto it : mp) {
        if (checkSubseq(s, it.first)) {
            res += it.second;
        }
    }
    return res;
}

bool checkSubseq(string s, string word) {
    if (word.length() > s.length()) return false;
    int p1 = 0, p2 = 0;
    while (p1 < s.length() && p2 < word.length()) {
        if (s[p1] == word[p2]) {
            p2++;
        }
        p1++;
    }
    return p2 >= word.length() ? true : false;
}

// Optimal: Next letter pointer
// Impossible algorithm
int numMatchingSubseq(string s, vector<string>& words) {
    
}
