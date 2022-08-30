#include <iostream>
#include <vector>
using namespace std;

/**
 * I: s = "leetcode", wordDict = ["leet","code"]
 * O: true
 * Explanation: Return true because "leetcode" can be segmented as "leet code".
 *
 * I: s = "applepenapple", wordDict = ["apple","pen"]
 * O: true
 * Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
    Note that you are allowed to reuse a dictionary word.
 *
 * I: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
 * O: false
 */

bool wordBreak(string s, vector<string>& wordDict);

vector<int> nearestT(vector<bool>& dp, int end);

void printVec(vector<bool>& vec);

int main(int argc, char const* argv[]) {
    string s = "applepenapple";
    vector<string> wordDict{"apple", "pen"};
    cout << wordBreak(s, wordDict) << endl;
    return 0;
}

bool wordBreak(string s, vector<string>& wordDict) {
    int n = s.length();
    vector<bool> dp(n, false);
    for (int i = 0; i < n; i++) {
        // cout << "i: " << i << endl;
        // cout << s.substr(0, i + 1) << endl;
        dp[i] = count(wordDict.begin(), wordDict.end(), s.substr(0, i + 1)) != 0 ? true : false;
        // cout << "nearestT: " << nearestT(dp, i) << endl;
        // cout << s.substr(nearestT(dp, i) + 1, i - nearestT(dp, i)) << endl;
        vector<int> vec = nearestT(dp, i);
        for (int j = 0; j < vec.size(); j++) {
            int pos = vec[j];
            dp[i] = dp[i] || count(wordDict.begin(), wordDict.end(), s.substr(pos + 1, i - pos)) != 0 ? true : false;
        }
        // printVec(dp);
    }
    // printVec(dp);
    return dp[n - 1];
}

vector<int> nearestT(vector<bool>& dp, int end) {
    vector<int> vec;
    for (int i = end - 1; i >= 0; i--) {
        if (dp[i]) vec.push_back(i);
    }
    return vec;
}

void printVec(vector<bool>& vec) {
    int len = vec.size();
    cout << "[";
    for (int i = 0; i < len; i++) {
        if (i == len - 1)
            cout << vec[i];
        else
            cout << vec[i] << ',';
    }
    cout << "]" << endl;
}
