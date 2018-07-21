/*
Given a string, find the length of the longest substring without repeating characters. 
For example, the longest substring without repeating letters for "abcabcbb" is "abc", 
which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[256];
        memset(hash, -1, sizeof(hash));
        const char *str = s.c_str();
        int len = strlen(str);
        int tmplen = 0, maxlen = 0, start = 0;
        for (int i = 0; i < len; i++) {
            if (hash[ str[i] ] == -1) {
                tmplen++;
            }
            else {
                start = max(start, hash[ str[i] ]); // back to new start
                tmplen = i - start; // calculate new length
            }
            hash[ str[i] ] = i;
            maxlen = max(maxlen, tmplen);
        }
        return maxlen;
    }

    // don't use to save start index
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int i = 0, j = 0;
        int maxlen = 0;
        bool exist[256] = { false };
        while (j < n) {
            if (exist[s[j]]) {
                maxlen = max(maxlen, j-i);
                while (s[i] != s[j]) {
                    exist[s[i]] = false;
                    i++;
                }
                i++;
                j++;
            } else {
                exist[s[j]] = true;
                j++;
            }
        }
        maxlen = max(maxlen, n-i);
        return maxlen;
    }
};