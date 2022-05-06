#include <stdio.h>
#include <stdlib.h>

/*
 * Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 * Output: [8,9,9,9,0,0,0,1]
 * 9 9 9 9 9 9 9
 * 9 9 9 9
 * 8 9 9 9 0 0 0 1
 */

struct Listnode {
    int val;
    struct Listnode *next;
};

typedef struct Listnode ListNode;

void printListNode(ListNode *root) {
    while (root != NULL) {
        if (root->next == NULL) {
            printf("%d", root->val);
        } else {
            printf("%d -> ", root->val);
        }
        root = root->next;
    }
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    if (!l1)
        return l2;
    if (!l2)
        return l1;

    ListNode *root, *cur, *stub;
    int v1, v2, carry = 0, temp;
    cur = (ListNode *)malloc(sizeof(ListNode));

    while (l1 || l2) {
        v1 = l1 ? l1->val : 0;
        v2 = l2 ? l2->val : 0;
        temp = v1 + v2 + carry;
        if (temp > 9) {
            temp %= 10;
            carry = 1;
        } else {
            carry = 0;
        }
        stub = (ListNode *)malloc(sizeof(ListNode));
        stub->val = temp;
        cur->next = stub;
        cur = cur->next;
        if (l1)
            l1 = l1->next;
        if (l2)
            l2 = l2->next;
    }

    if (carry == 1) {
        stub = (ListNode *)malloc(sizeof(ListNode));
        stub->val = 1;
        stub->next = NULL;
        cur->next = stub;
    }
    stub->next = NULL;
    cur = root->next;
    free(root);

    return cur;
}

int main(int argc, char const *argv[]) {
    ListNode *l1 = (ListNode *)malloc(sizeof(ListNode));
    ListNode *n11 = (ListNode *)malloc(sizeof(ListNode));
    ListNode *n12 = (ListNode *)malloc(sizeof(ListNode));
    ListNode *n13 = (ListNode *)malloc(sizeof(ListNode));
    l1 = n11;
    n11->val = 2;
    n11->next = n12;
    n12->val = 4;
    n12->next = n13;
    n13->val = 3;
    n13->next = NULL;
    ListNode *l2 = (ListNode *)malloc(sizeof(ListNode));
    ListNode *n21 = (ListNode *)malloc(sizeof(ListNode));
    ListNode *n22 = (ListNode *)malloc(sizeof(ListNode));
    ListNode *n23 = (ListNode *)malloc(sizeof(ListNode));
    l2 = n21;
    n21->val = 5;
    n21->next = n22;
    n22->val = 6;
    n22->next = n23;
    n23->val = 4;
    n23->next = NULL;
    ListNode *root = addTwoNumbers(l1, l2);
    printListNode(root);
    return 0;
}
