/**

Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

You may assume that the given expression is always valid.

Some examples:
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23
Note: Do not use the eval built-in library function.

*/

class Solution {
public:
    int calculate(string s) {
        stack<int> sval;
        stack<char> sop;
        int i = 0, n = s.length();
        while (i < n) {
            if (isspace(s[i])) { i++; continue; }
            if (isdigit(s[i])) {
                int val = 0;
                while (i < n && isdigit(s[i])) {
                    val = val * 10 + s[i] - '0';
                    i++;
                }
                if (!sop.empty()) {
                    if (sop.top() == '(') {
                        sval.push(val);
                    }
                    else {
                        switch (sop.top()) {
                            case '+': sval.top() += val; break;
                            case '-': sval.top() -= val; break;
                        }
                        sop.pop();
                    }
                }
                else
                    sval.push(val);

            }
            else {
                char op = s[i];
                if (op != ')') {
                    sop.push(op);
                }
                else {
                    sop.pop(); // pop left parenthese
                    while (!sop.empty() && sop.top() != '(') {
                        int vtop = sval.top();
                        sval.pop();
                        switch (sop.top()) {
                            case '+': sval.top() += vtop; break;
                            case '-': sval.top() -= vtop; break;
                        }
                        sop.pop();
                    }
                }
                i++;
            }
        }
        while (!sop.empty()) {
            int vtop = sval.top();
            sval.pop();
            switch (sop.top()) {
                case '+': sval.top() += vtop; break;
                case '-': sval.top() -= vtop; break;
            }
            sop.pop();
        }
        return sval.top();
    }
};