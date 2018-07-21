/*
Given an array of words and a length L, 
format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; 
that is, pack as many words as you can in each line. 
Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. 
If the number of spaces on a line do not divide evenly between words, 
the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.
*/

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {

        vector<string> ans;
        if (words.empty()) return ans;
        if (L == 0 && words[0]=="") return words;
        else if (L == 0 && words[0].size())
            return ans;

        int total = 0;
        for (int i = 0; i < (int)words.size(); i++) {
            total += words[i].size();
        }
        int row;
        if (total % L == 0)
            row = total / L;
        else
            row = total / L + 1;
        if (row == 0) ++row;
        size_t i = 0;
        while (i < words.size()) {
            vector<string> temp;
            int tmplen = 0;
            while (i<words.size() && tmplen<L) {
                if (tmplen && tmplen + words[i].size() < L) {
                    tmplen += (words[i].size() + 1);
                    temp.push_back(" " + words[i++]);
                }
                else if (tmplen==0 && words[i].size() <= L) {
                    tmplen += words[i].size();
                    temp.push_back(words[i++]);
                }
                else
                    break;
            }
            string line;
            int space = L - tmplen;
            int k;
            while (temp.size()>1 && space && i<words.size()) {
                for (k = 0; space && k<(int)temp.size()-1; k++) {
                    temp[k] += ' ';
                    space--;
                }
            }
            for (k = 0; k < (int)temp.size(); k++) line += temp[k];
            if ((int)line.size() < L) line.append(L - (int)line.size(), ' ');
            temp.clear();
            ans.push_back(line);
        }

        return ans;
    }
};