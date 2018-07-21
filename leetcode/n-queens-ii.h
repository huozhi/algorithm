/*
Follow up for N-Queens problem.
Now, instead outputting board configurations, return the total number of distinct solutions.
*/

class Solution {
public:
    int sum;
    vector<int> q;
    int N;
    int totalNQueens(int n) {
        if (n<=0) return 0;
        sum = 0;
        N = n;
        q.resize(N, 0);
        getAns(0); 
        return sum;
    }
    
    bool place(int r) {
        for (int i=0; i<r; i++)
            if (q[i]==q[r] || abs(r-i)==abs(q[r]-q[i]))
                return false;
        return true;
    }

    void getAns(int r) {
        if (r==N) {
            ++sum;
            return;
        }
        for (int i=0; i<N; i++) {
            q[r] = i;
            if (place(r))
                getAns(r + 1);
        }
    }
};