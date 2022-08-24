#include <algorithm>
#include <iostream>
using namespace std;

/**
 * I: root = [1,2,3]
 * O: 6
 * Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.
 *
 * I: root = [-10,9,20,null,null,15,7]
 * O: 42
 * Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr){};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){};
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right){};
};

int maxPathSum(TreeNode* root);

int dfs(TreeNode* root, int& res);

int main(int argc, char const* argv[]) {
    return 0;
}

int maxPathSum(TreeNode* root) {
    int res = INT_MIN;
    dfs(root, res);
    return res;
}

int dfs(TreeNode* root, int& res) {
    if (!root->left && !root->right) return root->val;
    int left = max(dfs(root->left, res), 0);
    int right = max(dfs(root->right, res), 0);
    res = max(res, root->val + left + right);
    return max(left, right) + root->val;
}
