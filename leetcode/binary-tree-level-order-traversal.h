/*

Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > ans;
        if (!root) return ans;
        deque<TreeNode *> dq;
        dq.push_back(root);
        while (!dq.empty()) {
            vector<TreeNode *> temp(dq.begin(), dq.end());
            vector<int> values;
            dq.clear();
            for (auto &node : temp) {
                if (node->left) dq.push_back(node->left);
                if (node->right) dq.push_back(node->right);
                values.push_back(node->val);
            }
            ans.push_back(values);
        }
        return ans;
    }
};