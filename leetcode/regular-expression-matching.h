/*
'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true

Note:
corner cases:
s = "abbc", p = "ab*bbc"
s = "ac", p = "ab*c"
s = "abbbc", p = "ab*c"
s = "abcbcd", p = "a.*c.*d"
s = "ab", p = ".*c"
s = "aaa", p = "ab*ac*c"
lessons paid with blood....

Solution 1:
DP

Solution 2:
Recursion
*/

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        int slen = strlen(s), plen = strlen(p);
        vector<vector<bool> > dp(slen+1, vector<bool>(plen+1, false));
        dp[0][0] = true;
        for (int j = 1; j <= plen; j++) {
            if (j>=2 && p[j-1]=='*')
                dp[0][j] = dp[0][j-2];
        }
        for (int i = 1; i <= slen; i++) {
            for (int j = 1; j <= plen; j++) {
                if (p[j-1]=='.' || s[i-1]==p[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else if (p[j-1] == '*') {
                    dp[i][j] = dp[i][j-1] || dp[i][j-2]; // match a char in p or ignore p
                    if (s[i-1]==p[j-2] || p[j-2]=='.')
                        dp[i][j] = dp[i][j] || dp[i-1][j]; // match a '.'
                }
            }
        }
        return dp[slen][plen];
    }
};
  

class Solution {
public:  
    bool isMatch(const char *s, const char *p) {
        if (*p=='\0')
            return *s=='\0';
        if (*(p+1) == '*') {
            while (*s==*p || (*p=='.' && *s)) {
                if (isMatch(s, p+2)) return true;
                s++;
            }
            // if *s == '\0'
            return isMatch(s, p+2);
        }
        if (*s==*p || (*p=='.' && *s))
            return isMatch(s+1, p+1);
        return false;
    }
};