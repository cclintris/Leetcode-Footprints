#include <iostream>
#include <vector>
using namespace std;

/**
 * I: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
 * O: 6
 * Explanation: [1,1,1,0,0,1,1,1,1,1,1]
    Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
 *
 * I: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
 * O: 10
 * Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
    Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
 */

int longestOnes(vector<int>& nums, int k);

int main(int argc, char const* argv[]) {
    return 0;
}

int longestOnes(vector<int>& nums, int k) {
    int l = 0, cnt = 0, res = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0) cnt++;
        while (cnt > k) {
            if (nums[l] == 0) cnt--;
            l++;
        }
        res = max(res, i - l + 1);
    }
    return res;
}
