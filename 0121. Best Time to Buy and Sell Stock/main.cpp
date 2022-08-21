#include <iostream>
#include <vector>
using namespace std;

/**
 * I: prices = [7,1,5,3,6,4]
 * O: 5
 *
 * I: prices = [7,6,4,3,1]
 * O: 0
 */

int maxProfit(vector<int>& prices);

int main(int argc, char const* argv[]) {
    vector<int> prices{1, 2};
    cout << maxProfit(prices) << endl;
    return 0;
}

int maxProfit(vector<int>& prices) {
    int m = prices.size();
    int l = 0, r = 1;
    int max = 0;
    while (r <= m - 1) {
        if (prices[l] > prices[r]) {
            l = r;
            r = l + 1;
        } else {
            int tmp = prices[r] - prices[l];
            if (tmp > max)
                max = tmp;
            r++;
        }
    }

    return max;
}
