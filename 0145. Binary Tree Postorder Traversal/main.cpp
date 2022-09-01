#include <iostream>
#include <queue>
#include <stack>
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

vector<int> postorderTraversal(TreeNode* root);

void traverse(vector<int>& res, TreeNode* root);

int main(int argc, char const* argv[]) {
    return 0;
}

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    traverse(res, root);
    return res;
}

// recursive
void traverse(vector<int>& res, TreeNode* root) {
    if (!root) return;
    traverse(res, root->left);
    traverse(res, root->right);
    res.push_back(root->val);
}

// iterative
void traverse(vector<int>& res, TreeNode* root) {
    if (!root) return;
    stack<TreeNode*> s1{{root}};
    stack<TreeNode*> s2;
    while (!s1.empty()) {
        TreeNode* top = s1.top();
        s2.push(top);
        s1.pop();
        if (top->left) s1.push(top->left);
        if (top->right) s1.push(top->right);
    }
    while (!s2.empty()) {
        res.push_back(s2.top()->val);
        s2.pop();
    }
}
