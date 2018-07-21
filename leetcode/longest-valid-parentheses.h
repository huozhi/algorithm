/*
Given a string containing just the characters '(' and ')', 
find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

Note:
unmatched left pars and rigth pars are separators.
maximum length is from last to the separator
we assign the first separator is ')', its index is -1

*/

class Solution {
public:
    int longestValidParentheses(string s) {
        int maxlen = 0;
        stack<pair<char, int> > par;
        par.push(make_pair(')', -1));
        for (int i = 0; i < (int)s.size(); i++) {
            if (par.top().first=='(' && s[i]==')') {
                par.pop();
                maxlen = max(maxlen, i - par.top().second);
            }
            else
                par.push(make_pair(s[i], i)); // separator
        }
        return maxlen;
    }
};
