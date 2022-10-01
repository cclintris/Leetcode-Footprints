#include <iostream>
#include <vector>
using namespace std;

/**
 * I: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
 * O: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
 *
 * I: heights = [[1]]
 * O: [[0,0]]
 */

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights);

void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int pre, int i, int j);

void printVec(vector<vector<int>>& res);

int main(int argc, char const* argv[]) {
    vector<vector<int>> heights{{1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4}};
    vector<vector<int>> res = pacificAtlantic(heights);
    printVec(res);
    return 0;
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    int m = heights.size(), n = heights[0].size();
    if (m == 0 || n == 0) return {};
    vector<vector<int>> res;
    vector<vector<bool>> pacific(m, vector<bool>(n, false));
    vector<vector<bool>> atlantic(m, vector<bool>(n, false));
    for (int i = 0; i < m; i++) {
        dfs(heights, pacific, INT_MIN, i, 0);
        dfs(heights, atlantic, INT_MIN, i, n - 1);
    }
    for (int i = 0; i < n; i++) {
        dfs(heights, pacific, INT_MIN, 0, i);
        dfs(heights, atlantic, INT_MIN, m - 1, i);
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (pacific[i][j] && atlantic[i][j])
                res.push_back({i, j});
        }
    }
    return res;
}

void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int pre, int i, int j) {
    int m = heights.size(), n = heights[0].size();
    if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || pre > heights[i][j]) return;
    visited[i][j] = true;
    dfs(heights, visited, heights[i][j], i - 1, j);  // up
    dfs(heights, visited, heights[i][j], i + 1, j);  // down
    dfs(heights, visited, heights[i][j], i, j - 1);  // left
    dfs(heights, visited, heights[i][j], i, j + 1);  // right
}

void printVec(vector<vector<int>>& res) {
    int m = res.size();
    cout << "[";
    for (int i = 0; i < m; i++) {
        if (i == m - 1)
            cout << "[" << res[i][0] << "," << res[i][1] << "]";
        else
            cout << "[" << res[i][0] << "," << res[i][1] << "],";
    }
    cout << "]" << endl;
    ;
}
