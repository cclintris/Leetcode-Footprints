#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/**
 * I: n = 12
 * O: 3
 * Explanation: 12 = 4 + 4 + 4.
 *
 * I: n = 13
 * O: 2
 * Explanation: 13 = 4 + 9.
 */

int numSquares(int n);

int main(int argc, char const *argv[]) {
    int n = 12;
    cout << numSquares(n) << endl;
    return 0;
}

int numSquares(int n) {
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (j * j > i) break;
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }
    return dp[n];
}
