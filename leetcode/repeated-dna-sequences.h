/*

All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". 
When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

For example,

Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].
Hide Tags Hash Table Bit Manipulation


*/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> occur;
        vector<string> r;
        int len = s.length();
        
        if (len < 10) return r;
        for (int i = 0; i <= len - 10; i++) {
            string sub = s.substr(i, 10);
            occur[sub]++;
            if (occur[sub] == 2) {
                r.push_back(sub);
            }
        }
        return r;
    }
};

