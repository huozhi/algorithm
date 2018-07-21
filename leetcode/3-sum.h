/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.

>    For example, given array S = {-1 0 1 2 -1 -4},

>    A solution set is:
>    (-1, 0, 1)
>    (-1, -1, 2)

Transform 3 sum problem to 2 sum and (0-target)
tirple != result.back() dosen't slove every problem
take care of the case { -13,-13,5,6,7,8 }
if we don't have condition (i && num[i]==num[i-1]) continue
if will generater like this:

#0: {-13,5,6}
#1: {-13,7,8}
#2: {-13,5,6}
#3: {-13,7,8}

so must jump the duplicates in vector num

*/


class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &nums) {
        vector<vector<int>> result;
        int len = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < len; i++) {
            int L = i + 1, R = len - 1;
            
            while (L < R) {
                int target = -nums[i];
                
                if (nums[L] + nums[R] == target) {
                    vector<int> triple = {nums[i], nums[L], nums[R]};
                    result.push_back(triple);
                    while (L < R && nums[L] == triple[1]) L++;
                    while (L < R && nums[R] == triple[2]) R--;
                }
                else if (nums[L] + nums[R] < target) {
                    L++;
                }
                else {
                    R--;
                }
            }
            while (i < len - 1 && nums[i] == nums[i + 1]) i++;
        }
        return result;
    }
};

