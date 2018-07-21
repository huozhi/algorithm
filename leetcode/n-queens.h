/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard 
such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' 
placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/

class Solution {
public:
    vector<vector<string> > ans;
    vector<int> q;
    int N;
    bool place(int r) {
        for (int i=0; i<r; i++)
            if (q[i]==q[r] || abs(r-i)==abs(q[r]-q[i]))
                return false;
        return true;
    }

    void getAns(int r) {
        if (r==N) {
            vector<string> temp(N, string(N, '.'));
            for (int i=0; i<q.size(); i++)
                temp[i][ q[i] ] = 'Q';
            ans.push_back(temp);
            return;
        }
        for (int i=0; i<N; i++) {
            q[r] = i;
            if (place(r))
                getAns(r + 1);
        }
    }

    vector<vector<string> > solveNQueens(int n) {
        ans.clear();
        q.clear();
        N = n;
        q.resize(N, 0);
        getAns(0);
        return ans;
    }
};