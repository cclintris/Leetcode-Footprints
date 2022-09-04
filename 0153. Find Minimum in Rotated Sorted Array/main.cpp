#include <iostream>
#include <vector>
using namespace std;

/**
 * I: nums = [3,4,5,1,2]
 * O: 1
 * Explanation: The original array was [1,2,3,4,5] rotated 3 times.
 *
 * I: Input: nums = [4,5,6,7,0,1,2]
 * O: 0
 * Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.
 *
 * I: Input: nums = [11,13,15,17]
 * O: 11
 * Explanation: The original array was [11,13,15,17] and it was rotated 4 times.
 */

int findMin(vector<int>& nums);

int main(int argc, char const* argv[]) {
    return 0;
}

// Brute force is easy, but takes O(n)
// Intuitively, when hinted with O(logn), think of Binary Search
int findMin(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int mid = (left + right) / 2;
        if (nums[mid] > nums[right])
            left = mid + 1;
        else
            right = mid;
    }
    return nums[right];
}
