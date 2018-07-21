/**

everse a singly linked list.

click to show more hints.

Hint:
A linked list can be reversed either iteratively or recursively. Could you implement both?

*/

// iterative solution
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode dummy(0), *rhead = &dummy;
        ListNode *curr = head;
        while (curr) {
            ListNode *next = curr->next;
            ListNode *rnext = dummy.next;
            dummy.next = curr;
            curr->next = rnext;
            curr = next;
        }
        return dummy.next;
    }
};

// recursive solution

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode dummy(0);
        ListNode *rhead = &dummy;
        recur(head, rhead);
        rhead->next = nullptr;
        return dummy.next;
    }

    void recur(ListNode* node, ListNode* &rhead) {
        if (!node) {
            return;
        }
        recur(node->next, rhead);
        rhead->next = node;
        rhead = rhead->next;
    }
};

