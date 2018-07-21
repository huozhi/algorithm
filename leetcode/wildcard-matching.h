/*
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
*/

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        int slen = strlen(s), plen = strlen(p);
        int cnt = 0;
        const char *tmp = p;
        while (*tmp) if (*(tmp++) != '*') cnt++;
        if (cnt > slen) return false; // avoid MLE
        vector<vector<bool> > dp(slen+1, vector<bool>(plen+1, false));
        dp[0][0] = true;
        for (int j = 1; j <= plen; j++) {
            if (dp[0][j-1] && p[j-1]=='*') dp[0][j] = true; // a little bit hard to understand
            for (int i = 1; i <= slen; i++) {
                if (p[j-1] == '*')
                    dp[i][j] = (dp[i-1][j] || dp[i][j-1]);
                else if (p[j-1]=='?' || (s[i-1]==p[j-1]))
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = false;
            }
        }
        return dp[slen][plen];
    }
};