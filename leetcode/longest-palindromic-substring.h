/*
Given a string S, find the longest palindromic substring in S. 
You may assume that the maximum length of S is 1000, and there 
exists one unique longest palindromic substring.


Note:
j is symmetric to i, j = id*2-i
*/

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size()==0) return s;
        string str;
        int len = s.size()*2+1;
        str.resize(len);
        str[0] = '#';
        for (int i = 0; i < (int)s.size(); i++) {
            str[i*2+1] = s[i];
            str[i*2+2] = '#';
        }
        int *p = new int[len];
        p[0] = 1;
        int mx=0;
        int id=1;
        for (int i = 1; i < len; i++) {
            if (mx > i)
                p[i] = min(p[id*2-i], mx-i);
            else
                p[i] = 1;
            while ((p[i]+i<len) && (i-p[i]>=0) && (str[i-p[i]]==str[i+p[i]])) p[i]++;
            if (p[i] + i > mx) {
                mx = i + p[i];
                id = i;
            }
        }
        int ans = 0;
        for (int i = 0; i < len; i++) {
            if (ans < p[i]) {
                ans = p[i];
                id = i;
            }
        }
        --ans; // real length
        string pli = "";
        if (str[id] != '#')
            pli += str[id];
        for (int i=1; i<ans; i++) {
            if (str[id+i] != '#')
                pli += str[id+i];
        }
        for (int i=1; i<ans; i++) {
            if (str[id-i] != '#')
                pli.insert(pli.begin(), str[id-i]);
        }
        return pli;
    }
};