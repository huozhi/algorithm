/*
Given a collection of integers that might contain duplicates, S, 
return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/

class Solution {
public:
    void dfs(vector<int> &S, int start,vector<int> &subset,vector<vector<int> > &ans){
        ans.push_back(subset);
        for (size_t i=start; i<S.size(); i++) {
            if (i!=start && S[i]==S[i-1]) continue;
            subset.push_back(S[i]);
            dfs(S, i+1, subset, ans);
            subset.pop_back(); // key part
        }
    }
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > ans;
        vector<int> subset;
        sort(S.begin(), S.end());
        dfs(S, 0, subset, ans);
        return ans;
    }
};