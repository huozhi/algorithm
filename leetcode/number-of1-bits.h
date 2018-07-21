/**

Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).

For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.


Solution 2:

n = 0x110100 n-1 = 0x110011 n&(n - 1) = 0x110000
n = 0x110000 n-1 = 0x101111 n&(n - 1) = 0x100000
n = 0x100000 n-1 = 0x011111 n&(n - 1) = 0x0

the loop will only run c times, and c is the count of 1 bit in the integer

*/

// Solution 1
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int c = 0;
        while (n) {
            c += n & 1;
            n >>= 1;
        }
        return c;
    }
};


// Solution 2
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int c = 0;
        while (n) {
            n &= n - 1;
            c++;
        }
        return c;
    }
};