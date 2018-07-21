/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        if (n <= 0 || k <= 0) return result;
        vector<int> comb;
        dfs(1, k, n, comb, result);
        return result;
    }

    void dfs(int i, int k, int n, vector<int>& comb, vector<vector<int>>& result) {
        if (comb.size() == k) {
            result.push_back(comb);
            return;
        }
        for (; i <= n; i++) {
            comb.push_back(i);
            dfs(i + 1, k, n, comb, result);
            comb.pop_back();
        }
    }
};