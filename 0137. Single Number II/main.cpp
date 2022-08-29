#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/**
 * I: nums = [2,2,3,2]
 * O: 3
 *
 * I: nums = [0,1,0,1,0,1,99]
 * O: 99
 */

int singleNumber(vector<int>& nums);

int main(int argc, char const* argv[]) {
    vector<int> nums{0, 1, 0, 1, 0, 1, 99};
    cout << singleNumber(nums) << endl;
    return 0;
}

int singleNumber(vector<int>& nums) {
    int n = nums.size();
    if (n == 1 || n == 2 || n == 3) return nums[0];
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 3; i += 3) {
        if (nums[i] != nums[i + 1])
            return nums[i];
    }
    return nums[n - 1];
}

// // a more general version will be accepting x as parameter where
// // n is the frequency for which one element appears in the array
// // except for one
// int singleNumber(vector<int>& nums, int x) {
//     int n = nums.size();
//     for (int i = 1; i <= x; i++) {
//         if (n == i) return nums[0];
//     }
//     sort(nums.begin(), nums.end());
//     for (int i = 0; i < n - x; i += x) {
//         if (nums[i] != nums[i + 1])
//             return nums[i];
//     }
//     return nums[n - 1];
// }
