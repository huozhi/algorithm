/**
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
*/

class Solution {
public:
    int factor[10] = {1,1,2,6,24,120,720,5040,40320,362880};
    string getPermutation(int n, int k) {
        string num = string("123456789").substr(0, n);
        string ans(n, ' ');
        --k;
        for (int i = 0; i < n; i++) {
            int idx = (k) / factor[n-i-1];
            ans[i] = num[idx];
            num.erase(idx, 1);
            k %= factor[n-i-1];
        }
        return ans;
    }
};