/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
*/

class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return construct(preorder, inorder,
                         0, (int)preorder.size() - 1,
                         0, (int)inorder.size() - 1);
    }

    TreeNode *construct(vector<int> &pre, vector<int> &in,
                    int pstart, int pend, int istart, int iend) {
        if (pstart > pend || istart > iend)
            return nullptr;
        int val = pre[pstart];
        int sentinel = find(in.begin() + istart, in.begin() + iend, val) - in.begin();
        TreeNode *root = new TreeNode(val);
        root->left = construct(pre, in,
                               pstart + 1, pstart + sentinel - istart,
                               istart, sentinel - 1);
        root->right = construct(pre, in,
                                pstart + sentinel - istart + 1, pend,
                                sentinel + 1, iend);
        return root;
    }
};