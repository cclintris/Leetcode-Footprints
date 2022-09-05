#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

/**
 * I: s = "eceba"
 * O: 3
 * Explanation: The substring is "ece" which its length is 3.
 *
 * I: s = "ccaabbb"
 * O: 5
 * Explanation: The substring is "aabbb" which its length is 5.
 */

int lengthOfLongestSubstringTwoDistinct(string s);

int main(int argc, char const *argv[]) {
    string s = "eceba";
    cout << lengthOfLongestSubstringTwoDistinct(s) << endl;
    return 0;
}

int lengthOfLongestSubstringTwoDistinct(string s) {
    if (s.length() == 1 || s == "") return 1;
    unordered_map<char, int> mp;
    int left = 0, right = 0;
    int res = 0;
    while (right < s.length()) {
        mp[s[right]]++;
        while (mp.size() > 2) {
            if (--mp[s[left]] == 0)
                mp.erase(s[left]);
            left++;
        }
        res = max(res, right - left + 1);
        right++;
    }
    return res;
}
