/*
Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes 
of the first two lists.
*/

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(0);
        ListNode *head = &dummy;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                head->next = l1;
                l1 = l1->next;
            }
            else {
                head->next = l2;
                l2 = l2->next;
            }
            head = head->next;
        }
        while (l1) {
            head->next = l1;
            head = head->next;
            l1 = l1->next;
        }
        while (l2) {
            head->next = l2;
            head = head->next;
            l2 = l2->next;
        }
        return dummy.next;
    }
};