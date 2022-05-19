#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * I: nums = [1,2,3]
 * O: [1,3,2]

 * I: nums = [3,2,1]
 * O: [1,2,3]
 *
 * I: nums = [1,1,5]
 * O: [1,5,1]
 */

int cmp(const void* a, const void* b);

void swap(int* num1, int* num2);

void nextPermutation(int* nums, int numsSize);

void printIntList(int* arr, int size);

int main(int argc, char const* argv[]) {
    int numsSize = 6;
    int nums[6] = {2, 3, 0, 2, 4, 1};
    nextPermutation(nums, numsSize);
    printIntList(nums, numsSize);
    return 0;
}

int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

void swap(int* num1, int* num2) {
    int tmp = *num1;
    *num1 = *num2;
    *num2 = tmp;
}

// Applying the Single Pass Approach
// [1, 5, 8, 4, 7, 6, 5, 3, 1]
// [1, 5, 8, 5, 7, 6, 4, 3, 1]
// [1, 5, 8, 5, 1, 3, 4, 6, 7]
void nextPermutation(int* nums, int numsSize) {
    int right = numsSize - 1;
    int* target;
    int end = right, min;
    for (int i = right; i > 0; i--) {
        if (nums[i] > nums[i - 1]) {
            while (nums[end] <= nums[i - 1] && end >= i) {
                end--;
            }
            target = &nums[end];
            // printIntList(nums, numsSize);
            swap(&nums[i - 1], target);
            // printIntList(nums, numsSize);
            qsort(&nums[i], right - i + 1, sizeof(int), cmp);
            // printIntList(nums, numsSize);
            return;
        }
    }
    qsort(nums, numsSize, sizeof(int), cmp);
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
