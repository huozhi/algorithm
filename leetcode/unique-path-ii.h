/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. 
How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty()) return 0;

        int path[105][105];
        memset(path, 0, sizeof(path));
        int n = (int)obstacleGrid.size(), m = obstacleGrid[0].size();
        int i, j;
        for (j=0; j<m && !obstacleGrid[0][j]; j++) path[0][j] = 1;
        for (i=0; i<n && !obstacleGrid[i][0]; i++) path[i][0] = 1;
        for (i=1; i<n; i++) {
            for (j=1; j<m; j++) {
                if (!obstacleGrid[i][j])
                    path[i][j] = path[i-1][j] + path[i][j-1];
            }
        }
        return path[n-1][m-1];
    }
};