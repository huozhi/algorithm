/*
Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
Note:
All words have the same length.
All words contain only lowercase alphabetic characters.

Thinking:
use two hash sets to imitate two bfs queues
bfs a layer, then erase them all from dict

layer 1      hit
              |
layer 2      hot
            /   \
layer 3    dot   lot
           |     |
layer 4    dog  log
            \   /
layer 5      cog

*/

class Solution {
public:
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        re.clear();
        unordered_map<string, vector<string> > prefix; // mark word's preifx
        vector<unordered_set<string> > layer(2); // bfs
        int pre = 0; // double swap queue
        int cur = 1;
        dict.insert(end); // dont forget
        layer[cur].insert(start);
        while (true) {

            swap(pre, cur); // swap queue
            for (auto it=layer[pre].begin(); it!=layer[pre].end(); it++)
                dict.erase(*it); // erase word has been visited
            layer[cur].clear(); // clear prev
            for (auto it=layer[pre].begin(); it!=layer[pre].end(); it++) {
                string word = *it;
                for (int i = 0; i < word.length(); i++) {
                    for (char c='a'; c<='z'; c++) {
                        if (c == word[i]) continue;
                        swap(word[i], c);
                        if (dict.count(word)) {
                            // important, build prefix path
                            prefix[word].push_back(*it);
                            layer[cur].insert(word);
                        }
                        swap(word[i], c);
                    }
                }
            }
            if (layer[cur].count(end)) break;
            if (layer[cur].empty()) return re; // can't reach end by transform
        }
        vector<string> trace;
        buildpath(trace, prefix, end);
        return re;
    }

private:
    vector<vector<string> > re;

    void buildpath(vector<string> &trace, unordered_map<string, vector<string> > &pre, string &end) {
        trace.push_back(end);
        if (pre[end].empty()) {
            // build path finished
            re.push_back(vector<string>(trace.rbegin(), trace.rend()));
        }
        for (auto it=pre[end].begin(); it!=pre[end].end(); it++) {
            buildpath(trace, pre, *it);
        }
        trace.pop_back();
    }
};