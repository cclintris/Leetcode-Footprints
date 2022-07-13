#include <iostream>
using namespace std;

/**
 * I: root = [2,1,3]
 * O: true
 *
 * I: root = [5,1,4,null,null,3,6]
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

bool isValidBST(TreeNode *root);

bool check(TreeNode *node, long minV, long maxV);

int main(int argc, char const *argv[]) {
    TreeNode *n1 = new TreeNode(4);
    TreeNode *n3 = new TreeNode(3);
    TreeNode *n4 = new TreeNode(7);
    TreeNode *n2 = new TreeNode(6, n3, n4);
    TreeNode *root = new TreeNode(5, n1, n2);
    cout << isValidBST(root) << endl;
    return 0;
}

bool isValidBST(TreeNode *root) {
    return check(root, LONG_MIN, LONG_MAX);
}

bool check(TreeNode *node, long minV, long maxV) {
    if (!node) return true;
    if (node->val <= minV || node->val >= maxV) return false;
    return check(node->left, minV, node->val) && check(node->right, node->val, maxV);
}
