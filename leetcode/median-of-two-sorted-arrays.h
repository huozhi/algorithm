class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        vector<int> v(m+n);
        int i=0, j=0, k=0;
        while(i<m && k<n) {
            if(A[i]<B[k]) v[j] = A[i++];
            else v[j] = B[k++];
            ++j;
        }
        for(; i<m; j++,i++) v[j] = A[i];
        for(; k<n; j++,k++) v[j] = B[k];
        if ((m+n)%2==0) {
            return (v[(m+n)/2-1] + v[(m+n)/2])/2.0;
        }
        else
            return (double)v[(m+n-1)/2];
    }
};
