#include <stdio.h>
#include <stdlib.h>

#include "../utils/output/print.h"

/**
 * I: matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * O: [[7,4,1],[8,5,2],[9,6,3]]
 *
 * I: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
 * O: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
 */

// Algorithm: First transpose, then reverse it by column
void rotate(int** matrix, int matrixSize, int* matrixColSize);

void transpose(int** matrix, int matrixSize, int* matrixColSize);

void swap(int* addr1, int* addr2);

void reverse(int** matrix, int matrixSize, int* matrixColSize);

int main(int argc, char const* argv[]) {
    int matrixSize = 4;
    int* matrixColSize = (int*)malloc(sizeof(int) * matrixSize);
    matrixColSize[0] = 4;
    matrixColSize[1] = 4;
    matrixColSize[2] = 4;
    matrixColSize[3] = 4;
    int** matrix = (int**)malloc(sizeof(int*) * matrixSize);
    matrix[0] = (int*)malloc(sizeof(int) * (*matrixColSize));
    matrix[0][0] = 5;
    matrix[0][1] = 1;
    matrix[0][2] = 9;
    matrix[0][3] = 11;
    matrix[1] = (int*)malloc(sizeof(int) * (*matrixColSize));
    matrix[1][0] = 2;
    matrix[1][1] = 4;
    matrix[1][2] = 8;
    matrix[1][3] = 10;
    matrix[2] = (int*)malloc(sizeof(int) * (*matrixColSize));
    matrix[2][0] = 13;
    matrix[2][1] = 3;
    matrix[2][2] = 6;
    matrix[2][3] = 7;
    matrix[3] = (int*)malloc(sizeof(int) * (*matrixColSize));
    matrix[3][0] = 15;
    matrix[3][1] = 14;
    matrix[3][2] = 12;
    matrix[3][3] = 16;
    rotate(matrix, matrixSize, matrixColSize);
    printInt2DList(matrix, matrixSize, matrixColSize);
    return 0;
}

void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    transpose(matrix, matrixSize, matrixColSize);
    reverse(matrix, matrixSize, matrixColSize);
}

void transpose(int** matrix, int matrixSize, int* matrixColSize) {
    for (int i = 0; i < matrixSize; i++) {
        for (int j = i; j < *matrixColSize; j++) {
            swap(matrix[i] + j, matrix[j] + i);
        }
    }
}

void swap(int* addr1, int* addr2) {
    int tmp = *addr1;
    *addr1 = *addr2;
    *addr2 = tmp;
}

void reverse(int** matrix, int matrixSize, int* matrixColSize) {
    for (int i = 0; i < matrixSize / 2; i++) {
        for (int j = 0; j < *matrixColSize; j++) {
            swap(matrix[j] + i, matrix[j] + matrixSize - 1 - i);
        }
    }
}
