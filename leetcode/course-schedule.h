/**

There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

*/

class Solution {
public:
    // dfs method to judge if there is a cycle in the subtree of a node
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        map<int, vector<int>> graph;
        vector<bool> visit(numCourses, false);

        // we need a arr to store if there is no cycle in one's subtree
        // if we do not use it, problem will goes to TLE on leetcode oj
        vector<bool> hasNoCycle(numCourses, false);
        for (int i = 0; i < prerequisites.size(); i++) {
            int label = prerequisites[i].first,
                depen = prerequisites[i].second;
            graph[label].push_back(depen);
        }
        for (auto i = graph.begin(); i != graph.end(); i++) {
            if (findCycle(graph, visit, hasNoCycle, i->first))
                return false;
        }
        return true;
    }

    bool findCycle(map<int, vector<int>> &graph, vector<bool> &visit, vector<bool> &hasNoCycle, int curr) {
        if (visit[curr])
            return true; // there is a cycle, cause the node is visited two times
        if (hasNoCycle[curr])
            return false;

        visit[curr] = true;
        for (int i = 0; i < graph[curr].size(); i++) {
            if (findCycle(graph, visit, hasNoCycle, graph[curr][i])) {
                return false;
            }
        }
        visit[curr] = false;
        hasNoCycle[curr] = true;
        return false;
    }
};