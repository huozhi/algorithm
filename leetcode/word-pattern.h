/**

Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.

*/


class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char, string> forwardRule;
        map<string, char> backwardRule;
        stringstream ss(str);
        int len = pattern.length();
        string tmp;
        for (int i = 0; i < len; i++) {
            char c = pattern[i];
            if (!(ss >> tmp))
                return false;
            if (!forwardRule.count(c)) {
                forwardRule[c] = tmp;
            }
            else if (forwardRule[c] != tmp) {
                return false;
            }
            if (!backwardRule.count(tmp)) {
                backwardRule[tmp] = c;
            }
            else if (backwardRule[tmp] != c) {
                return false;
            }
        }
        if (ss >> tmp)
            return false;
        return true;
    }
};