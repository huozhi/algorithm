/**

Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)

*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int lhp = 1, rhp = 1, n = nums.size();
        vector<int> res(n, 1);
        for (int i = n - 2; i >= 0; i--) {
            lhp *= nums[i + 1];
            res[i] *= lhp;
        }
        for (int i = 1; i < n; i++) {
            rhp *= nums[i - 1];
            res[i] *= rhp;
        }
        return res;
    }
};