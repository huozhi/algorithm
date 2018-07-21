/**

Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.


Example 1
Input: "2-1-1".

((2-1)-1) = 0
(2-(1-1)) = 2
Output: [0, 2]


Example 2
Input: "2*3-4*5"

(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10
Output: [-34, -14, -10, -10, 10]

*/

class Solution {
public:
    int compute(int a, int b, char op) {
        switch (op) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
        }
        return 0;
    }

    vector<int> diffWaysToCompute(string input) {
        int n = input.length();
        int idx = 0, val = 0;
        while (idx < n && isdigit(input[idx])) {
            val *= 10;
            val += input[idx++] - '0';
        }
        if (idx == n) return { val };

        vector<int> result, left, right;
        for (int i = 0; i < n; i++) {
            if (!isdigit(input[i])) {
                left = diffWaysToCompute(input.substr(0, i));
                right = diffWaysToCompute(input.substr(i + 1));

                for (int j = 0; j < left.size(); j++) {
                    for (int k = 0; k < right.size(); k++) {
                        result.push_back(compute(left[j], right[k], input[i]));
                    }
                }
            }
        }
        return result;
    }
};