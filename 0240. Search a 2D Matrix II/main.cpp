#include <iostream>
#include <vector>
using namespace std;

/**
 * I: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
 * O: 1
 *
 * I: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
 * O: 0
 */

bool searchMatrix(vector<vector<int>>& matrix, int target);

int main(int argc, char const* argv[]) {
    vector<vector<int>> matrix{{1, 4}, {2, 5}};
    int target = 2;
    cout << searchMatrix(matrix, target) << endl;
    return 0;
}

// Brute force
// bool searchMatrix(vector<vector<int>>& matrix, int target) {
//     int m = matrix.size(), n = matrix[0].size();
//     for (int i = 0; i < m; i++) {
//         if (matrix[i][0] > target) return false;
//         for (int j = 0; j < n; j++) {
//             if (matrix[i][j] > target) break;
//             if (matrix[i][j] == target) return true;
//         }
//     }
//     return false;
// }

// binary search
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = matrix.size();
    int col = matrix[0].size();

    int r = 0;
    int c = col - 1;
    while ((r < row && r >= 0) && (c < col && c >= 0)) {
        int element = matrix[r][c];

        if (element == target) {
            return true;
        } else if (element > target) {
            c--;
        } else {
            r++;
        }
    }
    return false;
}
