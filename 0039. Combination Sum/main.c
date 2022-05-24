#include <stdio.h>
#include <stdlib.h>

/**
 * I: candidates = [2,3,6,7], target = 7
 * O: [[2,2,3],[7]]
 *
 * I: candidates = [2,3,5], target = 8
 * O: [[2,2,2,2],[2,3,3],[3,5]]
 *
 * I: candidates = [2], target = 1
 * O: []
 */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **combinationSum(int *candidates,
                     int candidatesSize,
                     int target,
                     int *returnSize,
                     int **returnColumnSizes);

void backtracking(int idx,
                  int *ls,
                  int ls_idx,
                  int total,
                  int target,
                  int *candidates,
                  int size,
                  int **res,
                  int **returnColumnSizes);

int main(int argc, char const *argv[]) {
    return 0;
}

int resIdx;

int **combinationSum(int *candidates,
                     int candidatesSize,
                     int target,
                     int *returnSize,
                     int **returnColumnSizes) {
    int **res = (int **)malloc(sizeof(int *) * 200);
    resIdx = 0;
    int ls[500] = {0};
    for (int i = 0; i < 200; i++) {
        res[i] = (int *)malloc(sizeof(int) * 500);
    }
    *returnColumnSizes = (int *)malloc(sizeof(int) * 200);
    backtracking(0, &ls[0], 0, target, target, candidates, candidatesSize, res, returnColumnSizes);
    *returnSize = resIdx;
    return &res[0];
}

void backtracking(
    int idx,
    int *ls,
    int ls_idx,
    int total,
    int target,
    int *candidates,
    int size,
    int **res,
    int **returnColumnSizes) {
    int i;

    if (total == 0) {
        memcpy(res[resIdx], &ls[0], sizeof(int) * (ls_idx + 1));
        returnColumnSizes[0][resIdx] = ls_idx;
        resIdx++;
        return;
    }
    if (total < 0)
        return;

    if (idx >= size)
        return;

    for (i = idx; i < size; i++) {
        ls[ls_idx] = candidates[i];
        backtracking(i,
                     ls,
                     ls_idx + 1,
                     total - candidates[i],
                     target,
                     candidates,
                     size,
                     res,
                     returnColumnSizes);
    }

    return;
}