/*
Given a linked list and a value x, partition it such that all nodes less than
 x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
*/

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode L(0), G(0); // less and greater or equal to
        ListNode *pl = &L, *pg = &G;
        for (ListNode *h = head; h; h = h->next) {
            if (h->val < x) {
                pl->next = h;
                pl = pl->next;
            }
            else {
                pg->next = h;
                pg = pg->next;
            }
        }
        pl->next = pg->next = NULL;
        if (!L.next) return G.next;
        pl->next = G.next;
        return L.next;
    }
};