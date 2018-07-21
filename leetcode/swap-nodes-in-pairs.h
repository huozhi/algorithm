/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.
Given 1->2->3   , you should return the list as 2->1->3.
Your algorithm should use only constant space.
You may not modify the values in the list, only nodes itself can be changed.
*/


class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode oddlist(0), evenlist(0), dummy(0);
        ListNode* curr = &dummy, *odd = &oddlist, *even = &evenlist;
        bool isOdd = true;
        while (head) {
            if (isOdd) {
                odd->next = head;
                odd = odd->next;
            }
            else {
                even->next = head;
                even = even->next;
            }
            head = head->next;
            isOdd = !isOdd;
        }
        odd->next = even->next = nullptr;
        even = evenlist.next;
        odd = oddlist.next;

        while (even && odd) {
            curr->next = even;
            curr = curr->next;
            even = even->next;
            curr->next = odd;
            curr = curr->next;
            odd = odd->next;
        }
        if (odd) {
            curr->next = odd;
            odd = odd->next;
            curr = curr->next;
        }
        curr->next = nullptr;
        return dummy.next;
    }
};