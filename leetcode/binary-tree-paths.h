/**

Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]

*/

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> results;
        dfsPath(results, root, string());
        return results;
    }

    void dfsPath(vector<string>& results, TreeNode *root, string path) {
        if (!root) {
            if (!path.empty())
                results.push_back(path);
            return;
        }
        int val = root->val;
        if (!path.empty()) {
            path.append("->");
        }

        path.append(std::to_string(val));
        if (!root->left && !root->right) {
            if (!path.empty())
                results.push_back(path);
            return;
        }

        if (root->left)
            dfsPath(results, root->left, path);

        if (root->right)
            dfsPath(results, root->right, path);
    }
};

