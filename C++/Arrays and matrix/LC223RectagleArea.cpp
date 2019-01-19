/*
223. Rectangle Area
Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Rectangle Area

Example:

Input: A = -3, B = 0, C = 3, D = 4, E = 0, F = -1, G = 9, H = 2
Output: 45

*/

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int abcd = (C-A)*(D-B);
        int efgh = (G-E)*(H-F);
        
        int a = max(A,E);
        int b = max(B,F);
        int c = min(C,G);
        int d = min(D,H);
        
        int intersection=0;
        if(a<c && b<d)
            intersection = ((c-a)*(d-b));
        int total = abcd+efgh - intersection;
        return total;    
    }
};