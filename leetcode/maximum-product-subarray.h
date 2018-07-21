/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
*/

class Solution {
public:
    int maxProduct(int A[], int n) {
        if (n < 1) return 0;
        int maxp = A[0];
        int curp = 1;
        for (int i = 0; i < n; i++) {
            if (A[i] == 0) {
                curp = 1;
                maxp = max(maxp, 0);
            }
            else {
                curp *= A[i];
                maxp = max(maxp, curp);
            }
        }
        curp = 1;
        maxp = max(maxp, A[n-1]);
        for (int i = n-1; i >= 0; i--) {
            if (A[i] == 0) {
                curp = 1;
                maxp = max(maxp, 0);
            }
            else {
                curp *= A[i];
                maxp = max(maxp, curp);
            }
        }
        return maxp;
    }
};