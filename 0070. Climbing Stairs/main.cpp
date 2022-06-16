#include <iostream>
using namespace std;

/**
 * I: n = 2
 * O: 2
 * Explanation: There are two ways to climb to the top.
    1. 1 step + 1 step
    2. 2 steps
 *
 *
 * I: n = 3
 * O: 3
 * Explanation: There are three ways to climb to the top.
    1. 1 step + 1 step + 1 step
    2. 1 step + 2 steps
    3. 2 steps + 1 step
 */

int climbStairs(int n);

int main(int argc, char const *argv[]) {
    int n = 35;
    cout << climbStairs(n) << endl;
    return 0;
}

int climbStairs(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    int dp[n];
    dp[0] = 1;
    dp[1] = 2;
    for (int i = 2; i < n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n - 1];
}
