#include <iostream>
using namespace std;

/**
 * I: head = [1,2,3,4,5], k = 2
 * O: [4,5,1,2,3]
 *
 * I: head = [0,1,2], k = 4
 * O: [2,0,1]
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* rotateRight(ListNode* head, int k);

ListNode* rotate(ListNode* head);

void printList(ListNode* head);

int main(int argc, char const* argv[]) {
    // ListNode l5(5, NULL);
    // ListNode l4(4, &l5);
    ListNode l3(2, NULL);
    ListNode l2(1, &l3);
    ListNode l1(0, &l2);
    // printList(&l1);
    int k = 4;
    ListNode* rl = rotateRight(&l1, k);
    printList(rl);
    return 0;
}

ListNode* rotateRight(ListNode* head, int k) {
    if (head == NULL) return NULL;

    ListNode* tmp = head;
    int len = 1;
    while (tmp->next != NULL) {
        tmp = tmp->next;
        len++;
    }
    k = k % len;

    ListNode* ret = head;
    for (int i = 0; i < k; i++) {
        ret = rotate(ret);
    }
    return ret;
}

ListNode* rotate(ListNode* head) {
    ListNode* last = head;
    ListNode* prev = head;
    int len = 0;
    while (last->next != NULL) {
        last = last->next;
        len++;
    }
    // cout << "len " << len << endl;
    for (int i = 0; i < len - 1; i++)
        prev = prev->next;

    // cout << "prev " << prev->val << endl;
    // cout << "last " << last->val << endl;

    ListNode* tmp = head;
    head = last;
    head->next = tmp;
    prev->next = NULL;

    return head;
}

void printList(ListNode* head) {
    cout << "[";
    while (head != NULL) {
        if (head->next == NULL)
            cout << head->val;
        else
            cout << head->val << ',';
        head = head->next;
    }
    cout << "]\n";
}
