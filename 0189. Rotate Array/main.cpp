#include <iostream>
#include <vector>
using namespace std;

/**
 * I: nums = [1,2,3,4,5,6,7], k = 3
 * O: [5,6,7,1,2,3,4]
 *
 * I: nums = [-1,-100,3,99], k = 2
 * O: Output: [3,99,-1,-100]
 */

void rotate(vector<int>& nums, int k);

void printVec(vector<int>& vec);

int main(int argc, char const* argv[]) {
    vector<int> nums{1, 2};
    int k = 3;
    rotate(nums, k);
    printVec(nums);
    return 0;
}

// TLE
// void rotate(vector<int>& nums, int k) {
//     int s = nums.size();
//     while (k > 0) {
//         for (int i = s - 1; i >= 1; i--) {
//             int tmp = nums[i - 1];
//             nums[i - 1] = nums[i];
//             nums[i] = tmp;
//         }
//         k--;
//     }
// }

void rotate(vector<int>& nums, int k) {
    int s = nums.size();
    while (k > s) {
        k -= s;
    }
    reverse(nums.end() - k, nums.end());
    reverse(nums.begin(), nums.begin() + s - k);
    reverse(nums.begin(), nums.end());
}

void printVec(vector<int>& vec) {
    int len = vec.size();
    cout << "[";
    for (int i = 0; i < len; i++) {
        if (i == len - 1)
            cout << vec[i];
        else
            cout << vec[i] << ',';
    }
    cout << "]\n";
}
