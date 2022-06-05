#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/**
 * I: nums = [-2,1,-3,4,-1,2,1,-5,4]
 * O: 6
 *
 * I: nums = [1]
 * O: 1
 *
 * I: nums = [5,4,-1,7,8]
 * O: 23
 */

int maxSubArray(vector<int> &nums);

int main(int argc, char const *argv[]) {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> nums;
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
        nums.push_back(arr[i]);
    }
    int res = maxSubArray(nums);
    cout << res << endl;
    return 0;
}

int maxSubArray(vector<int> &nums) {
    int res = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i - 1] > 0)
            nums[i] += nums[i - 1];
        res = max(res, nums[i]);
    }
    return res;
}
