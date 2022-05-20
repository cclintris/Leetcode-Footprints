#include <stdio.h>
#include <stdlib.h>

/**
 * I: nums = [5,7,7,8,8,10], target = 8
 * O: [3,4]
 *
 * I: nums = [5,7,7,8,8,10], target = 6
 * O: [-1,-1]
 *
 * I: nums = [], target = 0
 * O: [-1,-1]
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize);

void printIntList(int* arr, int size);

int main(int argc, char const* argv[]) {
    int numsSize = 3;
    int nums[3] = {2, 2, 3};
    int target = 3;
    int* returnSize = (int*)malloc(sizeof(int));
    int* ret = searchRange(nums, numsSize, target, returnSize);
    printIntList(ret, *returnSize);
    free(ret);
    free(returnSize);
    return 0;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int* ret = (int*)malloc(sizeof(int) * 2);
    ret[0] = -1;
    ret[1] = -1;
    *returnSize = 2;
    if (nums == NULL) return ret;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == target && ret[0] == -1) {
            ret[0] = i;
            if (i == numsSize - 1) {
                ret[1] = i;
                return ret;
            }
        } else {
            if (ret[0] != -1 && nums[i] == target) {
                ret[1] = i;
            } else if (ret[0] != -1 && nums[i] != target) {
                if (ret[1] == -1) {
                    ret[1] = ret[0];
                }
                return ret;
            } else {
                continue;
            }
        }
    }

    return ret;
}

void printIntList(int* arr, int size) {
    printf("[");
    int index = 0;
    while (size > 0) {
        if (size == 1) {
            printf("%d", arr[index]);
        } else {
            printf("%d,", arr[index]);
        }
        index++;
        size--;
    }
    printf("]\n");
}
