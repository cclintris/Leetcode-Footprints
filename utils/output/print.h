#ifndef PRINT_H
#define PRINT_H

// [num1, num2, num3]
void printIntList(int* arr, int size);

// [[num1, num2...], [num1, num2...], ...]
void printInt2DList(int** arr, int rowSize, int* colSize);

// [[c1, c2, ...], [c1, c2, ...], ...]
void printChar2DList(char** arr, int row, int col);

void printString2DList(char*** arr, int rowSize, int* colSize);

#endif
