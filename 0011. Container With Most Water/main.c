#include <stdio.h>
#include <stdlib.h>

/**
 * I: height = [1,8,6,2,5,4,8,3,7]
 * O: 49
 */

int maxArea(int* height, int heightSize) {
    int l = 0;
    int r = heightSize - 1;
    int maxArea = 0;
    int tmpArea = 0;

    while (l != r) {
        int width = r - l;
        if (height[l] < height[r]) {
            tmpArea = height[l] * width;
            l++;
        } else {
            tmpArea = height[r] * width;
            r--;
        }
        if (tmpArea > maxArea) maxArea = tmpArea;
    }

    return maxArea;
}

int main(int argc, char const* argv[]) {
    int height[2] = {1, 1};
    int heightSize = 2;
    printf("%d", maxArea(height, heightSize));
    return 0;
}
