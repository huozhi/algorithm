/*
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.

Note:

Solution 1:
Recursion

Solution 2:
3-dim DP (what a godlike solution it was...)

*/

class Solution {
public:
    bool isScramble(string s1, string s2) {
        return isScrambleRecur(s1, s2);
    }

    bool isScrambleRecur(string &s1, string &s2) {
        if (s1 == s2)
            return true;
        string cp1 = s1, cp2 = s2;
        sort(cp1.begin(), cp1.end());
        sort(cp2.begin(), cp2.end());
        if (cp1 != cp2) // contains different characters
            return false;
        int len = s1.length();
        for (int i = 1; i < len; i++) {
            string LS1 = s1.substr(0, i), RS1 = s1.substr(i);
            string LS2 = s2.substr(0, i), RS2 = s2.substr(i);
            // found
            if (isScrambleRecur(LS1, LS2) && isScramble(RS1, RS2))
                return true;
            // do swap
            LS2 = s2.substr(0, len-i), RS2 = s2.substr(len-i);
            if (isScrambleRecur(LS1, RS2) && isScramble(LS2, RS1))
                return true;
        }
        // unfound any partitions matched
        return false;
    }

    /*
    bool isScramble(string s1, string s2) {
        const int len = s1.size();
        bool dp[len+1][len][len];
        
        for (int i = 0; i < len; i++)
            for (int j = 0; j < len; j++)
                dp[1][i][j] = (s1[i] == s2[j]);
        
        // k for length
        for (int k = 2; k <= len; k++) {
            // i for index of s1
            for (int i = 0; i <= len-k; i++) {
                // j for index of s2
                for (int j = 0; j <= len-k; j++) {
                    // p for partition
                    dp[k][i][j] = false;
                    for (int p = 1; p<k && !dp[k][i][j]; p++) {
                        dp[k][i][j] = (dp[p][i][j] && dp[k-p][i+p][j+p])
                        || (dp[p][i][k-p+j] && dp[k-p][i+p][j]);
                    }
                }
            }
        }
        return dp[len][0][0];
    }
    */
};

