#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "../utils/output/print.h"

/**
 * I:
 * O:
 */

void solveSudoku(char** board, int boardSize, int* boardColSize);

bool backtrack(char** board, int size);

bool validNumPlace(char** board, int size, int row, int col, char c);

bool isNumInRow(char** board, int size, int row, char c);

bool isNumInCol(char** board, int size, int col, char c);

bool isNumInBox(char** board, int row, int col, char c);

int main(int argc, char const* argv[]) {
    int boardSize = 9;
    int* boardColSize = (int*)malloc(sizeof(int));
    *boardColSize = 9;
    char** board = (char**)malloc(sizeof(char*) * 9);
    board[0] = (char*)malloc(sizeof(char) * 9);
    board[0][0] = '5';
    board[0][1] = '3';
    board[0][2] = '.';
    board[0][3] = '.';
    board[0][4] = '7';
    board[0][5] = '.';
    board[0][6] = '.';
    board[0][7] = '.';
    board[0][8] = '.';

    board[1] = (char*)malloc(sizeof(char*) * 9);
    board[1][0] = '6';
    board[1][1] = '.';
    board[1][2] = '.';
    board[1][3] = '1';
    board[1][4] = '9';
    board[1][5] = '5';
    board[1][6] = '.';
    board[1][7] = '.';
    board[1][8] = '.';

    board[2] = (char*)malloc(sizeof(char*) * 9);
    board[2][0] = '.';
    board[2][1] = '9';
    board[2][2] = '8';
    board[2][3] = '.';
    board[2][4] = '.';
    board[2][5] = '.';
    board[2][6] = '.';
    board[2][7] = '6';
    board[2][8] = '.';

    board[3] = (char*)malloc(sizeof(char*) * 9);
    board[3][0] = '8';
    board[3][1] = '.';
    board[3][2] = '.';
    board[3][3] = '.';
    board[3][4] = '6';
    board[3][5] = '.';
    board[3][6] = '.';
    board[3][7] = '.';
    board[3][8] = '3';

    board[4] = (char*)malloc(sizeof(char*) * 9);
    board[4][0] = '4';
    board[4][1] = '.';
    board[4][2] = '.';
    board[4][3] = '8';
    board[4][4] = '.';
    board[4][5] = '3';
    board[4][6] = '.';
    board[4][7] = '.';
    board[4][8] = '1';

    board[5] = (char*)malloc(sizeof(char*) * 9);
    board[5][0] = '7';
    board[5][1] = '.';
    board[5][2] = '.';
    board[5][3] = '.';
    board[5][4] = '2';
    board[5][5] = '.';
    board[5][6] = '.';
    board[5][7] = '.';
    board[5][8] = '6';

    board[6] = (char*)malloc(sizeof(char*) * 9);
    board[6][0] = '.';
    board[6][1] = '6';
    board[6][2] = '.';
    board[6][3] = '.';
    board[6][4] = '.';
    board[6][5] = '.';
    board[6][6] = '2';
    board[6][7] = '8';
    board[6][8] = '.';

    board[7] = (char*)malloc(sizeof(char*) * 9);
    board[7][0] = '.';
    board[7][1] = '.';
    board[7][2] = '.';
    board[7][3] = '4';
    board[7][4] = '1';
    board[7][5] = '9';
    board[7][6] = '.';
    board[7][7] = '.';
    board[7][8] = '5';

    board[8] = (char*)malloc(sizeof(char*) * 9);
    board[8][0] = '.';
    board[8][1] = '.';
    board[8][2] = '.';
    board[8][3] = '.';
    board[8][4] = '8';
    board[8][5] = '.';
    board[8][6] = '.';
    board[8][7] = '7';
    board[8][8] = '9';

    solveSudoku(board, boardSize, boardColSize);
    printChar2DList(board, 9, 9);
    return 0;
}

void solveSudoku(char** board, int boardSize, int* boardColSize) {
    backtrack(board, boardSize);
}

/**
 * Backtracking Algorithm:
 * With the given state of the board, traverse it row by row.
 * If the current cell is '.' (not digit) check all numbers from 1-9 and
 * check whether each of them is valid by adding in that cell. We do the same for
 * other cells same way. If at any point we find either row or col or sub-box
 * violates the rules, then, we backtrack to previous cells and try placing
 * different number.
 * Repeat this process over and over again until it fills out all '.' cells in
 * grid with valid numbers.
 */
bool backtrack(char** board, int size) {
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            if (board[row][col] == '.') {
                for (char try = '1'; try <= '9'; try++) {
                    if (validNumPlace(board, size, row, col, try)) {
                        board[row][col] = try;

                        if (backtrack(board, size))
                            return true;
                        else
                            board[row][col] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

bool validNumPlace(char** board, int size, int row, int col, char c) {
    return !isNumInRow(board, size, row, c) &&
           !isNumInCol(board, size, col, c) &&
           !isNumInBox(board, row, col, c);
}

bool isNumInRow(char** board, int size, int row, char c) {
    for (int i = 0; i < size; i++) {
        if (board[row][i] == c)
            return true;
    }
    return false;
}

bool isNumInCol(char** board, int size, int col, char c) {
    for (int i = 0; i < size; i++) {
        if (board[i][col] == c)
            return true;
    }
    return false;
}

bool isNumInBox(char** board, int row, int col, char c) {
    int subBoxRow = row - row % 3;
    int subBoxCol = col - col % 3;
    for (int i = subBoxRow; i < subBoxRow + 3; i++) {
        for (int j = subBoxCol; j < subBoxCol + 3; j++) {
            if (board[i][j] == c)
                return true;
        }
    }
    return false;
}
