#include <stdio.h>
#include <stdlib.h>

#include "../STL/list/singlelinkedlist.h"

/**
 *
 * I: lists = [[1,4,5],[1,3,4],[2,6]]
 * O: [1,1,2,3,4,4,5,6]

 * I: lists = []
 * O: []
 *
 * I: lists = [[]]
 * O: []
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
    if (l1 == NULL && l2 == NULL) return NULL;
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    ListNode* ret;
    ListNode *p1 = l1, *p2 = l2;
    ListNode* dummy = (ListNode*)malloc(sizeof(ListNode*) * 100);
    ret = dummy;
    while (p1 != NULL && p2 != NULL) {
        if (p1->val < p2->val) {
            dummy->next = p1;
            dummy = p1;
            p1 = p1->next;
        } else {
            dummy->next = p2;
            dummy = p2;
            p2 = p2->next;
        }
    }
    if (p1 == NULL) {
        while (p2 != NULL) {
            dummy->next = p2;
            dummy = p2;
            p2 = p2->next;
        }
    }
    if (p2 == NULL) {
        while (p1 != NULL) {
            dummy->next = p1;
            dummy = p1;
            p1 = p1->next;
        }
    }
    dummy->next = NULL;
    return ret->next;
}

ListNode* mergeKLists(ListNode** lists, int listsSize) {
    if (listsSize == 0) return NULL;
    ListNode* ret = lists[0];
    for (int i = 1; i < listsSize; i++) {
        ret = merge2Lists(ret, lists[i]);
    }
    return ret;
}

int main(int argc, char const* argv[]) {
    ListNode** lists = (ListNode**)malloc(sizeof(ListNode*) * 3);
    ListNode* l1n1 = (ListNode*)malloc(sizeof(ListNode*));
    ListNode* l1n2 = (ListNode*)malloc(sizeof(ListNode*));
    ListNode* l1n3 = (ListNode*)malloc(sizeof(ListNode*));
    lists[0] = l1n1;
    l1n1->val = 1;
    l1n1->next = l1n2;
    l1n2->val = 4;
    l1n2->next = l1n3;
    l1n3->val = 5;
    l1n3->next = NULL;
    ListNode* l2n1 = (ListNode*)malloc(sizeof(ListNode*));
    ListNode* l2n2 = (ListNode*)malloc(sizeof(ListNode*));
    ListNode* l2n3 = (ListNode*)malloc(sizeof(ListNode*));
    lists[1] = l2n1;
    l2n1->val = 1;
    l2n1->next = l2n2;
    l2n2->val = 3;
    l2n2->next = l2n3;
    l2n3->val = 4;
    l2n3->next = NULL;
    ListNode* l3n1 = (ListNode*)malloc(sizeof(ListNode*));
    ListNode* l3n2 = (ListNode*)malloc(sizeof(ListNode*));
    lists[2] = l3n1;
    l3n1->val = 2;
    l3n1->next = l3n2;
    l3n2->val = 6;
    l3n2->next = NULL;
    int listsSize = 3;
    ListNode* ret = mergeKLists(lists, listsSize);
    printList(ret);
    return 0;
}
