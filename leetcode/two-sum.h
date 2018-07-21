/*
Given an array of integers, find two numbers such that they add up to a 
specific target number.

The function twoSum should return indices of the two numbers such that they 
add up to the target, where index1 must be less than index2. Please note 
that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> another;
        vector<int> copynum(numbers);
        sort(copynum.begin(), copynum.end());
        for (int i=0; i<(int)copynum.size(); i++) {
            another.push_back(target - copynum[i]);
        }
        int i=0, j = (int)numbers.size()-1;
        while(i<j) {
            if(copynum[i] == another[j]) {
                break;
            }
            else if(copynum[i] > another[j]) {
                j--;
            }
            else {
                i++;
            }
        }
        
        vector<int>::iterator ia, ib;
        ia = find(numbers.begin(), numbers.end(), copynum[i]);
        if (copynum[i] == target - copynum[i])
            ib = find(ia + 1, numbers.end(), copynum[i]);
        else
            ib = find(numbers.begin(), numbers.end(), target-copynum[i]);
        vector<int> ans(2);
        ans[0] = min(ia - numbers.begin() + 1, ib - numbers.begin() + 1);
        ans[1] = max(ia - numbers.begin() + 1, ib - numbers.begin() + 1);
        
        return ans;
    }
};
