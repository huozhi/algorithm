/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid.
The brackets must close in the correct order,
"()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

class Solution {
public:
    bool ispar(char c) {
        return (c=='(' || c==')' ||
            c=='[' || c==']' ||
            c=='{' || c=='}');
    }

    bool isleft(char c) {
        return (c=='('||c=='['||c=='{');
    }

    bool isright(char c) {
        return (c==')'||c==']'||c=='}');
    }

    bool match(char a, char b) {
        return (a=='(' && b==')')
        ||  (a=='[' && b==']')
        || (a=='{' && b=='}');
    }

    bool isValid(string s) {
        if (s.empty()) return true;
        stack<char> par;
        int len = (int)s.size();
        for (int i = 0; i < len; i++) {
            if (ispar(s[i])) {
                if(isleft(s[i])) {
                    par.push(s[i]);
                }
                else if(isright(s[i])) {
                    if (par.empty()) {
                        return false;
                    }
                    else {
                        if (match(par.top(), s[i])) {
                            par.pop();
                        }
                    }
                }
            }
        }
        if (par.empty()) return true;
        return false;
    }
};
