/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].
*/

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ans;
        stack<TreeNode *> stk;
        TreeNode *node = root;
        while (node || !stk.empty()) {
            while (node) {
                stk.push(node);
                node = node->left;
            }
            if (!stk.empty()) {
                node = stk.top();
                ans.push_back(node->val);
                stk.pop();
                node = node->right;
            }
        }
        return ans;
    }
};