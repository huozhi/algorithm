/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. 
The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.
*/

class Solution {
public:
    const int MAXN = 105;
    int uniquePaths(int m, int n) {
        if (m<=0 || n<=0) return 0;
        if (m<=1 || n<=1) return 1;
        int path[MAXN];
        memset(path,0,sizeof(path));
        path[0] = 1;
        while (n--)
            for (int i=1; i<m; i++) path[i]+=path[i-1];
        return path[m-1];
    }
};