#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/**
 * I: nums = [2,3,-2,4]
 * O: 6
 * Explanation: [2,3] has the largest product 6.

 *
 * I: Input: nums = [-2,0,-1]
 * O: 0
 * Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 */

int maxProduct(vector<int>& nums);

int main(int argc, char const* argv[]) {
    return 0;
}

int maxProduct(vector<int>& nums) {
    int res = nums[0], minn = nums[0], maxx = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        int temp = maxx;
        maxx = max({maxx * nums[i], minn * nums[i], nums[i]});
        minn = min({temp * nums[i], minn * nums[i], nums[i]});
        res = max(res, maxx);
    }
    return res;
}
