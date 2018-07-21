/*
Given a sorted array of integers, find the starting and ending 
position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> range(2, -1);
        int i = 0,
            j = n - 1,
            mid = i + (j - i) / 2,
            found = 0,
            val;

        while (i <= j) {
            mid = i + (j - i) / 2, val = A[mid];
            if (val == target) {
                i = j = mid;
                found = 1;
                break;
            }
            else if (val > target) {
                j = mid - 1;
            }
            else {
                i = mid + 1;
            }
        }
        if (found) {
            while (i > 0 && A[i] == target && A[i - 1] == target) i--;
            while (j < n - 1 && A[j] == target && A[j + 1] == target) j++;
            range[0] = i; range[1] = j;
        }
        return range;
    }
};