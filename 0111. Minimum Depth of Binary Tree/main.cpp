#include <algorithm>
#include <iostream>
using namespace std;

/**
 * I: root = [3,9,20,null,null,15,7]
 * O: 2
 *
 * I: root = [2,null,3,null,4,null,5,null,6]
 * O: 5
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

int minDepth(TreeNode* root);

int main(int argc, char const* argv[]) {
    return 0;
}

int minDepth(TreeNode* root) {
    if (root) {
        if (!root->left)
            return minDepth(root->right) + 1;
        if (!root->right)
            return minDepth(root->left) + 1;

        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
    return 0;
}
