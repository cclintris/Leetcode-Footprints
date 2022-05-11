#include <stdio.h>
#include <stdlib.h>

/**
 *
 * I: nums = [1,0,-1,0,-2,2], target = 0
 * O: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

 * I: nums = [2,2,2,2,2], target = 8
 * O: [[2,2,2,2]]
 */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#define MALLOC_UNIT 5000

int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    if (numsSize < 4) {
        *returnSize = 0;
        return NULL;
    }
    qsort(nums, numsSize, sizeof(int), cmp);
    int ret_Sz = 0;
    int count = MALLOC_UNIT;
    int** ret = (int**)malloc(sizeof(int*) * count);
    *returnColumnSizes = malloc(sizeof(int) * count);
    int l, r, index, flag;
    for (int i = 0; i < numsSize - 3; i++) {
        for (int j = i + 1; j < numsSize - 2; j++) {
            l = j + 1;
            r = numsSize - 1;
            int tmp = nums[i] + nums[j];
            while (l != r) {
                int remain = target - tmp;
                int sum = nums[l] + nums[r];
                if (sum < remain) {
                    l++;
                } else if (sum > remain) {
                    r--;
                } else {
                    flag = 0;
                    for (int k = 0; k < ret_Sz; k++) {
                        if (ret[k][0] == nums[i] &&
                            ret[k][1] == nums[j] &&
                            ret[k][2] == nums[l] &&
                            ret[k][3] == nums[r]) {
                            flag = 1;
                        }
                    }
                    if (!flag) {
                        ret_Sz++;
                        if (ret_Sz == count) {
                            ret = realloc(ret, sizeof(int*) * count);
                            *returnColumnSizes = realloc(*returnColumnSizes, sizeof(int) * count);
                        }
                        index = ret_Sz - 1;
                        ret[index] = malloc(sizeof(int) * 4);
                        ret[index][0] = nums[i];
                        ret[index][1] = nums[j];
                        ret[index][2] = nums[l];
                        ret[index][3] = nums[r];
                        (*returnColumnSizes)[index] = 4;
                    }
                    l++;
                }
            }
        }
    }
    *returnSize = ret_Sz;
    return ret;
}

void print4SumArrUnit(int* arr) {
    printf("[%d, %d, %d, %d]", arr[0], arr[1], arr[2], arr[3]);
}

void printTwoDimensionArr(int** arr, int size) {
    printf("[");
    if (size != 0) {
        for (int i = 0; i < size; i++) {
            if (i == size - 1) {
                print4SumArrUnit(arr[i]);
            } else {
                print4SumArrUnit(arr[i]);
                printf(",");
            }
        }
    }
    printf("]\n");
}

int main(int argc, char const* argv[]) {
    int nums[8] = {-3, -2, -1, 0, 0, 1, 2, 3};
    int numSize = 8;
    int target = 0;
    int* returnSize = (int*)malloc(sizeof(int));
    int** returnColumnSizes = (int**)malloc(sizeof(int*));
    int** res = fourSum(nums, numSize, target, returnSize, returnColumnSizes);
    printTwoDimensionArr(res, *returnSize);
    free(res);
    free(returnColumnSizes);
    free(returnSize);
    return 0;
}
