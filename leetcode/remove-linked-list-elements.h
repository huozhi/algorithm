/**
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.

*/

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0), *curr = &dummy;
        while (head) {
            if (head->val != val) {
                curr->next = head;
                curr = curr->next;
            }
            head = head->next;
        }
        curr->next = nullptr;
        return dummy.next;
    }
};
