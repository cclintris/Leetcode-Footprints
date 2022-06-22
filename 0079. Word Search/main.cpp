#include <iostream>
#include <vector>
using namespace std;

/**
 * I: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
 * O: true
 *
 * I: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
 * O: true
 *
 * I: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
 * O: false
 */

bool exist(vector<vector<char>>& board, string word);

bool dfs(vector<vector<char>>& board, int m, int n, string word, int x, int y);

int main(int argc, char const* argv[]) {
    return 0;
}

bool exist(vector<vector<char>>& board, string word) {
    int m = board.size(), n = board[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (dfs(board, m, n, word, i, j))
                return true;
        }
    }
    return false;
}

bool dfs(vector<vector<char>>& board, int m, int n, string& word, int x, int y) {
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    if (word.length() == 0)
        return true;

    if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] != word[0])
        return false;

    bool res = false;
    char ch = board[x][y];
    board[x][y] = '_';
    string str = word.substr(1);
    for (int i = 0; i < 4; i++)
        res = res || dfs(board, m, n, str, x + dx[i], y + dy[i]);

    board[x][y] = ch;
    return res;
}
