#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/**
 *  Input: nums = [23,2,4,6,7], k = 6
    Output: true
    Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.

    Input: nums = [23,2,6,4,7], k = 6
    Output: true
    Explanation: [23, 2, 6, 4, 7] is an continuous subarray of size 5 whose elements sum up to 42.
    42 is a multiple of 6 because 42 = 7 * 6 and 7 is an integer.

    Input: nums = [23,2,6,4,7], k = 13
    Output: false
*/

bool checkSubarraySum(vector<int>& nums, int k);

int main(int argc, char const* argv[]) {
    return 0;
}

bool checkSubarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> mp{{0, -1}};
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        int r = sum % k;
        if (mp.find(r) != mp.end()) {
            if (i - mp[r] > 1) return true;
        } else {
            mp[r] = i;
        }
    }
    return false;
}
