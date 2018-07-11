//Find the total area covered by two rectilinear rectangles in a 2D plane.
//
//Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.
//
//Rectangle Area
//
//Example :
//
//Input: A = -3, B = 0, C = 3, D = 4, E = 0, F = -1, G = 9, H = 2
//	Output : 45
//	Note :
//
//	Assume that the total area is never beyond the maximum possible value of int.
//
#include<utility>
using namespace std;
class Solution {
	pair<int, int> findIntersection(int a, int b, int c, int d) {
		int left = c >= b ? b : c < a ? a : c;
		int right = d >= b ? b : d <= a ? a : d;
		return { left,right };
	}
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		auto i = findIntersection(A, C, E, G);
		auto j = findIntersection(B, D, F, H);
		//cout << i.first << " " << i.second << " " << j.first << " " << j.second << endl;
		int total = (C - A)*(D - B) + (G - E)*(H - F);
		return total-(i.second - i.first)*(j.second - j.first);
	}
};