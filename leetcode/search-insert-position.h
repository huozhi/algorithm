/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
*/

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int i = 0, j = n - 1, mid, val;
        while (i < j) {
            mid = i + (j - i + 1) / 2; // key point, if no + 1, dead loop
            val = A[mid];
            if (val <= target) {
                i = mid;
            }
            else {
                j = mid - 1;
            }
        }
        while (i < n && A[i] < target) i++;
        return i;
    }
};