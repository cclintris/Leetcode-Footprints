#ifndef STL_SINGLELINKEDLIST
#define STL_SINGLELINKEDLIST

typedef struct Node {
    int val;
    struct Node* next;
} ListNode;

void printList(ListNode* root);

#endif
