/*
Have you thought about this?
Here are some good questions to ask before coding. 
Bonus points for you if you have already thought through this!

If the integer's last digit is 0,
what should the output be? ie, cases such as 10, 100.

Did you notice that the reversed integer might overflow?
Assume the input is a 32-bit integer, 
then the reverse of 1000000003 overflows. 
How should you handle such cases?

Throw an exception? 
Good, but what if throwing an exception is not an option? 
You would then have to re-design the function (ie, add an extra parameter).
*/


class Solution {
public:
    int reverse(int x) {
        bool positive = x > 0 ? true : false;
        long long t = abs((long long)x);
        long long r = 0;
        while(t){
            r = r * 10 + t % 10;
            t /= 10;
        }
        if (r > INT_MAX) {
            return 0;
        }
        if (!positive)
            r = -r;
        return r;
    }
};
