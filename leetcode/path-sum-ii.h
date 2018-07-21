/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
*/

class Solution {
public:
    typedef vector<int> VI;
    typedef vector<VI> VVI;
    // typedef unordered_map<TreeNode *, int> UMT;
    int data[10000];
    VVI ans;
    int target;
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        ans.clear();
        target = sum;
        dfs(root, 0, 0);
        return ans;
    }

    void dfs(TreeNode *root, int i, int sum) {
        if (!root) return;
        sum += root->val;
        data[i] = root->val;
        if (target==sum && !root->left && !root->right) {
            vector<int> tmp(data, data+i+1);
            ans.push_back(tmp);
            return;
        }
        if (root->left)
            dfs(root->left, i+1, sum);
        if (root->right)
            dfs(root->right, i+1, sum);
    }
    
};