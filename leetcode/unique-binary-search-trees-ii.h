/*
Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

public:
    vector<TreeNode *> generateTrees(int n) {
        return gen(1, n);
    }


    vector<TreeNode *> gen(int start, int end) {
        if (start > end) {
            return vector<TreeNode *>(1, (TreeNode *)NULL);
        }

        vector<TreeNode *> ans;
        for (int k = start; k <= end; ++k) {

            vector<TreeNode *> leftSubtree  = gen(start, k-1);
            vector<TreeNode *> rightSubtree = gen(k+1, end);

            for (int l = 0; l < leftSubtree.size(); l++) {

                for (int r = 0; r < rightSubtree.size(); r++) {
                    TreeNode *root = new TreeNode(k);
                    root->left  = leftSubtree[l];
                    root->right = rightSubtree[r];
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
};