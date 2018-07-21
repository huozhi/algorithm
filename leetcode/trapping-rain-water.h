/**

Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

Note:
regard the bar's width as 0, then we have
the contained area minus the bar area is the answer
[0,1,0,2,1,0,1,3,2,1,2,1] was changed to [0,1,1,2,2,2,2,3,2,2,2,1]
then minus the bar it self

*/

// use no extra space
class Solution {
public:
    int trap(int A[], int n) {
        int area = 0;
        int maxh = 0;
        int left = 0, right = n-1;
        while (left < right) {
            // if can not contain water
            int lw = A[left], rw = A[right];
            if (lw < rw) {
                maxh = max(maxh, lw);
                area += maxh - lw;
                left++;
            }
            else {
                maxh = max(maxh, rw);
                area += maxh - rw;
                right--;
            }

        }
        return area;
    }
};


// use extra space
class Solution {
public:
    int trap(int A[], int n) {
        int leftHighest[n], rightHighest[n], maxh;
        leftHighest[0] = 0, maxh = 0;
        for (int i = 1; i < n; i++)
            leftHighest[i] = maxh = max(maxh, A[i - 1]);
        rightHighest[n - 1] = 0, maxh = 0;
        for (int i = n - 2; i >= 0; i--)
            rightHighest[i] = maxh = max(maxh, A[i + 1]);
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += max(0, min(leftHighest[i], rightHighest[i]) - A[i]);
        return sum;
    }
};


// use stack
class Solution {
public:
    int trap(int A[], int n) {
        stack<int> s;
        int water = 0;
        s.push(0);
        for (int i = 1; i < n; i++) {
            if (A[i] > A[s.top()]) {
                int bottom = A[s.top()];
                s.pop();
                // A[i] is right highest
                while (!s.empty() && A[i]>=A[s.top()]) {
                    int height = A[s.top()] - bottom;
                    int width = i - s.top() - 1;
                    water += height * width;
                    bottom = A[s.top()];
                    s.pop();
                }
                // stack top is left highest
                if (!s.empty()) water += (A[i] - bottom) * (i - s.top() - 1);
            }
            s.push(i);
        }
        return water;
    }
};