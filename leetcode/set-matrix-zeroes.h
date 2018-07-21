/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. 
Do it in place.

click to show follow up.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int rs = (int)matrix.size(), cs = (int)matrix[0].size();
        // bool rgc = (rs >= cs); // row size greater than column size
        bool *rowfill = new bool[rs];
        bool *colfill = new bool[cs];
        memset(rowfill, 0, rs);
        memset(colfill, 0, cs);
        for (int i = 0; i < rs; i++) {
            for (int j = 0; j < cs; j++) {
                if (matrix[i][j] == 0) {
                    if (!rowfill[i]) {
                        rowfill[i] = true;
                    }
                    if (!colfill[j]) {
                        colfill[j] = true;
                    }
                }
            }
        }
        for (int i = 0; i < rs; i++)
            if (rowfill[i])
                for (int k = 0; k < cs; k++) matrix[i][k] = 0;
        for (int j = 0; j < cs; j++)
            if (colfill[j])
                for (int k = 0; k < rs; k++) matrix[k][j] = 0;
        delete [] rowfill;
        delete [] colfill;
    }
};