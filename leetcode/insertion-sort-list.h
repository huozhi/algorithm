/*
Sort a linked list using insertion sort.
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
    ListNode *insertionSortList(ListNode *head) {
        if (!head) return head;
        ListNode *new_head = head;
        for (ListNode *i = new_head; i && i->next; ) {
            if (i->val > i->next->val) {
                ListNode *tmp = i->next;
                i->next = i->next->next;
                
                for (ListNode *k = new_head, *pre = NULL; k != i->next; pre=k, k=k->next) {
                    if (k->val > tmp->val) {
                        if (pre) pre->next = tmp;
                        else new_head = tmp;
                        tmp->next = k;
                        break;
                    }
                }
            }
            else  i=i->next;
        }
        return new_head;
    }
};