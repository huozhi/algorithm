/**

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Credits:
Special thanks to @ifanchu for adding this problem and creating all test cases. Also thanks to @ts for adding additional test cases.

Dynamic Programming


*/

class Solution {
public:
    int rob(vector<int> &num) {
        if (num.empty()) return 0;
        if (num.size() == 1) return num[0];
        
        int a = 0,
            b = num[0],
            c = num[1];
        for (int i = 2; i < num.size(); i++) {
            int cur = max(a, b) + num[i]; // jump c
            a = b;
            b = c;
            c = cur; // sum
        }
        return max(b, c);
    }
};