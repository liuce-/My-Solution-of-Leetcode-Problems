//Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
//
//Example:
//
//Input:
//[
//	["1", "0", "1", "0", "0"],
//	["1", "0", "1", "1", "1"],
//	["1", "1", "1", "1", "1"],
//	["1", "0", "0", "1", "0"]
//]
//Output: 6
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		if (matrix.size() == 0)
			return 0;
		int ans = 0;
		vector<vector<vector<int>>> dp(matrix.size() + 1, vector<vector<int>>(matrix[0].size() + 1, {0,0,0,0}));//{0,0,0,0}means{leftWidth,leftHeight,upWidth,upHeight}
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[0].size(); j++) {
				if (matrix[i][j] != '0') {
					int x = i + 1;
					int y = j + 1;
					dp[x][y][0] = dp[x][y - 1][0] + 1;
					dp[x][y][1] = min(dp[x][y - 1][1], dp[x - 1][y][3] + 1);
					dp[x][y][2] = min(dp[x][y - 1][2], dp[x][y][0]);
					dp[x][y][3] = dp[x-1][y][3] + 1;
					ans = max(ans, max(dp[x][y][0] * dp[x][y][1], dp[x][y][2] * dp[x][y][3]));
				}
			}
		}
		return ans;
	}
};

//int main() {
//	Solution s;
//	s.maximalRectangle();
//}


//Found on leetcode: https://leetcode.com/problems/maximal-rectangle/discuss/122456/Easiest-solution-build-on-top-of-leetcode84
class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
			if (matrix.size() == 0) return 0;
			// for each cell with value=1, we look upward (north), the number of continuous '1' is the height of cell
			int* heights = new int[matrix[0].size()];
			int maxArea = -1;
			for (int i = 0; i<matrix.size(); i++) {
				for (int j = 0; j<matrix[0].size(); j++) {
					if (matrix[i][j] == '0') {
						heights[j] = 0;
					}
					else {
						heights[j] ++;
					}
				}
				int area = yourLeetCode84Method(heights);
				maxArea = max(maxArea, area);
			}
			return maxArea;
	}
};
//https://github.com/Chasiny/Blog/blob/master/blog/algorithm/leetcode/85.%20Maximal%20Rectangle.md
class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		if (matrix.size()<1) {
			return 0;
		}
		int max = 0;
		vector<vector<int>> mask(matrix.size(), vector<int>(matrix[0].size(), 0));
		for (int i = 0; i<matrix.size(); i++) {
			int count = 0;
			for (int j = 0; j<matrix[0].size(); j++) {
				if (matrix[i][j] == '1') {
					count++;
					mask[i][j] = count;
				}
				else {
					count = 0;
					mask[i][j] = 0;
				}
			}
		}
		vector<vector<bool>> isVisited(matrix.size(), vector<bool>(matrix[0].size(), false));
		for (int j = 0; j<matrix[0].size(); j++) {
			for (int i = 0; i<matrix.size(); i++) {
				if (isVisited[i][j]) {
					continue;
				}
				int lpos = i - 1;
				int rpos = i + 1;
				while (lpos >= 0 && mask[lpos][j] >= mask[i][j]) {
					if (mask[lpos][j] == mask[i][j]) {
						isVisited[lpos][j] = true;
					}
					lpos--;
				}
				while (rpos<matrix.size() && mask[rpos][j] >= mask[i][j]) {
					if (mask[rpos][j] == mask[i][j]) {
						isVisited[rpos][j] = true;
					}
					rpos++;
				}

				int ans = (rpos - lpos - 1)*mask[i][j];
				max = max>ans ? max : ans;
			}
		}

		return max;
	}
};

//https://leetcode.com/problems/maximal-rectangle/discuss/29054/Share-my-DP-solution
class Solution {
public:
	int maximalRectangle(vector<vector<char> > &matrix) {
		if (matrix.empty()) return 0;
		const int m = matrix.size();
		const int n = matrix[0].size();
		vector<int> left(n),right(n),height(n);
		fill_n(left, n, 0); fill_n(right, n, n); fill_n(height, n, 0);
		int maxA = 0;
		for (int i = 0; i<m; i++) {
			int cur_left = 0, cur_right = n;
			for (int j = 0; j<n; j++) { // compute height (can do this from either side)
				if (matrix[i][j] == '1') height[j]++;
				else height[j] = 0;
			}
			for (int j = 0; j<n; j++) { // compute left (from left to right)
				if (matrix[i][j] == '1') left[j] = max(left[j], cur_left);
				else { left[j] = 0; cur_left = j + 1; }
			}
			// compute right (from right to left)
			for (int j = n - 1; j >= 0; j--) {
				if (matrix[i][j] == '1') right[j] = min(right[j], cur_right);
				else { right[j] = n; cur_right = j; }
			}
			// compute the area of rectangle (can do this from either side)
			for (int j = 0; j<n; j++)
				maxA = max(maxA, (right[j] - left[j])*height[j]);
		}
		return maxA;
	}
};
