/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the emtpy string "".

If there are multiple such windows, 
you are guaranteed that there will always be only one unique minimum window in S.Minimum Window Substring

Take care the cases:
S = "a", T = "a"
S = "a", T = "aa"

the ans's length may be same with T, S

I use the condition that minlen > 0 to ensure ans is changed,
but I was totally wrong because T may be unfound in S then minlen and minstart didn't change.
A trick to solve it is setting minstart into -1, and minlen into S.size()+1,
to keep sure that they have been changed
*/

class Solution {
public:
    string minWindow(string S, string T) {
        int found[256];
        int need[256];
        memset(found, 0, sizeof found);
        memset(need, 0, sizeof need);
        for (int i = 0; i < T.size(); i++)
            need[ T[i] ]++;
        string ans = "";
        size_t len = 0;
        size_t minstart = -1, minlen = S.size()+1;
        for (size_t i=0, j=0; i<S.size(); i++) {
            int c = S[i];
            if (need[c]) {
                ++found[c];
                if (found[c] <= need[c]) ++len;
                if (len == T.size()) {
                    while (need[ S[j] ]==0 || found[ S[j] ]>need[ S[j] ]) {
                        if (need[ S[j] ])
                            --found[ S[j] ];
                        ++j;
                    }
                    if (minlen > (i-j+1)) {
                        minlen = i-j+1;
                        minstart = j;
                    }
                }
            }
        }

        ans = (minstart != -1) ? S.substr(minstart, minlen) : "";
        return ans;
    }
};