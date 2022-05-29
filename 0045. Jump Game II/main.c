#include <stdio.h>
#include <stdlib.h>

/**
 * I: nums = [2,3,1,1,4]
 * O: 2
 * Explanation: The minimum number of jumps to reach the last index is 2.
 * Jump 1 step from index 0 to 1, then 3 steps to the last index.
 *
 * I: nums = [2,3,0,1,4]
 * O: 2
 */

int jump(int* nums, int numsSize);

int main(int argc, char const* argv[]) {
    int nums[5] = {2, 3, 0, 1, 4};
    int numsSize = 5;
    printf("%d\n", jump(nums, numsSize));
    return 0;
}

int jump(int* nums, int numsSize) {
    int count = 0;
    int l = 0, r = 0;  // window grouping
    while (r < numsSize - 1) {
        int farthest = l + nums[l];
        for (int i = l + 1; i <= r; i++) {
            int tmp = i + nums[i];
            if (tmp > farthest)
                farthest = tmp;
        }
        l = r + 1;
        r = farthest;
        count += 1;
    }

    return count;
}
