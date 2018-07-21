/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. 
(ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
*/

class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > ans;
        vector<int> level;
        queue<TreeNode *> trav;
        if (!root) return ans;
        trav.push(root);
        trav.push(NULL);
        int L = 1;
        while (trav.front() && !trav.empty()) {
            while (trav.front()) {
                TreeNode *curr = trav.front();
                if (L) {
                    level.push_back(curr->val);
                }
                else {
                    level.insert(level.begin(), curr->val);
                }
                if (curr->left) trav.push(curr->left);
                if (curr->right) trav.push(curr->right);
                trav.pop();
            }
            ans.push_back(level);
            L = !L;
            level.clear();
            trav.pop();
            trav.push(NULL);
        }
        return ans;
    }
};