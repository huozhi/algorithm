/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path
such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
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
    bool hasPathSum(TreeNode *root, int sum) {
        if(!root) return false;
        return equalSum(root,0,sum);
    }
    
    bool equalSum(TreeNode *node, int sum, const int give_sum) {
        if (!node) {
            return false;
        }
        else {
            if (!node->left && !node->right) {
                if (sum + node->val == give_sum)
                    return true;
            }
        }
        bool l = equalSum(node->left, node->val + sum, give_sum);
        bool r = equalSum(node->right, node->val + sum, give_sum);
        return l || r;
    }
};