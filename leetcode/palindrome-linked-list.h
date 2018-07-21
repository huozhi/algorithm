/**

Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?

*/

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        ListNode* fast = head, *slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow->next;
        slow->next = nullptr;
        fast = reverseList(fast);
        slow = head;
        if (!fast) return false;

        while (slow && fast) {
            if (slow->val != fast->val)
                return false;
            slow = slow->next;
            fast = fast->next;
        }
        return true;
    }

    ListNode* reverseList(ListNode* head) {
        if (!head)
            return nullptr;
        ListNode res(0);
        ListNode* curr = head, *next, *temp;
        while (curr) {
            next = curr->next;
            temp = res.next;
            res.next = curr;
            res.next->next = temp;
            curr = next;
        }
        return res.next;
    }
};