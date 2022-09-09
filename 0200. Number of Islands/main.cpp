#include <iostream>
#include <vector>
using namespace std;

/**
 * I: grid =
 * [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
  ]
 * O: 1
 *
 * I: grid =
 * [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
    ]
 * O: 3
 */

int numIslands(vector<vector<char>>& grid);

void dfs(vector<vector<char>>& grid, int i, int j);

int main(int argc, char const* argv[]) {
    vector<vector<char>> grid{{'1', '1', '0', '0', '0'},
                              {'1', '1', '0', '0', '0'},
                              {'0', '1', '1', '1', '0'},
                              {'0', '0', '0', '1', '1'}};
    cout << numIslands(grid) << endl;
    return 0;
}

int numIslands(vector<vector<char>>& grid) {
    int res = 0;
    int m = grid.size(), n = grid[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '1') {
                dfs(grid, i, j);
                res++;
            }
        }
    }
    return res;
}

void dfs(vector<vector<char>>& grid, int i, int j) {
    int m = grid.size(), n = grid[0].size();
    if (i < 0 || j < 0) return;
    if (i >= m || j >= n) return;
    if (grid[i][j] == '0') return;
    grid[i][j] = '0';
    dfs(grid, i + 1, j);
    dfs(grid, i - 1, j);
    dfs(grid, i, j + 1);
    dfs(grid, i, j - 1);
}
