/*
Given a list, 
rotate the list to the right by k places, 
where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
*/

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head || !head->next) return head;

        int len = 1;
        ListNode *pend = head;
        while (pend->next) {
            pend = pend->next;
            ++len;
        }
        ListNode *pk = head;
        k = (len - (k % len)) % len;
        if (k == 0) return head;
        for (int i = 1; i < k; i++) {
            pk = pk->next;
        }
        ListNode *newHead = pk->next;
        pk->next = 0;
        pend->next = head;
        return newHead;
    }
};