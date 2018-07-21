/*
Sort a linked list in O(n log n) time using constant space complexity.

Merge Sort  O(n log n)
Shell Sort  O(n log^2 n)
Select Sort O(n^2)
*/

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (!head || !head->next) {
            return head;
        }
        else {
            ListNode *fast = head, *slow = head;
            while (fast->next && fast->next->next) {
                fast = fast->next->next;
                slow = slow->next;
            }
            fast = slow;
            slow = slow->next;
            fast->next = NULL;
            fast = sortList(head);
            slow = sortList(slow);
            return mergeList(fast, slow);
        }
    }

    ListNode *mergeList(ListNode *A, ListNode *B) {
        ListNode dummy(0);
        ListNode *p = &dummy;
        while (A && B) {
            if (A->val < B->val) {
                p->next = A;
                A = A->next;
            }
            else {
                p->next = B;
                B = B->next;
            }
            p = p->next;
        }
        while (A) { p->next = A; A = A->next; p = p->next; }
        while (B) { p->next = B; B = B->next; p = p->next; }
        return dummy.next;
    }

};
