/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.


A sudoku puzzle...


Note:

Solution:
validate each new point
dfs, like n-queens

*/

class Solution {
public:
    bool valid(vector<vector<char> > &board, int i, int j) {
        int r, c;
        // validate row
        for (r = 0; r < 9; r++)
            if (r!=i && board[i][j]==board[r][j])
                return false;
        // validate column
        for (c = 0; c < 9; c++)
            if (c!=j && board[i][j]==board[i][c])
                return false;
        // validate block
        for (r=i/3*3; r<i/3*3+3; r++)
            for (c=j/3*3; c<j/3*3+3; c++)
                if ((c!=j||r!=i) && board[i][j]==board[r][c])
                    return false;
        // pass
        return true;
    }

    void solveSudoku(vector<vector<char> > &board) {
        dfs(board, 0, 0);
    }

    bool dfs(vector<vector<char> > &board, int i, int j) {
        if (i == 9)
            return true;
        if (j == 9)
            return dfs(board, i+1, 0);
        if (board[i][j] == '.') {
            for (int d = 1; d <= 9; d++) {
                board[i][j] = d + '0';
                if (valid(board, i, j) && dfs(board, i, j+1))
                    return true;
                board[i][j] = '.'; // dont forget, pass by reference...
            }
        }
        else {
            return dfs(board, i, j+1);
        }
        return false;
    }
};
