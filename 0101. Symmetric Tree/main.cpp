#include <iostream>
#include <vector>
using namespace std;

/**
 * I: root = [1,2,2,3,4,4,3]
 * O: true
 *
 * I: root = [1,2,2,null,3,null,3]
 * O: false
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isSymmetric(TreeNode *root);

bool check(TreeNode *l, TreeNode *r);

int main(int argc, char const *argv[]) {
    return 0;
}

bool isSymmetric(TreeNode *root) {
    if (!root) return true;
    if (!root->left && !root->right) return true;
    if (!root->left || !root->right) return false;
    return check(root->left, root->right);
}

bool check(TreeNode *l, TreeNode *r) {
    if (!l && !r) return true;
    if (!l || !r) return false;
    return l->val == r->val &&
           check(l->left, r->right) &&
           check(l->right, r->left);
}
