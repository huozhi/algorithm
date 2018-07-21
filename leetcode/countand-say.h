/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/

class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for (int i = 1; i < n; i++)
            s = next(s);
        return s;
    }

    string next(string s) {
        int cnt = 0;
        string r;
        char prev = s[0];
        for (int i = 0; i <= s.size(); i++) {
            if (prev == s[i])
                cnt++;
            else {
                r.push_back(cnt + '0');
                r.push_back(prev);
                prev = s[i];
                cnt = 1;
            }
        }
        if (cnt > 1) {
            r.push_back(cnt + '0');
            r.push_back(prev);
        }
        return r;
    }
};