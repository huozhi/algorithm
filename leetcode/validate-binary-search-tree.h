/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
*/

class Solution {
public:
    bool isValidBST(TreeNode *root) {
        if (!root) return true;
        vector<int> values;
        inOrder(root, values);
        for (int i = 0; i < (int)values.size()-1; i++) {
            if (values[i] >= values[i+1]) return false;
        }
        return true;
    }
    
    void inOrder(TreeNode *root, vector<int>& v) {
        if (root) {
            inOrder(root->left, v);
            v.push_back(root->val);
            inOrder(root->right, v);
        }
    }
};