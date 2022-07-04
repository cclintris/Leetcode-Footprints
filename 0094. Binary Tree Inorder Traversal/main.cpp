#include <iostream>
#include <vector>
using namespace std;

/**
 * I: root = [1,null,2,3]
 * O: [1,3,2]
 *
 * I: root = []
 * O: []
 *
 * I: root = [1]
 * O: [1]
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> inorderTraversal(TreeNode *root);

void inorder(vector<int> vec, TreeNode *root);

int main(int argc, char const *argv[]) {
    return 0;
}

vector<int> inorderTraversal(TreeNode *root) {
    vector<int> res;
    inorder(res, root);
    return res;
}

void inorder(vector<int> &vec, TreeNode *root) {
    if (root == NULL) return;
    inorder(vec, root->left);
    vec.push_back(root->val);
    inorder(vec, root->right);
}
