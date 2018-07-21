/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/

class Solution {
public:    
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        vector<int> first(2, 1);
        if(rowIndex < 0) return ans;
        else if(rowIndex == 0) {
            ans.push_back(1);
            return ans;
        }
        else if(rowIndex == 1) {
            return first;
        }
        for(int i = 1; i < rowIndex; i++) {
            ans.clear();
            ans.push_back(1);
            for (int j = 0; j < (int)first.size()-1; j++) {
                ans.push_back(first[j] + first[j+1]);
            }
            ans.push_back(1);
            first = ans;
        }
        return ans;
    }
};