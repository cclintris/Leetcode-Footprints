#include <stdio.h>
#include <stdlib.h>

/**
 * I: nums = [4,5,6,7,0,1,2], target = 0
 * O: 4

 * I: nums = [4,5,6,7,0,1,2], target = 3
 * O: -1
 *
 * I: nums = [1], target = 0
 * O: -1
 */

int search(int* nums, int numsSize, int target);

int main(int argc, char const* argv[]) {
    int numsSize = 7;
    int nums[7] = {4, 5, 6, 7, 0, 1, 2};
    int target = 3;
    printf("%d", search(nums, numsSize, target));
    return 0;
}

int search(int* nums, int numsSize, int target) {
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == target) {
            return i;
        }
    }
    return -1;
}
