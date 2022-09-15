#include <iostream>
using namespace std;

/**
 * I: root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
 * O: "UURL"
 * Explanation: The shortest path is: 3 → 1 → 5 → 2 → 6.
 *
 * I: root = [2,1], startValue = 2, destValue = 1
 * O: "L"
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

string getDirections(TreeNode* root, int startValue, int destValue);

bool getPath(TreeNode* root, string& res, int target);

int main(int argc, char const* argv[]) {
    string s = "temp";
    s.erase(s.end() - 1);
    cout << s << endl;
    return 0;
}

string getDirections(TreeNode* root, int startValue, int destValue) {
    string startStr = "", destStr = "", res = "";
    getPath(root, startStr, startValue);
    getPath(root, destStr, destValue);
    int i, j;
    // cout << "startStr: " << startStr << endl;
    // cout << "destStr: " << destStr << endl;
    for (i = 0; i < startStr.length(); i++) {
        if (startStr[i] != destStr[i]) break;
    }
    for (j = i; j < startStr.length(); j++) {
        res += "U";
    }
    return res + destStr.substr(i);
}

bool getPath(TreeNode* root, string& res, int target) {
    if (!root) return false;
    if (root->val == target) return true;
    res += 'L';
    if (getPath(root->left, res, target))
        return true;
    res.erase(res.end() - 1);

    res += 'R';
    if (getPath(root->right, res, target))
        return true;
    res.erase(res.end() - 1);
    return false;
}
