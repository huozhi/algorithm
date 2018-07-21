/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/

class Solution {
public:
    int cuts;
    vector<vector<bool> > pali;

    void palindrome(string s) {
        pali.assign(s.size(), vector<bool>(s.size(), false));
        for (int len = 1; len <= s.size(); len++) {
            for (int start = 0; start < s.size(); start++) {
                int end = start + len -1;
                if (end >= s.size()) continue;
                if (start == end) {
                    pali[start][end] = true;
                }
                else if (start == end-1) {
                    pali[start][end] = (s[start] == s[end]);
                }
                else {
                    pali[start][end] = (pali[start+1][end-1] && s[start]==s[end]);
                }
            }
        }
    }

    int minCut(string s) {
        palindrome(s);
        vector<int> cuts(s.size(), (int)s.size()-1); //IMPORTANT
        cuts[0] = 0;
        for (int k = 1; k < s.size(); k++) {
            if (pali[0][k])
                cuts[k] = 0;
            for (int p = 0; p < k; p++) {
                if (pali[p+1][k])
                    cuts[k] = min(cuts[p]+1, cuts[k]);
                // [0,k] is combined with [0,p] and [p,k]
            }
        }
        return cuts.back();
    }
};