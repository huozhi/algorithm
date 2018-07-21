/**

Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].

BFS or DFS

*/

class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> ans;
        queue<TreeNode *> q; // level bfs
        int last;
        if (!root) return ans;
        q.push(root);
        q.push(nullptr);
        TreeNode *t;
        while (!q.empty()) {
            if (q.front()) {
                while (!q.empty() && q.front()) {
                    t = q.front();
                    last = t->val;
                    if (t->left) q.push(t->left);
                    if (t->right) q.push(t->right);
                    q.pop();
                }
            }
            else {
                ans.push_back(last);
                q.pop();
                if (!q.empty()) q.push(nullptr);
            }
        }
        return ans;
    }
};