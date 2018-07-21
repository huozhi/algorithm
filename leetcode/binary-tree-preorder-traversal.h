/*
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> v;
        if (!root) return v;
        stack<TreeNode *> stk;
        TreeNode *cur = root;
        
        while (cur || !stk.empty()) {
            if (cur) {
                v.push_back(cur->val);
                stk.push(cur);
                cur = cur->left;
            }
            else {
                // finish visited left child tree
                cur = stk.top(); stk.pop(); // trace back to parent node
                cur = cur->right;
            }
        }
        return v;
    }
};