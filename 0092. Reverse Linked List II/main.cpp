#include <iostream>
using namespace std;

/**
 * I: head = [1,2,3,4,5], left = 2, right = 4
 * O: [1,4,3,2,5]
 *
 * I: head = [5], left = 1, right = 1
 * O: [5]
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* reverseBetween(ListNode* head, int left, int right);

void printList(ListNode* head);

int main(int argc, char const* argv[]) {
    int left = 1, right = 3;
    ListNode l4(5, NULL);
    ListNode l3(4, &l4);
    ListNode l2(3, &l3);
    ListNode l1(2, &l2);
    ListNode l0(1, &l1);
    ListNode* res = reverseBetween(&l0, left, right);
    printList(res);
    return 0;
}

ListNode* reverseBetween(ListNode* head, int left, int right) {
    // Dummy Node Approach (helps to handle edge cases)
    ListNode* dummy = new ListNode;  // dummy node
    dummy->next = head;

    // 1. reach node at position 'left'
    ListNode* leftPrev = dummy;
    ListNode* curr = head;
    for (int i = 0; i < left - 1; i++) {
        leftPrev = curr;
        curr = curr->next;
    }

    // 2. reverse from left to right
    ListNode* prev = NULL;
    ListNode* next = NULL;
    for (int i = 0; i < right - left + 1; i++) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // 3. updating pointers
    leftPrev->next->next = curr;
    leftPrev->next = prev;

    return dummy->next;
}

void printList(ListNode* head) {
    cout << "[";
    while (head != NULL) {
        if (head->next == NULL)
            cout << head->val;
        else
            cout << head->val << ',';
        head = head->next;
    }
    cout << "]\n";
}
