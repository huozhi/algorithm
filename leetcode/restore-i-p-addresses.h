/*
Given a string containing only digits, 
restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/

class Solution {
puclass Solution {
public:
    vector<string> result;

    int parseIP(string &s) {
        int n = 0;
        if (s.size() > 1 && s[0] == '0')
            return 256; // invalid ip
        for (int i = 0; i < s.size(); i++)
            n = n * 10 + (s[i] - '0');
        return n;
    }
    
    vector<string> restoreIpAddresses(string s) {
        result.clear();
        dfs(s, string(""), 0, 0);
        return result;
    }

    bool validNum(string &s) {
        return s.size() > 0 && s.size() < 4 && parseIP(s) <= 255;
    }

    void dfs(const string &ori, string s, int start, int cnt) {
        if (cnt == 3) {
            string sub = ori.substr(start);
            if (validNum(sub)) {
                s += sub;
                result.push_back(s);
            }
            return;
        }
        
        string tmp;
        for (int i = start, len = 1; i < ori.size() && len < 4; i++, len++) {
            tmp += ori[i];
            if (parseIP(tmp) <= 255) {
                if (cnt < 3)
                    dfs(ori, s + tmp + ".", start + len, cnt + 1);
                else
                    dfs(ori, s + tmp, start + len, cnt + 1);
            }
        }
    }
};
