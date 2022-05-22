#include <stdio.h>
#include <stdlib.h>

#include "../STL/list/singlelinkedlist.h"

/**
 *
 * I: head = [1,2,3,4]
 * O: [2,1,4,3]

 * I: head = []
 * O: []
 *
 * I: head = [1]
 * O: [1]
 */

ListNode* swapPairs(ListNode* head) {
    ListNode* current;
    ListNode* previous;
    ListNode* save;
    ListNode* pom;
    ListNode* link;

    int flag;

    pom = head;
    link = NULL;
    while (pom != NULL && pom->next != NULL) {
        if (pom == head)
            flag = 1;
        else
            flag = 0;

        previous = pom;
        current = pom->next;
        save = current->next;
        current->next = previous;
        previous->next = save;
        if (link != NULL)
            link->next = current;
        if (flag)
            head = current;

        link = previous;
        pom = save;
    }
    return head;
}

int main(int argc, char const* argv[]) {
    ListNode* l1n1 = (ListNode*)malloc(sizeof(ListNode*));
    ListNode* l1n2 = (ListNode*)malloc(sizeof(ListNode*));
    ListNode* l1n3 = (ListNode*)malloc(sizeof(ListNode*));
    ListNode* l1n4 = (ListNode*)malloc(sizeof(ListNode*));
    l1n1->val = 1;
    l1n1->next = l1n2;
    l1n2->val = 2;
    l1n2->next = l1n3;
    l1n3->val = 3;
    l1n3->next = l1n4;
    l1n4->val = 4;
    l1n4->next = NULL;
    ListNode* ret = swapPairs(l1n1);
    printList(ret);
    free(l1n1);
    free(l1n2);
    free(l1n3);
    free(l1n4);
    return 0;
}
