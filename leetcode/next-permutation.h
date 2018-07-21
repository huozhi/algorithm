/**

Implement next permutation, which rearranges numbers into the lexicographically 
next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible 
order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding 
outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

*/

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if (num.size() <= 1) return;
        int n = num.size();
        int i = n - 2, ii = n - 1;
        while (i >= 0 && !(num[i] < num[ii])) {
            --i;
            --ii;
        }
        if (i < 0)
            reverse(num.begin(), num.end());
        else {
            int j = n;
            while (!(num[--j] > num[i]));
            swap(num[i], num[j]);
            reverse(num.begin() + ii, num.end());
        }
    }
};