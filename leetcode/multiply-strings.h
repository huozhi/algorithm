class Solution {
public:
    string multiply(string num1, string num2) {
        string pro(num1.size() + num2.size(), '0');
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int i, j, c = 0;
        for (i = 0; i < num1.size(); i++) {
            for (j = 0; j < num2.size(); j++) {
                int v = (pro[i + j] - '0') + (num1[i] - '0') * (num2[j] - '0') + c;
                if (v >= 10) {
                    c = v / 10;
                    v %= 10;
                }
                else{
                    c = 0;
                }
                pro[i + j] = v + '0';
            }
            if (c) {
                pro[i + j] = c + '0';
                c = 0;
            }
        }
        if (c)
            pro[i + j] = c + '0';
        for (i = (int)pro.size() - 1; pro[i]=='0' && i>=0; i--);
        pro = (i < 0) ? "0" : pro.substr(0, i + 1);
        reverse(pro.begin(), pro.end());
        return pro;
    }
};
