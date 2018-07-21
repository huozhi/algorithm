/**
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Return 0 if the array contains less than 2 elements.

You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.

Credits:
Special thanks to @porker2008 for adding this problem and creating all test cases.

*/

class Solution {
public:
    int maximumGap(vector<int> &num) {
        if (num.size() <= 1) return 0;
        int maxv = num[0], minv = num[0];

        for (int v : num) {
            minv = min(minv, v);
            maxv = max(maxv, v);
        }
        int sz = num.size(),
            dis = maxv - minv,
            gap = ceil((double)dis / (sz - 1)),
            bktnum = ceil((double)dis / gap) + 1;


        vector<vector<int> > buket(bktnum);
        for (int i = 0; i < sz; i++) {
            int idx = (num[i] - minv) / gap;
            if (buket[idx].empty()) {
                buket[idx].resize(2, num[i]);
            }
            else {
                buket[idx][0] = min(buket[idx][0], num[i]);
                buket[idx][1] = max(buket[idx][1], num[i]);
            }
        }

        int maxgap = 0;
        int pre = 0;
        for (int i = 1; i < bktnum; i++) {
            if (buket[i].size() && buket[pre].size()) {
                maxgap = max(maxgap, buket[i][0] - buket[pre][1]);
                pre = i;
            }

        }
        return maxgap;
    }
};