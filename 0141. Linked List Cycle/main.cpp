#include <iostream>
using namespace std;

/**
 * I: head = [3,2,0,-4], pos = 1
 * O: true
 * Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
 *
 * I: head = [1,2], pos = 0
 * O: true
 * Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.
 *
 * I: head = [1], pos = -1
 * O: false
 * Explanation: There is no cycle in the linked list.
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int _val) : val(x), next(NULL){};
};

bool hasCycle(ListNode *head);

int main(int argc, char const *argv[]) {
    return 0;
}

bool hasCycle(ListNode *head) {
    if (head == NULL) return false;
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            return true;
    }
    return false;
}
