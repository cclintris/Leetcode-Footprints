#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/**
 * I: root = [3,9,20,null,null,15,7]
 * O: [[3],[9,20],[15,7]]
 *
 * I: root = [1]
 * O: [[1]]
 *
 * I: root = []
 * O: []
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// non-recursive algorithm
vector<vector<int>> levelOrder(TreeNode *root);

// recusive algorithm
vector<vector<int>> levelOrder(TreeNode *root);

void traverse(TreeNode *node, vector<vector<int>> &res, int level);

int main(int argc, char const *argv[]) {
    return 0;
}

vector<vector<int>> levelOrder(TreeNode *root) {
    if (!root) return {};
    vector<vector<int>> res;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        vector<int> level;
        int num = q.size();
        for (int i = 0; i < num; i++) {
            TreeNode *front = q.front();
            level.push_back(front->val);
            q.pop();
            if (front->left) q.push(front->left);
            if (front->right) q.push(front->right);
        }
        res.push_back(level);
    }

    return res;
}

vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> res;
    traverse(root, res, 0);
    return res;
}

void traverse(TreeNode *node, vector<vector<int>> &res, int level) {
    if (!node) return;
    if (res.size() == level)
        res.push_back({});
    res[level].push_back(node->val);
    if (node->left) traverse(node->left, res, level + 1);
    if (node->right) traverse(node->right, res, level + 1);
}
