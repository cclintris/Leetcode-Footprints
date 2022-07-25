#include <iostream>
#include <vector>
using namespace std;

/**
 * I: head = [-10,-3,0,5,9]
 * O: [0,-3,9,-10,null,5]
 * Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.
 *
 * I: head = []
 * O: []
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

TreeNode* sortedListToBST(ListNode* head);

TreeNode* sortedArrayToBST(vector<int>& nums);

TreeNode* construct(vector<int>& nums, int left, int right);

int main(int argc, char const* argv[]) {
    return 0;
}

TreeNode* sortedListToBST(ListNode* head) {
    vector<int> nums;
    while (head != NULL) {
        nums.push_back(head->val);
        head = head->next;
    }
    return sortedArrayToBST(nums);
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
