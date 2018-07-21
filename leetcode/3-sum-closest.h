/*
Given an array S of n integers, 
find three integers in S such that the sum is closest to a given number, target. 
Return the sum of the three integers. 
You may assume that each input would have exactly one solution.

>    For example, given array S = {-1 2 1 -4}, and target = 1.
>    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

*/

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int sum;
        int len = (int)num.size();
        // select a num, rest is target - select_num
        sort(num.begin(), num.end());
        int delta = INT_MAX;
        for (int i = 0; i < len-2; i++) {
            if (i && num[i]==num[i-1]) continue;
            int L = i + 1, R = len - 1;
            while (L < R) {
                int tempsum = num[i] + num[L] + num[R];
                int tempdlt = min(delta, abs(tempsum - target));
                if (tempsum == target)
                    return target;
                if (tempsum < target)
                    L++;
                else
                    R--;
                if (tempdlt < delta) {
                    sum = tempsum;
                    delta = tempdlt;
                }
            }
        }
        return sum;
    }
};