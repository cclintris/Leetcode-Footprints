#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * I: dividend = 10, divisor = 3
 * O: 3
 * Explanation: 10/3 = 3.33333.. which is truncated to 3.

 * I: dividend = 7, divisor = -3
 * O: -2
 * Explanation: 7/-3 = -2.33333.. which is truncated to -2.
 */

#define INT_MAX 2147483647
#define INT_MIN -2147483648

int divide(int dividend, int divisor) {
    // 当除数为1或者-1的时候有越界的可能，因此单独处理
    if (divisor == 1) {
        return dividend;
    }
    if (divisor == -1) {
        if (dividend <= INT_MIN) {
            return INT_MAX;
        }
        return -dividend;
    }

    // 当两者相等的时候就直接返回
    if (dividend == divisor) {
        return 1;
    }

    // 除数边界值特殊处理
    if (divisor == INT_MIN) {
        if (dividend == INT_MIN) {
            return 1;
        } else {
            return 0;
        }
    }

    int flag = 0;
    if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) {
        flag = 1;
    }
    long long absDivisor = divisor;
    long long num = dividend;
    int count = 0;
    if (divisor < 0) {
        absDivisor = 0 - (long long)divisor;
    }
    if (dividend < 0) {
        num = 0 - (long long)dividend;
    }
    while (num >= absDivisor) {
        int tempCount = 1;
        int tempDivisor = absDivisor;
        // 需指数级快速逼近，以避免执行超时
        while (tempDivisor < (num >> 1)) {  // 逼近至一半，同时避免溢出
            tempDivisor += tempDivisor;
            tempCount += tempCount;
        }
        count += tempCount;
        num -= tempDivisor;
    }
    if (flag) {
        count = -count;
    }
    return count;
}

int main(int argc, char const *argv[]) {
    int dividend = 10, divisor = 3;
    printf("%d", divide(dividend, divisor));
    return 0;
}
