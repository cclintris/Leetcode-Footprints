#include <iostream>
using namespace std;

/**
 * I: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
 * O: true
 *
 * I: root = [1,2,3], targetSum = 5
 * O: false
 *
 * I: root = [], targetSum = 0
 * O: false
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

bool hasPathSum(TreeNode* root, int targetSum);

int main(int argc, char const* argv[]) {
    return 0;
}

bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root) return false;
    if (root->left == NULL && root->right == NULL) {
        targetSum -= root->val;
        if (targetSum == 0)
            return true;
        else
            return false;
    }
    targetSum -= root->val;
    return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
}
