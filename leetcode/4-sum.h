/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

>    A solution set is:
>    (-1,  0, 0, 1)
>    (-2, -1, 1, 2)
>    (-2,  0, 0, 2)

*/

class Solution {
public:
    vector<vector<int> > result;
    int K;
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        result.clear();
        if (num.empty()) return result;
        K = 4;
        vector<int> ans(K);
        sort(num.begin(), num.end());
        KSum(num, ans, 0, K, target);
        return result;
    }

    void KSum(vector<int> &num, vector<int> &ans, int start, int k, int target) {
        int len = (int)num.size();
        if (k == 2) {
            int L = start, R = len-1;
            unordered_set<int> hasher;
            while (L < R) {
                if (target == num[L] + num[R]) {
                    ans[K-2] = num[L];
                    ans[K-1] = num[R];
                    if (hasher.find(num[L]) == hasher.end()) {
                        result.push_back(ans);
                        hasher.insert(num[L]);
                    }
                    L++; R--;
                }
                else if (target < num[L] + num[R]) R--;
                else L++;
            }
        }
        else {
            for (int i = start; i < len-2; i++) {
                if (i>start && num[i]==num[i-1]) continue;
                ans[K-k] = num[i];
                KSum(num, ans, i+1, k-1, target-num[i]);
            }
        }
    }
};
