/*
The gray code is a binary numeral system where two successive 
values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the 
code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence 
according to the above definition.

For now, the judge is able to judge based on one instance 
of gray code sequence. Sorry about that.
*/

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        if (n <= 0) return { 0 };
        if (n == 1) return { 0 , 1 };
        vector<int> sub = grayCode(n - 1);
        int len = sub.size();
        int h = 1 << (n - 1);
        for (int i = len - 1; i >= 0; i--)
            sub.push_back(h + sub[i]);
        return sub;
    }
};

class Solution {
public:
    vector<int> grayCode(int n) {
        string code(n, '0');
        vector<int> ans;
        int size = 1<<n;
        ans.push_back(0);
        int k;
        int val = 0;
        for (int i = 1; i < size; ++i) {
            if (i % 2) {
                if (code[n-1] - '0') {
                    code[n-1] = '0';
                    val--;
                }
                else {
                    code[n-1] = '1';
                    val++;
                }
            }
            else {
                for (k = n-1; k>0 && code[k]!='1'; k--);
                k--;
                if (code[k] - '0') {
                    code[k] = '0';
                    val -= 1<<(n-1-k);
                }
                else {
                    code[k] = '1';
                    val += 1<<(n-1-k);
                }
            }
            ans.push_back(val);
        }
        return ans;
    }
};