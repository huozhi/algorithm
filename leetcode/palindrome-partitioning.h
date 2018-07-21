/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]

*/

class Solution {
public:
    vector<vector<string> > result;

    bool isParlindrom(const string &s) {
         int i = 0, j = (int)s.size()-1;
         while (i < j) {
            if (s[i] == s[j]) i++,j--;
            else
                return false;
         }
         return true;
    }
    vector<vector<string> > partition(string s) {
        result.clear();
        vector<string> ans;
        dfs(s, ans, 0);
        return result;
    }

    void dfs(string &s, vector<string> &ans, int start) {
        if (start == s.size()) {
            if (!ans.empty())
                result.push_back(ans);
            return;
        }
        int len = 1;
        while (start + len <= (int)s.size()) {
            string temp = s.substr(start, len);
            if (isParlindrom(temp)) {
                ans.push_back(temp);
                dfs(s, ans, start + len);
                ans.pop_back();
            }
            len++;
        }
    }
};