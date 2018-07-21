/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].
*/

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > r;
        perm(r, num, 0);
        return r;
    }

    void perm(vector<vector<int> > &r, vector<int> &num, int start) {
        if (start == num.size())
            r.push_back(num);
        set<int> uset;
        for (int i = start; i < num.size(); i++) {
            if (uset.count(num[i])) continue;
            uset.insert(num[i]);
            swap(num[i], num[start]);
            perm(r, num, start + 1);
            swap(num[i], num[start]);
        }
    }
};