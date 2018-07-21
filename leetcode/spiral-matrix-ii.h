/*
Given an integer n, generate a square matrix filled with 
elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        if (n == 0) return vector<vector<int> >();
        vector<vector<int> > ans(n, vector<int>(n));
        int num = 1;
        int i = -1, j = -1;
        int L = 0;
        while (num <= n*n) {
            ++i; ++j; for (; num<=n*n && j<=n-L-1; j++) ans[i][j] = num++;
            --j; ++i; for (; num<=n*n && i<=n-L-1; i++) ans[i][j] = num++;
            --i; --j; for (; num<=n*n && j>=L; j--) ans[i][j] = num++;
            ++j; --i; for (; num<=n*n && i>L; i--) ans[i][j] = num++;
            L++;
        }
        return ans;
    }
};