/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, 
where "adjacent" cells are those horizontally or vertically neighboring. 
The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/

class Solution {
public:
    typedef vector<vector<bool> > VVB;
    int row, col;
    VVB visit;
    string target;
    bool found(VVB &visit, vector<vector<char> > &board, string &target, int i, int j, int idx) {
        if (idx == target.size())
            return true;
        if (i>=row || j>=col || i<0 || j<0)
            return false;

        if (target[idx]!=board[i][j] || visit[i][j])
            return false;
        visit[i][j] = true;
        if (found(visit, board, target, i+1, j, idx+1)) return true;
        if (found(visit, board, target, i-1, j, idx+1)) return true;
        if (found(visit, board, target, i, j+1, idx+1)) return true;
        if (found(visit, board, target, i, j-1, idx+1)) return true;
        visit[i][j] = false;

        return false;
    }

    bool exist(vector<vector<char> > &board, string word) {
        if (board.empty()) return false;
        row = board.size();
        col = board[0].size();
        target = word;
        visit.assign(row, vector<bool>(col, false));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (found(visit, board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
};