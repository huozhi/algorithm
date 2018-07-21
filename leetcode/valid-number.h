/*
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true

*/
class Solution {
public:
    enum RESULT { _NUL = -9, _SIGN = 0, _NUM = 2, _NAN = 8 };
    bool isNumber(const char *s) {
        stringstream strstream;
        strstream << s; string ss; strstream >> ss;
        if(strstream>>ss) return false;
        size_t ei = ss.find('e');
        if (ei != string::npos) {
            string s1 = ss.substr(0, ei);
            string s2 = ss.substr(ei+1, ss.size()-ei-1);
            return validSigleNumber(s1) && (eachIsDigit(s2, 1)==_NUM);
        }
        return validSigleNumber(ss);
    }

    bool validSigleNumber(string s) {
        if (s.empty()) return false;

        size_t di = s.find('.');
        if (di != string::npos) {
            string s1 = s.substr(0, di);
            string s2 = s.substr(di+1, s.size()-di-1);
            if (s1.empty() && s2.empty()) return false;
            int r1 = eachIsDigit(s1, 1);
            int r2 = eachIsDigit(s2, 0);
            return (r1+r2==_NUM+_SIGN) || (r1+r2==_NUM+_NUM) || (r1+r2==_NUM+_NUL);
        }
        return eachIsDigit(s,1)==_NUM;
    }

    int eachIsDigit(string s, int flag) {
        if (s.empty()) return _NUL;

        size_t i = 0;
        if (flag && (s[i]=='+' || s[i]=='-')) ++i;
        if (i==s.size()) return _SIGN;
        
        for (; i < s.size(); i++)
            if (!isdigit(s[i])) return _NAN;
        return _NUM;
    }
};