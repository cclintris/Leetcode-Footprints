#include <iostream>
#include <vector>
using namespace std;

/**
 * I: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
 * O: [[5,4,11,2],[5,8,4,5]]
 * Explanation: There are two paths whose sum equals targetSum:
    5 + 4 + 11 + 2 = 22
    5 + 8 + 4 + 5 = 22
 *
 * I: root = [1,2,3], targetSum = 5
 * O: []
 *
 * I: root = [1,2], targetSum = 0
 * O: []
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

vector<vector<int>> pathSum(TreeNode* root, int targetSum);

void dfs(vector<vector<int>>& res, vector<int>& tmp, TreeNode* node, int targetSum, int curSum);

int main(int argc, char const* argv[]) {
    return 0;
}

vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>> res;
    vector<int> tmp;
    if (!root) {
        return res;
    }
    dfs(res, tmp, root, targetSum, 0);
    return res;
}

void dfs(vector<vector<int>>& res, vector<int>& tmp, TreeNode* node, int targetSum, int curSum) {
    if (!node) return;
    tmp.push_back(node->val);
    curSum += node->val;
    if (!node->left && !node->right) {
        if (curSum == targetSum) {
            res.push_back(tmp);
        }
    } else {
        dfs(res, tmp, node->left, targetSum, curSum);
        dfs(res, tmp, node->right, targetSum, curSum);
    }
    tmp.pop_back();
}
