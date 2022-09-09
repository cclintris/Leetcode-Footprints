#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/**
 * I: nums = [1,2,3,1]
 * O: 4
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
    Total amount you can rob = 1 + 3 = 4.
 *
 * I: nums = [2,7,9,3,1]
 * O: 12
 * Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
    Total amount you can rob = 2 + 9 + 1 = 12.
 */

int rob(vector<int>& nums);

int main(int argc, char const* argv[]) {
    vector<int> nums{2, 1, 1, 2};
    cout << rob(nums) << endl;
    return 0;
}

int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];
    vector<int> dp(n);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
    }
    return dp[n - 1];
}
