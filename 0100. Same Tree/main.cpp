#include <iostream>
#include <vector>
using namespace std;

/**
 * I: p = [1,2,3], q = [1,2,3]
 * O: true
 *
 * I: p = [1,2], q = [1,null,2]
 * O: false
 *
 * I: p = [1,2,1], q = [1,1,2]
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

bool isSameTree(TreeNode *p, TreeNode *q);

int main(int argc, char const *argv[]) {
    return 0;
}

bool isSameTree(TreeNode *p, TreeNode *q) {
    if (!p && !q) return true;
    if (!p || !q) return false;
    return (p->val == q->val) &&
           isSameTree(p->left, q->left) &&
           isSameTree(p->right, q->right);
}
