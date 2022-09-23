#include <iostream>
#include <vector>
using namespace std;

/**
 * I: grid = [[1,0],[0,1]]
 * O: 3
 * Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
 *
 * I: grid = [[1,1],[1,0]]
 * O: 4
 * Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.
 *
 * I: grid = [[1,1],[1,1]]
 * O: 4
 * Explanation: Can't change any 0 to 1, only one island with area = 4.
 */

int largestIsland(vector<vector<int>>& grid);
int dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited, int m, int n);

int main(int argc, char const* argv[]) {
    return 0;
}

int largestIsland(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    bool hasZero = false;
    int res = INT_MIN;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) continue;
            grid[i][j] = 1;
            hasZero = true;
            vector<vector<bool>> visited(m, vector<bool>(n, false));
            res = max(res, dfs(grid, i, j, visited, m, n));
            grid[i][j] = 0;
        }
    }
    return hasZero ? res : m * n;
}

int dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited, int m, int n) {
    if (i >= m || i < 0 || j >= n || j < 0 || visited[i][j] || grid[i][j] == 0) return 0;
    visited[i][j] = true;
    return 1 +
           dfs(grid, i + 1, j, visited, m, n) +
           dfs(grid, i - 1, j, visited, m, n) +
           dfs(grid, i, j + 1, visited, m, n) +
           dfs(grid, i, j - 1, visited, m, n);
}
