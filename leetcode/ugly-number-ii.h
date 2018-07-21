/**

Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number.

Hint:

The naive approach is to call isUgly for every number until you reach the nth one. Most numbers are not ugly. Try to focus your effort on generating only the ugly ones.
An ugly number must be multiplied by either 2, 3, or 5 from a smaller ugly number.
The key is how to maintain the order of the ugly numbers. Try a similar approach of merging from three sorted lists: L1, L2, and L3.
Assume you have Uk, the kth ugly number. Then Uk+1 must be Min(L1 * 2, L2 * 3, L3 * 5).

*/

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> nums;
        nums.push_back(1);
        int i2 = 0, i3 = 0, i5 = 0;
        for (int i = 0; i < n - 1; i++) {
            int val = min(min(nums[i2] * 2, nums[i3] * 3), nums[i5] * 5);
            if (val == nums[i2] * 2) i2++;
            if (val == nums[i3] * 3) i3++;
            if (val == nums[i5] * 5) i5++;
            nums.push_back(val);
        }
        return nums.back();
    }
};