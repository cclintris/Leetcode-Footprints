#include <iostream>
#include <vector>
using namespace std;

/**
 * I: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
 * O: ["cats and dog","cat sand dog"]
 *
 * I: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
 * O: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
    Explanation: Note that you are allowed to reuse a dictionary word.
 *
 * I: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
 * O: []
 */

vector<string> wordBreak(string s, vector<string>& wordDict);

vector<bool> wordBreakDP(string s, vector<string>& wordDict);

vector<int> nearestT(vector<bool>& dp, int end);

void printVec(vector<bool>& vec);

int main(int argc, char const* argv[]) {
    return 0;
}

vector<string> wordBreak(string s, vector<string>& wordDict) {
    vector<bool> dp = wordBreakDP(s, wordDict);
    if (!dp.back()) return {};
    // unsolved
}

vector<bool> wordBreakDP(string s, vector<string>& wordDict) {
    int n = s.length();
    vector<bool> dp(n, false);
    for (int i = 0; i < n; i++) {
        dp[i] = count(wordDict.begin(), wordDict.end(), s.substr(0, i + 1)) != 0 ? true : false;
        vector<int> vec = nearestT(dp, i);
        for (int j = 0; j < vec.size(); j++) {
            int pos = vec[j];
            dp[i] = dp[i] || count(wordDict.begin(), wordDict.end(), s.substr(pos + 1, i - pos)) != 0 ? true : false;
        }
    }
    return dp;
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
