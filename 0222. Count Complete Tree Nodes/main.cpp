#include <iostream>
using namespace std;

/**
 * I: root = [1,2,3,4,5,6]
 * O: 6
 *
 * I: root = []
 * O: 0
 *
 * I: root = [1]
 * O: 1
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

int countNodes(TreeNode* root);

void count(TreeNode* root, int& res);

int main(int argc, char const* argv[]) {
    return 0;
}

int countNodes(TreeNode* root) {
    int res = 0;
    count(root, res);
    return res;
}

void count(TreeNode* root, int& res) {
    if (!root) return;
    count(root->left, res);
    count(root->right, res);
    res++;
    return;
}
