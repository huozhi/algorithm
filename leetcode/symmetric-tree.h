/*
Given a binary tree, check whether it is a mirror of itself
(ie, symmetric around its center).

For example, this binary tree is symmetric:

   1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.

confused what "{1,#,2,3}" means?


OJ's Binary Tree Serialization:
The serialization of a binary tree follows a level order traversal, 
where '#' signifies a path terminator where no node exists below.

Here's an example:
   1
  / \
 2   3
    /
   4
    \
     5
The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".
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
    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        return isSymmetric(root->left, root->right);
    }
    // aux
    bool isSymmetric(TreeNode *a, TreeNode *b) {
        if (a && b) {
            if (a->val == b->val) {
                return isSymmetric(a->left, b->right) && isSymmetric(a->right, b->left);
            }            
        }
        else if (!a && !b) return true;
        return false;
    }
};