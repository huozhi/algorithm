/**

Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        int slen = s.length(), tlen = t.length();
        if (slen != tlen)
            return false;
        int hash[256];
        memset(hash, 0, sizeof hash);
        for (char c : s) hash[c]++;
        for (int i = 0; i < tlen; i++) {
            if (hash[ t[i] ] > 0) {
                hash[ t[i] ]--;
                slen--;
            }
            else {
                return false;
            }
        }
        return slen == 0;
    }
};