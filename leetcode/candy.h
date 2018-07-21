/*
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?


Note:
intialization: [1....1]
search from 0 to n, if current ranting is higher than previous one, c[i] = c[i-1]+1
backtrak from n to 0, if current ranting is higher than previous one, c[i] = c[i+1]+1

*/

class Solution {
public:
    int candy(vector<int> &ratings) {
        if (ratings.empty()) return 0;
        int n = (int)ratings.size();
        vector<int> candies(n, 1);
        for (int i = 0; i < n-1; i++)
            if (ratings[i+1]>ratings[i] && candies[i+1]<=candies[i])
                candies[i+1] = candies[i] + 1;
        for (int i = n-1; i > 0; i--)
            if (ratings[i]<ratings[i-1] && candies[i-1]<=candies[i])
                candies[i-1] = candies[i] + 1;
        int sum = 0;
        return accumulate(candies.begin(), candies.end(), 0);
    }
};