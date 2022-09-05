#include <iostream>
using namespace std;

/**
 * I: [1,2,3,4,5]
 * O: [4,5,2,#,#,3,1]
 *
 * I:
 * O:
 *
 * I:
 * O:
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *upsideDownBinaryTree(TreeNode *root);

int main(int argc, char const *argv[]) {
    return 0;
}

TreeNode *upsideDownBinaryTree(TreeNode *root) {
    if (root == NULL) return NULL;
    if (root->left == NULL) return root;
    TreeNode *l = root->left;
    TreeNode *r = root->right;
    TreeNode *res = upsideDownBinaryTree(l);
    l->left = r;
    l->right = root;
    root->left = NULL;
    root->right = NULL;
    return res;
}
