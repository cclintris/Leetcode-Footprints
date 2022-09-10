#include <iostream>
#include <stack>
using namespace std;

/**
 * I: head = [1,2,6,3,4,5,6], val = 6
 * O: [1,2,3,4,5]
 *
 * I: head = [], val = 1
 * O: []
 *
 * I: head = [7,7,7,7], val = 7
 * O: []
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* removeElements(ListNode* head, int val);

int main(int argc, char const* argv[]) {
    return 0;
}

ListNode* removeElements(ListNode* head, int val) {
    if (!head) return NULL;
    ListNode* dummy = head;
    stack<ListNode*> st;
    while (head) {
        if (head->val == val && st.empty()) {
            head = head->next;
            dummy = dummy->next;
        } else if (head->val == val && !st.empty()) {
            ListNode* top = st.top();
            top->next = head->next;
            head = head->next;
        } else {
            st.push(head);
            head = head->next;
        }
    }
    return dummy;
}
