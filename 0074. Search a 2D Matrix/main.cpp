#include <iostream>
#include <vector>
using namespace std;

/**
 * I: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
 * O: true
 *
 * I: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
 * O: false
 */

bool searchMatrix(vector<vector<int> >& matrix, int target);

int main(int argc, char const* argv[]) {
    int m = 3, n = 4;
    vector<vector<int> > matrix(m, vector<int>(n));
    int arr[3][4] = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            matrix[i][j] = arr[i][j];
    int target = 13;
    cout << searchMatrix(matrix, target) << endl;
    return 0;
}

bool searchMatrix(vector<vector<int> >& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int targetRow = -1;
    for (int i = 0; i < m; i++) {
        if (target >= matrix[i][0] && target <= matrix[i][n - 1]) {
            targetRow = i;
            break;
        }
    }

    if (targetRow < 0) return false;
    for (int i = 0; i < n; i++) {
        if (matrix[targetRow][i] == target)
            return true;
    }
    return false;
}
