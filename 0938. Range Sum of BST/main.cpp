#include <iostream>
using namespace std;

/**
 * I: root = [10,5,15,3,7,null,18], low = 7, high = 15
 * O: 32
 * Explanation: Nodes 7, 10, and 15 are in the range [7, 15]. 7 + 10 + 15 = 32.
 *
 * I: root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
 * O: 23
 * Explanation: Nodes 6, 7, and 10 are in the range [6, 10]. 6 + 7 + 10 = 23.
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

int rangeSumBST(TreeNode* root, int low, int high);

void calculate(TreeNode* root, int low, int high, imt& res);

int main(int argc, char const* argv[]) {
    return 0;
}

int rangeSumBST(TreeNode* root, int low, int high) {
    if (!root) return 0;
    int res = 0;
    calculate(root, low, high, res);
    return res;
}

void calculate(TreeNode* root, int low, int high, int& res) {
    if (!root) return;
    if (root->val >= low && root->val <= high) {
        res += root->val;
        calculate(root->left, low, high, res);
        calculate(root->right, low, high, res);
    } else if (root->val < low) {
        calculate(root->right, low, high, res);
    } else {
        calculate(root->left, low, high, res);
    }
    return;
}
