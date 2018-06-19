//Given a m x n grid filled with non - negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
//
//Note: You can only move either down or right at any point in time.
//
//	Example :
//
//	Input :
//	[
//		[1, 3, 1],
//		[1, 5, 1],
//		[4, 2, 1]
//	]
//Output : 7
//	Explanation : Because the path 1¡ú3¡ú1¡ú1¡ú1 minimizes the sum.
//f(i,j)=v(i,j)+min{ f(i,j-1), f(i-1,j)}, if f(i,j-1) or f(i-1,j) exits

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		if (grid.size() < 1) {
			return 0;
		}

		int row = grid.size();
		int column = grid[0].size();
		vector<int> result(column+1, INT_MAX);
		result[1] = 0;
		for (int i = 0; i < row; i++) {	
			for (int j = 0; j < column; j++) {
					
					result[j+1] = grid[i][j] + min(result[j], result[j+1]);
				}
			
		}
		return result[column];
	}
};