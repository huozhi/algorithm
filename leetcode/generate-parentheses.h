/*
Given n pairs of parentheses, write a function to generate all 
combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        gen(ans, n, n, string(""));
        return ans;
    }

    // remaining left-parenthese, right-parenthese
    // print from left side to right side
    // lp must be more than rp
    void gen(vector<string> &ans, int lp, int rp, string s) {
        if (lp==0 && rp==0) {
            ans.push_back(s);
            return;
        }
        if (lp>0) {
            gen(ans, lp-1, rp, s+'(');
        }
        if (rp>0 && lp<rp) {
            gen(ans, lp, rp-1, s+')');
        }
    }
};
