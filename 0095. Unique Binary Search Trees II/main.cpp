#include <iostream>
#include <vector>
using namespace std;

/**
 * I: n = 3
 * O: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
 *
 * I: n = 1
 * O: [[1]]
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<TreeNode *> generateTrees(int n);

// Divide and Conquer
vector<TreeNode *> generateBST(int start, int end);

void printBSTree(TreeNode *root);

int main(int argc, char const *argv[]) {
    int n = 3;
    vector<TreeNode *> res = generateTrees(n);
    cout << "[";
    for (int i = 0; i < res.size(); i++) {
        cout << "[";
        printBSTree(res[i]);
        if (i == res.size() - 1)
            cout << "]";
        else
            cout << "],";
    }
    cout << "]";
    return 0;
}

vector<TreeNode *> generateTrees(int n) {
    if (n == 0)
        return {};
    return generateBST(1, n);
}

vector<TreeNode *> generateBST(int start, int end) {
    vector<TreeNode *> res;
    if (start > end) {
        res.push_back(NULL);
        return res;
    }

    for (int i = start; i <= end; i++) {
        vector<TreeNode *> leftNodes = generateBST(start, i - 1);
        vector<TreeNode *> rightNodes = generateBST(i + 1, end);
        for (TreeNode *l : leftNodes) {
            for (TreeNode *r : rightNodes) {
                TreeNode *root = new TreeNode(i, l, r);
                res.push_back(root);
            }
        }
    }

    return res;
}

void printBSTree(TreeNode *root) {
    if (root == NULL) {
        cout << "null,";
        return;
    }
    if (root->left == NULL && root->right == NULL) {
        cout << root->val << ",";
        return;
    }
    cout << root->val << ",";
    printBSTree(root->left);
    printBSTree(root->right);
}
