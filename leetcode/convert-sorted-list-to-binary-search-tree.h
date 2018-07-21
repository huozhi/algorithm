/*
Given a singly linked list where elements are sorted in ascending order, 
convert it to a height balanced BST.
*/

class Solution {
public:
    ListNode *curr;
    TreeNode *sortedListToBST(ListNode *head) {
        curr = head;
        int len = length(head);
        return convert(0, len - 1);
    }
    
    TreeNode *convert(int begin, int end) {
        if (begin > end) return NULL;
        
        int mid = (end + begin + 1) / 2;
        TreeNode *lst = convert(begin, mid - 1); // left sub-tree
        TreeNode *root = new TreeNode(curr->val);
        curr = curr->next;
        root->left = lst;
        root->right = convert(mid + 1, end);
        return root;
    }    
    
    
    int length(ListNode *head) {
        int len = 0;
        for (ListNode *p = head; p; p=p->next, ++len);
        return len;
    }
};