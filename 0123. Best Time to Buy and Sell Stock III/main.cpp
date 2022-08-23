#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/**
 * I: prices = [3,3,5,0,0,3,1,4]
 * O: 6
 *
 * I: prices = [1,2,3,4,5]
 * O: 4
 *
 * I: prices = [7,6,4,3,1]
 * O: 0
 */

int maxProfit(vector<int>& prices);

int maxProfitWithinRange(vector<int>& prices, int start, int end);

int main(int argc, char const* argv[]) {
    vector<int> prices{3, 3, 5, 0, 0, 3, 1, 4};
    cout << maxProfit(prices) << endl;
    return 0;
}

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<int> dp1(n, 0);
    vector<int> dp2(n, 0);

    // dp1 -> profit if 1st sale happened on or before i
    int min_price = prices[0];
    for (int i = 1; i < n; i++) {
        int profit = prices[i] - min_price;
        dp1[i] = max(dp1[i], max(dp1[i - 1], profit));
        min_price = min(prices[i], min_price);
    }

    // dp2 -> profit if 2nd buy happened on or after i
    int max_price = prices[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        int profit = max_price - prices[i];
        dp2[i] = max(dp2[i], max(dp2[i + 1], profit));
        max_price = max(max_price, prices[i]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int profit = dp1[i];
        if (i + 1 < n)
            profit += dp2[i + 1];
        ans = max(ans, profit);
    }
    
    return ans;
}

// int maxProfit(vector<int>& prices) {
//     int n = prices.size();
//     int res = 0;
//     int oneTransaction = maxProfitWithinRange(prices, 0, n - 1);
//     if (oneTransaction == 0) return 0;
//     for (int i = 1; i < n - 1; i++) {
//         int first = maxProfitWithinRange(prices, 0, i);
//         int second = maxProfitWithinRange(prices, i + 1, n - 1);
//         int tmp = first + second;
//         if (tmp > res)
//             res = tmp;
//     }
//     res = oneTransaction > res ? oneTransaction : res;

//     return res;
// }

// int maxProfitWithinRange(vector<int>& prices, int start, int end) {
//     int l = start;
//     int r = l + 1;
//     int max = 0;
//     while (r <= end) {
//         if (prices[l] > prices[r]) {
//             l = r;
//             r = l + 1;
//         } else {
//             int tmp = prices[r] - prices[l];
//             if (tmp > max)
//                 max = tmp;
//             r++;
//         }
//     }

//     return max;
// }
