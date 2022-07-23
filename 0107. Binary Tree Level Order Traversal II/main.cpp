#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
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

vector<vector<int>> levelOrderBottom(TreeNode* root);

int main(int argc, char const* argv[]) {
    return 0;
}

vector<vector<int>> levelOrderBottom(TreeNode* root) {
    if (!root) return {};
    vector<vector<int>> res;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        vector<int> level;
        int num = q.size();
        for (int i = 0; i < num; i++) {
            TreeNode* front = q.front();
            level.push_back(front->val);
            q.pop();
            if (front->left) q.push(front->left);
            if (front->right) q.push(front->right);
        }
        res.push_back(level);
    }

    reverse(res.begin(), res.end());
    return res;
}
