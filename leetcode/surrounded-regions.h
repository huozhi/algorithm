/*
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X

Note:

from the point on the boundary, to the illegal point.
the points on the zigzag path won't be covered.
so mark them, then keep them, change other 'O's to 'X's.

If we use the break condition like i<0 || j<0 || i==N || j==M,
it will turn into stack overflow beacuse of the last big data
which has 250 x 250 characters.

so we must cut the recursion step smartly...
I copied the answer of another coder then passed this problem...

*/

class Solution {
public:
    int N, M;
    void solve(vector<vector<char> > &board) {
        if (board.size()<=2 || board[0].size()<=2) return;
        N = board.size(); M = board[0].size();
        // top
        for (int j = 0; j < M; j++)
            if (board[0][j] == 'O') {
                board[0][j] = 'M';
                dfs(board, 0, j);
            }
        // bottom
        for (int j = 0; j < M; j++)
            if (board[N-1][j] == 'O') {
                board[N-1][j] = 'M';
                dfs(board, N-1, j);
            }
        // left
        for (int i = 1; i < N-1; i++)
            if (board[i][0] == 'O') {
                board[i][0] = 'M';
                dfs(board, i, 0);
            }
        // right
        for (int i = 1; i < N-1; i++)
            if (board[i][M-1] == 'O') {
                board[i][M-1] = 'M';
                dfs(board, i, M-1);
            }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == 'M')
                    board[i][j] = 'O';
            }
        }
    }

    void dfs(vector<vector<char> > &board, int i, int j) {
        if (i>1 && board[i-1][j]=='O') {
            board[i-1][j] = 'M'; // mark
            dfs(board, i-1, j);
        }
        if (j>1 && board[i][j-1]=='O') {
            board[i][j-1] = 'M';
            dfs(board, i, j-1);
        }
        if (i<N-1 && board[i+1][j]=='O') {
            board[i+1][j] = 'M';
            dfs(board, i+1, j);
        }
        if (j<M-1 && board[i][j+1]=='O') {
            board[i][j+1] = 'M';
            dfs(board, i, j+1);
        }
    }
};