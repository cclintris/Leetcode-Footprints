#include <iostream>
#include <vector>
using namespace std;

/**
 * I: matrix = [[9,9,4],[6,6,8],[2,1,1]]
 * O: 4
 * Explanation: The longest increasing path is [1, 2, 6, 9].
 *
 * I: matrix = [[3,4,5],[3,2,6],[2,2,1]]
 * O: 4
 * Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
 */

int longestIncreasingPath(vector<vector<int>>& matrix);

int dfs(vector<vector<int>>& dp, vector<vector<int>>& matrix, int i, int j, int m, int n);

bool check(int x, int y, int m, int n);

void printVec(int m, int n, vector<vector<int>>& vec);

int main(int argc, char const* argv[]) {
    vector<vector<int>> matrix{{9, 9, 4}, {6, 6, 8}, {2, 1, 1}};
    cout << longestIncreasingPath(matrix) << endl;
    return 0;
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n));
    int res = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            res = max(res, dfs(dp, matrix, i, j, m, n));
            // printVec(m, n, dp);
        }
    }
    // printVec(m, n, dp);
    return res;
}

int dfs(vector<vector<int>>& dp, vector<vector<int>>& matrix, int i, int j, int m, int n) {
    if (dp[i][j]) return dp[i][j];
    int res = 1;
    if (check(i, j - 1, m, n) && matrix[i][j - 1] > matrix[i][j]) {  // go left
        // cout << "left res: " << res << endl;
        res = max(res, dfs(dp, matrix, i, j - 1, m, n) + 1);
    }
    if (check(i, j + 1, m, n) && matrix[i][j + 1] > matrix[i][j]) {  // go right
        // cout << "right res: " << res << endl;
        res = max(res, dfs(dp, matrix, i, j + 1, m, n) + 1);
    }
    if (check(i + 1, j, m, n) && matrix[i + 1][j] > matrix[i][j]) {  // go down
        // cout << "down res: " << res << endl;
        res = max(res, dfs(dp, matrix, i + 1, j, m, n) + 1);
    }
    if (check(i - 1, j, m, n) && matrix[i - 1][j] > matrix[i][j]) {  // go up
        // cout << "up res: " << res << endl;
        res = max(res, dfs(dp, matrix, i - 1, j, m, n) + 1);
    }

    dp[i][j] = res;
    return res;
}

bool check(int x, int y, int m, int n) {
    return x < m && x >= 0 && y < n && y >= 0;
}

void printVec(int m, int n, vector<vector<int>>& vec) {
    // cout << "[" << endl;
    for (int i = 0; i < m; i++) {
        cout << "[";
        for (int j = 0; j < n; j++) {
            if (j == n - 1 && i == m - 1) {
                cout << vec[i][j] << "]" << endl;
                break;
            }
            if (j != n - 1)
                cout << vec[i][j] << ",";
            else
                cout << vec[i][j] << "]," << endl;
        }
    }
    cout << "------------------------------" << endl;
    // cout << "]" << endl;
}
