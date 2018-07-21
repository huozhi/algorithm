/*
Missing Ranges 

Given a sorted integer array where the range of elements are [lower, upper] inclusive,
return its missing ranges.
For example, given [0, 1, 3, 50, 75], lower = 0 and upper = 99, 
return ["2", "4->49", "51->74", "76->99"].

*/

class Solution {
public:
	vector<string> findMissingRanges(int A[], int n, int lower, int upper) {
        vector<string> ans;
        for (int i = 0; i < n && A[i] <= upper && lower <= upper; i++) {
            if (A[i] < lower) continue;
            if (A[i] > lower) {
                ans.push_back(range(lower, A[i] - 1));
            }
            lower = A[i] + 1;
        }
        if (lower <= upper) {
            ans.push_back(range(lower, upper));
        }
        return ans;
	}

	string range(int lower, int upper) {
        stringstream ss;
        ss << lower;
        if (lower < upper) {
            ss << "->" << upper;
        }
        return ss.str();
	}
};
