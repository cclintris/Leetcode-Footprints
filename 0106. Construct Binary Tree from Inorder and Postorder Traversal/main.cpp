#include <iostream>
#include <vector>
using namespace std;

/**
 * I: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
 * O: [3,9,20,null,null,15,7]
 *
 * I: inorder = [-1], postorder = [-1]
 * O: [-1]
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder);

TreeNode* construct(vector<int>& inorder, vector<int>& postorder, int left, int right, int& idx);

int main(int argc, char const* argv[]) {
    return 0;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int idx = postorder.size() - 1;
    return construct(inorder, postorder, 0, inorder.size() - 1, idx);
}

TreeNode* construct(vector<int>& inorder, vector<int>& postorder, int left, int right, int& idx) {
    if (left > right) return NULL;
    int pivot = right;
    while (inorder[pivot] != postorder[idx])
        pivot--;

    idx--;
    TreeNode* root = new TreeNode(inorder[pivot]);
    root->right = construct(inorder, postorder, pivot + 1, right, idx);
    root->left = construct(inorder, postorder, left, pivot - 1, idx);
    return root;
}
