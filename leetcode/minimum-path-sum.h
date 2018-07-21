/*
Given a m x n grid filled with non-negative numbers, 
find a path from top left to bottom right which minimizes the sum of all numbers along its path.


*/

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int r = (int)grid.size();
        int c = (int)grid[0].size();
        vector<vector<int> > dp(r, vector<int>(c, INT_MAX));
        dp[0][0] = grid[0][0];
        for (int i=1; i<c; i++)
            dp[0][i] = dp[0][i-1] + grid[0][i];
        for (int i=1; i<r; i++)
            dp[i][0] = dp[i-1][0] + grid[i][0];
    
        for (int i=1; i<r; i++)
            for (int k=1; k<c; k++)
                dp[i][k] = min(dp[i-1][k], dp[i][k-1]) + grid[i][k];
            
        return dp[r-1][c-1];
    }
};
