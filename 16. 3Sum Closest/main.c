#include <stdio.h>
#include <stdlib.h>

/**
 *
 * I: nums = [-1,2,1,-4], target = 1
 * O: 2

 * I: nums = [0,0,0], target = 1
 * O: 0
 */

#define MAX_INT 2147483647

int diff(int a, int b) {
    return a <= b ? b - a : a - b;
}

int threeSumClosest(int* nums, int numsSize, int target) {
    int ret;
    int dist = MAX_INT;
    for (int i = 0; i < numsSize - 2; i++) {
        for (int j = i + 1; j < numsSize - 1; j++) {
            for (int k = j + 1; k < numsSize; k++) {
                int tmp = nums[i] + nums[j] + nums[k];
                if (diff(tmp, target) < dist) {
                    dist = diff(tmp, target);
                    ret = tmp;
                }
            }
        }
    }

    return ret;
}

int main(int argc, char const* argv[]) {
    int nums[8] = {1, 2, 4, 8, 16, 32, 64, 128};
    int numSize = 8;
    int target = 82;
    printf("%d", threeSumClosest(nums, numSize, target));
    return 0;
}
