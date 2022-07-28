#include <iostream>
#include <vector>
using namespace std;

/**
 * I: s = "rabbbit", t = "rabbit"
 * O: 3
 *
 * I: s = "babgbag", t = "bag"
 * O: 5
 */

int numDistinct(string s, string t);

void printVec(int m, int n, vector<vector<int>>& vec);

int main(int argc, char const* argv[]) {
    string s = "babgbag";
    string t = "bag";
    cout << numDistinct(s, t) << endl;
    return 0;
}

int numDistinct(string s, string t) {
    if (s == t) return 1;
    int m = s.size(), n = t.size();
    vector<vector<unsigned long>> dp(n + 1, vector<unsigned long>(m + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= m; i++)
        dp[0][i] = 1;
    for (int i = 1; i <= n; i++)
        dp[i][0] = 0;
    // printVec(n + 1, m + 1, dp);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j == i && s[j - 1] == t[i - 1])
                dp[i][j] = dp[i - 1][j - 1];
            if (j > i && s[j - 1] == t[i - 1])
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
            if (j > i && s[j - 1] != t[i - 1])
                dp[i][j] = dp[i][j - 1];
        }
    }

    return dp[n][m];
}

void printVec(int m, int n, vector<vector<int>>& vec) {
    // cout << "[" << endl;
    for (int i = 0; i < m; i++) {
        cout << "[";
        for (int j = 0; j < n; j++) {
            if (j == n - 1 && i == m - 1) {
                cout << vec[i][j] << "]" << endl;
                break;
            }
            if (j != n - 1)
                cout << vec[i][j] << ",";
            else
                cout << vec[i][j] << "]," << endl;
        }
    }
    cout << "------------------------------" << endl;
    // cout << "]" << endl;
}
