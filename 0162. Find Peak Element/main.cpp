#include <iostream>
#include <vector>
using namespace std;

/**
 * I: nums = [1,2,3,1]
 * O: 2
 * Explanation: 3 is a peak element and your function should return the index number 2.
 *
 * I: nums = [1,2,1,3,5,6,4]
 * O: 5
 * Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.
 */

int findPeakElement(vector<int>& nums);

int main(int argc, char const* argv[]) {
    vector<int> nums{2, 1};
    cout << findPeakElement(nums) << endl;
    return 0;
}

// Binary search O(logn)
int findPeakElement(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;
    while (l != r) {
        int m = (l + r) / 2;
        if (m == 0 && nums[m] > nums[m + 1]) return m;
        if (m == nums.size() - 1 && nums[m] > nums[m - 1]) return m;
        if (nums[m] > nums[m + 1] && nums[m] > nums[m - 1]) return m;
        if (nums[m + 1] > nums[m]) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return l;
}
