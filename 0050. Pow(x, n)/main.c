#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "../constant/integer.h"

/**
 * I: x = 2.00000, n = 10
 * O: 1024.00000
 *
 * I: x = 2.10000, n = 3
 * O: 9.26100
 *
 * I: x = 2.00000, n = -2
 * O: 0.25000
 */

double myPow(double x, int n);

int main(int argc, char const *argv[]) {
    double x = 2.00000;
    int n = 6;
    printf("%f\n", myPow(x, n));
    return 0;
}

// Best pow algorithm
double myPow(double x, int n) {
    double res = 1;
    while (n) {
        if (abs(n % 2) == 1) {
            res = (n > 0) ? res * x : res / x;
        }
        x *= x;
        n /= 2;
    }
    return res;
}
