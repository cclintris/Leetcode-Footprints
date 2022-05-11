#include <stdio.h>
#include <stdlib.h>

/**
 * I: nums1 = [2], nums2 = [1, 3]
 * O: 2.00000
 */

void printArr(int* arr, int size) {
    printf("%d\n", size);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    if (nums1Size == 0 && nums2Size == 0) {
        return 0;
    }
    if (nums1Size == 0) {
        int m = nums2Size / 2;
        if (nums2Size % 2 == 0) {
            return (double)(nums2[m] + nums2[m - 1]) / 2;
        } else {
            return nums2[m];
        }
    }
    if (nums2Size == 0) {
        int m = nums1Size / 2;
        if (nums1Size % 2 == 0) {
            return (double)(nums1[m] + nums1[m - 1]) / 2;
        } else {
            return nums1[m];
        }
    }
    int p, q, r = 0;
    int size = nums1Size + nums2Size;
    int* arr = (int*)malloc(size * sizeof(int));
    while (p < nums1Size && q < nums2Size) {
        if (nums1[p] < nums2[q]) {
            arr[r] = nums1[p];
            p++;
        } else {
            arr[r] = nums2[q];
            q++;
        }
        r++;
    }

    if (p >= nums1Size) {
        for (int i = q; i < nums2Size; i++) {
            arr[r] = nums2[i];
            r++;
        }
    }
    if (q >= nums2Size) {
        for (int i = p; i < nums1Size; i++) {
            arr[r] = nums1[i];
            r++;
        }
    }

    int m = (size) / 2;
    if (size % 2 == 0) {
        return (double)(arr[m] + arr[m - 1]) / 2;
    } else {
        return arr[m];
    }
}

int main(int argc, char const* argv[]) {
    int arr1[] = {0, 0, 0, 0, 0};
    int arr2[] = {-1, 0, 0, 0, 0, 0, 1};
    int arr1Size = sizeof(arr1) / sizeof(arr1[0]);
    int arr2Size = sizeof(arr2) / sizeof(arr2[0]);
    double res = findMedianSortedArrays(arr1, arr1Size, arr2, arr2Size);
    printf("%f", res);
    return 0;
}
