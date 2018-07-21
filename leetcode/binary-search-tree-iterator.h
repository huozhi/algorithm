/*

Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.

*/


class BSTIterator {
public:
    stack<TreeNode *> S;
    TreeNode *cur;

    BSTIterator(TreeNode *root) {
        // clear
        while (!S.empty()) S.pop();
        cur = NULL;

        // initialize
        if (root) {
            cur = root;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return cur || !S.empty();
    }

    /** @return the next smallest number */
    int next() {
        while (cur) {
            S.push(cur);
            cur = cur->left;
        }
        if (!S.empty()) {
            cur = S.top();
            int ret = cur->val;
            S.pop();
            cur = cur->right;
            return ret;
        }
        return INT_MAX;
    }
};


/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */