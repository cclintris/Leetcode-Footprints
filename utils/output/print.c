#include "print.h"

#include <stdio.h>
#include <stdlib.h>

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

void printChar2DList(char** arr, int row, int col) {
    printf("[\n");
    for (int i = 0; i < row; i++) {
        printf("[");
        for (int j = 0; j < col; j++) {
            if (i == row - 1 && j == col - 1)
                printf("%c]\n", arr[i][j]);
            else if (j == col - 1)
                printf("%c],\n", arr[i][j]);
            else
                printf("%c,", arr[i][j]);
        }
    }
    printf("]\n");
}
