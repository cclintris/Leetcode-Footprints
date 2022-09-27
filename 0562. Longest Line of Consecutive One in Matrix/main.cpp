#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/**
 * I: mat = [[0,1,1,0],[0,1,1,0],[0,0,0,1]]
 * O: 3
 *
 * I: mat = [[1,1,1,1],[0,1,1,0],[0,0,0,1]]
 * O: 4
 */

int longestLine(vector<vector<int>>& mat);

int main(int argc, char const* argv[]) {
    vector<vector<int>> mat{{1, 1, 1, 1}, {0, 1, 1, 0}, {0, 0, 0, 1}};
    cout << longestLine(mat) << endl;
    return 0;
}

int longestLine(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(4, 0)));
    int res = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 1) {
                dp[i][j][0] = j > 0 ? dp[i][j - 1][0] + 1 : 1;                   // horizontal
                dp[i][j][1] = i > 0 ? dp[i - 1][j][1] + 1 : 1;                   // vertical
                dp[i][j][2] = i > 0 && j > 0 ? dp[i - 1][j - 1][2] + 1 : 1;      // diagonal
                dp[i][j][3] = i > 0 && j < n - 1 ? dp[i - 1][j + 1][3] + 1 : 1;  // antidiagonal
            }
            res = max(res, max({dp[i][j][0], dp[i][j][1], dp[i][j][2], dp[i][j][3]}));
        }
    }
    return res;
}
