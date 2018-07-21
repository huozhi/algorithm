/**

Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, 
replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), 
or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
Credits:
Special thanks to @mithmatt and @ts for adding this problem and creating all test cases.

*/

class Solution {
public:
    bool isHappy(int n) {
        set<int> s;
        while (n >= 1) {
            int val = 0;
            string str = std::to_string(n);
            for (char c : str) {
                val += (c - '0') * (c - '0');
            }
            if (s.count(val))
                return false;
            s.insert(val);
            if (val == 1) return true;
            n = val;

        }
        return false;
    }
};