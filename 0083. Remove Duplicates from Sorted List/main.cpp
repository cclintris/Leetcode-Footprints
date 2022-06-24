#include <iostream>
#include <map>
using namespace std;

/**
 * I: head = [1,1,2]
 * O: [1,2]
 *
 * I: head = [1,1,2,3,3]
 * O: [1,2,3]
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* deleteDuplicates(ListNode* head);

int main(int argc, char const* argv[]) {
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
        ListNode* node = new ListNode();
        node->val = item.first;
        tmp->next = node;
        node->next = NULL;
        tmp = node;
    }
    return dummy->next;
}
