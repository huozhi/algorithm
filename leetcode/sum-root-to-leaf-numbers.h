/**

Given a binary tree containing digits from 0-9 only, each root-to-leaf path 
could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.

*/

class Solution {
public:
    int sumNumbers(TreeNode *root) {
        return sumNumbers(root, 0);
    }

    int sumNumbers(TreeNode *root, int val) {
        if (root) {
            val = val * 10 + root->val;
            if (!root->left && !root->right)
                return val;
            else
                return sumNumbers(root->left, val) + sumNumbers(root->right, val);
        }
        return 0;
    }
};