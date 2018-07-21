/**

Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

You may assume that the given expression is always valid.

Some examples:
"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5
Note: Do not use the eval built-in library function.

*/

class Solution {
public:
    int prio(char c) {
        switch (c) {
            case '+':
            case '-':
                return 0;
            case '*':
            case '/':
                return 1;
        }
        return -1;
    }

    int calc(int a, int b, char c) {
        switch (c) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return a / b;
        }
        return 0;
    }

    int calculate(string s) {
        stack<int> sval;
        stack<char> sop;
        int i = 0, n = s.length();
        while (i < n) {
            if (isspace(s[i])) { i++; continue; }
            if (isdigit(s[i])) {
                int v = 0;
                while (isdigit(s[i])) {
                    v = v * 10 + s[i++] - '0';
                }
                sval.push(v);
            }
            else {
                char op = s[i];
                if (sop.empty() || prio(op) > prio(sop.top())) {
                    sop.push(op);
                }
                else {
                    while (!sop.empty() && prio(op) <= prio(sop.top())) {
                        char tpop = sop.top(); sop.pop();
                        double val = sval.top(); sval.pop();
                        sval.top() = calc(sval.top(), val, tpop);
                    }
                    sop.push(op);
                }
                i++;
            }
        }

        while (!sop.empty()) {
            char op = sop.top(); sop.pop();
            int val = sval.top(); sval.pop();
            sval.top() = calc(sval.top(), val, op);
        }
        return sval.top();
    }
};