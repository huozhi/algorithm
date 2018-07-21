/*
mplement strStr().

Returns a pointer to the first occurrence of needle in haystack, 
or null if needle is not part of haystack.
*/

class Solution {
public:
    // KMP
    int strStr(char *haystack, char *needle) {
        int plen = strlen(needle);
        int slen = strlen(haystack);
        int next[plen];
        memset(next, -1, sizeof next);
        
        int i = 0, j = -1;
        while (i < plen) {
            if (j == -1 || needle[i] == needle[j]) {
                next[i] = j;
                i++; j++;
            }
            else
                j = next[j]; // backward
        }

        i = 0; j = 0;
        while (i < slen && j < plen) {
            if (haystack[i] == needle[j]) {
                i++; j++;
            }
            else if (j == 0) // if unmatched and pattern is at start
                i++;
            else // if unmatched and pattern is not at start, traceback by kmp
                j = next[j - 1] + 1;
            
        }
        return j == plen ? i - plen : -1;
    }

    // brute force
    int strStr(char *haystack, char *needle) {
        int slen = strlen(haystack), plen = strlen(needle);
        if (!haystack || !needle || plen == 0) return 0;
        if (slen < plen) return -1;
        for (int i = 0; i <= slen - plen; i++) {
            bool found = true;
            for (int j = 0; j < plen; j++) {
                if (haystack[i + j] != needle[j]) {
                    found = false;
                    break;
                }
            }
            if (found) return i;
        }
        return -1;
    }
};

