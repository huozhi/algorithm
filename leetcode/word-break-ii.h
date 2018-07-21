/*
Given a string s and a dictionary of words dict, 
add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].
*/

class Solution {
public:
    vector<vector<int> > jump;
    vector<string> result;
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        string ans;
        result.clear();
        jump = jumpMark(s, dict);
        dfsBreak(ans, s, dict, 0);
        return result;
    }

    void dfsBreak(string ans, string &s, unordered_set<string> &dict, int start) {
        if (start == s.size()) {
            result.push_back(ans);
            return;
        }
        for (int i = 0; i < jump[start].size(); i++) {
            string temp = s.substr(start, jump[start][i]-start+1); // substring [start, i]
            if (dict.find(temp) != dict.end()) {
                string backup = ans;
                if (ans.empty())
                    ans += temp;
                else
                    ans += " " + temp;
                dfsBreak(ans, s, dict, jump[start][i]+1);
                ans = backup;
            }
        }
    }

    vector<vector<int> > jumpMark(string &s, unordered_set<string> &dict) {
        vector<vector<int> > jump(s.size());
        int end = (int)s.size();
        for (int i = end-1; i >= 0; i--) {
            if (dict.count(s.substr(i))) {
                jump[i].push_back(end-1);
            }
        }
        for (int i = end-2; i >= 0; i--) {
            for (int j = i, len = 1; j >= 0; j--, len++) {
                // if [i, end) is avaliable
                if (!jump[i+1].empty()) {
                    // if [j, end) can be break into [j, i) and [i, end)
                    // mean that if i could jump to end
                    // j could jump to i, then jump to end, word was broken on [j,end)
                    if (dict.count(s.substr(j, len)))
                        jump[j].push_back(i);
                }
            }
        }
        return jump;
    }
};