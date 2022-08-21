#include <iostream>
#include <queue>
using namespace std;

/**
 * I: root = [1,2,5,3,4,null,6]
 * O: [1,null,2,null,3,null,4,null,5,null,6]
 *
 * I: root = []
 * O: []
 *
 * I: root = [0]
 * O: [0]
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

void flatten(TreeNode* root);

void dfs(TreeNode* root, queue<TreeNode*>& q);

int main(int argc, char const* argv[]) {
    return 0;
}

void flatten(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    dfs(root, q);
    q.pop();
    TreeNode* tmp = root;
    while (!q.empty()) {
        tmp->left = nullptr;
        tmp->right = q.front();
        q.pop();
        tmp = tmp->right;
    }
}

void dfs(TreeNode* root, queue<TreeNode*>& q) {
    if (!root) return;
    q.push(root);
    dfs(root->left, q);
    dfs(root->right, q);
}
