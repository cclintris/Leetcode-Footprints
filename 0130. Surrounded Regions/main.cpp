#include <iostream>
#include <vector>
using namespace std;

/**
 * I: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
 * O: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
 * Explanation: Notice that an 'O' should not be flipped if:
    - It is on the border, or
    - It is adjacent to an 'O' that should not be flipped.
    The bottom 'O' is on the border, so it is not flipped.
    The other three 'O' form a surrounded region, so they are flipped.
 *
 * I: board = [["X"]]
 * O: [["X"]]
 */

void solve(vector<vector<char>>& board);

void dfs(vector<vector<char>>& board, int x, int y, int m, int n);

int main(int argc, char const* argv[]) {
    return 0;
}

void solve(vector<vector<char>>& board) {
    if (board.empty() || board[0].empty()) return;
    int m = board.size(), n = board[0].size();
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                if (board[i][j] == 'O')
                    dfs(board, i, j);
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == 'O') board[i][j] = 'X';
            if (board[i][j] == '$') board[i][j] = 'O';
        }
    }
}
void dfs(vector<vector<char>>& board, int x, int y) {
    int m = board.size(), n = board[0].size();
    vector<vector<int>> dir{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    board[x][y] = '$';
    for (int i = 0; i < dir.size(); ++i) {
        int dx = x + dir[i][0], dy = y + dir[i][1];
        if (dx >= 0 && dx < m && dy > 0 && dy < n && board[dx][dy] == 'O') {
            dfs(board, dx, dy);
        }
    }
}
