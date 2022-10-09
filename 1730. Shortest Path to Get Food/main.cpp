#include <iostream>
#include <queue>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

int getFood(vector<vector<char>>& grid);

int main(int argc, char const* argv[]) {
    return 0;
}

// BFS
int getFood(vector<vector<char>>& grid) {
    int m = grid.size(), n = grid[0].size();
    queue<pair<pair<int, int>, int>> q;
    pair<int, int> start;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '*') {
                start.first = i;
                start.second = j;
                break;
            }
        }
    }
    q.push({start, 0});
    unordered_set<string> visited;
    visited.insert(to_string(start.first) + "," + to_string(start.second));
    while (!q.empty()) {
        int size = q.size();
        while (size) {
            auto front = q.front();
            q.pop();
            int cur_x = front.first.first;
            int cur_y = front.first.second;
            int step = front.second;
            if (grid[cur_x][cur_y] == '#') return step;
            vector<int> dx{0, 0, 1, -1};
            vector<int> dy{1, -1, 0, 0};
            for (int i = 0; i < 4; i++) {
                int new_x = cur_x + dx[i];
                int new_y = cur_y + dy[i];
                if (new_x < 0 || new_x >= m || new_y < 0 || new_y >= n) continue;
                if (grid[new_x][new_y] == 'X') continue;
                string state = to_string(new_x) + "," + to_string(new_y);
                if (visited.find(state) == visited.end()) {
                    visited.insert(state);
                    q.push({{new_x, new_y}, step + 1});
                }
            }
            size--;
        }
    }
    return -1;
}
