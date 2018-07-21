/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
*/

class Solution {
public:
    int numDecodings(string s) {
        vector<int> ans(s.size()+1, 0);
        if (s.empty()) return 0;
        ans[0] = 1;
        if (s[0] == '0')
            ans[1] = 0;
        else
            ans[1] = 1;
        for (int i=2; i<=s.size(); i++) {
            int pre = s[i-2]-'0';
            int cur = s[i-1]-'0';
            int val = pre*10 + cur;
            if (cur>=1 && cur<=9)
                ans[i] = ans[i-1];
            if ((pre != 0) && (val>=1 && val<=26))
                ans[i] += ans[i-2];
        }
        return ans[s.size()];
    }

};
