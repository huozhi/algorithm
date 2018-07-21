/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
*/

// bad solution
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode trash(0);
        ListNode *prev, *curr;
        trash.next = head;
        curr = head; prev = &trash;
        int i = 1;
        while (curr) {
            if (i % k == 0) {
                ListNode *p, *c, *n;
                ListNode *newPrev = prev->next;
                for (p=prev->next, c=p->next; p!=curr; ) {
                    n = c->next;
                    c->next = p;
                    p = c;
                    c = n;
                }
                prev->next->next = c;
                prev->next = p;
                curr = c;
                prev = newPrev;
            }
            else
                curr = curr->next;
            i++;
        }
        return trash.next;
    }
};


// ingenious solution
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (!head || k == 1) return head;
        ListNode dummy(0), *prev = &dummy;
        dummy.next = head;
        int i = 0;
        while (head) {
            ++i;
            if (i % k == 0) {
                prev = reverse(prev, head->next);
                head = prev->next;
            }
            else
                head = head->next;
        }
        return dummy.next;
    }

    ListNode *reverse(ListNode *prev, ListNode *finish) {
        ListNode *last = prev->next, *curr = last->next;
        while (curr != finish) {
            last->next = curr->next; // next node
            curr->next = prev->next; // reverse
            prev->next = curr; // insert first
            curr = last->next; // current = next
        }
        return last;
    }
};