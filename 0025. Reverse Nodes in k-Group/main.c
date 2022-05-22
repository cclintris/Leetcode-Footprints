#include <stdio.h>
#include <stdlib.h>

#include "../STL/list/singlelinkedlist.h"

/**
 *
 * I: head = [1,2,3,4,5], k = 2
 * O: [2,1,4,3,5]

 * I: head = [1,2,3,4,5], k = 3
 * O: [3,2,1,4,5]
 */

ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == NULL || head->next == NULL || k < 2) return head;
    ListNode* dummy = (ListNode*)malloc(sizeof(ListNode));
    dummy->next = head;

    ListNode* tail = dummy;
    ListNode* pre = dummy;
    ListNode* temp = NULL;
    int count;

    while (1) {
        count = k;
        while (count > 0 && tail != NULL) {
            tail = tail->next;
            count--;
        }

        if (tail == NULL) break;

        head = pre->next;

        while (pre->next != tail) {
            temp = pre->next;
            pre->next = temp->next;
            temp->next = tail->next;
            tail->next = temp;
        }
        tail = head;
        pre = head;
    }
    return dummy->next;
}

int main(int argc, char const* argv[]) {
    ListNode* l1n1 = (ListNode*)malloc(sizeof(ListNode*));
    ListNode* l1n2 = (ListNode*)malloc(sizeof(ListNode*));
    ListNode* l1n3 = (ListNode*)malloc(sizeof(ListNode*));
    ListNode* l1n4 = (ListNode*)malloc(sizeof(ListNode*));
    ListNode* l1n5 = (ListNode*)malloc(sizeof(ListNode*));
    l1n1->val = 1;
    l1n1->next = l1n2;
    l1n2->val = 2;
    l1n2->next = l1n3;
    l1n3->val = 3;
    l1n3->next = l1n4;
    l1n4->val = 4;
    l1n4->next = l1n5;
    l1n5->val = 5;
    l1n5->next = NULL;
    ListNode* ret = reverseKGroup(l1n1, 2);
    printList(ret);
    free(l1n1);
    free(l1n2);
    free(l1n3);
    free(l1n4);
    free(l1n5);
    return 0;
}
