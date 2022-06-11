#include <iostream>
#include <vector>
using namespace std;

/**
 * I: m = 3, n = 7
 * O: 28
 *
 * I: m = 3, n = 2
 * O: 3
 */

int uniquePaths(int m, int n);

int main(int argc, char const *argv[]) {
    int m = 2, n = 2;
    cout << uniquePaths(m, n) << endl;
    return 0;
}

int uniquePaths(int m, int n) {
    if (m == 1 && n == 1) return 1;
    vector<vector<int> > dp(m, vector<int>(n));
    dp[0][0] = 0;
    for (int i = 1; i < m; i++)
        dp[i][0] = 1;
    for (int i = 1; i < n; i++)
        dp[0][i] = 1;
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];
}
