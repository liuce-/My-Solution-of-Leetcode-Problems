//Given n non - negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
//
//
//Above is a histogram where width of each bar is 1, given height = [2, 1, 5, 6, 2, 3].
//
//
//
//
//The largest rectangle is shown in the shaded area, which has area = 10 unit.
//
//
//
//Example:
//
//Input: [2, 1, 5, 6, 2, 3]
//	Output : 10
#include<vector>	
#include<algorithm>
#include<stack>
using namespace std;
//o(n^2) Time Limited exceeded
class Solution2 {
public:
	int largestRectangleArea(vector<int>& heights) {
		int res = 0;
		for (int i = 0; i < heights.size(); i++) {
			int minHeight = INT_MAX;
			for (int j = i; j < heights.size(); j++) {
				minHeight = min(minHeight, heights[j]);
				res = max(res, (j - i + 1)*minHeight);
			}
		}
		return res;
	}
}; 

//
class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		heights.push_back(0);
		int  area = 0;
		stack<int> stack;
		for (int i = 0; i<heights.size(); ++i) {
			while (!stack.empty() && heights[stack.top()] > heights[i]) {
				int h = heights[stack.top()];
				stack.pop();
				int w = stack.empty() ? i : i - 1 - stack.top();//If the stack is empty, it means h is smaller than any height ahead of it. So the width is i, whose area is substr(0,i);
				area = max(area, h*w);
			}
			stack.push(i);
		}

		return area;
	}
};


int main() {
	vector<int> testcase = { 1,5,6,2,3 };
	Solution s;
	s.largestRectangleArea(testcase);
	return 0;
}