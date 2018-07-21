/*
Given an array where elements are sorted in ascending order, 
convert it to a height balanced BST.
*/

class Solution {
public:
    TreeNode *addNode(vector<int> &num, int start, int end) {
        if (start <= end) {
            int mid = (start + end) / 2;
            TreeNode *root = new TreeNode(num[mid]);
            root->left  = addNode(num, start, mid-1);
            root->right = addNode(num, mid+1, end);
            return root;
        }
        return NULL;
    }
    
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return addNode(num, 0, num.size()-1);
    }
};