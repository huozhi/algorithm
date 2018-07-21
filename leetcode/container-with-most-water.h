/*
Here is a simple proof for the solution. 
Use v[low, high] indicates the volume of container with low and high. 
suppose height[low] < height[high], 
then we move low to low+1, 
that means we ingored v[low, high-1],v[low, high-2],etc, 
if this is safe, then the algorithm is right, 
and it's obvious that v[low, high-1],high[low, high-2]......
can't be larger than v[low, high]
since its width can't be larger than high-low, 
and its height is limited by height[low].
*/


class Solution {
public:
    int maxArea(vector<int> &height) {
        int maxArea = 0;
        int i=0, j=(int)height.size()-1;
        while(i<j){
            maxArea = max(maxArea, min(height[i],height[j])*(j-i));
            if(height[i]>height[j])
                j--;
            else
                i++;
        }
        return maxArea;
    }
};