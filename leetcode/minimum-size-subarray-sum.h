/**

iven an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.


More practice:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).

*/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty() || s == 0) return 0;
        int i = 0, j = 0, sum = 0;
        int n = nums.size(), minlen = n + 1;

        while (true) {
            if (sum < s) {
                if (j >= n) break;
                sum += nums[j++];
            }
            else {
                if (i > j) break;
                minlen = min(minlen, j - i);
                sum -= nums[i++];
            }
        }
        return minlen > n ? 0 : minlen;
    }
};