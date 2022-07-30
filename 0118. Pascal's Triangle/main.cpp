#include <iostream>
#include <vector>
using namespace std;

/**
 * I: numRows = 5
 * O: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
 *
 * I: numRows = 1
 * O: [[1]]
 */

vector<vector<int>> generate(int numRows);

void generatePascal(vector<vector<int>>& res, int numRows);

void printPascal(vector<vector<int>> tri, int numRows);

int main(int argc, char const* argv[]) {
    int numRows = 1;
    vector<vector<int>> res = generate(numRows);
    printPascal(res, numRows);
    return 0;
}

vector<vector<int>> generate(int numRows) {
    if (numRows == 1) return {{1}};
    vector<vector<int>> res;
    res.push_back({1});
    res.push_back({1, 1});
    generatePascal(res, numRows);
    return res;
}

void generatePascal(vector<vector<int>>& res, int numRows) {
    for (int i = 1; i < numRows - 1; i++) {
        vector<int> vec;
        vec.push_back(1);
        for (int j = 0; j < i; j++) {
            int num = res[i][j] + res[i][j + 1];
            vec.push_back(num);
        }
        vec.push_back(1);
        res.push_back(vec);
    }
}

void printPascal(vector<vector<int>> tri, int numRows) {
    cout << "[";
    for (int i = 1; i <= numRows; i++) {
        cout << "[";
        for (int j = 0; j < i; j++) {
            if (i == numRows) {
                if (j != i - 1)
                    cout << tri[i - 1][j] << ",";
                else
                    cout << tri[i - 1][j] << "]";
            } else {
                if (j != i - 1)
                    cout << tri[i - 1][j] << ",";
                else
                    cout << tri[i - 1][j] << "],";
            }
        }
    }
    cout << "]";
}
