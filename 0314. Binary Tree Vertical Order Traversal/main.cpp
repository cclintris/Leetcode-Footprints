#include <iostream>
#include <map>
#include <vector>
#include <utility>
using namespace std;

/**
 * I: root = [3,9,20,null,null,15,7]
 * O: [[9],[3,15],[20],[7]]
 *
 * I: root = [3,9,8,4,0,1,7]
 * O: [[4],[9],[3,0,1],[8],[7]]
 *
 * I: root = [3,9,8,4,0,1,7,null,null,null,2,5]
 * O: [[4],[9,5],[3,0,1],[8,2],[7]]
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

vector<vector<int>> verticalOrder(TreeNode* root);

void labelTree(TreeNode* root, unordered_map<int, vector<int>>& mp, int col);

int leftColumn(TreeNode* root, int depth);

int main(int argc, char const* argv[]) {
    return 0;
}

vector<vector<int>> verticalOrder(TreeNode* root) {
    if (!root) return {};
    map<int, vector<int>> mp;
    vector<pair<TreeNode*, int>> curs;
    curs.push_back(make_pair(root, 0));

    while (!curs.empty()) {
        vector<pair<TreeNode*, int>> tmp;
        for (auto cur : curs) {
            mp[cur.second].push_back(cur.first->val);
            if (cur.first->left)
                tmp.push_back({cur.first->left, cur.second - 1});
            if (cur.first->right)
                tmp.push_back({cur.first->right, cur.second + 1});
        }
        curs = tmp;
    }

    vector<vector<int>> ret;
    for (auto iter = mp.begin(); iter != mp.end(); iter++)
        ret.push_back(iter->second);
    return ret;
}

// vector<vector<int>> verticalOrder(TreeNode* root) {
//     vector<vector<int>> res;
//     map<int, vector<int>> mp;
//     int col = 0, depth = 0;
//     labelTree(root, mp, col);
//     leftColumn(root, depth);
//     // cout << "leftDepth: " << depth << endl;
//     // cout<<  "map size: " << mp.size() << endl;
//     for (auto it : mp) {
//         cout << it.first << ": ";
//         for (int i = 0; i < it.second.size(); i++) {
//             cout << it.second[i] << ", ";
//             if (i == it.second.size() - 1) cout << endl;
//         }
//     }
//     res.resize(mp.size());
//     for (auto it : mp) {
//         int index = it.first - depth;
//         // cout << "index: " << index << endl;
//         for (int i = 0; i < it.second.size(); i++) {
//             // cout << it.second[i] << " ";
//             res[index].push_back(it.second[i]);
//         }
//         cout << endl;
//     }
//     return res;
// }

// void labelTree(TreeNode* root, map<int, vector<int>>& mp, int col) {
//     if (!root) return;
//     mp[col].push_back(root->val);
//     labelTree(root->left, mp, col - 1);
//     labelTree(root->right, mp, col + 1);
// }

// bool leftColumn(TreeNode* root, int& depth) {
//     if (!root) {
//         depth++;
//         return true;
//     }
//     depth--;
//     if (leftColumn(root->left, depth)) {
//         return true;
//     }
//     return false;
// }
