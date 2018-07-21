/**

Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

For example, you may serialize the following tree

    1
   / \
  2   3
     / \
    4   5
as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.

*/

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string encode;
        if (!root) {
            return encode;
        }
        queue<TreeNode *> q;
        TreeNode *curr;
        q.push(root);

        while (!q.empty()) {
            curr = q.front();
            q.pop();
            if (curr) {
                q.push(curr->left);
                q.push(curr->right);
                int val = curr->val;
                encode.append(to_string(val));
            }
            else {
                encode.append("null");
            }
            encode.push_back(' ');
        }
        return encode;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty())
            return nullptr;
        stringstream ss(data);
        string temp;
        vector<TreeNode *> nodes;
        vector<int> index;
        while (ss >> temp) {
            if (index.empty())
                index.push_back(0);
            else
                index.push_back(index.back());
            if (temp != "null") {
                nodes.push_back(new TreeNode(stoi(temp)));
            }
            else {
                nodes.push_back(nullptr);
                index.back()++;
            }
        }
        int len = nodes.size();
        for (int i = 0; i < len; i++) {
            if (nodes[i]) {
                nodes[i]->left = nodes[(i - index[i]) * 2 + 1];
                nodes[i]->right = nodes[(i - index[i]) * 2 + 2];
            }
        }
        return nodes[0];
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));