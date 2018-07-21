/*
A linked list is given such that each node contains an additional random pointer 
which could point to any node in the list or null.

Return a deep copy of the list.
*/


/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

class Solution {
public:
    typedef RandomListNode RN;
    RandomListNode *copyRandomList(RandomListNode *head) {
        RN *curr = head;
        while (curr) {
            RN *temp = curr->next;
            curr->next = new RN(curr->label);
            curr->next->next = temp;
            curr = temp;
        }
        for (RN *old=head; old; old=old->next->next) {
            RN *cpy = old->next;
            cpy->random = (old->random) ? old->random->next : NULL;
        }
        RN result(0), *pr = &result;
        for (RN *it=head; it; it=it->next) {
            pr->next = it->next;
            it->next = it->next->next;
            pr = pr->next;
        }
        return result.next;
    }
};