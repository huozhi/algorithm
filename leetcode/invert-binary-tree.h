/**

Invert a binary tree.

     4
   /   \
  2     7
 / \   / \
1   3 6   9

to
     4
   /   \
  7     2
 / \   / \
9   6 3   1

Trivia:
This problem was inspired by this original tweet by Max Howell:
Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so fuck off.

*/

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root)
            return nullptr;
        TreeNode *tmp = root->left;
        root->left = root->right;
        root->right = tmp;

        if (root->left) invertTree(root->left);
        if (root->right) invertTree(root->right);
        return root;
    }
};