/**

Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.

*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length())
            return false;
        int sm[256], tm[256];
        memset(sm, 0, sizeof sm);
        memset(tm, 0, sizeof tm);
        int n = s.length();
        for (int i = 0; i < n; i++) {
            int si = s[i], ti = t[i];
            if (sm[si] || tm[ti]) {
                if (sm[si] != ti || tm[ti] != si)
                    return false;
            }
            else {
                sm[si] = ti;
                tm[ti] = si;
            }
        }
        return true;
    }
};