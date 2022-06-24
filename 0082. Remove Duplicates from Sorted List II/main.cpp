#include <iostream>
#include <map>
using namespace std;

/**
 * I: head = [1,2,3,3,4,4,5]
 * O: [1,2,5]
 *
 * I: head = [1,1,1,2,3]
 * O: [2,3]
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* deleteDuplicates(ListNode* head);

void printList(ListNode* head);

int main(int argc, char const* argv[]) {
    ListNode node7(5);
    ListNode node6(4, &node7);
    ListNode node5(4, &node6);
    ListNode node4(3, &node5);
    ListNode node3(3, &node4);
    ListNode node2(2, &node3);
    ListNode head(1, &node2);
    ListNode* ret = deleteDuplicates(&head);
    printList(ret);
    return 0;
}

ListNode* deleteDuplicates(ListNode* head) {
    ListNode* dummy = new ListNode();
    ListNode* tmp = dummy;
    map<int, int> mp;
    while (head != NULL) {
        if (mp.find(head->val) == mp.end()) {
            mp[head->val] = 1;
        } else {
            mp[head->val]++;
        }
        head = head->next;
    }
    for (const auto& item : mp) {
        if (item.second == 1) {
            ListNode* node = new ListNode();
            node->val = item.first;
            tmp->next = node;
            node->next = NULL;
            tmp = node;
        }
    }
    return dummy->next;
}

void printList(ListNode* head) {
    cout << "[";
    while (head != NULL) {
        if (head->next == NULL) {
            cout << head->val;
        } else {
            cout << head->val << ",";
        }
        head = head->next;
    }
    cout << "]" << endl;
}
