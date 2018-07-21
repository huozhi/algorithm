/*
Given a matrix of m x n elements (m rows, n columns), 
return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> ans;
        if (matrix.size() == 0) return ans;
        int i = -1, j = -1, M = matrix.size(), N = matrix[0].size();
        int L = 0; // later
        while (ans.size() < M*N) {
            i++; j++; while (ans.size() < M*N && j <= N-L-1) ans.push_back(matrix[i][j++]);
            j--; i++; while (ans.size() < M*N && i <= M-L-1) ans.push_back(matrix[i++][j]);
            i--; j--; while (ans.size() < M*N && j >= L) ans.push_back(matrix[i][j--]);
            j++; i--; while (ans.size() < M*N && i > L) ans.push_back(matrix[i--][j]);
            L++;
        }
        return ans;
    }
};
