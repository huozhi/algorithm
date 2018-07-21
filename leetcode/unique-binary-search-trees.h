/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

Catalan Number:
1, 1, 2, 5, 10....

Recursion: sum: n, root has value of i, one of [1:n], left one has i-1 less combinations than i,
right one has n-i more combinations than i, so C(i-1) * C(n-i)

*/


class Solution {
public:
    int numTrees(int n) {
        // if (n==0 || n==1) return 1;
        // else {
        //     int num = 0;
        //     for (int i = 1; i <= n; i++) {
        //         num += (numTrees(i-1) * numTrees(n-i));
        //     }
        //     return num;
        // }
        int A[21]; // catalan number is greater than INT_MAX when C(21)
        A[0] = A[1] = 1;
        for (int i = 2; i < 21; i++)
            A[i] = A[i-1] * (4*i-2) / (i+1); // Cn = (2n)!/((n+1)!*n!)
        return A[n];
    }
};