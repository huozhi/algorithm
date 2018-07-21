/**

Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

Examples: 
[2,3,4] , the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
For example:

add(1)
add(2)
findMedian() -> 1.5
add(3) 
findMedian() -> 2

*/

class MedianFinder {
    priority_queue<int, vector<int>, greater<int> > minheap;
    priority_queue<int, vector<int>, less<int> > maxheap;
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        if (maxheap.empty()) {
            maxheap.push(num);
        }
        else {
            if (num <= maxheap.top()) {
                maxheap.push(num);
            }
            else {
                minheap.push(num);
            }
            // adjust two heaps
            if (minheap.size() + 1 < maxheap.size()) {
                int t = maxheap.top();
                maxheap.pop();
                minheap.push(t);
            }
            else if (minheap.size() > maxheap.size()) {
                int t = minheap.top();
                minheap.pop();
                maxheap.push(t);
            }
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if (maxheap.empty())
            return 0;
        else if (maxheap.size() > minheap.size())
            return maxheap.top();
        else
            return (maxheap.top() + minheap.top()) / 2.0;
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();