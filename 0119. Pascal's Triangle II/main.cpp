#include <iostream>
#include <vector>
using namespace std;

/**
 * I: rowIndex = 3
 * O: [1,3,3,1]
 *
 * I: rowIndex = 0
 * O: [1]
 *
 * I: rowIndex = 1
 * O: [1,1]
 */

vector<int> getRow(int rowIndex);

vector<vector<int>> generate(int numRows);

void generatePascal(vector<vector<int>>& res, int numRows);

void printVec(vector<int>& vec);

int main(int argc, char const* argv[]) {
    vector<int> res = getRow(4);
    printVec(res);
    return 0;
}

vector<int> getRow(int rowIndex) {
    vector<vector<int>> vec = generate(rowIndex + 1);
    return vec[rowIndex];
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

void printVec(vector<int>& vec) {
    int len = vec.size();
    cout << "[";
    for (int i = 0; i < len; i++) {
        if (i == len - 1)
            cout << vec[i];
        else
            cout << vec[i] << ',';
    }
    cout << "]";
}
