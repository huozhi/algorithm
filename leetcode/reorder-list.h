/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
*/

class Solution {
public:
    void reorderList(ListNode *head) {
        if (!head || !head->next) return;
        ListNode* fast = head, *slow = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *last = reverseList(slow);
        ListNode dummy(0), *curr = &dummy;
        while (head != slow) {
            curr->next = head;
            curr = curr->next;
            head = head->next;
            curr->next = last;
            curr = curr->next;
            last = last->next;
        }
        if (last) {
            curr->next = last;
            last = last->next;
            curr = curr->next;
        }
        curr->next = nullptr;
        head = dummy.next;
    }

    ListNode* reverseList(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode *prev = nullptr, *curr = head, *next = head->next;
        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};