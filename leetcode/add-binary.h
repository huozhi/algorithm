/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/

class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int i = (int)a.length() - 1, j = (int)b.length() - 1;
        int t, c = 0, sum;
        while (i >= 0 || j >= 0)
            if (j < 0) {
                sum = (a[i] - '0') + c;
            else if (i < 0)
                sum = (b[j] - '0') + c;
            else
                sum = (a[i] - '0') + (b[j] - '0') + c;
            t = sum & 1;
            c = sum >> 1;
            ans.insert(ans.begin(), t + '0');
            i--; j--;
        }
        if (c)
            ans.insert(ans.begin(), '1');
        if (ans.empty())
            return "0";
        return ans;
    }
};
