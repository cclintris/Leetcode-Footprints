#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/**
 * I: nums = [10,9,2,5,3,7,101,18]
 * O: 4
 *
 * I: nums = [0,1,0,3,2,3]
 * O: 4
 *
 * I: nums = [7,7,7,7,7,7,7]
 * O: 1
 */

int lengthOfLIS(vector<int>& nums);

int main(int argc, char const* argv[]) {
    return 0;
}

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);
    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}
