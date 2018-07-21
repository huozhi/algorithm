/*
Given a binary tree, determine if it is height-balanced.

For this problem,a height-balanced binary tree is defined
as a binary tree in which the depth of the two subtrees of
every node never differ by more than 1.
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
    bool isBalanced(TreeNode *root) {
        int height = 0;
        return isAVL(root, height);
    }
    
    bool isAVL(TreeNode *node, int &height) {
        if (!node) {
            height = 0;
            return true;
        }
        int left_h;
        bool left_b = isAVL(node->left, left_h);
        int right_h;
        bool right_b = isAVL(node->right, right_h);
        if (left_b && right_b && abs(left_h - right_h)<=1) {
            height = max(left_h, right_h) + 1;
            return true;
        }
        else {
            height = max(left_h, right_h) + 1;
            return false;
        }
    }
};