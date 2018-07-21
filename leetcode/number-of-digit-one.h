/**

Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

For example:
Given n = 13,
Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.

*/

class Solution {
public:
    int countDigitOne(int n) {
        int lowc = 1, lown = 0, highn = n;
        int cnt = 0, curr;
        while (highn > 0) {
            curr = highn % 10;
            highn /= 10;
            if (curr == 1) {
                cnt += highn * lowc;
                cnt += lown + 1; // start from 0, not 1
            }
            else if (curr > 1) {
                cnt += (highn + 1) * lowc;
            }
            else {
                cnt += highn * lowc;
            }
            lown = curr * lowc + lown;
            lowc *= 10;
        }
        return cnt;
    }
};