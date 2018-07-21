/*
Given a non-negative number represented as an array of digits, 
plus one to the number.

The digits are stored such that the most significant digit is at 
the head of the list.
*/

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> ans;

        // calculate
        vector<int>::reverse_iterator it = digits.rbegin();
        int carry = 1;
        for (; it != digits.rend(); it++) {
            *it += carry;
            if (*it == 10) {
                *it -= 10;
                carry = 1;
            }
            else {
                carry = 0;
            }
        }
        if (carry) {
            ans.push_back(carry);

        }
        ans.insert(ans.end(), digits.begin(), digits.end());

        return ans;
    }
};
