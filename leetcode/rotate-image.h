/*
You are given an n x n 2D matrix representing an image.
Rotate the image by 90 degrees (clockwise).
*/

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        for (int i=0, n=(int)matrix.size(); i<n/2; ++i) {
            for (int j=i; j<n-1-i; j++) {
                int t = matrix[i][j];
                matrix[i][j] = matrix[n-j-1][i];
                matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
                matrix[n-i-1][n-j-1] = matrix[j][n-1-i];
                matrix[j][n-1-i] = t;
            }
        }
    }


    void rotate(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix.front().empty()) return;
        int n = matrix.size();
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n / 2; i++) {
                swap(matrix[i][j], matrix[n - i - 1][j]);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
