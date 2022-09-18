#include <iostream>
using namespace std;

/**
 * I: root = [4,2,5,1,3], target = 3.714286
 * O: 4
 *
 * I: root = [1], target = 4.428571
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

int closestValue(TreeNode* root, double target);

void findClosest(TreeNode* root, double target, int& res, double& min);

int main(int argc, char const* argv[]) {
    return 0;
}

int closestValue(TreeNode* root, double target) {
    int res = 0;
    double init = root->val - target;
    if (init == 0) return root->val;
    if (init < 0) {
        init -= 1;
        init *= -1;
    } else {
        init += 1;
    }
    findClosest(root, target, res, init);
    return res;
}

void findClosest(TreeNode* root, double target, int& res, double& min) {
    if (!root) return;
    double tmp = root->val - target;
    if (tmp == 0) {
        res = root->val;
        return;
    }
    if (tmp < 0) tmp *= -1;
    if (tmp < min) {
        min = tmp;
        res = root->val;
    }
    if (target < root->val) {
        findClosest(root->left, target, res, min);
    } else {
        findClosest(root->right, target, res, min);
    }
    return;
}