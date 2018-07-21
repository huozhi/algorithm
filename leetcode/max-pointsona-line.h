/*

Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

*/

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int result = 0;
        for (int i = 0; i < points.size(); i++) {
            unordered_map<float, int> um;
            int deplicate = 0, tmp = 1;
            um[INT_MIN] = 0;
            for (int j = 0; j < points.size(); j++) {
                if (i == j) continue;
                Point a = points[i], b = points[j];
                if (a.x == b.x && a.y == b.y) {
                    deplicate++;
                    continue;
                }
                float slope = (a.x == b.x)
                    ? INT_MAX
                    : (float)(a.y - b.y) / (a.x - b.x);
                if (um.count(slope)) {
                    tmp = max(++um[slope], tmp);
                }
                else {
                    um[slope] = 2;
                    tmp = max(tmp, 2);
                }
            }
            result = max(result, tmp + deplicate);
        }
        return result;
    }
};