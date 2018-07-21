/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its 
index, otherwise return -1.

You may assume no duplicate exists in the array.
*/

class Solution {
public:
    int search(int A[], int n, int target) {
        if (n==0) return -1;
        int i = 0, j = n-1, mid=(i+j)/2;
        while (i<j && A[i]>A[j]) {
            if (A[i]>A[mid]) {
                j = mid;
            }
            else {
                i = mid+1;
            }
            mid = (i+j)/2;
        }
        int add = i;
        j = add + n - 1, mid=(i+j)/2;
        while (i < j) {
            if (A[mid % n] == target) {
                return mid%n;
            }
            else if (A[mid % n] > target) {
                j = mid;
            }
            else {
                i = mid+1;
            }
            mid = (i+j)/2;
        }
        if (A[mid % n] == target) return mid % n;
        return -1;
        
    }
};