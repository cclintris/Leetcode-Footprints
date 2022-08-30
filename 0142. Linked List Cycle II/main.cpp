#include <iostream>
#include <unordered_map>
using namespace std;

/**
 * I: head = [3,2,0,-4], pos = 1
 * O: tail connects to node index 1
 *
 * I: head = [1,2], pos = 0
 * O: tail connects to node index 0
 *
 * I: head = [1], pos = -1
 * O: no cycle
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int _val) : val(x), next(NULL){};
};

ListNode *detectCycle(ListNode *head);

int main(int argc, char const *argv[]) {
    return 0;
}

// Brute
ListNode *detectCycle(ListNode *head) {
    if (!head) return NULL;
    unordered_map<ListNode *, int> mp;
    while (head != NULL) {
        mp[head] = 1;
        head = head->next;
        if (mp[head]) return head;
    }
    return NULL;
}

// Floyd's tortoise and hare
// 1.Initially take two pointers, fast and slow. The fast pointer takes two steps ahead while the slow pointer will take a single step ahead for each iteration.
// 2.We know that if a cycle exists, fast and slow pointers will collide.
// 3.If the cycle does not exist, the fast pointer will move to NULL
// 4.Else, when both slow and fast pointer collides, it detects a cycle exists.
// 5.Take another pointer, say entry. Point to the very first of the linked list.
// 6.Move the slow and the entry pointer ahead by single steps until they collide.
// 7.Once they collide we get the starting node of the linked list.

// Optimized
ListNode *detectCycle(ListNode *head) {
    if (!head) return NULL;
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) {
            ListNode *entry = head;
            while (entry != slow) {
                entry = entry->next;
                slow = slow->next;
            }
            return slow;
        }
    }
    return NULL;
}
