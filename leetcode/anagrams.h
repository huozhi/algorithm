/*
Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.

For example:

Input:　　["tea","and","ate","eat","den","dna"]

Output:   ["tea","ate","eat","and","dna"]
(the order is not required)
*/

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // write your code here
        vector<string> r;
        unordered_map<string, int> m;
        for (string s : strs) {
            sort(s.begin(), s.end());
            m[s]++;
        }
        for (string s : strs) {
            string st = s;
            sort(st.begin(), st.end());
            if (m[st] > 1) r.push_back(s);
        }
        return r;
    }
};
