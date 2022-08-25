#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/**
 * I: nums = [100,4,200,1,3,2]
 * O: 4
 * Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
 *
 * I: nums = [0,3,7,2,5,8,4,6,0,1]
 * O: 9
 */

int longestConsecutive(vector<int>& nums);

int main(int argc, char const* argv[]) {
    vector<int> nums{1, 2, 0, 1};
    cout << longestConsecutive(nums) << endl;
    return 0;
}

int longestConsecutive(vector<int>& nums) {
    int tmp = 1, n = nums.size();
    if (n == 0) return 0;
    int res = 0;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 1; i++) {
        if (nums[i + 1] - nums[i] == 1) {
            tmp++;
        } else if (nums[i + 1] - nums[i] == 0) {
            continue;
        } else {
            res = max(tmp, res);
            tmp = 1;
        }
    }
    res = max(tmp, res);
    return res;
}
