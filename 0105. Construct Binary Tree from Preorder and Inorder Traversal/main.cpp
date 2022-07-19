#include <iostream>
#include <vector>
using namespace std;

/**
 * I: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
 * O: [3,9,20,null,null,15,7]
 *
 * I: preorder = [-1], inorder = [-1]
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

// https://bear-1111.medium.com/leetcode-105-construct-binary-tree-from-preorder-and-inorder-traversal-9ca1f9246347
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);

TreeNode* construct(vector<int>& preorder, vector<int>& inorder, int& idx, int left, int right);

int main(int argc, char const* argv[]) {
    return 0;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n = inorder.size();
    int idx = 0;
    return construct(preorder, inorder, idx, 0, n - 1);
}

TreeNode* construct(vector<int>& preorder, vector<int>& inorder, int& idx, int left, int right) {
    if (left > right) return NULL;
    int pivot = left;
    while (inorder[pivot] != preorder[idx])
        pivot++;

    idx++;
    TreeNode* root = new TreeNode(inorder[pivot]);
    root->left = construct(preorder, inorder, idx, left, pivot - 1);
    root->right = construct(preorder, inorder, idx, pivot + 1, right);
    return root;
}
