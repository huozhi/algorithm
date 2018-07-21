class Solution {
public:
    int minDepth(TreeNode *root) {
        if (!root) return 0;
        return recur(root);
    }
    
    int recur(TreeNode *root) {
        int lh, rh;
        if (!root->left && !root->right)
            return 1;
        if (root->left && !root->right)
            return 1 + recur(root->left);
        else if (!root->left && root->right)
            return 1 + recur(root->right);
        lh = 1 + recur(root->left);
        rh = 1 + recur(root->right);
        return (lh < rh) ? lh : rh;
    }
};