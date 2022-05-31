#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "../utils/output/print.h"

/**
 * I: nums = [1,2,3]
 * O: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 *
 * I: nums = [1,1,2]
 * O: [[1,1,2],
 *     [1,2,1],
 *     [2,1,1]]
 *
 */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes);

void recursion(int* nums, int** ret, int start, int end, int* returnSize);

void swap(int* x, int* y);

bool needSwap(int* nums, int start, int end);

int main(int argc, char const* argv[]) {
    int nums[3] = {1, 1, 2};
    int numsSize = 3;
    int* returnSize = (int*)malloc(sizeof(int));
    int** returnColumnSize = (int**)malloc(sizeof(int*));
    int** ret = permuteUnique(nums, numsSize, returnSize, returnColumnSize);
    printInt2DList(ret, *returnSize, *returnColumnSize);
    return 0;
}

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
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

void recursion(int* nums, int** ret, int start, int end, int* returnSize) {
    if (start == end) {
        for (int i = 0; i < end; i++) {
            ret[*returnSize][i] = nums[i];
        }
        (*returnSize)++;
        return;
    }

    for (int i = start; i < end; i++) {
        if (!needSwap(nums, start, i))
            continue;
        swap(nums + start, nums + i);
        recursion(nums, ret, start + 1, end, returnSize);
        swap(nums + start, nums + i);
    }
}

void swap(int* x, int* y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

bool needSwap(int* nums, int start, int end) {
    for (int i = start; i < end; i++) {
        if (nums[i] == nums[end])
            return false;
    }
    return true;
}
