#include <iostream>
#include <map>
#include <vector>
using namespace std;

/**
 * I: mat = [[1,2,3],[4,5,6],[7,8,9]]
 * O: [1,2,4,7,5,3,6,8,9]
 *
 * I: mat = [[1,2],[3,4]]
 * O: [1,2,3,4]
 */

vector<int> findDiagonalOrder(vector<vector<int>>& mat);

void printVec(vector<int>& vec);

int main(int argc, char const* argv[]) {
    vector<vector<int>> mat{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> res = findDiagonalOrder(mat);
    printVec(res);
    return 0;
}

vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    vector<int> res;
    map<int, vector<int>> mp;
    int n = mat.size(), m = mat[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            mp[i + j].push_back(mat[i][j]);
        }
    }
    for (auto it = mp.begin(); it != mp.end(); it++) {
        if (it->first % 2 == 0) {
            for (int i = it->second.size() - 1; i >= 0; i--)
                res.push_back(it->second[i]);
        } else {
            for (int i = 0; i < it->second.size(); i++)
                res.push_back(it->second[i]);
        }
    }
    return res;
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
