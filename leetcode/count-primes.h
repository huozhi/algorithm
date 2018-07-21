/**

Count Primes Total Accepted: 745 Total Submissions: 5471 My Submissions Question Solution 
Description:

Count the number of prime numbers less than a non-negative number, n

Hint: The number n could be in the order of 100,000 to 5,000,000.

click to show more hints.

References:
How Many Primes Are There?

Sieve of Eratosthenes

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.



*/

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        bool *primes = new bool[n];
        for (int i = 2; i < n; i++) primes[i] = true;
        int sqr = sqrt(n - 1);
        for (int i = 2; i <= sqr; i++) {
            if (primes[i]) {
                for (int j = i * i; j < n; j += i)
                    primes[j] = false;
            }
        }
        int c = 0;
        for (int i = 2; i < n; i++)
            c += primes[i] ? 1 : 0;
        delete [] primes;
        return c;
    }
};