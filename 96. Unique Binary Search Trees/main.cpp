#include <iostream>
#include <vector>
using namespace std;

/**
 * I: n = 3
 * O: 5
 *
 * I: n = 1
 * O: 1
 */

int numTrees(int n);

void printVec(vector<int>& vec);

int main(int argc, char const* argv[]) {
    int n = 3;
    cout << numTrees(n) << endl;
    return 0;
}

int numTrees(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            dp[i] += dp[j] * dp[i - 1 - j];
        }
    }
    // printVec(dp);
    return dp[n];
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
    cout << "]\n";
}
