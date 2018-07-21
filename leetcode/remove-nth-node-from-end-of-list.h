/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
*/

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (!head || n<1) return head;
        vector<pair<int, ListNode*> > arr;
        ListNode *curr = head;
        int index = 0;
        while (curr) {
            arr.push_back(make_pair(index, curr));
            curr = curr->next;
            index++;
        }
        arr.push_back(make_pair(index, curr));
        int i = (int)arr.size() - n -1;
        if (i == 0) {
            ListNode *tmp = head->next;
            delete head;
            head = tmp;
        }
        else {
            arr[i].second->next = NULL;
            delete arr[i].second;
            arr[i-1].second->next = arr[i+1].second;
        }
        arr.clear();
        return head;
    }
};