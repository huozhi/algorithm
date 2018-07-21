/**

Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

*/
  
class Solution {
public:
    /**
     * @param tokens The Reverse Polish Notation
     * @return the value
     */
    int evalRPN(vector<string>& tokens) {
        // Write your code here
        stack<int> s;
        int n = tokens.size();
        for (int i = 0; i < n; i++) {
            string& tk = tokens[i];
            if (!isdigit(tk[0]) && tk.length() == 1) {
                int val = s.top(); s.pop();
                switch (tk[0]) {
                    case '+': s.top() += val; break;
                    case '-': s.top() -= val; break;
                    case '*': s.top() *= val; break;
                    case '/': s.top() /= val; break;
                }
            }
            else {
                s.push(stoi(tk));
            }
        }
        return s.top();
    }
};
