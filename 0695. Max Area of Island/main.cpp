#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/**
 * I:
 * O:
 *
 * I:
 * O:
 *
 * I:
 * O:
 */

int maxAreaOfIsland(vector<vector<int>>& grid);

void dfs(vector<vector<int>>& grid, int i, int j, int& res);

int main(int argc, char const* argv[]) {
    return 0;
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    int res = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                int tmp = 1;
                dfs(grid, i, j, tmp);
                res = max(res, tmp);
            }
        }
    }
    return res;
}

void dfs(vector<vector<int>>& grid, int i, int j, int& res) {
    int m = grid.size(), n = grid[0].size();
    if (grid[i][j] == 0 || grid[i][j] == -1) return;
    if (i < 0 || i >= m || j < 0 || j >= n) return;
    grid[i][j] = -1;
    vector<int> dx{0, 0, 1, -1};
    vector<int> dy{1, -1, 0, 0};
    for (int d = 0; d < 4; d++) {
        int new_x = i + dx[d];
        int new_y = j + dy[d];
        if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && grid[new_x][new_y] == 1) {
            res++;
            dfs(grid, new_x, new_y, res);
        }
    }
}
