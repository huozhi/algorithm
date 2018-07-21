/*
Compare two version numbers version1 and version1.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37
Credits:
Special thanks to @ts for adding this problem and creating all test cases.

Tags:
String

*/


class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream ssv1, ssv2;
        replace(version1.begin(), version1.end(), '.', ' ');
        replace(version2.begin(), version2.end(), '.', ' ');
        ssv1 << version1; ssv2 << version2;
        int curv1, curv2;
        queue<int> v1, v2;
        while (ssv1 >> curv1) v1.push(curv1);
        while (ssv2 >> curv2) v2.push(curv2);

        while (!v1.empty() && !v2.empty()) {
            curv1 = v1.front(); v1.pop();
            curv2 = v2.front(); v2.pop();
            if (curv1 > curv2) return 1;
            else if (curv1 < curv2) return -1;
        }
        if (!v1.empty()) {
            curv1 = v1.front(); v1.pop();
            return curv1 > 0 ? 1 : 0;
        }
        else if (!v2.empty()) {
            curv2 = v2.front(); v2.pop();
            return curv2 > 0 ? -1 : 0;
        }
        return 0;
    }
};