/**

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4
For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.

*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        return (left && right) ? root : (left ? left : right);
    }
};


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || !p || !q) return root;
        vector<TreeNode *> ppath, qpath;
        dfs(root, p, ppath);
        dfs(root, q, qpath);
        int n = min(ppath.size(), qpath.size());
        TreeNode *res = nullptr;
        for (int i = 0; i < n; i++) {
            if (qpath[i] == ppath[i])
                res = ppath[i];
            else
                break;
        }
        return res;
    }

    bool dfs(TreeNode* root, TreeNode *node, vector<TreeNode *>& path) {
        if (root == nullptr)
            return false;
        path.push_back(root);
        if (root == node) {
            path.push_back(node);
            return true;
        }
        if (dfs(root->left, node, path))
            return true;

        if (dfs(root->right, node, path))
            return true;
        path.pop_back();
        return false;
    }
};

