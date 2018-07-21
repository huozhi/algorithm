/**

Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, 
and all nodes in the last level are as far left as possible. 
It can have between 1 and 2^h nodes inclusive at the last level h.

*/



// Solution 1, Recursion
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int lh = 0, rh = 0;
        TreeNode *pl = root, *pr = root;
        while (pl) { lh++; pl = pl->left; }
        while (pr) { rh++; pr = pr->right; }
        if (lh == rh)
            return (1 << lh) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

// Solution 2, Binary Search, Bit manpulation to fetch the node by order
class Solution {
public:
    TreeNode *fetchNode(TreeNode *root, int path, int depth) {
        while (depth-- && root) {
            if (path & (1 << depth)) {
                root = root->right;
            }
            else {
                root = root->left;
            }
        }
        return root;
    }

    int countNodes(TreeNode* root) {
        int depth = 0;
        TreeNode *pl = root;
        while (pl) {
            ++depth;
            pl = pl->left;
        }
        if (depth == 0) return 0;
        int low = 1 << (depth - 1), high = (1 << depth) - 1;
        while (low <= high) {
            int mid = (high - low) / 2 + low;
            if (fetchNode(root, mid, depth - 1)) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return high;
    }
};

