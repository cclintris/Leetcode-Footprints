#include <iostream>
using namespace std;

/**
 * I: root = [4,2,7,1,3,6,9]
 * O: [4,7,2,9,6,3,1]
 *
 * I: root = [2,1,3]
 * O: [2,3,1]
 *
 * I: root = []
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

TreeNode* invertTree(TreeNode* root);

void inversion(TreeNode* root);

int main(int argc, char const* argv[]) {
    return 0;
}

TreeNode* invertTree(TreeNode* root) {
    inversion(root);
    return root;
}

void inversion(TreeNode* root) {
    if (!root) return;
    if (!root->left && !root->right) return;
    TreeNode *l = NULL, *r = NULL;
    if (root->left) l = root->left;
    if (root->right) r = root->right;
    root->left = r;
    root->right = l;
    inversion(root->left);
    inversion(root->right);
    return;
}
