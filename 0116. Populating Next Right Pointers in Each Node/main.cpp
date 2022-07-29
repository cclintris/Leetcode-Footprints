#include <iostream>
#include <queue>
using namespace std;

/**
 * I: root = [1,2,3,4,5,6,7]
 * O: [1,#,2,3,#,4,5,6,7,#]
 * Explanation: Given the above perfect binary tree (Figure A), your function
 * should populate each next pointer to point to its next right node,
 * just like in Figure B. The serialized output is in level order as connected by the next pointers,
 * with '#' signifying the end of each level.
 *
 * I: root = []
 * O: []
 */

struct Node {
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL){};
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL){};
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node* connect(Node* root);

int main(int argc, char const* argv[]) {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << q.front() << endl;
    return 0;
}

Node* connect(Node* root) {
    if (!root) return NULL;

    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; i++) {
            Node* front = q.front();
            q.pop();
            if (i != n - 1) {
                front->next = q.front();
            } else {
                front->next = NULL;
            }
            if (front->left) q.push(front->left);
            if (front->right) q.push(front->right);
        }
    }

    return root;
}
