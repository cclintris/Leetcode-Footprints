#include <iostream>
using namespace std;

/**
 * I: head = [4,2,1,3]
 * O: [1,2,3,4]
 *
 * I: head = [-1,5,3,4,0]
 * O: [-1,0,3,4,5]
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* insertionSortList(ListNode* head);

void printList(ListNode* head);

int main(int argc, char const* argv[]) {
    return 0;
}

ListNode* insertionSortList(ListNode* head) {
    if (!head) return NULL;
    ListNode* dummy = new ListNode(INT_MIN);
    ListNode* cur = dummy;
    while (head) {
        ListNode* t = head->next;
        cur = dummy;
        while (cur->next && cur->next->val < head->val) {
            cur = cur->next;
        }
        head->next = cur->next;
        cur->next = head;
        head = t;
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
