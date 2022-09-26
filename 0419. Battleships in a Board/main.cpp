#include <iostream>
#include <vector>
using namespace std;

/**
 * I: board = [["X",".",".","X"],[".",".",".","X"],[".",".",".","X"]]
 * O: 2
 *
 * I: board = [["."]]
 * O: 0
 */

int countBattleships(vector<vector<char>>& board);

int dfs(vector<vector<char>>& board, int i, int j, int m, int n, vector<vector<bool>>& visited);

int main(int argc, char const* argv[]) {
    vector<vector<char>> board{{'X', '.', '.', '.'}, {'.', '.', '.', 'X'}, {'.', '.', '.', 'X'}};
    cout << countBattleships(board) << endl;
    return 0;
}

int countBattleships(vector<vector<char>>& board) {
    int m = board.size(), n = board[0].size();
    int res = 0;
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            res += (dfs(board, i, j, m, n, visited) != 0 ? 1 : 0);
        }
    }
    return res;
}

int dfs(vector<vector<char>>& board, int i, int j, int m, int n, vector<vector<bool>>& visited) {
    if (i < 0 || i >= m || j < 0 || j >= n) return 0;
    if (board[i][j] == '.' || visited[i][j]) return 0;
    visited[i][j] = true;
    return 1 +
           dfs(board, i - 1, j, m, n, visited) +
           dfs(board, i + 1, j, m, n, visited) +
           dfs(board, i, j - 1, m, n, visited) +
           dfs(board, i, j + 1, m, n, visited);
}
