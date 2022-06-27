#include <iostream>
using namespace std;

/**
 * I: head = [1,4,3,2,5,2], x = 3
 * O: [1,2,2,4,3,5]
 *
 * I: head = [2,1], x = 2
 * O: [1,2]
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* partition(ListNode* head, int x);

void printList(ListNode* head);

int main(int argc, char const* argv[]) {
    int x = 3;
    ListNode l5(2, NULL);
    ListNode l4(5, &l5);
    ListNode l3(2, &l4);
    ListNode l2(3, &l3);
    ListNode l1(4, &l2);
    ListNode l0(1, &l1);
    ListNode* head = partition(&l0, x);
    printList(head);
    return 0;
}

ListNode* partition(ListNode* head, int x) {
    ListNode* smaller = new ListNode();
    ListNode* smaller_dummy = smaller;
    ListNode* greater = new ListNode();
    ListNode* greater_dummy = greater;
    while (head != NULL) {
        ListNode* node = new ListNode(head->val);
        if (head->val < x) {
            smaller->next = node;
            smaller = node;
        } else {
            greater->next = node;
            greater = node;
        }
        head = head->next;
    }
    smaller->next = greater_dummy->next;

    return smaller_dummy->next;
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
