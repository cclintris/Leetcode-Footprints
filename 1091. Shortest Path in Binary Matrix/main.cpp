#include <iostream>
#include <queue>
#include <set>
#include <utility>
#include <vector>
using namespace std;

/**
 * I: grid = [[0,1],[1,0]]
 * O: 2
 *
 * I: grid = [[0,0,0],[1,1,0],[1,1,0]]
 * O: 4
 *
 * I: grid = [[1,0,0],[1,1,0],[1,1,0]]
 * O: -1
 */

int shortestPathBinaryMatrix(vector<vector<int>>& grid);

int main(int argc, char const* argv[]) {
    return 0;
}

// BFS + dp
int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1) {
        return -1;
    }
    vector<pair<int, int>> adj = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {-1, 1}, {1, -1}, {1, 1}, {-1, -1}};
    vector<vector<int>> dp(n, vector<int>(n, 0));
    set<pair<int, int>> visited;
    queue<pair<int, int>> q;
    q.push({0, 0});
    dp[0][0] = 1;

    while (!q.empty()) {
        pair<int, int> p = q.front();
        for (int i = 0; i < 8; i++) {
            int x = p.first + adj[i].first;
            int y = p.second + adj[i].second;
            if (x < 0 or y < 0 or x >= n or y >= n) {
                continue;
            } else {
                if (visited.find({x, y}) != visited.end()) {
                    continue;
                } else {
                    visited.insert({x, y});
                }
                if (grid[x][y] == 1) {
                    continue;
                } else {
                    if (dp[x][y] == 0) {
                        dp[x][y] = 1 + dp[p.first][p.second];
                    }
                    q.push({x, y});
                }
            }
        }
        q.pop();
    }
    return dp[n - 1][n - 1] == 0 ? -1 : dp[n - 1][n - 1];
}

// BFS
int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1) return -1;
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    grid[0][0] = 1;
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        int x = cur.first, y = cur.second;
        int distance = grid[x][y];
        if (x == m - 1 && y == n - 1) return distance;
        vector<int> dx{0, 1, 1, 1, 0, -1, -1, -1};
        vector<int> dy{1, 1, 0, -1, -1, -1, 0, 1};
        for (int i = 0; i < 8; i++) {
            int d_x = x + dx[i];
            int d_y = y + dy[i];
            if (d_x == m - 1 && d_y == n - 1) return distance + 1;
            if (d_x >= 0 && d_x < m && d_y >= 0 && d_y < n && grid[d_x][d_y] == 0) {
                grid[d_x][d_y] = distance + 1;
                q.push(make_pair(d_x, d_y));
            }
        }
        q.pop();
    }
    return -1;
}
