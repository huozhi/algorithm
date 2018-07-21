/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
*/

class Solution {
public:
    bool search(int A[], int n, int target) {
        if (n<=0) return false;
        int l=0, r=n-1, m;
        while (l<=r) {
            m = (l+r) / 2;
            if (A[m] == target) return true;
            if (A[l] < A[m]) {
                if (A[l]<=target && A[m]>target)
                    r = m-1;
                else
                    l = m+1;
            }
            else if (A[l] > A[m]) {
                if (A[r]>=target && target>A[m])
                    l = m+1;
                else
                    r = m-1;
            }
            else {
                l++;
            }
        }
        return false;        
    }
};