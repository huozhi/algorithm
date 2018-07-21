/*
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".
*/

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> simple;
        for (int i = 0; i < path.size(); i++) {
            if (path[i] == '/') {
                path[i] = ' ';
            }
        }
        stringstream ss;
        ss << path;
        string dir;
        while (ss >> dir) {
            if (dir == "..") {
                if (!simple.empty()) simple.pop_back();
            }
            else if (dir == ".")
                continue;
            else if(!dir.empty())
                simple.push_back(dir);
        }
        string ans("/");
        for (int i=0; i<(int)simple.size(); i++) {
            if (i < (int)simple.size() - 1)
                ans += (simple[i] += '/');
            else
                ans += simple[i];
        }
        return ans;
    }
};
