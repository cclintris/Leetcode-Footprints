#include <iostream>
#include <queue>
#include <stack>
using namespace std;

/**
 * I: head = [1,2,3,4]
 * O: [1,4,2,3]
 *
 * I: head = [1,2,3,4,5]
 * O: [1,5,2,4,3]
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr){};
    ListNode(int _val) : val(_val), next(nullptr){};
    ListNode(int _val, ListNode* _next) : val(_val), next(_next){};
};

void printList(ListNode* head);

void reorderList(ListNode* head);

int main(int argc, char const* argv[]) {
    ListNode* n5 = new ListNode(5);
    ListNode* n4 = new ListNode(4, n5);
    ListNode* n3 = new ListNode(3, n4);
    ListNode* n2 = new ListNode(2, n3);
    ListNode* n1 = new ListNode(1, n2);
    printList(n1);
    reorderList(n1);
    printList(n1);
    return 0;
}

void reorderList(ListNode* head) {
    // Finding the middle of the list in order to split it in 2 parts
    ListNode* slow = head;
    ListNode* fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* head2 = slow->next;
    slow->next = NULL;

    // Reversing the 2nd half of the list
    ListNode* forward = NULL;
    ListNode* prev = NULL;
    ListNode* curr = head2;

    while (curr) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    // Merge the 2 lists
    head2 = prev;
    while (head2) {
        ListNode* ptr1 = head->next;
        ListNode* ptr2 = head2->next;

        head->next = head2;
        head2->next = ptr1;
        head = ptr1;
        head2 = ptr2;
    }
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
