/**

Given an integer array of size n, find all elements that appear more than [n/3] times. The algorithm should run in linear time and in O(1) space.

*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int a, b;
        int cnt1 = 0, cnt2 = 0;
        for (int val : nums) {
            if (cnt1 == 0 || val == a) {
                cnt1++;
                a = val;
            }
            else if (cnt2 == 0 || val == b) {
                cnt2++;
                b = val;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }
        
        cnt1 = cnt2 = 0;
        for (int val : nums) {
            if (val == a) cnt1++;
            else if (val == b) cnt2++;
        }
        vector<int> res;
        if (cnt1 > nums.size() / 3) res.push_back(a);
        if (cnt2 > nums.size() / 3) res.push_back(b);
        return res;
    }
};