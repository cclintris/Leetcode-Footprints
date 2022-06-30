#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/**
 * I: nums = [1,2,2]
 * O: [[],[1],[1,2],[1,2,2],[2],[2,2]]
 *
 * I: nums = [0]
 * O: [[],[0]]
 */

vector<vector<int>> subsetsWithDup(vector<int>& nums);

void dfs(vector<vector<int>>& res, vector<int>& tmp, vector<int> nums, int start, int k);

void printV(vector<vector<int>> vec);

int main(int argc, char const* argv[]) {
    int arr[5] = {4, 4, 4, 1, 4};
    int n = 5;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        nums[i] = arr[i];
    vector<vector<int>> res = subsetsWithDup(nums);
    printV(res);
    return 0;
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> tmp;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n + 1; i++) {
        dfs(res, tmp, nums, 0, i);
    }
    return res;
}

void dfs(vector<vector<int>>& res, vector<int>& tmp, vector<int> nums, int start, int k) {
    if (tmp.size() == k) {
        if (find(res.begin(), res.end(), tmp) == res.end()) {
            res.push_back(tmp);
        }
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
