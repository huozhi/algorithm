/*
Divide two integers without using multiplication, division and mod operator.
*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        unsigned int dd = dividend, dv = divisor;
        dd = (dividend < 0) ? -dd : dd;
        dv = (divisor < 0) ? -dv : dv;
        int ans = 0;
        while (dd >= dv) {
            int i;
            long long v = dv;
            for (i = 0; v <= dd; i++)
                v <<= 1;
            ans += (1 << (i-1));
            dd -= (dv << (i-1));
        }
        return (dividend>0 ^ divisor>0) ? -ans : ans;
    }
};