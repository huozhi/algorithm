/*
Given two strings S and T, determine if they are both one edit distance apart.
*/

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int slen = s.length(), tlen = t.length();
        if (slen == 0) return tlen == 1;
        if (tlen == 1) return slen == 0;
        int dis = abs(slen - tlen);
        if (dis == 0) {
            int cnt = 0;
            for (int i = 0; i < tlen; i++) {
                if (s[i] != t[i]) ++cnt;
                if (cnt > 1) return false;
            }
            return cnt == 1;
        }
        else if (dis == 1) {
            string& refs = slen > tlen ? s : t;
            string& reft = slen > tlen ? t : s;
            for (int i = 0; i < (int)refs.length(); i++) {
                string temp = refs;
                if (temp.erase(i, 1) == reft)
                    return true;
            }
            return false;
        }
        return false;
    }
};
