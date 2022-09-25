#include <iostream>
#include <unordered_set>
using namespace std;

/**
 * I: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
 * O: 3
 * Explanation: The LCA of nodes 5 and 1 is 3.
 *
 * I: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
 * O: 5
 * Explanation: The LCA of nodes 5 and 4 is 5 since a node can be a descendant of itself according to the LCA definition.
 *
 * I: root = [1,2], p = 1, q = 2
 * O: 1
 */

// Definition for a Node.
class Node {
   public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};

Node* lowestCommonAncestor(Node* p, Node* q);

int main(int argc, char const* argv[]) {
    return 0;
}

Node* lowestCommonAncestor(Node* p, Node* q) {
    unordered_set<Node*> set;
    Node* root = NULL;
    while (p) {
        set.insert(p);
        if (p->parent == NULL) root = p;
        p = p->parent;
    }
    while (q) {
        if (set.find(q) != set.end()) return q;
        q = q->parent;
    }
    return root;
}
