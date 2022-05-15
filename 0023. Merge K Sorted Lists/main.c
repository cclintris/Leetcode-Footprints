#include <stdio.h>
#include <stdlib.h>

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

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* merge2Lists(struct ListNode* l1, struct ListNode* l2) {
    if (l1 == NULL && l2 == NULL) return NULL;
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    struct ListNode* ret;
    struct ListNode *p1 = l1, *p2 = l2;
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode*) * 100);
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

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize == NULL) return NULL;
    struct ListNode* ret = lists[0];
    for (int i = 1; i < listsSize; i++) {
        ret = merge2Lists(ret, lists[i]);
    }
    return ret;
}

void printList(struct ListNode* head) {
    printf("[");
    struct ListNode* ptr = head;
    while (ptr != NULL) {
        if (ptr->next == NULL) {
            printf("%d", ptr->val);
        } else {
            printf("%d,", ptr->val);
        }
        ptr = ptr->next;
    }
    printf("]");
}

int main(int argc, char const* argv[]) {
    struct ListNode** lists = (struct ListNode**)malloc(sizeof(struct ListNode*) * 3);
    struct ListNode* l1n1 = (struct ListNode*)malloc(sizeof(struct ListNode*));
    struct ListNode* l1n2 = (struct ListNode*)malloc(sizeof(struct ListNode*));
    struct ListNode* l1n3 = (struct ListNode*)malloc(sizeof(struct ListNode*));
    lists[0] = l1n1;
    l1n1->val = 1;
    l1n1->next = l1n2;
    l1n2->val = 4;
    l1n2->next = l1n3;
    l1n3->val = 5;
    l1n3->next = NULL;
    struct ListNode* l2n1 = (struct ListNode*)malloc(sizeof(struct ListNode*));
    struct ListNode* l2n2 = (struct ListNode*)malloc(sizeof(struct ListNode*));
    struct ListNode* l2n3 = (struct ListNode*)malloc(sizeof(struct ListNode*));
    lists[1] = l2n1;
    l2n1->val = 1;
    l2n1->next = l2n2;
    l2n2->val = 3;
    l2n2->next = l2n3;
    l2n3->val = 4;
    l2n3->next = NULL;
    struct ListNode* l3n1 = (struct ListNode*)malloc(sizeof(struct ListNode*));
    struct ListNode* l3n2 = (struct ListNode*)malloc(sizeof(struct ListNode*));
    lists[2] = l3n1;
    l3n1->val = 2;
    l3n1->next = l3n2;
    l3n2->val = 6;
    l3n2->next = NULL;
    int listsSize = 3;
    struct ListNode* ret = mergeKLists(lists, listsSize);
    printList(ret);
    return 0;
}
