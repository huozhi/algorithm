class Solution {
public:
    void insert(ListNode*& node, int data) {
        if (!node)
            node = new ListNode(data);
        else {
            ListNode *cur = node;
            while (cur->next)
                cur = cur->next;
            cur->next = new ListNode(data);
        }
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *first1 = l1;
        ListNode *first2 = l2;
        ListNode *sum = NULL;
        int carry = 0;
        while (first1 && first2) {
            int temp = first1->val + first2->val + carry;
            if (temp > 9) {
                temp -= 10;
                carry = 1;
            }
            else {
                carry = 0;
            }
            insert(sum, temp);
            first1 = first1->next, first2 = first2->next;
        }
        while(first1) {
            int temp = first1->val + carry;
            if(temp > 9) {
                temp -= 10;
                carry = 1;
            }
            else
                carry = 0;
            insert(sum, temp);
            first1 = first1->next;
        }
        while(first2) {
            int temp = first2->val + carry;
            if(temp > 9) {
                temp -= 10;
                carry = 1;
            }
            else
                carry = 0;
            insert(sum, temp);
            first2 = first2->next;
        }
        if (carry)
            insert(sum, 1);

        return sum;
    }
};