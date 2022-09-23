#include <iostream>
#include <unordered_map>
using namespace std;

/**
 * I: matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
 * O: 1
 * Explanation:
    In the above grid, the diagonals are:
    "[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]".
    In each diagonal all elements are the same, so the answer is True.
 *
 * I: matrix = [[1,2],[2,2]]
 * O: 0
 * Explanation:
    The diagonal "[1, 2]" has different elements.
 */

bool isToeplitzMatrix(vector<vector<int>>& matrix)

    int main(int argc, char const* argv[]) {
    return 0;
}

bool isToeplitzMatrix(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    unordered_map<int, int> mp;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mp.find(i - j) != mp.end() && matrix[i][j] != mp[i - j])
                return false;
            mp[i - j] = matrix[i][j];
        }
    }
    return true;
}
