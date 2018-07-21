/**

Given an integer, write a function to determine if it is a power of two.


*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        int cntOne = 0;
        while (n) {
            cntOne += (n & 1);
            n >>= 1;
        }
        return cntOne == 1;
    }
};