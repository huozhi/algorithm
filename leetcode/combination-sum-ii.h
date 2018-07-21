/*
Given a collection of candidate numbers (C) and a target number (T), 
find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 
*/

class Solution {
public:
    vector<vector<int> > result;
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        result.clear();
        sort(num.begin(), num.end());
        vector<int> ans;
        combineDFS(num, ans, 0, target);
        return result;
    }

    void combineDFS(vector<int> &num, vector<int> &ans, int start, int target) {
        if (target == 0) {
            result.push_back(ans);
            return;
        }
        if (start==num.size() || target<0) {
            return;
        }

        for (int i = start; i < num.size(); i++) {
            if (i>start && num[i]==num[i-1]) continue;
            ans.push_back(num[i]);
            combineDFS(num, ans, i+1, target-num[i]);
            ans.pop_back();
        }
    }

};