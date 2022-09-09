#include <deque>
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> rightSideView(TreeNode *root);

// BFS levelorder recursive
void levelOrder(vector<vector<int>> &vec, TreeNode *root, int level);

int main(int argc, char const *argv[]) {
    return 0;
}

// BFS iterative using deque
vector<int> rightSideView(TreeNode *root) {
    if (!root) return {};
    vector<int> res;
    deque<TreeNode *> dq;
    dq.push_back(root);
    while (!dq.empty()) {
        int s = dq.size();
        TreeNode *back = dq.back();
        res.push_back(back->val);
        while (s > 0) {
            TreeNode *front = dq.front();
            if (front->left) dq.push_back(front->left);
            if (front->right) dq.push_back(front->right);
            dq.pop_front();
            s--;
        }
    }
    return res;
}

// BFS levelorder recursive
vector<int> rightSideView(TreeNode *root) {
    vector<int> res;
    vector<vector<int>> level;
    levelOrder(level, root, 0);
    for (int i = 0; i < level.size(); i++) {
        res.push_back(level[i][level[i].size() - 1]);
    }
    return res;
}

void levelOrder(vector<vector<int>> &vec, TreeNode *root, int level) {
    if (!root) return;
    if (vec.size() == level) vec.push_back({});
    vec[level].push_back(root->val);
    levelOrder(vec, root->left, level + 1);
    levelOrder(vec, root->right, level + 1);
}
