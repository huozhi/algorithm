/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
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
    struct cmp {
        bool operator() (ListNode* a, ListNode* b) {
            return a->val > b-> val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode *>, cmp> que;
        for (auto head : lists) {
            if (head) que.push(head);
        }
        
        ListNode dummy = ListNode(0);
        ListNode *tail = &dummy;

        while (!que.empty()) {
            ListNode *node = que.top();
            tail->next = node;
            tail = tail->next;
            que.pop();
            if (node->next) {
                que.push(node->next);
            }    
        }
        
        while (!que.empty()) {
            tail->next = que.top();
            que.pop();
            tail = tail->next;
        }
        return dummy.next;
    }
};

