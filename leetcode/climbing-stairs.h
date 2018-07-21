/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps.
In how many distinct ways can you climb to the top?
*/

class Solution {
public:
    int climbStairs(int n) {
        // fibonacci
        if (n == 1) return 1;
        if (n == 2) return 2;
        int pre = 1, cur = 2;
        int c;
        for (int i = 0; i < n - 2; i++) {
            c = cur + pre;
            pre = cur; cur = c;
        }
        return c;
    }
};