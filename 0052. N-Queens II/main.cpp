#include <iostream>
#include <vector>
using namespace std;

/**
 * I: n = 4
 * O: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
 *
 * I: n = 1
 * O: [["Q"]]
 */

int totalNQueens(int n);

vector<vector<string> > solveNQueens(int n);

void backtrack(vector<vector<string> > &ret, vector<string> &board, int row, int n);

bool checkAttack(vector<string> &board, int row, int col);

bool validPos(int row, int col, int n);

void printV(vector<vector<string> > &vec, int n);

int main(int argc, char const *argv[]) {
    int n = 1;
    int res = totalNQueens(n);
    cout << res << endl;
    return 0;
}

int totalNQueens(int n) {
    vector<vector<string> > ret = solveNQueens(n);
    return ret.size();
}

vector<vector<string> > solveNQueens(int n) {
    vector<vector<string> > ret;
    vector<string> board;
    for (int i = 0; i < n; i++) {
        string tmp;
        for (int j = 0; j < n; j++)
            tmp += '.';
        board.push_back(tmp);
    }
    backtrack(ret, board, 0, n);
    return ret;
}

void backtrack(vector<vector<string> > &ret, vector<string> &board, int row, int n) {
    if (row == n) {
        ret.push_back(board);
        return;
    }
    for (int col = 0; col < n; col++) {
        board[row][col] = 'Q';
        if (checkAttack(board, row, col))
            backtrack(ret, board, row + 1, n);
        board[row][col] = '.';
    }
}

bool checkAttack(vector<string> &board, int row, int col) {
    int v[2] = {-1, 1};
    int S = board.size();
    for (int i = 0; i < S; i++) {
        if ((board[row][i] == 'Q' && i != col) || (board[i][col] == 'Q' && i != row))
            return false;
    }
    for (int i = 1; i < S; i++) {
        for (int x = 0; x < 2; x++) {
            for (int y = 0; y < 2; y++) {
                int nRow = row + v[x] * i;
                int nCol = col + v[y] * i;
                if (!validPos(nRow, nCol, S))
                    continue;
                if (board[nRow][nCol] == 'Q')
                    return false;
            }
        }
    }
    return true;
}

bool validPos(int row, int col, int n) {
    if ((row >= 0 && row < n) && (col >= 0 && col < n))
        return true;
    return false;
}

void printV(vector<vector<string> > &vec, int n) {
    cout << "[";
    for (int i = 0; i < vec.size(); i++) {
        cout << "[";
        for (int j = 0; j < n; j++) {
            if (j == n - 1 && i == vec.size() - 1)
                cout << vec.at(i).at(j) << "]";
            else if (j == n - 1)
                cout << vec.at(i).at(j) << "],";
            else
                cout << vec.at(i).at(j) << ",";
        }
    }
    cout << "]";
}
