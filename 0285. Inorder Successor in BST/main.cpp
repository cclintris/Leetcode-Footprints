#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p);

int main(int argc, char const* argv[]) {
    return 0;
}

// Without BST properties, also suitable for BT
TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    stack<TreeNode*> st;
    bool seen = false;
    TreeNode* t = root;
    while (t || !st.empty()) {
        while (t) {
            st.push(t);
            t = t->left;
        }
        TreeNode* top = st.top();
        st.pop();
        if (seen) return top;
        if (top->val == p->val) seen = true;
        t = top->right;
    }
    return NULL;
}

// Using BST properties
TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    TreeNode* res = NULL;
    while (root) {
        if (root->val > p->val) {
            res = root;
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return res;
}
