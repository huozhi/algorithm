/*
Given an array of size n, find the majority element. The majority element is the element that appears more than [ n/2 ] times.

You may assume that the array is non-empty and the majority element always exist in the array.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.

Tags
Divide and Conquer Array Bit Manipulation

*/

class Solution {
public:
    int majorityElement(vector<int> &num) {
        int cnt = 1, major = num[0];
        
        for (int i = 1; i < num.size(); i++) {
            if (num[i] != major) {
                --cnt;
                if (cnt == 0) {
                    major = num[i];
                    cnt = 1;
                }
            }
            else {
                ++cnt;
            }
        }
        return major;
    }
};