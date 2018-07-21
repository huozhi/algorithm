/**

Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].

*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if (nums.empty()) return ans;
        int s, e, n = nums.size();
        string cur;
        for (s = 0, e = 1; e < n; e++) {
            if (nums[e] - nums[e - 1] != 1) {
                cur.append(to_string(nums[s]));
                if (e - s > 1) {
                    cur.append("->");
                    cur.append(to_string(nums[e - 1]));
                }
                ans.push_back(cur);
                cur.clear();
                s = e;
            }
        }
        cur.append(to_string(nums[s]));
        if (e - 1 - s > 0) {
            cur.append("->");
            cur.append(to_string(nums[e - 1]));
        }
        ans.push_back(cur);
        return ans;
    }
};