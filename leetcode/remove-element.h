/*
Given an array and a value,
remove all instances of that value in place and return the new length.
The order of elements can be changed.
It doesn't matter what you leave beyond the new length.
*/

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int len = n;
        for (int i = 0; i < n; i++) {
            if (A[i] == elem)
               len--;
        }
        int *copyA = new int[len];
        int j = 0;
        for (int i = 0 ;i < n; i++) {
            if (A[i] != elem)
                copyA[j++] = A[i];
        }
        for (j = 0; j < len; j++) A[j] = copyA[j];
        return len;
    }
};