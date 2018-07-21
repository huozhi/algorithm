/*

Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

For example,

Given numerator = 1, denominator = 2, return "0.5".
Given numerator = 2, denominator = 1, return "2".
Given numerator = 2, denominator = 3, return "0.(6)".
Credits:
Special thanks to @Shangrila for adding this problem and creating all test cases.

Tags:
Hash Table Math

*/

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        ostringstream out;
        long long num = numerator, den = denominator;
        

        if (den < 0) {
            den = -den;
            num = -num;
        }
        if (num < 0) {
            num = -num;
            out << "-";
        }
        long long rem = num % den;
        out << (num / den);
        if (rem == 0) {
            return out.str();
        }
        
        
        out << ".";
        vector<int> rems;
        unordered_map<int, int> apper;

        for (int i = 0; rem && !apper.count(rem); i++) {
            apper[rem] = i;
            rem *= 10;
            rems.push_back(rem / den);
            rem = rem % den;
        }

        if (rem) {
            for (int k = 0; k < apper[rem]; k++) {
                out << rems[k];
            }
            out << "(";
            for (int k = apper[rem]; k < apper.size(); k++) {
                out << rems[k];
            }
            out << ")";
        }
        else {
            for (int k = 0; k < apper.size(); k++) {
                out << rems[k];
            }
        }
        return out.str();
    }
};
