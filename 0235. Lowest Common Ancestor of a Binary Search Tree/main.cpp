#include <iostream>
#include <vector>
using namespace std;

/**
 * I: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
 * O: 6
 *
 * I: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
 * O: 2
 *
 * I: root = [2,1], p = 2, q = 1
 * O: 2
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);

bool buildPath(TreeNode* root, int target, vector<TreeNode*>& res);

int main(int argc, char const* argv[]) {
    return 0;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == NULL || (root->val <= max(p->val, q->val) && root->val >= min(p->val, q->val))) return root;
    if (root->val > max(p->val, q->val)) return lowestCommonAncestor(root->left, p, q);
    if (root->val < min(p->val, q->val)) return lowestCommonAncestor(root->right, p, q);
    return root;
}

// bool buildPath(TreeNode* root, int target, vector<TreeNode*>& res) {
//     if (!root) return false;
//     if (root->val == target) return true;
//     res.push_back(root);
//     if (buildPath(root->left, target, res))
//         return true;
//     res.erase(res.end() - 1);
//     if (buildPath(root->right, target, res))
//         return true;
//     res.erase(res.end() - 1);
//     return false;
// }
