/**

Kth Largest Element in an Array Total Accepted: 423 Total Submissions: 1567 My Submissions Question Solution 
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.

*/

class Solution {
public:
    // Solution 1, use partition to sort the array, util the mid position is kth
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return findKthLargest(nums, 0, n - 1, k);
    }

    int findKthLargest(vector<int>& nums, int start, int end, int k) {
        int key = nums[end];
        int mid = start - 1;
        for (int i = start; i < end; i++)
            if (nums[i] <= key)
                swap(nums[++mid], nums[i]);
        swap(nums[end], nums[++mid]);
        int pos = end - mid + 1;
        if (pos == k)
            return nums[mid];
        else if (pos > k)
            return findKthLargest(nums, mid + 1, end, k);
        else
            return findKthLargest(nums, start, mid - 1, k - pos);
    }


    // Solution 2, use mini heap, if the array is too large, keep k elements in heap
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int i = 0, n = nums.size();
        while (k--)
            pq.push(nums[i++]);
        while (i < n) {
            pq.push(nums[i++]);
            pq.pop();
        }
        return pq.top();
    }
};

