/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3].
*/

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n <= 2) return n;
        int  len = 0, cnt = 0;
        int prev = A[0] - 3; // random number 3
        for (int i = 0; i < n; i++, len++) {
            A[len] = A[i];
            if (A[i] == prev) {
                cnt++;
                if (cnt >= 2) len--;
            }
            else {
                prev = A[i];
                cnt = 0;
            }
        }
        return len;
    }
};