/*
Given a string s consists of upper/lower-case alphabets and empty
space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space
 characters only.

For example, 
Given s = "Hello World",
return 5.
*/

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        stringstream ss;
        vector<string> v;
        string w;
        ss << s;
        while (ss >> w) v.push_back(w);
        if (v.empty()) return 0;
        else return v[v.size()-1].length();
    }
};