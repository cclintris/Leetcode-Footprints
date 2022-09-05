#include <iostream>
#include <unordered_set>
using namespace std;

/**
 * I: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
 * O: Intersected at '8'
 *
 * I: intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
 * O: Intersected at '2'
 *
 * I: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
 * O: No intersection
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);

int main(int argc, char const *argv[]) {
    return 0;
}

// Brute force using Hashset
// Using extra hashset space
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    unordered_set<ListNode *> set;
    while (headA) {
        set.insert(headA);
        headA = headA->next;
    }
    while (headB) {
        if (set.find(headB) != set.end())
            return headB;
        headB = headB->next;
    }
    return NULL;
}

// Optimal solutions
// Intuition: For two equal lengthed linkedlist, if there is an intersection
// then, there they would definitely end same.
// https://www.youtube.com/watch?v=D0X0BONOQhI
// Basically impossible to think of.
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int lenA = 0, lenB = 0;
    ListNode *tmpA = headA, *tmpB = headB;
    while (headA) {
        lenA++;
        headA = headA->next;
    }
    while (headB) {
        lenB++;
        headB = headB->next;
    }
    if (lenA > lenB) {
        int diff = lenA - lenB;
        while (diff > 0) {
            tmpA = tmpA->next;
            diff--;
        }
    }
    if (lenB > lenA) {
        int diff = lenB - lenA;
        while (diff > 0) {
            tmpB = tmpB.next;
            diff--;
        }
    }
    while (tmpA && tmpB) {
        if (tmpA == tmpB) return tmpA;
        tmpA = tmpA->next;
        tmpB = tmpB->next;
    }
    return NULL;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *l1 = headA, *l2 = headB;
    while (l1 != l2) {
        if (l1 == NULL)
            l1 = headB;
        else
            l1 = l1->next;
        if (l2 == NULL)
            l2 = headA;
        else
            l2 = l2->next;
    }
    return l1;
}
