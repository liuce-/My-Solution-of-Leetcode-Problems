//A robot is located at the top - left corner of a m x n grid(marked 'Start' in the diagram below).
//
//The robot can only move either down or right at any point in time.The robot is trying to reach the bottom - right corner of the grid(marked 'Finish' in the diagram below).
//
//Now consider if some obstacles are added to the grids.How many unique paths would there be ?
//
//An obstacle and empty space is marked as 1 and 0 respectively in the grid.
//
//Note: m and n will be at most 100.
//
//	Example 1 :
//
//	Input :
//	[
//		[0, 0, 0],
//		[0, 1, 0],
//		[0, 0, 0]
//	]
//Output : 2
//	Explanation :
//	There is one obstacle in the middle of the 3x3 grid above.
//	There are two ways to reach the bottom - right corner :
//		 1. Right->Right->Down->Down
//			 2. Down->Down->Right->Right


#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		if (m == 0 || n == 0) {
			return 0;
		}

		int** result = new int*[m];
		for (int i = 0; i < m; i++)
			result[i] = new int[n];

		if (obstacleGrid[0][0] == 1) {
			return 0;
		}
		result[0][0] = 1;


		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (i == 0 && j == 0)
					continue;

				if (obstacleGrid[i][j] == 1) {
					result[i][j] = 0;
					continue;
				}
				if (i == 0) {
					result[i][j] = result[i][j-1];
					continue;
				}
				if (j == 0) {
					result[i][j] = result[i-1][j];
					continue;
				}
				
				result[i][j] = result[i][j - 1] + result[i - 1][j];

			}
		}
		return result[m - 1][n - 1];

	}
};