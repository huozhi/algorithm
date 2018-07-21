/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. 
You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time 
(ie, you must sell the stock before you buy again).

Depart it into two parts [0, separator) and [separator, end)
find the max profit in each interval, then add up, find the max sum of profits

DP: use two arrays to store the profits in many intervals
LeftToRight array: [0, 1), [0, 2), ..., [0, separator)...
RightToLeft array: [separator, separator+1), [separator, separator+2), ...

(end represent prices.size())

*/

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int maxl, maxr, pro, ans = 0;
        int lowl = 0;
        maxl = 0;
        int N = (int)prices.size();
        vector<int> ltor(N, 0), rtol(N, 0);

        for (int i = 1; i < N; i++) {
            pro = prices[i] - prices[lowl];
            if (pro > maxl) {
                maxl = pro;
            }
            if (prices[i] < prices[lowl]) {
                lowl = i;
            }
            ltor[i] = maxl;
        }

        int lowr = N-1;
        maxr = 0;
        for (int j = N-2; j >= 0; j--) {
            pro = prices[j] - prices[lowr];
            if (pro < maxr)
                maxr = pro;
            if (prices[j] > prices[lowr])
                lowr = j;
            rtol[j] = -maxr;
        }
        for (int i = 0; i < N; i++)
            ans = max(ans, ltor[i] + rtol[i]);
        
        return ans;
    }
};