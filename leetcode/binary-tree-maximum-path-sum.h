/*
Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.
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
    int pathRecur(TreeNode *root, int &maxSum) {
        if (root) {
            int leftVal  = max(pathRecur(root->left, maxSum), 0);
            int rightVal = max(pathRecur(root->right, maxSum), 0);
            int rootVal  = root->val;
            rootVal += (leftVal + rightVal);
            maxSum = max(rootVal, maxSum);
            return max(root->val+leftVal, root->val+rightVal);
        }
        return 0;
    }

    int maxPathSum(TreeNode *root) {
        if (!root) return 0;
        int maxSum = INT_MIN;
        pathRecur(root, maxSum);
        return maxSum;
    }
};
