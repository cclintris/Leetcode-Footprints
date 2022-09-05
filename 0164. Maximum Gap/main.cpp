#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/**
 * I: nums = [3,6,9,1]
 * O: 3
 * Explanation:
 * The sorted form of the array is [1,3,6,9], either (3,6) or (6,9) has the maximum difference 3.
 *
 * I: nums = [10]
 * O: 0
 * Explanation: The array contains less than 2 elements, therefore return 0.
 */

int maximumGap(vector<int>& nums);

int main(int argc, char const* argv[]) {
    vector<int> nums{3, 6, 9, 1};
    cout << maximumGap(nums) << endl;
    return 0;
}

int maximumGap(vector<int>& nums) {
    if (nums.size() < 2) return 0;
    sort(nums.begin(), nums.end());
    int res = INT_MIN;
    for (int i = 0; i < nums.size() - 1; i++) {
        res = max(res, nums[i + 1] - nums[i]);
    }
    return res;
}
