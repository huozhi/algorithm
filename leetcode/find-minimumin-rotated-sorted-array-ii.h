/*
Follow up for "Find Minimum in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array may contain duplicates.

Tags: 
Array, Binary Search

*/

class Solution {
public:
    int findMin(vector<int> &num) {
        assert(!num.empty());
        int start = 0, end = (int)num.size()-1;
        int minVal = num[start];
        while (start < end) {
            int mid = (start + end) / 2;
            if (num[start] == num[end]) {
                for (int i = start; i != end; i++)
                    minVal = min(minVal, num[i]);
                return minVal;
            }
            if (num[mid] > num[end]) {
                start = mid + 1;
            }
            else {
                end = mid;
            }
            minVal = min(minVal, num[start]);
        }
        return minVal;
    }
};
