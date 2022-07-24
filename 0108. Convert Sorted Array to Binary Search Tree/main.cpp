#include <iostream>
#include <vector>
using namespace std;

/**
 * I: nums = [-10,-3,0,5,9]
 * O: [0,-3,9,-10,null,5]
 * Explanation: [0,-10,5,null,-3,null,9] is also accepted:
 *
 * I: nums = [1,3]
 * O: [3,1]
 * Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

TreeNode* sortedArrayToBST(vector<int>& nums);

TreeNode* construct(vector<int>& nums, int left, int right);

int main(int argc, char const* argv[]) {
    // cout << 3 / 2 << endl;
    return 0;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return construct(nums, 0, nums.size() - 1);
}

TreeNode* construct(vector<int>& nums, int left, int right) {
    if (left > right) return NULL;
    int mid = (left + right) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = construct(nums, left, mid - 1);
    root->right = construct(nums, mid + 1, right);
    return root;
}
