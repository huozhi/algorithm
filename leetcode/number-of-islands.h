/**

Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. 
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3

*/

class Solution {
public:
    typedef vector<char> VC;
    typedef vector<bool> VB;
    typedef vector<VC> VVC;
    typedef vector<VB> VVB;
    int numIslands(VVC &grid) {
        if (grid.empty() || grid.front().empty()) return 0;
        int n = grid.size(), m = grid.front().size();
        int cnt = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cnt += dfs(i, j, n, m, grid);
        return cnt;
    }

    int dfs(int i, int j, int n, int m, VVC &grid) {
        if (i >= n || i < 0 || j >= m || j < 0) return 0;
        if (grid[i][j] == '0') return 0;
        grid[i][j] = '0';
        dfs(i + 1, j, n, m, grid);
        dfs(i, j + 1, n, m, grid);
        dfs(i - 1, j, n, m, grid);
        dfs(i, j - 1, n, m, grid);
        return 1;
    }
};