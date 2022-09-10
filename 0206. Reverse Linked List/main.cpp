#include <iostream>
using namespace std;

/**
 * I: head = [1,2,3,4,5]
 * O: [5,4,3,2,1]
 *
 * I: head = [1,2]
 * O: [2,1]
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

ListNode* reverseList(ListNode* head);

int main(int argc, char const* argv[]) {
    return 0;
}

ListNode* reverseList(ListNode* head) {
    if (!head) return NULL;

    ListNode* prev = NULL;
    ListNode* cur = head;
    ListNode* forward = NULL;
    while (cur) {
        forward = cur->next;
        cur->next = prev;
        prev = cur;
        cur = forward;
    }
    return prev;
}
