#include <stdio.h>
#include <stdlib.h>

#include "../STL/list/singlelinkedlist.h"

/**
 *
 * I: list1 = [1,2,4], list2 = [1,3,4]
 * O: [1,1,2,3,4,4]

 * I: list1 = [], list2 = []
 * O: []
 *
 * I: list1 = [], list2 = [0]
 * O: [0]
 */

 ListNode* mergeTwoLists( ListNode* list1,  ListNode* list2) {
    if (list1 == NULL && list2 == NULL) return NULL;
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

     ListNode* ret;
     ListNode* dummy = ( ListNode*)malloc(sizeof( ListNode*) * 100);
    ret = dummy;
     ListNode *p1 = list1, *p2 = list2;
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
    if (p1 != NULL) {
        while (p1 != NULL) {
            dummy->next = p1;
            dummy = p1;
            p1 = p1->next;
        }
    }
    if (p2 != NULL) {
        while (p2 != NULL) {
            dummy->next = p2;
            dummy = p2;
            p2 = p2->next;
        }
    }
    dummy->next = NULL;
    return ret->next;
}

int main(int argc, char const* argv[]) {
     ListNode* l1n1 = ( ListNode*)malloc(sizeof( ListNode*));
     ListNode* l1n2 = ( ListNode*)malloc(sizeof( ListNode*));
     ListNode* l1n3 = ( ListNode*)malloc(sizeof( ListNode*));
    l1n1->val = 1;
    l1n1->next = l1n2;
    l1n2->val = 2;
    l1n2->next = l1n3;
    l1n3->val = 4;
    l1n3->next = NULL;
     ListNode* l2n1 = ( ListNode*)malloc(sizeof( ListNode*));
     ListNode* l2n2 = ( ListNode*)malloc(sizeof( ListNode*));
     ListNode* l2n3 = ( ListNode*)malloc(sizeof( ListNode*));
    l2n1->val = 1;
    l2n1->next = l2n2;
    l2n2->val = 3;
    l2n2->next = l2n3;
    l2n3->val = 4;
    l2n3->next = NULL;
     ListNode* mergeList = mergeTwoLists(l1n1, l2n1);
    printList(mergeList);
    free(l1n1);
    free(l1n2);
    free(l1n3);
    free(l2n1);
    free(l2n2);
    free(l2n3);
    return 0;
}
