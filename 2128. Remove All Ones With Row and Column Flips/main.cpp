#include <iostream>
#include <vector>
using namespace std;

/**
 * I: grid = [[0,1,0],[1,0,1],[0,1,0]]
 * O: false
 * Explanation: It is impossible to remove all 1's from grid.
 *
 * I: grid = [[0]]
 * O: true
 * Explanation: There are no 1's in grid.
 *
 * I: grid = [[1,1,0],[0,0,0],[0,0,0]]
 * O: false
 */

bool removeOnes(vector<vector<int>>& grid);

int main(int argc, char const* argv[]) {
    return 0;
}

bool removeOnes(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    for (int i = 0; i < m; i++) {
        if (grid[i][0] == 1) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    grid[i][j] = 0;
                else
                    grid[i][j] = 1;
            }
        }

        for (int k = 0; k < n; k++) {
            if (grid[i][k] != grid[0][k])
                return false;
        }
    }
    return true;
}
