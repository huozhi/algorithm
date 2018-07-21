/**

Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Rectangle Area
Assume that the total area is never beyond the maximum possible value of int.

(A,B):(-3,0)
(C,D):(0,-1)
(E,F):(3,4)
(G,H):(9,2)

*/

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int rtx = min(C, G), rty = min(D, H);
        int lbx = max(A, E), lby = max(B, F);
        int inter = abs(rtx - lbx) * abs(rty - lby);

        int areaA = abs(A - C) * abs(B - D);
        int areaB = abs(G - E) * abs(H - F);

        return areaA + areaB - inter;
    }
};