/*
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

click to show spoilers.

Note:
Your solution should be in logarithmic complexity.

Tags:
Array Binary Search

*/

class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        // if (num.size() == 1) return 0;
        int i = 0, j = (int)num.size()-1;
        while (i < j) {
            int mid = (i + j) / 2;
            bool lup = (mid == 0 ? true : num[mid] > num[mid - 1]);
            bool rdown = (mid == num.size()-1 ? true : num[mid] > num[mid + 1]);
            if (lup && rdown)
                return mid;
            else if (lup && !rdown)
                i = mid + 1;
            else
                j = mid - 1;
        }
        return i;
    }
};

