/*
You are given a string, S, and a list of words, L, that are all of the same length. Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.

For example, given:
S: "barfoothefoobarman"
L: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).

Note:
easy but pruning is important
*/

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> starts;
        unordered_map<string, int> dict;
        int slen = S.size(), wcnt = L.size(), wlen = L[0].size();
        if (wcnt*wlen > slen) return starts;
        for (int i = 0; i < wcnt; i++)
            dict[ L[i] ]++;

        // foucs on the condition here
        // i <= slen-wcnt*wlen means that it will iterate to the "last start" index
        // if the end index is larger than "last start", TLE showed up
        for (int i = 0; i <= slen-wcnt*wlen; i++) {
            unordered_map<string, int> tempDict;
            int temp_wcnt = 0;
            for (int j = i; j < i+wlen*wcnt; j+=wlen) {
                string word = S.substr(j, wlen);
                if (dict.count(word)) {
                    tempDict[word]++;
                    if (tempDict[word] <= dict[word])
                        temp_wcnt++;
                    else
                        break;
                }
                else
                    break;
            }
            if (temp_wcnt == wcnt)
                starts.push_back(i);
        }
        return starts;
    }
};