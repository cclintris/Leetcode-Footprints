#include <iostream>
#include <vector>
using namespace std;

/**
 * I: n = 4, k = 2
 * O:
 * [
    [2,4],
    [3,4],
    [2,3],
    [1,2],
    [1,3],
    [1,4],
   ]
 *
 * I: n = 1, k = 1
 * O: [[1]]
 */

vector<vector<int> > combine(int n, int k);

void dfs(vector<vector<int> >& res, vector<int>& tmp, int n, int k, int start);

void printV(vector<vector<int> > vec, int k);

int main(int argc, char const* argv[]) {
    int n = 4, k = 3;
    vector<vector<int> > res = combine(n, k);
    printV(res, k);
    return 0;
}

vector<vector<int> > combine(int n, int k) {
    vector<vector<int> > res;
    vector<int> tmp;
    dfs(res, tmp, n, k, 1);
    return res;
}

void dfs(vector<vector<int> >& res, vector<int>& tmp, int n, int k, int start) {
    if (tmp.size() == k) {
        res.push_back(tmp);
        return;
    }
    for (int i = start; i <= n; i++) {
        tmp.push_back(i);
        dfs(res, tmp, n, k, i + 1);
        tmp.pop_back();
    }
    return;
}

void printV(vector<vector<int> > vec, int k) {
    int len = vec.size();
    cout << "[";
    for (int i = 0; i < len; i++) {
        cout << "[";
        for (int j = 0; j < k; j++) {
            if (j == k - 1) {
                cout << vec[i][j];
            } else {
                cout << vec[i][j] << ",";
            }
        }
        cout << "]";
        if (i != len - 1)
            cout << ",";
    }
    cout << "]" << endl;
}
