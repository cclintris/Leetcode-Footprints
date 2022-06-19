#include <iostream>
#include <vector>
using namespace std;

/**
 * I: matrix = [[1,1,1],[1,0,1],[1,1,1]]
 * O: [[1,0,1],[0,0,0],[1,0,1]]
 *
 * I: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
 * O: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 */

void setZeroes(vector<vector<int> >& matrix);

void zerofy(vector<vector<int> >& matrix, vector<vector<bool> >& vec, int x, int y);

void printV(vector<vector<int> >& vec);

int main(int argc, char const* argv[]) {
    int m = 1, n = 3;
    vector<vector<int> > matrix(m, vector<int>(n));
    int arr[1][3] = {{5, 1, 1}};
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            matrix[i][j] = arr[i][j];

    setZeroes(matrix);
    printV(matrix);
    return 0;
}

void setZeroes(vector<vector<int> >& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<bool> > vec(m, vector<bool>(n, false));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!vec[i][j] && matrix[i][j] == 0)
                zerofy(matrix, vec, i, j);
        }
    }
}

void zerofy(vector<vector<int> >& matrix, vector<vector<bool> >& vec, int x, int y) {
    int m = matrix.size(), n = matrix[0].size();
    for (int i = 0; i < x; i++) {
        if (matrix[i][y] != 0)
            vec[i][y] = true;
        matrix[i][y] = 0;
    }
    for (int i = x + 1; i < m; i++) {
        if (matrix[i][y] != 0)
            vec[i][y] = true;
        matrix[i][y] = 0;
    }
    for (int i = 0; i < y; i++) {
        if (matrix[x][i] != 0)
            vec[x][i] = true;
        matrix[x][i] = 0;
    }
    for (int i = y + 1; i < n; i++) {
        if (matrix[x][i] != 0)
            vec[x][i] = true;
        matrix[x][i] = 0;
    }
}

void printV(vector<vector<int> >& vec) {
    int m = vec.size(), n = vec[0].size();
    cout << "[";
    for (int i = 0; i < m; i++) {
        cout << "[";
        for (int j = 0; j < n; j++) {
            if (j == n - 1 && i == m - 1)
                cout << vec[i][j] << "]";
            else if (j == n - 1)
                cout << vec[i][j] << "],";
            else
                cout << vec[i][j] << ",";
        }
    }
    cout << "]\n";
}
