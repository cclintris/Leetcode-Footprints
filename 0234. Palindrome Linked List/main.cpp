#include <iostream>
#include <vector>
using namespace std;

/**
 * I: head = [1,2,2,1]
 * O: true
 *
 * I: head = [1,2]
 * O: false
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

bool isPalindrome(ListNode* head);

int main(int argc, char const* argv[]) {
    return 0;
}

bool isPalindrome(ListNode* head) {
    if (!head) return false;
    if (!head->next) return true;
    vector<int> pre;
    vector<int> post;
    int len = 0;
    ListNode* tmp = head;
    while (head) {
        len++;
        head = head->next;
    }
    bool flag = len % 2 == 0;
    int mid = len / 2;
    while (mid && tmp) {
        pre.push_back(tmp->val);
        mid--;
        tmp = tmp->next;
    }
    if (!flag) tmp = tmp->next;
    while (tmp) {
        post.push_back(tmp->val);
        tmp = tmp->next;
    }
    int n = pre.size();
    for (int i = 0; i < n; i++) {
        if (pre[i] != post[n - 1 - i])
            return false;
    }
    return true;
}
