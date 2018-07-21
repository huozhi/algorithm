/*
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
click to show hints.

Hints:
If you notice carefully in the flattened tree, each node's right child points 
to the next node of a pre-order traversal.
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
    void flatten(TreeNode *root) {
        if (root) {
            if (root->left) {
                TreeNode *temp = root->right;
                root->right = root->left;
                TreeNode *rightmost = root->left; // new_tree_rightmost
                while (rightmost->right) rightmost = rightmost->right;
                rightmost->right = temp;
                root->left = NULL;
            }
            flatten(root->right);
        }
    }
};