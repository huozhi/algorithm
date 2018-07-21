/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    Node* prev = NULL;
    Node* next = NULL;
    Node* child = NULL;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        stack<Node *> stk;
        Node dummy = Node(0, NULL, NULL, NULL);
        Node *tail = &dummy;
        
        if (head) stk.push(head);
        while (!stk.empty()) {
            Node *curr = stk.top();
            stk.pop();
            tail->next = curr;
            curr->prev = tail;
            
            while (curr && !(curr->child)) {
                curr = curr->next;
                tail = tail->next;
            }
            if (curr && curr->child) {
                Node *next = curr->next;
                if (next) {
                    next->prev = NULL;
                    stk.push(next);
                }

                Node *child = curr->child;
                curr->next = child;
                child->prev = curr;
                curr->child = NULL;
                tail = tail->next;
                stk.push(child);
            }
        }
        
        if (head) head->prev = NULL;
        return dummy.next;
    }
};
