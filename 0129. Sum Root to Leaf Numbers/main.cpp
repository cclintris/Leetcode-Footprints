#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/**
 * I: root = [1,2,3]
 * O: 25
 * Explanation:
    The root-to-leaf path 1->2 represents the number 12.
    The root-to-leaf path 1->3 represents the number 13.
    Therefore, sum = 12 + 13 = 25.
 *
 * I: Input: root = [4,9,0,5,1]
 * O: 1026
 * Explanation:
    The root-to-leaf path 4->9->5 represents the number 495.
    The root-to-leaf path 4->9->1 represents the number 491.
    The root-to-leaf path 4->0 represents the number 40.
    Therefore, sum = 495 + 491 + 40 = 1026.
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr){};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){};
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right){};
};

int dfs(TreeNode* root, vector<int>& vec, int& sum);

int sumNumbers(TreeNode* root);

int main(int argc, char const* argv[]) {
    return 0;
}

int sumNumbers(TreeNode* root) {
    int sum = 0;
    vector<int> vec;
    dfs(root, vec, sum);
    return sum;
}

int dfs(TreeNode* root, vector<int> vec, int& sum) {
    if (!root) return 0;
    if (!root->left && !root->right) {
        vec.push_back(root->val);
        int n = vec.size();
        for (int i = 0; i < n; i++) {
            sum += vec[i] * pow(10, n - i - 1);
        }
        return 0;
    }
    vec.push_back(root->val);
    dfs(root->left, vec, sum);
    dfs(root->right, vec, sum);
    return sum;
}
