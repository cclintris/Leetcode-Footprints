#include <stdio.h>
#include <stdlib.h>

#include "../utils/output/print.h"

/**
 * I: nums = [1,2,3]
 * O: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 *
 * I: nums = [0,1]
 * O: [[0,1],[1,0]]
 *
 * I: nums = [1]
 * O: [[1]]
 */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes);

void recursion(int* nums, int** ret, int pos, int numsSize, int* returnSize);

void swap(int* x, int* y);

int main(int argc, char const* argv[]) {
    int nums[4] = {1, 2, 3, 4};
    int numsSize = 4;
    int* returnSize = (int*)malloc(sizeof(int));
    int** returnColumnSize = (int**)malloc(sizeof(int*));
    int** ret = permute(nums, numsSize, returnSize, returnColumnSize);
    printInt2DList(ret, *returnSize, *returnColumnSize);
    return 0;
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if (numsSize == 0) return NULL;

    int count = 1;
    for (int i = 2; i <= numsSize; i++) {
        count *= i;
    }
    int** ret = (int**)malloc(sizeof(int*) * count);
    *returnColumnSizes = (int*)malloc(sizeof(int) * count);
    for (int i = 0; i < count; i++) {
        ret[i] = (int*)malloc(sizeof(int) * numsSize);
        (*returnColumnSizes)[i] = numsSize;
    }

    recursion(nums, ret, 0, numsSize, returnSize);
    return ret;
}

void recursion(int* nums, int** ret, int pos, int numsSize, int* returnSize) {
    if (pos == numsSize) {
        for (int i = 0; i < numsSize; i++) {
            ret[*returnSize][i] = nums[i];
        }
        (*returnSize)++;
        return;
    }

    for (int i = pos; i < numsSize; i++) {
        swap(nums + pos, nums + i);
        recursion(nums, ret, pos + 1, numsSize, returnSize);
        swap(nums + pos, nums + i);
    }
}

void swap(int* x, int* y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}
