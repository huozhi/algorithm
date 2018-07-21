/*
Given s1, s2, s3, find whether s3 is formed by
the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
*/

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length()+s2.length() != s3.length()) return false;
        vector<vector<bool> > match(s1.size()+1, vector<bool>(s2.size()+1,false));
        match[0][0] = true;
        for (size_t i = 1; i <= s1.size(); i++)
            if (s1[i-1] == s3[i-1]) match[i][0] = true; else break;
        for (size_t i = 1; i <= s2.size(); i++)
            if (s2[i-1] == s3[i-1]) match[0][i] = true; else break;

        for (size_t i = 1; i <= s1.size(); i++) {
            for (size_t j = 1; j <= s2.size(); j++) {
                if (s1[i-1]==s3[i+j-1] && match[i-1][j]) {
                    match[i][j] = true;
                }
                if (s2[j-1]==s3[i+j-1] && match[i][j-1]) {
                    match[i][j] = true;
                }
            }
        }
        return match[s1.size()][s2.size()];
    }
};