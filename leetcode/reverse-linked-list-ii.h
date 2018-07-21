/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (!head || m==n) return head;
        int i = 0;
        ListNode *curr = head, *prev=NULL, *start, *start_next, *end, *end_next;
        for (; i < n-1; i++, prev=curr, curr=curr->next) {
            if (i == m-1) {
                start = prev;
                start_next = curr;                
            }
        }
        end = curr; end_next = end->next;
        prev = start_next; curr = prev->next;
        
        // reverse
        while (prev != end) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        if (start)
            start->next = end;
        else
            head = end;

        start_next->next = end_next;
        return head;
    }
};