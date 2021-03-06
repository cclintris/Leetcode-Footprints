#include <stdio.h>
#include <stdlib.h>

int comp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

void input(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes,
           int* box, int total, int now, int count, int** ans) {
    if (now >= candidatesSize) {
        return;
    }
    for (int i = now; i < candidatesSize; i++) {
        if (i > now) {
            while (i < candidatesSize && candidates[i] == candidates[i - 1]) {
                i++;
            }
            if (i == candidatesSize) {
                return;
            }
        }
        int add = total + candidates[i];
        if (add > target) {
            return;
        } else if (add < target) {
            box[count] = candidates[i];
            input(candidates, candidatesSize, target, returnSize, returnColumnSizes,
                  box, add, i + 1, count + 1, ans);
        } else {
            box[count] = candidates[i];
            ans[*returnSize] = malloc(sizeof(int) * (count + 1));
            for (int j = 0; j <= count; j++) {
                ans[*returnSize][j] = box[j];
            }
            (*returnColumnSizes)[*returnSize] = count + 1;
            *returnSize += 1;
            return;
        }
    }
}

int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    qsort(candidates, candidatesSize, sizeof(int), comp);
    int box[100];
    int** ans = malloc(sizeof(int*) * 100);
    *returnSize = 0;
    (*returnColumnSizes) = malloc(sizeof(int) * 100);
    input(candidates, candidatesSize, target, returnSize, returnColumnSizes, box, 0, 0, 0, ans);
    return ans;
}

int main(int argc, char const* argv[]) {
    return 0;
}