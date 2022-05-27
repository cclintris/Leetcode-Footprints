#include <stdio.h>
#include <stdlib.h>

#include "../utils/output/print.h"

/**
 * I: height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * O: 6
 * Explanation:
 * The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
 * In this case, 6 units of rain water (blue section) are being trapped.
 *
 * I: height = [4,2,0,3,2,5]
 * O: 9
 */

int trap(int* height, int heightSize);

// int getMax(int block, int* height, int start, int end);

int main(int argc, char const* argv[]) {
    int height[6] = {4, 2, 0, 3, 2, 5};
    int heightSize = 6;
    printf("%d\n", trap(height, heightSize));
    return 0;
}

// Dynamic programming
int trap(int* height, int heightSize) {
    int leftMax[heightSize], rightMax[heightSize];
    int vol = 0;

    leftMax[0] = height[0];
    for (int i = 1; i < heightSize; i++) {
        int max = height[i] > leftMax[i - 1] ? height[i] : leftMax[i - 1];
        leftMax[i] = max;
    }
    // printIntList(leftMax, heightSize);
    rightMax[heightSize - 1] = height[heightSize - 1];
    for (int i = heightSize - 2; i >= 0; i--) {
        int max = height[i] > rightMax[i + 1] ? height[i] : rightMax[i + 1];
        rightMax[i] = max;
    }
    // printIntList(rightMax, heightSize);

    for (int i = 1; i < heightSize - 1; i++) {
        int min = leftMax[i] < rightMax[i] ? leftMax[i] : rightMax[i];
        vol += abs(height[i] - min);
    }

    return vol;
}

// Brute force TLE
// int trap(int* height, int heightSize) {
//     int vol = 0;
//     for (int i = 0; i < heightSize; i++) {
//         int leftMax = getMax(height[i], height, 0, i);
//         int rightMax = getMax(height[i], height, i, heightSize - 1);

//         if (leftMax > height[i] && rightMax > height[i]) {
//             int min = leftMax < rightMax ? leftMax : rightMax;
//             vol += (min - height[i]);
//         }
//     }

//     return vol;
// }

// int getMax(int block, int* height, int start, int end) {
//     int max = block;
//     for (int i = start; i <= end; i++) {
//         if (height[i] > max) {
//             max = height[i];
//         }
//     }
//     return max;
// }
