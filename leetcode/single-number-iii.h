/**

Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?

*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int Xor = 0;
        for (int num : nums) Xor ^= num;
        /**
          * from the result that two different nums xor is not zero,
          * we knew that at least 1 bit of them are different,
          * see here, num - 1 let the most right hand bit 1 change to 0,
          * and all 0 on the right of it becomes to 1,
          * ~(num - 1) set 0 back to 1 and 1 back to 0
          * for example, 10100 -> 10011 -> 00100,
          * then we use num & ~(num - 1) to get the most right bit 1
          */
        Xor &= (~(Xor - 1));
        // separate the array into two parts
        vector<int> ans = { 0, 0 };
        for (int num : nums) {
            if (num & Xor)
                ans[0] ^= num;
            else
                ans[1] ^= num;
        }
        return ans;
    }
};