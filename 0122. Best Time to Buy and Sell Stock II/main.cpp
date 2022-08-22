#include <iostream>
#include <vector>
using namespace std;

/**
 * I: prices = [7,1,5,3,6,4]
 * O: 7
 *
 * I: prices = [1,2,3,4,5]
 * O: 4
 *
 * I: prices = [7,6,4,3,1]
 * O: 0
 */

int maxProfit(vector<int>& prices);

int main(int argc, char const* argv[]) {
    vector<int> prices{1, 4};
    cout << maxProfit(prices) << endl;
    return 0;
}

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<int> dp(n, 0);
    for (int i = 0; i < n - 1; i++) {
        if (prices[i] < prices[i + 1]) {
            dp[i + 1] = dp[i] + (prices[i + 1] - prices[i]);
        } else {
            dp[i + 1] = dp[i];
        }
    }

    return dp[n - 1];
}
