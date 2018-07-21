/*
Given two words (start and end), and a dictionary, 
find the length of shortest transformation sequence from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.

Thinking:
DFS method will meet so many cases, so it will turn into TLE.
Use bfs to search path. If a word was found in dictionary, erase it.
because if there exsits another path from a new point to point crossing
this found point(word), it must be longger than the current one.

*/

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        queue<string> bfs;
        int len = 1;
        bfs.push(start);
        bfs.push("");
        while (!bfs.empty()) {
            string temp = bfs.front();
            bfs.pop();
            if (!temp.empty()) {
                for (int i = 0; i < temp.size(); i++) {
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == temp[i]) continue;
                        swap(temp[i], c);
                        if (dict.find(temp) != dict.end()) {
                            bfs.push(temp);
                            dict.erase(temp);
                        }
                        if (temp == end) return len + 1;
                        swap(c, temp[i]);
                    }
                }
            }
            else if (!bfs.empty()) {
                len++; // new level
                bfs.push(""); // separator
            }
        }
        return 0;
    }
};