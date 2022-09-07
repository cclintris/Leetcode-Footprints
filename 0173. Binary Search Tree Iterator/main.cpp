#include <iostream>
#include <queue>
#include <stack>
using namespace std;

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class BSTIterator {
   private:
    stack<TreeNode*> st;

   private:
    void pushAll(TreeNode* root) {
        while (root != NULL) {
            st.push(root);
            root = root->left;
        }
    }

   public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }

    int next() {
        TreeNode* temp = st.top();
        st.pop();
        pushAll(temp->right);
        return temp->val;
    }

    bool hasNext() {
        return !st.empty();
    }
};

// iterative
// void inorder(TreeNode* root) {
//     TreeNode* cur = root;
//     stack<TreeNode*> s;
//     while (!s.empty() && cur != NULL) {
//         while (cur != NULL) {
//             s.push(cur);
//             cur = cur->left;
//         }
//         cur = s.top();
//         s.pop();
//         cout << cur->val << endl;
//         cur = cur->right;
//     }
// }

int main(int argc, char const* argv[]) {
    return 0;
}
