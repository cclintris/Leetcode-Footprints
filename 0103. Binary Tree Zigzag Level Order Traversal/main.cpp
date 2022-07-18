#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/**
 * I: root = [3,9,20,null,null,15,7]
 * O: [[3],[20,9],[15,7]]
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

vector<vector<int>> zigzagLevelOrder(TreeNode *root);

int main(int argc, char const *argv[]) {
    return 0;
}

vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    if (!root) return {};
    vector<vector<int>> res;
    queue<TreeNode *> q;
    q.push(root);
    bool oddLevel = false;
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
        if (oddLevel)
            reverse(level.begin(), level.end());
        oddLevel = !oddLevel;
        res.push_back(level);
    }

    return res;
}