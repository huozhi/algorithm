/*
Write an efficient algorithm that searches for a value in an m x n matrix. 
This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last 
integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, r = m * n - 1, mid;
        while (l <= r) {
            mid = l + (r - l) / 2;
            int i = mid / n, j = mid - i * n;
            int val = matrix[i][j];
            if (val == target)
                return true;
            else if (val < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return false;
    }
};