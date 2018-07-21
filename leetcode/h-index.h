/**

Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."

For example, given citations = [3, 0, 6, 1, 5], which means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively. Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, his h-index is 3.

Note: If there are several possible values for h, the maximum one is taken as the h-index.

*/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if (n == 0) return 0;
        sort(citations.begin(), citations.end(), greater<int>());
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (i >= citations[i]) {
                return i;
            }
        }
        return n;
    }
};


class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int cnts[n + 1];
        memset(cnts, 0, sizeof cnts);
        for (int i = 0; i < n; i++) {
            if (citations[i] > n)
                cnts[n]++;
            else
                cnts[ citations[i] ]++;
        }
        int sum = 0;
        for (int i = n; i > 0; i--) {
            if (cnts[i] + sum >= i) {
                return i;
            }
            sum += cnts[i];
        }
        return 0;
    }
};