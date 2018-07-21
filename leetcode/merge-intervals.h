/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/

class Solution {
public:
    struct Comp {
        bool operator()(const Interval &a, const Interval &b) {
            if (a.start < b.start)
                return true;
            else if (a.start == b.start)
                return (a.end < b.end);
            return false;
        }
    };
    vector<Interval> merge(vector<Interval> &intervals) {
        sort(intervals.begin(), intervals.end(), Comp());
        if (intervals.empty()) return intervals;
        int mstart = intervals[0].start, mend = intervals[0].end;
        vector<Interval> ans;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start > mend) {
                ans.push_back(Interval(mstart, mend));
                mstart = intervals[i].start;
                mend = intervals[i].end;
            }
            else if (intervals[i].end > mend) {
                mend = intervals[i].end;
            }
        }
        ans.push_back(Interval(mstart, mend));
        return ans;
    }
};