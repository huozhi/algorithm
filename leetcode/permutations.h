/*
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

*/
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > r;
        perm(r, num, 0);
        return r;
    }

    void perm(vector<vector<int> > &r, vector<int> &num, int start) {
        if (start == num.size())
            r.push_back(num);
        for (int i = start; i < num.size(); i++) {
            swap(num[i], num[start]);
            perm(r, num, start + 1);
            swap(num[i], num[start]);
        }
    }
};