#include <algorithm>
#include <iostream>
using namespace std;

/**
 * I: root = [3,9,20,null,null,15,7]
 * O: true
 *
 * I: root = [1,2,2,3,3,null,null,4,4]
 * O: false
 *
 * I: root = []
 * O: true
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

bool isBalanced(TreeNode* root);

int height(TreeNode* root);

int main(int argc, char const* argv[]) {
    return 0;
}

bool isBalanced(TreeNode* root) {
    if (!root) return true;
    int l = height(root->left);
    int r = height(root->right);
    if (abs(l - r) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return true;
    return false;
}

int height(TreeNode* root) {
    if (!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}
