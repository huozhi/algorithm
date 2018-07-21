/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

0 - "..." (whatever)
1 - "..." (whatever)
2 - "abc"
3 - "def"
4 - "ghi"
5 - "jkl"
6 - "mno"
7 - "pqrs"
8 - "tuv"
9 - "wxyz"


Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
*/

class Solution {
public:
    map<char, string> btn;
    vector<string> ans;
    void init() {
        ans.clear();
        btn['0'] = "_";
        btn['1'] = "*";
        btn['2'] = "abc";
        btn['3'] = "def";
        btn['4'] = "ghi";
        btn['5'] = "jkl";
        btn['6'] = "mno";
        btn['7'] = "pqrs";
        btn['8'] = "tuv";
        btn['9'] = "wxyz";
    }

    void dfs(string r, string s, size_t len) {
        if (len == s.length()) {
            ans.push_back(r);
            return;
        }
        for (size_t i = 0; i < btn[ s[len] ].length(); i++) {
            string digits = btn[ s[len] ];
            string nr = r + digits[i];
            dfs(nr, s, len+1);
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.compare("")==0) {
            ans.push_back("");
            return ans;
        }
        init();
        dfs(string(""), digits, 0);
        return ans;
    }
};
