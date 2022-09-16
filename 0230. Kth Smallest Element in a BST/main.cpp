#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/**
 * I: root = [3,1,4,null,2], k = 1
 * O: 1
 *
 * I: root = [5,3,6,2,4,null,null,1], k = 3
 * O: 3
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

int kthSmallest(TreeNode* root, int k);

void buildTree(TreeNode* root, priority_queue<int, vector<int>, greater<int>>& minHeap);

int main(int argc, char const* argv[]) {
    return 0;
}

int kthSmallest(TreeNode* root, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    buildTree(root, minHeap);
    for (int i = 0; i < k - 1; i++) {
        minHeap.pop();
    }
    return minHeap.top();
}

void buildTree(TreeNode* root, priority_queue<int, vector<int>, greater<int>>& minHeap) {
    if (!root) return;
    minHeap.push(root->val);
    buildTree(root->left, minHeap);
    buildTree(root->right, minHeap);
    return;
}
