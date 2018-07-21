/*
Given an unsorted array of integers, 
find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. 
Return its length: 4.

Your algorithm should run in O(n) complexity.
*/

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        set<int> s(num.begin(), num.end()), visit;
        int longest = 0;
        for (int cur : num) {
            if (visit.find(cur) == visit.end()) {
                visit.insert(cur);
                int pre = cur - 1, next = cur + 1;
                while (s.find(pre) != s.end()) visit.insert(pre--);
                while (s.find(next) != s.end()) visit.insert(next++);
                longest = max(longest, next - pre - 1);
            }
        }
        return longest;
    }
};