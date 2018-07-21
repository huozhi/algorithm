/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

 **
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> ans;
        int i = 0, n = intervals.size();
        for (; i < n && intervals[i].end < newInterval.start; i++) {
            ans.push_back(intervals[i]);
        }
        if (i == n) {
            ans.push_back(newInterval);
            return ans;
        }
        newInterval.start = min(intervals[i].start, newInterval.start);
        for (; i < n && newInterval.end >= intervals[i].start; i++) {
            newInterval.end = max(newInterval.end, intervals[i].end);
        }

        ans.push_back(newInterval);
        for (; i < n; i++) {
            ans.push_back(intervals[i]);
        }
        return ans;
    }
};