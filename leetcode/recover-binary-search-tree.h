/**
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward.
Could you devise a constant space solution?
confused what "{1,#,2,3}" means? > read more on how binary tree is
serialized on OJ.
*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */



class Solution {
public:
    TreeNode *pre, *p1, *p2;
    void recoverTree(TreeNode *root) {
        if (!root) return;
        pre = p1 = p2 = NULL;
        inOrderTraverse(root);
        swap(p1->val, p2->val);
    }
    
    void inOrderTraverse(TreeNode *root) {
        if (root) {
            inOrderTraverse(root->left);
            if (pre && pre->val > root->val) {
                if (!p1) {
                    p1 = pre; p2 = root;
                }
                else
                    p2 = root;
            }
            pre = root;
            inOrderTraverse(root->right);
        }
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode *> v;
        inorder(root, v);
        
        for (int i = 1; i < v.size(); i++) {
            int k = i;
            while (k > 0 && v[k]->val < v[k - 1]->val) {
                swap(v[k]->val, v[k - 1]->val);
                k--;
            }
        }
    }
    
    void inorder(TreeNode* root, vector<TreeNode *> &v) {
        if (root) {
            inorder(root->left, v);
            v.push_back(root);
            inorder(root->right, v);
        }
    }
};

