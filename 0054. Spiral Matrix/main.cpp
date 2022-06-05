#include <iostream>
#include <vector>
using namespace std;

/**
 * I: matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * O: [1,2,3,6,9,8,7,4,5]
 *
 * I: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
 * O: [1,2,3,4,8,12,11,10,9,5,6,7]
 */

#define STOP_SIGN 1000

vector<int> spiralOrder(vector<vector<int> >& matrix);

void walk(vector<vector<int> >& matrix, int& row, int& col, vector<int>& vec, char& dir);

bool isValid(int& row, int& col, vector<vector<int> >& matrix);

void printV(vector<int>& vec);

int main(int argc, char const* argv[]) {
    int m = 3, n = 4;
    int arr[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    vector<vector<int> > matrix(m);
    for (int i = 0; i < m; i++) {
        matrix[i].resize(n);
        for (int j = 0; j < n; j++) {
            matrix[i][j] = arr[i][j];
        }
    }
    vector<int> res = spiralOrder(matrix);
    printV(res);
    return 0;
}

vector<int> spiralOrder(vector<vector<int> >& matrix) {
    int m = matrix.size();
    int n = matrix.at(0).size();
    vector<int> vec;
    int row = 0, col = -1;
    char dir = 'r';
    while (vec.size() != (m * n)) {
        walk(matrix, row, col, vec, dir);
    }
    return vec;
}

void walk(vector<vector<int> >& matrix, int& row, int& col, vector<int>& vec, char& dir) {
    int m = matrix.size();
    int n = matrix.at(0).size();
    switch (dir) {
        case 'r':
            /* right */
            col++;
            while (matrix.at(row).at(col) != STOP_SIGN && isValid(row, col, matrix)) {
                vec.push_back(matrix.at(row).at(col));
                matrix.at(row).at(col) = STOP_SIGN;
                col++;
                if (col == n) break;
            }
            col--;
            dir = 'd';
            break;

        case 'l':
            /* left */
            col--;
            while (matrix.at(row).at(col) != STOP_SIGN && isValid(row, col, matrix)) {
                vec.push_back(matrix.at(row).at(col));
                matrix.at(row).at(col) = STOP_SIGN;
                col--;
                if (col == -1) break;
            }
            col++;
            dir = 'u';
            break;

        case 'u':
            /* up */
            row--;
            while (matrix.at(row).at(col) != STOP_SIGN && isValid(row, col, matrix)) {
                vec.push_back(matrix.at(row).at(col));
                matrix.at(row).at(col) = STOP_SIGN;
                row--;
                if (row == -1) break;
            }
            row++;
            dir = 'r';
            break;

        case 'd':
            /* down */
            row++;
            while (matrix.at(row).at(col) != STOP_SIGN && isValid(row, col, matrix)) {
                vec.push_back(matrix.at(row).at(col));
                matrix.at(row).at(col) = STOP_SIGN;
                row++;
                if (row == m) break;
            }
            row--;
            dir = 'l';
            break;

        default:
            break;
    }
}

bool isValid(int& row, int& col, vector<vector<int> >& matrix) {
    int m = matrix.size();
    int n = matrix.at(0).size();
    if (row >= 0 && row < m && col >= 0 && col < n)
        return true;
    return false;
}

void printV(vector<int>& vec) {
    cout << "[";
    for (int i = 0; i < vec.size(); i++) {
        if (i == vec.size() - 1)
            cout << vec.at(i);
        else
            cout << vec.at(i) << ",";
    }
    cout << "]" << endl;
}
