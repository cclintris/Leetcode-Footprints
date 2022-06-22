#include <iostream>
#include <vector>
using namespace std;

/**
 * I: nums = [1,2,3]
 * O: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
 *
 * I: nums = [0]
 * O: [[],[0]]
 */

vector<vector<int>> subsets(vector<int>& nums);

void dfs(vector<vector<int>>& res, vector<int>& tmp, vector<int> nums, int start, int k);

void printV(vector<vector<int>> vec);

int main(int argc, char const* argv[]) {
    int arr[3] = {1, 2, 3};
    int n = 3;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        nums[i] = arr[i];
    vector<vector<int>> res = subsets(nums);
    printV(res);
    return 0;
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> tmp;
    int n = nums.size();
    for (int k = 0; k < n + 1; k++) {
        dfs(res, tmp, nums, 0, k);
    }
    return res;
}

void dfs(vector<vector<int>>& res, vector<int>& tmp, vector<int> nums, int start, int k) {
    if (tmp.size() == k) {
        res.push_back(tmp);
        return;
    }
    for (int i = start; i < nums.size(); i++) {
        tmp.push_back(nums[i]);
        dfs(res, tmp, nums, i + 1, k);
        tmp.pop_back();
    }
    return;
}

void printV(vector<vector<int>> vec) {
    cout << "[";
    for (int i = 0; i < vec.size(); i++) {
        cout << "[";
        int len = vec[i].size();
        for (int j = 0; j < len; j++) {
            if (j != len - 1) {
                cout << vec[i][j] << ",";
            } else {
                cout << vec[i][j];
            }
        }
        if (i != vec.size() - 1) {
            cout << "],";
        } else {
            cout << "]";
        }
    }
    cout << "]";
}
