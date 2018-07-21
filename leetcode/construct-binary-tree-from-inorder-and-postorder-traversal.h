/*
Given inorder and postorder traversal of a tree, construct the binary tree.
*/

class Solution {
public:
    typedef vector<int> VI;
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.empty()) return NULL;
        TreeNode *root;
        int len = (int)inorder.size() - 1;
        root = build(inorder, postorder, 0, len, 0, len);
        return root;
    }

    TreeNode *build(VI &in, VI &post, int is, int ie, int ps, int pe) {
        if (is>ie || ps>pe) return NULL;

        int j;
        for (j = is; j <= ie; j++) {
            if (in[j] == post[pe]) break;
        }
        TreeNode *root = new TreeNode(post[pe]);
        root->left  = build(in, post, is, j-1, ps, ps+j-is-1);
        root->right = build(in, post, j+1, ie, ps+j-is, pe-1);
        return root;
    }

};