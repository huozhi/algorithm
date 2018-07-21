/*
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
*/


/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */



class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        deque<TreeLinkNode *> level;
        level.push_back(root);
        TreeLinkNode *cur = level.front(), *head;
        while (!level.empty()) {
            head = level.front();
            level.push_back(NULL);
            while (level.front()) {
                cur = level.front();
                level.pop_front();
                cur->next = level.front(); // null at end
                if(cur->left) level.push_back(cur->left);
                if(cur->right) level.push_back(cur->right);
            }
            level.pop_front(); // pop null
        }
    }
};