#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/**
 * I: nums = [2,2,1]
 * O: 1
 *
 * I: nums = [4,1,2,1,2]
 * O: 4
 *
 * I: nums = [1]
 * O: 1
 */

int singleNumber(vector<int>& nums);

int main(int argc, char const* argv[]) {
    vector<int> nums{4, 1, 2, 1, 2};
    cout << singleNumber(nums) << endl;
    return 0;
}

int singleNumber(vector<int>& nums) {
    int n = nums.size();
    if (n == 1 || n == 2) return nums[0];
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 2; i += 2) {
        if (nums[i] != nums[i + 1])
            return nums[i];
    }
    return nums[n - 1];
}
