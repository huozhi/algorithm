/*
Given a linked list, 
return the node where the cycle begins. 
If there is no cycle, return null.

Follow up:
Can you solve it without using extra space?
*/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        bool hasCycle = false;
        ListNode *fast = head, *slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                hasCycle = true;
                break;
            }
        }
        if (!hasCycle)
            return false;
        fast = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};


/*

assume that:
fast move steps 2s in sum, and for slow s in sum;
circle is r, n(n>0) is numbers of turns

we have:
s = 2s - nr(1), fast has reeled n times on circle

list length: l
from haed to enter: x
from enter to meet: y

s = x + y(2)

so:
s = nr(3)
s = x + y(4)
x + y = nr(5)

x = nr - y(6)

set step of two pointers into 1
when they meet at enter:
pointer1 moved x from head to enter
pointer2 moved y from meet to enter

*/