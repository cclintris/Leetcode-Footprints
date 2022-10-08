#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

/**
 * I: grid = [[0,0,0],[1,1,0],[0,0,0],[0,1,1],[0,0,0]], k = 1
 * O: 6
 *
 * I: grid = [[0,1,1],[1,1,1],[1,0,0]], k = 1
 * O: -1
 *
 * I:
 * O:
 */

int shortestPath(vector<vector<int>>& grid, int k);

int main(int argc, char const* argv[]) {
    return 0;
}

struct triplet {
    int x, y, k;
};

// BFS: commented code is canonical BFS, TLE or takes very long
// Optmization: BFS + pruning
int shortestPath(vector<vector<int>>& grid, int k) {
    int m = grid.size(), n = grid[0].size();
    queue<triplet> q;
    unordered_set<string> visited;
    vector<vector<int>> obstables(m, vector<int>(n, -1));
    int step = 0;
    q.push({0, 0, k});
    obstables[0][0] = k;
    while (!q.empty()) {
        int size = q.size();
        while (size) {
            int row = q.front().x;
            int col = q.front().y;
            int quota = q.front().k;
            if (row == m - 1 && col == n - 1) return step;
            q.pop();
            vector<int> dx{0, 0, 1, -1};
            vector<int> dy{1, -1, 0, 0};
            for (int i = 0; i < 4; i++) {
                int new_x = row + dx[i];
                int new_y = col + dy[i];
                // if (new_x >= m || new_x < 0 || new_y >= n || new_y < 0 || (quota <= 0 && grid[new_x][new_y])) continue;
                if (new_x >= m || new_x < 0 || new_y >= n || new_y < 0) continue;
                int new_k = quota - grid[new_x][new_y];
                if (new_k <= obstables[new_x][new_y]) continue;
                obstables[new_x][new_y] = new_k;
                q.push({new_x, new_y, new_k});
                // string state = to_string(new_x) + "," + to_string(new_y) + "," + to_string(new_k);
                // if (new_k >= 0 && visited.find(state) == visited.end()) {
                //     visited.insert(state);
                //     q.push({new_x, new_y, new_k});
                // }
            }
            size--;
        }
        step++;
    }
    return -1;
}
