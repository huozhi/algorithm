/*
Given an array of integers, every element appears three times except for one. 
Find that single one.
*/


// Solution 1, use hash table
class Solution {
public:
    int singleNumber(int A[], int n) {
        if (n <= 0)
            return -1;
        else if(n == 1)
            return A[0];
        unordered_map<int, int> um;
        for(int i=0; i<n; i++) {
            if (um.count(A[i])) {
                if (um[A[i]] == 2)
                    um.erase(A[i]);
                else
                    ++um[A[i]];
            }
            else {
                um[A[i]] = 1;
            }
        }
        return um.begin()->first;
    }
};


// Solution 2
class Solution {
public:
    int singleNumber(int A[], int n) {
        int ones = 0, twos = 0, xthrees = 0;
        for(int i = 0; i < n; ++i) {
            twos |= (ones & A[i]);
            ones ^= A[i];
            xthrees = ~(ones & twos);
            ones &= xthrees;
            twos &= xthrees;
        }
        return ones;
    }
};