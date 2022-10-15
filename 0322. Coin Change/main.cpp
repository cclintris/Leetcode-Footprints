#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/**
 * I: coins = [1,2,5], amount = 11
 * O: 3
 *
 * I: coins = [2], amount = 3
 * O: -1
 *
 * I: coins = [1], amount = 0
 * O: 0
 */

int coinChange(vector<int>& coins, int amount);

int dfs(vector<int>& coins, int rem, vector<int>& dp);

int main(int argc, char const* argv[]) {
    vector<int> coins{2};
    int amount = 3;
    cout << coinChange(coins, amount) << endl;
    return 0;
}

int coinChange(vector<int>& coins, int amount) {
    if (amount == 0) return 0;
    vector<int> dp(amount);
    return dfs(coins, amount, dp);
}

int dfs(vector<int>& coins, int rem, vector<int>& dp) {
    if (rem < 0) return -1;
    if (rem == 0) return 0;
    if (dp[rem - 1] != 0) return dp[rem - 1];
    int res = INT_MAX;
    for (int i = 0; i < coins.size(); i++) {
        int tmp = dfs(coins, rem - coins[i], dp);
        if (tmp >= 0 && tmp < res) {
            res = min(res, tmp + 1);
        }
    }
    dp[rem - 1] = res == INT_MAX ? -1 : res;
    return dp[rem - 1];
}
