/*
Given a string s and a dictionary of words dict, 
determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".

*/

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int len = s.length();
        bool seg[len + 1];
        seg[0] = true;
        for (int i = 1; i <= len; i++) {
            for (int j = 0; j < i; j++) {
                // string segmented by [0, j - 1] and [j, i - 1]
                seg[i] = seg[j] && dict.count(s.substr(j, i - j));
                if (seg[i]) break;
            }
        }
        return seg[len];
    }
};