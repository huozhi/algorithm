/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/

class Solution {
public:
    int value(const char& c) {
        int v = 0;
        switch (c) {
            case 'I': v = 1; break;
            case 'V': v = 5; break;
            case 'X': v = 10; break;
            case 'L': v = 50; break;
            case 'C': v = 100; break;
            case 'D': v = 500; break;
            case 'M': v = 1000; break;
        }
        return v;
    }

    int romanToInt(string s) {
        if (s.empty()) return 0;
        if (s.size()==1) return value(s[0]);
        size_t i = s.size()-1;
        int ans = 0;
        size_t j = i-1;
        int pre;
        int cur;
        for (; i > 0; i--) {
            j = i-1;
            pre = value(s[j]), cur = value(s[i]);
            if (pre < cur) {
                ans = ans + cur - pre;
                if (j == 0) return ans;
                i = j;
            }
            else {
                ans += cur;
            }
        }
        return ans + value(s[0]);
    }
};