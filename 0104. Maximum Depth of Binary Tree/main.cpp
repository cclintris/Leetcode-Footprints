#include <iostream>
using namespace std;

/**
 * I: root = [3,9,20,null,null,15,7]
 * O: 3
 *
 * I: root = [1,null,2]
 * O: 2
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxDepth(TreeNode *root);

int main(int argc, char const *argv[]) {
    return 0;
}

int maxDepth(TreeNode *root) {
    if (!root) return 0;
    int maxLeft = maxDepth(root->left);
    int maxRight = maxDepth(root->right);
    return max(maxLeft, maxRight) + 1;
}
