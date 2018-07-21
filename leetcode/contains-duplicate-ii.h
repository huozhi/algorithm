/**

Given an array of integers and an integer k, 
return true if and only if there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.

*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> index;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (!index.count(nums[i])) {
                index[ nums[i] ] = i;
            }
            else {
                if (i - index[ nums[i] ] <= k)
                    return true;
            }
        }
        return false;
    }
};