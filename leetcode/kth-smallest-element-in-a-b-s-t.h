/**

Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

Hint:

Try to utilize the property of a BST.
What if you could modify the BST node's structure?
The optimal runtime complexity is O(height of BST).

*/

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if (root == nullptr) return -1;
        stack<TreeNode *> s;
        while (root || !s.empty()) {
            while (root) {
                s.push(root);
                root = root->left;
            }
            if (!s.empty()) {
                TreeNode *cur = s.top(); s.pop();
                if (--k == 0) return cur->val;
                root = cur->right;
            }
        }
        return root->val;
    }
};