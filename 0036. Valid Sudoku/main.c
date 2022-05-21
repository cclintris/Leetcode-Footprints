#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * I:
 * board =
[['5','3','.','.','7','.','.','.','.']
,['6','.','.','1','9','5','.','.','.']
,['.','9','8','.','.','.','.','6','.']
,['8','.','.','.','6','.','.','.','3']
,['4','.','.','8','.','3','.','.','1']
,['7','.','.','.','2','.','.','.','6']
,['.','6','.','.','.','.','2','8','.']
,['.','.','.','4','1','9','.','.','5']
,['.','.','.','.','8','.','.','7','9']]
 *
 * O: true
 *
 *
 *
 * I:
 * board =
[['8','3','.','.','7','.','.','.','.']
,['6','.','.','1','9','5','.','.','.']
,['.','9','8','.','.','.','.','6','.']
,['8','.','.','.','6','.','.','.','3']
,['4','.','.','8','.','3','.','.','1']
,['7','.','.','.','2','.','.','.','6']
,['.','6','.','.','.','.','2','8','.']
,['.','.','.','4','1','9','.','.','5']
,['.','.','.','.','8','.','.','7','9']]
 *
 * O: false
 */

bool isValidSudoku(char** board, int boardSize, int* boardColSize);

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
    printf("%d\n", isValidSudoku(board, boardSize, boardColSize));
    return 0;
}

bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    int freq[9] = {0};

    // Case 1: check for valid rows
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            if (board[i][j] == '.') continue;
            if (freq[board[i][j] - '1'] >= 1) {
                return false;
            }
            freq[board[i][j] - '1']++;
        }
        memset(freq, 0, boardSize * sizeof *freq);
    }

    // Case 2: check for valid columns
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            if (board[j][i] == '.') continue;
            if (freq[board[j][i] - '1'] >= 1) {
                return false;
            }
            freq[board[j][i] - '1']++;
        }
        memset(freq, 0, boardSize * sizeof *freq);
    }

    // Case 3: check for valid 3x3 boxes
    int col_cur = 0;
    int row_cur = 0;
    while (row_cur != boardSize) {
        for (int i = row_cur; i < row_cur + 3; i++) {
            for (int j = col_cur; j < col_cur + 3; j++) {
                if (board[i][j] == '.') continue;
                if (freq[board[i][j] - '1'] >= 1) return false;
                freq[board[i][j] - '1']++;
            }
        }
        col_cur += 3;
        if (col_cur >= 9) {
            row_cur += 3;
            col_cur = 0;
        }
        memset(freq, 0, boardSize * sizeof *freq);
    }

    return true;
}
