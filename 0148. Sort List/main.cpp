#include <iostream>
using namespace std;

/**
 * I: head = [4,2,1,3]
 * O: [1,2,3,4]
 *
 * I: head = [-1,5,3,4,0]
 * O: [-1,0,3,4,5]
 *
 * I: head  = []
 * O: []
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* sortList(ListNode* head);

ListNode* merge(ListNode* l1, ListNode* l2);

void printList(ListNode* head);

int main(int argc, char const* argv[]) {
    // ListNode* node5 = new ListNode(0, NULL);
    ListNode* node4 = new ListNode(4, NULL);
    ListNode* node3 = new ListNode(1, node4);
    ListNode* node2 = new ListNode(3, node3);
    ListNode* head = new ListNode(2, node2);
    printList(head);
    ListNode* ret = sortList(head);
    printList(ret);
    return 0;
}

ListNode* sortList(ListNode* head) {
    if (!head || !head->next)
        return head;

    // Use Floyd's tortoise and hare to find the middle of list, in order to perform mergesort on left and right halves lists
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* tmp = NULL;
    while (fast && fast->next) {
        tmp = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    tmp->next = NULL;               // end of first half
    ListNode* l1 = sortList(head);  // left recusive
    ListNode* l2 = sortList(slow);  // right recursive
    return merge(l1, l2);
}

ListNode* merge(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(-1);
    ListNode* cur = dummy;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            cur->next = l1;
            l1 = l1->next;
        } else {
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
    }

    if (l1) {
        cur->next = l1;
        // l1 = l1->next;
    }
    if (l2) {
        cur->next = l2;
        // l2 = l2->next;
    }
    return dummy->next;
}

void printList(ListNode* head) {
    cout << "[";
    while (head != NULL) {
        if (head->next == NULL) {
            cout << head->val;
        } else {
            cout << head->val << ",";
        }
        head = head->next;
    }
    cout << "]" << endl;
}
