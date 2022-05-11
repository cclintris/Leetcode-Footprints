#include <stdio.h>
#include <stdlib.h>

/**
 *
 * I: nums = [-1,0,1,2,-1,-4]
 * O: [[-1,-1,2],[-1,0,1]]

 * I: nums = []
 * O: []
 *
 * I: nums = [0]
 * O: []
 */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

static int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

#define MALLOC_UNIT 5000

int **threeSum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes) {
    *returnSize = 0;
    if (numsSize < 3) return NULL;

    qsort(nums, numsSize, sizeof(int), compare);
    int count = MALLOC_UNIT, ret_sz = 0;
    int **ret = (int **)malloc(sizeof(int *) * count);
    *returnColumnSizes = malloc(sizeof(int) * count);
    for (int i = 0; i < numsSize - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int target = (-1) * (nums[i]), left = i + 1, right = numsSize - 1;
        while (left < right) {
            if (left > i + 1 && nums[left - 1] == nums[left]) {
                left++;
                continue;
            }

            if (nums[left] + nums[right] == target) {
                ret_sz++;
                if (ret_sz == count) {
                    count <<= 1;
                    ret = realloc(ret, sizeof(int *) * count);
                    *returnColumnSizes = realloc(*returnColumnSizes, sizeof(int) * count);
                }
                ret[ret_sz - 1] = malloc(sizeof(int) * 3);
                ret[ret_sz - 1][0] = nums[i];
                ret[ret_sz - 1][1] = nums[left];
                ret[ret_sz - 1][2] = nums[right];
                (*returnColumnSizes)[ret_sz - 1] = 3;
                left++;
            } else if (nums[left] + nums[right] < target) {
                left++;
            } else {
                right--;
            }
        }
    }
    *returnSize = ret_sz;
    return ret;
}

void print3SumArrUnit(int *arr) {
    printf("[%d, %d, %d]", arr[0], arr[1], arr[2]);
}

void printTwoDimensionArr(int **arr, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        if (i == size - 1) {
            print3SumArrUnit(arr[i]);
        } else {
            print3SumArrUnit(arr[i]);
            printf(",");
        }
    }
    printf("]");
}

int main(int argc, char const *argv[]) {
    int nums[6] = {-1, 0, 1, 2, -1, 4};
    int numSize = 6;
    int *returnSize = (int *)malloc(sizeof(int));
    int **returnColumnSize = (int **)malloc(sizeof(int *));
    int **res = threeSum(nums, numSize, returnSize, returnColumnSize);
    printTwoDimensionArr(res, *returnSize);
    free(returnSize);
    free(returnColumnSize);
    free(res);
    return 0;
}
