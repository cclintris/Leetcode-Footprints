#include <iostream>
using namespace std;

/**
 * I: root = [4,2,5,1,3]
 * O: [1,2,3,4,5]
 * Explanation: The figure below shows the transformed BST.
 * The solid line indicates the successor relationship, while the dashed line means the predecessor relationship.
 *
 * I: root = [2,1,3]
 * O: [1,2,3]
 */

// Definition for a Node.
class Node {
   public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
   private:
    void dfs(Node* curNode, Node*& lastVisitedNode, Node*& firstVisitedNode) {
        // if curNode is not null
        if (curNode) {
            // make left call
            dfs(curNode->left, lastVisitedNode, firstVisitedNode);

            // if lastVisitedNode is not null, we can make the connection b/w the cur & lastVisitedNode
            // but(else), if its null, then we know we got the firstVisitedNode, so we can use it later
            if (lastVisitedNode) {
                lastVisitedNode->right = curNode;
                curNode->left = lastVisitedNode;
            } else {
                firstVisitedNode = curNode;
            }

            // updating the lastVisitedNode, bcz now curNode will become the lastVisitedNode
            lastVisitedNode = curNode;

            // make right call
            dfs(curNode->right, lastVisitedNode, firstVisitedNode);
        }
    }

   public:
    Node* treeToDoublyList(Node* curNode) {
        // base case
        if (!curNode) return NULL;

        // will pass lastVisitedNode and firstVisitedNode by address in DFS()
        Node *lastVisitedNode = NULL, *firstVisitedNode = NULL;
        dfs(curNode, lastVisitedNode, firstVisitedNode);

        // pointing last node to first node & vice versa, bcz we need to create Circular Linked List
        lastVisitedNode->right = firstVisitedNode;
        firstVisitedNode->left = lastVisitedNode;

        return firstVisitedNode;
    }
};

// class Solution {
//    public:
//     Node* treeToDoublyList(Node* root) {
//         if (!root) return NULL;
//         Node* last = construct(root);
//         Node* first = last;
//         while (first->left) {
//             first = first->left;
//         }
//         first->left = last;
//         last->right = first;
//         return first;
//     }

//     Node* construct(Node* root) {
//         if (!root) return NULL;
//         if (!root->left && !root->right) {
//             Node* node = new Node(root->val);
//             return node;
//         }
//         Node* l = construct(root->left);
//         Node* r = construct(root->right);
//         Node* m = new Node(root->val, l, r);
//         if (l) l->right = m;
//         if (r) r->left = m;
//         return r;
//     }
// };

int main(int argc, char const* argv[]) {
    return 0;
}
