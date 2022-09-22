#include <iostream>
#include <unordered_map>
using namespace std;

/**
 * I:
 * O:
 *
 * I:
 * O:
 *
 * I:
 * O:
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

int diameterOfBinaryTree(TreeNode* root);

int getHeight(TreeNode* root, unordered_map<TreeNode*, int>& mp;);

int main(int argc, char const* argv[]) {
    return 0;
}

int diameterOfBinaryTree(TreeNode* root) {
    if (!root) return 0;
    unordered_map<TreeNode*, int> mp;
    int res = getHeight(root->left, mp) + getHeight(root->right, mp);
    return max(res, max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
}

int getHeight(TreeNode* root, unordered_map<TreeNode*, int>& mp) {
    if (!root) return 0;
    if (mp.find(root) != mp.end()) return mp[root];
    int h = 1 + max(getHeight(root->left, mp), getHeight(root->right, mp));
    return mp[root] = h;
}
