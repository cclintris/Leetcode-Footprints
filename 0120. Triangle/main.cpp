#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/**
 * I: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
 * O: 11
 * Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
 *
 * I: triangle = [[-10]]
 * O: -10
 *
 * I: [[-1],[2,3],[1,-1,-3]]
 * O: -1
 */

int minimumTotal(vector<vector<int>>& triangle);

void printVec(vector<int>& vec);

int main(int argc, char const* argv[]) {
    vector<int> v1;
    v1.push_back(-1);
    vector<int> v2;
    v2.push_back(2);
    v2.push_back(3);
    vector<int> v3;
    v3.push_back(1);
    v3.push_back(-1);
    v3.push_back(-3);
    // vector<int> v4;
    // v4.push_back(4);
    // v4.push_back(1);
    // v4.push_back(8);
    // v4.push_back(3);
    vector<vector<int>> triangle;
    triangle.push_back(v1);
    triangle.push_back(v2);
    triangle.push_back(v3);
    // triangle.push_back(v4);
    cout << minimumTotal(triangle) << endl;
    return 0;
}

int minimumTotal(vector<vector<int>>& triangle) {
    int m = triangle.size();
    vector<int> dp(triangle[m - 1].size() + 1, 0);
    // printVec(dp);
    for (int i = m - 1; i >= 0; i--) {
        for (int j = 0; j < triangle[i].size(); j++) {
            // cout << "triangle[i][j]: " << triangle[i][j] << endl;
            dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
        }
        // printVec(dp);
    }

    return dp[0];
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
    cout << "]" << endl;
}
