#include <stdio.h>
#include <stdlib.h>

/**
 *
 * I: nums = [1,1,2]
 * O: 2, nums = [1,2,_]

 * I: nums = [0,0,1,1,1,2,2,3,3,4]
 * O: 5, nums = [0,1,2,3,4,_,_,_,_,_]
 */

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 1) return numsSize;
    int index = 1;
    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            continue;
        } else {
            nums[index++] = nums[i + 1];
        }
    }

    return index;
}

int main(int argc, char const* argv[]) {
    int nums[5] = {0, 1, 2, 3, 4};
    int numsSize = 5;
    printf("%d", removeDuplicates(nums, numsSize));
    return 0;
}
