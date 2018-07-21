/*
Given a sorted linked list, delete all nodes that have duplicate numbers, 
leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*/

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head) return head;
        ListNode* start = head, *end = head;
        ListNode dummy(0), *curr = &dummy;
        while (end) {
            while (end && start->val == end->val)
                end = end->next;
            if (start->next == end) {
                curr->next = start;
                curr = curr->next;
            }
            start = end;
        }
        curr->next = nullptr;
        return dummy.next;
    }
};