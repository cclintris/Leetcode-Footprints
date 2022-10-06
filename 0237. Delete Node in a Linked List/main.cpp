#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

void deleteNode(ListNode* node);

int main(int argc, char const* argv[]) {
    return 0;
}

void deleteNode(ListNode* node) {
    ListNode* next = node->next;
    if (next->next) {
        ListNode* target = next->next;
        node->val = next->val;
        node->next = target;
    } else {
        node->val = next->val;
        node->next = NULL;
    }
}
