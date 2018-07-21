/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > ans;
        if (numRows <= 0) {
            return ans;
        }
        ans.resize(numRows);
        ans[0].push_back(1);
        for (int i = 1; i < numRows; i++) {
            ans[i].push_back(1);
            for (int j = 0; j < (int)ans[i-1].size()-1; j++) {
                int val = ans[i-1][j] + ans[i-1][j+1];
                ans[i].push_back(val);
            }
            ans[i].push_back(1);
        }
        return ans;
    }
};
