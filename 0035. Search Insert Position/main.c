#include <stdio.h>
#include <stdlib.h>

/**
 * I: nums = [1,3,5,6], target = 5
 * O: 2
 *
 * I: nums = [1,3,5,6], target = 2
 * O: 1
 *
 * I: nums = [1,3,5,6], target = 7
 * O: 4
 */

int searchInsert(int* nums, int numsSize, int target);

int main(int argc, char const* argv[]) {
    int numsSize = 4;
    int nums[4] = {1, 3, 5, 6};
    int target = 0;
    printf("%d", searchInsert(nums, numsSize, target));
    return 0;
}

int searchInsert(int* nums, int numsSize, int target) {
    if (target > nums[numsSize - 1]) return numsSize;
    if (target < nums[0]) return 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == target) {
            return i;
        } else {
            if (nums[i + 1] > target) {
                return i + 1;
            }
        }
    }
    return 0;
}
