#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/**
 * I: grid = [[1,3,1],[1,5,1],[4,2,1]]
 * O: 7
 *
 * I: grid = [[1,2,3],[4,5,6]]
 * O: 12
 */

int minPathSum(vector<vector<int> >& grid);

bool valid(int x, int y, int m, int n);

int main(int argc, char const* argv[]) {
    int m = 2, n = 3;
    int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};
    vector<vector<int> > grid(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            grid[i][j] = arr[i][j];
    }
    cout << minPathSum(grid) << endl;
    return 0;
}

int minPathSum(vector<vector<int> >& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int> > dp(m, vector<int>(n));
    dp[0][0] = grid[0][0];
    for (int i = 1; i < m; i++)
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    for (int i = 1; i < n; i++)
        dp[0][i] = dp[0][i - 1] + grid[0][i];
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }
    return dp[m - 1][n - 1];
}

bool valid(int x, int y, int m, int n) {
    if (x >= 0 && x < n && y >= 0 && y < m)
        return true;
    return false;
}
