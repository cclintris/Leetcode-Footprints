#include <iostream>
#include <vector>
using namespace std;

/**
 * I: n = 3
 * O: [[1,2,3],[8,9,4],[7,6,5]]
 *
 * I: n = 1
 * O: [[1]]
 */

vector<vector<int> > generateMatrix(int n);

bool valid(int row, int col, int n);

void printV(vector<vector<int> >& vec, int n);

int main(int argc, char const* argv[]) {
    int n = 4;
    vector<vector<int> > vec = generateMatrix(n);
    printV(vec, n);
    return 0;
}

vector<vector<int> > generateMatrix(int n) {
    vector<vector<int> > spiral(n, vector<int>(n));
    // printV(spiral, n);
    int ele = 1;
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};  // r d l u
    int row = 0, col = 0;
    int d = 0;
    while (ele <= n * n) {
        spiral[row][col] = ele++;
        // printV(spiral, n);
        int r = row + dir[d][0];
        int c = col + dir[d][1];
        if (!valid(r, c, n)) {
            d = (d + 1) % 4;
            row += dir[d][0];
            col += dir[d][1];
            continue;
        }
        if (spiral[r][c] != 0) {
            d = (d + 1) % 4;
            row += dir[d][0];
            col += dir[d][1];
            continue;
        }
        row += dir[d][0];
        col += dir[d][1];
    }

    return spiral;
}

bool valid(int row, int col, int n) {
    if (row >= 0 && row < n && col >= 0 && col < n)
        return true;
    return false;
}

void printV(vector<vector<int> >& vec, int n) {
    cout << "[";
    for (int i = 0; i < vec.size(); i++) {
        cout << "[";
        for (int j = 0; j < n; j++) {
            if (j == n - 1 && i == vec.size() - 1)
                cout << vec[i][j] << "]";
            else if (j == n - 1)
                cout << vec[i][j] << "],";
            else
                cout << vec[i][j] << ",";
        }
    }
    cout << "]\n";
}
