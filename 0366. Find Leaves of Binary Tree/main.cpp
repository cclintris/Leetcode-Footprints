#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/**
 * I: root = [1,2,3,4,5]
 * O: [[4,5,3],[2],[1]]
 *
 * I: root = [1]
 * O: [1]
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

vector<vector<int>> findLeaves(TreeNode* root);

int dfs(TreeNode* root, vector<vector<int>>& res);

int main(int argc, char const* argv[]) {
    return 0;
}

vector<vector<int>> findLeaves(TreeNode* root) {
    vector<vector<int>> res;
    dfs(root, res);
    return res;
}

int dfs(TreeNode* root, vector<vector<int>>& res) {
    if (!root) return -1;
    int left = dfs(root->left, res) + 1;
    int right = dfs(root->right, res) + 1;
    int maxDepth = max(left, right);
    if (maxDepth >= res.size())
        res.resize(maxDepth + 1);
    res[maxDepth].push_back(root->val);
    return maxDepth;
}
