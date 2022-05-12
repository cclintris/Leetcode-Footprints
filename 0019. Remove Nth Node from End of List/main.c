#include <stdio.h>
#include <stdlib.h>

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
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* ptr = head;
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
    struct ListNode* after = ptr->next->next;
    if (after == NULL) {
        ptr->next = NULL;
    } else {
        ptr->next = after;
    }

    return head;
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
    struct ListNode* l1 = (struct ListNode*)malloc(sizeof(struct ListNode*));
    struct ListNode* l2 = (struct ListNode*)malloc(sizeof(struct ListNode*));
    struct ListNode* l3 = (struct ListNode*)malloc(sizeof(struct ListNode*));
    struct ListNode* l4 = (struct ListNode*)malloc(sizeof(struct ListNode*));
    struct ListNode* l5 = (struct ListNode*)malloc(sizeof(struct ListNode*));
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
    struct ListNode* head = removeNthFromEnd(l1, 3);
    printList(head);
    free(l5);
    free(l4);
    free(l3);
    free(l2);
    free(l1);
    return 0;
}
