/*

Given a 2D binary matrix filled with 0's and 1's, 
find the largest rectangle containing all ones and return its area.

*/

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int r = matrix.size(), c = r ? matrix[0].size() : 0;
        vector<vector<int> > h(r, vector<int>(c, 0));
        for (int j = 0; j < c; j++) {
            for (int i = 0; i < r; i++) {
                if (matrix[i][j] == '1')
                    h[i][j] = (i>=1) ? h[i-1][j] + 1 : 1;
                else
                    h[i][j] = 0;
            }
        }
        stack<int> idx;
        int area = 0;
        for (int i = 0; i < r; i++) {

            for (int j = 0; j < c; ) {
                if (idx.empty() || h[i][j]>h[i][idx.top()]) {
                    idx.push(j++);
                }
                else {
                    int k = idx.top(); idx.pop();
                    int w = idx.empty() ? j : j-idx.top()-1;
                    area = max(area, h[i][k] * w);
                }
            }
            while (!idx.empty()) {
                int k = idx.top(); idx.pop();
                int w = idx.empty() ? c : c-idx.top()-1;
                area = max(area, h[i][k] * w);
            }
        }
        return area;
    }
};
