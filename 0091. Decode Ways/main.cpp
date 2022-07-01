#include <iostream>
#include <vector>
using namespace std;

/**
 * I: s = "12"
 * O: 2
 * Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).
 *
 * I: s = "226"
 * O: 3
 * Explanation: "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
 *
 * I: s = "06"
 * O: 0
 * Explanation: "06" cannot be mapped to "F" because of the leading zero ("6" is different from "06").
 */

int numDecodings(string s);

void printVec(vector<int>& vec);

int main(int argc, char const* argv[]) {
    string s = "27";
    cout << numDecodings(s) << endl;
    return 0;
}

int numDecodings(string s) {
    if (s.empty() || s[0] == '0') return 0;
    if (s.length() == 1) return 1;
    vector<int> dp(s.length(), 0);
    dp[0] = 1;
    dp[1] = s[1] == '0' ? 0 : dp[0];
    if ((s[0] == '1') || (s[0] == '2' && s[1] <= '6'))
        dp[1] += dp[0];
    // printVec(dp);
    for (int i = 2; i < s.length(); i++) {
        dp[i] = s[i] == '0' ? 0 : dp[i - 1];
        if (i > 1 && (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6'))) {
            dp[i] += dp[i - 2];
        }
        // printVec(dp);
    }
    return dp[s.length() - 1];
}

void printVec(vector<int>& vec) {
    int len = vec.size();
    cout << "[";
    for (int i = 0; i < len; i++) {
        if (i == len - 1)
            cout << vec[i];
        else
            cout << vec[i] << ',';
    }
    cout << "]\n";
}
