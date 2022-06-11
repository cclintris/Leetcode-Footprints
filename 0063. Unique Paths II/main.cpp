#include <iostream>
#include <vector>
using namespace std;

/**
 * I: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
 * O: 2
 *
 * I: obstacleGrid = [[0,1],[0,0]]
 * O: 1
 */

int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid);

int main(int argc, char const* argv[]) {
    int arr[4][5] = {{0, 1, 0, 0, 0}, {1, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};
    int m = 4, n = 5;
    vector<vector<int> > obstacleGrid(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            obstacleGrid[i][j] = arr[i][j];
        }
    }
    cout << uniquePathsWithObstacles(obstacleGrid) << endl;
    return 0;
}

int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    if (m == 1 && n == 1 && obstacleGrid[0][0] == 1) return 0;
    if (m == 1 && n == 1 && obstacleGrid[0][0] == 0) return 1;
    if (obstacleGrid[0][0] == 1) return 0;

    vector<vector<int> > dp(m, vector<int>(n));
    dp[0][0] = 0;
    for (int i = 1; i < n; i++) {
        if (obstacleGrid[0][i]) {
            for (int j = i; j < n; j++)
                dp[0][j] = 0;
            break;
        } else {
            dp[0][i] = 1;
        }
    }
    for (int i = 1; i < m; i++) {
        if (obstacleGrid[i][0]) {
            for (int j = i; j < m; j++)
                dp[j][0] = 0;
            break;
        } else {
            dp[i][0] = 1;
        }
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (obstacleGrid[i][j]) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }

    return dp[m - 1][n - 1];
}
