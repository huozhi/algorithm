/*
Write a function to find the longest common prefix string amongst an array of strings.
*/

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0) return string("");
        string prefix = strs[0];

        if (strs.size() == 1) return prefix;
        for (int i = 1; i < strs.size(); i++) {
            int len = 0;
            for (int j = 0; j < prefix.size(); j++) {
                if (strs[i][j] == prefix[j]) {
                    ++len;
                }
                else {
                    break;
                }
            }
            prefix = prefix.substr(0, len);
        }
        return prefix;
    }
};