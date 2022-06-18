#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/**
 * I: word1 = "horse", word2 = "ros"
 * O: 3
 * Explanation:
    horse -> rorse (replace 'h' with 'r')
    rorse -> rose (remove 'r')
    rose -> ros (remove 'e')
 *
 * I: word1 = "intention", word2 = "execution"
 * O: 5
 * Explanation:
    intention -> inention (remove 't')
    inention -> enention (replace 'i' with 'e')
    enention -> exention (replace 'n' with 'x')
    exention -> exection (replace 'n' with 'c')
    exection -> execution (insert 'u')
 */

int minDistance(string word1, string word2);

int main(int argc, char const *argv[]) {
    string word1 = "intention";
    string word2 = "execution";
    cout << minDistance(word1, word2) << endl;
    return 0;
}

int minDistance(string word1, string word2) {
    int m = word1.length(), n = word2.length();
    vector<vector<int> > dp(m + 1, vector<int>(n + 1));
    dp[0][0] = 0;
    for (int i = 1; i <= m; i++)
        dp[i][0] = dp[i - 1][0] + 1;
    for (int i = 1; i <= n; i++)
        dp[0][i] = dp[0][i - 1] + 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
            }
        }
    }

    return dp[m][n];
}
