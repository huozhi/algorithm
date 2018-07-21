/*
Given a set of distinct integers, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

class Solution {
public:
    vector<vector<int> > ans;

    void add(const vector<int> &S, int i, vector<int> tmp) {
        if (i == S.size()) {
            ans.push_back(tmp);
            return;
        }
        add(S, i+1, tmp);
        tmp.push_back(S[i]);
        add(S, i+1, tmp);
    }
    vector<vector<int> > subsets(vector<int> &S) {
        ans.clear();
        sort(S.begin(), S.end());
        add(S, 0, vector<int>());
        return ans;
    }
};