/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, 
please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given 
input specs). You are responsible to gather all the input requirements up front.

spoilers alert... click to show requirements for atoi.

Requirements for atoi:
The function first discards as many whitespace characters as necessary until 
the first non-whitespace character is found. Then, starting from this character, 
takes an optional initial plus or minus sign followed by as many numerical 
digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral 
number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid 
integral number, or if no such sequence exists because either str is empty 
or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. 
If the correct value is out of the range of representable values, 
INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
*/
class Solution {
public:
    int atoi(string str) {
        if (str.empty()) return 0;
        int i = 0, len = str.length();
        while (isspace(str[i])) i++;
        bool positive = true;
        if (str[i] == '-') {
            positive = false;
            i++;
        }
        else if (str[i] == '+') i++;

        long long r = 0,
                  base = 10,
                  INT_MAX_ABS = INT_MAX,
                  INT_MIN_ABS = INT_MAX_ABS + 1;
        while (isdigit(str[i])) {
            long long sum = r * base + (long long)(str[i] - '0');
            if (positive && sum > INT_MAX_ABS) return INT_MAX;
            if (!positive && sum > INT_MIN_ABS) return INT_MIN;
                
            r = r * 10 + (str[i]-'0');
            ++i;
        }
        return positive ? r : -r;
    }
};