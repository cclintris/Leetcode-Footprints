#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/**
 * I: target = 7, nums = [2,3,1,2,4,3]
 * O: 2
 * Explanation: The subarray [4,3] has the minimal length under the problem constraint.
 *
 * I: target = 4, nums = [1,4,4]
 * O: 1
 *
 * I: target = 11, nums = [1,1,1,1,1,1,1,1]
 * O: 0
 */

int minSubArrayLen(int target, vector<int>& nums);

int main(int argc, char const* argv[]) {
    int target = 6;
    vector<int> nums{10, 2, 3};
    cout << minSubArrayLen(target, nums) << endl;
    return 0;
}

// Sliding Window
int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    if (n == 1) {
        if (nums[0] < target)
            return 0;
        else
            return 1;
    }
    int l = 0, r = l + 1;
    int res = INT_MAX;
    int sum = nums[l] + nums[r];
    while (l < r && r < n) {
        if (nums[l] >= target || nums[r >= target]) return 1;
        if (sum < target) {
            r++;
            if (r < n) sum += nums[r];
        } else {
            while (sum >= target) {
                sum -= nums[l];
                l++;
            }
            int dist = r - l + 2;
            res = min(res, dist);
        }
    }
    return res == INT_MAX ? 0 : res;
}
