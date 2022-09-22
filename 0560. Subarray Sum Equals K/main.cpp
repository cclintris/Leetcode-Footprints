#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/**
 * I: nums = [1,1,1], k = 2
 * O: 2
 *
 * I: nums = [1,2,3], k = 3
 * O: 2
 */

int subarraySum(vector<int>& nums, int k);

int main(int argc, char const* argv[]) {
    vector<int> nums{-1, -1, 1};
    int k = 0;
    cout << subarraySum(nums, k) << endl;
    return 0;
}

int subarraySum(vector<int>& nums, int k) {
    int res = 0, sum = 0, n = nums.size();
    unordered_map<int, int> m{{0, 1}};
    for (int i = 0; i < n; ++i) {
        sum += nums[i];
        res += m[sum - k];
        ++m[sum];
    }
    return res;
}
