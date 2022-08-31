#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/**
 * I: root = [1,null,2,3]
 * O: [1,2,3]
 *
 * I: root = []
 * O: []
 *
 * I: root = [1]
 * O: [1]
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

void printVec(vector<int>& vec);

vector<int> preorderTraversal(TreeNode* root);

void traverse(vector<int>& res, TreeNode* root);

int main(int argc, char const* argv[]) {
    return 0;
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    traverse(res, root);
    return res;
}

// recursive
void traverse(vector<int>& res, TreeNode* root) {
    if (!root) return;
    res.push_back(root->val);
    traverse(res, root->left);
    traverse(res, root->right);
    return;
}

// iterative
void traverse(vector<int>& res, TreeNode* root) {
    if (!root) return;
    stack<TreeNode*> pre{{root}};
    while (!pre.empty()) {
        TreeNode* top = pre.top();
        pre.pop();
        res.push_back(top->val);
        if (top->right) pre.push(top->right);
        if (top->left) pre.push(top->left);
    }
}

void printVec(vector<int>& vec) {
    int len = vec.size();
    cout << "[";
    for (int i = 0; i < len; i++) {
        if (i == len - 1)
            cout << vec[i];
        else
            cout << vec[i] << ',';
    }
    cout << "]" << endl;
}
