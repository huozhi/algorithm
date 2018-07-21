/*

Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.

*/

class Solution {
public:
    struct cmp {
        bool operator()(const int& x, const int& y) {
            string sx = to_string(x), sy = to_string(y);
            return sx + sy > sy + sx;
        }
    };

    string largestNumber(vector<int> &num) {
        sort(num.begin(), num.end(), cmp());
        ostringstream out;
        for (int i = 0; i < num.size(); i++)
            out << num[i];
        if (out.str()[0] == '0') return "0";
        return out.str();
    }
};