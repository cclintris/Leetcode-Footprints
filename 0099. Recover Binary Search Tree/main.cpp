#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/**
 * I: root = [1,3,null,null,2]
 * O: [3,1,null,null,2]
 * Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.
 *
 * I: root = [3,1,4,null,null,2]
 * O: [2,1,4,null,null,3]
 * Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void recoverTree(TreeNode *root);

void inorder(TreeNode *root, vector<int> &values, vector<TreeNode *> &nodes);

int main(int argc, char const *argv[]) {
    return 0;
}

// A valid BST's value will result in a ascending order when traversed in a inorder fashion
// preorder  NLR
// inorder   LNR
// postorder LRN
void recoverTree(TreeNode *root) {
    vector<int> values;
    vector<TreeNode *> nodes;
    inorder(root, values, nodes);
    sort(values.begin(), values.end());
    for (int i = 0; i < nodes.size(); i++) {
        nodes[i]->val = values[i];
    }
}

void inorder(TreeNode *root, vector<int> &values, vector<TreeNode *> &nodes) {
    if (!root) return;
    inorder(root->left, values, nodes);
    values.push_back(root->val);
    nodes.push_back(root);
    inorder(root->right, values, nodes);
}
