#include "singlelinkedlist.h"

#include <stdio.h>
#include <stdlib.h>

void printList(ListNode *root) {
    while (root != NULL) {
        if (root->next == NULL) {
            printf("%d", root->val);
        } else {
            printf("%d -> ", root->val);
        }
        root = root->next;
    }
    printf("\n");
}
