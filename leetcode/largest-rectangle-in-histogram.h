/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, 
find the area of largest rectangle in the histogram.
Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.

*/
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        stack<int> index;
        int i = 0, maxArea = 0;
        int len = (int)height.size();
        while (i < len) {
            if (index.empty() || height[i]>height[index.top()]) {
                index.push(i++);
            }
            else {
                int j = index.top();
                index.pop();
                maxArea = max(maxArea, height[j] * (index.empty() ? i : i-index.top()-1));
            }
        }

        while (!index.empty()) {
            int j = index.top();
            index.pop();
            maxArea = max(maxArea, height[j] * (index.empty() ? len : len-index.top()-1));
        }
        return maxArea;
    }
};