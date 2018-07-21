/*
Say you have an array for which the ith element is the price of a given stock 
on day i.

If you were only permitted to complete at most one transaction (ie, buy one 
and sell one share of the stock), design an algorithm to find the maximum profit.
*/

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int low = INT_MAX, profit = 0, maxp = 0;
        for(int i = 0; i < prices.size(); i++) {
            int profit = prices[i] - low;
            maxp = max(maxp, profit);
            low = min(low, prices[i]);
        }
        return maxp;
    }
};

