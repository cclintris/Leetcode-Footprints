#include <stdio.h>
#include <stdlib.h>

/**
 * I: nums = [3,2,2,3], val = 3
 * O: 2, nums = [2,2,_,_]

 * I: nums = [0,1,2,2,3,0,4,2], val = 2
 * O: 5, nums = [0,1,4,0,3,_,_,_]
 */

int removeElement(int* nums, int numsSize, int val) {
    int index = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[index++] = nums[i];
        }
    }

    return index;
}

int main(int argc, char const* argv[]) {
    int numsSize = 8;
    int nums[8] = {0, 1, 2, 2, 3, 0, 4, 2};
    int val = 2;
    printf("%d", removeElement(nums, numsSize, val));
    return 0;
}
