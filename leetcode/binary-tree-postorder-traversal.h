/*

Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

*/

class Solution {
public:
    // Solution 1
    vector<int> postorderTraversal(TreeNode *root) {
        unordered_map<TreeNode *, bool> m; // mark the node if visited first time
        stack<TreeNode *> s;
        vector<int> ans;
        while (!s.empty() || root) {
            while (root) {
                s.push(root);
                m[root] = true;
                root = root->left;
            }
            if (!s.empty()) {
                TreeNode *curr = s.top();
                s.pop();
                if (m[curr]) {
                    s.push(curr);
                    root = curr->right;
                    m[curr] = false;
                }
                else {
                    ans.push_back(curr->val);
                    
                }
            }
        }
        return ans;
    }
};


// Solution 2
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ans;
        if (!root) return ans;
        stack<TreeNode *> s;
        s.push(root);

        TreeNode *curr, *prev = NULL;
        while (!s.empty()) {
            curr = s.top();
            // visit the none-children node or visit node with its children visted
            if (!curr->left && !curr->right ||
                prev && (prev==curr->left || prev==curr->right)) {
                ans.push_back(curr->val);
                s.pop();
                prev = curr;
            }
            else {
                if (curr->right) s.push(curr->right);
                if (curr->left) s.push(curr->left);
            }
        }
        return ans;
    }

};

