#include <stdio.h>
#include <stdlib.h>

/**
 * I: nums = [1,2,0]
 * O: 3
 *
 * I: nums = [3,4,-1,1]
 * O: 2
 *
 * I: nums = [7,8,9,11,12]
 * O: 1
 */

int firstMissingPositive(int* nums, int numsSize);

int cmp(const void* a, const void* b);

int main(int argc, char const* argv[]) {
    int nums[9] = {2147483647, 2147483646, 2147483645, 3, 2, 1, -1, 0, -2147483648};
    int numsSize = 9;
    printf("%d\n", firstMissingPositive(nums, numsSize));
    return 0;
}

int cmp(const void* a, const void* b) {
    int va = *(const int*)a;
    int vb = *(const int*)b;
    return (va > vb) - (va < vb);
}

int firstMissingPositive(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);

    int firstPos = 1;
    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            continue;
        } else {
            if (nums[i] > 0) {
                if (nums[i] - firstPos != 0)
                    return firstPos;
                else
                    firstPos++;
            }
        }
    }

    if (nums[numsSize - 1] == firstPos) return firstPos + 1;

    return firstPos;
}
