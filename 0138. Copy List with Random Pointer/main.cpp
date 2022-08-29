#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/**
 * I: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
 * O: [[7,null],[13,0],[11,4],[10,2],[1,0]]
 *
 * I: head = [[1,1],[2,1]]
 * O: [[1,1],[2,1]]
 *
 * I: head = [[3,null],[3,0],[3,null]]
 * O: [[3,null],[3,0],[3,null]]
 */

struct Node {
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

int main(int argc, char const* argv[]) {
    return 0;
}

Node* copyRandomList(Node* head) {
    unordered_map<int, Node*> new_mp;
    unordered_map<Node*, int> old_mp;
    vector<Node*> store;
    int key = 0;
    Node* tmp = head;
    while (head != NULL) {
        Node* clone = new Node(head->val);
        store.push_back(clone);
        new_mp[key] = clone;
        old_mp[head] = key;
        key++;
        head = head->next;
    }
    new_mp[-1, NULL];
    store.push_back(NULL);

    int index = 0;
    while (store[index] != NULL) {
        store[index]->next = store[index + 1];
        index++;
    }
    index = 0;

    while (tmp != NULL) {
        Node* random = tmp->random;
        if (!random) {
            store[index++]->random = new_mp[-1];
        } else {
            int pos = old_mp[random];
            store[index++]->random = new_mp[pos];
        }
        tmp = tmp->next;
    }
    return store[0];
}
