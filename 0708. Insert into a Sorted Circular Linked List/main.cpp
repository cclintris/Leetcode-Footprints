#include <iostream>
#include <unordered_set>
using namespace std;

/**
 * I: head = [3,4,1], insertVal = 2
 * O: [3,4,1,2]
 *
 * I: head = [], insertVal = 1
 * O: [1]
 *
 * I: head = [1], insertVal = 0
 * O: [1,0]
 */

// Definition for a Node.
class Node {
   public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};

Node* insert(Node* head, int insertVal);

int main(int argc, char const* argv[]) {
    return 0;
}

Node* insert(Node* head, int insertVal) {
    if (!head) {
        Node* node = new Node(insertVal);
        node->next = node;
        return node;
    }
    Node* res = head;
    unordered_set<Node*> set;
    bool flag = true;
    while (1) {
        if (head->val <= insertVal && head->next->val >= insertVal) break;
        flag = (head->val <= insertVal);
        if (set.find(head) != set.end()) {
            // Node* min = new Node(INT_MAX);
            Node* max = new Node(INT_MIN);
            for (auto it = set.begin(); it != set.end(); it++) {
                // if ((*it)->val < min->val) min = *it;
                if ((*it)->val > max->val) max = *it;
                // head = flag ? max : min;
                head = max;
            }
            break;
        }
        set.insert(head);
        head = head->next;
    }
    Node* node = new Node(insertVal);
    Node* next = head->next;
    head->next = node;
    node->next = next;
    return res;
}
