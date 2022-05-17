#include <stdio.h>
#include <stdlib.h>
/**
 *
 * I: head = [1,2,3,4,5], k = 2
 * O: [2,1,4,3,5]

 * I: head = [1,2,3,4,5], k = 3
 * O: [3,2,1,4,5]
 */

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if (head == NULL || head->next == NULL || k < 2) return head;
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;

    struct ListNode* tail = dummy;
    struct ListNode* pre = dummy;
    struct ListNode* temp = NULL;
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

void printList(struct ListNode* list) {
    printf("[");
    struct ListNode* p = list;
    while (p != NULL) {
        if (p->next != NULL) {
            printf("%d,", p->val);
        } else {
            printf("%d", p->val);
        }
        p = p->next;
    }
    printf("]\n");
}

int main(int argc, char const* argv[]) {
    struct ListNode* l1n1 = (struct ListNode*)malloc(sizeof(struct ListNode*));
    struct ListNode* l1n2 = (struct ListNode*)malloc(sizeof(struct ListNode*));
    struct ListNode* l1n3 = (struct ListNode*)malloc(sizeof(struct ListNode*));
    struct ListNode* l1n4 = (struct ListNode*)malloc(sizeof(struct ListNode*));
    struct ListNode* l1n5 = (struct ListNode*)malloc(sizeof(struct ListNode*));
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
    struct ListNode* ret = reverseKGroup(l1n1, 2);
    printList(ret);
    free(l1n1);
    free(l1n2);
    free(l1n3);
    free(l1n4);
    free(l1n5);
    return 0;
}
