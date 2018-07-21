/**

The string "PAYPALISHIRING" is written in a zigzag pattern on 
a given number of rows like this: (you may want to display this 
pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion 
given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

*/

class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows < 2) return s;
        string cvrt;
        int gap = nRows * 2 - 2;
        int small_gap = gap;
        int r = 0;
        while (r<nRows && small_gap>=0) {
            for (int i = r; i < s.size(); i += gap) {
                cvrt += s[i];
                if (small_gap!=gap && small_gap && i+small_gap<s.size())
                    cvrt += s[i+small_gap];
            }
            small_gap -= 2;
            r++;
        }
        return cvrt;
    }
};


class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) return s;
        string res;
        vector<string> row(numRows);
        int n = s.length();
        int mod = numRows * 2 - 2;
        for (int i = 0; i < n; i++) {
            int idx = i % mod;
            idx = idx >= numRows ? mod - idx : idx;
            row[idx].push_back(s[i]);
        }
        for (string str : row)
            res.append(str);
        return res;
    }
};

