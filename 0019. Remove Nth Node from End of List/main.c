#include <stdio.h>
#include <stdlib.h>

#include "../STL/list/singlelinkedlist.h"

/**
 *
 * I: head = [1,2,3,4,5], n = 2
 * O: [1,2,3,5]

 * I: head = [1], n = 1
 * O: []
 *
 * I: head = [1,2], n = 1
 * O: [1]
 */

/**
 * Definition for singly-linked list.
 *  ListNode {
 *     int val;
 *      ListNode *next;
 * };
 */

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* ptr = head;
    int len = 0;
    while (ptr->next != NULL) {
        len++;
        ptr = ptr->next;
    }
    if (len == 0) return NULL;
    // printf("len %d\n", len);
    int step = len - n;
    if (step < 0) {
        head = head->next;
        return head;
    }
    ptr = head;
    for (int i = 0; i < step; i++) {
        ptr = ptr->next;
    }
    // printf("prev %d\n", ptr->val);
    ListNode* after = ptr->next->next;
    if (after == NULL) {
        ptr->next = NULL;
    } else {
        ptr->next = after;
    }

    return head;
}

int main(int argc, char const* argv[]) {
    ListNode* l1 = (ListNode*)malloc(sizeof(ListNode*));
    ListNode* l2 = (ListNode*)malloc(sizeof(ListNode*));
    ListNode* l3 = (ListNode*)malloc(sizeof(ListNode*));
    ListNode* l4 = (ListNode*)malloc(sizeof(ListNode*));
    ListNode* l5 = (ListNode*)malloc(sizeof(ListNode*));
    l1->val = 1;
    l1->next = l2;
    l2->val = 2;
    l2->next = l3;
    l3->val = 3;
    l3->next = l4;
    l4->val = 4;
    l4->next = l5;
    l5->val = 5;
    l5->next = NULL;
    ListNode* head = removeNthFromEnd(l1, 3);
    printList(head);
    free(l5);
    free(l4);
    free(l3);
    free(l2);
    free(l1);
    return 0;
}
