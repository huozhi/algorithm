/*
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

*/

class Solution {
public:
    void reverseWords(string &str) {
        reverse(str.begin(), str.end());
        stringstream ss(str);
        str.clear();
        string temp;
        while (ss >> temp) {
            reverse(temp.begin(), temp.end());
            if (str.empty())
                str.append(temp);
            else
                str.append(" " + temp);
        }
    }
};