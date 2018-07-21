/*
Given a binary tree, return the bottom-up level order traversal of its 
nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
*/

class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > ans;
        if (!root) return ans;
        vector<int> level;
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty()) {
            que.push(NULL);
            level.clear();
            while (que.front()) {
                TreeNode *tmp = que.front();
                que.pop();
                level.push_back(tmp->val);
                if (tmp->left) que.push(tmp->left);
                if (tmp->right) que.push(tmp->right);
            }
            que.pop();
            ans.insert(ans.begin(), level);
        }
        return ans;
    }
};