/**
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.

Tags:
Linked List

 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        int lenA = 1, lenB = 1;
        ListNode *pA = headA, *pB = headB;
        while (pA->next && pA->next!=headA) {
            ++lenA;
            pA = pA->next;
        }
        while (pB->next && pB->next!=headB) {
            ++lenB;
            pB = pB->next;
        }
        if (pB != pA) return NULL;
        pA = headA, pB = headB;
        if (lenA >= lenB) {
            for (int i = 0; i < lenA - lenB; i++) pA = pA->next;
        }
        else {
            for (int i = 0; i < lenB - lenA; i++) pB = pB->next;
        }

        while (pA != pB) {
            pA = pA->next;
            pB = pB->next;
        }
        return pA;
    }
};